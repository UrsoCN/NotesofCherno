// 【68】【Cherno C++】【中字】C++的虚析构函数

// 虚析构函数在处理多态的时候非常有用
// 标记为虚析构函数意思不是覆写析构函数，而是加上一个析构函数
// 只要你允许一个类拥有子类，那么就有必要将这个类的析构函数声明为虚析构函数

// 此处这位外国友人说错了，定义基类的虚析构并不是什么相加，
// 而是：基类中只要定义了虚析构（且只能在基类中定义虚析构，子类析构才是虚析构，
// 如果在二级子类中定义虚析构，编译器不认，且virtual失效），
// 在编译器角度来讲，那么由此基类派生出的所有子类的析构均为对基类的虚析构的重写，
// 当多态发生时，用父类引用，引用子类实例时，此时的虚指针保存的子类虚表的地址，
// 该函数指针数组中的第一元素永远留给虚析构函数指针。
// 所以当delete 父类引用时，即第一个调用子类虚表中的子类重写的虚析构函数此为第一阶段。
// 然后进入第二阶段：（二阶段纯为内存释放而触发的逐级析构与虚析构就没有半毛钱关系了）
// 而当子类发生析构时，子类内存开始释放，因内存包涵关系，触发父类析构执行，
// 层层向上递进，至到子类所包涵的所有内存释放完成。

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

int main()
{
    Base *base = new Base();
    delete base;
    std::cout << "-----------------" << std::endl;
    Derived *derived = new Derived();
    delete derived;
    std::cout << "-----------------" << std::endl;
    Base *poly = new Derived();
    delete poly; // 这里会造成内存泄漏
    // Base Constructor
    // Base Destructor
    // -----------------
    // Base Constructor
    // Derived Constructor
    // Derived Destructor
    // Base Destructor
    // -----------------
    // Base Constructor
    // Derived Constructor
    // Base Destructor
}