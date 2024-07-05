#include "../src/cryptlib.cpp"
#include "../src/importkey.cpp"
#include "assertFunc.cpp"
#include <iostream>

void newln(){
    std::cout << "\n";
}

//encrypt: print output (dict passed by reference)
void testOutput(std::string& dict){
    //shift by set amount (default args)
    std::cout << encrypt1("akjg8",dict,6) << std::endl;
    //shift by length of string (default args)
    std::cout << encrypt2("ac0",dict) << std::endl;
    newln();
}

int main(){
    //encryption dict (single line)
    std::string dict = importKeySL("testkey.txt");

    // testOutput(dict);

    //encryption dict (multi line)
    std::vector<std::string> txtContents = importKeyML("testkey.txt");
    std::cout << txtContents[1] << std::endl;
    newln();

    //encrypt: PASS
    assertPF("Char only",encrypt1("akjg8",dict,6),"gqpmd");
    assertPF("Char + Int",encrypt2("ac0",dict),"dfc");
    newln();

    //encrypt: FAIL (case-sensitive input)
    assertPF("Char only",encrypt1("akJg8",dict,6),"gqpmd");
    assertPF("Char + Int",encrypt2("aC0",dict),"dfc");
    newln();

    //encrypt: FAIL (char not in dict)
    std::string errStr = "ak=jg";
    std::cout << encrypt1(errStr,dict) << std::endl;
    std::cout << encrypt2(errStr,dict) << std::endl;
    newln();

    //decrypt PASS
    assertPF("Char only",decrypt1("gqpmd",dict,6),"akjg8");
    assertPF("Char + Int",decrypt2("dfc",dict),"ac0");
    newln();

    //decrypt FAIL
    assertPF("Char only",decrypt1("gQpmd",dict,6),"akjg8");
    assertPF("Char + Int",decrypt2("dfC",dict),"ac0");

    return 0;
}