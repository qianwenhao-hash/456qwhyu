/********************************************************************************
** Form generated from reading UI file 'new_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_MAINWINDOW_H
#define UI_NEW_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_new_MainWindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *new_MainWindow)
    {
        if (new_MainWindow->objectName().isEmpty())
            new_MainWindow->setObjectName(QString::fromUtf8("new_MainWindow"));
        new_MainWindow->resize(800, 600);
        menubar = new QMenuBar(new_MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        new_MainWindow->setMenuBar(menubar);
        centralwidget = new QWidget(new_MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        new_MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(new_MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        new_MainWindow->setStatusBar(statusbar);

        retranslateUi(new_MainWindow);

        QMetaObject::connectSlotsByName(new_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *new_MainWindow)
    {
        new_MainWindow->setWindowTitle(QCoreApplication::translate("new_MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_MainWindow: public Ui_new_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_MAINWINDOW_H
