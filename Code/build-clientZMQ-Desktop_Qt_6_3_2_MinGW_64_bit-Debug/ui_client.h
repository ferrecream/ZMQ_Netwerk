/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *button3;
    QPushButton *buttonDiv;
    QLineEdit *Display;
    QPushButton *button2;
    QPushButton *GetKey;
    QLineEdit *GetDisplay;
    QPushButton *button1;
    QPushButton *button5;
    QPushButton *SetKey;
    QPushButton *button7;
    QPushButton *buttonMult;
    QPushButton *buttonMin;
    QPushButton *buttonEqual;
    QPushButton *button9;
    QLineEdit *KeyIdDisplay;
    QLineEdit *KeyDisplay;
    QPushButton *button4;
    QPushButton *buttonAdd;
    QPushButton *button6;
    QPushButton *button8;
    QPushButton *button0;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QString::fromUtf8("Client"));
        Client->resize(722, 372);
        centralwidget = new QWidget(Client);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        button3 = new QPushButton(centralwidget);
        button3->setObjectName(QString::fromUtf8("button3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(button3->sizePolicy().hasHeightForWidth());
        button3->setSizePolicy(sizePolicy);
        button3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(button3, 6, 2, 1, 1);

        buttonDiv = new QPushButton(centralwidget);
        buttonDiv->setObjectName(QString::fromUtf8("buttonDiv"));
        sizePolicy.setHeightForWidth(buttonDiv->sizePolicy().hasHeightForWidth());
        buttonDiv->setSizePolicy(sizePolicy);
        buttonDiv->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #FFBC00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(buttonDiv, 3, 3, 1, 1);

        Display = new QLineEdit(centralwidget);
        Display->setObjectName(QString::fromUtf8("Display"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Display->sizePolicy().hasHeightForWidth());
        Display->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(18);
        font.setBold(true);
        Display->setFont(font);
        Display->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color: gray;\n"
"	border: 1px solid gray;\n"
"	color: #ffffff;\n"
"	padding: 5px;\n"
"}"));
        Display->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(Display, 0, 0, 3, 4);

        button2 = new QPushButton(centralwidget);
        button2->setObjectName(QString::fromUtf8("button2"));
        sizePolicy.setHeightForWidth(button2->sizePolicy().hasHeightForWidth());
        button2->setSizePolicy(sizePolicy);
        button2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(button2, 6, 1, 1, 1);

        GetKey = new QPushButton(centralwidget);
        GetKey->setObjectName(QString::fromUtf8("GetKey"));

        gridLayout->addWidget(GetKey, 3, 5, 1, 1);

        GetDisplay = new QLineEdit(centralwidget);
        GetDisplay->setObjectName(QString::fromUtf8("GetDisplay"));

        gridLayout->addWidget(GetDisplay, 2, 4, 1, 2);

        button1 = new QPushButton(centralwidget);
        button1->setObjectName(QString::fromUtf8("button1"));
        sizePolicy.setHeightForWidth(button1->sizePolicy().hasHeightForWidth());
        button1->setSizePolicy(sizePolicy);
        button1->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(button1, 6, 0, 1, 1);

        button5 = new QPushButton(centralwidget);
        button5->setObjectName(QString::fromUtf8("button5"));
        sizePolicy.setHeightForWidth(button5->sizePolicy().hasHeightForWidth());
        button5->setSizePolicy(sizePolicy);
        button5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(button5, 5, 1, 1, 1);

        SetKey = new QPushButton(centralwidget);
        SetKey->setObjectName(QString::fromUtf8("SetKey"));

        gridLayout->addWidget(SetKey, 3, 4, 1, 1);

        button7 = new QPushButton(centralwidget);
        button7->setObjectName(QString::fromUtf8("button7"));
        sizePolicy.setHeightForWidth(button7->sizePolicy().hasHeightForWidth());
        button7->setSizePolicy(sizePolicy);
        button7->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(button7, 3, 0, 1, 1);

        buttonMult = new QPushButton(centralwidget);
        buttonMult->setObjectName(QString::fromUtf8("buttonMult"));
        sizePolicy.setHeightForWidth(buttonMult->sizePolicy().hasHeightForWidth());
        buttonMult->setSizePolicy(sizePolicy);
        buttonMult->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #FFBC00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(buttonMult, 5, 3, 1, 1);

        buttonMin = new QPushButton(centralwidget);
        buttonMin->setObjectName(QString::fromUtf8("buttonMin"));
        sizePolicy.setHeightForWidth(buttonMin->sizePolicy().hasHeightForWidth());
        buttonMin->setSizePolicy(sizePolicy);
        buttonMin->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #FFBC00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(buttonMin, 7, 3, 1, 1);

        buttonEqual = new QPushButton(centralwidget);
        buttonEqual->setObjectName(QString::fromUtf8("buttonEqual"));
        sizePolicy.setHeightForWidth(buttonEqual->sizePolicy().hasHeightForWidth());
        buttonEqual->setSizePolicy(sizePolicy);
        buttonEqual->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #FFBC00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(buttonEqual, 7, 2, 1, 1);

        button9 = new QPushButton(centralwidget);
        button9->setObjectName(QString::fromUtf8("button9"));
        sizePolicy.setHeightForWidth(button9->sizePolicy().hasHeightForWidth());
        button9->setSizePolicy(sizePolicy);
        button9->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(button9, 3, 2, 1, 1);

        KeyIdDisplay = new QLineEdit(centralwidget);
        KeyIdDisplay->setObjectName(QString::fromUtf8("KeyIdDisplay"));
        sizePolicy.setHeightForWidth(KeyIdDisplay->sizePolicy().hasHeightForWidth());
        KeyIdDisplay->setSizePolicy(sizePolicy);

        gridLayout->addWidget(KeyIdDisplay, 0, 4, 1, 2);

        KeyDisplay = new QLineEdit(centralwidget);
        KeyDisplay->setObjectName(QString::fromUtf8("KeyDisplay"));
        sizePolicy.setHeightForWidth(KeyDisplay->sizePolicy().hasHeightForWidth());
        KeyDisplay->setSizePolicy(sizePolicy);

        gridLayout->addWidget(KeyDisplay, 1, 4, 1, 2);

        button4 = new QPushButton(centralwidget);
        button4->setObjectName(QString::fromUtf8("button4"));
        sizePolicy.setHeightForWidth(button4->sizePolicy().hasHeightForWidth());
        button4->setSizePolicy(sizePolicy);
        button4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(button4, 5, 0, 1, 1);

        buttonAdd = new QPushButton(centralwidget);
        buttonAdd->setObjectName(QString::fromUtf8("buttonAdd"));
        sizePolicy.setHeightForWidth(buttonAdd->sizePolicy().hasHeightForWidth());
        buttonAdd->setSizePolicy(sizePolicy);
        buttonAdd->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #FFBC00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(buttonAdd, 6, 3, 1, 1);

        button6 = new QPushButton(centralwidget);
        button6->setObjectName(QString::fromUtf8("button6"));
        sizePolicy.setHeightForWidth(button6->sizePolicy().hasHeightForWidth());
        button6->setSizePolicy(sizePolicy);
        button6->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(button6, 5, 2, 1, 1);

        button8 = new QPushButton(centralwidget);
        button8->setObjectName(QString::fromUtf8("button8"));
        sizePolicy.setHeightForWidth(button8->sizePolicy().hasHeightForWidth());
        button8->setSizePolicy(sizePolicy);
        button8->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(button8, 3, 1, 1, 1);

        button0 = new QPushButton(centralwidget);
        button0->setObjectName(QString::fromUtf8("button0"));
        sizePolicy.setHeightForWidth(button0->sizePolicy().hasHeightForWidth());
        button0->setSizePolicy(sizePolicy);
        button0->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(button0, 7, 1, 1, 1);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 5, 4, 3, 2);

        Client->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Client);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 722, 25));
        Client->setMenuBar(menubar);
        statusbar = new QStatusBar(Client);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Client->setStatusBar(statusbar);

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QMainWindow *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "Client", nullptr));
        button3->setText(QCoreApplication::translate("Client", "3", nullptr));
        buttonDiv->setText(QCoreApplication::translate("Client", "/", nullptr));
        Display->setText(QCoreApplication::translate("Client", "0.0", nullptr));
        button2->setText(QCoreApplication::translate("Client", "2", nullptr));
        GetKey->setText(QCoreApplication::translate("Client", "GET", nullptr));
        button1->setText(QCoreApplication::translate("Client", "1", nullptr));
        button5->setText(QCoreApplication::translate("Client", "5", nullptr));
        SetKey->setText(QCoreApplication::translate("Client", "SET", nullptr));
        button7->setText(QCoreApplication::translate("Client", "7", nullptr));
        buttonMult->setText(QCoreApplication::translate("Client", "*", nullptr));
        buttonMin->setText(QCoreApplication::translate("Client", "-", nullptr));
        buttonEqual->setText(QCoreApplication::translate("Client", "=", nullptr));
        button9->setText(QCoreApplication::translate("Client", "9", nullptr));
        button4->setText(QCoreApplication::translate("Client", "4", nullptr));
        buttonAdd->setText(QCoreApplication::translate("Client", "+", nullptr));
        button6->setText(QCoreApplication::translate("Client", "6", nullptr));
        button8->setText(QCoreApplication::translate("Client", "8", nullptr));
        button0->setText(QCoreApplication::translate("Client", "0", nullptr));
        textEdit->setHtml(QCoreApplication::translate("Client", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Calculator is straight forward.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">the get and set key locker is not so</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">on the above line you put in your keyID</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">on the"
                        " middle line you put in your Key </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">you can press set now</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">if you want to retrieve the key make sure the KeyID</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">is typed in in the above line</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">than tap GET an you will get you key back</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
