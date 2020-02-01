#include "DNAsequence.h"

std::ostream &operator<<(std::ostream &os,const DnaSequence& dna){
    size_t i = 0, size = dna.getLen();
    for(; i < size; ++i){
        os << dna.getData()[i].getNuc();
    }
    return os;
}

