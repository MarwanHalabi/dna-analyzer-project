#ifndef DNA_DATABASE_H
#define DNA_DATABASE_H

#include <map>
#include "DNAsequence.h"

///////  DATA BASE  ///////
typedef std::map<int, DnaSequence> MIdDna;
typedef std::map<int, std::string> MNameDna;

class DataBase{
public:
    static MIdDna MapIdDna;
    static MNameDna MapIdName;
};


#endif //DNA_DATABASE_H
