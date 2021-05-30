/********************************************************************************
** Form generated from reading UI file 'form5.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM5_H
#define UI_FORM5_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form5
{
public:

    void setupUi(QWidget *Form5)
    {
        if (Form5->objectName().isEmpty())
            Form5->setObjectName(QString::fromUtf8("Form5"));
        Form5->resize(400, 300);

        retranslateUi(Form5);

        QMetaObject::connectSlotsByName(Form5);
    } // setupUi

    void retranslateUi(QWidget *Form5)
    {
        Form5->setWindowTitle(QCoreApplication::translate("Form5", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form5: public Ui_Form5 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM5_H
