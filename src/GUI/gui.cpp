#include "gui.h"

void GUI::onInit()
{
	QRect qrGeometry;
	QSize szWindow;

	//move window to screen center
	qrGeometry = frameGeometry();
	qrGeometry.moveCenter(QDesktopWidget().availableGeometry().center());
	move(qrGeometry.topLeft());

	//make window fixed-sized
	szWindow = size();
	setMaximumSize(szWindow);
	setMinimumSize(szWindow);

	// set default encoding to cp1251
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1251"));

	m_pCurrentScene = NULL;
	m_Engine.setCallbacks((PCALLBACK)callback, this);
}

void GUI::updateImage()
{
	QPixmap pmNew = QPixmap::fromImage(m_Engine.getImage());
	QGraphicsScene *pNewScene = new QGraphicsScene;
	pNewScene->addPixmap(pmNew);
	ui.gvMain->setScene(pNewScene);
	if (m_pCurrentScene != NULL) delete m_pCurrentScene;
	m_pCurrentScene = pNewScene;
}

void GUI::onOpen()
{
	string sPath;

	sPath = QFileDialog::getOpenFileName(this, "Загрузка изображения",
		QString("C:\\"), "Изображения (*.jpg;*.png;*.bmp)").toStdString();
	if (sPath.empty()) return;

	if (!m_Engine.load(sPath))
	{
		QMessageBox::critical(this, "Ошибка", "Не удаётся загрузить изображение");
		return;
	};

	updateImage();
	m_sPath = sPath;
}

void GUI::onSaveAs()
{
	string sPath;

	sPath = QFileDialog::getSaveFileName(this, "Загрузка изображения",
		QString("C:\\"), "Изображения (*.jpg;*.png;*.bmp)").toStdString();
	if (sPath.empty()) return;

	if (!m_Engine.save(sPath))
	{
		QMessageBox::critical(this, "Ошибка", "Не удаётся сохранить изображение");
		return;
	};

	m_sPath = sPath;
}

void GUI::onSave()
{
	if (!m_Engine.save(m_sPath))
	{
		QMessageBox::critical(this, "Ошибка", "Не удаётся сохранить изображение");
		return;
	}
}

void QGrayscaleThread::run()
{
	m_lEngine.toGrayscale();
}

void QMyFiltThread::run()
{
	m_lEngine.toMyFiltr();
}

void QGrayWorldThread::run()
{
	m_lEngine.toGrayWorld();
}

void QMedianThread::run()
{
	m_lEngine.toMedian();
}

void QGaussThread::run()
{
	m_lEngine.toGauss();
}

void QLinearThread::run()
{
	m_lEngine.toLinearFil();
}

void QRotateThread::run()
{
	m_lEngine.toRotate();
}

void QResizeThread::run()
{
	m_lEngine.toResize();
}

void QWavesThread::run()
{
	m_lEngine.toWaves();
}

void QHistEqThread::run()
{
	m_lEngine.toHistEq();
}

void QStretchChanThread::run()
{
	m_lEngine.toStretchChan();
}

void QSobelThread::run()
{
	m_lEngine.toSobel();
}

//писать сюда

void QGaussThread::setSigmaVal(double val)
{
	this->m_lEngine.setSigma(val);
}

void QRotateThread::setAngleVal(double val)
{
	this->m_lEngine.setAngle(val);
}

void QResizeThread::setSigmaVal(qreal val)
{
	this->m_lEngine.setSigma(val);
}

void QLinearThread::setFilter(Filter fil)
{
	this->m_lEngine.setFilter(fil);
}

void QWavesThread::setAllVal(qreal xVal, qreal yVal, qreal length)
{
	this->m_lEngine.setAmplitude(xVal,yVal);
	this->m_lEngine.setSigma(length);
}

void GUI::onGrayscale()
{
	enableControls(false);
	m_GrayscaleThread.start();
}

void GUI::onGrayWorld()
{
	enableControls(false);
	m_GrayWorldThread.start();
}

void GUI::onMedian()
{
	enableControls(false);
	m_MedianThread.start();
}

void GUI::onMyFilt()
{
	enableControls(false);
	m_MyFiltThread.start();
}

void GUI::onGauss()
{
	Sigma *pDialog = new Sigma(this);
	if ( pDialog->exec() == QDialog::Accepted )
	{
		double sigmaVal = pDialog->getSigma();
		m_GaussThread.setSigmaVal(sigmaVal);
		enableControls(false);
		m_GaussThread.start();
	}
	delete pDialog;
}

void GUI::onLinear()
{
	LinearDialog *pDialog = new LinearDialog(this);
	if ( pDialog->exec() == QDialog::Accepted )
	{
		Filter filVal = pDialog->getFilter();
		m_LinearThread.setFilter(filVal);
		enableControls(false);
		m_LinearThread.start();
	}
	delete pDialog;
}

void GUI::onRotate()
{
	rotateDialog *pDialog = new rotateDialog(this);
	if ( pDialog->exec() == QDialog::Accepted )
	{
		int angleVal = pDialog->getAngle();
		m_RotateThread.setAngleVal(angleVal);
		enableControls(false);
		m_RotateThread.start();
	}
	delete pDialog;
}

void GUI::onWaves()
{
	wavesDialog *pDialog = new wavesDialog(this);
	if ( pDialog->exec() == QDialog::Accepted )
	{
		qreal xVal = pDialog->getAX();
		qreal yVal = pDialog->getAY();
		qreal leng = pDialog->getLength();
		m_WavesThread.setAllVal(xVal,yVal,leng);
		enableControls(false);
		m_WavesThread.start();
	}
	delete pDialog;
}

void GUI::onResize()
{
	resizeDialog *pDialog = new resizeDialog(this);
	if ( pDialog->exec() == QDialog::Accepted )
	{
		qreal sigmaVal = pDialog->getCoeff();
		m_ResizeThread.setSigmaVal(sigmaVal);
		enableControls(false);
		m_ResizeThread.start();
	}
	delete pDialog;
}

void GUI::onHistEq()
{
	enableControls(false);
	m_HistEqThread.start();
}

void GUI::onStretchChan()
{
	enableControls(false);
	m_StretchChanThread.start();
}

void GUI::onSobel()
{
	enableControls(false);
	m_SobelThread.start();
}

//писать сюда

GUI::GUI(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags), m_GrayscaleThread(m_Engine), m_HistEqThread(m_Engine), m_StretchChanThread(m_Engine), m_SobelThread(m_Engine), m_MedianThread(m_Engine), m_GrayWorldThread(m_Engine), m_GaussThread(m_Engine), m_RotateThread(m_Engine), m_LinearThread(m_Engine), m_ResizeThread(m_Engine), m_WavesThread(m_Engine), m_MyFiltThread(m_Engine)
{
	ui.setupUi(this);
	onInit();

	connect(ui.btnOpen, SIGNAL(clicked()), this, SLOT(onOpen()));
	connect(ui.mnuOpen, SIGNAL(activated()), this, SLOT(onOpen()));
	connect(ui.btnSave, SIGNAL(clicked()), this, SLOT(onSave()));
	connect(ui.mnuSave, SIGNAL(activated()), this, SLOT(onSave()));
	connect(ui.btnSaveAs, SIGNAL(clicked()), this, SLOT(onSaveAs()));
	connect(ui.mnuSaveAs, SIGNAL(activated()), this, SLOT(onSaveAs()));
	
	connect(ui.btnGrayscale, SIGNAL(clicked()), this, SLOT(onGrayscale()));
	connect(ui.mnuGrayscale, SIGNAL(activated()), this, SLOT(onGrayscale()));
	connect(ui.btnHistEq, SIGNAL(clicked()), this, SLOT(onHistEq()));
	connect(ui.mnuHistEq, SIGNAL(activated()), this, SLOT(onHistEq()));
	connect(ui.btnStretchChan, SIGNAL(clicked()), this, SLOT(onStretchChan()));
	connect(ui.mnuStretchChan, SIGNAL(activated()), this, SLOT(onStretchChan()));
	connect(ui.btnSobel, SIGNAL(clicked()), this, SLOT(onSobel()));
	connect(ui.mnuSobel, SIGNAL(activated()), this, SLOT(onSobel()));
	connect(ui.btnMedian, SIGNAL(clicked()), this, SLOT(onMedian()));
	connect(ui.mnuMedian, SIGNAL(activated()), this, SLOT(onMedian()));
	connect(ui.btnGrayWorld, SIGNAL(clicked()), this, SLOT(onGrayWorld()));
	connect(ui.mnuGrayWorld, SIGNAL(activated()), this, SLOT(onGrayWorld()));
	connect(ui.btnGauss, SIGNAL(clicked()), this, SLOT(onGauss()));
	connect(ui.mnuGauss, SIGNAL(activated()), this, SLOT(onGauss()));
	connect(ui.btnRotate, SIGNAL(clicked()), this, SLOT(onRotate()));
	connect(ui.mnuRotate, SIGNAL(activated()), this, SLOT(onRotate()));
	connect(ui.btnLinear, SIGNAL(clicked()), this, SLOT(onLinear()));
	connect(ui.mnuLinear, SIGNAL(activated()), this, SLOT(onLinear()));
	connect(ui.btnResize, SIGNAL(clicked()), this, SLOT(onResize()));
	connect(ui.mnuResize, SIGNAL(activated()), this, SLOT(onResize()));
	connect(ui.btnWaves, SIGNAL(clicked()), this, SLOT(onWaves()));
	connect(ui.mnuWaves, SIGNAL(activated()), this, SLOT(onWaves()));
	connect(ui.btnMyFilt, SIGNAL(clicked()), this, SLOT(onMyFilt()));
	connect(ui.mnuMyFilt, SIGNAL(activated()), this, SLOT(onMyFilt()));


	//писать сюда
}

GUI::~GUI()
{}

void GUI::callback(uint percent, GUI* pThis)
{
	QProgressEvent *pEvent = new QProgressEvent;
	pEvent->percent = percent;
	QCoreApplication::postEvent(pThis, pEvent);
}

void GUI::enableControls(bool in_bEnable)
{
	ui.gbImage->setEnabled(in_bEnable);
	ui.gbFilters->setEnabled(in_bEnable);
	ui.menuBar->setEnabled(in_bEnable);
	ui.Geometry->setEnabled(in_bEnable);
}

bool GUI::event(QEvent *event)
{
	if (event->type() == (QEvent::Type)(QEvent::User + 1))
	{
		// Progress event
		QProgressEvent *pEvent = (QProgressEvent*)event;
		ui.pbMain->setValue(pEvent->percent);
		if (pEvent->percent == 100)
		{
			enableControls(true);
			updateImage();
		}
	}

	return QMainWindow::event(event);
}
