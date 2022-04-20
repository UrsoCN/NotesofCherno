// 【75】【Cherno C++】【中字】C++的结构化绑定

// warning: structured bindings only available with ‘-std=c++17’ or ‘-std=gnu++17’
// 用g++编译时需要加上‘-std=c++17’ or ‘-std=gnu++17’

// 结构化绑定struct binding是C++17的新特性，能让我们更好地处理多返回值

#include <iostream>
#include <string>
#include <tuple>

// 也可以用如下的结构体实现多返回值
struct Person
{
    std::string Name;
    int Age;
};

// std::pair<std::string,int> CreatPerson() // 只能有两个变量
std::tuple<std::string, int> CreatPerson() // 可以理解为pair的扩展
{
    return {"Cherno", 24};
}

int main()
{
    // std::tuple<std::string, int> person = CreatPerson();
    // auto person = CreatPerson();
    // std::string& name = std::get<0>(person);
    // int age = std::get<1>(person);

    // std::string name;
    // int age;
    // std::tie(name, age) = CreatPerson();

    auto[name, age] = CreatPerson();
    std::cout << name;
}