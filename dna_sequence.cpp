//
// Created by ruti on 6/1/20.
//

#include "dna_sequence.h"

void DnaSequence::iniByStr(const std::string& str) {
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

void DnaSequence::initFromOther(const DnaSequence &dnaSequence) {
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

size_t DnaSequence::findSubSeq(const DnaSequence& subSeq) {

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

std::vector<size_t> DnaSequence::findAllSubSeq(const DnaSequence& subSeq) const{
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

std::vector<DnaSequence> DnaSequence::findConsensusSeq(){
    std::vector<DnaSequence> res;
    DnaSequence d((char *)"ATG");
    std::vector<size_t> startCodon = this -> findAllSubSeq(d);
    size_t i =0;
    for (std::vector<size_t>::iterator iter = startCodon.begin(); iter!= startCodon.end(); ++iter) {
        for (i = *iter+3; i < m_length;i+=3) {
            std::string str = slicing(i,i+3).getDna();
            if(str == "TAG" ||  str == "TGA" ||  str == "TAA") {
                break;
            }
        }
        res.push_back(slicing(*iter,i+3));

    }
    return res;
}