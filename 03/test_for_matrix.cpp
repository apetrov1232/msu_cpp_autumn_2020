#include "matrix_class.h"
#include <fstream>
int main(){
    //test1
    Matrix m(10, 5);
    if (m.getRows()== 10 && m.getColumns()==5)
        cout<<"OK 1"<<endl;
    else
        cout<<"Wrong 1"<<endl;
    //test2
    m[0][0] = 3;
    m[0][1] = 2;
    m*=5;
    if (m[0][0]==15 && m[0][1]==10)
        cout<<"OK 2"<<endl;
    else
        cout<<"Wrong 2"<<endl;
    //test3
    Matrix m2(10, 5);
    if (m2 != m)
        cout<<"OK 3"<<endl;
    else
        cout<<"Wrong 3"<<endl;
    //test4
    m2[0][0] = 15; m2[0][1] = 10;
    if (m2==m)
        cout<<"OK 4"<<endl;
    else
        cout<<"Wrong 4"<<endl;
    //test5
    bool err = 0;
    try{
        m[0][-1] = 3;
    }
    catch(...){
        err = 1;
    }
    if (err)
        cout<<"OK 5"<<endl;
    else
        cout<<"Wrong 5"<<endl;
    //test6
    Matrix M = m + m2;
    m*=2;
    if (M==m)
        cout<<"OK 6"<<endl;
    else
        cout<<"Wrong 6"<<endl;
    //test7
    ofstream fout;
    fout.open("test_matrix_in_stream.txt");
    fout<<M;
    fout.close();
    ifstream fin;
    fin.open("test_matrix_in_stream.txt");
    char c[70];
    string s;
    while(fin.getline(c, 70))
        s += string(c) + "/n";
    fin.close();
    if (s=="30 20 0 0 0 /n0 0 0 0 0 /n0 0 0 0 0 /n0 0 0 0 0 /n0 0 0 0 0 /n0 0 0 0 0 /n0 0 0 0 0 /n0 0 0 0 0 /n0 0 0 0 0 /n0 0 0 0 0 /n")
        cout<<"OK 7"<<endl;
    else
        cout<<"Wrong 7"<<endl;
    //test8
    Matrix m3 = Matrix(4,3);
    if (m3 != M)
        cout<<"OK 8"<<endl;
    else
        cout<<"Wrong 8"<<endl;
    //test9
    err = 0;
    try{
        m3+M;
    }
    catch(...){
        err = 1;
    }
    if (err)
        cout<<"OK 9"<<endl;
    else
        cout<<"Wrong 9"<<endl;

    return 0;
}
