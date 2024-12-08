#include "serialhandler.h"
#include <QDebug>

SerialHandler::SerialHandler(QObject *parent)
    : QObject(parent), serialPort(new QSerialPort(this)) {}

SerialHandler::~SerialHandler() {
    if (serialPort->isOpen()) {
        serialPort->close();
    }
}

void SerialHandler::startCommunication(const QString &portName) {
    serialPort->setPortName(portName);
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::ReadOnly)) {
        connect(serialPort, &QSerialPort::readyRead, this, &SerialHandler::readSerialData);
        qDebug() << "Serial port opened successfully!";
    } else {
        qDebug() << "Failed to open serial port:" << serialPort->errorString();
    }
}

void SerialHandler::readSerialData() {
    while (serialPort->canReadLine()) {
        QByteArray data = serialPort->readLine().trimmed();
        if (!data.isEmpty() && data.size() == 1) {
            emit keyPressed(data[0]);
        }
    }
}
