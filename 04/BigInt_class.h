#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

const int C = 5;

class BigInt{

private:

    int* val = nullptr; // value = val[0] + val[1] * 10^C + val[1] * 10^(2*C) + ...

    int size_ = 0;

    bool positive = true;

public:

    BigInt(){};

    BigInt(const std::string& s){
        int tmp;
        if (s[0] == '-'){
            positive = false;
            size_ = (s.size() - 1) / C;
            if (((s.size() - 1) % C) != 0)
                size_ += 1;
            val = new int[size_];
            for (int i = 0; i < size_; i++){
                tmp = 0;
                for (size_t j = 0; ((j < C) && (i*C + j < s.size() - 1)); j++){
                    tmp = tmp + (s[s.size() -1 - i*C - j] - '0') * int(pow(10, j));
                }
                val[i] = tmp;
            }
        }
        else{
            positive = true;
            size_ = s.size() / C;
            if ((s.size() % C) != 0)
                size_ += 1;
            val = new int[size_];
            for (int i = 0; i < size_; i++){
                tmp = 0;
                for (size_t j = 0; ((j < C) && (i*C + j < s.size())); j++){
                    tmp = tmp + (s[s.size() -1 - i*C - j] - '0') * int(pow(10, j));
                }
                val[i] = tmp;
            }
        }
    }

    BigInt(const int x){
        int z = 1;
        if (x < 0){
            positive = false;
            z = -1;
        }
        if (x == 0){
            val = new int[1];
            val[0] = 0;
            size_ = 1;
            return;
        }
        int tmp = z*x;
        int len = 0;
        while(tmp!= 0){
            tmp /= int(pow(10, C));
            len += 1;
        }
        size_ = len;
        val = new int[len];
        tmp = z*x;
        len = 0;
        while(tmp != 0){
            val[len] = tmp % int(pow(10, C));
            tmp /= int(pow(10, C));
            len += 1;
        }
    }

    BigInt(const BigInt& copied){
        val = new int[copied.size_];
        std::copy(copied.val, copied.val + copied.size_, val);
        size_ = copied.size_;
        positive = copied.positive;
    }

    BigInt(BigInt&& moved){
        val = moved.val;
        size_ = moved.size_;
        positive = moved.positive;
        moved.val = nullptr;
    }

    ~BigInt(){
        if (val != nullptr)
            delete[] val;
        size_ = -1;
    }

    BigInt& operator=(const int x);

    BigInt& operator=(const BigInt& copied);

    BigInt& operator=(BigInt&& moved);

    bool operator == (const BigInt& other) const;

    bool operator != (const BigInt& other) const;

    bool operator > (const BigInt& other) const;

    bool operator >= (const BigInt& other) const;

    bool operator < (const BigInt& other) const;

    bool operator <= (const BigInt& other) const;

    bool operator == (const int x) const;

    bool operator != (const int x) const;

    bool operator > (const int x) const;

    bool operator >= (const int x) const;

    bool operator < (const int x) const;

    bool operator <= (const int x) const;

    BigInt operator+(const BigInt& other);

    BigInt operator+(const int x);

    BigInt operator-(const BigInt& other);

    BigInt operator-(const int x);

    BigInt operator*(const BigInt& other);

    BigInt operator*(const int x);

    friend std::ostream& operator<<(std::ostream& ostream, const BigInt& x);

    friend BigInt operator-(const BigInt& x);
};
