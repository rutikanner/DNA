//
// Created by ruti on 6/1/20.
//

#include "dna_sequence.h"

std::vector<DnaSequence> DnaSequence::findConsensusSeq(){
    std::vector<DnaSequence> res;
    DnaSequence d((char *)"ATG");
    std::vector<size_t> startCodon = this -> findAllSubSeq(d);
    size_t i =0;
    for (std::vector<size_t>::iterator iter = startCodon.begin(); iter!= startCodon.end(); ++iter) {
        for (i = *iter+3; i < m_length;i+=3) {
            if(slicing(i,i+3).getDna() == "TAG" || slicing(i,i+3).getDna() == "TGA" || slicing(i,i+3).getDna() == "TAA") {
                break;
            }
        }
        res.push_back(slicing(*iter,i+3));
    }
    return res;
}