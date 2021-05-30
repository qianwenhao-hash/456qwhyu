/********************************************************************************
** Form generated from reading UI file 'zhunwen.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZHUNWEN_H
#define UI_ZHUNWEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Zhunwen
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Zhunwen)
    {
        if (Zhunwen->objectName().isEmpty())
            Zhunwen->setObjectName(QString::fromUtf8("Zhunwen"));
        Zhunwen->resize(800, 600);
        menubar = new QMenuBar(Zhunwen);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Zhunwen->setMenuBar(menubar);
        centralwidget = new QWidget(Zhunwen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Zhunwen->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Zhunwen);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Zhunwen->setStatusBar(statusbar);

        retranslateUi(Zhunwen);

        QMetaObject::connectSlotsByName(Zhunwen);
    } // setupUi

    void retranslateUi(QMainWindow *Zhunwen)
    {
        Zhunwen->setWindowTitle(QCoreApplication::translate("Zhunwen", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Zhunwen: public Ui_Zhunwen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZHUNWEN_H
