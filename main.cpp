#include <iostream>
#include "dna_sequence.h"
//std::cout<<d5<<std::endl;
//enum {FALSE,TRUE} e_bool;
int main() {
    try {
//        char* c_str= (char *)"ruti kanner";
        std::string string = "Ar";
        DnaSequence d1(string);
        std::cout<<d1<<std::endl;
////    DnaSequence d2("kanner");
////    std::cout<<d2<<std::endl;
//        DnaSequence d3(d1);
//        std::cout<<d3<<std::endl;
//        //d3 = d2;
//        std::cout<<d3<<std::endl;
//        d1 = c_str;
//        std::cout<<d1<<std::endl;
////    d2 = string;
////    std::cout<<d2<<std::endl;
//        DnaSequence d4(c_str);
//        std::cout<<d4<<std::endl;
//        DnaSequence d5(string);
//        std::cout<<d5<<std::endl;
//        std::cout<<d5[3]<<std::endl;
//        d3 = d1;
//        std::cout<<"d3: "<<d3<<std::endl;
//        std::cout<<"d1: "<<d1<<std::endl;
//        std::cout<<"d5: "<<d5<<std::endl;
//        int flag = (d1!=d5);
//        std::cout<< flag<<std::endl;
    }
    catch (const char* error) {
        std::cout<<"catch: "<<error<<std::endl;
    }
    return 0;
}
