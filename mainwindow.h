#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QComboBox>
#include <QTime>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *timerSend;
    QSerialPort *portIN;
    QSerialPort *portOUT;

    void setNumberList(QComboBox *cbox);
    void setBaudRateList(QComboBox *cbox);
    void setDataBitsList(QComboBox *cbox);
    void setParityList(QComboBox *cbox);
    void setStopBitsList(QComboBox *cbox);
    void setFlowControlList(QComboBox *cbox);
    void setLog(QString text);
    void disableSettings(qint8 nport, bool status);
    void writePort(QSerialPort *port, QByteArray data);

    QByteArray dataIN;
    QByteArray dataOUT;

private slots:
    void readData();
    void timerSendSlot();
    void on_buttonIN_clicked();
    void on_buttonOUT_clicked();
    void on_buttonSend_clicked();
    void on_buttonStop_clicked();
    void on_clearBufferButton_clicked();
};

#endif // MAINWINDOW_H
