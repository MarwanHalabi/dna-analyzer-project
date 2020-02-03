#ifndef DNA_DNAANALYZER_H
#define DNA_DNAANALYZER_H

#include "DNAsequence.h"

class DnaSequenceAnalyzer{

public:
    explicit DnaSequenceAnalyzer(std::basic_string<char> dna, const char *name = "");
    DnaSequenceAnalyzer();
    void load(const String& path, const String& name = "");
    void save(const String file_name = "");
    void dup(const String& source, const String& name = "");
    void show(const String& source);
    ~DnaSequenceAnalyzer();



private:
    size_t m_id;
    String m_name;
    DnaSequence m_dna_seq;
    String m_status;
    static size_t id;
};


inline DnaSequenceAnalyzer::DnaSequenceAnalyzer(std::basic_string<char> dna, const char *name) {
    m_id = ++id;
    m_dna_seq = dna;
    m_status = "new";
    if(name == ""){
        char str[20];
        sprintf(str, "%lu", m_id);
        String temp(str);
        m_name = "seq_";
        m_name += temp;
    }
    else{
        m_name = name;
    }
}

inline DnaSequenceAnalyzer::DnaSequenceAnalyzer() {
    m_id = 0;
    m_name = "";
    m_dna_seq = "";
    m_status = "new";
}

inline DnaSequenceAnalyzer::~DnaSequenceAnalyzer() {
    delete[] m_dna_seq.getData();
}


inline void DnaSequenceAnalyzer::load(const String& path, const String& name ){

}

inline void DnaSequenceAnalyzer::save(const String file_name ){
    m_dna_seq.save_to_file("test.txt");
}

inline void DnaSequenceAnalyzer::dup(const String& soruce, const String& name){

}

inline void DnaSequenceAnalyzer::show(const String& source){

}

#endif //DNA_DNAANALYZER_H
