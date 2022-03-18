// 【46】【Cherno C++】【中字】C++的箭头操作符

// ->操作符还有另一个作用：获取成员变量（在内存）的偏移量

#include <iostream>
#include <string>

class Entity
{
public:
    void Print() const { std::cout << "Hello!" << std::endl; }
};

class ScopePtr // Entity类的作用域指针，Entity超出范围就被销毁
{
private:
    Entity *m_Obj;

public:
    ScopePtr(Entity *entity)
        : m_Obj(entity) {}

    ~ScopePtr()
    {
        delete m_Obj;
    }

    // Entity* GetObject() { return m_Obj; } // 可以重载->操作符来达到同样效果

    Entity *operator->()
    {
        return m_Obj;
    }

    const Entity *operator->() const
    {
        return m_Obj;
    }
};

/*-------------------------------------------------------*/

struct Vector3
{
    float x, y, z;
};

/*-------------------------------------------------------*/

int main()
{
    // Entity e;
    // e.Print();

    // Entity *ptr = &e;
    // (*ptr).Print();
    // ptr->Print();

    // Entity &entity = *ptr;
    // entity.Print();

    const ScopePtr entity = new Entity();

    // entity.GetObject()->Print(); // 使用这个智能指针时，需要间接地调用它的成员函数
    entity->Print(); // 重载->之后就能更轻松地调用了

    /*-------------------------------------------------------*/
    int offset = (long)&((Vector3 *)nullptr)->z; // 得到内存的布局，nullptr也可以用0代替
    std::cout << offset << std::endl; // offset is 8 of z
    /*-------------------------------------------------------*/

    std::cin.get();
}