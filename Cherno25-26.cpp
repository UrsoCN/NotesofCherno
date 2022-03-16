// 【25】【Cherno C++】【中字】C++构造函数
// 【26】【Cherno C++】【中字】C++析构函数

#include <iostream>

class Entity
{
public:
    float X, Y;

    Entity()
    { // constructor
        X = 0.0f;
        Y = 0.0f;
        std::cout << "Created Entity!" << std::endl;
    }

    // Entity(float x, float y)
    // { // Overloaded constructor
    //     X = x;
    //     Y = y;
    // }

    ~Entity(){ // destructor
        std::cout << "Destroyed Entity!" << std::endl;
    }

    void Print()
    {
        std::cout << X << ", " << Y << std::endl;
    }
};

class Log
{ //当只希望使用这个类的静态方法而不希望实例化对象时，可以有两个方法
private:
    // Log() {}    //1. 将构造 函数设为私有
public:
    Log() = delete; // 2. 删除构造函数//无法引用 "Log" 的默认构造函数 -- 它是已删除的函数
    static void Write()
    {
    }
};

void Function(){
    Entity e;
    e.Print();                     // 1.72191e-19, 4.59121e-41
}

int main()
{
    // Log::Write(); // 当使用类的静态函数时，构造函数不会被调用
    // Log l; //没有构造函数，不能初始化
    // Entity e(10.0f, 5.0f);
    // std::cout << e.X << std::endl; //用VS编译好像会报错，uninitialized local variable
                                   // g++好像不管这个
    // Entity e;
    // e.Print();                     // 1.72191e-19, 4.59121e-41

    Function(); //Function函数执行完后，ta实例化的e的作用域就结束了。

    std::cin.get();
}