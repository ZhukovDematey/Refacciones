#include <QCoreApplication>
#include <array>
#include <QString>
#include <iostream>

using namespace std;

void analyzePS(QString bearing);

array<array<QString,2>,66> rules = {"BS2", "Indefinido",
                                    "ZE", "Indefinido",
                                    "W", "Stainless steel",
                                    "WBB1", "Stainless steel/Not with ISO rules",
                                    "D", "Dimentions on inches",

                                    "N", "Only 1 groove",
                                    "R", "Only 1 snap ring",
                                    "NR", "Only 1 groove, snap ring",
                                    "N1", "Only 1 groove a fixing groove (notch) on one side of the outer ring",
                                    "RS1", "1 seal neoprene modification on the seal",
                                    "RS2", "1 seal viton high friction",
                                    "RSH", "1 seal neoprene high friction",
                                    "RSH2", "1 seal viton high friction",
                                    "RSL", "1 seal neoprene low friction",
                                    "RST", "1 seal neoprene low friction",
                                    "RZ", "1 seal steel, groove non contact",
                                    "Z", "1 seal steel",
                                    "ZNBR", "1 seal steel seal groove and ring at the same side as teh seal",
                                    "ZNR", "1 seal steel seal, groove and ringe at the opposite side as the seal",
                                    "2ZNR", "2 steel seal with groove and ring",
                                    "2ZS", " 2 steel seal, groove and ring at the oppostie side as the seal",
                                    "X", "dimentions do not follow iso",
                                    "2RS1", "2 seals neoprene",
                                    "2RS2", "2 seals viton",
                                    "2RSH", "2 seals neoprene",
                                    "2RSH2", "2 seals viton",
                                    "2RSL", "2 seals neoprene",
                                    "2RST", "2 seals neoprene",
                                    "2RZ", "2 seals, groove",
                                    "2Z", "2 seals steel",

                                    "M", "Cage of brass",
                                    "MA(S)", "Cage of brass, lubrication guide on position \"a\"",
                                    "MB(S)", "Cage of brass, lubrication guide on position \"b\"",
                                    "TN", "Polyamide(nylon) cage",
                                    "TN9", "Polyamide 66(nylon) cage reinforced with glass fiber",
                                    "TN9/VG1561", "Polyamide 46(nylon) cage reinforced with glass fiber",
                                    "TNH", "PEEk cage reinforced with glass fiber",

                                    "HA1", "Ignore for now",

                                    "P5", "p5 level of heat resistance",
                                    "P6", "p6 level of heat resistance",
                                    "P52", "p5 level of heat resistance C2 ball",
                                    "P62", "p6 level of heat resistance C2 ball",
                                    "P63", "p6 level of heat resistance C3 ball",
                                    "C1", "cmaller than size c2",
                                    "C2", "smaller than size than normal",
                                    "C3", "bigger than normal",
                                    "C4", "bigger than c3",
                                    "C5", "bigger than c4",
                                    "CA", "ignore for now",
                                    "GA", "ignore for now",

                                    "DB", "Ignore for now",
                                    "DF", "Ignore for now",
                                    "DT", "Ignore for now",

                                    "S0", "Ignore for now",
                                    "S1", "Ignore for now",

                                    "GE2", "Ignore for now",
                                    "GFJ", "Ignore for now",
                                    "GJN", "Ignore for now",
                                    "HT", "Ignore for now",
                                    "LHT23", "Ignore for now",
                                    "LT", "Ignore for now",
                                    "LT10", "Ignore for now",
                                    "MT33", "Ignore for now",
                                    "MT47", "Ignore for now",
                                    "VT378", "Ignore for now",
                                    "WT", "Ignore for now"


                                   };


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString sampleB = "zE6001NRS1RZ";
    analyzePS(sampleB);

    return a.exec();
}

void analyzePS(QString bearing){

    cout<<"Analyzing: " << bearing.toStdString()<<endl;
    for(size_t row = 0; row < rules.size(); row++){
        bool matchDetected = false;

        for(size_t column = 0; column < rules[row].size(); column++){
            if(column == 0){
                if(bearing.contains(rules[row][column], Qt::CaseInsensitive)){
                    matchDetected = true;
                    cout <<"Has "<<rules[row][column].toStdString();
                }
            }else{
                if(matchDetected){
                    cout<<": "<<rules[row][column].toStdString()<<endl;
                    matchDetected = false;
                }
            }
        }
    }
}


/*for(auto const &row : rules)
{
    for(auto const &element : row){
        cout << element.toStdString()<<" ";
    }
    cout << endl;
}
*/
