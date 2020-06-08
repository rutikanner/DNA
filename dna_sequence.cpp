//
// Created by ruti on 6/1/20.
//

#include "dna_sequence.h"

std::vector<DnaSequence> DnaSequence::findConsensusSeq(){
    std::vector<DnaSequence> res;
    DnaSequence d((char *)"ATG");
    std::vector<size_t> startCodon = this -> findAllSubSeq(d);
    bool found = false;
    size_t i =0;

//    for(auto iter = begin (startCodon); iter != end (startCodon); ++iter){
    for (std::vector<size_t>::iterator iter = startCodon.begin(); *iter; ++iter) {
        for (i = *iter+3; i < m_length && found== false;i+=3) {
            if(slicing(i,i+3).getDna() == "TAG" || slicing(i,i+3).getDna() == "TGA" || slicing(i,i+3).getDna() == "TAA")
                if(i-*iter %3 == 0)
                {
                    found = true;
//                    res.push_back(DnaSequence(std::string(m_dna + *iter, m_dna + i + 3)));
//                    res.push_back(slicing(*iter,i+3));
                }
        }
        res.push_back(slicing(*iter,i+3));

    }
    return res;
}