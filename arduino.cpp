#include "arduino.h"

Arduino::Arduino()
{
    dataBuffer = "";
    arduinoPortName = "";
    arduinoIsAvailable = false;
    serial = new QSerialPort;
}

QString Arduino::getPortName()
{
    return arduinoPortName;
}

QSerialPort* Arduino::getSerial()
{
    return serial;
}

int Arduino::connectToArduino()
{
    // Scan available ports to find the Arduino
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        if (serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()) {
            if (serialPortInfo.vendorIdentifier() == vendorID && serialPortInfo.productIdentifier() == productID) {
                arduinoIsAvailable = true;
                arduinoPortName = serialPortInfo.portName();
            }
        }
    }

    qDebug() << "Arduino port name is: " << arduinoPortName;

    if (arduinoIsAvailable) {
        serial->setPortName(arduinoPortName);
        if (serial->open(QSerialPort::ReadWrite))  {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0;  // Connection successful
        }
        return 1;  // Failed to open serial port
    }
    return -1;  // Arduino not found
}

int Arduino::disconnectFromArduino()
{
    if (serial->isOpen()) {
        serial->close();
        return 0;  // Disconnected successfully
    }
    return 1;  // Disconnection failed
}

int Arduino::sendDataToArduino(QByteArray data)
{
    if (serial->isWritable()) {
        serial->write(data);  // Send data to Arduino
        return 0;  // Data sent successfully
    } else {
        qDebug() << "Failed to write to Arduino!";
        return 1;  // Failed to write
    }
}

QByteArray Arduino::receiveDataFromArduino()
{
    if (serial->isReadable()) {
        dataBuffer = serial->readAll();  // Read available data
        return dataBuffer;
    }
    return "";  // No data received
}
