#include "wavesdialog.h"

wavesDialog::wavesDialog(QWidget *parent,  Qt::WFlags flags)
	: QDialog(parent, Qt::WindowSystemMenuHint)
{
	ui.setupUi(this);

	connect(ui.btnOk, SIGNAL(clicked()), this, SLOT(onWaves()));
	connect(ui.btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
}

wavesDialog::~wavesDialog()
{}

void wavesDialog::onWaves()
{
	amplitX = this->ui.amplitudeXBox->value();
	amplitY = this->ui.amplitudeYBox->value();
	length = this->ui.lengthBox->value();
	this->accept();
}

qreal wavesDialog::getAX() const
{
	return amplitX;
}

qreal wavesDialog::getAY() const
{
	return amplitY;
}

qreal wavesDialog::getLength() const
{
	return length;
}