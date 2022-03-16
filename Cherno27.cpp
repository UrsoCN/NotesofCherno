// 【27】【Cherno C++】【中字】C++继承

#include <iostream>

class Entity
{
public:
    float X, Y;
    void Move(float xa, float ya)
    {
        X += xa;
        Y += ya;
    }
};

class Player : public Entity
{
public:
    const char *Name;   //在32位中表现为4字节，64位中表现为8字节

    void PrintName()
    {
        std::cout << Name << std::endl;
    }
};

int main()
{
    std::cout << sizeof(Entity) << std::endl;
    std::cout << sizeof(Player) << std::endl;

    Player player; //子类是父类的超集
    player.Move(5, 5);
    player.X = 2;

    std::cin.get();
}