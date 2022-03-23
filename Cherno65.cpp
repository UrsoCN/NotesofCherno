// 【65】【Cherno C++】【中字】C++的排序

// 聚焦在std::sort

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
    std::vector<int> values = {3, 5, 1, 4, 2};
    // std::sort(values.begin(), values.end(), std::greater<int>());
    std::sort(
        values.begin(), values.end(), [](int a, int b)
        { 
            if(a == 1)
                return false;
            if(b == 1)
                return true;
            // return a > b // a > b时返回true，也就是a排在前面
            return a < b; });

    for (int value : values)
    {
        std::cout << value << std::endl;
    }
}