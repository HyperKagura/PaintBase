#include "lineardialog.h"

LinearDialog::LinearDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	this->resize(1);

    this->connect(this->ui.sizeBox, SIGNAL(valueChanged(int)), this, SLOT(resize(int)));
    this->connect(this->ui.btnOk, SIGNAL(released()), this, SLOT(apply()));
    this->connect(this->ui.btnCancel, SIGNAL(released()), this, SLOT(cancel()));
}

LinearDialog::~LinearDialog()
{}

void LinearDialog::resize(int rad) {
    for (int i = 0; i < this->inputMatrix.size(); i++) {
        for (int j = 0; j < this->inputMatrix[i].size(); j++) {
            if (i >= rad*2+1 || j >= rad*2+1) {
                delete this->inputMatrix[i][j];
            }
        }
    }

    this->inputMatrix.resize(rad*2+1);

    for (int i = 0; i < rad*2 +1; i++) {
        this->inputMatrix[i].resize(rad*2+1);
    }

    for (int i = 0; i < this->inputMatrix.size(); i++) {
        for (int j = 0; j < this->inputMatrix[i].size(); j++) {
            if (this->inputMatrix[i][j] == NULL) {
                this->inputMatrix[i][j] = new QDoubleSpinBox(this);
                this->inputMatrix[i][j]->setMinimum(-100.0);
                this->inputMatrix[i][j]->setMaximum(100.0);
                this->inputMatrix[i][j]->setValue(0.0);
                this->inputMatrix[i][j]->setSingleStep(1.0);
                this->ui.layoutInputMatrix->addWidget(this->inputMatrix[i][j], j, i);
            }
        }
    }
}

void LinearDialog::apply() {
    this->result = Filter(this->inputMatrix[0].size(), this->inputMatrix.size());

    for (int x = 0; x < this->result.width(); x++) {
        for (int y = 0; y < this->result.height(); y++) {
            this->result.at(x, y) = this->inputMatrix[x][y]->value();
        }
    }

	this->accept();
}

void LinearDialog::cancel() {
    this->reject();
}

Filter LinearDialog::getFilter() {
    return this->result;
}