#ifndef DNA_NUCLEOTIDE_H
#define DNA_NUCLEOTIDE_H

#include "stringclass.h"

class Nucleotide{

public:
    //default constructor
    Nucleotide();
    //constructor by char
    Nucleotide(char nuc);
    //empty deconstrctor for future use
    ~Nucleotide();

    //assigment operators: by char or another object
    Nucleotide& operator = (const Nucleotide& nuc);
    Nucleotide& operator = (char nuc);

    //return the nuc data
    char getNuc() const;

    //compare operators
    bool operator == (const Nucleotide& nuc) const;  // out of the class so we won't make an access to the object's parts
    bool operator != (const Nucleotide& nuc);

    // << operator to stream out
    friend std::ostream& operator << (std::ostream& os,const Nucleotide& nuc);

    //check if this char can be part of dna
    bool isDnaNuc(char nuc) const;
    char getDnaPair() const;

private:

    char m_nuc;
};

inline Nucleotide::Nucleotide() {
    m_nuc = '\0';
}

inline Nucleotide::Nucleotide(char nuc) {
    if(isDnaNuc(nuc)){
        m_nuc = nuc;
    }
}

inline Nucleotide::~Nucleotide() {}


inline bool Nucleotide::isDnaNuc(char nuc) const{
    if(nuc == 'A' || nuc == 'T' || nuc == 'C' || nuc == 'G' || nuc == '\0'){ return true;}
    throw std::exception();
}

inline Nucleotide &Nucleotide::operator=(const Nucleotide &nuc) {
    m_nuc = nuc.m_nuc;
    return *this;
}

inline Nucleotide &Nucleotide::operator=(const char nuc) {
    if(this->isDnaNuc(nuc)) {
        m_nuc = nuc;
        return *this;
    }
}

inline char Nucleotide::getNuc() const {
    return this->m_nuc;
}

inline bool Nucleotide::operator==(const Nucleotide &nuc) const{
    return (this->getNuc() == nuc.getNuc());
}

inline bool Nucleotide::operator!=(const Nucleotide &nuc) {
    return !(*this == nuc);
}

inline char Nucleotide::getDnaPair() const {
    char nuc = m_nuc;
    if (nuc == 'A'){return 'T';}
    else if (nuc == 'T'){ return 'A';}
    else if (nuc == 'G'){ return 'C';}
    else return 'G';
}

std::ostream &operator<<(std::ostream &os, const Nucleotide &nuc);


#endif