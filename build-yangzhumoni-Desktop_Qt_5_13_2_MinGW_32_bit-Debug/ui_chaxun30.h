/********************************************************************************
** Form generated from reading UI file 'chaxun30.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAXUN30_H
#define UI_CHAXUN30_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chaxun30
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Chaxun30)
    {
        if (Chaxun30->objectName().isEmpty())
            Chaxun30->setObjectName(QString::fromUtf8("Chaxun30"));
        Chaxun30->resize(800, 600);
        menubar = new QMenuBar(Chaxun30);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Chaxun30->setMenuBar(menubar);
        centralwidget = new QWidget(Chaxun30);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Chaxun30->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Chaxun30);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Chaxun30->setStatusBar(statusbar);

        retranslateUi(Chaxun30);

        QMetaObject::connectSlotsByName(Chaxun30);
    } // setupUi

    void retranslateUi(QMainWindow *Chaxun30)
    {
        Chaxun30->setWindowTitle(QCoreApplication::translate("Chaxun30", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chaxun30: public Ui_Chaxun30 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAXUN30_H
