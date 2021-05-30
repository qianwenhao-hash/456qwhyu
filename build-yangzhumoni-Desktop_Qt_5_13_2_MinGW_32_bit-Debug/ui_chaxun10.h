/********************************************************************************
** Form generated from reading UI file 'chaxun10.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAXUN10_H
#define UI_CHAXUN10_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chaxun10
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Chaxun10)
    {
        if (Chaxun10->objectName().isEmpty())
            Chaxun10->setObjectName(QString::fromUtf8("Chaxun10"));
        Chaxun10->resize(800, 600);
        menubar = new QMenuBar(Chaxun10);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Chaxun10->setMenuBar(menubar);
        centralwidget = new QWidget(Chaxun10);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Chaxun10->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Chaxun10);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Chaxun10->setStatusBar(statusbar);

        retranslateUi(Chaxun10);

        QMetaObject::connectSlotsByName(Chaxun10);
    } // setupUi

    void retranslateUi(QMainWindow *Chaxun10)
    {
        Chaxun10->setWindowTitle(QCoreApplication::translate("Chaxun10", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chaxun10: public Ui_Chaxun10 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAXUN10_H
