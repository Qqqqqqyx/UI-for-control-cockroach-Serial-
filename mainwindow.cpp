#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Inite Serial
    m_serial = new Serial;
    //Find all ports
    QStringList serialStrlist = m_serial->scanSerial();
    for(int i=0;i<serialStrlist.size();i++){
        ui->PortBox->addItem(serialStrlist[i]);
    }
    //Set defaulted Baud
    ui->BaudrateBox->setCurrentIndex(1);
    //Read data when comes
    QObject::connect(m_serial, SIGNAL(readSignal()), this, SLOT(readSerialData()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ClearButton_clicked()
{
    ui->ReceiveText->clear();
}


void MainWindow::on_SendButton_clicked()
{
    QByteArray sendData = ui->Sendline->text().toLatin1();
    m_serial->sendData(sendData);
    ui->Sendline->clear();
}


void MainWindow::on_OpenButton_clicked()
{
    if(ui->OpenButton->text() == "Open Serial"){
        if(m_serial->open(ui->PortBox->currentText(), ui->BaudrateBox->currentText().toInt())){
            //Close list Enable
            ui->PortBox->setEnabled(false);
            ui->BaudrateBox->setEnabled(false);
            //Change Button Name
            ui->OpenButton->setText("Close Serial");
        }
    }
    else{
        //Close
        m_serial->close();
        //list Enable
        ui->PortBox->setEnabled(true);
        ui->BaudrateBox->setEnabled(true);
        //Change Button Name
        ui->OpenButton->setText("Open Serial");
    }
}

void MainWindow::readSerialData()
{
    QString originStr = ui->ReceiveText->toPlainText();
    originStr += tr(m_serial->getReadBuf());
//    ui->ReceiveText->setText(originStr);
//    ui->ReceiveText->moveCursor(QTextCursor::End);
//    ui->ReceiveText->insertPlainText(m_serial->getReadBuf());
//    ui->ReceiveText->moveCursor(QTextCursor::End);
    ui->ReceiveText->clear();
    ui->ReceiveText->append(originStr);

    m_serial->clearReadBuf();
}

void MainWindow::on_Sendline_returnPressed()
{
    ui->SendButton->click();
}


void MainWindow::on_LEDonButton_clicked()
{
    QByteArray sendData;
    sendData.append('o');
    m_serial->sendData(sendData);
}


void MainWindow::on_LEDoffButton_clicked()
{
    QByteArray sendData;
    sendData.append('f');
    m_serial->sendData(sendData);
}


void MainWindow::on_TLeftButton_3_clicked()
{
    if(ui->TLeftButton_3->text() == "Turn Left"){
        QByteArray sendData;
        sendData.append('l');
        m_serial->sendData(sendData);
        ui->TLeftButton_3->setText("Stop");
    }
    else{
        QByteArray sendData0;
        sendData0.append("L");
        m_serial->sendData(sendData0);
        ui->TLeftButton_3->setText("Turn Left");
    }
}


void MainWindow::on_TrightButton_clicked()
{
    if(ui->TrightButton->text() == "Turn Right"){
        QByteArray sendData;
        sendData.append('r');
        m_serial->sendData(sendData);
        ui->TrightButton->setText("Stop");
    }
    else{
        QByteArray sendData0;
        sendData0.append("R");
        m_serial->sendData(sendData0);
        ui->TrightButton->setText("Turn Right");
    }
}

