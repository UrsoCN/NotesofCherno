// 【36】【Cherno C++】【中字】C++的成员初始化列表
// 在构造函数里初始化语句会有性能浪费（基本数据类型如int不会出现这种情况）
// 原因是成员对象会首先由默认构造函数实例化
// 如果再在构造函数函数体里加上初始化语句，那么实际上就会有两个成员对象类的对象在内存里
// 之后默认构造函数实例化的那个对象再被丢弃
// 另外，对const对象初始化也必须用成员初始化列表

#include <iostream>
#include <string>

class Example
{
public:
    Example()
    {
        std::cout << "Created Example!" << std::endl;
    }
    Example(int x)
    {
        std::cout << "Created Example with " << x << "!" << std::endl;
    }
};

class Entity
{
private:
    std::string m_Name;
    Example m_Example;

public:
    Entity()
    {
        m_Name = std::string("Unknow");
        m_Example = Example(8);
    }
    // 成员初始化列表
    // Entity()
    //     : m_Name("Unknow") {}
    // Entity(const std::string &name)
    //     : m_Name(name) {}

    const std::string &GetName() const { return m_Name; }
};

int main()
{
    Entity e0;
    std::cin.get();
}