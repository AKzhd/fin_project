#include <QGuiApplication>
//#include <QQmlApplicationEngine>
//#include <QQmlContext>
#include <QApplication>
#include "TcpServer.h"
#include "pgsql.h"
#include <QMainWindow>
#include "mainwindow.h"

#include <QtCore/QCoreApplication>

int main(int argc, char *argv[])
{

// #if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
//     QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
// #endif

    QApplication app(argc, argv);
    // QQmlApplicationEngine engine;
    // const QUrl url(QStringLiteral("qrc:/main.qml"));
    // QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
    //     &app, [url](QObject *obj, const QUrl &objUrl) {
    //         if (!obj && url == objUrl)
    //             QCoreApplication::exit(-1);
    //     }, Qt::QueuedConnection);



   // TcpServer tcpServer;

    // engine.rootContext()->setContextProperty("server", &tcpServer);

    // engine.load(url);


    if(!createConnection())
        return 1;
    if(!createTables())
        return 1;
    auto w= new MainWindow();
    w->show();//показываем MainWindow
    // QMainWindow window;
    // window.show();
    return app.exec();



}

