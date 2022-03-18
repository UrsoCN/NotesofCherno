// 【44】【Cherno C++】【中字】C++的智能指针

// Smart Pointer本质上是原始指针的一个包装
// 1. unique_ptr: 作用域指针，超出作用域后就会销毁
// 且unique_ptr应当是唯一的，不能复制unique_ptr(删除了它的拷贝构造函数和=操作符)
// 2. shared_ptr:
// shared_ptr实现的方式取决于编译器和在编译器中使用的标准库
// 绝大多数系统中，它使用的是引用计数(refrence counting)，可以跟踪指针有多少个引用
// 一旦引用计数达到0，它就被删除了
// 3. weak_ptr: 
// std::weak_ptr<Entity> weakEntity = sharedEntity;不会增加引用计数
// 当你不想要Entity的所有权的时候，可以使用weak_ptr

#include <iostream>
#include <string>
#include <memory>

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
    void Print() {}
};

int main()
{
    {
        std::shared_ptr<Entity> e0;

        {
            // std::unique_ptr<Entity> entity(new Entity());

            // 不能像下面这么做，因为unique_ptr构造函数是explicit的，必须显式调用构造函数
            // std::unique_ptr<Entity> entity = new Entity();
            // 一个更好的做法是通过std::make_unique<Entity>()来构造，主要原因是处于异常安全
            // 在构造函数抛出异常时，不会返回一个悬空指针，避免内存泄漏
            // std::unique_ptr<Entity> entity = std::make_unique<Entity>(); //C++14引入的
            // entity->Print();

            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            e0 = sharedEntity;
            // std::weak_ptr<Entity> weakEntity = sharedEntity;
            std::cout << "end of the inner scope" << std::endl;
        }
    }

    std::cin.get();
}