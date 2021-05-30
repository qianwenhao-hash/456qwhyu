/********************************************************************************
** Form generated from reading UI file 'chaxun3.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAXUN3_H
#define UI_CHAXUN3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chaxun3
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Chaxun3)
    {
        if (Chaxun3->objectName().isEmpty())
            Chaxun3->setObjectName(QString::fromUtf8("Chaxun3"));
        Chaxun3->resize(800, 600);
        menubar = new QMenuBar(Chaxun3);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Chaxun3->setMenuBar(menubar);
        centralwidget = new QWidget(Chaxun3);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Chaxun3->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Chaxun3);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Chaxun3->setStatusBar(statusbar);

        retranslateUi(Chaxun3);

        QMetaObject::connectSlotsByName(Chaxun3);
    } // setupUi

    void retranslateUi(QMainWindow *Chaxun3)
    {
        Chaxun3->setWindowTitle(QCoreApplication::translate("Chaxun3", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chaxun3: public Ui_Chaxun3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAXUN3_H
