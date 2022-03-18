// 【43】【Cherno C++】【中字】C++的对象生存期（栈作用域生存期）

// 在C++中，我们可以做到在堆中分配对象，同时做到像栈一样
// 在超出作用域后自动删除
// 通过使用标准库中的unique_ptr,一个作用域指针

#include <iostream>
#include <string>

class Entity
{
public:
    Entity()
    {
        std::cout << "Created Entity!" << std::endl;
    }
    ~Entity()
    {
        std::cout << "Destroyed Entity!" << std::endl;
    }
};

int *CreatArray()
{
    // int array[50]; // 这样写是毫无意义的，因为域结束后就没了
    int *array = new int[50]; // 应当在堆中构建
    return array;
}

class ScopePtr // 这就是一个基本的作用域指针(类)
{
private:
    Entity *m_Ptr;

public:
    ScopePtr(Entity *ptr)
        : m_Ptr(ptr) {}
    ~ScopePtr()
    {
        delete m_Ptr;
    }
};

int main()
{
    // int *a = CreatArray();

    // Entity entity;
    // {
    //     Entity entity;
    // }
    // {
    //     Entity *entity = new Entity(); // 程序结束后，由操作系统回收这部分内存
    // }

    {
        ScopePtr e = new Entity(); // 隐式转换 //且这样即使在堆中构造,也会在作用域结束后被销毁
        // Entity *e = new Entity();
    }

    std::cin.get();
}