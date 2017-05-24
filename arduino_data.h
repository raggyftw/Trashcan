#ifndef ARDUINO_DATA_H
#define ARDUINO_DATA_H

#include <QMainWindow>
#include <QSerialPort>
#include <QByteArray>

class arduino_data;

class arduino_data : public QMainWindow
{
    Q_OBJECT

public:
    explicit arduino_data(QWidget *parent = 0);
    ~arduino_data();
    double get_weight();
    double get_height();

private slots:
    void readSerial();

private:
    QSerialPort *arduino;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QByteArray serialData;
    QString serialBuffer;
    QString parsed_weight;
    double weight_value;
    QString parsed_height;
    double height_value;
    double weight;
    double height;

};

#endif // ARDUINO_DATA_H
