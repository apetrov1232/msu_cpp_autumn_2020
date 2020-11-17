#include "format.hpp"

int main(){
    //test1
    auto text = format("{1}+{1} = {0}", 2, "one");
    if (text == "one+one = 2")
        std::cout<<"OK 1"<<std::endl;
    else
        std::cout<<"Wrong 1"<<std::endl;
    //test2
    bool iserr = false;
    try{
        text = format("{1}+{1} = {2}", 2, "one");
    }
    catch(const WrongValueInBrackets& err){
        iserr = true;
        std::cout<<"OK 2"<<std::endl;
    }
    catch(...){
        iserr = true;
        std::cout<<"Wrong 2"<<std::endl;
    }
    if (!iserr)
        std::cout<<"Wrong 2"<<std::endl;
    //test3
    iserr = false;
    try{
        text = format("}}{0}", "argument");
    }
    catch(const IncorrectUsingBrackets& err){
        iserr = true;
        std::cout<<"OK 3"<<std::endl;
    }
    catch(...){
        iserr = true;
        std::cout<<"Wrong 3"<<std::endl;
    }
    if (!iserr)
        std::cout<<"Wrong 3"<<std::endl;
    //test4
    text = format("{0}{1}={2}!={3}", 0, "!", '1', "1");
    if (text == "0!=1!=1")
        std::cout<<"OK 4"<<std::endl;
    else
        std::cout<<"Wrong 4"<<std::endl;
    //test5
    text = format("{10}{11}",0,1,2,3,4,5,6,7,8,9,"ABC", 2*3);
    if (text == "ABC6")
        std::cout<<"OK 5"<<std::endl;
    else
        std::cout<<"Wrong 5"<<std::endl;
    return 0;
}
