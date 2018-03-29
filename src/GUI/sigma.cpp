#include "sigma.h"

Sigma::Sigma(QWidget *parent,  Qt::WFlags flags)
	: QDialog(parent, Qt::WindowSystemMenuHint)
{
	ui.setupUi(this);

	connect(ui.btnOk, SIGNAL(clicked()), this, SLOT(onSigma()));
	connect(ui.btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
}

Sigma::~Sigma()
{}

void Sigma::onSigma()
{
	m_sigma = this->ui.sigmaBox->value();
	this->accept();
}

double Sigma::getSigma() const
{
	return this->m_sigma;
}