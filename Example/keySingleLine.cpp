#include <iostream>
#include <string>

#include "../src/cryptlib.cpp"
#include "../src/importkey.cpp"

int main(){
    //create instances
    KeyReader kr;
    CoreLogic cl;

    //import key from `key.txt` as string
    std::string cryptKey = kr.importKeySL("../src/key.txt");

    //encrypt
    std::string encryptedMessage = cl.encrypt1(
        "PLACEHOLDER",cryptKey
    );
    std::cout << encryptedMessage << "\n";

    //decrypt
    std::string decryptedMessage = cl.decrypt1(
        "PLACEHOLDER",cryptKey
    );
    std::cout << decryptedMessage << "\n";

    return 0;
}