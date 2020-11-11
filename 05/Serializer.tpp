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
    process(t);
    process(args...);
}

template <typename... ArgsT>
void Serializer::process(uint64_t t, ArgsT... args){
    process(t);
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
    Error err = process(t);
    if (err != Error::NoError)
        return err;
    return process(args...);
}

template <typename... ArgsT>
Error Deserializer::process(uint64_t& t, ArgsT&... args){
    Error err = process(t);
    if (err != Error::NoError)
        return err;
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
    if (!(this->in_>>x))
        return Error::CorruptedArchive;
    try{
        t = stoull(x);
    } catch(...){
        return Error::CorruptedArchive;
    }
    return Error::NoError;
}
