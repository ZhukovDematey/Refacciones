#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <memory>
#include "stringparser.h"

int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QQmlContext *context = engine.rootContext();
    std::unique_ptr<StringParser> parser(new StringParser);
    context->setContextProperty("stringParser", parser.get());


    QString sampleB = "ZE6001NRS1RZ";
    StringParser bearingsParser;
    bearingsParser.parseString(sampleB);

    engine.load(QUrl(QStringLiteral("qrc:/Main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
