#pragma once
#include <iostream>
using namespace std;

class Row{

private:

    int* x = nullptr;
    int length = 0;

public:

    ~Row(){
        if (x != nullptr)
            delete[] x;
    };

    int getRowSize() const;

    void setLength(const int n);

    int& operator[](const int i);

};

class Matrix{

private:

    Row* rows = nullptr;
    int high = 0;

public:

    Matrix(const int n, const int l){
        rows = new Row[n];
        for (int i = 0; i < n; i++)
            rows[i].setLength(l);
        high = n;
    };

    ~Matrix(){
        if (rows != nullptr)
            delete[] rows;
    };

    Row& operator[](const int i);

    Matrix& operator *= (const int k);

    bool operator == (const Matrix& m) const;

    bool operator != (const Matrix& m) const;

    Matrix operator + (const Matrix& m);

    friend ostream& operator<<(ostream& ostream, const Matrix& m);

    int getRows() const;

    int getColumns() const;

};
