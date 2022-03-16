// 【30】【Cherno C++】【中字】C++可见性

// C++中有三个基础的可见性修饰符：private protected public
// class的默认可见性是private
// struct的默认可见性是public

// private只有类本身和friend类可见
// protect表示只有类及其子类可见（和friend类
// public表示所有都能访问

#include <iostream>
#include <string>

class Entity
{
private:
    int X, Y;

protected:
    void Print() {}

public:
    Entity()
    {
        X = 0;
        Print();
    }
};

class Player : public Entity
{
private:
public:
    Player()
    {
        // X = 2; //同样不能访问
        Print(); //可以访问父类的protected成员
    }
};

int main()
{
    Entity e;
    // e.X = 2; //不能访问
    // e.Print(); //同样不能访问

    std::cin.get();
}