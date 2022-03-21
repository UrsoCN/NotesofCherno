// 【64】【Cherno C++】【中字】C++多维数组

#include <iostream>
#include <array>

int main()
{

    // 要知道，这样处理数组的数组，会造成内存碎片的问题
    // 我们创建了5个单独的缓冲区，每个缓冲区有5个整数，他们会被分配到内存的随机(空闲)位置
    // 在大量调用时，很可能造成cache miss，损失性能

    int *array = new int[5];
    int **a2d = new int *[5]; // 5个int指针
    for (int i = 0; i < 5; i++)
        a2d[i] = new int[5]; // allocate the memory

    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            a2d[y][x] = 2;
        }
    }

    // int ***a3d = new int **[5]; // 5个int指针的指针
    // for (int i = 0; i < 5; i++)
    // {
    //     a3d[i] = new int *[5];
    //     for (int j = 0; j < 5; j++)
    //     {
    //         // int **ptr = a3d[i];
    //         // ptr[j] = new int[5];
    //         a3d[i][j] = new int[5];
    //     }
    // }

    for (int i = 0; i < 5; i++) // 需要先释放真正的多维数组
        delete[] a2d[i];
    delete[] a2d;
    // 这只会释放5个指针的内存，而后面分配的内存由于丢失掉了这些指针，
    // 也无法释放了，这就造成了内存泄漏

    int *array = new int[5 * 5];
    // for (int i = 0; i < 5 * 5; i++)
    // {
    //     array[i] = 2;
    // }
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            array[y * 5 + x] = 2;
        }
    }

    std::cin.get();
}