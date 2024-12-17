// Atomic.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

void worker(std::atomic<int>& _Counter)
{
    for (int i = 0; i < 10000; ++i)
    {
        _Counter++;
        _Counter += 2;
    }
}

int main()
{
    std::atomic<int> Counter(0);

    std::vector<std::thread> Workers;

    for (int i = 0; i < 5; ++i)
    {
        Workers.push_back(std::thread(worker, std::ref(Counter)));
    }

    for (int i = 0; i < 5; ++i)
    {
        Workers[i].join();
    }

    std::cout << "Counter 최종값 : " << Counter << std::endl;
}
