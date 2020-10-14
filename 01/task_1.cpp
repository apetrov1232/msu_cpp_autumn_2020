#include "task_1.h"

void Allocator::makeAllocator(size_t maxSize){
    if (this->all != nullptr){
        free(this->all);
    };
    this->all = static_cast<char*>(malloc(maxSize));
    this->val = maxSize;
    this->offset = this->all;
};

char* Allocator::alloc(size_t size){
    if ((this->offset - this->all + size) > this->val){
        return nullptr;
    }
    char* ans = this->offset;
    this->offset = this->offset + size;
    return ans;
};

void Allocator::reset(){
    this->offset = this->all;
};

