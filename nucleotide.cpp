#include "nucleotide.h"

std::ostream &operator<<(std::ostream &os, const Nucleotide &nuc){
    return (os << nuc.getNuc());
}


