#include "parser.h"

string my_start_func(){
    return "Start!";
}

string my_final_func(){
    return "Final!";
}

string my_digit_func(string &next){
    return next + " is digit";
}

string my_string_func(string &next){
    return next + " is string";
}

string my_newstart_func(){
    return "NewStart!";
}

int main(){
    TokenParser Parser;

    Parser.SetStartCallback(my_start_func);
    Parser.SetFinalCallback(my_final_func);
    Parser.SetDigitTokenCallback(my_digit_func);
    Parser.SetStringTokenCallback(my_string_func);

    string in="test2_1.txt", out="ans2_1.txt";
    Parser.StartParse(in, out);
    while(Parser.Parse());

    string c="", s="";
    ifstream check;
    check.open("ans2_1.txt");
    while(check>>c){
        s+=c+" ";
    }
    if (s=="Start! 123456 is digit abcdef is string Final! ")
        cout<<"OK 1"<<endl;
    else
        cout<<"Wrong 1"<<endl;
    s="";
    check.close();

    in="test2_2.txt", out="ans2_2.txt";
    Parser.StartParse(in, out);
    while(Parser.Parse());

    check.open("ans2_2.txt");
    while(check>>c){
        s+=c+" ";
    }
    if (s=="Start! 123kkfmdks123 is string a is string 123123 is digit 123123234 is digit 1a is string Final! ")
        cout<<"OK 2"<<endl;
    else
        cout<<"Wrong 2"<<endl;
    s="";
    check.close();

    in="test2_3.txt", out="ans2_3.txt";
    Parser.SetStartCallback(my_newstart_func);
    Parser.StartParse(in, out);
    while(Parser.Parse());

    check.open("ans2_3.txt");
    while(check>>c){
        s+=c+" ";
    }
    if (s=="NewStart! Final! ")
        cout<<"OK 3"<<endl;
    else
        cout<<"Wrong 3"<<endl;
    s="";
    check.close();

    return 0;
}
