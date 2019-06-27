#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCoreApplication>
#include "stringparser.h"

void analyzePS(QString bearing);
bool hasStringMatch(QString bearing, size_t row, size_t column);

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QString sampleB = "ZE6001NRS1RZ";

    StringParser bearingsParser;
    bearingsParser.parseString(sampleB);

    return a.exec();
}
