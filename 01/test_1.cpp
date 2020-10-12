#include <iostream>
#include "task_1.cpp"
using namespace std;

int main(){

    //test1
    Allocator X;
    X.makeAllocator(10);
    if (X.alloc(11)==nullptr)
        cout<<"OK 1"<<endl;
    else
        cout<<"Wrong 1"<<endl;

    //test2
    X.makeAllocator(1);
    X.alloc(1);
    X.reset();
    if (X.alloc(1)==nullptr)
        cout<<"Wrong 2"<<endl;
    else if (X.alloc(1)==nullptr)
        cout<<"OK 2"<<endl;
    else
        cout<<"Wrong 2"<<endl;

    //test3
    X.makeAllocator(1000);
    X.alloc(5);
    X.alloc(994);
    char* y1 = X.alloc(1);
    if (y1 == nullptr)
        cout<<"Wrong 3"<<endl;
    y1[0] = 'x';
    X.reset();
    char* y2 = X.alloc(1000);
    if (y2[999]!='x')
        cout<<"Wrong 3"<<endl;
    else
        cout<<"OK 3"<<endl;

    return 0;
}
