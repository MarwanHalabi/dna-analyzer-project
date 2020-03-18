#ifndef DNA_DATABASE_H
#define DNA_DATABASE_H

#include <map>
#include "DNAsequence.h"

///////  DATA BASE  ///////
typedef std::map<int, DnaSequence> MIdDna;
typedef std::map<int, std::string> MNameDna;
typedef std::map<std::string,std::vector<std::string> > bCommands;

class DataBase{
public:
    static MIdDna MapIdDna;
    static MNameDna MapIdName;
    static bCommands batchCommands;
};


#endif //DNA_DATABASE_H
