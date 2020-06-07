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


private:
    class Nucleotide{
    public:
        Nucleotide(char nucleotide):m_nucleotide(nucleotide){
            if (!isValid(nucleotide))
                throw ValError("nucleotide in not valid");
        }

        Nucleotide():m_nucleotide(0){}

        DnaSequence::Nucleotide& operator = (const char& nucleotide){
            if (!isValid(nucleotide))
                throw ValError("nucleotide in not valid");
            m_nucleotide = nucleotide;
            return *this;
        }
        char getNuc() const{return m_nucleotide;}

    private:
        char m_nucleotide;
        bool isValid(char nucleotide){
            return((nucleotide == 'A') or (nucleotide == 'C') or (nucleotide == 'G') or (nucleotide == 'T'));
        }
    };

    Nucleotide* m_dna;
    size_t m_length;
    void iniByStr(const std::string& str);
    void initFromOther(const DnaSequence& dnaSequence);

public:

    DnaSequence(const std::string& string);
    DnaSequence(DnaSequence& dnaSequence);
    ~DnaSequence();
    DnaSequence& operator = (const DnaSequence& dnaSequence);
//    DnaSequence& operator = (const char* string);
    DnaSequence& operator = (const std::string& string);
    const Nucleotide & operator [](size_t idx) const;
    Nucleotide& operator [](size_t idx);
    std::string getDna() const;
    size_t length() const ;
    friend std::ostream& operator << (std::ostream& os, const DnaSequence& dnaSequence);

};

//inline bool isValidNuc(const std::string& dna){
//
//    if(std::string(dna).find_first_not_of("ACGT") != std::string::npos)
//        return false;
//    return true;
//}

//inline bool isValidSeq(const std::string& dna){
//
//    if(std::string(dna).find_first_not_of("ACGT") != std::string::npos)
//        return false;
//    return true;
//}
//
//inline std::string checkValid(const std::string& dna){
//
//    if(!isValidSeq(dna))
//        throw ValError("ValError: DNA sequence is not valid");
//    return dna;
//}

inline void DnaSequence::iniByStr(const std::string& str) {
    m_length = str.length();
    if (m_length) {
        m_dna = new Nucleotide[m_length];
        Nucleotide *ptrNucleotide = m_dna;
        try {
            for (std::string::const_iterator iter = str.begin(); *iter; ++iter) {
                *ptrNucleotide++ = *iter;
            }
        }
        catch (ValError &ex) {
            delete[] m_dna;
            m_dna = NULL;
            throw;
        }
    }
}

inline void DnaSequence::initFromOther(const DnaSequence &dnaSequence) {
    m_length = dnaSequence.m_length;
    m_dna = new Nucleotide[m_length];
    try {
        for (size_t i = 0; i < m_length; ++i) {
            (*this)[i] = dnaSequence[i];
        }
    }

    catch (ValError& ex) {
        delete [] m_dna;
        m_dna = NULL;
        throw;
    }

}
inline DnaSequence::DnaSequence(const std::string& str): m_dna(NULL), m_length(0) {
    iniByStr(str);
}

//inline DnaSequence::DnaSequence(char *string) : m_dna(new char [checkValid(string).length()]) {
//    strcpy(m_dna, string);
//}

inline DnaSequence::DnaSequence(DnaSequence &dnaSequence){
    initFromOther(dnaSequence);
}

inline DnaSequence::~DnaSequence() {
    delete [] m_dna;
    m_dna = NULL;
}

inline DnaSequence & DnaSequence::operator=(const DnaSequence &dnaSequence) {
    if(this == &dnaSequence)
        return *this;

    delete [] m_dna;
    m_dna = NULL;
    initFromOther(dnaSequence);

    return *this;
}

inline DnaSequence& DnaSequence::operator=(const std::string &str) {

    delete [] m_dna;
    m_dna = NULL;
    iniByStr(str);

    return *this;
}

inline std::string DnaSequence::getDna() const {
    std::string result;
    for (size_t i = 0; i < m_length; ++i) {
        result += (*this)[i].getNuc();
    }
    return result;
}

inline std::ostream& operator << (std::ostream& os, const DnaSequence& dnaSequence)
{
    os<<dnaSequence.getDna();
    return os;
}

inline const DnaSequence::Nucleotide& DnaSequence::operator[](size_t index) const{
    if(m_length < index)
        throw "out ot range";
    return m_dna[index];
}

inline DnaSequence::Nucleotide& DnaSequence::operator[](size_t index) {
    return const_cast<Nucleotide&>(static_cast<const DnaSequence&>(*this)[index]);
}

inline bool operator == (const DnaSequence& dnaSequence1, const DnaSequence& dnaSequence2) {
    if (dnaSequence1.length() != dnaSequence2.length())
        return false;
    for (size_t i = 0; i < dnaSequence2.length(); ++i) {
        if (dnaSequence1[i].getNuc() != dnaSequence2[i].getNuc())
            return false;
    }
    return true;
}

inline bool operator != (const DnaSequence& dnaSequence1, const DnaSequence& dnaSequence2)
{
    return !(dnaSequence1.getDna() == dnaSequence2.getDna());
}

inline size_t DnaSequence::length() const
{
    return m_length;
}

//inline char DnaSequence::Nucleotide::getNuc() const{
//    return m_nucleotide;
//}

#endif //DNASEQUENCE_DNA_SEQUENCE_H
