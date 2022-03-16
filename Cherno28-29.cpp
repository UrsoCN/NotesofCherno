// 【28】【Cherno C++】【中字】C++虚函数
// 【29】【Cherno C++】【中字】C++接口（纯虚函数）

// 关于使用虚函数时的运行成本：(一般来说性能损失很小)
// 1. 存储V表的额外内存，包括基类中指向V表的成员指针
// 2. 每次调用虚函数时，需要遍历这个V表，来确定要映射到哪个函数

// 纯虚函数本质上与Java或者C#中的抽象方法或者接口相同
// 纯虚函数允许在基类定义一个没有实现的函数，然后强制子类去实现该函数
// 在OO中，类中的接口只包含未实现的方法，作为模板是很常见的
// 纯虚函数只有在被实现之后才能实例化(不能没有函数体/方法实现)

#include <iostream>
#include <string>

// 当我们想要编写一个函数来打印"某些(多个)"类的类名时
// 我们就需要有一个类来保证这些类有(提供)GetClassName函数(这就是所谓接口)
// 这里，这个类就是Printable，要注意C++没有interface关键字

class Printable
{
public:
    virtual std::string GetClassName() = 0;
};

class Entity : public Printable
{
public:
    // 虚函数
    //如果这个函数被重写了，编译器会在生成的V表中找到正确的函数
    virtual std::string GetName() { return "Entity"; }

    // 纯虚函数
    // virtual std::string GetName() = 0;

    std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity
{
private:
    std::string m_Name;
public:
    Player(const std::string &name) // const 是为了限定它只读
        : m_Name(name) {}
        // 这里使用的技巧是构造函数初始化列表
        // 本质上这就是构造函数，
        // :后面的是这个语句的意思相当于函数体内部的m_Name = name语句，也是赋值的意思
        // 使用构造函数初始化列表并没有效率上的优势，仅仅是书写方便，尤其是成员变量较多时，这种写法非常简单明了。

    std::string GetName() override { return m_Name; }

    std::string GetClassName() override { return "Player"; }
};

void PrintName(Entity *entity)
{
    std::cout << entity->GetName() << std::endl;
}

class A : public Printable  //任何一个继承自Printable的类都有一个能调用的GetClassName()函数
{
    std::string GetClassName() override { return "A"; }
};

void Print(Printable* obj)
{
    std::cout << obj->GetClassName() << std::endl;
}

int main()
{
    Entity *e = new Entity();//在定义Entity为纯虚函数时，不允许使用抽象类类型 "Entity" 的对象
    PrintName(e);

    Player *p = new Player("Cherno");
    PrintName(p);

    Entity *entity = p;
    PrintName(entity);

    std::cout<<"`````````````````````````````````````"<<std::endl;

    Print(e);
    Print(p);
    Print(entity);

    Print(new A());


    // 如果没有定义Entity->GetName为虚函数，
    // 这里的三次打印都打印出Entity，而不是期望中的Cherno
    // 为了简单起见，当想要覆写(override)一个函数时，必须将基类中的基函数标记位虚函数

    // 另一个可行的举措是：在Player->GetName使用C++11引入的关键字"override"
    // 这不仅会使得代码可读性更强，
    // 还能自动校验“override”声明的成员函数是否的确是虚函数
    std::cin.get();
}