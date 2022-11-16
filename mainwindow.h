#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "serial.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSerialPort *m_serialPort;

private slots:
    void on_ClearButton_clicked();

    void on_SendButton_clicked();

    void on_OpenButton_clicked();

    void readSerialData();

    void on_Sendline_returnPressed();

    void on_LEDonButton_clicked();

    void on_LEDoffButton_clicked();

    void on_TLeftButton_3_clicked();

    void on_TrightButton_clicked();

private:
    Ui::MainWindow *ui;
    Serial *m_serial;
};
#endif // MAINWINDOW_H
