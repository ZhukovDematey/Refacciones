#ifndef STRINGPARSER_H
#define STRINGPARSER_H

#include <vector>
#include <QString>

class StringParser
{
public:
    StringParser();
    virtual ~StringParser();

private:
    virtual void fillRules();

private:
    std::vector<QString> rules;
};

#endif // STRINGPARSER_H
