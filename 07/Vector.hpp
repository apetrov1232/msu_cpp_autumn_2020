#pragma once
#include <iostream>

template <typename T>
class Allocator{

public:
    T* allocate(size_t cnt);

    void deallocate(T* ptr);
};



template <typename T>
class VectorIterator{

    T* current_;
    bool isReserved;

public:

    VectorIterator(T*& begin, const size_t Size, const bool r, const bool isBeg)
        : isReserved(r){
            T* begin_ = begin;
            T* end_ = begin_;
            for (size_t i(0); i<Size; i++)
                end_++;
            if (r){
                std::swap(begin_, end_);
                begin_--;
                end_--;
            }
            if (isBeg)
                current_ = begin_;
            else
                current_ = end_;
        };

    T operator*() const;

    void operator++();

    bool operator==(const VectorIterator& other) const;

    bool operator!=(const VectorIterator& other) const;
};



template<typename T, typename Alloc = Allocator<T>>
class Vector{

    T* data;
    size_t Size;
    size_t Capacity;
    Alloc alc;

    void transportdata();

public:

    Vector(const size_t cnt = 0){
        Size = cnt;
        Capacity = cnt;
        data = alc.allocate(cnt);
    };

    ~Vector(){
        alc.deallocate(data);
    };

    T& operator[](const size_t i);

    void push_back(const T x);

    void pop_back();

    template<typename... ArgsT>
    void emplace_back(const ArgsT&... args);

    bool empty();

    size_t size();

    size_t capacity();

    void clear();

    VectorIterator<T> begin() noexcept;

    VectorIterator<T> rbegin() noexcept;

    VectorIterator<T> end() noexcept;

    VectorIterator<T> rend() noexcept;

    void resize(const size_t cnt);

    void reserve(const size_t cnt);
};

#include "Vector.tpp"
