#include <QGuiApplication>
#include "pgsql.h"
//#include <QQmlApplicationEngine>
// #include <QQmlContext>
#include <QApplication>
#include "TcpClient.hpp"
#include "mainwindow.h"
#include "dialog.h"


int main(int argc, char *argv[])
{
// #if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
//     QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
// #endif

    //QGuiApplication app(argc, argv);
    QApplication app(argc,argv);


    // QQmlApplicationEngine engine;
    // const QUrl url(QStringLiteral("qrc:/main.qml"));
    // QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
    //     &app, [url](QObject *obj, const QUrl &objUrl) {
    //         if (!obj && url == objUrl)
    //             QCoreApplication::exit(-1);
    //     }, Qt::QueuedConnection);

    TcpClient client;
    // engine.rootContext()->setContextProperty("client", &client);
    // engine.load(url);



    if(!createConnection())
        return 1;
    Dialog window;//запускаем класс соединения с базой
    window.show();
    return app.exec();
}




