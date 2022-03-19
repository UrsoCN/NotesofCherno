// 【53】【Cherno C++】【中字】C++的模板

// 像这个cpp文件里的编程方式常被称为元编程meta programming

#include <iostream>

// 被写作模板的函数不是一个实际的代码/函数
// 只有当我们实际带哦用它的时候，这些函数才被真的创建
// 当我们调用这个函数的时候，基于传递的参数
// 这个函数才被创建出来，并作为源代码被编译
template <typename T> // template<class T>
void Print(T value)
{
    std::cout << value << std::endl;
}

template <int N>
class Array
{
private:
    int m_Array[N];

public:
    int GetSize() const { return N; }
};

template <typename T, int N>
class Array1
{
private:
    T m_Array[N];

public:
    int GetSize() const { return N; }
};

int main()
{
    Print(5); // Print<int>(5);
    Print("Hello");
    Print(5.5f);

    Array<5> array;
    std::cout << array.GetSize() << std::endl;

    Array1<std::string, 50> array1;
    std::cout << array1.GetSize() << std::endl;

    std::cin.get();
}