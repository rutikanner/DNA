//
// Created by ruti on 6/1/20.
//

#ifndef DNASEQUENCE_DNA_SEQUENCE_H
#define DNASEQUENCE_DNA_SEQUENCE_H

#include <string>
#include <iostream>
#include <cstring>
#include "val_error.h"
//#include "nucleotide.h"

class DnaSequence{

public:
    DnaSequence(char* string);
    DnaSequence(const std::string& string);
    DnaSequence(DnaSequence& dnaSequence);
    DnaSequence& operator = (const DnaSequence& dnaSequence);
//    DnaSequence& operator = (const char* string);
//    DnaSequence& operator = (const std::string& string);
//    Nucleotide& operator [] (size_t index);
//    void init(const char* dna);
    const char* getDna() const;
    size_t length(const char *string) const ;

private:

//    class Nucleotide;
    char* m_dna;

};

inline bool isValidSeq(const std::string& dna){

    if(std::string(dna).find_first_not_of("ACGT") != std::string::npos)
        return false;
    return true;
}

inline std::string checkValid(const std::string& dna){

    if(!isValidSeq(dna))
        throw ValError("ValError: DNA sequence is not valid");
    return dna;
}


inline DnaSequence::DnaSequence(const std::string& string): m_dna(new char [string.length()]){
    strcpy(m_dna, string.c_str());
}

inline DnaSequence::DnaSequence(char *string) : m_dna(new char [strlen(string)]) {
    strcpy(m_dna, string);
}

inline DnaSequence::DnaSequence(DnaSequence &dnaSequence) : m_dna(new char [(checkValid(dnaSequence.getDna())).length()]){
    strcpy(m_dna, dnaSequence.getDna());
}

//inline void DnaSequence::init(const char *dna) {
//    char *tmp = m_dna;
//    m_dna = new char [strlen(dna)];
//    delete [] tmp;
//    strcpy(m_dna , dna);
//}

inline DnaSequence & DnaSequence::operator=(const DnaSequence &dnaSequence) {
//    init(dnaSequence.m_dna);
    char *tmp = m_dna;
    m_dna = new char [strlen(dnaSequence.m_dna)];
    delete [] tmp;
    strcpy(m_dna , dnaSequence.m_dna);

    return *this;
}
//
//inline DnaSequence&  DnaSequence::operator=(const std::string& dna) {
//    init(checkValid(dna).c_str());
//    return *this;
//}
//
//inline DnaSequence & DnaSequence::operator=(const char* dna) {
//    init(dna);
//    return *this;
//}

inline const char* DnaSequence::getDna() const {return m_dna;}

inline std::ostream& operator << (std::ostream& os, const DnaSequence& dnaSequence)
{
    os<<dnaSequence.getDna();
    return os;
}

//inline char& DnaSequence::operator[] (size_t index)
//{
//    return m_dna[index-1];
//}

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

inline size_t DnaSequence::length(const char *string) const
{
    return strlen(string);
}



#endif //DNASEQUENCE_DNA_SEQUENCE_H
