// 【62】【Cherno C++】【中字】C++的线程
// 在Linux平台下编译时记得加上"-lpthread"链接库

#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork()
{
    using namespace std::literals::chrono_literals; // 为能正常使用'1s'添加的命名空间

    std::cout << "Started thread id = " << std::this_thread::get_id() << std::endl;

    while (!s_Finished)
    {
        std::cout << "working...\n";
        std::this_thread::sleep_for(1s);
    }
}

int main()
{
    std::cout << "Main thread id = " << std::this_thread::get_id() << std::endl;

    std::thread worker(DoWork);

    std::cin.get();
    s_Finished = true;

    worker.join(); // 在当前线程上等待这个线程(worker)完成
    std::cout << "Finished." << std::endl;

    std::cin.get();
}