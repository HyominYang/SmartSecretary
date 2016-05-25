#ifndef CALENDARMODEL_H
#define CALENDARMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QDebug>
#include <QList>
#include <qvariant.h>
#include <QDate>

class CalendarModel  : public QObject
{
    Q_OBJECT
public:
    explicit CalendarModel(QObject *parent = 0);
    Q_INVOKABLE bool getEventForDate(int index, const QDate &date);
    Q_INVOKABLE bool getHoliday(const QDate &date);
signals:

public slots:
private:
    bool group[5][12][32];
};

#endif // CALENDARMODEL_H
