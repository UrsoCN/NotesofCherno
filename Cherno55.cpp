// 【55】【Cherno C++】【中字】C++的宏

// 这节讲的主要是在C++中使用预处理器来"宏"化某些操作

#include <iostream>
#include <string>

#define WAIT std::cin.get()

#ifdef PR_DEBUG == 1
#define LOG(x) std::cout << x << std::endl
#elif defined(PR_RELEASE)
#define LOG(x)
#endif

#if 0

#define MAIN int main() \
{\
    std::cin.get();\
}

#endif

int main()
{
    LOG("Hello!");
    WAIT;
}