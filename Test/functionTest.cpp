#include "../src/cryptlib.cpp"
#include "../src/importkey.cpp"
#include "assertFunc.cpp"
#include <iostream>

void newln(){
    std::cout << "\n";
}

int main(){
    //create instances
    KeyReader kr;
    CoreLogic cl;

    //encryption dict (single line)
    std::string dict = kr.importKeySL("testkey.txt");

    // testOutput(dict);

    //encryption dict (multi line)
    std::vector<std::string> txtContents = kr.importKeyML("testkey.txt");
    std::cout << txtContents[1] << "\n";
    newln();

    //encrypt: FAIL (char not in dict)
    std::string errStr = "ak=jg";
    std::cout << cl.encrypt1(errStr,dict);
    std::cout << cl.encrypt2(errStr,dict);
    newln();

    //encrypt: PASS
    assertPF("Char only",cl.encrypt1("akjg8",dict,6),"gqpmd");
    assertPF("Char + Int",cl.encrypt2("ac0",dict),"dfc");
    newln();

    //encrypt: FAIL (case-sensitive input)
    assertPF("Char only",cl.encrypt1("akJg8",dict,6),"gqpmd");
    assertPF("Char + Int",cl.encrypt2("aC0",dict),"dfc");
    newln();

    //decrypt PASS
    assertPF("Char only",cl.decrypt1("gqpmd",dict,6),"akjg8");
    assertPF("Char + Int",cl.decrypt2("dfc",dict),"ac0");
    newln();

    //decrypt FAIL
    assertPF("Char only",cl.decrypt1("gQpmd",dict,6),"akjg8");
    assertPF("Char + Int",cl.decrypt2("dfC",dict),"ac0");

    return 0;
}

/*
    DEPRECIATED
    encrypt: print output (dict passed by reference)
*/
void testOutput(std::string& dict){
    CoreLogic cl;

    //shift by set amount (default args)
    std::cout << cl.encrypt1("akjg8",dict,6) << "\n";
    //shift by length of string (default args)
    std::cout << cl.encrypt2("ac0",dict) << "\n";
    newln();
}