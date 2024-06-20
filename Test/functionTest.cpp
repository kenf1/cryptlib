#include "../src/cryptlib.cpp"
#include "assertFunc.cpp"
#include <iostream>

void newln(){
    std::cout << "\n";
}

int main(){
    //encryption dict
    std::string dict = "abcdefghijklmnopqrstuvwxyz1234567890";

    //shift by set amount (default args)
    std::cout << encrypt1("akjg8",dict,6) << std::endl;
    //shift by length of string (default args)
    std::cout << encrypt2("ac0",dict) << std::endl;
    newln();

    //run tests: Pass
    assertPF(
        "Char only",
        encrypt1("akjg8",dict,6),
        "gqpmd"
    );
    assertPF(
        "Char + Int",
        encrypt2("ac0",dict),
        "dfc"
    );
    newln();

    //run tests: Fail
    assertPF(
        "Char only",
        encrypt1("akJg8",dict,6),
        "gqpmd"
    );
    assertPF(
        "Char + Int",
        encrypt2("aC0",dict),
        "dfc"
    );
    newln();

    /*
        expect error (default args)
        `=` not found in dict
    */
    std::string errStr = "ak=jg";
    std::cout << encrypt1(errStr,dict) << std::endl;
    std::cout << encrypt2(errStr,dict) << std::endl;

    return 0;
}