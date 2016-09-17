#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "listmodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<RecordListModel> ("CrazzyMad.RecordListModel", 1, 0, "RecordListModel");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

