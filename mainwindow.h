#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QComboBox>
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
    QTimer *timerDoubler;
    QTimer *timerRequest;

    QSerialPort *portIN;
    QSerialPort *portOUT;

    void setNumberList(QComboBox *cbox);
    void setBaudRateList(QComboBox *cbox);
    void setDataBitsList(QComboBox *cbox);
    void setParityList(QComboBox *cbox);
    void setStopBitsList(QComboBox *cbox);
    void setFlowControlList(QComboBox *cbox);

private slots:
    void readByte();
    void on_buttonIN_clicked();
    void on_button_OUT_clicked();
};

#endif // MAINWINDOW_H
