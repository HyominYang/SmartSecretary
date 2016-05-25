#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "manager.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Manager manager;

    manager.exec();

    return app.exec();
}

