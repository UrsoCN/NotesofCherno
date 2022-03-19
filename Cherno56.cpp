// 【56】【Cherno C++】【中字】C++的auto关键字

// 总结：有点用，别用

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::string GetName()
{
    return "Cherno";
}

// char* GetName()
// {
//     return "Cherno";
// }

class Device
{
};

class DeviceManager
{
private:
    std::unordered_map<std::string, std::vector<Device *>> m_Devices;

public:
    const std::unordered_map<std::string, std::vector<Device *>> &GetDevices() const
    {
        return m_Devices;
    }
};

int main()
{
    // auto a = 5L;
    // auto b = a;

    auto name = GetName();
    int namesize = name.size();

    std::vector<std::string> strings;
    strings.push_back("Apple");
    strings.push_back("Orange");

    // for (auto it = strings.begin(); it != strings.end(); it++)
    for (std::vector<std::string>::iterator it = strings.begin();
         it != strings.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    DeviceManager dm;
    const std::unordered_map<std::string, std::vector<Device *>> &devices = dm.GetDevices();
    const auto &devices = dm.GetDevices();

    std::cin.get();
}