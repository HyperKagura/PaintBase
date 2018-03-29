#ifndef LINEARDIALOG_H
#define LINEARDIALOG_H

#include <QDialog>
#include "ui_lineardialog.h"
#include "../Engine/Filter.h"

class LinearDialog : public QDialog
{
	Q_OBJECT

	QVector <QVector <QDoubleSpinBox *> > inputMatrix;

	Filter result;

private slots:
	void resize(int width);
	void apply();
    void cancel();

public:
	LinearDialog(QWidget *parent = 0);
	~LinearDialog();

	Filter getFilter();

private:
	Ui::LinearDialog ui;
};

#endif // LINEARDIALOG_H
