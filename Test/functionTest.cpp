#include <iostream>
#include <string>
#include <vector>

#include "../src/cryptlib.cpp"
#include "../src/importkey.cpp"

class Test{
private:
    KeyReader kr;
    CoreLogic cl;
    std::string dict;
    std::vector<std::string> txtContents;

public:
    Test(){
        //import single-line & multi-line key
        dict = kr.importKeySL("testkey.txt");
        txtContents = kr.importKeyML("testkey.txt");
    }

    void assertPF(
        const std::string& testName,
        const std::string& actual,
        const std::string& expected
    ){
        std::cout << testName << ": ";
        if(actual.compare(expected) == 0){
            std::cout << "Pass\n";
        }else{
            std::cout << "Fail\n";
        }
    }

    void runTests(){
        std::cout << "Running tests...\n";

        //encrypt
        std::cout << "\nEncrypt:\n";
        assertPF("Char only",cl.encrypt1("akjg8",dict,6),"gqpmd");
        assertPF("Char + Int",cl.encrypt2("ac0",dict),"dfc");

        //decrypt
        std::cout << "\nDecrypt:\n";
        assertPF("Char only",cl.decrypt1("gqpmd",dict,6),"akjg8");
        assertPF("Char + Int",cl.decrypt2("dfc",dict),"ac0");

        //expect fail
        std::cout << "\nExpected fail:\n";
        std::string errStr = "ak=jg";
        std::cout << cl.encrypt1(errStr,dict);
        std::cout << cl.encrypt2(errStr,dict);
    }
};

int main(){
    Test test;
    test.runTests();

    return 0;
}