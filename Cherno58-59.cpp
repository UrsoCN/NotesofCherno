// 【58】【Cherno C++】【中字】C++的函数指针
// 【59】【Cherno C++】【中字】C++的lambda

// lambda本质上是我们定义一种叫做匿名函数的方式
// lambda的用法是，在我们会设置函数指针指向函数的任何地方，我们都可以将它设置为lambda

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// void HelloWorld()
// {
//     std::cout << "Hello World!" << std::endl;
// }

// void HelloWorld(int a)
// {
//     std::cout << "Hello World! Value: " << a << std::endl;
// }

void PrintFunction(int value)
{
    std::cout << "Value: " << value << std::endl;
}

// void ForEach(const std::vector<int> &values, void (*func)(int))
void ForEach(const std::vector<int> &values, const std::function<void(int)> &func)
{
    for (int value : values)
        func(value);
}

int main()
{
    // typedef void(*HelloWorldFunction)(int);
    // void(*function)() = HelloWorld; // 与下行等价
    // auto function = HelloWorld; // 不能带括号，带括号调用函数，不带返回函数指针
    // HelloWorldFunction function = HelloWorld; // 与上式等价
    // function(8);

    std::vector<int> values = {1, 5, 4, 2, 3};

    auto it = std::find_if(values.begin(), values.end(), [](int value)
                 { return value > 3; });
    std::cout << *it <<std::endl;


    // ForEach(values, PrintFunction); // 可以通过函数指针让一个函数执行一个指定的函数

    // 匿名函数，lambda
    // []捕获方式：如何传入，传出函数

    // int a = 5;

    // auto lambda = [=](int value) mutable
    // { a = 5; std::cout << "Value: " << value << a << std::endl; };

    // ForEach(values, lambda);
    // ForEach(values, [](int value)
    //         { std::cout << "Value: " << value << std::endl; }); // 可以通过函数指针让一个函数执行一个指定的函数
}