/********************************************************************************
** Form generated from reading UI file 'utterchat.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UTTERCHAT_H
#define UI_UTTERCHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_utterchat
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *utterchat)
    {
        if (utterchat->objectName().isEmpty())
            utterchat->setObjectName("utterchat");
        utterchat->resize(800, 600);
        centralwidget = new QWidget(utterchat);
        centralwidget->setObjectName("centralwidget");
        utterchat->setCentralWidget(centralwidget);
        menubar = new QMenuBar(utterchat);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        utterchat->setMenuBar(menubar);
        statusbar = new QStatusBar(utterchat);
        statusbar->setObjectName("statusbar");
        utterchat->setStatusBar(statusbar);

        retranslateUi(utterchat);

        QMetaObject::connectSlotsByName(utterchat);
    } // setupUi

    void retranslateUi(QMainWindow *utterchat)
    {
        utterchat->setWindowTitle(QCoreApplication::translate("utterchat", "utterchat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class utterchat: public Ui_utterchat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UTTERCHAT_H
