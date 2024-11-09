#include <string>
#include <vector>
#include <iostream>

//backend logic + wrapper functions
class CoreLogic{
public:
    //backend logic for encrypting input string, case sensitive
    std::string cryptLogic(
        std::string ver, //case-sensitive, accepted values: encrypt, decrypt
        std::string input,
        const std::string& refDict,
        int offset
    ){
        //reserve space for output
        std::string arr;
        arr.reserve(input.size());

        //get letter @ offset loc -> append to array
        for(char c: input){
            size_t index = refDict.find(c);

            //char not in refDict
            if(index == std::string::npos){
                std::cerr << "Input string contains character not found in refDict\n";
                return "";
            }

            //branch point
            if(ver.compare("encrypt") == 0){
                size_t newIndex = (index + offset) % refDict.size();
                arr += refDict[newIndex];
            }else if(ver.compare("decrypt") == 0){
                size_t newIndex = (index - offset + refDict.size()) % refDict.size();
                arr += refDict[newIndex];
            }else{
                std::cerr << "Accepted options are `encrypt` and `decrypt`\n";
                return "";
            }
        }

        return arr;
    }

    //shift by set amount (wrapper)
    std::string encrypt1(
        std::string input,
        std::string& refDict,
        int offset=6
    ){
        return cryptLogic("encrypt",input,refDict,offset);
    }

    //shift by set amount (wrapper)
    std::string decrypt1(
        std::string input,
        std::string& refDict,
        int offset=6
    ){
        return cryptLogic("decrypt",input,refDict,offset);
    }

    //shift by length of string (wrapper)
    std::string encrypt2(
        std::string input,
        std::string& refDict
    ){
        int offset = input.length();
        return cryptLogic("encrypt",input,refDict,offset);
    }

    //shift by length of string (wrapper)
    std::string decrypt2(
        std::string input,
        std::string& refDict
    ){
        int offset = input.length();
        return cryptLogic("decrypt",input,refDict,offset);
    }
};

/*
    DEPRECIATED
    returns error message if input string contains notFound char
*/
std::string replaceError(
    std::string cryptStr,
    std::string errorMsg,
    char notFound
){
    size_t indexO = cryptStr.find(notFound);

    //check if notFound char present in cryptStr
    if(indexO != std::string::npos){
        std::cerr << errorMsg << "\n";
        return "";
    }else{
        return cryptStr;
    }
}