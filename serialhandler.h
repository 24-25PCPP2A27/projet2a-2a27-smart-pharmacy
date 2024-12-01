#ifndef SERIALHANDLER_H
#define SERIALHANDLER_H

#include <QObject>
#include <QSerialPort>

class SerialHandler : public QObject {
    Q_OBJECT

public:
    explicit SerialHandler(QObject *parent = nullptr);
    ~SerialHandler();

    void startCommunication(const QString &portName);

signals:
    void keyPressed(char key);

private slots:
    void readSerialData();

private:
    QSerialPort *serialPort;
};

#endif // SERIALHANDLER_H
