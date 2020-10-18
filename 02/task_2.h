#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

class TokenParser
{
    private:
        string (*start_func)();
        string (*final_func)();
        string (*digit_func)(string);
        string (*string_func)(string);
        ifstream file;
        ofstream ans;

    public:
        void StartParse(string in, string out);
        bool Parse();
        void SetStartCallback(string (*f)());
        void SetFinalCallback(string (*f)());
        void SetDigitTokenCallback(string (*f)(string));
        void SetStringTokenCallback(string (*f)(string));
        ~TokenParser(){
            if (file.is_open())
                file.close();
            if (ans.is_open())
                ans.close();
        };
};
