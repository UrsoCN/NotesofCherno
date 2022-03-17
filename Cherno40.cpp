// 【40】【Cherno C++】【中字】 C++隐式转换与explicit关键字
// explicit关键字用来禁用隐式转换

#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
    std::string m_Name;
    int m_Age;

public:
    Entity(const String &name)
        : m_Name(name), m_Age(-1) {}
    explicit Entity(int age)
        : m_Name("Unknown"), m_Age(age) {}
};

void PrintEntity(const Entity& entity){
    // ...
}

int main()
{  
    // 因为可以通过22构造Entity对象，所以C++认为你也可以把22隐式转换成Entity
    // PrintEntity(22);
    // 下面这个就不能直接用"Cherno"了，C++只允许做一次隐式转换
    PrintEntity(std::string("Cherno")); //需要const char[] -> std::string -> Entity

    Entity a("Cherno");

    //下面就用到了隐式转换，隐式地讲22转换成一个Entity，构造出一个Entity
    // Entity b = 22; //Entity b = Entity(22);在注明explicit之后就不能这么用了。
    Entity b = (Entity)22; //cast，显式转换
    std::cin.get();
}