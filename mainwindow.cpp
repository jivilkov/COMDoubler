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
}

MainWindow::~MainWindow()
{
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

void MainWindow::setBaudRateList(QComboBox *cbox){
    cbox->addItem(QString("%0").arg(QSerialPort::Baud1200), QSerialPort::Baud1200);
    cbox->addItem(QString("%0").arg(QSerialPort::Baud2400), QSerialPort::Baud2400);
    cbox->addItem(QString("%0").arg(QSerialPort::Baud4800), QSerialPort::Baud4800);
    cbox->addItem(QString("%0").arg(QSerialPort::Baud9600), QSerialPort::Baud9600);
    cbox->addItem(QString("%0").arg(QSerialPort::Baud19200), QSerialPort::Baud19200);
    cbox->addItem(QString("%0").arg(QSerialPort::Baud38400), QSerialPort::Baud38400);
    cbox->addItem(QString("%0").arg(QSerialPort::Baud57600), QSerialPort::Baud57600);
    cbox->addItem(QString("%0").arg(QSerialPort::Baud115200), QSerialPort::Baud115200);
}

void MainWindow::setDataBitsList(QComboBox *cbox){
    cbox->addItem(QString("%0").arg(QSerialPort::Data5), QSerialPort::Data5);
    cbox->addItem(QString("%0").arg(QSerialPort::Data6), QSerialPort::Data6);
    cbox->addItem(QString("%0").arg(QSerialPort::Data7), QSerialPort::Data7);
    cbox->addItem(QString("%0").arg(QSerialPort::Data8), QSerialPort::Data8);
}

void MainWindow::setParityList(QComboBox *cbox){
    cbox->addItem(QString("None"), QSerialPort::NoParity);
    cbox->addItem(QString("Even"), QSerialPort::EvenParity);
    cbox->addItem(QString("Odd"), QSerialPort::OddParity);
    cbox->addItem(QString("Mark"), QSerialPort::MarkParity);
    cbox->addItem(QString("Space"), QSerialPort::SpaceParity);
}

void MainWindow::setStopBitsList(QComboBox *cbox){
    cbox->addItem(QString("%0").arg(QSerialPort::OneStop), QSerialPort::OneStop);
#ifdef Q_OS_WIN
    cbox->addItem(QString("%0").arg(QSerialPort::OneAndHalfStop), QSerialPort::OneAndHalfStop);
#endif
    cbox->addItem(QString("%0").arg(QSerialPort::TwoStop), QSerialPort::TwoStop);
}

void MainWindow::setFlowControlList(QComboBox *cbox){
    cbox->addItem(QString("None"), QSerialPort::NoFlowControl);
    cbox->addItem(QString("RTS/CTS"), QSerialPort::HardwareControl);
    cbox->addItem(QString("XON/XOFF"), QSerialPort::SoftwareControl);
}

void MainWindow::readByte(){

}

void MainWindow::on_buttonIN_clicked(){
    portIN->

}

void MainWindow::on_button_OUT_clicked()
{
    
}
