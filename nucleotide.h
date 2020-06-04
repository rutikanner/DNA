//
// Created by ruti on 6/4/20.
//

#ifndef DNASEQUENCE_NUCLEOTIDE_H
#define DNASEQUENCE_NUCLEOTIDE_H
#include "val_error.h"
class Nucleotide{
public:
    Nucleotide(const char& nucleotide);

private:
    char m_nucleotide;
};
inline Nucleotide::Nucleotide(const char &nucleotide) {
    if ((m_nucleotide == 'A') or (m_nucleotide == 'C') or (m_nucleotide == 'G') or m_nucleotide == 'T')
        m_nucleotide = nucleotide;
    else throw ValError("nucleotide in not valid");
}

#endif //DNASEQUENCE_NUCLEOTIDE_H
