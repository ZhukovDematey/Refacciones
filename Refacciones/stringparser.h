#ifndef STRINGPARSER_H
#define STRINGPARSER_H

#include <vector>
#include <QString>

class StringParser
{
public:
    StringParser();
    virtual ~StringParser();
    virtual void parseString(QString &parsedString) final;

private:
    virtual void fillRules();
    bool hasStringMatch(QString stringToParse, size_t ruleToAnalyze);

private:
    std::vector<QString> rules;
};

#endif // STRINGPARSER_H
