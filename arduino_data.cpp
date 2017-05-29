#include "arduino_data.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <string>
#include <QDebug>
#include <QMessageBox>

arduino_data::arduino_data(QWidget *parent) : // Constructor used to establish serial connection.
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

    QStringList buffer_split = serialBuffer.split(","); //Splits the QSTring into several strings, sepperated by ","

    if(buffer_split.length() < 3){ //Checks if the length of the QString is less than 3
        serialData = arduino->readAll();//Reads all available data
        serialBuffer = serialBuffer + QString::fromStdString(serialData.toStdString());//Sends the data to the buffer
        serialData.clear();//Clears the datastream
    }//End of if-statement
    else{
        serialBuffer = ""; //Sets the buffer to be empty
        parsed_weight = buffer_split[1]; //Stores the 2nd element of the Stringlist 
        weight_value =  (parsed_weight.toDouble()); //converts the stored element to a double
        parsed_height = buffer_split[0]; //Stores the 1st element of the Stringlist
        height_value =  (parsed_height.toDouble());//converts the stored element to a double
    }//End of else-statement
}//End of readserial
double arduino_data::get_weight(){
weight = weight_value*-1; //stores the weight value and changes the sign of the stored data
return weight; //Returns the weight value
}
double arduino_data::get_height(){
height= height_value; //Stores the height value.
return height; //returns the stored value
}
