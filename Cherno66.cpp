// 【66】【Cherno C++】【中字】C++的类型双关

#include <iostream>

struct Entity
{
    int x, y;
};

int main()
{
    Entity e = {5, 8};
    int *position = (int *)&e;
    std::cout << position[0] << ", " << position[1] << std::endl;

    int y = *(int *)((char *)&e + 4);
    std::cout << y << std::endl;
    // int a = 50;
    // double value = *(double*)&a; // 这就是类型双关
    // std::cout << value << std::endl;
}