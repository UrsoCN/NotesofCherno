// 【78】【Cherno C++】【中字】如何存储任意类型的数据

// warning: structured bindings only available with ‘-std=c++17’ or ‘-std=gnu++17’
// 用g++编译时需要加上‘-std=c++17’ or ‘-std=gnu++17’

// std::any同样是C++17的新特性
// 对于小类型(small type)来说，any将它们存储为一个严格对齐的Union
// 对于大类型，会用void*，动态分配内存

#include <iostream>
#include <any>

void *operator new(size_t size)
{
    return malloc(size);
}

int main()
{
    std::any data;
    data = 2;
    data = "Cherno";
    data = std::string("Cherno");

    std::string &string = std::any_cast<std::string &>(data);
    // 通过引用减少复制操作，以免影响性能
}