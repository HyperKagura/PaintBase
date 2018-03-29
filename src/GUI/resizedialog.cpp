#include "resizedialog.h"

resizeDialog::resizeDialog(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, Qt::WindowSystemMenuHint)
{
	ui.setupUi(this);

	connect(ui.btnOk, SIGNAL(clicked()), this, SLOT(onResize()));
	connect(ui.btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
}

resizeDialog::~resizeDialog()
{}

void resizeDialog::onResize()
{
	coeff = this->ui.coeffBox->value();
	this->accept();
}

qreal resizeDialog::getCoeff() const
{
	return coeff;
}
