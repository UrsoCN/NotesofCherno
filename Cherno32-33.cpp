// 【32】【Cherno C++】【中字】C++字符串
// 【33】【Cherno C++】【中字】C++字符串字面量

// 字符串字面量永远保存在内存的只读区域内

#include <iostream>
#include <string>

#include <stdlib.h> //要注意这个是C的标准库
#include <cstring>

void PrintString(const std::string &string) //&表示是一个引用，const表示我们不会在这里修改原string
{
    // string += "h";
    std::cout << string << std::endl;
}

int main()
{
    // const char *name = "Cherno"; // C++11不可以将const char[] 转换成 char *
    // char name2[6] = {'C', 'h', 'e', 'r', 'n', 'o'};
    // char name3[7] = {'C', 'h', 'e', 'r', 'n', 'o', '\0'}; //'\0'可以直接写为0

    // std::cout << name << std::endl;
    // std::cout << name2 << std::endl;
    // std::cout << name3 << std::endl;

    // std::string name = "Cherno";
    // std::cout << name << std::endl;

    // std::string name2 = "Cherno";                         // + "hello!";不能直接用+操作符，因为是两个const char*
    // name2 += "hello!";                                    //将指针加到了name(std::string)，std::string重载了+=操作符
    // std::string name2 = std::string("Cherno") + "hello!"; //也就是这样

    //···········································································//

    const char name[8] = u8"Che\0rno";  //这就是一个字符串字面量，默认是一个(const char [7])"Cherno"
                                        //u8也就是utf-8
    std::cout << strlen(name) << std::endl; //3
// 在C++11之前，有char和 wchar_t ，因此专攻 std::basic_string<>至 std::string和 std::wstring
// 但是，wchar_t 的位宽特定于平台:在 Windows 上是 16 位，而在其他平台上是 32 位。
// 随着 C++11 的出现，标准 adds char16_t表示 16 位宽字符；
// 因此在 Windows 上，std::u16string恰好可以与 std::wstring 互换在大多数情况下，因为它们都能够表示 16 位宽字符。
    const wchar_t *name4 = L"Cherno"; //需要在前面加一个L("const char *" 类型的值不能用于初始化 "const wchar_t *" 类型的实体)
    const char16_t *name5 = u"Cherno";
    const char32_t *name6 = U"Cherno";

    using namespace std::string_literals; //C++14，给出了一些方便的字符串函数。
    std::string name0 = "Cherno"s + "hello!"; //s是一个函数，inline std::string std::literals::string_literals::operator ""s(const char *__str, std::size_t __len)

    const char* example = R"(Line1  
        Line2
        Line3
     )"; //R忽略转义字符

    const char *ex = "Line1\n"
    "Line2\n"
    "Line3\n";

    std::cin.get();
}