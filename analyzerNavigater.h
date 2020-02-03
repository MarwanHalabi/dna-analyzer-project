#ifndef DNA_ANALYZERNAVIGATER_H
#define DNA_ANALYZERNAVIGATER_H

#include "dnaAnalyzer.h"
#include <vector>
#include <map>
#include <sstream>

enum string_code {
    eNew, eLoad, eSave, eDup, eShow,

};

string_code hashit (std::string const& inString) {
    if (inString == "new") return eNew;
    if (inString == "load") return eLoad;
    if (inString == "save") return eSave;
    if (inString == "dup") return eDup;
    if (inString == "show") return eShow;
}


class Navigate{
private:
    std::vector<std::string> commandV;
public:
    explicit Navigate(const std::string& = "");
    ~Navigate();
    void doCommands();

};

inline Navigate::Navigate(const std::string& CL){
    std::stringstream ss(CL);
    std::string temp;
    while (ss >> temp)
        commandV.push_back(temp);
}

inline Navigate::~Navigate(){

}

inline void Navigate::doCommands(){
    if(commandV[0] == "new"){
        //DnaSequenceAnalyzer a(commandV[1],commandV[2]);
    }
    switch (hashit(commandV[0])){
        case eNew:
            break;
        case eLoad:
            //dnaSequenceAnalyzer.load(reinterpret_cast<String &>(commandV[1]), reinterpret_cast<String &>(commandV[2]));
            break;
        case eDup:
            break;
        case eShow:
            break;
        case eSave:
            DnaSequenceAnalyzer dnaSequenceAnalyzer(commandV[1]);
            int n = commandV[1].length();
            char char_array[n + 1];
            strcpy(char_array, commandV[1].c_str());
            dnaSequenceAnalyzer.save(char_array);
            break;
    }
}
#endif //DNA_ANALYZERNAVIGATER_H
