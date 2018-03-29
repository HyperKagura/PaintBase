#ifndef RESIZEDIALOG_H
#define RESIZEDIALOG_H

#include <QDialog>
#include "ui_resizedialog.h"
#include <QtGui/QMainWindow>
#include <QDesktopWidget>
#include <QDesktopServices>
#include <QWidget>

class resizeDialog : public QDialog
{
	Q_OBJECT

	qreal coeff;

public:
	resizeDialog(QWidget *parent = 0, Qt::WFlags flags  = 0);
	~resizeDialog();

	qreal getCoeff() const;

private slots:
	void onResize();

private:
	Ui::resizeDialog ui;
};

#endif // RESIZEDIALOG_H
