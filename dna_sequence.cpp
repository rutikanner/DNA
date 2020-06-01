//
// Created by ruti on 6/1/20.
//

#include "dna_sequence.h"

std::string DnaSequence::isValid(std::string dna) const {
    for (size_t i = 0; i < dna.length(); ++i) {
        if (!(dna[i] == 'A' or dna[i] == 'G' or dna[i] == 'C' or dna[i] == 'T'))
            throw "DNA sequence is not valid";
    }
    return dna;
}