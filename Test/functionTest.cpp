#include "../src/cryptlib.cpp"
#include <iostream>

int main(){
    //encryption dict
    std::string dict = "abcdefghijklmnopqrstuvwxyz1234567890";

    //shift by set amount (default args)
    std::cout << encrypt1("akjg8",dict,6) << std::endl;

    //shift by length of string (default args)
    std::cout << encrypt2("ac0",dict) << std::endl;

    /*
        expect error (default args)
        `=` not found in dict
    */
    std::string errStr = "ak=jg";
    std::cout << encrypt1(errStr,dict) << std::endl;
    std::cout << encrypt2(errStr,dict) << std::endl;

    return 0;
}