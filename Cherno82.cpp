// 【82】【Cherno C++】【中字】C++的单例模式

// 从根本上说，单例的行为就像名称空间，单例类可以像名称空间一样工作
// C++中的单例只是一种组织一堆全局变量和静态函数的方式。
// 这些静态函数有时可能对这些变量起作用，有时候也可能不对这些变量起作用。

#include <iostream>

// class Singleton
// {
// public:
//     Singleton(const Singleton&) = delete;

//     // 2.提供一种静态访问该类的方法
//     static Singleton &Get()
//     {
//         // 2.3. 然后就能直接返回这个实例了
//         return s_Instance;
//     }
//     void Function() {}

// private:
//     // 1. singleton不能有公共的构造函数，这会让它能被实例化
//     Singleton() {}

//     // 2.1. 创建单例类的静态实例
//     static Singleton s_Instance; // 2.2. 由于它是静态的，所以需要在某处定义它
// };

// Singleton Singleton::s_Instance;

class Random
{
public:
    Random(const Random &) = delete;

    static Random &Get()
    {
        return s_Instance;
    }

    float Float() { return m_RandomGenerator; }
    // 如果只是需要返回某个静态值，那么只需要将这个标记为static而不需要单例
    // 而用了单例类之后，就有了类的特性（类成员变量）

    // static float Float() { return Get().IFloat(); }

private:
    // float IFloat() { return m_RandomGenerator; }

    Random() {}

    float m_RandomGenerator = 0.5f;

    static Random s_Instance;
};

Random Random::s_Instance;

namespace RandomClass
{
    static float s_RandomGenerator = 0.5f;
    static float Float() { return s_RandomGenerator; }
} // namespace RandomClass

int main()
{
    // 需要避免非引用的用法，那样就会创建一个额外的Singleton实例，可以通过删除copy构造函数来避免
    // Singleton &instance = Singleton::Get();
    // Singleton::Get().Function();
    auto &random = Random::Get();
    float number = random.Float();

    // 要实现如下的直接调用，可以通过line46和49的tricks完成
    // 这样的话，甚至可以直接将Get()声明为private
    // float number = Random::Float();

    return 0;
}