#pragma once
#include <iostream>

class BigInt{

private:

    int* val = nullptr;

    int size_ = 0;

    bool positive = true;

public:

    BigInt(){};

    BigInt(const std::string& s){
        if (s[0] == '-'){
            positive = false;
            size_ = s.size() - 1;
            val = new int[size_];
            for (int i = 0; i < size_; i++)
                val[size_-1-i] = (s[i + 1] - '0');
        }
        else{
            positive = true;
            size_ = s.size();
            val = new int[size_];
            for (int i = 0; i < size_; i++)
                val[size_-1-i] = (s[i] - '0');
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
        while(tmp != 0){
            tmp /= 10;
            len += 1;
        }

        size_ = len;
        val = new int[len];
        tmp = z*x;
        len = 0;
        while(tmp != 0){
            val[len] = tmp%10;
            tmp /= 10;
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
