#include <cstdlib>
class Allocator{
public:
    size_t val = 0;
    char* all = nullptr;
    char* offset = nullptr;

    void makeAllocator(size_t maxSize);
    char* alloc(size_t size);
    void reset();
    ~Allocator(){
        if (this->all != nullptr){
            free(this->all);
        };
    };
};
