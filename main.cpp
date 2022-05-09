#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "guesser.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<Guesser>("Guesser", 1, 0, "Guesser1");
        //QStringLiteral("this is the guesser class"));

    Guesser the_guesser;
    //the_guesser.echo();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("the_guesser", &the_guesser);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
