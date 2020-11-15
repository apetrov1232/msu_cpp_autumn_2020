#pragma once
#include <iostream>
#include <sstream>

class ErrorFormat: public std::exception
{
public:
    const char* what() const noexcept{
        return "Error with function Format";
    }
};

class IncorrectUsingBrackets: public ErrorFormat
{
public:
    const char* what() const noexcept{
        return "{} is used incorrect";
    }
};

class WrongValueInBrackets: public ErrorFormat
{
public:
    const char* what() const noexcept{
        return "Value don't fit to {}";
    }
};

template <typename T>
std::string process(const std::string& s, const int i, const T& t);

template <typename T, typename... ArgsT>
std::string process(const std::string& s, const int i, const T& t, const ArgsT&... args);

template <typename... ArgsT>
std::string format(const std::string& s, const ArgsT&... args);

#include "format.tpp"
