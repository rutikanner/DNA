#include <iostream>
#include "dna_sequence.h"

int main() {
    char* c_str= (char *)"ruti kanner";
    std::string string = "shoshi rizel";
    DnaSequence d1((char*) "ruti");
    std::cout<<d1<<std::endl;
//    DnaSequence d2("kanner");
//    std::cout<<d2<<std::endl;
    DnaSequence d3(d1);
    std::cout<<d3<<std::endl;
    //d3 = d2;
    std::cout<<d3<<std::endl;
    d1 = c_str;
    std::cout<<d1<<std::endl;
//    d2 = string;
//    std::cout<<d2<<std::endl;
    DnaSequence d4(c_str);
    std::cout<<d4<<std::endl;
    DnaSequence d5(string);
    std::cout<<d5<<std::endl;

    return 0;
}
