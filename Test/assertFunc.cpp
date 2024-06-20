#include <iostream>
#include <string>

/*
    create own assert function
    Output: print Pass or Fail
*/
void assertPF(
    std::string testName,
    std::string inputStr,
    std::string expectedStr
){
    std::cout << testName << ": ";
    if(inputStr == expectedStr){
        std::cout << "Pass" << std::endl;
    }else{
        std::cout << "Fail" << std::endl;
    }
}