/********************************************************************************
** Form generated from reading UI file 'chaxun20.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAXUN20_H
#define UI_CHAXUN20_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chaxun20
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Chaxun20)
    {
        if (Chaxun20->objectName().isEmpty())
            Chaxun20->setObjectName(QString::fromUtf8("Chaxun20"));
        Chaxun20->resize(800, 600);
        menubar = new QMenuBar(Chaxun20);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Chaxun20->setMenuBar(menubar);
        centralwidget = new QWidget(Chaxun20);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Chaxun20->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Chaxun20);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Chaxun20->setStatusBar(statusbar);

        retranslateUi(Chaxun20);

        QMetaObject::connectSlotsByName(Chaxun20);
    } // setupUi

    void retranslateUi(QMainWindow *Chaxun20)
    {
        Chaxun20->setWindowTitle(QCoreApplication::translate("Chaxun20", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chaxun20: public Ui_Chaxun20 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAXUN20_H
