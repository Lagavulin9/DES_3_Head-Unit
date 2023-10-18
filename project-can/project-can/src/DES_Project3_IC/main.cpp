#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "ICdatamanager.h"
#include "ICdataStubImpl.h" 

int main(int argc, char *argv[])
{
    
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::shared_ptr<ICdataStubImpl> InstrumentCluster = std::make_shared<ICdataStubImpl>();

    ICdatamanager dataManager;

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    
    engine.rootContext()->setContextProperty("dataManager", &dataManager);
    
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
