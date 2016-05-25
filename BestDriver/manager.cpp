#include "manager.h"

Manager::Manager(QObject *parent) : QObject(parent)
{
    m_date = QDate::currentDate();
}

void Manager::setUIProperty(QString name, QVariant value)
{
    m_engine.rootContext()->setContextProperty("__ui__" + name, value);
}

void Manager::exec()
{
    // Set Current Date
    setUIProperty("year", m_date.year());
    setUIProperty("month", m_date.month());
    setUIProperty("day", m_date.day());

    m_engine.rootContext()->setContextProperty("calendarModel", &m_cal);

    // Load UI
    m_engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
}
