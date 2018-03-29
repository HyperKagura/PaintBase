#ifndef SIGMA_H
#define SIGMA_H

#include <QDialog>
using namespace std;
#include "ui_sigma.h"
#include <QtGui/QMainWindow>
#include <QDesktopWidget>
#include <QDesktopServices>
#include <QWidget>

class Sigma : public QDialog
{
	Q_OBJECT

	double m_sigma;

public:
	Sigma(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Sigma();

	double getSigma() const;

private slots:
	void onSigma();

private:
	Ui::Sigma ui;
};

#endif // SIGMA_H
