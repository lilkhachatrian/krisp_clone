/********************************************************************************
** Form generated from reading UI file 'hello_world.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLO_WORLD_H
#define UI_HELLO_WORLD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hello_world
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *hello_world)
    {
        if (hello_world->objectName().isEmpty())
            hello_world->setObjectName(QString::fromUtf8("hello_world"));
        hello_world->resize(800, 600);
        centralwidget = new QWidget(hello_world);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(330, 190, 101, 31));
        hello_world->setCentralWidget(centralwidget);
        menubar = new QMenuBar(hello_world);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        hello_world->setMenuBar(menubar);
        statusbar = new QStatusBar(hello_world);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        hello_world->setStatusBar(statusbar);

        retranslateUi(hello_world);

        QMetaObject::connectSlotsByName(hello_world);
    } // setupUi

    void retranslateUi(QMainWindow *hello_world)
    {
        hello_world->setWindowTitle(QApplication::translate("hello_world", "hello_world", nullptr));
        textBrowser->setHtml(QApplication::translate("hello_world", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Hello World!</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hello_world: public Ui_hello_world {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLO_WORLD_H
