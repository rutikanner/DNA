//
// Created by ruti on 6/1/20.
//

#ifndef DNASEQUENCE_DNA_SEQUENCE_H
#define DNASEQUENCE_DNA_SEQUENCE_H
#include <string>
#include <iostream>
#include <cstring>


class DnaSequence{
public:
    DnaSequence(std::string string);
//    DnaSequence(char* string);
    DnaSequence(DnaSequence& dnaSequence);
    DnaSequence& operator = (const DnaSequence& dnaSequence);
//    DnaSequence& operator = (const char* string);
    DnaSequence& operator = (const std::string& string);
    char operator [] (size_t index);
    void init(const char* dna);
    char* getDna() const;
    size_t length(const char *& string) const ;
    std::string isValid(std::string dna) const ;
private:
    char* m_dna;

};


inline DnaSequence::DnaSequence(std::string string) : m_dna(new char [isValid(string).length()]) {
    strcpy(m_dna, string.c_str());
}
//
//inline DnaSequence::DnaSequence(char *string) : m_dna(new char [strlen(string)]) {
//    strcpy(m_dna, string);
//}

inline DnaSequence::DnaSequence(DnaSequence &dnaSequence) : m_dna(new char [(isValid(dnaSequence.getDna())).length()]){
    strcpy(m_dna, dnaSequence.getDna());
}

inline void DnaSequence::init(const char *dna) {
    char* tmp = new char [strlen(dna)];
    strcpy(tmp , dna);
    delete [] m_dna;
    m_dna = tmp;
}

inline DnaSequence & DnaSequence::operator=(const DnaSequence &dnaSequence) {
    init(dnaSequence.m_dna);
    return *this;
}

inline DnaSequence&  DnaSequence::operator=(const std::string& dna) {
    init(isValid(dna).c_str());
    return *this;
}

//inline DnaSequence & DnaSequence::operator=(const char* dna) {
//    init(dna);
//    return *this;
//}

inline char* DnaSequence::getDna() const {return m_dna;}

inline std::ostream& operator << (std::ostream& os, const DnaSequence& dnaSequence)
{
    os<<dnaSequence.getDna();
    return os;
}

inline char DnaSequence::operator[] (size_t index)
{
    return m_dna[index-1];
}

inline bool operator == (const DnaSequence& dnaSequence1, const DnaSequence& dnaSequence2)
{
    if(!strcmp(dnaSequence1.getDna(),dnaSequence2.getDna()))
        return true;
    return false;}

inline bool operator != (const DnaSequence& dnaSequence1, const DnaSequence& dnaSequence2)
{
    if(!strcmp(dnaSequence1.getDna(),dnaSequence2.getDna()))
        return false;
    return true;
}

inline size_t DnaSequence::length(const char *& string) const
{
    return strlen(string);
}

#endif //DNASEQUENCE_DNA_SEQUENCE_H
