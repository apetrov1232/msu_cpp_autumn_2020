template <typename T>
std::string process(const std::string& s, const int i, const T& t){
    std::string ans = "";
    std::string tmp = "";
    std::stringstream stream;
    int val;
    for (size_t j = 0; j < s.size(); j++){
        if (s[j] == '}')
            throw IncorrectUsingBrackets();
        if (s[j] != '{')
            ans += s[j];
        else{
            j++;
            if (j >= s.size())
                throw IncorrectUsingBrackets();
            val = 0;
            tmp = "";
            while (s[j] != '}'){
                tmp += s[j];
                if (isdigit(s[j]))
                    val += (s[j] - '0');
                else
                    throw WrongValueInBrackets();
                j++;
                if (j >= s.size())
                    throw IncorrectUsingBrackets();
            }
            if (val == i){
                stream.str(std::string());
                stream.clear();
                stream<<t;
                stream>>tmp;
                ans += tmp;
            }
            else
                ans += "{"+tmp+"}";
        }
    }
    return ans;
}

template <typename T, typename... ArgsT>
std::string process(const std::string& s, const int i, const T& t, const ArgsT&... args){
    std::string s_new = process(s, i, t);
    return process(s_new, i+1, args...);
}

template <typename... ArgsT>
std::string format(const std::string& s, const ArgsT&... args){
    std::string ans = process(s,0,args...);
    for (size_t j = 0; j < ans.size(); j++){
        if ((ans[j] == '}') || (ans[j] == '{'))
            throw WrongValueInBrackets();
    }
    return ans;
}
