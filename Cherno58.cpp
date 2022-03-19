// 【58】【Cherno C++】【中字】C++的函数指针

#include <iostream>
#include <vector>

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

void ForEach(const std::vector<int> &values, void (*func)(int))
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
    ForEach(values, PrintFunction); // 可以通过函数指针让一个函数执行一个指定的函数

    // 匿名函数，lambda
    // []捕获方式：如何传入，传出函数
    ForEach(values, [](int value)
            { std::cout << "Value: " << value << std::endl; }); // 可以通过函数指针让一个函数执行一个指定的函数
}