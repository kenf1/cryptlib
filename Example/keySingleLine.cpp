#include "../src/cryptlib.cpp"
#include "../src/importkey.cpp"
#include <iostream>
#include <string>

int main(){
    //import key from `key.txt` as string
    std::string cryptKey = importKeySL("../src/key.txt");

    //encrypt
    std::string encryptedMessage = encrypt1("PLACEHOLDER",cryptKey);
    std::cout << encryptedMessage << "\n";

    //decrypt
    std::string decryptedMessage = decrypt1("PLACEHOLDER",cryptKey);
    std::cout << decryptedMessage << "\n";

    return 0;
}