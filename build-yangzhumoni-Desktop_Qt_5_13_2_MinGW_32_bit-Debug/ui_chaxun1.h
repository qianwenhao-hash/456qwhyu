/********************************************************************************
** Form generated from reading UI file 'chaxun1.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAXUN1_H
#define UI_CHAXUN1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chaxun1
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Chaxun1)
    {
        if (Chaxun1->objectName().isEmpty())
            Chaxun1->setObjectName(QString::fromUtf8("Chaxun1"));
        Chaxun1->resize(800, 600);
        menubar = new QMenuBar(Chaxun1);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Chaxun1->setMenuBar(menubar);
        centralwidget = new QWidget(Chaxun1);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Chaxun1->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Chaxun1);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Chaxun1->setStatusBar(statusbar);

        retranslateUi(Chaxun1);

        QMetaObject::connectSlotsByName(Chaxun1);
    } // setupUi

    void retranslateUi(QMainWindow *Chaxun1)
    {
        Chaxun1->setWindowTitle(QCoreApplication::translate("Chaxun1", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chaxun1: public Ui_Chaxun1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAXUN1_H
