/********************************************************************************
** Form generated from reading UI file 'chaxun2.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAXUN2_H
#define UI_CHAXUN2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chaxun2
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Chaxun2)
    {
        if (Chaxun2->objectName().isEmpty())
            Chaxun2->setObjectName(QString::fromUtf8("Chaxun2"));
        Chaxun2->resize(800, 600);
        menubar = new QMenuBar(Chaxun2);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Chaxun2->setMenuBar(menubar);
        centralwidget = new QWidget(Chaxun2);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Chaxun2->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Chaxun2);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Chaxun2->setStatusBar(statusbar);

        retranslateUi(Chaxun2);

        QMetaObject::connectSlotsByName(Chaxun2);
    } // setupUi

    void retranslateUi(QMainWindow *Chaxun2)
    {
        Chaxun2->setWindowTitle(QCoreApplication::translate("Chaxun2", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chaxun2: public Ui_Chaxun2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAXUN2_H
