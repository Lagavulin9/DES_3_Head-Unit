#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "ICdatamanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
     
    qmlRegisterType<ICdatamanager>("ICdatamanager", 1, 0, "ICdatamanager");
    qRegisterMetaType<uint32_t>("uint32_t");
    qRegisterMetaType<uint8_t>("uint8_t");
    
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);


    return app.exec();
}
