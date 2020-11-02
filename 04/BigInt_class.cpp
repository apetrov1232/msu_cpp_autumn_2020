#include "BigInt_class.h"


BigInt& BigInt::operator=(const int& x){
    delete[] val;
    BigInt X(x);
    val = X.val;
    size_ = X.size_;
    positive = X.positive;
    X.val = nullptr;
    return *this;
}

BigInt& BigInt::operator=(const BigInt& copied){
    if (this == &copied)
        return *this;
    delete[] val;
    val = new char[copied.size_];
    size_ = copied.size_;
    positive = copied.positive;
    std::copy(copied.val, copied.val + copied.size_, val);
    return *this;
}

BigInt& BigInt::operator=(BigInt&& moved){
    delete[] val;
    val = moved.val;
    size_ = moved.size_;
    positive = moved.positive;
    moved.val = nullptr;
    return *this;
}

bool BigInt::operator == (const BigInt& other) const{
    if ((other.size_ != size_) || (positive != other.positive))
        return false;
    for (int i = 0; i < size_; i++)
        if (val[i] != other.val[i])
            return false;
    return true;
};

bool BigInt::operator != (const BigInt& other) const{
    return !(*this == other);
};

bool BigInt::operator > (const BigInt& other) const{
    if (positive != other.positive)
        return positive;
    if (size_ != other.size_)
        return (size_ > other.size_)^(!positive);
    for (int i = size_-1; i >= 0; i--){
        if (val[i] < other.val[i])
            return false;
        if (val[i] > other.val[i])
            return true;
    }
    return false;
};

bool BigInt::operator >= (const BigInt& other) const{
    return ((*this > other) || (*this == other));
}

bool BigInt::operator < (const BigInt& other) const{
    return !(*this >= other);
}

bool BigInt::operator <= (const BigInt& other) const{
    return (!(*this >= other) || (*this == other));
}

bool BigInt::operator == (const int& x) const{
    BigInt other(x);
    if ((other.size_ != size_) || (positive != other.positive))
        return false;
    for (int i = 0; i < size_; i++)
        if (val[i] != other.val[i])
            return false;
    return true;
};

bool BigInt::operator != (const int& x) const{
    return !(*this == x);
};

bool BigInt::operator > (const int& x) const{
    BigInt other(x);
    if (positive != other.positive)
        return positive;
    if (size_ != other.size_)
        return ((size_ > other.size_)==(positive));
    for (int i = size_-1; i >= 0; i--){
        if (val[i] < other.val[i])
            return (false==positive);
        if (val[i] > other.val[i])
            return (true==positive);
    }
    return false;
};

bool BigInt::operator >= (const int& x) const{
    return ((*this > x) || (*this == x));
}

bool BigInt::operator < (const int& x) const{
    return !(*this >= x);
}

bool BigInt::operator <= (const int& x) const{
    return (!(*this >= x) || (*this == x));
}

BigInt BigInt::operator+(const BigInt& other){//O(max(n1,n2))
    BigInt X = BigInt();
    int res, tmp;
    if (positive == other.positive){
        X.positive = positive;
        X.size_ = std::max(size_, other.size_) + 1;
        X.val = new char[X.size_];
        res = 0;
        for (int i=0; i < std::min(size_, other.size_); i++){
            tmp = val[i] - '0' + other.val[i] - '0' + res;
            res = tmp / 10;
            X.val[i] = tmp % 10 + '0';
        }
        char * bigger;
        if (size_ > other.size_)
            bigger = val;
        else
            bigger = other.val;
        for (int i = std::min(size_, other.size_); i < std::max(size_, other.size_); i++){
            tmp = bigger[i] - '0' + res;
            res = tmp / 10;
            X.val[i] = tmp % 10 + '0';
        }
        if (res != 0)
            X.val[std::max(size_, other.size_)] = res;
        else{
            X.size_ = X.size_ - 1;
            char * nw = new char[X.size_];
            std::copy(X.val, X.val + X.size_, nw);
            delete[] X.val;
            X.val = nw;
        }
    }
    else{
        const BigInt* bigg;
        const BigInt* small;
        X.size_ = std::max(size_, other.size_);
        X.val = new char[X.size_];
        if (X > other && X > -other){
            bigg = this;
            small = &other;
        }
        else{
            bigg = &other;
            small = this;
        }
        X.positive = bigg->positive;
        res = 0;
        for (int i = 0; i < small->size_; i++){
            tmp = bigg->val[i] - '0' - (small->val[i] - '0') - res;
            if (tmp >= 0){
                X.val[i] = tmp + '0';
                res = 0;
            }
            else{
                tmp = -tmp;
                res = tmp/10 + (tmp%10 != 0);
                X.val[i] = 10 - tmp%10 + '0';
            }
        }
        for (int i = small->size_; i < bigg->size_; i++){
            tmp = bigg->val[i] - '0' - res;
            if (tmp >= 0){
                X.val[i] = tmp + '0';
                res = 0;
            }
            else{
                tmp = -tmp;
                res = tmp/10 + (tmp%10 != 0);
                X.val[i] = 10 - tmp%10 + '0';
            }
        }
        int cnt = 0;
        for (int i = bigg->size_ - 1; (X.val[i]=='0' && i>=0); i--)
            cnt++;
        if (cnt == X.size_)
            cnt--;
        X.size_ = X.size_ - cnt;
        char * nw = new char[X.size_];
        std::copy(X.val, X.val + X.size_, nw);
        delete[] X.val;
        X.val = nw;
    }
    return X;
}

BigInt BigInt::operator+(const int& x){
    return (*this + BigInt(x));
};

BigInt BigInt::operator-(const BigInt& other){
    return (*this + (-other));
}

BigInt BigInt::operator-(const int& x){
    return (*this - BigInt(x));
}

BigInt BigInt::operator*(const BigInt& other){ //O(n1*(n1+n2))=O(n^2)
    BigInt X = BigInt();
    X.size_ = other.size_ + size_;
    X.val = new char[X.size_];
    X.positive = (positive == other.positive);
    int res = 0, tmp, cnt;
    for (int i = 0; i < X.size_; i++)
        X.val[i] = '0';
    for (int i = 0; i < size_; i++){
        for (int j = 0; j < other.size_; j++){
            tmp = (X.val[i + j] - '0') + (val[i] - '0')*(other.val[j] - '0') + res;
            X.val[i+j] = tmp % 10 + '0';
            res = tmp / 10;
        }
        cnt = other.size_ + i;
        while(res != 0){
            tmp = (X.val[cnt] - '0') + res;
            X.val[cnt] = tmp % 10 + '0';
            res = tmp / 10;
            cnt += 1;
        }
    }
    cnt = 0;
    for (int i = X.size_ - 1; (X.val[i]=='0' && i>=0); i--)
        cnt++;
    if (cnt == X.size_)
        cnt--;
    X.size_ = X.size_ - cnt;
    char * nw = new char[X.size_];
    std::copy(X.val, X.val + X.size_, nw);
    delete[] X.val;
    X.val = nw;
    return X;
}

BigInt BigInt::operator*(const int& x){
    return (*this * BigInt(x));
}

std::ostream& operator<<(std::ostream& ostream, const BigInt& x){
    if (!x.positive)
        ostream<<'-';
    for (int i = x.size_ - 1; i >=0; i--)
        ostream<<x.val[i];
    return ostream;
};

BigInt operator-(const BigInt& x){
    BigInt X(x);
    X.positive = !(X.positive);
    return X;
};
