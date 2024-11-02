#include "../src/cryptlib.cpp"
#include "../src/importkey.cpp"
#include <iostream>
#include <string>

int main(){
    //create instances
    KeyReader kr;
    CoreLogic cl;

    /*
        import contents of `key.txt` as vector
        
        vector[0] = key, use stoi for converting string -> int
        vector[1] = offset
    */
    std::vector cryptKey = kr.importKeyML("../src/key.txt");

    //encrypt
    std::string encryptedMessage = cl.encrypt1(
        "PLACEHOLDER",cryptKey[0],stoi(cryptKey[1])
    );
    std::cout << encryptedMessage << "\n";

    //decrypt
    std::string decryptedMessage = cl.decrypt1(
        "PLACEHOLDER",cryptKey[0],stoi(cryptKey[1])
    );
    std::cout << decryptedMessage << "\n";

    return 0;
}