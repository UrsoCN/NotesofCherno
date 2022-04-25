// 【84】【Cherno C++】【中字】跟踪内存分配的简单方法

// 重载new、free操作符之后就能方便地跟踪内存分配了(加断点)

#include <iostream>
#include <memory>

struct AllocationMetrics
{
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;

    uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};

static AllocationMetrics s_AllocationMetrics;

void *operator new(size_t size)
{
    s_AllocationMetrics.TotalAllocated += size;
    // std::cout << "Allocate " << size << " bytes.\n";
    return malloc(size);
}

void operator delete(void *memory, size_t size)
{
    s_AllocationMetrics.TotalFreed += size;
    // std::cout << "Free " << size << " bytes.\n";
    free(memory);
}

struct Object
{
    int x, y, z;
};

static void PrintMemoryUsage()
{
    std::cout << "Memory Usage:" << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}

int main()
{
    PrintMemoryUsage();
    {
        std::unique_ptr<Object> obj = std::make_unique<Object>();
        PrintMemoryUsage();
    }

    PrintMemoryUsage();
    Object *obj = new Object;
    PrintMemoryUsage();
    delete obj;
    PrintMemoryUsage();
    std::string string = "Cherno";
    PrintMemoryUsage();

    return 0;
}