// 【77】【Cherno C++】【中字】单一变量存放多种类型的数据

// warning: structured bindings only available with ‘-std=c++17’ or ‘-std=gnu++17’
// 用g++编译时需要加上‘-std=c++17’ or ‘-std=gnu++17’

// std::variant同样是C++17的新特性，可以让我们不用担心处理的确切数据类型

#include <iostream>
#include <variant>

int main()
{
    std::variant<std::string, int> data;
    std::cout << sizeof(data) << "\n"; // variants将所有可能的数据类型存储为单独的变量、作为单独的成员

    union u
    {
        std::string a;
        int b;
    };
    std::cout << sizeof(u) << "\n"; // 而联合体的大小是最大类型的大小

    data = "Cherno";
    if (auto value = std::get_if<std::string>(&data))
    {
        std::cout << data.index() << "\t" << std::get<std::string>(data) << "\n";
        // ...
    }
    else
    {
    }

    data = 2;
    std::cout << data.index() << "\t" << std::get<int>(data) << "\n";
}