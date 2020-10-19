#include "parser.h"

void TokenParser::StartParse(const string &in, const string &out){
    this->file.open(in);
    this->ans.open(out);
    this->ans<<this->start_func()<<endl;
};

bool TokenParser::Parse(){
    string next = "";
    this->file>>next;
    if (!this->ans.is_open()){
        //parsing already end
        return false;
    }

    bool isnumber = 1;
    for (long long unsigned int i=0; i<next.size(); i++){
        if (!isdigit(next[i])){
            isnumber = 0;
            break;
        }
    }
    if (next.size()!=0){
        if (isnumber){
            this->ans<<this->digit_func(next)<<endl;
        }
        else{
            this->ans<<this->string_func(next)<<endl;
        }
    };

    if (file.eof()){
        //all tokens are obtained
        this->ans<<this->final_func()<<endl;
        this->ans.close();
        this->file.close();
        return false;
    };
    return true;
};

void TokenParser::SetStartCallback(const function <string ()> &f){
    this->start_func = f;
};

void TokenParser::SetFinalCallback(const function <string ()> &f){
    this->final_func = f;
};

void TokenParser::SetDigitTokenCallback(const function <string (const string&)> &f){
    this->digit_func = f;
};

void TokenParser::SetStringTokenCallback(const function <string (const string&)> &f){
    this->string_func = f;
};

