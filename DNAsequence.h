#ifndef DNA_DNASEQUENCE_H
#define DNA_DNASEQUENCE_H

#include <cstring>
#include <cstdlib>
#include <fstream>
#include <string>
#include <map>
#include <iterator>
#include "nucleotide.h"

class DnaSequence{

public:
    //constructor by file data
    explicit DnaSequence(const char* path );

    //constructor by string data
    explicit DnaSequence(const String& str);

    explicit DnaSequence(const std::string& str);

    //default constructor
    DnaSequence();
    //deconstructor
    ~DnaSequence();

    //assignment operators
    DnaSequence& operator = (const DnaSequence& dna);
    DnaSequence& operator = (const char* data);
    DnaSequence& operator = (const String& str);
    DnaSequence& operator = (Nucleotide* data);

    //check if the data is legal
    bool isDna(const char* data) const;
    bool isDna(const String& data) const;
    bool isDna(const std::string& data) const;

    //get the nec
    const Nucleotide* getData() const;
    //get the sequence size
    size_t getLen() const;

    bool operator == (const DnaSequence& dna) const;  // out of the class so we won't make an access to the object's parts
    bool operator != (const DnaSequence& dna) const;

    // index [] operator for easy access
    Nucleotide operator [] (size_t n) const;

    void save_to_file(const char* path);
    DnaSequence makeSlice(size_t start, size_t end);
    std::string pairDna();
    std::string get_str();
    friend std::ostream& operator << (std::ostream& os,const DnaSequence& dna);


private:
    Nucleotide* m_data;
};

inline DnaSequence::DnaSequence(const char *path) {
    std::ifstream file(path);
    std::string data;

    if (file.is_open()){
        getline (file,data);
        file.close();
    }
    else{
        throw std::exception();
    }

    if(isDna(data)){
        size_t size = data.length(), i = 0;
        m_data = new Nucleotide[size + 1] ;
        for(; i < size; ++i){
            m_data[i] = data[i];
        }
        m_data[size] = '\0';
    }
    else {
        throw std::exception();
    }
}

inline DnaSequence::DnaSequence(const String &str){
    if(isDna(str)){
        size_t size = str.getLen(), i = 0;
        m_data = new Nucleotide[size + 1] ;
        for(; i < size; ++i){
            m_data[i] = str[i];
        }
        m_data[size] = '\0';
    }
}

inline DnaSequence::DnaSequence(const std::string& str){
    if(isDna(str)){
        size_t size = str.size(), i = 0;
        m_data = new Nucleotide[size + 1] ;
        for(; i < size; ++i){
            m_data[i] = str[i];
        }
        m_data[size] = '\0';
    }
}


inline DnaSequence::DnaSequence() {
    m_data = NULL;
}

inline DnaSequence::~DnaSequence() {}

inline const Nucleotide* DnaSequence::getData() const{
    return this->m_data;
}

inline DnaSequence &DnaSequence::operator=(const DnaSequence &dna) {
    size_t size = dna.getLen(), i = 0;
    delete[] m_data;
    m_data = new Nucleotide[size+1];

    for(; i < size; i++){
        m_data[i] = dna.m_data[i];
    }
    m_data[size] = '\0';

    return *this;
}

inline DnaSequence &DnaSequence::operator=(const char *data) {
    if(this->isDna(data)) {
        size_t size = strlen(data), i = 0;
        delete[] m_data;
        m_data = new Nucleotide[size + 1];

        for (; i < size; i++) {
            m_data[i] = data[i];
        }
        m_data[size] = '\0';
    }
    return *this;
}

inline DnaSequence &DnaSequence::operator=(const String &str) {
    if(this->isDna(str)) {
        size_t size = str.getLen(), i = 0;
        delete[] m_data;
        m_data = new Nucleotide[size + 1];

        for (; i < size; i++) {
            m_data[i] = (str[i]);
        }
        m_data[size] = '\0';
    }
    return *this;
}


inline DnaSequence &DnaSequence::operator=(Nucleotide *data) {
    size_t size = 0, i = 0;
    delete[] m_data;
    while (data[size++]!='\0'){}
    m_data = new Nucleotide[size--];

    for(; i < size; i++){
        m_data[i] = (data[i]);
    }
    m_data[size] = '\0';
    return *this;
}

inline bool DnaSequence::operator == (const DnaSequence& dna)const {
    size_t i = 0, l1 = this->getLen();

    if (l1 != dna.getLen()){
        return false;
    }

    for(;i<l1;i++){
        if(m_data[i].getNuc() != dna.getData()[i].getNuc()){ return false;}
    }
    return true;
}

inline bool DnaSequence::operator != (const DnaSequence& dna) const {
    return !(*this==dna);
}


inline Nucleotide DnaSequence::operator[](size_t n) const {
    if( n > (this->getLen()-1) ){ throw std::exception(); }
    return this->m_data[n];
}


inline bool DnaSequence::isDna(const char *data) const{
    size_t  i = 0, l1 = strlen(data);
    for(; i<=l1 ; i++){
        if(!(*(data+i) == 'A' || *(data+i) == 'T' || *(data+i) == 'C' || *(data+i) == 'G')){
            throw std::exception();
        }
    }
    return true;
}

/**/
inline bool DnaSequence::isDna(const String &data) const {
    size_t  i = 0, l1 = data.getSize();
    for(; i<l1 ;i++){
        if( ! (data[i] == 'A' || data[i] == 'T' || data[i] == 'C' || data[i] == 'G') ){
            throw std::exception();
        }
    }
    return true;
}
/**/
inline bool DnaSequence::isDna(const std::string &data) const {
    size_t  i = 0, l1 = data.size();
    for(;i<l1;i++){
        if(!(data[i] == 'A' || data[i] == 'T' || data[i] == 'C' || data[i] == 'G')){
            throw std::exception();
        }
    }
    return true;
}

inline size_t DnaSequence::getLen() const {
    size_t c = 0;
    while(m_data[c++]!='\0'){}
    return --c;
}

inline void DnaSequence::save_to_file(const char *path) {
    std::ofstream new_file;
    new_file.open(path);
    new_file << *this;
    new_file.close();
}

inline DnaSequence DnaSequence::makeSlice( size_t start ,size_t end){

    if( end > this->getLen() || start< 0 || start>end){throw std::exception();}

    else{
        Nucleotide* slice = new Nucleotide[end - start+1];
        DnaSequence DNA_Slice;
        size_t i =0;

        for(;i<end- start;i++){
            slice[i] = m_data[i+start];
        }
        slice[end- start+1 ] = '\0';
        DNA_Slice = slice;
        return DNA_Slice;
    }
}

inline std::string DnaSequence::pairDna(){
    std::string rev = "";
    size_t len = this->getLen() ,i;
    for( i = len ; i >= 1 ; i--){
        rev+=this->getData()[i-1].getDnaPair();
        rev+=this->getData()[i-1].getNuc();
    }
    return rev;
}

inline std::string DnaSequence::get_str(){
    std::string wtr = "";
    size_t len = this->getLen() ,i;
    for( i = 0 ; i < len ; i++){
        wtr += this->getData()[i].getNuc();
    }
    return wtr;
}

#endif