#include <iostream>
#include "dna_sequence.h"
#include "test_dna.h"

int main() {
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();

    try {
//        Nucleotide n('C');
        char* c_str= (char *)"C";
        std::string string = "As";
        DnaSequence d1((char *)"CG");
        std::cout<<d1<<std::endl;
        DnaSequence d2(string);
        std::cout<<d2<<std::endl;
        DnaSequence d3(d1);
        std::cout<<d3<<std::endl;
        d3 = d2;
        std::cout<<d3<<std::endl;
        d1 = c_str;
        std::cout<<d1<<std::endl;
        d2 = string;
        std::cout<<d2<<std::endl;
        DnaSequence d4(c_str);
        std::cout<<d4<<std::endl;
        DnaSequence d5(string);
        std::cout<<d5<<std::endl;
//        std::cout<<d5[3]<<std::endl;
        d3 = d1;
        std::cout<<"d3: "<<d3<<std::endl;
        std::cout<<"d1: "<<d1<<std::endl;
        std::cout<<"d5: "<<d5<<std::endl;
        int flag = (d1!=d5);
        std::cout<< flag<<std::endl;

    }

    catch (ValError &error) {
        std::cout<<error.what()<<std::endl;
    }

    return 0;
}
