/********************************************************************************
** Form generated from reading UI file 'rotatedialog.ui'
**
** Created: Tue 2. Oct 10:22:39 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROTATEDIALOG_H
#define UI_ROTATEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_rotateDialog
{
public:
    QGroupBox *groupBox;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpinBox *angleBox;

    void setupUi(QDialog *rotateDialog)
    {
        if (rotateDialog->objectName().isEmpty())
            rotateDialog->setObjectName(QString::fromUtf8("rotateDialog"));
        rotateDialog->resize(189, 99);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/GUI/Resources/mainicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        rotateDialog->setWindowIcon(icon);
        rotateDialog->setModal(true);
        groupBox = new QGroupBox(rotateDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 171, 81));
        btnOk = new QPushButton(groupBox);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));
        btnOk->setGeometry(QRect(90, 20, 75, 23));
        btnCancel = new QPushButton(groupBox);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(90, 50, 75, 23));
        angleBox = new QSpinBox(groupBox);
        angleBox->setObjectName(QString::fromUtf8("angleBox"));
        angleBox->setGeometry(QRect(20, 20, 51, 22));
        angleBox->setMaximum(360);

        retranslateUi(rotateDialog);

        QMetaObject::connectSlotsByName(rotateDialog);
    } // setupUi

    void retranslateUi(QDialog *rotateDialog)
    {
        rotateDialog->setWindowTitle(QApplication::translate("rotateDialog", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("rotateDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\203\320\263\320\276\320\273 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260", 0, QApplication::UnicodeUTF8));
        btnOk->setText(QApplication::translate("rotateDialog", "OK", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("rotateDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        angleBox->setSuffix(QApplication::translate("rotateDialog", "\302\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class rotateDialog: public Ui_rotateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROTATEDIALOG_H
