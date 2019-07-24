#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("COM Doubler");

    // number
    setNumberList(ui->comboBoxNumberIn);
    setNumberList(ui->comboBoxNumberOut);

    // baud rate
    setBaudRateList(ui->comboBoxBaudRateIn);
    setBaudRateList(ui->comboBoxBaudRateOut);

    // data bits
    setDataBitsList(ui->comboBoxDataBitsIn);
    setDataBitsList(ui->comboBoxDataBitsOut);

    // parity
    setParityList(ui->comboBoxParityIn);
    setParityList(ui->comboBoxParityOut);

    // stop bits
    setStopBitsList(ui->comboBoxStopBitsIn);
    setStopBitsList(ui->comboBoxStopBitsOut);

    // flow control
    setFlowControlList(ui->comboBoxFlowControlIn);
    setFlowControlList(ui->comboBoxFlowControlOut);

    // default
    ui->comboBoxBaudRateIn->setCurrentIndex(3);
    ui->comboBoxBaudRateOut->setCurrentIndex(3);

    ui->comboBoxDataBitsIn->setCurrentIndex(3);
    ui->comboBoxDataBitsOut->setCurrentIndex(3);

    portIN = NULL;
    portOUT = NULL;

    timerSend = new QTimer();
    connect(timerSend, SIGNAL(timeout()), SLOT(timerSendSlot()));

    ui->buttonSend->setDisabled(false);
    ui->buttonStop->setDisabled(true);
}

MainWindow::~MainWindow()
{
    if (timerSend) delete timerSend;
    if (portIN) delete portIN;
    if (portOUT) delete portOUT;
    delete ui;
}

void MainWindow::setNumberList(QComboBox *cbox)
{
    QString description;
    QString manufacturer;
    QString serialNumber;
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        QStringList list;
        description = info.description();
        manufacturer = info.manufacturer();
        serialNumber = info.serialNumber();
        list << info.portName()
             << (!description.isEmpty() ? description : NULL)
             << (!manufacturer.isEmpty() ? manufacturer : NULL)
             << (!serialNumber.isEmpty() ? serialNumber : NULL)
             << info.systemLocation()
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : NULL)
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : NULL);
        cbox->addItem(list.first(), list);
    }
}

void MainWindow::setBaudRateList(QComboBox *cbox)
{
    cbox->addItem(QString("%0").arg(QSerialPort::Baud1200), QSerialPort::Baud1200);
    cbox->addItem(QString("%0").arg(QSerialPort::Baud2400), QSerialPort::Baud2400);
    cbox->addItem(QString("%0").arg(QSerialPort::Baud4800), QSerialPort::Baud4800);
    cbox->addItem(QString("%0").arg(QSerialPort::Baud9600), QSerialPort::Baud9600);
    cbox->addItem(QString("%0").arg(QSerialPort::Baud19200), QSerialPort::Baud19200);
    cbox->addItem(QString("%0").arg(QSerialPort::Baud38400), QSerialPort::Baud38400);
    cbox->addItem(QString("%0").arg(QSerialPort::Baud57600), QSerialPort::Baud57600);
    cbox->addItem(QString("%0").arg(QSerialPort::Baud115200), QSerialPort::Baud115200);
}

void MainWindow::setDataBitsList(QComboBox *cbox)
{
    cbox->addItem(QString("%0").arg(QSerialPort::Data5), QSerialPort::Data5);
    cbox->addItem(QString("%0").arg(QSerialPort::Data6), QSerialPort::Data6);
    cbox->addItem(QString("%0").arg(QSerialPort::Data7), QSerialPort::Data7);
    cbox->addItem(QString("%0").arg(QSerialPort::Data8), QSerialPort::Data8);
}

void MainWindow::setParityList(QComboBox *cbox)
{
    cbox->addItem(QString("None"), QSerialPort::NoParity);
    cbox->addItem(QString("Even"), QSerialPort::EvenParity);
    cbox->addItem(QString("Odd"), QSerialPort::OddParity);
    cbox->addItem(QString("Mark"), QSerialPort::MarkParity);
    cbox->addItem(QString("Space"), QSerialPort::SpaceParity);
}

void MainWindow::setStopBitsList(QComboBox *cbox)
{
    cbox->addItem(QString("%0").arg(QSerialPort::OneStop), QSerialPort::OneStop);
#ifdef Q_OS_WIN
    cbox->addItem(QString("%0").arg(QSerialPort::OneAndHalfStop), QSerialPort::OneAndHalfStop);
#endif
    cbox->addItem(QString("%0").arg(QSerialPort::TwoStop), QSerialPort::TwoStop);
}

void MainWindow::setFlowControlList(QComboBox *cbox)
{
    cbox->addItem(QString("None"), QSerialPort::NoFlowControl);
    cbox->addItem(QString("RTS/CTS"), QSerialPort::HardwareControl);
    cbox->addItem(QString("XON/XOFF"), QSerialPort::SoftwareControl);
}

void MainWindow::setLog(QString text)
{
    ui->textBrowser->insertPlainText(QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss") + " " + text + "\n");
}

void MainWindow::disableSettings(qint8 nport, bool status)
{
    if (nport){
        ui->comboBoxNumberIn->setDisabled(status);
        ui->comboBoxBaudRateIn->setDisabled(status);
        ui->comboBoxDataBitsIn->setDisabled(status);
        ui->comboBoxParityIn->setDisabled(status);
        ui->comboBoxStopBitsIn->setDisabled(status);
        ui->comboBoxFlowControlIn->setDisabled(status);
        if (status){
            ui->buttonIN->setText("Disconnect");
        } else {
            ui->buttonIN->setText("Connect");
        }
    } else {
        ui->comboBoxNumberOut->setDisabled(status);
        ui->comboBoxBaudRateOut->setDisabled(status);
        ui->comboBoxDataBitsOut->setDisabled(status);
        ui->comboBoxParityOut->setDisabled(status);
        ui->comboBoxStopBitsOut->setDisabled(status);
        ui->comboBoxFlowControlOut->setDisabled(status);
        if (status){
            ui->buttonOUT->setText("Disconnect");
        } else {
            ui->buttonOUT->setText("Connect");
        }
    }
}

void MainWindow::writePort(QSerialPort *port, QByteArray data)
{
    port->write(data);
}

void MainWindow::on_buttonIN_clicked(){

    if (portIN != NULL && portIN->isOpen()){
        disableSettings(1, false);
        portIN->flush();
        portIN->clear();
        portIN->close();
        setLog(portIN->portName() + " disconnect");
        portIN->deleteLater();
        portIN = NULL;
    } else {
        portIN = new QSerialPort();
        connect(portIN, SIGNAL(readyRead()), SLOT(readData()));
        portIN->setPortName(ui->comboBoxNumberIn->currentText());
        portIN->setBaudRate(ui->comboBoxBaudRateIn->itemData(ui->comboBoxBaudRateIn->currentIndex()).toInt());
        portIN->setDataBits(static_cast<QSerialPort::DataBits>(ui->comboBoxDataBitsIn->itemData(ui->comboBoxDataBitsIn->currentIndex()).toInt()));
        portIN->setParity(static_cast<QSerialPort::Parity>(ui->comboBoxParityIn->itemData(ui->comboBoxParityIn->currentIndex()).toInt()));
        portIN->setStopBits(static_cast<QSerialPort::StopBits>(ui->comboBoxStopBitsIn->itemData(ui->comboBoxStopBitsIn->currentIndex()).toInt()));
        portIN->setFlowControl(static_cast<QSerialPort::FlowControl>(ui->comboBoxNumberIn->itemData(ui->comboBoxNumberIn->currentIndex()).toInt()));
        if (portIN->open(QIODevice::ReadWrite)){
            setLog(portIN->portName() + " connect");
            disableSettings(1, true);
        } else {
            setLog(portIN->portName() + "  " + portIN->errorString());
        }
    }
}

void MainWindow::on_buttonOUT_clicked()
{
    if (portOUT != NULL && portOUT->isOpen()){
        disableSettings(0, false);
        portOUT->flush();
        portOUT->clear();
        portOUT->close();
        setLog(portOUT->portName() + " disconnect");
        portOUT->deleteLater();
        portOUT = NULL;
    } else {
        portOUT = new QSerialPort();
        /*connect(portOUT, SIGNAL(readyRead()), SLOT(readData()));*/
        portOUT->setPortName(ui->comboBoxNumberOut->currentText());
        portOUT->setBaudRate(ui->comboBoxBaudRateOut->itemData(ui->comboBoxBaudRateOut->currentIndex()).toInt());
        portOUT->setDataBits(static_cast<QSerialPort::DataBits>(ui->comboBoxDataBitsOut->itemData(ui->comboBoxDataBitsOut->currentIndex()).toInt()));
        portOUT->setParity(static_cast<QSerialPort::Parity>(ui->comboBoxParityOut->itemData(ui->comboBoxParityOut->currentIndex()).toInt()));
        portOUT->setStopBits(static_cast<QSerialPort::StopBits>(ui->comboBoxStopBitsOut->itemData(ui->comboBoxStopBitsOut->currentIndex()).toInt()));
        portOUT->setFlowControl(static_cast<QSerialPort::FlowControl>(ui->comboBoxNumberOut->itemData(ui->comboBoxNumberOut->currentIndex()).toInt()));
        if (portOUT->open(QIODevice::ReadWrite)){
            setLog(portOUT->portName() + " connect");
            disableSettings(0, true);
        } else {
            setLog(portOUT->portName() + " " + portOUT->errorString());
        }    }
}

void MainWindow::readData()
{
    if (portIN){
        dataIN = portIN->readAll();
        setLog(portIN->portName() + " read: " + QString(dataIN));
        ui->currentByte->setText(QString(dataIN));
    }

    /*
    if (portOUT){
        dataOUT = portOUT->readAll();c
        setLog(portOUT->portName() + " read: " + QString(dataOUT));
    }
    */

    timerSendSlot();
}

void MainWindow::timerSendSlot()
{
    if (portIN && portOUT && dataIN.length() > 0){
        writePort(portOUT, dataIN);
        setLog(portOUT->portName() + " write: " + QString(dataIN));
    }
}

void MainWindow::on_buttonSend_clicked()
{
    if (timerSend){
        setLog("Sending started");
        timerSend->start(ui->spinBox->value() * 1000);
    }
    ui->buttonSend->setDisabled(true);
    ui->buttonStop->setDisabled(false);
}

void MainWindow::on_buttonStop_clicked()
{
    if (timerSend){
        setLog("Stopped sending");
        timerSend->stop();
    }
    ui->buttonSend->setDisabled(false);
    ui->buttonStop->setDisabled(true);
}

void MainWindow::on_clearBufferButton_clicked()
{
    if (dataIN.length() > 0){
        dataIN.clear();
    }
    if (dataOUT.length() > 0){
        dataOUT.clear();
    }

    ui->currentByte->setText(QString("Empty"));
}
