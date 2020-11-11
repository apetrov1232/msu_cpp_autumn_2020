bool isDigit(const std::string& x){
    for(size_t i = 0; i < x.size(); i++)
        if (!(isdigit(x[i])))
            return false;
    return true;
}

template <typename T>
void Serializer::save(T& object){
    object.serialize(*this);
}

template <typename... ArgsT>
void Serializer::operator()(ArgsT... args){
    process(args...);
}

template <typename... ArgsT>
void Serializer::process(bool t, ArgsT... args){
    if (t == true)
        this->out_<<sep<<"true";
    else
        this->out_<<sep<<"false";
    process(args...);
}

template <typename... ArgsT>
void Serializer::process(uint64_t t, ArgsT... args){
    this->out_<<sep<<std::to_string(t);
    process(args...);
}

void Serializer::process(bool t){
    if (t == true)
        this->out_<<sep<<"true";
    else
        this->out_<<sep<<"false";
}

void Serializer::process(uint64_t t){
    this->out_<<sep<<std::to_string(t);
}

template <typename T>
Error Deserializer::load(T& object){
    return object.deserialize(*this);
}

template <typename... ArgsT>
Error Deserializer::operator()(ArgsT&... args){
    return process(args...);
}


template <typename... ArgsT>
Error Deserializer::process(bool& t, ArgsT&... args){
    std::string x;
    if (!(this->in_>>x))
        return Error::CorruptedArchive;
    if ((x == "true") || (x == "false"))
        t = (x == "true");
    else
        return Error::CorruptedArchive;
    return process(args...);
}

template <typename... ArgsT>
Error Deserializer::process(uint64_t& t, ArgsT&... args){
    std::string x;
    if (!(this->in_>>x))
        return Error::CorruptedArchive;
    if (isDigit(x.c_str()))
        t = stoull(x);
    else
        return Error::CorruptedArchive;
    return process(args...);
}

Error Deserializer::process(bool& t){
    std::string x;
    if (!(this->in_>>x))
        return Error::CorruptedArchive;
    if ((x == "true") || (x == "false"))
        t = (x == "true");
    else
        return Error::CorruptedArchive;
    return Error::NoError;
}

Error Deserializer::process(uint64_t& t){
    std::string x;
    std::string sep;
    if (!(this->in_>>x))
        return Error::CorruptedArchive;
    if (isDigit(x.c_str()))
        t = stoull(x);
    else
        return Error::CorruptedArchive;
    return Error::NoError;
}
