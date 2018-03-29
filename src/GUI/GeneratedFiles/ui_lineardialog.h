/********************************************************************************
** Form generated from reading UI file 'lineardialog.ui'
**
** Created: Tue 2. Oct 10:22:39 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEARDIALOG_H
#define UI_LINEARDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LinearDialog
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *layoutInputMatrix;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *sizeBox;
    QFrame *line_4;
    QSpacerItem *horizontalSpacer;
    QFrame *line_6;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void setupUi(QDialog *LinearDialog)
    {
        if (LinearDialog->objectName().isEmpty())
            LinearDialog->setObjectName(QString::fromUtf8("LinearDialog"));
        LinearDialog->resize(327, 240);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/GUI/Resources/mainicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        LinearDialog->setWindowIcon(icon);
        LinearDialog->setModal(true);
        horizontalLayoutWidget = new QWidget(LinearDialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 60, 311, 171));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        layoutInputMatrix = new QGridLayout();
        layoutInputMatrix->setSpacing(6);
        layoutInputMatrix->setObjectName(QString::fromUtf8("layoutInputMatrix"));

        horizontalLayout_2->addLayout(layoutInputMatrix);

        horizontalLayoutWidget_2 = new QWidget(LinearDialog);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 10, 311, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        sizeBox = new QSpinBox(horizontalLayoutWidget_2);
        sizeBox->setObjectName(QString::fromUtf8("sizeBox"));
        sizeBox->setMinimum(1);
        sizeBox->setMaximum(3);

        horizontalLayout_3->addWidget(sizeBox);

        line_4 = new QFrame(horizontalLayoutWidget_2);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        line_6 = new QFrame(horizontalLayoutWidget_2);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_6);

        btnOk = new QPushButton(horizontalLayoutWidget_2);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout_3->addWidget(btnOk);

        btnCancel = new QPushButton(horizontalLayoutWidget_2);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_3->addWidget(btnCancel);


        retranslateUi(LinearDialog);

        QMetaObject::connectSlotsByName(LinearDialog);
    } // setupUi

    void retranslateUi(QDialog *LinearDialog)
    {
        LinearDialog->setWindowTitle(QApplication::translate("LinearDialog", "\320\233\320\270\320\275\320\265\320\271\320\275\321\213\320\271 \321\204\320\270\320\273\321\214\321\202\321\200", 0, QApplication::UnicodeUTF8));
        sizeBox->setSuffix(QApplication::translate("LinearDialog", " px", 0, QApplication::UnicodeUTF8));
        btnOk->setText(QApplication::translate("LinearDialog", "OK", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("LinearDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LinearDialog: public Ui_LinearDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEARDIALOG_H
