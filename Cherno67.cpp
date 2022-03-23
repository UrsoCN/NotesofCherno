// 【67】【Cherno C++】【中字】C++的联合体

// 通常union是匿名使用的，但是匿名union不能含有成员函数
// union的语法与struct一致
// 在可以使用类型双关的时候，使用union时，可读性更强

#include <iostream>

struct Vector2
{
    float x, y;
};

struct Vector4
{
    union // 通常不写名称，作为匿名使用
    {
        struct
        {
            float x, y, z, w;
        };
        struct // 第二个Union成员，与第一个成员占用相同的空间
        {
            Vector2 a, b;
        };
    };

    // Vector2& GetA(){
    //     return *(Vector2*)&x; // 将x的内存地址转换成Vector2*，再通过类型双关解引用成Vector2
    // }
};

void PrintVector2(const Vector2 &vector)
{
    std::cout << vector.x << ", " << vector.y << std::endl;
}

int main()
{
    Vector4 vector = {1.0f, 2.0f, 3.0f, 4.0f};
    PrintVector2(vector.a);
    PrintVector2(vector.b);
    vector.z = 500;
    std::cout << "-----------------------" << std::endl;
    PrintVector2(vector.a);
    PrintVector2(vector.b);


    // struct Union
    // {
    //     union
    //     {
    //         float a;
    //         int b;
    //     };
    // };
    // Union u;
    // u.a = 2.0f;
    // std::cout << u.a << ", " << u.b << std::endl; // 2, 1073741824 // b将(float)2解释成int
}