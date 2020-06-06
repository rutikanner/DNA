//
// Created by ruti on 6/4/20.
//

#include "test_dna.h"
#include <cstring>
#include "dna_sequence.h"


/////////////////////////////////////
// TESTS under this line

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