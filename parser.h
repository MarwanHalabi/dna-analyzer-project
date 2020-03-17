#ifndef DNA_PARSER_H
#define DNA_PARSER_H

#include "commands.h"

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
        Save SAVE;
        Load LOAD;
        Dup DUP;
        Slice SLICE;
        SC.insert(std::pair<std::string, Icommand *>("new", &NEW));
        SC.insert(std::pair<std::string, Icommand *>("save", &SAVE));
        SC.insert(std::pair<std::string, Icommand *>("load", &LOAD));
        SC.insert(std::pair<std::string, Icommand *>("dup", &DUP));
        SC.insert(std::pair<std::string, Icommand *>("slice", &SLICE));

        for (std::string line; std::getline(std::cin, line);) {
            Navigate parser(SC,line);
        }
    }
};


#endif //DNA_PARSER_H
