/********************************************************************************
** Form generated from reading UI file 'form4.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM4_H
#define UI_FORM4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form4
{
public:

    void setupUi(QWidget *Form4)
    {
        if (Form4->objectName().isEmpty())
            Form4->setObjectName(QString::fromUtf8("Form4"));
        Form4->resize(400, 300);

        retranslateUi(Form4);

        QMetaObject::connectSlotsByName(Form4);
    } // setupUi

    void retranslateUi(QWidget *Form4)
    {
        Form4->setWindowTitle(QCoreApplication::translate("Form4", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form4: public Ui_Form4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM4_H
