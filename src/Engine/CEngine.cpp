#include "CEngine.h"

CEngine::CEngine()
{
	m_fnCallback = NULL;
	m_pCallbackExtra = NULL;
	sigma = 1/3;
}

bool CEngine::load(const string& in_sPath)
{
	QString path(in_sPath.data());
	return m_Image.load(path);
}

bool CEngine::save(const string& in_sPath)
{
	QString path(in_sPath.data()); 
	return m_Image.save(path);
}

const QImage& CEngine::getImage() const
{
	return m_Image;
}

void CEngine::toGrayWorld(bool in_bDelay)
{
	QImage imgNew(m_Image.width(), m_Image.height(), QImage::Format_RGB32);
	uint uiPercent, uiQuantum = m_Image.width() * m_Image.height() / 50;
	double rGray = 0, gGray = 0, bGray = 0, avg;

	for (uint y = 0; y < m_Image.height(); ++y)
	{
		uint rTempGray = 0, gTempGray = 0, bTempGray = 0;
		for (uint x = 0; x < m_Image.width(); ++x)
		{
			QRgb rgb = m_Image.pixel(x,y);
			rTempGray+=qRed(rgb);
			gTempGray+=qGreen(rgb);
			bTempGray+=qBlue(rgb);

			uiPercent = y * m_Image.width() + x;
			if (uiPercent % uiQuantum == 0 && m_fnCallback)
				m_fnCallback(uiPercent / uiQuantum, m_pCallbackExtra);
		}
		rGray+=rTempGray/m_Image.width();
		gGray+=gTempGray/m_Image.width();
		bGray+=bTempGray/m_Image.width();
	}
	rGray=rGray/m_Image.height();
	gGray=gGray/m_Image.height();
	bGray=bGray/m_Image.height();
	avg=(rGray+gGray+bGray)/3;
	rGray=avg/rGray;
	gGray=avg/gGray;
	bGray=avg/bGray;
	for (uint y = 0; y < m_Image.height(); ++y)
	{
		for (uint x = 0; x < m_Image.width(); ++x)
		{
			QRgb rgb = m_Image.pixel(x,y);
			double dNewR = qRed(rgb)*rGray;
			double dNewG = qGreen(rgb)*gGray;
			double dNewB = qBlue(rgb)*bGray;
			int newR = static_cast<int>(dNewR+0.5);
			int newG = static_cast<int>(dNewG+0.5);
			int newB = static_cast<int>(dNewB+0.5);
			if (newR > 255) newR=255;
			if (newG > 255) newG=255;
			if (newB > 255) newB=255;
			rgb = qRgb(newR,newG,newB);
			imgNew.setPixel(x, y, rgb);

			uiPercent = y * m_Image.width() + x;
			if (uiPercent % uiQuantum == 0 && m_fnCallback)
				m_fnCallback(uiPercent / uiQuantum + 50, m_pCallbackExtra);
		}
	}
	m_Image=imgNew;

	if (m_fnCallback) m_fnCallback(100, m_pCallbackExtra);

}

void CEngine::toSobel(bool in_bDelay)
{
	QImage imgNew(m_Image.width(), m_Image.height(), QImage::Format_RGB32);
	uint uiPercent, uiQuantum = m_Image.width() * m_Image.height() / 100;
	
	int sob1[3]={1, 2, 1};
	int sob2[3]={1, 0,-1};
	for (uint y = 0; y < m_Image.height(); ++y)
	{
		for (uint x = 0; x < m_Image.width(); ++x)
		{
			int sobRes[3][3]={{0,0,0},	//на красный канал
							  {0,0,0},	//на зеленый
							  {0,0,0}};	//на синий
			for (int y1 = -1; y1 < 2; y1++)
			{
				for (int x1 = -1; x1 < 2; x1++)
				{
					int newX = x + x1;
					int newY = y + y1;
					if (newX < 0) newX=-newX;
					else if (newX >= imgNew.width()) newX=m_Image.width()*2-newX-1;
					if (newY < 0) newY=-newY;
					else if (newY >= imgNew.height()) newY=m_Image.height()*2-newY-1;
					QRgb rgb = m_Image.pixel(newX,newY);
					sobRes[y1+1][0]+=sob1[x1+1]*qRed(rgb);
					sobRes[y1+1][1]+=sob1[x1+1]*qGreen(rgb);
					sobRes[y1+1][2]+=sob1[x1+1]*qBlue(rgb);
				}
			}
			int newR = 0, newG = 0, newB = 0;
			for (int y1 = 0; y1 < 3; y1++)
			{
				newR+=sobRes[y1][0]*sob2[y1];
				newG+=sobRes[y1][1]*sob2[y1];
				newB+=sobRes[y1][2]*sob2[y1];
			}
			if (newR < 0) newR = 0;
			else if (newR > 255) newR = 255;
			if (newG < 0) newG = 0;
			else if (newG > 255) newG = 255;
			if (newB < 0) newB = 0;
			else if (newB > 255) newB = 255;
			int newRgb = qRgb(newR, newG, newB);
			imgNew.setPixel(x, y, newRgb);

			uiPercent = y * m_Image.width() + x;
			if (uiPercent % uiQuantum == 0 && m_fnCallback)
				m_fnCallback(uiPercent / uiQuantum, m_pCallbackExtra);
		}
		//if (in_bDelay) Sleep(5); //! only for emulation purposes
	}

	m_Image=imgNew;
	if (m_fnCallback) m_fnCallback(100, m_pCallbackExtra);
}

void CEngine::toRotate(bool in_bDelay)
{
	
	QImage imgNew(m_Image.width(), m_Image.height(), QImage::Format_RGB32);
	uint uiPercent, uiQuantum = m_Image.width() * m_Image.height() / 50;

	int centerX = m_Image.width()/2;
	int centerY = m_Image.height()/2;

	qreal ang = angle * 3.14 / 180;

	for (uint y = 0; y < m_Image.height(); ++y)
	{
		for (uint x = 0; x < m_Image.width(); ++x)
		{
			imgNew.setPixel(x, y, qRgb(0, 0, 0));

			uiPercent = y * m_Image.height() + x;
			if (uiPercent % uiQuantum == 0 && m_fnCallback)
			m_fnCallback(uiPercent / uiQuantum, m_pCallbackExtra);
		}
	}
	
	for (int y = 0; y < m_Image.height(); ++y)
	{
		for (int x = 0; x < m_Image.width(); ++x)
		{
			qreal relativeX = x - centerX;
			qreal relativeY = y - centerY;
            qreal sourceX = centerX + relativeX * qCos(ang) + relativeY * qSin(ang);
            qreal sourceY = centerY - relativeX * qSin(ang) + relativeY * qCos(ang);

            if (sourceX >= 0 && sourceX < m_Image.width() && sourceY >= 0 && sourceY < m_Image.height()) {
                int left, top;
                int sx = (int)sourceX;
                int sy = (int)sourceY;

                if (sx >=  m_Image.width() ) left = sx - 1;
                else left = sx;
                
                if (sy >= m_Image.height() ) top = sy - 1;
                else top = sy;

                imgNew.setPixel(x, y, belinearColorInterpolation(
                    QRect(left, top, 1, 1),
                    m_Image.pixel(left, top),
                    m_Image.pixel(left, top + 1),
                    m_Image.pixel(left + 1, top + 1),
                    m_Image.pixel(left + 1, top),
                    sourceX, sourceY
                ));
            }

			uiPercent = y * m_Image.height() + x;
			if (uiPercent % uiQuantum == 0 && m_fnCallback)
			m_fnCallback(uiPercent / uiQuantum + 50, m_pCallbackExtra);
		}
		//if (in_bDelay) Sleep(5); //! only for emulation purposes
	}

	m_Image = imgNew;
	if (m_fnCallback) m_fnCallback(100, m_pCallbackExtra);
}

void CEngine::toResize(bool in_bDelay)
{
	int newWidth = static_cast<int>(m_Image.width()*sigma);
	int newHeight = static_cast<int>(m_Image.height()*sigma);
	
	QImage imgNew(newWidth, newHeight, QImage::Format_RGB32);
	uint uiPercent, uiQuantum = newHeight * newWidth / 50;

	for (uint y = 0; y < newHeight; ++y)
	{
		for (uint x = 0; x < newWidth; ++x)
		{
			imgNew.setPixel(x, y, qRgb(0, 0, 0));

			uiPercent = y * newHeight + x;
			if (uiPercent % uiQuantum == 0 && m_fnCallback)
			m_fnCallback(uiPercent / uiQuantum, m_pCallbackExtra);
		}
	}

	for (int y = 0; y < newHeight; y++) {
        for (int x = 0; x < newWidth; x++) {
            qreal sourceX = x / sigma;
            qreal sourceY = y / sigma;

            if (sourceX >= 0 && sourceX < m_Image.width() && sourceY >= 0 && sourceY < m_Image.height() ) 
			{
                int left, top;
                int sx = (int)sourceX;
                int sy = (int)sourceY;

                if (sx >= m_Image.width()) {
                    left = sx - 1;
                }
                else {
                    left = sx;
                }

                if (sy >= m_Image.height()) {
                    top = sy - 1;
                }
                else {
                    top = sy;
                }

                imgNew.setPixel(x, y, belinearColorInterpolation(
                    QRect(left, top, 1, 1),
                    m_Image.pixel(left, top),
                    m_Image.pixel(left, top + 1),
                    m_Image.pixel(left + 1, top + 1),
                    m_Image.pixel(left + 1, top),
                    sourceX, sourceY
                ));
            }
			uiPercent = y * newHeight + x;
			if (uiPercent % uiQuantum == 0 && m_fnCallback)
			m_fnCallback(uiPercent / uiQuantum + 50, m_pCallbackExtra);
        }
    }

	m_Image = imgNew;
	if (m_fnCallback) m_fnCallback(100, m_pCallbackExtra);
}

void CEngine::toMyFiltr(bool in_bDelay)
{
	QImage imgNew(m_Image.width(), m_Image.height(), QImage::Format_RGB32);
	uint uiPercent, uiQuantum = m_Image.height() * m_Image.width() / 100;

/*	QImage fil = setMyFiltr(m_Image.width(), m_Image.height(), uiQuantum);

	for (int y = 0; y < m_Image.height(); y++)
	{
		for (int x = 0; x < m_Image.width(); x++)
		{
			qreal perc = 1;
			QRgb rgb = fil.pixel(x, y);
			QRgb rgbMain = m_Image.pixel(x,y);
			qreal newR = qRed(rgb)*perc + qRed(rgbMain)*(1-perc);
			qreal newG = qGreen(rgb)*perc + qGreen(rgbMain)*(1-perc);
			qreal newB = qBlue(rgb)*perc + qBlue(rgbMain)*(1-perc);
			int r = (int)newR;
			int g = (int)newG;
			int b = (int)newB;
			imgNew.setPixel(x, y, qRgb(r,g,b));

			uiPercent = y * m_Image.width() + x;
			if (uiPercent % uiQuantum == 0 && m_fnCallback)
			m_fnCallback(uiPercent / uiQuantum + 50, m_pCallbackExtra);
		}
		//QImage myImg("ColorShift.png", "png");
	} */

	int sob1[3]={1, 2, 1};
	int sob2[3]={1, 0,-1};
	for (int y = 0; y < m_Image.height(); ++y)
	{
		for (int x = 0; x < m_Image.width(); ++x)
		{
			int sobRes[3][3]={{0,0,0},	//на красный канал
							  {0,0,0},	//на зеленый
							  {0,0,0}};	//на синий
			for (int y1 = -1; y1 < 2; y1++)
			{
				for (int x1 = -1; x1 < 2; x1++)
				{
					int newX = x + x1;
					int newY = y + y1;
					if (newX < 0) newX=-newX;
					else if (newX >= imgNew.width()) newX=m_Image.width()*2-newX-1;
					if (newY < 0) newY=-newY;
					else if (newY >= imgNew.height()) newY=m_Image.height()*2-newY-1;
					QRgb rgb = m_Image.pixel(newX,newY);
					sobRes[y1+1][0]+=sob1[x1+1]*qRed(rgb);
					sobRes[y1+1][1]+=sob1[x1+1]*qGreen(rgb);
					sobRes[y1+1][2]+=sob1[x1+1]*qBlue(rgb);
				}
			}
			int newR = 0, newG = 0, newB = 0;
			for (int y1 = 0; y1 < 3; y1++)
			{
				newR+=sobRes[y1][0]*sob2[y1];
				newG+=sobRes[y1][1]*sob2[y1];
				newB+=sobRes[y1][2]*sob2[y1];
			}
			if (newR < 0) newR = 0;
			else if (newR > 255) newR = 255;
			if (newG < 0) newG = 0;
			else if (newG > 255) newG = 255;
			if (newB < 0) newB = 0;
			else if (newB > 255) newB = 255;
			
			QRgb oldRgb = m_Image.pixel(x,y);
			if (newR > qRed(oldRgb)) newR = qRed(oldRgb);
			if (newG > qGreen(oldRgb)) newG = qGreen(oldRgb);
			if (newB > qBlue(oldRgb)) newB = qBlue(oldRgb);

			int newRgb = qRgb(newR, newG, newB);
			imgNew.setPixel(x,y,newRgb);

			uiPercent = y * m_Image.width() + x;
			if (uiPercent % uiQuantum == 0 && m_fnCallback)
				m_fnCallback(uiPercent / uiQuantum, m_pCallbackExtra);
		}
		//if (in_bDelay) Sleep(5); //! only for emulation purposes
	}

	m_Image = imgNew;
	if (m_fnCallback) m_fnCallback(100, m_pCallbackExtra);
}

void CEngine::toGrayscale(bool in_bDelay)
{
	
	QVector<QRgb> vGrayscale;
	QImage imgNew(m_Image.width(), m_Image.height(), QImage::Format_Indexed8);
	uint uiPercent, uiQuantum = m_Image.width() * m_Image.height() / 100;

	vGrayscale.reserve(256);  //все значени€ оттенков серого
	for (uint i = 0; i < 256; ++i) {
		vGrayscale.append(qRgb(i, i, i));
	}
	imgNew.setColorTable(vGrayscale);

	for (uint y = 0; y < m_Image.height(); ++y)
	{
		for (uint x = 0; x < m_Image.width(); ++x)
		{
			QRgb rgb = m_Image.pixel(x, y);
			uint uiGray = 0.2125*qRed(rgb) + 0.7154*qGreen(rgb) + 0.0721*qBlue(rgb);
			imgNew.setPixel(x, y, uiGray);
			uiPercent = y * m_Image.width() + x;
			if (uiPercent % uiQuantum == 0 && m_fnCallback)
				m_fnCallback(uiPercent / uiQuantum, m_pCallbackExtra);
		}
		//if (in_bDelay) Sleep(5); //! only for emulation purposes
	}

	m_Image = imgNew;
	if (m_fnCallback) m_fnCallback(100, m_pCallbackExtra);
}

void CEngine::toMedian(bool in_bDelay)
{
	QImage imgNew(m_Image.width(), m_Image.height(), QImage::Format_RGB32);
	uint uiPercent, uiQuantum = m_Image.width() * m_Image.height() / 100;

	for (uint y = 0; y < m_Image.height(); ++y)
	{
		for (uint x = 0; x < m_Image.width(); ++x)
		{
			int medArrayR[9];
			int medArrayG[9];
			int medArrayB[9];
			for (int y1 = -1; y1 < 2; y1++)
			{
				for (int x1 = -1; x1 < 2; x1++)
				{
					int newX = x + x1;
					int newY = y + y1;
					if (newX < 0) newX=-newX;
					else if (newX > imgNew.width()) newX=m_Image.width()*2-newX-1;
					if (newY < 0) newY=-newY;
					else if (newY > imgNew.height()) newY=m_Image.height()*2-newY-1;
					QRgb rgb = m_Image.pixel(newX,newY);
					medArrayR[(y1+1)*3+x1+1]=qRed(rgb);
					medArrayG[(y1+1)*3+x1+1]=qGreen(rgb);
					medArrayB[(y1+1)*3+x1+1]=qBlue(rgb);
				}
			}
			sort(medArrayR,medArrayR+9);
			sort(medArrayG,medArrayG+9);
			sort(medArrayB,medArrayB+9);
			int newRgb = qRgb(medArrayR[4], medArrayG[4], medArrayB[4]);
			imgNew.setPixel(x, y, newRgb);

			uiPercent = y * m_Image.width() + x;
			if (uiPercent % uiQuantum == 0 && m_fnCallback)
				m_fnCallback(uiPercent / uiQuantum, m_pCallbackExtra);
		}
		//if (in_bDelay) Sleep(5); //! only for emulation purposes
	}

	m_Image=imgNew;
	if (m_fnCallback) m_fnCallback(100, m_pCallbackExtra);
}

void CEngine::toStretchChan(bool in_bDelay) 
{
	QImage imgNew(m_Image.width(), m_Image.height(), QImage::Format_RGB32);
	uint uiPercent, uiQuantum = m_Image.width() * m_Image.height() / 100;
	int redHist[256], greenHist[256], blueHist[256];

	for (int i=0; i<256; i++) redHist[i]=0;
	for (int i=0; i<256; i++) blueHist[i]=0;
	for (int i=0; i<256; i++) greenHist[i]=0;
	
	for (uint y = 0; y < m_Image.height(); ++y)
	{
		for (uint x = 0; x < m_Image.width(); ++x)
		{
			QRgb rgb = m_Image.pixel(x, y);
			int r = qRed(rgb), g = qGreen(rgb), b = qBlue(rgb);

			redHist[r]++;
			blueHist[b]++;
			greenHist[g]++;
		}
	}

	int badPixNum = m_Image.height()*m_Image.width()/20; //5% пикселей дл€ отсечени€ на гистограмме
	int minR=0, minG = 0, minB=0, maxR=255, maxG=255, maxB=255, badPixNum2 = badPixNum;
		
	while (badPixNum)	//границы красного
	{
		if (redHist[minR]==0) minR++;
		else if (redHist[minR]<badPixNum)
			{
				badPixNum-=redHist[minR];
				minR++;
			}
			else badPixNum=0;
	}
	badPixNum=badPixNum2;

	while (badPixNum2)
	{
		if (redHist[maxR]==0) maxR--;
		else if (redHist[maxR]<badPixNum2)
			{
				badPixNum2-=redHist[maxR];
				maxR--;
			}
			else badPixNum2=0;
	}
	badPixNum2=badPixNum;

	while (badPixNum)	//границы зеленого
	{
		if (greenHist[minG]==0) minG++;
		else if (greenHist[minG]<badPixNum)
			{
				badPixNum-=greenHist[minG];
				minG++;
			}
			else badPixNum=0;
	}
	badPixNum=badPixNum2;

	while (badPixNum2)
	{
		if (greenHist[maxG]==0) maxG--;
		else if (greenHist[maxG]<badPixNum2)
			{
				badPixNum2-=greenHist[maxG];
				maxG--;
			}
			else badPixNum2=0;
	}
	badPixNum2=badPixNum;

	while (badPixNum)	//границы синего
	{
		if (blueHist[minB]==0) minB++;
		else if (blueHist[minB]<badPixNum)
			{
				badPixNum-=blueHist[minB];
				minB++;
			}
			else badPixNum=0;
	}

	while (badPixNum2)
	{
		if (blueHist[maxB]==0) maxB--;
		else if (blueHist[maxB]<badPixNum2)
			{
				badPixNum2-=blueHist[maxB];
				maxB--;
			}
			else badPixNum2=0;
	}
	badPixNum2=badPixNum;

	for (uint y = 0; y < m_Image.height(); ++y)
	{
		for (uint x = 0; x < m_Image.width(); ++x)
		{
			QRgb rgb = m_Image.pixel(x, y);
			
			if (qRed(rgb)<minR) rgb = qRgb(0,qGreen(rgb),qBlue(rgb));	//red
			else if (qRed(rgb)>maxR) rgb = qRgb(255,qGreen(rgb),qBlue(rgb));
			else 
			{
				double newColor = (qRed(rgb)-minR)*255/(maxR-minR);
				int newRed = static_cast<int>(newColor+0.5);
				rgb = qRgb(newRed,qGreen(rgb),qBlue(rgb));
			}
			if (qGreen(rgb)<minG) rgb = qRgb(qRed(rgb),0,qBlue(rgb));	//green
			else if (qGreen(rgb)>maxG) rgb = qRgb(qRed(rgb),255,qBlue(rgb));
			else 
			{
				double newColor = (qGreen(rgb)-minG)*255/(maxG-minG);
				int newGreen = static_cast<int>(newColor+0.5);
				rgb = qRgb(qRed(rgb),newGreen,qBlue(rgb));
			}
			if (qBlue(rgb)<minB) rgb = qRgb(qRed(rgb),qGreen(rgb),0);	//blue
			else if (qBlue(rgb)>maxB) rgb = qRgb(qRed(rgb),qGreen(rgb),255);
			else 
			{
				double newColor = (qBlue(rgb)-minB)*255/(maxB-minB);
				int newBlue = static_cast<int>(newColor+0.5);
				rgb = qRgb(qRed(rgb),qGreen(rgb),newBlue);
			}
			
			imgNew.setPixel(x, y, rgb);
			
			uiPercent = y * m_Image.width() + x;	//сколько писелей уже обработано
			if (uiPercent % uiQuantum == 0 && m_fnCallback)
				m_fnCallback(uiPercent / uiQuantum, m_pCallbackExtra);
		}
		//if (in_bDelay) Sleep(5); //! only for emulation purposes
	}

	m_Image = imgNew;
	if (m_fnCallback) m_fnCallback(100, m_pCallbackExtra);
}

void CEngine::toHistEq(bool in_bDelay)
{
	int hist[256];
	QImage imgNew(m_Image.width(), m_Image.height(), QImage::Format_RGB32);
	uint uiPercent, uiQuantum = m_Image.width() * m_Image.height() / 100;

	for (int i=0; i<256; i++) hist[i]=0;

	for (uint y = 0; y < m_Image.height(); ++y)		//построение гистограммы €рости hist
	{
		for (uint x = 0; x < m_Image.width(); ++x)
		{
			QRgb rgb = m_Image.pixel(x, y);
			int grIndex = 0.2125*qRed(rgb) + 0.7154*qGreen(rgb) + 0.0721*qBlue(rgb);
			hist[grIndex]++;
		}
	}

	int badPixNum = m_Image.height()*m_Image.width()/20; //5% пикселей дл€ отсечени€ на гистограмме
	int min=0, max=255, badPixNum2 = badPixNum;
		
	while (badPixNum)
	{
		if (hist[min]==0) min++;
		else if (hist[min]<badPixNum)
			{
				badPixNum-=hist[min];
				min++;
			}
			else badPixNum=0;
	}

	while (badPixNum2)
	{
		if (hist[max]==0) max--;
		else if (hist[max]<badPixNum2)
			{
				badPixNum2-=hist[max];
				max--;
			}
			else badPixNum2=0;
	}

	for (uint y = 0; y < m_Image.height(); ++y)
	{
		for (uint x = 0; x < m_Image.width(); ++x)
		{
			QRgb rgb = m_Image.pixel(x, y);
			
			if (qRed(rgb)<=min) rgb = qRgb(0,qGreen(rgb),qBlue(rgb));	//red
			else if (qRed(rgb)>=max) rgb = qRgb(255,qGreen(rgb),qBlue(rgb));
			else 
			{
				double newColor = (qRed(rgb)-min)*255/(max-min);
				int newRed = static_cast<int>(newColor+0.5);
				rgb = qRgb(newRed,qGreen(rgb),qBlue(rgb));
			}
			
			if (qGreen(rgb)<=min) rgb = qRgb(qRed(rgb),0,qBlue(rgb));	//green
			else if (qGreen(rgb)>=max) rgb = qRgb(qRed(rgb),255,qBlue(rgb));
			else 
			{
				double newColor = (qGreen(rgb)-min)*255/(max-min);
				int newGreen = static_cast<int>(newColor+0.5);
				rgb = qRgb(qRed(rgb),newGreen,qBlue(rgb));
			}
			
			if (qBlue(rgb)<=min) rgb = qRgb(qRed(rgb),qGreen(rgb),0);	//blue
			else if (qBlue(rgb)>=max) rgb = qRgb(qRed(rgb),qGreen(rgb),255);
			else 
			{
				double newColor = (qBlue(rgb)-min)*255/(max-min);
				int newBlue = static_cast<int>(newColor+0.5);
				rgb = qRgb(qRed(rgb),qGreen(rgb),newBlue);
			}
			imgNew.setPixel(x, y, rgb);
			
			uiPercent = y * m_Image.width() + x;
			if (uiPercent % uiQuantum == 0 && m_fnCallback)
				m_fnCallback(uiPercent / uiQuantum, m_pCallbackExtra);
		}
		//if (in_bDelay) Sleep(5); //! only for emulation purposes
	}

	m_Image = imgNew;
	if (m_fnCallback) m_fnCallback(100, m_pCallbackExtra);
}

void CEngine::toGauss(bool in_bDelay)
{
	QImage imgNew(m_Image.width(), m_Image.height(), QImage::Format_RGB32);
	uint uiPercent, uiQuantum = m_Image.width() * m_Image.height() / 100;
	
	int filSize = static_cast<int>(sigma*6 + 0.5);		//получим размер фильтра
	if (filSize % 2 == 0 ) filSize++;

	double *halfGauss = new double[filSize*sizeof(double)];
	int centr = filSize/2;
	for (int i = 0; i < filSize; i++)
	{
		double x = i - centr;
		double temp = exp(-(x*x)/(2*sigma*sigma))/(sqrt(6.28)*sigma);
		halfGauss[i] = temp;
	}				//получили сепарабельный фильтр √аусса

	for (uint y = 0; y < m_Image.height(); ++y)
	{
		for (uint x = 0; x < m_Image.width(); ++x)
		{
			double *gaussResR = new double[filSize*sizeof(double)];
			double *gaussResG = new double[filSize*sizeof(double)];
			double *gaussResB = new double[filSize*sizeof(double)];
			for (int i = 0; i < filSize; i++) 
			{
				gaussResR[i]=0;
				gaussResG[i]=0;
				gaussResB[i]=0;
			}
			for (int y1 = -centr; y1 < centr + 1; y1++)
			{
				for (int x1 = -centr; x1 < centr + 1; x1++)
				{
					int newX = x + x1;
					int newY = y + y1;
					if (newX < 0) newX=-newX-1;
					else if (newX >= imgNew.width()) newX=m_Image.width()*2-newX-1;
					if (newY < 0) newY=-newY-1;
					else if (newY >= imgNew.height()) newY=m_Image.height()*2-newY-1;
					QRgb rgb = m_Image.pixel(newX,newY);
					gaussResR[y1+centr]+=halfGauss[x1+centr]*qRed(rgb);
					gaussResG[y1+centr]+=halfGauss[x1+centr]*qGreen(rgb);
					gaussResB[y1+centr]+=halfGauss[x1+centr]*qBlue(rgb);
				}
			}

			double newDR = 0, newDG = 0, newDB = 0;
			for (int y1 = 0; y1 < filSize; y1++)
			{
				newDR+=gaussResR[y1]*halfGauss[y1];
				newDG+=gaussResG[y1]*halfGauss[y1];
				newDB+=gaussResB[y1]*halfGauss[y1];
			}
			int newR = static_cast<int>(newDR + 0.5);
			int newG = static_cast<int>(newDG + 0.5);
			int newB = static_cast<int>(newDB + 0.5);
			if (newR < 0) newR = 0;
			else if (newR > 255) newR = 255;
			if (newG < 0) newG = 0;
			else if (newG > 255) newG = 255;
			if (newB < 0) newB = 0;
			else if (newB > 255) newB = 255;
			int newRgb = qRgb(newR, newG, newB);
			imgNew.setPixel(x, y, newRgb);

			delete[] gaussResR;
			delete[] gaussResG;
			delete[] gaussResB;

			uiPercent = y * m_Image.width() + x;
			if (uiPercent % uiQuantum == 0 && m_fnCallback)
				m_fnCallback(uiPercent / uiQuantum, m_pCallbackExtra);
		}
		//if (in_bDelay) Sleep(5); //! only for emulation purposes
	}
	delete[] halfGauss;

	m_Image = imgNew;
	if (m_fnCallback) m_fnCallback(100, m_pCallbackExtra);
}

void CEngine::toWaves(bool in_bDelay)
{
	QImage imgNew(m_Image.width(), m_Image.height(), QImage::Format_RGB32);
	uint uiPercent, uiQuantum = m_Image.width() * m_Image.height() / 50;

	for (int y = 0; y < m_Image.height(); y++) {
        for (int x = 0; x < m_Image.width(); x++) {
            imgNew.setPixel(x, y, qRgb(0,0,0));

			uiPercent = y * m_Image.width() + x;
			if (uiPercent % uiQuantum == 0 && m_fnCallback)
				m_fnCallback(uiPercent / uiQuantum, m_pCallbackExtra);
        }
    }

    for (int y = 0; y < m_Image.height(); y++) {
        for (int x = 0; x < m_Image.width(); x++) {
            qreal phase = (amplitudeX * y + amplitudeY * x) / (amplitudeX + amplitudeY);
            qreal sourceX = x + amplitudeX * qSin(2 * M_PI * phase / sigma);	//sigma - длина волны
            qreal sourceY = y + amplitudeY * qSin(2 * M_PI * phase / sigma);

            if (sourceX >= 0 && sourceX < m_Image.width() && sourceY >= 0 && sourceY < m_Image.height()) {
                int left, top;
                int sx = (int)sourceX;
                int sy = (int)sourceY;

                if (sx >= m_Image.width()) {
                    left = sx - 1;
                }
                else {
                    left = sx;
                }

                if (sy >= m_Image.height()) {
                    top = sy - 1;
                }
                else {
                    top = sy;
                }

                imgNew.setPixel(x, y, belinearColorInterpolation(
                    QRect(left, top, 1, 1),
                    m_Image.pixel(left, top),
                    m_Image.pixel(left, top + 1),
                    m_Image.pixel(left + 1, top + 1),
                    m_Image.pixel(left + 1, top),
                    sourceX, sourceY
                ));
            }

			uiPercent = y * m_Image.width() + x;
			if (uiPercent % uiQuantum == 0 && m_fnCallback)
				m_fnCallback(uiPercent / uiQuantum + 50, m_pCallbackExtra);
        }
    }


	m_Image = imgNew;
	if (m_fnCallback) m_fnCallback(100, m_pCallbackExtra);
}

void CEngine::toLinearFil(bool in_bDelay)
{
	QImage imgNew(m_Image.width(), m_Image.height(), QImage::Format_RGB32);
	uint uiPercent, uiQuantum = m_Image.width() * m_Image.height() / 100;

	int rad = mFilter.width()/2;
	for (uint y = 0; y < m_Image.height(); ++y)
	{
		for (uint x = 0; x < m_Image.width(); ++x)
		{
			
			qreal resultR = 0.0, resultG = 0.0, resultB = 0.0;
			for (int x1 = -rad; x1 <= rad; x1++) 
			{
				for (int y1 = -rad; y1 <= rad; y1++) 
				{
					int newX = x + x1;
					int newY = y + y1;
					if (newX < 0) newX=-newX-1;
					else if (newX >= imgNew.width()) newX=m_Image.width()*2-newX-1;
					if (newY < 0) newY=-newY-1;
					else if (newY >= imgNew.height()) newY=m_Image.height()*2-newY-1;
					QRgb color = m_Image.pixel(newX, newY);
					resultR += mFilter.at(x1+rad, y1+rad) * qRed(color);
					resultG += mFilter.at(x1+rad, y1+rad) * qGreen(color);
					resultB += mFilter.at(x1+rad, y1+rad) * qBlue(color);
			    }
		    }

			int r = qBound(0, (int)resultR, 255);
			int g = qBound(0, (int)resultG, 255);
			int b = qBound(0, (int)resultB, 255);
			imgNew.setPixel(x, y, qRgb(r,g,b));

			uiPercent = y * m_Image.width() + x;
			if (uiPercent % uiQuantum == 0 && m_fnCallback)
				m_fnCallback(uiPercent / uiQuantum, m_pCallbackExtra);
		}
		//if (in_bDelay) Sleep(5); //! only for emulation purposes
	}

	m_Image = imgNew;
	if (m_fnCallback) m_fnCallback(100, m_pCallbackExtra);
}

void CEngine::setCallbacks(PCALLBACK in_fnCallback, void *in_pCallbackExtra)
{
	m_fnCallback = in_fnCallback;
	m_pCallbackExtra = in_pCallbackExtra;
}

void CEngine::setSigma(double val)
{
	this->sigma=val;
}

void CEngine::setAngle(int val)
{
	angle=val;
}

void CEngine::setFilter(Filter filt)
{
	this->mFilter = filt;
}

QImage CEngine::setMyFiltr(int width, int height, uint uiQuantum)
{
	QImage myImg = QImage("ColorShift.png");
	uint uiPercent;

	QImage res(width, height, QImage::Format_RGB32);

	qreal coeffX = myImg.width()/ width;
	qreal coeffY = myImg.height()/ height;

	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
		{
			qreal sourceX = x*coeffX;
			qreal sourceY = y*coeffY;
			int sx = (int) sourceX;
			int sy = (int) sourceY;
			QRgb rgb = myImg.pixel(sx, sy);
			res.setPixel(x, y, rgb);

			uiPercent = y * m_Image.width() + x;
			if (uiPercent % uiQuantum == 0 && m_fnCallback)
			m_fnCallback(uiPercent / uiQuantum, m_pCallbackExtra);
		}

	return res;
}

void CEngine::setAmplitude(double valX, double valY)
{
	this->amplitudeX=valX;
	this->amplitudeY=valY;
}

qreal CEngine::linearInterpolation(
        qreal left,
        qreal right,
        qreal lValue,
        qreal rValue,
        qreal x)
{
    return ((right - x) * lValue + (x - left) * rValue) / (right - left);
}
 
qreal CEngine::belinearInterpolation(
        QRect r,
        qreal ltValue,
        qreal lbValue,
        qreal rbValue,
        qreal rtValue,
        qreal x, qreal y)
{
 
    qreal r1 = linearInterpolation(r.left(), r.left() + r.width(), ltValue, rtValue, x);	//коэффиценты интерпол€ции
    qreal r2 = linearInterpolation(r.left(), r.left() + r.width(), lbValue, rbValue, x);
    qreal result = linearInterpolation(r.top(), r.top() + r.height(), r1, r2, y);
    return result;
}
 
QRgb CEngine::belinearColorInterpolation(
        QRect rt,
        QRgb ltValue,
        QRgb lbValue,
        QRgb rbValue,
        QRgb rtValue,
        qreal x, qreal y)
{
    int r = (int)belinearInterpolation(rt, qRed(ltValue),
                                       qRed(lbValue),
                                       qRed(rbValue),
                                       qRed(rtValue), x, y);
    int g = (int)belinearInterpolation(rt, qGreen(ltValue),
                                       qGreen(lbValue),
                                       qGreen(rbValue),
                                       qGreen(rtValue), x, y);
    int b = (int)belinearInterpolation(rt, qBlue(ltValue),
                                       qBlue(lbValue),
                                       qBlue(rbValue),
                                       qBlue(rtValue), x, y);
    return qRgb(r, g, b);
}

