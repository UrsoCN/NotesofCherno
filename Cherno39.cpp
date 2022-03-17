// 【39】【Cherno C++】【中字】 C++ new关键字
// new主要就是找到一块足够我们使用的内存，并讲内存地址返回过来
// new是一个操作符，就像+-=一样

#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
    std::string m_Name;

public:
    Entity() : m_Name("Unknown") {}
    Entity(const String& name) : m_Name(name) {}
    const std::string &GetName() const { return m_Name; }
};

int main()
{
    int a = 2;
    int *b = new int[50]; //200 Bytes

    Entity *e = new Entity(); //不仅会分配内存，还会调用构造函数
    Entity *e = new(b) Entity(); //指定在b里初始化

    // 相当于C中的malloc，返回的都是void*
    // 仅有的区别就是new会调用Entity()构造函数
    Entity *e1 = (Entity*)malloc(sizeof(Entity));

    delete[] b;
    delete e;
    delete e1;

    std::cin.get();
}
