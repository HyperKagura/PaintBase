#ifndef GUI_H
#define GUI_H

#include <string>
#include <vector>
#include <fstream>
using namespace std;
#include <QtGui/QMainWindow>
#include "ui_gui.h"
#include "sigma.h"
#include "rotatedialog.h"
#include "resizedialog.h"
#include "lineardialog.h"
#include "wavesdialog.h"
#include <QDesktopWidget>
#include <QTextCodec>
#include <QMessageBox>
#include <QFileDialog>
#include <QClipboard>
#include <QTimer>
#include <QThread>
#include <QDesktopServices>

#include "../Engine/CEngine.h"

#ifndef uint
typedef unsigned int uint;
#endif //uint

class QGrayscaleThread;

class QGrayscaleThread : public QThread
{
	Q_OBJECT

	CEngine& m_lEngine;

protected:
	void run();

public:
	QGrayscaleThread(CEngine& in_lEngine) : m_lEngine(in_lEngine) {};
};

class QMyFiltThread : public QThread
{
	Q_OBJECT

	CEngine& m_lEngine;

protected:
	void run();

public:
	QMyFiltThread(CEngine& in_lEngine) : m_lEngine(in_lEngine) {};
};

class QGaussThread : public QThread
{
	Q_OBJECT

	CEngine& m_lEngine;

protected:
	void run();

public:
	void setSigmaVal(double val);
	QGaussThread(CEngine& in_lEngine) : m_lEngine(in_lEngine) {};
};

class QLinearThread : public QThread
{
	Q_OBJECT

	CEngine& m_lEngine;

protected:
	void run();

public:
	void setFilter(Filter fil);
	QLinearThread(CEngine& in_lEngine) : m_lEngine(in_lEngine) {};
};

class QRotateThread : public QThread
{
	Q_OBJECT

	CEngine& m_lEngine;

protected:
	void run();

public:
	void setAngleVal(double val);
	QRotateThread(CEngine& in_lEngine) : m_lEngine(in_lEngine) {};
};

class QResizeThread : public QThread
{
	Q_OBJECT

	CEngine& m_lEngine;

protected:
	void run();

public:
	void setSigmaVal(qreal val);
	QResizeThread(CEngine& in_lEngine) : m_lEngine(in_lEngine) {};
};

class QWavesThread : public QThread
{
	Q_OBJECT

	CEngine& m_lEngine;

protected:
	void run();

public:
	void setAllVal(qreal xVal, qreal yVal, qreal length);
	QWavesThread(CEngine& in_lEngine) : m_lEngine(in_lEngine) {};
};

class QGrayWorldThread : public QThread
{
	Q_OBJECT

	CEngine& m_lEngine;

protected:
	void run();

public:
	QGrayWorldThread(CEngine& in_lEngine) : m_lEngine(in_lEngine) {};
};

class QSobelThread : public QThread
{
	Q_OBJECT

	CEngine& m_lEngine;

protected:
	void run();

public:
	QSobelThread(CEngine& in_lEngine) : m_lEngine(in_lEngine) {};
};

class QMedianThread : public QThread
{
	Q_OBJECT

	CEngine& m_lEngine;

protected:
	void run();

public:
	QMedianThread(CEngine& in_lEngine) : m_lEngine(in_lEngine) {};
};

class QStretchChanThread : public QThread
{
	Q_OBJECT

	CEngine& m_lEngine;

protected:
	void run();

public:
	QStretchChanThread(CEngine& in_lEngine) : m_lEngine(in_lEngine) {};
};

class  QProgressEvent : public QEvent
{
public:
	uint percent;
	QProgressEvent() : QEvent((QEvent::Type)(QEvent::User + 1)) {};
};

class QHistEqThread : public QThread
{
	Q_OBJECT

	CEngine& m_lEngine;

protected:
	void run();

public:
	QHistEqThread(CEngine& in_lEngine) : m_lEngine(in_lEngine) {};
};

class GUI : public QMainWindow
{
	Q_OBJECT

public:
	GUI(QWidget *parent = 0, Qt::WFlags flags = 0);
	~GUI();

private slots:
	void onOpen();
	void onSave();
	void onSaveAs();

	void onGrayscale();
	void onHistEq();
	void onStretchChan();
	void onSobel();
	void onMedian();
	void onGrayWorld();
	void onGauss();
	void onRotate();
	void onLinear();
	void onResize();
	void onWaves();
	void onMyFilt();

protected:
	bool event(QEvent *event);

private:
	Ui::GUIClass ui;
	CEngine m_Engine;
	string m_sPath;
	QGaussThread m_GaussThread;
	QGraphicsScene *m_pCurrentScene;
	QGrayscaleThread m_GrayscaleThread;
	QHistEqThread m_HistEqThread;
	QStretchChanThread m_StretchChanThread;
	QSobelThread m_SobelThread;
	QMedianThread m_MedianThread;
	QGrayWorldThread m_GrayWorldThread;
	QRotateThread m_RotateThread;
	QLinearThread m_LinearThread;
	QResizeThread m_ResizeThread;
	QWavesThread m_WavesThread;
	QMyFiltThread m_MyFiltThread;

	//писать сюда

	void onInit();
	void updateImage();
	void enableControls(bool in_bEnable);

	static void callback(uint percent, GUI* pThis);
};

#endif // GUI_H
