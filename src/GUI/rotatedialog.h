#ifndef ROTATEDIALOG_H
#define ROTATEDIALOG_H

#include <QDialog>
#include "ui_rotatedialog.h"
#include <QtGui/QMainWindow>
#include <QDesktopWidget>
#include <QDesktopServices>
#include <QWidget>

class rotateDialog : public QDialog
{
	Q_OBJECT
		
	int angle;

public:
	rotateDialog(QWidget *parent = 0, Qt::WFlags flags = 0);
	~rotateDialog();

	int getAngle() const;


private slots:
	void onRotate();
	
private:
	Ui::rotateDialog ui;
};

#endif // ROTATEDIALOG_H
