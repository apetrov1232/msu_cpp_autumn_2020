#include "task_2.h"

void TokenParser::StartParse(string in, string out){
    this->file.open(in);
    this->ans.open(out);
    this->ans<<this->start_func()<<endl;
};

bool TokenParser::Parse(){
    string next = "";
    this->file>>next;
    if (!this->ans.is_open()){
        //парсинг уже ранее закончился
        return false;
    }

    bool isnumber = 1;
    for (long long unsigned int i=0; i<size(next); i++){
        if (!isdigit(next[i])){
            isnumber = 0;
            break;
        }
    }
    if (size(next)!=0){
        if (isnumber){
            this->ans<<this->digit_func(next)<<endl;
        }
        else{
            this->ans<<this->string_func(next)<<endl;
        }
    };

    if (file.eof()){
        //токены кончились
        this->ans<<this->final_func()<<endl;
        this->ans.close();
        this->file.close();
        return false;
    };
    return true;
};

void TokenParser::SetStartCallback(string (*f)()){
    this->start_func = f;
};

void TokenParser::SetFinalCallback(string (*f)()){
    this->final_func = f;
};

void TokenParser::SetDigitTokenCallback(string (*f)(string)){
    this->digit_func = f;
};

void TokenParser::SetStringTokenCallback(string (*f)(string)){
    this->string_func = f;
};

