// 【48】【Cherno C++】【中字】C++的stdvector使用优化

#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
    float x, y, z;

    Vertex(float x, float y, float z)
        : x(x), y(y), z(z) {}

    Vertex(const Vertex &vertex)
        : x(vertex.x), y(vertex.y), z(vertex.z)
    {
        std::cout << "Copied" << std::endl;
    }
};

int main()
{
    std::vector<Vertex> vertices;
    vertices.reserve(3);
    // 这样构造会先在main的栈帧里构造处Vertex，在将其push_back(复制)到vertices
    // 而默认的vertices的capacity为1，再push_back之后，需要重新构造一个足以容纳2个Vertex的vertices
    // 并将原vertices+push_back的Vertex复制到新的vertices
    // vertices.push_back(Vertex(1, 2, 3));
    // vertices.push_back(Vertex(4, 5, 6));
    // vertices.push_back(Vertex(7, 8, 9)); 
    vertices.emplace_back(1, 2, 3);
    vertices.emplace_back(4, 5, 6);
    vertices.emplace_back(7, 8, 9);

    // 在这样的两步优化之后，在终端可以观察到不再有copy了

    std::cin.get();
}