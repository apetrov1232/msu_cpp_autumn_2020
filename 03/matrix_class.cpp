#include "matrix_class.h"

int Row::getRowSize() const{
    return length;
}

void Row::setLength(const int n){
    x = new int[n];
    //default matrix elements is zero
    for (int i = 0; i < n; i++)
        x[i] = 0;
    length = n;
};

int& Row::operator[](const int i){
    if ((i >= length) || (i < 0)){
        throw out_of_range("");
    }
    return x[i];
};



Row& Matrix::operator[](const int i){
    if ((i >= high) || (i < 0)){
        throw out_of_range("");
    }
    return rows[i];
};

void Matrix::operator*=(const int k){
    for (int i = 0; i < getRows(); i++)
        for (int j = 0; j < getColumns(); j++)
            rows[i][j]*=k;
};

bool Matrix::operator==(const Matrix& m){
    if (getRows() != m.getRows() || getColumns()!=m.getColumns())
        return false;
    for (int i = 0; i < getRows(); i++)
        for (int j = 0; j < getColumns(); j++)
            if (rows[i][j] != m.rows[i][j])
                return false;
    return true;
};

bool Matrix::operator!=(const Matrix& m){
    return !(*this == m);
};

Matrix Matrix::operator+(const Matrix& m){
    if (getRows() != m.getRows() || getColumns()!=m.getColumns())
        throw out_of_range(""); //incorrect case
    Matrix tmp(m.getRows(),m.getColumns());
    for (int i = 0; i < m.getRows(); i++)
        for (int j = 0; j < m.getColumns(); j++)
            tmp[i][j] = rows[i][j] + m.rows[i][j];
    return tmp;
};

int Matrix::getRows() const{
    return high;
};

int Matrix::getColumns() const{
    return (this->rows[0]).getRowSize();
};

ostream& operator<<(ostream& ostream, const Matrix& m){
    for (int i = 0; i < m.getRows(); i++){
        for (int j = 0; j < m.getColumns(); j++)
            ostream<<m.rows[i][j]<<" ";
        ostream<<endl;
    }
    return ostream;
}
