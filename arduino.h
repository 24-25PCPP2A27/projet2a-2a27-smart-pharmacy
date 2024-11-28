#ifndef ARDUINO_H
#define ARDUINO_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class Arduino
{
public:
    Arduino();                          // Constructor
    int connectToArduino();             // Connect the PC to Arduino
    int disconnectFromArduino();        // Close the connection
    int sendDataToArduino(QByteArray);  // Send data to Arduino
    QByteArray receiveDataFromArduino();// Read data from Arduino
    QString getPortName();              // Get Arduino port name
    QSerialPort* getSerial();           // Accessor for serial port

private:
    QSerialPort *serial;                // Serial port object for communication
    QString arduinoPortName;            // Port name of the connected Arduino
    bool arduinoIsAvailable;            // Status of Arduino availability
    QByteArray dataBuffer;              // Buffer for received data

    static const quint16 vendorID = 9025;  // Vendor ID for Arduino Uno
    static const quint16 productID = 67;   // Product ID for Arduino Uno
};

#endif // ARDUINO_H
