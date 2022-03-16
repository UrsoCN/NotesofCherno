// 【31】【Cherno C++】【中字】C++数组

// 当访问数组范围外的内存时，debug会返回Memory access violation
// release不会得到报错

// 如果想返回一个数组，这个数组是在函数中创建的，需要使用new关键字

// 在C++11中，有标准数组std::array，有边界检测，记录数组大小
// 对new来的数组用sizeof计算大小不可靠
// 一种解决方法是声明时使用
//     static const int size = 5; 
//   // static constexpr int size = 5;//constexpr限定了变量必须为静态
//     int example[size];

#include <iostream>
#include <array>

class Entity
{
    // int example[5];
    static const int exampleSize = 5;
    int example[exampleSize];
    // int *example = new int[5];  //这样写的话，example会得到new出来的数组的地址
                                //也就是所谓内存间接寻址(memory indirection)
                                //应当避免这种情况(在内存中跳跃影响性能)，直接在栈上创建数组
    std::array<int, 5> another;
    
    Entity()
    {
        for (int i = 0; i < exampleSize; i++)
            example[i] = 2;
        for (int i = 0; i < another.size(); i++)
            another[i] = 2;
    }
};

int main()
{
    int example[5];
    for (int i = 0; i < 5; i++)
        example[i] = 2;
    int count = sizeof(example) / sizeof(int);
    std::cout << count << std::endl;    //5


    // int *ptr = example; //example等价于指针
    //
    // for (int i = 0; i < 5; i++) //写成i <= 4性能会更差
    //     example[i] = 2;
    //
    // example[2] = 5;
    // *(ptr + 2) = 6; //同样可以操作数组
    // *(int*)((char*)ptr + 8) = 6; //与上行语句等价

    int *another = new int[5]; //与上文声明语句一样，只是生存期不同
                               //声明在栈上创建，在到达main的}时会销毁
                               //new在堆上创建，直到我们程序把它销毁之前，都处于活动状态
    for (int i = 0; i < 5; i++)
        another[i] = 2;
    int count1 = sizeof(another) / sizeof(int);
    std::cout << count1 << std::endl;   //2，因为在64位程序里，指针8字节，int4字节
    int count2 = sizeof(*another) / sizeof(int);
    std::cout << count2 << std::endl;   //1

    delete[] another;

    // for (int i = 0; i < 5; i++)
    //     std::cout << example[i] << std::endl;

    std::cin.get();
}