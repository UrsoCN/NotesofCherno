// 【37】【Cherno C++】【中字】C++的三元操作符
// if语句的语法糖

#include <iostream>
#include <string>

static int s_Level = 1;
static int s_Speed = 2;

int main()
{
    // 嵌套三元操作符
    s_Speed = s_Level > 5 && s_Level < 100 ? s_Level > 10 ? 15 : 10 : 5;
    // 上面的应当像这样读
    s_Speed = (s_Level > 5 && s_Level < 100) ? (s_Level > 10 ? 15 : 10) : 5;
    /*-------------------------------------------------------*/
    if (s_Level > 5)
        s_Speed = 10;
    else
        s_Speed = 5;
    s_Speed = s_Level > 5 ? 10 : 5;                           //与上面等价
                                                              /*-------------------------------------------------------*/
    std::string rank = s_Level > 10 ? "Master" : "Begginner"; //因为返回值优化，不会有中间变量
    std::string otherRank;                                    //这样写代码从技术上讲更慢，会构造一个临时字符串，然后覆盖它
    if (s_Level > 10)
        otherRank = "Master";
    else
        otherRank = "Begginner";

    std::cin.get();
}