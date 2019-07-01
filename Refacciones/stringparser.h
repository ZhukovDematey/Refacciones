#ifndef STRINGPARSER_H
#define STRINGPARSER_H

#include <vector>
#include <QString>
#include <QObject>

class StringParser : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString detectedMatch READ getdetectedMatch WRITE setdetectedMatch NOTIFY detectedMatchChanged)

public:
    explicit StringParser(QObject *parent= nullptr);
    virtual ~StringParser();
    virtual void parseString(QString &parsedString) final;

    QString getdetectedMatch() const;
    void setdetectedMatch(const QString &detectedMatch);

public slots:
    void parseNow(QString stringToParse);

signals:
    void detectedMatchChanged();

private:
    virtual void fillRules();
    bool hasStringMatch(QString stringToParse, size_t ruleToAnalyze);

private:
    std::vector<QString> rules;
    QString m_detectedMatch;
};

#endif // STRINGPARSER_H
