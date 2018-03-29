/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created: Tue 2. Oct 18:55:18 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIClass
{
public:
    QAction *mnuOpen;
    QAction *mnuSave;
    QAction *mnuSaveAs;
    QAction *action_4;
    QAction *exit;
    QAction *mnuGrayWorld;
    QAction *action_8;
    QAction *about;
    QAction *mnuGrayscale;
    QAction *mnuHistEq;
    QAction *mnuStretchChan;
    QAction *mnuSobel;
    QAction *mnuMedian;
    QAction *mnuGauss;
    QAction *mnuRotate;
    QAction *mnuResize;
    QAction *mnuLinear;
    QAction *mnuWaves;
    QAction *NeonGlow;
    QAction *mnuMyFilt;
    QWidget *centralWidget;
    QGroupBox *gbImage;
    QPushButton *btnOpen;
    QPushButton *btnSave;
    QPushButton *btnSaveAs;
    QGroupBox *gbFilters;
    QPushButton *btnGrayWorld;
    QPushButton *btnGrayscale;
    QPushButton *btnHistEq;
    QPushButton *btnStretchChan;
    QPushButton *btnSobel;
    QPushButton *btnMedian;
    QPushButton *btnGauss;
    QPushButton *btnLinear;
    QPushButton *btnWaves;
    QPushButton *btnMyFilt;
    QGraphicsView *gvMain;
    QProgressBar *pbMain;
    QGroupBox *Geometry;
    QPushButton *btnRotate;
    QPushButton *btnResize;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;

    void setupUi(QMainWindow *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName(QString::fromUtf8("GUIClass"));
        GUIClass->resize(750, 581);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/GUI/Resources/mainicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        GUIClass->setWindowIcon(icon);
        mnuOpen = new QAction(GUIClass);
        mnuOpen->setObjectName(QString::fromUtf8("mnuOpen"));
        mnuSave = new QAction(GUIClass);
        mnuSave->setObjectName(QString::fromUtf8("mnuSave"));
        mnuSaveAs = new QAction(GUIClass);
        mnuSaveAs->setObjectName(QString::fromUtf8("mnuSaveAs"));
        action_4 = new QAction(GUIClass);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        exit = new QAction(GUIClass);
        exit->setObjectName(QString::fromUtf8("exit"));
        mnuGrayWorld = new QAction(GUIClass);
        mnuGrayWorld->setObjectName(QString::fromUtf8("mnuGrayWorld"));
        action_8 = new QAction(GUIClass);
        action_8->setObjectName(QString::fromUtf8("action_8"));
        about = new QAction(GUIClass);
        about->setObjectName(QString::fromUtf8("about"));
        mnuGrayscale = new QAction(GUIClass);
        mnuGrayscale->setObjectName(QString::fromUtf8("mnuGrayscale"));
        mnuHistEq = new QAction(GUIClass);
        mnuHistEq->setObjectName(QString::fromUtf8("mnuHistEq"));
        mnuStretchChan = new QAction(GUIClass);
        mnuStretchChan->setObjectName(QString::fromUtf8("mnuStretchChan"));
        mnuSobel = new QAction(GUIClass);
        mnuSobel->setObjectName(QString::fromUtf8("mnuSobel"));
        mnuMedian = new QAction(GUIClass);
        mnuMedian->setObjectName(QString::fromUtf8("mnuMedian"));
        mnuGauss = new QAction(GUIClass);
        mnuGauss->setObjectName(QString::fromUtf8("mnuGauss"));
        mnuRotate = new QAction(GUIClass);
        mnuRotate->setObjectName(QString::fromUtf8("mnuRotate"));
        mnuResize = new QAction(GUIClass);
        mnuResize->setObjectName(QString::fromUtf8("mnuResize"));
        mnuLinear = new QAction(GUIClass);
        mnuLinear->setObjectName(QString::fromUtf8("mnuLinear"));
        mnuWaves = new QAction(GUIClass);
        mnuWaves->setObjectName(QString::fromUtf8("mnuWaves"));
        NeonGlow = new QAction(GUIClass);
        NeonGlow->setObjectName(QString::fromUtf8("NeonGlow"));
        mnuMyFilt = new QAction(GUIClass);
        mnuMyFilt->setObjectName(QString::fromUtf8("mnuMyFilt"));
        centralWidget = new QWidget(GUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gbImage = new QGroupBox(centralWidget);
        gbImage->setObjectName(QString::fromUtf8("gbImage"));
        gbImage->setGeometry(QRect(10, 10, 151, 111));
        btnOpen = new QPushButton(gbImage);
        btnOpen->setObjectName(QString::fromUtf8("btnOpen"));
        btnOpen->setGeometry(QRect(10, 20, 131, 23));
        btnSave = new QPushButton(gbImage);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(10, 50, 131, 23));
        btnSaveAs = new QPushButton(gbImage);
        btnSaveAs->setObjectName(QString::fromUtf8("btnSaveAs"));
        btnSaveAs->setGeometry(QRect(10, 80, 131, 23));
        gbFilters = new QGroupBox(centralWidget);
        gbFilters->setObjectName(QString::fromUtf8("gbFilters"));
        gbFilters->setGeometry(QRect(10, 120, 151, 321));
        btnGrayWorld = new QPushButton(gbFilters);
        btnGrayWorld->setObjectName(QString::fromUtf8("btnGrayWorld"));
        btnGrayWorld->setGeometry(QRect(10, 50, 131, 23));
        btnGrayscale = new QPushButton(gbFilters);
        btnGrayscale->setObjectName(QString::fromUtf8("btnGrayscale"));
        btnGrayscale->setGeometry(QRect(10, 20, 131, 23));
        btnHistEq = new QPushButton(gbFilters);
        btnHistEq->setObjectName(QString::fromUtf8("btnHistEq"));
        btnHistEq->setGeometry(QRect(10, 80, 131, 23));
        btnStretchChan = new QPushButton(gbFilters);
        btnStretchChan->setObjectName(QString::fromUtf8("btnStretchChan"));
        btnStretchChan->setGeometry(QRect(10, 110, 131, 23));
        btnSobel = new QPushButton(gbFilters);
        btnSobel->setObjectName(QString::fromUtf8("btnSobel"));
        btnSobel->setGeometry(QRect(10, 140, 131, 23));
        btnMedian = new QPushButton(gbFilters);
        btnMedian->setObjectName(QString::fromUtf8("btnMedian"));
        btnMedian->setGeometry(QRect(10, 170, 131, 23));
        btnGauss = new QPushButton(gbFilters);
        btnGauss->setObjectName(QString::fromUtf8("btnGauss"));
        btnGauss->setGeometry(QRect(10, 200, 131, 23));
        btnLinear = new QPushButton(gbFilters);
        btnLinear->setObjectName(QString::fromUtf8("btnLinear"));
        btnLinear->setGeometry(QRect(10, 230, 131, 23));
        btnWaves = new QPushButton(gbFilters);
        btnWaves->setObjectName(QString::fromUtf8("btnWaves"));
        btnWaves->setGeometry(QRect(10, 260, 131, 23));
        btnMyFilt = new QPushButton(gbFilters);
        btnMyFilt->setObjectName(QString::fromUtf8("btnMyFilt"));
        btnMyFilt->setGeometry(QRect(10, 290, 131, 23));
        gvMain = new QGraphicsView(centralWidget);
        gvMain->setObjectName(QString::fromUtf8("gvMain"));
        gvMain->setGeometry(QRect(170, 10, 571, 511));
        pbMain = new QProgressBar(centralWidget);
        pbMain->setObjectName(QString::fromUtf8("pbMain"));
        pbMain->setGeometry(QRect(10, 530, 731, 23));
        pbMain->setValue(0);
        pbMain->setTextVisible(true);
        pbMain->setInvertedAppearance(false);
        Geometry = new QGroupBox(centralWidget);
        Geometry->setObjectName(QString::fromUtf8("Geometry"));
        Geometry->setGeometry(QRect(10, 440, 151, 80));
        btnRotate = new QPushButton(Geometry);
        btnRotate->setObjectName(QString::fromUtf8("btnRotate"));
        btnRotate->setGeometry(QRect(10, 20, 131, 23));
        btnResize = new QPushButton(Geometry);
        btnResize->setObjectName(QString::fromUtf8("btnResize"));
        btnResize->setGeometry(QRect(10, 50, 131, 23));
        GUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GUIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 750, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        GUIClass->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(mnuOpen);
        menu->addAction(mnuSave);
        menu->addAction(mnuSaveAs);
        menu->addSeparator();
        menu->addAction(exit);
        menu_2->addAction(mnuGrayscale);
        menu_2->addAction(mnuGrayWorld);
        menu_2->addAction(mnuHistEq);
        menu_2->addAction(mnuStretchChan);
        menu_2->addAction(mnuSobel);
        menu_2->addAction(mnuMedian);
        menu_2->addAction(mnuGauss);
        menu_2->addAction(mnuLinear);
        menu_2->addAction(mnuWaves);
        menu_2->addAction(mnuMyFilt);
        menu_3->addAction(about);
        menu_4->addAction(mnuRotate);
        menu_4->addAction(mnuResize);

        retranslateUi(GUIClass);

        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *GUIClass)
    {
        GUIClass->setWindowTitle(QApplication::translate("GUIClass", "Simple image editor", 0, QApplication::UnicodeUTF8));
        mnuOpen->setText(QApplication::translate("GUIClass", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mnuSave->setText(QApplication::translate("GUIClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        mnuSaveAs->setText(QApplication::translate("GUIClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272", 0, QApplication::UnicodeUTF8));
        action_4->setText(QApplication::translate("GUIClass", "-", 0, QApplication::UnicodeUTF8));
        exit->setText(QApplication::translate("GUIClass", "\320\222\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        mnuGrayWorld->setText(QApplication::translate("GUIClass", "\"\320\241\320\265\321\200\321\213\320\271 \320\274\320\270\321\200\"", 0, QApplication::UnicodeUTF8));
        action_8->setText(QApplication::translate("GUIClass", "\320\234\320\265\320\264\320\270\320\260\320\275\320\275\320\260\321\217 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\217", 0, QApplication::UnicodeUTF8));
        about->setText(QApplication::translate("GUIClass", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0, QApplication::UnicodeUTF8));
        mnuGrayscale->setText(QApplication::translate("GUIClass", "Grayscale", 0, QApplication::UnicodeUTF8));
        mnuHistEq->setText(QApplication::translate("GUIClass", "\320\220\320\262\321\202\320\276\320\272\320\276\320\275\321\202\321\200\320\260\321\201\321\202", 0, QApplication::UnicodeUTF8));
        mnuStretchChan->setText(QApplication::translate("GUIClass", "\320\232\320\276\320\275\321\202\321\200\320\260\321\201\321\202", 0, QApplication::UnicodeUTF8));
        mnuSobel->setText(QApplication::translate("GUIClass", "\320\241\320\276\320\261\320\265\320\273\321\214", 0, QApplication::UnicodeUTF8));
        mnuMedian->setText(QApplication::translate("GUIClass", "\320\234\320\265\320\264\320\270\320\260\320\275\320\260", 0, QApplication::UnicodeUTF8));
        mnuGauss->setText(QApplication::translate("GUIClass", "\320\244\320\270\320\273\321\214\321\202\321\200 \320\223\320\260\321\203\321\201\321\201\320\260", 0, QApplication::UnicodeUTF8));
        mnuRotate->setText(QApplication::translate("GUIClass", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", 0, QApplication::UnicodeUTF8));
        mnuResize->setText(QApplication::translate("GUIClass", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        mnuLinear->setText(QApplication::translate("GUIClass", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\273\321\214\320\275\321\213\320\271 \320\233\320\244", 0, QApplication::UnicodeUTF8));
        mnuWaves->setText(QApplication::translate("GUIClass", "\320\222\320\276\320\273\320\275\321\213", 0, QApplication::UnicodeUTF8));
        NeonGlow->setText(QApplication::translate("GUIClass", "\320\235\320\265\320\276\320\275\320\276\320\262\321\213\320\271 \321\201\320\262\320\265\321\202", 0, QApplication::UnicodeUTF8));
        mnuMyFilt->setText(QApplication::translate("GUIClass", "\320\234\320\276\320\271 \321\204\320\270\320\273\321\214\321\202\321\200", 0, QApplication::UnicodeUTF8));
        gbImage->setTitle(QApplication::translate("GUIClass", "\320\244\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        btnOpen->setText(QApplication::translate("GUIClass", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
        btnSave->setText(QApplication::translate("GUIClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        btnSaveAs->setText(QApplication::translate("GUIClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", 0, QApplication::UnicodeUTF8));
        gbFilters->setTitle(QApplication::translate("GUIClass", "\320\244\320\270\320\273\321\214\321\202\321\200\321\213", 0, QApplication::UnicodeUTF8));
        btnGrayWorld->setText(QApplication::translate("GUIClass", "\"\320\241\320\265\321\200\321\213\320\271 \320\274\320\270\321\200\"", 0, QApplication::UnicodeUTF8));
        btnGrayscale->setText(QApplication::translate("GUIClass", "Grayscale", 0, QApplication::UnicodeUTF8));
        btnHistEq->setText(QApplication::translate("GUIClass", "\320\220\320\262\321\202\320\276\320\272\320\276\320\275\321\202\321\200\320\260\321\201\321\202", 0, QApplication::UnicodeUTF8));
        btnStretchChan->setText(QApplication::translate("GUIClass", "\320\232\320\276\320\275\321\202\321\200\320\260\321\201\321\202", 0, QApplication::UnicodeUTF8));
        btnSobel->setText(QApplication::translate("GUIClass", "\320\241\320\276\320\261\320\265\320\273\321\214", 0, QApplication::UnicodeUTF8));
        btnMedian->setText(QApplication::translate("GUIClass", "\320\234\320\265\320\264\320\270\320\260\320\275\320\260", 0, QApplication::UnicodeUTF8));
        btnGauss->setText(QApplication::translate("GUIClass", "\320\244\320\270\320\273\321\214\321\202\321\200 \320\223\320\260\321\203\321\201\321\201\320\260", 0, QApplication::UnicodeUTF8));
        btnLinear->setText(QApplication::translate("GUIClass", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\273\321\214\320\275\321\213\320\271 \320\233\320\244", 0, QApplication::UnicodeUTF8));
        btnWaves->setText(QApplication::translate("GUIClass", "\320\222\320\276\320\273\320\275\321\213", 0, QApplication::UnicodeUTF8));
        btnMyFilt->setText(QApplication::translate("GUIClass", "\320\234\320\276\320\271 \321\204\320\270\320\273\321\214\321\202\321\200", 0, QApplication::UnicodeUTF8));
        pbMain->setFormat(QApplication::translate("GUIClass", "%p%", 0, QApplication::UnicodeUTF8));
        Geometry->setTitle(QApplication::translate("GUIClass", "\320\237\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\321\217 \320\263\320\265\320\276\320\274\320\265\321\202\321\200\320\270\320\270", 0, QApplication::UnicodeUTF8));
        btnRotate->setText(QApplication::translate("GUIClass", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", 0, QApplication::UnicodeUTF8));
        btnResize->setText(QApplication::translate("GUIClass", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("GUIClass", "\320\244\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("GUIClass", "\320\244\320\270\320\273\321\214\321\202\321\200\321\213", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("GUIClass", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
        menu_4->setTitle(QApplication::translate("GUIClass", "\320\223\320\265\320\276\320\274\320\265\321\202\321\200\320\270\321\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
