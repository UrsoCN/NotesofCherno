// 【85】【Cherno C++】【中字】C++中的左值与右值

// 左值可以被称为地址值(在内存中有位置的实际变量)
// 右值可以被称为临时值(没有/访问不到存储空间、位置)
// 可以通过 常引用或者右值引用演唱右值的生命周期

#include <iostream>

int &GetValue()
{ // 左值引用
    static int value = 10;
    return value;
}

void SetValue(int value) {}

void PrintName(std::string &name)
{ // 非const的左值引用只接受左值
    std::cout << "[lvalue]" << name << std::endl;
}

void PrintName(const std::string &&name)
{ // 右值引用不能绑定到左值
    std::cout << "[rvalue]" << name << std::endl;
}

int main()
{
    int i = GetValue();
    GetValue() = 5;

    SetValue(i);  // 左值参数调用
    SetValue(10); // 右值参数调用，当函数被调时，这个右值会被用来创建一个左值

    // 关于const，const引用可以同时接受左值和右值
    // int& a = 10; // 不能用左值作为右值的引用
    const int &a = 10; // 通过创建一个左值实现

    std::string firstName = "Yan";
    std::string lastName = "Chernikov";
    std::string fullname = firstName + lastName;
    PrintName(fullname);             // 接受左值
    PrintName(firstName + lastName); // 接受右值

    return 0;
}