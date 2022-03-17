// 【35】【Cherno C++】【中字】C++的mutable关键字

#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;
    mutable int m_DebugCount = 0; //调试时希望能看到GetName函数被调用了多少次
public:
    //返回一个不改变的引用，同时承诺这个方法不修改成员
    const std::string &GetName() const
    {
        m_DebugCount++;
        return m_Name;
    }
};

int main()
{
    const Entity e;

    int x = 8;
    // lambda表达式，可以看作是个一次性的函数
    // []中是捕获列表，可以传值、传引用，或者通过=对所有变量进行传值
    // 这里的mutable意味着通过值传递的变量可以改变
    // 不过这个改变相当于在lambda中复制了一个变量，对这个复制的变量进行修改
    auto f = [=]() mutable
    {
        x++;
        std::cout << x << std::endl;
    };

    f();    //9
    std::cout << x << std::endl;    //8

    std::cin.get();
}