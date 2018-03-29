/********************************************************************************
** Form generated from reading UI file 'resizedialog.ui'
**
** Created: Tue 2. Oct 10:22:39 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESIZEDIALOG_H
#define UI_RESIZEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_resizeDialog
{
public:
    QGroupBox *groupBox;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QDoubleSpinBox *coeffBox;

    void setupUi(QDialog *resizeDialog)
    {
        if (resizeDialog->objectName().isEmpty())
            resizeDialog->setObjectName(QString::fromUtf8("resizeDialog"));
        resizeDialog->resize(248, 97);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/GUI/Resources/mainicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        resizeDialog->setWindowIcon(icon);
        resizeDialog->setModal(true);
        groupBox = new QGroupBox(resizeDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 231, 81));
        btnOk = new QPushButton(groupBox);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));
        btnOk->setGeometry(QRect(150, 20, 75, 23));
        btnCancel = new QPushButton(groupBox);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(150, 50, 75, 23));
        coeffBox = new QDoubleSpinBox(groupBox);
        coeffBox->setObjectName(QString::fromUtf8("coeffBox"));
        coeffBox->setGeometry(QRect(10, 20, 71, 22));
        coeffBox->setMinimum(0.2);
        coeffBox->setMaximum(4);
        coeffBox->setSingleStep(0.2);
        coeffBox->setValue(1.5);

        retranslateUi(resizeDialog);

        QMetaObject::connectSlotsByName(resizeDialog);
    } // setupUi

    void retranslateUi(QDialog *resizeDialog)
    {
        resizeDialog->setWindowTitle(QApplication::translate("resizeDialog", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("resizeDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\274\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        btnOk->setText(QApplication::translate("resizeDialog", "OK", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("resizeDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class resizeDialog: public Ui_resizeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESIZEDIALOG_H
