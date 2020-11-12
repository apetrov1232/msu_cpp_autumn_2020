#pragma once
#include <sstream>
#include <iostream>

enum class Error{
    NoError,
    CorruptedArchive
};

bool isDigit(const std::string& x);

class Serializer{
    static constexpr char sep = ' ';

    public:

        explicit Serializer(std::ostream& out):out_(out){};

        template <typename T>
        void save(T& object);

        template <typename... ArgsT>
        void operator()(ArgsT... args);

    private:

        std::ostream& out_ = std::cout;

        template <typename... ArgsT>
        void process(bool t, ArgsT... args);

        template <typename... ArgsT>
        void process(uint64_t t, ArgsT... args);

        void process(bool t);

        void process(uint64_t t);
};

class Deserializer{
    public:

        explicit Deserializer(std::istream& in):in_(in){};

        template <typename T>
        Error load(T& object);

        template <typename... ArgsT>
        Error operator()(ArgsT&... args);

    private:

        std::istream& in_ = std::cin;

        template <typename... ArgsT>
        Error process(bool& t, ArgsT&... args);

        template <typename... ArgsT>
        Error process(uint64_t& t, ArgsT&... args);

        Error process(bool& t);

        Error process(uint64_t& t);
};

#include "Serializer.tpp"
