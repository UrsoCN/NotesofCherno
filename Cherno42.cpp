// 【42】【Cherno C++】【中字】C++的this关键字

#include <iostream>
#include <string>

void PrintEntity(const Entity& e);

class Entity
{
private:
    int x, y;

public:
    Entity(int x, int y)
    {
        // 当我们希望在函数体内初始化x,y时，我们会遇到一些问题
        // 成员x,y和函数变量x,y名字一样
        // x = x; // 这样做时，我们实际上是将变量x=变量x，什么也没做

        Entity* const e = this; // 这就是this的真正含义

        e->x = x;
        this->y = y; // 这才是我们真正希望做到的
        // (*this).y = y; // 与上式等价
        PrintEntity(*this);
    }

    int GetX() const{
        const Entity* e = this;

        return x;
    }
};

void PrintEntity(const Entity& e){
    // ...
}


int main()
{

    std::cin.get();
}