/********************************************************************************
** Form generated from reading UI file 'chanxun20.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANXUN20_H
#define UI_CHANXUN20_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chanxun20
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Chanxun20)
    {
        if (Chanxun20->objectName().isEmpty())
            Chanxun20->setObjectName(QString::fromUtf8("Chanxun20"));
        Chanxun20->resize(800, 600);
        menubar = new QMenuBar(Chanxun20);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Chanxun20->setMenuBar(menubar);
        centralwidget = new QWidget(Chanxun20);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Chanxun20->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Chanxun20);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Chanxun20->setStatusBar(statusbar);

        retranslateUi(Chanxun20);

        QMetaObject::connectSlotsByName(Chanxun20);
    } // setupUi

    void retranslateUi(QMainWindow *Chanxun20)
    {
        Chanxun20->setWindowTitle(QCoreApplication::translate("Chanxun20", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chanxun20: public Ui_Chanxun20 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANXUN20_H
