// 【38】【Cherno C++】【中字】 创建并初始化C++对象

#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
    String m_Name;

public:
    Entity() : m_Name("Unknown") {}
    Entity(const String &name) : m_Name(name) {}

    const String &GetName() const { return m_Name; }
};

int main()
{
    // 在栈上创建并初始化对象，如果允许这样创建对象，那么就这样创建
    // 这就是C++中最快，最可管控的初始化对象的方法
    Entity entity;
    std::cout << entity.GetName() << std::endl;

    // 在堆上创建并初始化对象，new关键字，返回的会是一个地址（指针）
    // 当我们使用new之后，我们需要负责释放这些内存。
    Entity *entity2 = new Entity("Cherno");
    std::cout << entity2->GetName() << std::endl;
    delete entity2;

    std::cin.get();
}
