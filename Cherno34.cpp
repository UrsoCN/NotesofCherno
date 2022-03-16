// 【34】【Cherno C++】【中字】C++中的CONST

// const被Cherno称为伪关键字，因为它在改变生成代码方面做不了什么，类似于类里的可见性

#include <iostream>

class Entity
{
private:
    int m_X, m_Y;
    mutable int var; //但你确实要改一个成员变量，就标记它为mutiable

public:
    int GetX() const //这只在类中有效，表示我们不能修改成员变量
    {
        // m_X = 2; //是不被允许的
        var = 2;
        return m_X;
    }
    int GetX() //所以这类成员函数一般都有两个，一个const供希望const的函数调用
    {
        return m_X;
    }
    void SetX(int x)
    {
        m_X = x;
    }
};

class Entity2
{
private:
    int *m_X, m_Y; //在这样写的时候m_X是指针，但m_Y是int变量

public:
    const int *const GetX() const //返回一个指针，指针、指针指向的内容不能修改，同时承诺这个方法不修改成员
    {
        // m_X = 2; //是不被允许的
        return m_X;
    }
};

void PrintEntity(const Entity &e)
//引用表示了我们不希望复制原Entity(损失性能)
//同时我们也不希望修改原来的Entity，同时得到传值和传引用的"优点"
//这同时会要求函数里调用的Entity的成员方法是const的，不然就不能保证不修改原来的Entity了
//也就是这个函数里只能调用Entity常函数
{
    std::cout << e.GetX() << std::endl;
}

int main()
{
    Entity e;

    const int Max_Age = 90;

    // const int *a = new int;
    // int const *a = new int; //与上面一样
    // int* const a = new int; //指针本身const，
    const int *const a = new int; //指针和指针指向的对象都const

    // *a = 2; //在声明时添加const之后，就不能修改指针指向的对象了
    // a = (int *)&Max_Age; //const指针不能修改
    std::cout << *a << std::endl;

    std::cin.get();
}