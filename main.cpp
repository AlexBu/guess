#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "guesser.h"
#include "guessee.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterUncreatableType<Guesser>("Guesser", 1, 0, "Guesser1",
        "cannot create guesser object");
    qmlRegisterUncreatableType<Guessee>("Guessee", 1, 0, "Guessee1",
        "cannot create guessee object");

    Guesser the_guesser;
    Guessee the_guessee;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("the_guesser", &the_guesser);
    engine.rootContext()->setContextProperty("the_guessee", &the_guessee);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
