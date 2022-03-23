// 【69】【Cherno C++】【中字】C++的类型转换

// C++的类型转换在C的基础上添加了编译时检查，能够快速地知道，这样的转换是否可行

//  * cast 分为 static_cast  dynamic_cast reinterpret_cast const_cast
//  * static_cast static_cast 用于进行比较“自然”和低风险的转换，如整型和浮点型、字符型之间的互相转换,不能用于指针类型的强制转换
//  * reinterpret_cast  用于进行各种不同类型的指针之间强制转换
//  * const_cast 仅用于进行去除 const 属性的转换
//  * dynamic_cast 不检查转换安全性，仅运行时检查，如果不能转换，返回null

#include <iostream>

class Base
{
public:
    Base() { std::cout << "Base Constructor\n"; }
    virtual ~Base() { std::cout << "Base Destructor\n"; }
};

class Derived : public Base
{
public:
    Derived()
    {
        m_Array = new int[5];
        std::cout << "Derived Constructor\n";
    }
    ~Derived()
    {
        delete[] m_Array;
        std::cout << "Derived Destructor\n";
    }

private:
    int *m_Array;
};

class AnotherClass : public Base
{
public:
    AnotherClass(){};
    ~AnotherClass(){};
};

int main()
{
    // double value = 5.25;
    // // int a = value;
    // // int a = (int)value;
    // double a = (int)value + 5.3; // 10.3 // C style cast here

    // double s = static_cast<int>(value) + 5.3; // C++ style cast here

    // std::cout << a << std::endl;
    // std::cout << s << std::endl;

    Derived *derived = new Derived();

    Base *base = derived;

    // AnotherClass *ac = static_cast<AnotherClass*>(base);
    Derived *ac = dynamic_cast<Derived *>(base);

    delete derived;
}
