// MemoryOrderRelaxed.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <thread>
#include <atomic>


void t1(std::atomic<int>* a, std::atomic<int>* b)
{
    int x = a->load(std::memory_order_relaxed);  // x = a (읽기)
    b->store(1, std::memory_order_relaxed);      // b = 1 (쓰기)

    printf("x : %d \n", x);
}

void t2(std::atomic<int>* a, std::atomic<int>* b)
{
    a->store(1, std::memory_order_relaxed);      // a = 1 (쓰기)
    int y = b->load(std::memory_order_relaxed);  // y = b (읽기)

    printf("y : %d \n", y);
}

int main()
{
    std::vector<std::thread> threads;

    std::atomic<int> a(0);
    std::atomic<int> b(0);

    threads.push_back(std::thread(t1, &a, &b));
    threads.push_back(std::thread(t2, &a, &b));

    for (int i = 0; i < 2; i++)
    {
        threads[i].join();
    }
}
