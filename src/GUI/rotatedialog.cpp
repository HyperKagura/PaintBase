#include "rotatedialog.h"

rotateDialog::rotateDialog(QWidget *parent,  Qt::WFlags flags)
	: QDialog(parent, Qt::WindowSystemMenuHint)
{
	ui.setupUi(this);

	connect(ui.btnOk, SIGNAL(clicked()), this, SLOT(onRotate()));
	connect(ui.btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
}

rotateDialog::~rotateDialog()
{}

void rotateDialog::onRotate()
{
	angle = this->ui.angleBox->value();
	this->accept();
}

int rotateDialog::getAngle() const
{
	return angle;
}