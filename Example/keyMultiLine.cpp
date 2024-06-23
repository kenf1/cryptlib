#include "../src/cryptlib.cpp"
#include "../src/importkey.cpp"
#include <iostream>
#include <string>

int main(){
    /*
        import contents of `key.txt` as vector
        
        vector[0] = key, use stoi for converting string -> int
        vector[1] = offset
    */
    std::vector cryptKey = importKeyML("../src/key.txt");

    //encrypt
    std::string encryptedMessage = encrypt1("PLACEHOLDER",cryptKey[0],stoi(cryptKey[1]));
    std::cout << encryptedMessage << std::endl;

    //decrypt
    std::string decryptedMessage = decrypt1("PLACEHOLDER",cryptKey[0],stoi(cryptKey[1]));
    std::cout << decryptedMessage << std::endl;

    return 0;
}