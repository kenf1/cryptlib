#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//all functions for importing key file
class KeyReader{
public:
    //import key, only line 1 of txt file is read
    std::string importKeySL(std::string fileName){
        std::ifstream txtFile(fileName);

        if(!txtFile.is_open()){
            std::cerr << "Unable to open file\n";
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
            std::cerr << "Unable to open file\n";
            return vec; //empty
        }

        //read + append each line to vector
        std::string fileContent;
        while(std::getline(txtFile,fileContent)){
            vec.push_back(fileContent);
        }

        txtFile.close();
        return vec;
    }
};