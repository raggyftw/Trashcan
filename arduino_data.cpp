#include "arduino_data.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <string>
#include <QDebug>
#include <QMessageBox>

arduino_data::arduino_data(QWidget *parent) :
    QMainWindow(parent)
{

    arduino = new QSerialPort(this);
    serialBuffer = "";

    bool arduino_is_available = false;
    QString arduino_uno_port_name;
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
            if((serialPortInfo.productIdentifier() == arduino_uno_product_id)
                    && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id)){
                         arduino_is_available = true;
                            arduino_uno_port_name = serialPortInfo.portName();
            }
        }
    }


    if(arduino_is_available){
        arduino->setPortName(arduino_uno_port_name);
        arduino->open(QSerialPort::ReadOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
    }else{
        QMessageBox::information(this, "Serial Port Error", "Couldn't open serial port to arduino.");
    }
}


arduino_data::~arduino_data()
{
    if(arduino->isOpen()){
        arduino->close();
    }
}


void arduino_data::readSerial()
{

    QStringList buffer_split = serialBuffer.split(",");
    //qDebug() << buffer_split;


    if(buffer_split.length() < 3){
        serialData = arduino->readAll();
        serialBuffer = serialBuffer + QString::fromStdString(serialData.toStdString());
        serialData.clear();
    }else{
        serialBuffer = "";
        parsed_weight = buffer_split[1];
        weight_value =  (parsed_weight.toDouble());
        parsed_height = buffer_split[0];
        height_value =  (parsed_height.toDouble());
        qDebug()<<height_value<<weight_value;
    }

}
double arduino_data::get_weight(){
weight = weight_value;
return weight;
}
double arduino_data::get_height(){
height= height_value;
return height;
}
