// 【57】【Cherno C++】【中字】C++的静态数组（std array)

#include <iostream>
#include <array>

template <typename T>
void printarray(const T &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << std::endl;
    }
}

template <typename T, unsigned long N> // or // template <typename T, size_t N>
void printarray2(const std::array<T, N> &data)
{
    for (int i = 0; i < N; i++)
    {
        std::cout << data[i] << std::endl;
    }
}

int main()
{
    std::array<int, 5> data;
    data[0] = 2;
    data[4] = 1;
    printarray(data);
    printarray2(data);
}