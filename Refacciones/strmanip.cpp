#include "strmanip.h"
#include <iostream>

using namespace std;

bool compare(int samplePosition, QString sample, QString searchValue);

int strsearch(QString sample, QString searchValue)
{
    for(int i = 0; i < sample.length(); i++){
        if((sample.at(i) ==  searchValue.at(0)) && compare(i, sample, searchValue)){
            return i;
        }
    }
    return  -1;
}

bool compare(int samplePosition, QString sample, QString searchValue){
    int i = 0;
    while((samplePosition < sample.length()) &&
          (i < searchValue.length())){

        if(sample.at(samplePosition) != searchValue.at(i)){
            return false;
        }
        samplePosition++;
        i++;
    }
    return (i == searchValue.length());
}
