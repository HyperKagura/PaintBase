#ifndef FILTER_H
#define FILTER_H

#include <QVector>
#include <QString>
#include <QStringList>

class Filter {
    QVector <QVector <qreal> > kernel;

  public:
    Filter();
	Filter(QString str);
    Filter(int width, int height);
    Filter(const Filter &filter);

    static Filter single(int width, int height);
    static Filter single(const Filter &filter);

    const qreal & at(int x, int y) const;
    qreal & at(int x, int y);

    int width() const;
    int height() const;

    Filter normalized() const;
    Filter transposed() const;

    Filter & operator =(const Filter &filter);
};

Filter operator -(const Filter &filter);
Filter operator +(const Filter &f, const Filter &g);
Filter operator -(const Filter &f, const Filter &g);
Filter operator *(qreal a, const Filter &f);
Filter operator *(const Filter &f, qreal a);

#endif  // FILTER_H
