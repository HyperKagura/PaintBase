/********************************************************************************
** Form generated from reading UI file 'sigma.ui'
**
** Created: Tue 2. Oct 10:22:39 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGMA_H
#define UI_SIGMA_H

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

class Ui_Sigma
{
public:
    QGroupBox *groupBox;
    QPushButton *btnOk;
    QDoubleSpinBox *sigmaBox;
    QPushButton *btnCancel;

    void setupUi(QDialog *Sigma)
    {
        if (Sigma->objectName().isEmpty())
            Sigma->setObjectName(QString::fromUtf8("Sigma"));
        Sigma->resize(218, 100);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/GUI/Resources/mainicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Sigma->setWindowIcon(icon);
        Sigma->setModal(true);
        groupBox = new QGroupBox(Sigma);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 201, 81));
        btnOk = new QPushButton(groupBox);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));
        btnOk->setGeometry(QRect(120, 20, 75, 23));
        sigmaBox = new QDoubleSpinBox(groupBox);
        sigmaBox->setObjectName(QString::fromUtf8("sigmaBox"));
        sigmaBox->setGeometry(QRect(10, 20, 81, 21));
        sigmaBox->setDecimals(3);
        sigmaBox->setMinimum(0.3);
        sigmaBox->setMaximum(5);
        sigmaBox->setSingleStep(0.001);
        sigmaBox->setValue(0.3);
        btnCancel = new QPushButton(groupBox);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(120, 50, 75, 23));

        retranslateUi(Sigma);

        QMetaObject::connectSlotsByName(Sigma);
    } // setupUi

    void retranslateUi(QDialog *Sigma)
    {
        Sigma->setWindowTitle(QApplication::translate("Sigma", "Sigma", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Sigma", "\320\222\321\213\320\261\320\265\321\200\320\265\321\202\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200", 0, QApplication::UnicodeUTF8));
        btnOk->setText(QApplication::translate("Sigma", "OK", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("Sigma", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Sigma: public Ui_Sigma {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGMA_H
