#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//import key, only reads line 1 of txt file
std::string importKeySL(std::string fileName){
    std::ifstream txtFile(fileName);

    if(!txtFile.is_open()){
        std::cerr << "Unable to open file" << std::endl;
        return "Fail"; //break
    }

    //read 1st line (remaining lines ignored)
    std::string fileContent;
    std::getline(txtFile,fileContent);

    txtFile.close();
    return fileContent;
}

//import key, all lines -> vector
std::vector<std::string> importKeyML(std::string fileName){
    std::vector<std::string> vec;
    std::ifstream txtFile(fileName);

    if(!txtFile.is_open()){
        std::cerr << "Unable to open file" << std::endl;
        return vec; //break
    }

    //read + append each line to vector
    std::string fileContent;
    while(std::getline(txtFile,fileContent)) {
        vec.push_back(fileContent);
    }

    txtFile.close();
    return vec;
}