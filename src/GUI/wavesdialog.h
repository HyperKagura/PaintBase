#ifndef WAVESDIALOG_H
#define WAVESDIALOG_H

#include <QDialog>
#include "ui_wavesdialog.h"
#include <QtGui/QMainWindow>
#include <QDesktopWidget>
#include <QDesktopServices>
#include <QWidget>

class wavesDialog : public QDialog
{
	Q_OBJECT

	qreal amplitX;
	qreal amplitY;
	qreal length;

public:
	wavesDialog(QWidget *parent = 0, Qt::WFlags flags = 0);
	~wavesDialog();

	qreal getAX() const;
	qreal getAY() const;
	qreal getLength() const;

private slots:
	void onWaves();

private:
	Ui::wavesDialog ui;
};

#endif // WAVESDIALOG_H
