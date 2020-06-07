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
    ASSERT_EQ(d1[0].getNuc(),'C');
}

