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
    void batchMode();

};



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
        Len LEN;
        Find FIND;
        Count COUNT;
        findAll FINDALL;
        batch BATCH;
        batchSave BATCHSAVE;
        batchLoad BATCHLOAD;
        batchShow BATCHSHOW;
        batchList BATCHLIST;

        SC.insert(std::pair<std::string, Icommand *>("new", &NEW));
        SC.insert(std::pair<std::string, Icommand *>("load", &LOAD));
        SC.insert(std::pair<std::string, Icommand *>("dup", &DUP));

        SC.insert(std::pair<std::string, Icommand *>("slice", &SLICE));
        SC.insert(std::pair<std::string, Icommand *>("save", &SAVE));

        SC.insert(std::pair<std::string, Icommand *>("len", &LEN));
        SC.insert(std::pair<std::string, Icommand *>("find", &FIND));
        SC.insert(std::pair<std::string, Icommand *>("count", &COUNT));
        SC.insert(std::pair<std::string, Icommand *>("findAll", &FINDALL));

        SC.insert(std::pair<std::string, Icommand *>("batch", &BATCH));
        SC.insert(std::pair<std::string, Icommand *>("batchSave", &BATCHSAVE));
        SC.insert(std::pair<std::string, Icommand *>("batchLoad", &BATCHLOAD));
        SC.insert(std::pair<std::string, Icommand *>("batchShow", &BATCHSHOW));
        SC.insert(std::pair<std::string, Icommand *>("batchList", &BATCHLIST));

        std::cout<<BOLDGREEN<<"> cmd >>> "<<RESET;
        for (std::string line; std::getline(std::cin, line);std::cout<<BOLDGREEN<<"> cmd >>> "<<RESET) {
            Navigate parser(SC,line);
        }
    }
};


#endif //DNA_PARSER_H
