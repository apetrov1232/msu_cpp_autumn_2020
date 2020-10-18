#pragma once
#include <iostream>
#include <fstream>
#include <cctype>
#include <functional>
using namespace std;

class TokenParser
{
    private:
        function <string ()> start_func;
        function <string ()> final_func;
        function <string (string&)> digit_func;
        function <string (string&)> string_func;
        ifstream file;
        ofstream ans;

    public:
        void StartParse(string &in, string &out);
        bool Parse();
        void SetStartCallback(const function <string ()> f);
        void SetFinalCallback(const function <string ()> f);
        void SetDigitTokenCallback(const function <string (string&)> f);
        void SetStringTokenCallback(const function <string (string&)> f);
        ~TokenParser(){
            if (file.is_open())
                file.close();
            if (ans.is_open())
                ans.close();
        };
};
