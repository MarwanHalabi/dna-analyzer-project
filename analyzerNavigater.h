#ifndef DNA_ANALYZERNAVIGATER_H
#define DNA_ANALYZERNAVIGATER_H

#include "DNAsequence.h"
#include <vector>
#include <map>
#include <sstream>


typedef std::vector<std::string> VStr;
typedef std::map<int, DnaSequence*> MIdDna;
typedef std::map<std::string, DnaSequence*> MNameDna;


///////  DATA BASE  ///////

class DataBase{
public:
    static MIdDna MapIdDna;
    static MNameDna MapIdName;
};

/////// COMMAND INTERFACE ///////
class Icommand{
public:
    virtual void execute(VStr) = 0;
};

/////// COMMANDS ///////
class New: public Icommand{
private:
    static int ID;
    int currentID;
public:
    void execute(VStr commandV){
        DnaSequence Dna(commandV[1]);
        currentID = ID++;
        DataBase::MapIdDna.insert(std::pair<int,DnaSequence*>(currentID,&Dna));
        std::cout<<"["<<currentID<<"]"<<*DataBase::MapIdDna[currentID]<<"\n";
    }
};


/////// PARSER ///////
typedef std::map<std::string,Icommand*> strCommands ;

class Navigate{
private:
    VStr commandV;
    strCommands doCommandsV;
public:
    explicit Navigate(strCommands SC, const std::string& = "");
    ~Navigate();
    void doCommands();

};

inline Navigate::Navigate(strCommands SC, const std::string& CL){
    std::stringstream ss(CL);
    std::string temp;
    while (ss >> temp)
        commandV.push_back(temp);
    doCommandsV = SC;
    doCommands();
}

inline Navigate::~Navigate(){

}

inline void Navigate::doCommands(){
    doCommandsV[commandV[0]]->execute(commandV);
    }


/////// CONTROLLER ///////
class Controller{
public:
    static void start() {
        strCommands SC;
        New NEW;
        SC.insert(std::pair<std::string, Icommand *>("new", &NEW));

        for (std::string line; std::getline(std::cin, line);) {
            Navigate parser(SC,line);
        }
    }
};

#endif //DNA_ANALYZERNAVIGATER_H
