//
// Created by ruti on 6/4/20.
//

#include "test_dna.h"
#include <cstring>
#include "dna_sequence.h"
#include <gtest/gtest.h>

TEST(DnaTest, CopyConstractor)
{
    DnaSequence d1((char*)"CG");
    DnaSequence d2(d1);
    ASSERT_TRUE(d2.getDna() == d2.getDna());
}

TEST(DnaTest, CopyConstractorFromString)
{
    std::string string = "C";
    DnaSequence d2(string);
    ASSERT_TRUE(d2.getDna() == string);
}

TEST(DnaTest, OperatorEqual)
{
    DnaSequence d1((char*)"CG");
    DnaSequence d2((char*)"CG");
    ASSERT_TRUE(d1.getDna() == d2.getDna());
}


TEST(DnaTest, OperatorNotEqual)
{
    DnaSequence d1((char*)"CG");
    DnaSequence d2((char*)"C");
    ASSERT_TRUE(d1.getDna() != d2.getDna());

}

TEST(DnaTest, Exeption)
{
    ASSERT_ANY_THROW(DnaSequence d1((char*)"CAR"););
}


TEST(DnaTest, OperatorGet)
{
    DnaSequence d1((char*)"CA");
    ASSERT_EQ(char(d1[0]),'C');
}

TEST(DnaTest, OperatorSet)
{
    DnaSequence d1((char*)"CA");
    d1[0] = 'A';
    char d = d1[0];
    ASSERT_EQ(d,'A');
}


TEST(DnaTest, BasicSlicing)
{
    DnaSequence d1((char*)"CAGGAC");
    ASSERT_EQ(d1.slicing(1,3).getDna(),"AG");
}

TEST(DnaTest, SlicingOutOfRange)
{
    DnaSequence d1((char*)"CAGGAC");
    ASSERT_ANY_THROW(d1.slicing(0,7).getDna());
}

TEST(DnaTest, GetPairSeq)
{
    DnaSequence d1((char*)"GTGC");
    ASSERT_EQ(d1.getPairSeq().getDna(), "GCAC");
}

TEST(DnaTest, SubSeq)
{
    DnaSequence d1((char*)"GTGC");
    DnaSequence d2((char*)"TG");

    ASSERT_EQ(d1.findSubSeq(d2), 1);
}

TEST(DnaTest, NoSubSeq)
{
    DnaSequence d1((char*)"GTGC");
    DnaSequence d2((char*)"A");
    ASSERT_EQ(d1.findSubSeq(d2), -1);
}

TEST(DnaTest, CountSubSeq)
{
    DnaSequence d1((char*)"GCTGC");
    DnaSequence d2((char*)"GC");

    ASSERT_EQ(d1.countSubSeq(d2), 2);
}

TEST(DnaTest, FindAllSubSeq)
{
    DnaSequence d1((char*)"GCTGCGC");
    DnaSequence d2((char*)"GC");
    std::vector<size_t> vector;
    vector.push_back(0);
    vector.push_back(3);
    vector.push_back(5);
    std::vector<size_t> res = d1.findAllSubSeq(d2);
    ASSERT_EQ(res, vector);

}

TEST(DnaTest, FindConsensusSeq)
{
    std::vector<DnaSequence> vect;
    vect.push_back(DnaSequence("ATGTTATGTTGA"));
    vect.push_back(DnaSequence("ATGTTGAGTGTTTAA"));
    ASSERT_EQ(DnaSequence("ATGTTATGTTGAGTGTTTAA").findConsensusSeq(), vect);
    vect.clear();
    ASSERT_EQ(DnaSequence("AAAAAAAAAAATTTTT").findConsensusSeq(), vect);

}