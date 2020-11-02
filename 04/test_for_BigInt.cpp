#include "BigInt_class.h"

int main(){
    //test1
    BigInt X("-123");
    if (X == -123)
        std::cout<<"OK 1"<<std::endl;
    else
        std::cout<<"Wrong 1"<<std::endl;
    //test2
    int z = 9;
    BigInt Y(567);
    BigInt P(Y);
    BigInt Z = z;
    if (P == Y && Z == z)
        std::cout<<"OK 2"<<std::endl;
    else
        std::cout<<"Wrong 2"<<std::endl;
    //test3
    Y = z;
    if (Z == Y)
        std::cout<<"OK 3"<<std::endl;
    else
        std::cout<<"Wrong 3"<<std::endl;
    //test4
    BigInt W = -555;
    BigInt V = W;
    BigInt R("0");
    R = Y;
    if (R == Y && V == W)
        std::cout<<"OK 4"<<std::endl;
    else
        std::cout<<"Wrong 4"<<std::endl;
    //test5
    BigInt F = std::move(BigInt(30));
    BigInt G("0");
    G = std::move(BigInt(40));
    if (G == 40 && F == (G - 10))
        std::cout<<"OK 5"<<std::endl;
    else
        std::cout<<"Wrong 5"<<std::endl;
    //test6
    if ((P > Y) && (-Y == -9) && (Y + G == 49) && ((-P - G) == -607) && (Y * G == 360) && ((Y * W - F + P) == -4458))
        std::cout<<"OK 6"<<std::endl;
    else
        std::cout<<"Wrong 6"<<std::endl;
    //test7
    BigInt a = 1;
    BigInt b("123456789012345678901234567890");
    BigInt c = a * b + 2;
    BigInt d;
    d = std::move(c);
    a = d + b;
    if (a == BigInt("246913578024691357802469135782"))
        std::cout<<"OK 7"<<std::endl;
    else
        std::cout<<"Wrong 7"<<std::endl;

    return 0;
}
