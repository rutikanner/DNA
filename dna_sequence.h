//
// Created by ruti on 6/1/20.
//

#ifndef DNASEQUENCE_DNA_SEQUENCE_H
#define DNASEQUENCE_DNA_SEQUENCE_H

#include <string>
#include <iostream>
#include <cstring>
#include "val_error.h"
#include <fstream>
#include <vector>

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
        char getPairNuc() const {
            if (m_nucleotide == 'T')
                return 'A';
            if (m_nucleotide == 'A')
                return 'T';
            if (m_nucleotide == 'G')
                return 'C';

            return 'G';

        }
        operator char(){return m_nucleotide;}

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
    DnaSequence& operator = (const std::string& string);
    const Nucleotide & operator [](size_t idx) const;
    Nucleotide& operator [](size_t idx);
    std::string getDna() const;
    size_t length() const ;
    void readFromFile(const std::string& fileName);
    void writeToFile(const std::string& fileName);
    DnaSequence slicing(size_t start, size_t end);
    DnaSequence getPairSeq();
    size_t findSubSeq(const DnaSequence& subSeq);
    size_t countSubSeq(const DnaSequence& subSeq);
    std::vector<size_t> findAllSubSeq(const DnaSequence& subSeq);
    std::vector<DnaSequence> findConsensusSeq(const DnaSequence& dnaSeq);
    friend std::ostream& operator << (std::ostream& os, const DnaSequence& dnaSequence);

};

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

inline const DnaSequence::Nucleotide& DnaSequence::operator[](size_t index) const{
    if(m_length < index)
        throw "out ot range";
    return m_dna[index];
}

inline DnaSequence::Nucleotide& DnaSequence::operator[](size_t index) {
    return const_cast<Nucleotide&>(static_cast<const DnaSequence&>(*this)[index]);
}

inline std::string DnaSequence::getDna() const {
    std::string result;
    for (size_t i = 0; i < m_length; ++i) {
        result += (*this)[i].getNuc();
    }
    return result;
}

inline size_t DnaSequence::length() const
{
    return m_length;
}

//inline void DnaSequence::readFromFile(const std::string& fileName) {
//    std::ifstream in(fileName);
//    std::string dna;
//    in >> dna;
//    iniByStr(dna);
//}
//
//inline void DnaSequence::writeToFile(const std::string& fileName){
//    std::ofstream out(fileName);
//    out << m_dna;
//}

inline DnaSequence DnaSequence::slicing(size_t start, size_t end) {
    std::string result;

    if(end < start || end > m_length)
        throw "out of range";

    for (size_t i = start; i < end; ++i) {
        result += m_dna[i].getNuc();
    }
    DnaSequence d(result);

    return d;
}

inline DnaSequence DnaSequence::getPairSeq() {
    std::string result;

    for (size_t i = m_length; i > 0 ; --i) {
        result+= m_dna[i -1].getPairNuc();
    }
    DnaSequence d(result);

    return d;
}

inline size_t DnaSequence::findSubSeq(const DnaSequence& subSeq) {

    for (size_t i = 0; i < m_length; ++i) {

        if(m_dna[i] == subSeq.m_dna[0])
        {
            size_t j;
            for (j = 0; j < subSeq.m_length; ++j) {
                if (m_dna[i+j] != subSeq.m_dna[j])
                    break;

                if(subSeq.m_length -1 == j)
                    return i;
            }
        }
    }
    return -1;
}

inline size_t DnaSequence::countSubSeq(const DnaSequence& subSeq){

    return findAllSubSeq(subSeq).size();
}

inline std::vector<size_t> DnaSequence::findAllSubSeq(const DnaSequence& subSeq){
    std::vector<size_t> vec;
    size_t j =0;

    for (size_t i = 0; i < m_length; ++i) {

        if (m_dna[i] == subSeq.m_dna[0]) {

            for (j = 0; j < subSeq.m_length; ++j) {

                if (m_dna[i + j] != subSeq.m_dna[j])
                    break;

                if (subSeq.m_length - 1 == j) {
                    vec.push_back(i);
                }

            }
        }
    }
    return vec;
}

inline std::vector<DnaSequence> DnaSequence::findConsensusSeq(const DnaSequence& dnaSeq){

}


inline std::ostream& operator << (std::ostream& os, const DnaSequence& dnaSequence)
{
    os<<dnaSequence.getDna();
    return os;
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


#endif //DNASEQUENCE_DNA_SEQUENCE_H
