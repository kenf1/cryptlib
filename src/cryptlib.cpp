#include <string>
#include <vector>
#include <iostream>

//backend logic for encrypting input string, case sensitive
std::string cryptLogic(
    std::string ver, //accepted values: encrypt, decrypt
    std::string input,
    std::string& refDict,
    int offset=6
){
    std::vector<char> arr = {};

    //get letter @ offset loc -> append to array
    for(char c: input){
        size_t index = refDict.find(c);

        if(index != std::string::npos){
            //encrypt
            if(ver == "encrypt"){
                int shiftPos = index + offset;

                //loop to beginning if overflow
                if(shiftPos >= refDict.length()){
                    int loopOffset = (shiftPos-refDict.length());
                    arr.push_back(refDict.at(loopOffset));
                }else{
                    arr.push_back(refDict.at(shiftPos));
                }
            }

            //decrypt
            if(ver == "decrypt"){
                int shiftPos = index - offset;

                //loop from end when overflow
                if(shiftPos < 0){
                    int loopOffset = (refDict.length()-abs(shiftPos));
                    arr.push_back(refDict.at(loopOffset));
                }else{
                    arr.push_back(refDict.at(shiftPos));
                }
            }

        //char not in refDict
        }else{
            std::cerr << "Input string contains character not found in refDict" << std::endl;
            return "Error";
        }
    }

    std::string cryptStr(arr.begin(),arr.end());
    return cryptStr;
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

/*
    DEPRECIATED
    returns error message if input string contains notFound char
*/
std::string replaceError(
    std::string cryptStr,
    std::string errorMsg="Error",
    char notFound='|'
){
    size_t indexO = cryptStr.find(notFound);
    if(indexO != std::string::npos){
        return errorMsg;
    }else{
        return cryptStr;
    }
}