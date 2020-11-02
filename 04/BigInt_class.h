#pragma once
#include <iostream>

class BigInt{

private:

    char* val = nullptr;

    int size_ = 0;

    bool positive = true;

public:

    BigInt(){};

    BigInt(const std::string& s){
        std::string line = s;
        if (s[0] == '-'){
            positive = false;
            line = std::string(s.c_str() + 1);
        }
        size_ = line.size();
        val = new char[size_];
        for (size_t i = 0; i < line.size(); i++)
            val[line.size()-1-i] = line[i];
    }

    BigInt(const int& x){
        int z = 1;
        if (x < 0){
            positive = false;
            z = -1;
        }
        if (x == 0){
            val = new char[1];
            val[0] = '0';
            size_ = 1;
            return;
        }
        int tmp = z*x;
        int len = 0;
        while(tmp != 0){
            tmp /= 10;
            len += 1;
        }

        size_ = len;
        val = new char[len];
        tmp = z*x;
        len = 0;
        while(tmp != 0){
            val[len] = tmp%10+ '0';
            tmp /= 10;
            len += 1;
        }
    }

    BigInt(const BigInt& copied){
        val = new char[copied.size_];
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

    BigInt& operator=(const int& x);

    BigInt& operator=(const BigInt& copied);

    BigInt& operator=(BigInt&& moved);

    bool operator == (const BigInt& other) const;

    bool operator != (const BigInt& other) const;

    bool operator > (const BigInt& other) const;

    bool operator >= (const BigInt& other) const;

    bool operator < (const BigInt& other) const;

    bool operator <= (const BigInt& other) const;

    bool operator == (const int& x) const;

    bool operator != (const int& x) const;

    bool operator > (const int& x) const;

    bool operator >= (const int& x) const;

    bool operator < (const int& x) const;

    bool operator <= (const int& x) const;

    BigInt operator+(const BigInt& other);

    BigInt operator+(const int& x);

    BigInt operator-(const BigInt& other);

    BigInt operator-(const int& x);

    BigInt operator*(const BigInt& other);

    BigInt operator*(const int& x);

    friend std::ostream& operator<<(std::ostream& ostream, const BigInt& x);

    friend BigInt operator-(const BigInt& x);
};
