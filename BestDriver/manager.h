#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>
#include <QProcess>
#include <QtSql>
#include <QFontDatabase>
#include <QGuiApplication>

#include "calendarmodel.h"

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = 0);
    void exec();
signals:

public slots:

private:
    void setUIProperty(QString name, QVariant value);
    QQmlApplicationEngine m_engine;
    QDate m_date;
    CalendarModel m_cal;
};

#endif // MANAGER_H
