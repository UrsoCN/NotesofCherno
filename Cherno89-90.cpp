// 【89】【Cherno C++】【中字】C++移动语义
// 【90】【Cherno C++】【中字】stdmove与移动赋值操作符

// 参考博客：https://www.cnblogs.com/zhangyi1357/p/16018810.html

// 三法则：如果需要析构函数，则一定需要拷贝构造函数和拷贝赋值操作符
// 五法则：为了支持移动语义，又增加了移动构造函数和移动赋值运算符

// 依赖C++11引入的右值引用

#include <iostream>
#include <cstring>
class String
{
public:
    String() = default;
    String(const char *string)
    {
        printf("Created!\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }
    String(const String &other)
    {
        printf("Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }
    String(String &&other) // 移动构造函数
    {
        printf("Moved!\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        other.m_Data = nullptr;
        other.m_Size = 0; // 偷掉原来的String
    }
    ~String()
    {
        printf("Destroyed!\n");
        delete[] m_Data;
    }

    void Print()
    {
        for (uint32_t i = 0; i < m_Size; ++i)
            printf("%c", m_Data[i]);
        printf("\n");
    }
    String &operator=(String &&other) // 移动复制运算符重载
    {
        printf("Moved\n");
        if (this != &other)
        {
            delete[] m_Data;

            m_Size = other.m_Size;
            m_Data = other.m_Data;

            other.m_Data = nullptr;
            other.m_Size = 0;
        }
        return *this;
    }

private:
    char *m_Data;
    uint32_t m_Size;
};

class Entity
{
public:
    Entity(const String &name) : m_Name(name) {}
    // 接受右值的函数在参数传进来后其右值属性就退化了，
    // 所以这里给m_Name的参数仍然是左值，还是会调用复制构造函数。
    // Entity(String &&name) : m_Name(name) {}
    // 可以通过强制类型转换实现
    // Entity(String &&name) : m_Name((String &&) name) {}
    // 更好的方法是通过std::move实现
    Entity(String &&name) : m_Name(std::move(name)) {}

    void PrintName() { m_Name.Print(); }

private:
    String m_Name;
};

int main(int argc, const char *argv[])
{
    {
        Entity entity(String("Cherno"));
        entity.PrintName();
    }
    std::cout << "- - - - - -\n";
    String string = "Hello";
    String dest = std::move(string);
    std::cout << "- - - - - -\n";
    String apple = "apple";
    String orange = "orange";

    printf("apple: ");
    apple.Print();
    printf("orange: ");
    orange.Print();

    apple = std::move(orange);

    printf("apple: ");
    apple.Print();
    printf("orange: ");
    orange.Print();
    std::cout << "- - - - - -\n";

    return 0;
}