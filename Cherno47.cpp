// 【47】【Cherno C++】【中字】C++的动态数组（std::vector）

#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
    float x, y, z;
};

std::ostream &operator<<(std::ostream &stream, const Vertex &vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

int main()
{
    // Vertex与Vertex*有很大区别
    // 存储Vertex对象比Vertex*在技术上更优，调整大小时Vertex*更优
    std::vector<Vertex> vertices;
    vertices.push_back({1, 2, 3});
    vertices.push_back({4, 5, 6});

    for (int i = 0; i < vertices.size(); i++)
        std::cout << vertices[i] << std::endl;

    vertices.erase(vertices.begin() + 1);

    for (const Vertex &v : vertices)
        std::cout << v << std::endl;

    std::cin.get();
}
