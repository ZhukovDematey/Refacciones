#include "stringparser.h"
#include "strmanip.h"
#include <QDebug>

StringParser::StringParser(QObject *parent):
        QObject(parent)
{
    fillRules();
}

StringParser::~StringParser()
{

}

void StringParser::parseString(QString &parsedString)
{
    qDebug()<<"Analyzing: " << parsedString <<endl;

    //Brand Detection Algorithm
    QString::iterator begin_Iter = parsedString.begin();
    QString::iterator brandEnd_Iter = parsedString.begin() + 3;

    QString brandString;

    for(auto iter = begin_Iter; iter < brandEnd_Iter; iter++){
        brandString.append(*iter);
    }

    if(brandString.contains("SKF")){
        setdetectedMatch("SKF autodetected");
    }else if (brandString.contains("FAG")) {
        setdetectedMatch("FAG autodetected");
    }else if (brandString.contains("SNR")) {
        setdetectedMatch("SNR autodetected");
    }
    //Brand

    for(size_t row = 0; row < rules.size(); row++){
        if(hasStringMatch(parsedString, row)){
            qDebug() << "has " << rules.at(row);
            setdetectedMatch("Has " + rules.at(row));
        }
    }
}

void StringParser::parseNow(QString stringToParse)
{
    parseString(stringToParse);
}

void StringParser::fillRules()
{
    rules.push_back("BS2");
    rules.push_back("ZE");
    rules.push_back("W");
    rules.push_back("WBB1");
    rules.push_back("D");

    rules.push_back("N");
    rules.push_back("R");
    rules.push_back("NR");
    rules.push_back("N1");
    rules.push_back("RS1");
    rules.push_back("RS2");
    rules.push_back("RSH");
    rules.push_back("RSH2");
    rules.push_back("RSL");
    rules.push_back("RST");
    rules.push_back("RZ");
    rules.push_back("Z");
    rules.push_back("ZNBR");
    rules.push_back("ZNR");
    rules.push_back("2ZNR");
    rules.push_back("2ZS");
    rules.push_back("X");
    rules.push_back("2RS1");
    rules.push_back("2RS2");
    rules.push_back("2RSH");
    rules.push_back("2RSH2");
    rules.push_back("2RSL");
    rules.push_back("2RST");
    rules.push_back("2RZ");
    rules.push_back("2Z");

    rules.push_back("M");
    rules.push_back("MA(S)");
    rules.push_back("MB(S)");
    rules.push_back("TN");
    rules.push_back("TN9");
    rules.push_back("TN9/VG1561");
    rules.push_back("TNH");

    rules.push_back("HA1");

    rules.push_back("P5");
    rules.push_back("P6");
    rules.push_back("P52");
    rules.push_back("P62");
    rules.push_back("P63");
    rules.push_back("C1");
    rules.push_back("C2");
    rules.push_back("C3");
    rules.push_back("C4");
    rules.push_back("C5");
    rules.push_back("CA");
    rules.push_back("GA");

    rules.push_back("DB");
    rules.push_back("DF");
    rules.push_back("DT");

    rules.push_back("S0");
    rules.push_back("S1");

    rules.push_back("GE2");
    rules.push_back("GFJ");
    rules.push_back("GJN");
    rules.push_back("HT");
    rules.push_back("LHT23");
    rules.push_back("LT");
    rules.push_back("LT10");
    rules.push_back("MT33");
    rules.push_back("VT378");
    rules.push_back("WT");

}

bool StringParser::hasStringMatch(QString stringToParse, size_t ruleToAnalyze)
{
    bool matched = true;
    int searchedSringPos = strsearch(stringToParse, rules.at(ruleToAnalyze));
    if(searchedSringPos != -1){
        for (size_t row = 0; row < rules.size(); row++) {
            if(row  != ruleToAnalyze){
                int similarStringPos = strsearch(stringToParse, rules.at(row));
                if(searchedSringPos == similarStringPos && rules.at(row) > rules.at(ruleToAnalyze)){
                    matched = false;
                }
            }
        }        
    }else{
        matched = false;
    }
    return matched;
}

QString StringParser::getdetectedMatch() const
{
    return m_detectedMatch;
}

void StringParser::setdetectedMatch(const QString &detectedMatch)
{
    m_detectedMatch = detectedMatch;
    emit detectedMatchChanged();
}

