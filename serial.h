#ifndef SERIAL_H
#define SERIAL_H
#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>

class Serial:public QObject
{
    Q_OBJECT

public:
    Serial();
    QStringList scanSerial();
    bool open(QString serialName, int baudRate);
    void close();
    void sendData(QByteArray &sendData);
    QByteArray getReadBuf();
    void clearReadBuf();

signals:
    void readSignal();

public slots:
    void readData();

private:
    QSerialPort *m_serialPort;
    QByteArray m_readBuf;
};

#endif // SERIAL_H
