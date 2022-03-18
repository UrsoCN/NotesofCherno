// 【45】【Cherno C++】【中字】C++的复制与拷贝构造函数

#include <iostream>
#include <string>
#include <cstring>

class String
{
private:
    char *m_Buffer;
    unsigned int m_Size;

public:
    String(const char *string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1]; // 记得delete
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0;
    }

    ~String()
    {
        delete[] m_Buffer;
    }

    // C++的默认拷贝构造函数会是内存复制(浅层拷贝)，就像下面这样
    //  : m_Buffer(other.m_Buffer), m_Size(other.m_Size)
    // memcpy(this, &other, sizeof(String));
    String(const String &other)
        : m_Size(other.m_Size)
    {
        std::cout << "Copied String!" << std::endl;
        
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }

    char &operator[](unsigned int index)
    {
        return m_Buffer[index];
    }

    friend std::ostream &operator<<(std::ostream &stream, const String &string);
};

std::ostream &operator<<(std::ostream &stream, const String &string)
{
    stream << string.m_Buffer;
    return stream;
}

void PrintString(const String& string)
{
    std::cout << string << std::endl;
}

int main()
{
    String string = "Cherno";
    String second = string;
    second[2] = 'a'; // they are both "Charno" before we edit copy constructor

    PrintString(string);
    PrintString(second); // 在终端可以看到我们得到了三个string的复制

    // std::cout << string << std::endl;
    // std::cout << second << std::endl;
    // free(): double free detected in tcache 2
    // Aborted
    // 这时会出现如上错误，原因是复制的时候m_Buffer内存地址对于这两个String对象来说是一样的
    // 一个方便的解决方法是拷贝构造函数，当复制这个String时，它就会被调用
    // 拷贝出来的对象会与原变量具有相同的类型

    std::cin.get();
}