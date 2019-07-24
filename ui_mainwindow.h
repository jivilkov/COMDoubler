/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QPushButton *buttonSend;
    QPushButton *buttonStop;
    QSpinBox *spinBox;
    QPlainTextEdit *textBrowser;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout;
    QLabel *currentByte;
    QPushButton *clearBufferButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QComboBox *comboBoxNumberIn;
    QLabel *label;
    QComboBox *comboBoxFlowControlIn;
    QLabel *label_5;
    QPushButton *buttonIN;
    QLabel *label_2;
    QLabel *label_6;
    QComboBox *comboBoxStopBitsIn;
    QLabel *label_4;
    QComboBox *comboBoxParityIn;
    QComboBox *comboBoxBaudRateIn;
    QComboBox *comboBoxDataBitsIn;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QComboBox *comboBoxBaudRateOut;
    QPushButton *buttonOUT;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_8;
    QComboBox *comboBoxDataBitsOut;
    QComboBox *comboBoxFlowControlOut;
    QComboBox *comboBoxParityOut;
    QComboBox *comboBoxNumberOut;
    QComboBox *comboBoxStopBitsOut;
    QLabel *label_12;
    QSpacerItem *verticalSpacer_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 469);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setBaseSize(QSize(0, 0));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        buttonSend = new QPushButton(groupBox_3);
        buttonSend->setObjectName(QString::fromUtf8("buttonSend"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonSend->sizePolicy().hasHeightForWidth());
        buttonSend->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(buttonSend, 0, 1, 1, 1);

        buttonStop = new QPushButton(groupBox_3);
        buttonStop->setObjectName(QString::fromUtf8("buttonStop"));
        sizePolicy1.setHeightForWidth(buttonStop->sizePolicy().hasHeightForWidth());
        buttonStop->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(buttonStop, 0, 2, 1, 1);

        spinBox = new QSpinBox(groupBox_3);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(4);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy2);
        spinBox->setMinimum(1);
        spinBox->setMaximum(3600);
        spinBox->setValue(60);

        gridLayout_3->addWidget(spinBox, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 0, 1, 1, 1);

        textBrowser = new QPlainTextEdit(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(20);
        sizePolicy3.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(textBrowser, 1, 1, 1, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(groupBox_4);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        currentByte = new QLabel(groupBox_4);
        currentByte->setObjectName(QString::fromUtf8("currentByte"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(8);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(currentByte->sizePolicy().hasHeightForWidth());
        currentByte->setSizePolicy(sizePolicy4);

        horizontalLayout->addWidget(currentByte);

        clearBufferButton = new QPushButton(groupBox_4);
        clearBufferButton->setObjectName(QString::fromUtf8("clearBufferButton"));
        sizePolicy1.setHeightForWidth(clearBufferButton->sizePolicy().hasHeightForWidth());
        clearBufferButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(clearBufferButton);


        gridLayout_4->addWidget(groupBox_4, 2, 1, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboBoxNumberIn = new QComboBox(groupBox);
        comboBoxNumberIn->setObjectName(QString::fromUtf8("comboBoxNumberIn"));

        gridLayout->addWidget(comboBoxNumberIn, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBoxFlowControlIn = new QComboBox(groupBox);
        comboBoxFlowControlIn->setObjectName(QString::fromUtf8("comboBoxFlowControlIn"));

        gridLayout->addWidget(comboBoxFlowControlIn, 5, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        buttonIN = new QPushButton(groupBox);
        buttonIN->setObjectName(QString::fromUtf8("buttonIN"));

        gridLayout->addWidget(buttonIN, 7, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        comboBoxStopBitsIn = new QComboBox(groupBox);
        comboBoxStopBitsIn->setObjectName(QString::fromUtf8("comboBoxStopBitsIn"));

        gridLayout->addWidget(comboBoxStopBitsIn, 4, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        comboBoxParityIn = new QComboBox(groupBox);
        comboBoxParityIn->setObjectName(QString::fromUtf8("comboBoxParityIn"));

        gridLayout->addWidget(comboBoxParityIn, 3, 1, 1, 1);

        comboBoxBaudRateIn = new QComboBox(groupBox);
        comboBoxBaudRateIn->setObjectName(QString::fromUtf8("comboBoxBaudRateIn"));

        gridLayout->addWidget(comboBoxBaudRateIn, 1, 1, 1, 1);

        comboBoxDataBitsIn = new QComboBox(groupBox);
        comboBoxDataBitsIn->setObjectName(QString::fromUtf8("comboBoxDataBitsIn"));

        gridLayout->addWidget(comboBoxDataBitsIn, 2, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 8, 1, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 3, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        comboBoxBaudRateOut = new QComboBox(groupBox_2);
        comboBoxBaudRateOut->setObjectName(QString::fromUtf8("comboBoxBaudRateOut"));

        gridLayout_2->addWidget(comboBoxBaudRateOut, 1, 1, 1, 1);

        buttonOUT = new QPushButton(groupBox_2);
        buttonOUT->setObjectName(QString::fromUtf8("buttonOUT"));

        gridLayout_2->addWidget(buttonOUT, 7, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 2, 0, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 3, 0, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 4, 0, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 1, 0, 1, 1);

        comboBoxDataBitsOut = new QComboBox(groupBox_2);
        comboBoxDataBitsOut->setObjectName(QString::fromUtf8("comboBoxDataBitsOut"));

        gridLayout_2->addWidget(comboBoxDataBitsOut, 2, 1, 1, 1);

        comboBoxFlowControlOut = new QComboBox(groupBox_2);
        comboBoxFlowControlOut->setObjectName(QString::fromUtf8("comboBoxFlowControlOut"));

        gridLayout_2->addWidget(comboBoxFlowControlOut, 5, 1, 1, 1);

        comboBoxParityOut = new QComboBox(groupBox_2);
        comboBoxParityOut->setObjectName(QString::fromUtf8("comboBoxParityOut"));

        gridLayout_2->addWidget(comboBoxParityOut, 3, 1, 1, 1);

        comboBoxNumberOut = new QComboBox(groupBox_2);
        comboBoxNumberOut->setObjectName(QString::fromUtf8("comboBoxNumberOut"));

        gridLayout_2->addWidget(comboBoxNumberOut, 0, 1, 1, 1);

        comboBoxStopBitsOut = new QComboBox(groupBox_2);
        comboBoxStopBitsOut->setObjectName(QString::fromUtf8("comboBoxStopBitsOut"));

        gridLayout_2->addWidget(comboBoxStopBitsOut, 4, 1, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 5, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 8, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 2, 3, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Delay (sec)", nullptr));
        buttonSend->setText(QApplication::translate("MainWindow", "Send", nullptr));
        buttonStop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Buffer", nullptr));
        currentByte->setText(QApplication::translate("MainWindow", "Empty", nullptr));
        clearBufferButton->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "IN", nullptr));
        label->setText(QApplication::translate("MainWindow", "Number", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Stop bits", nullptr));
        buttonIN->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Baud rate", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "FlowControl", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Parity", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Data bits", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "OUT", nullptr));
        buttonOUT->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Number", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Data bits", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Parity", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Stop bits", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Baud rate", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "FlowControl", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
