#include <string>
#include <vector>

//backend logic for encrypting input string
std::string encryptLogic(
    std::string input,
    std::string refDict,
    int offset=6,
    char notFound='|'
){
    std::vector<char> arr = {};

    //get letter @ offset loc -> append to array
    for(char c: input){
        size_t index = refDict.find(c);

        if(index != std::string::npos){
            int shiftPos = index + offset;

            //loop to beginning if overflow
            if(shiftPos >= refDict.length()){
                int loopOffset = (shiftPos-refDict.length());
                arr.push_back(refDict.at(loopOffset));
            }else{
                arr.push_back(refDict.at(shiftPos));
            }
        }else{
            //use placeholder for anything not found in refDict
            arr.push_back(notFound);
        }
    }

    std::string cryptStr(arr.begin(),arr.end());
    return cryptStr;
}

//replace error
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

//shift by set amount (wrapper)
std::string encrypt1(
    std::string input,
    std::string refDict,
    int offset=6,
    std::string errorMsg="Error",
    char notFound='|'
){
    return replaceError(
        encryptLogic(input,refDict,offset,notFound)
    );
}

//shift by length of string (wrapper)
std::string encrypt2(
    std::string input,
    std::string refDict,
    std::string errorMsg="Error",
    char notFound='|'
){
    int offset = input.length();
    return replaceError(
        encryptLogic(input,refDict,offset,notFound)
    );
}