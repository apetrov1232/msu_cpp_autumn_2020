#include<cstdlib>

class Allocator{
public:

    size_t val = 0;
    char* all = nullptr;
    char* offset = nullptr;

    void makeAllocator(size_t maxSize){
        if (this->all != nullptr){
            free(this->all);
        };
        this->all = static_cast<char*>(malloc(maxSize));
        this->val = maxSize;
        this->offset = this->all;
    };

    char* alloc(size_t size){
        if ((this->offset - this->all + size) > this->val){
            return nullptr;
        }
        char* ans = this->offset;
        this->offset = this->offset + size;
        return ans;
    };

    void reset(){
        this->offset = this->all;
    };

    ~Allocator(){
        if (this->all != nullptr){
            free(this->all);
        };
    };
};
