/********************************************************************************
** Form generated from reading UI file 'wavesdialog.ui'
**
** Created: Tue 2. Oct 18:55:18 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAVESDIALOG_H
#define UI_WAVESDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_wavesDialog
{
public:
    QGroupBox *groupBox;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QDoubleSpinBox *amplitudeXBox;
    QDoubleSpinBox *lengthBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *amplitudeYBox;

    void setupUi(QDialog *wavesDialog)
    {
        if (wavesDialog->objectName().isEmpty())
            wavesDialog->setObjectName(QString::fromUtf8("wavesDialog"));
        wavesDialog->resize(279, 126);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/GUI/Resources/mainicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        wavesDialog->setWindowIcon(icon);
        wavesDialog->setModal(true);
        groupBox = new QGroupBox(wavesDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 261, 111));
        btnOk = new QPushButton(groupBox);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));
        btnOk->setGeometry(QRect(180, 20, 75, 23));
        btnCancel = new QPushButton(groupBox);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(180, 50, 75, 23));
        amplitudeXBox = new QDoubleSpinBox(groupBox);
        amplitudeXBox->setObjectName(QString::fromUtf8("amplitudeXBox"));
        amplitudeXBox->setGeometry(QRect(100, 20, 62, 22));
        amplitudeXBox->setMinimum(-100);
        amplitudeXBox->setMaximum(100);
        amplitudeXBox->setSingleStep(3);
        amplitudeXBox->setValue(4);
        lengthBox = new QDoubleSpinBox(groupBox);
        lengthBox->setObjectName(QString::fromUtf8("lengthBox"));
        lengthBox->setGeometry(QRect(100, 80, 62, 22));
        lengthBox->setMinimum(3);
        lengthBox->setMaximum(50);
        lengthBox->setSingleStep(3);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 81, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 81, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 80, 71, 21));
        amplitudeYBox = new QDoubleSpinBox(groupBox);
        amplitudeYBox->setObjectName(QString::fromUtf8("amplitudeYBox"));
        amplitudeYBox->setGeometry(QRect(100, 50, 62, 22));
        amplitudeYBox->setMinimum(-100);
        amplitudeYBox->setMaximum(1050);
        amplitudeYBox->setSingleStep(3);
        amplitudeYBox->setValue(4);

        retranslateUi(wavesDialog);

        QMetaObject::connectSlotsByName(wavesDialog);
    } // setupUi

    void retranslateUi(QDialog *wavesDialog)
    {
        wavesDialog->setWindowTitle(QApplication::translate("wavesDialog", "\320\255\321\204\321\204\320\265\320\272\321\202 \"\320\222\320\276\320\273\320\275\321\213\"", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("wavesDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213:", 0, QApplication::UnicodeUTF8));
        btnOk->setText(QApplication::translate("wavesDialog", "\320\236\320\232", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("wavesDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("wavesDialog", "\320\220\320\274\320\277\320\273\320\270\321\202\321\203\320\264\320\260 \320\277\320\276 X", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("wavesDialog", "\320\220\320\274\320\277\320\273\320\270\321\202\321\203\320\264\320\260 \320\277\320\276 Y", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("wavesDialog", "\320\224\320\273\320\270\320\275\320\260 \320\262\320\276\320\273\320\275\321\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class wavesDialog: public Ui_wavesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAVESDIALOG_H
