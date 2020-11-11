#include "Serializer.hpp"

struct Data01{
    uint64_t a;
    bool b1;
    bool b2;
    bool b3;
    template <typename Serializer>
    void serialize(Serializer& serializer){
        serializer(a, b1, b2, b3);
    }

    template <typename Deserializer>
    Error deserialize(Deserializer& deserializer){
        return deserializer(a, b1, b2, b3);
    }
};

struct Data02{
    uint64_t a;
    template <typename Serializer>
    void serialize(Serializer& serializer){
        serializer(a);
    }

    template <typename Deserializer>
    Error deserialize(Deserializer& deserializer){
        return deserializer(a);
    }
};

struct Data1{
    uint64_t a;
    bool b;
    uint64_t c;

    template <typename Serializer>
    void serialize(Serializer& serializer){
        serializer(a, b, c);
    }

    template <typename Deserializer>
    Error deserialize(Deserializer& deserializer){
        return deserializer(a, b, c);
    }
};

struct Data2{
    uint64_t a;
    bool b1;
    bool b2;
    bool b3;
    uint64_t c;

    template <typename Serializer>
    void serialize(Serializer& serializer){
        serializer(a, b1, b2, b3, c);
    }

    template <typename Deserializer>
    Error deserialize(Deserializer& deserializer){
        return deserializer(a, b1, b2, b3, c);
    }
};

int main(){
    std::string c;
    std::stringstream stream;
    Serializer serializer1(stream);
    Deserializer deserializer1(stream);

    //test1
    Data1 x{1, true, 2};
    serializer1.save(x);
    Data1 y {0, false, 0};
    Error err = deserializer1.load(y);
    if ((err == Error::NoError) && (x.a == y.a) && (x.b == y.b) && (x.c == y.c))
        std::cout<<"OK 1"<<std::endl;
    else
        std::cout<<"Wrong 1"<<std::endl;

    //test2
    err = deserializer1.load(y);
    if (err == Error::CorruptedArchive)
        std::cout<<"OK 2"<<std::endl;
    else
        std::cout<<"Wrong 2"<<std::endl;

    //test3
    stream.str(std::string());
    stream.clear();
    Data2 z1{1, false, false, true, 50000};
    Data2 z;
    serializer1.save(z1);
    stream>>c;
    err = deserializer1.load(z);
    if (err == Error::CorruptedArchive)
        std::cout<<"OK 3"<<std::endl;
    else
        std::cout<<"Wrong 3"<<std::endl;

    //test4
    stream.str(std::string());
    stream.clear();
    Data2 z3{2, false, false, true, 50000};
    Data01 f1{4, true, false, true};
    Data02 f2{987654321};
    serializer1.save(f1);
    serializer1.save(f2);

    err = deserializer1.load(z3);
    if ((err == Error::NoError) && (z3.a == 4) && (z3.b1 == true)
        && (z3.b2 == false) && (z3.b3 == true) && (z3.c == 987654321))
        std::cout<<"OK 4"<<std::endl;
    else
        std::cout<<"Wrong 4"<<std::endl;

    return 0;
}
