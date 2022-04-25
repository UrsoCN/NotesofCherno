// 【80】【Cherno C++】【中字】如何让C++字符串更快

// warning: structured bindings only available with ‘-std=c++17’ or ‘-std=gnu++17’
// 用g++编译时需要加上‘-std=c++17’ or ‘-std=gnu++17’

// std::string_view同样是C++17的新特性，但是在此之前，这种优化已经很常用了

// gcc的string默认大小是32个字节，字符串小于等于15直接保存在栈上，超过之后才会使用new分配

// string的常用优化：__SSO__(短字符串优化)、__COW__（写时复制技术优化）

#include <iostream>
#include <string>

static uint32_t s_AllocCount = 0;

void *operator new(size_t size)
{
    s_AllocCount++;
    std::cout << "Allocating " << size << " bytes\n";
    return malloc(size);
}

void PrintName(const std::string &name)
{
    std::cout << name << std::endl;
}

void PrintName(std::string_view name)
{
    std::cout << name << std::endl;
}

int main()
{
    const std::string name = "Yan Chernikovasduhasduihasiudhiaushdiuashdiuahsdnaksj";
    const char *cname = "Yan Chernikovsduohasdhaoisjdoiasodijaosijdoaisndbasuidnkas"; // C-like的编码风格

#if 1
    std::string firstName = name.substr(0,3);
    std::string lastName = name.substr(4,9);
#else
    std::string_view firstName(name.c_str(), 3);
    std::string_view lastName(name.c_str() + 4, 9);
#endif

    PrintName(name);
    PrintName(firstName);
    PrintName(lastName);

    std::cout << s_AllocCount << " allocations" << std::endl;

    return 0;
}