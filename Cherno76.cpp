// 【76】【Cherno C++】【中字】如何处理OPTIONAL数据

// warning: structured bindings only available with ‘-std=c++17’ or ‘-std=gnu++17’
// 用g++编译时需要加上‘-std=c++17’ or ‘-std=gnu++17’

// std::optional同样是C++17的新特性，可以用来处理可能存在、也可能不存在的数据

#include <iostream>
#include <fstream>
#include <optional>

// std::string ReadFileAsString(const std::string &filepath, bool &outSuccess)
// {
//     std::ifstream stream(filepath);
//     if (stream)
//     {
//         std::string result;
//         // read file
//         stream.close();
//         outSuccess = true;
//         return result;
//     }

//     outSuccess = false;
//     return std::string();
// }

std::optional<std::string> ReadFileAsString(const std::string &filepath)
{
    std::ifstream stream(filepath);
    if (stream)
    {
        std::string result;
        // read file
        stream.close();
        return result;
    }

    return {};
}

int main()
{
    // bool fileOpenSuccessfully;
    // std::string data = ReadFileAsString("data.txt", fileOpenSuccessfully);

    // std::optional<std::string> data = ReadFileAsString("data.txt");
    auto data = ReadFileAsString("data.txt");

    std::string value = data.value_or("Not present");
    std::cout << value << std::endl;

    // if (data != "") // 这样写的话没法判断存在空的data.txt的情况
    // if (data.has_value())
    if (data)
    {
        std::cout << "File read successfully!" << std::endl;
    }
    else
    {
        std::cout << "File could not be opened!" << std::endl;
    }
}