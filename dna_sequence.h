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
    DnaSequence(const DnaSequence& dnaSequence);
    ~DnaSequence();
    DnaSequence& operator = (const DnaSequence& dnaSequence);
    DnaSequence& operator = (const std::string& string);
    const Nucleotide & operator [](size_t idx) const;
    Nucleotide& operator [](size_t idx);
    std::string getDna() const;
    size_t length() const ;
    void writeToFile(const char* path);
    DnaSequence slicing(size_t start, size_t end) const;
    DnaSequence getPairSeq();
    size_t findSubSeq(const DnaSequence& subSeq);
    size_t countSubSeq(const DnaSequence& subSeq);
    std::vector<size_t> findAllSubSeq(const DnaSequence& subSeq) const;
    std::vector<DnaSequence> findConsensusSeq();
    friend std::ostream& operator << (std::ostream& os, const DnaSequence& dnaSequence);

};

inline DnaSequence::DnaSequence(const std::string& str): m_dna(NULL), m_length(0) {
    iniByStr(str);
}

inline DnaSequence::DnaSequence(const DnaSequence &dnaSequence){
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

inline DnaSequence readFromFile(const char* path) {
    std::ifstream in(path);
    std::string dna;
    in >> dna;
    DnaSequence d(dna);
    return d;
}

inline void DnaSequence::writeToFile(const char* path){
    std::ofstream out(path);
    out << m_dna;
}

inline DnaSequence DnaSequence::slicing(size_t start, size_t end) const{
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

inline size_t DnaSequence::countSubSeq(const DnaSequence& subSeq){

    return findAllSubSeq(subSeq).size();
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
