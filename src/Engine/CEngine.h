#pragma once
#ifndef _CENGINE_H
#define _CENGINE_H

#include <string>
using namespace std;
#include <QImage>
#include <QtCore/qmath.h>
#include <QVector>
#include <QPoint>
#include <QRect>
#include <QtAlgorithms>
#include <QDebug>
#include <cmath>
#include <Windows.h>
#include "Filter.h"

typedef void (*PCALLBACK)(uint percent, void *extra);

class CEngine
{
	QImage m_Image;
	PCALLBACK m_fnCallback;
	void *m_pCallbackExtra;

	qreal sigma;
	qreal amplitudeX;
	qreal amplitudeY;
	int angle;
	Filter mFilter;

public:
	CEngine();

	void setCallbacks(PCALLBACK in_fnCallback, void *in_pCallbackExtra);

	bool load(const string& in_sPath);
	bool save(const string& in_sPath);

	const QImage& getImage() const;

	void setSigma(double val);
	void setAmplitude(double valX, double valY);
	void setAngle(int val);
	void setFilter(Filter filt);
	QImage setMyFiltr(int width, int height, uint uiQuantum);

	void toGrayscale(bool in_bDelay = true);
	void toHistEq(bool in_bDelay = true);
	void toStretchChan(bool in_bDelay = true);
	void toSobel(bool in_bDelay = true);
	void toMedian(bool in_bDelay = true);
	void toGrayWorld(bool in_bDelay = true);
	void toGauss(bool in_bDelay = true);
	void toRotate(bool in_bDelay = true);
	void toLinearFil(bool in_bDelay = true);
	void toResize(bool in_bDelay = true);
	void toWaves(bool in_bDelay = true);
	void toMyFiltr(bool in_bDelay = true);
	// ... other filters

	QRgb belinearColorInterpolation(
        QRect rt,
        QRgb ltValue,
        QRgb lbValue,
        QRgb rbValue,
        QRgb rtValue,
        qreal x, qreal y);

	qreal belinearInterpolation(
        QRect r,
        qreal ltValue,
        qreal lbValue,
        qreal rbValue,
        qreal rtValue,
        qreal x, qreal y);

	qreal linearInterpolation(
        qreal left,
        qreal right,
        qreal lValue,
        qreal rValue,
        qreal x);

};

#endif //_CENGINE_H
