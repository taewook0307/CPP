// MemoryOrderAcquire_Release.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

void producer(std::atomic<bool>* is_ready, int* data)
{
    *data = 10;
    is_ready->store(true, std::memory_order_release);       // 해당 명령 이전의 모든 메모리 명령들이 해당 명령 이후로 재배치 되는 것을 금지 
}

void consumer(std::atomic<bool>* is_ready, int* data)
{
    while (!is_ready->load(std::memory_order_acquire)) {}   // 해당 명령 뒤에 오는 모든 메모리 명령들이 해당 명령 위로 재배치 되는 것을 금지

    std::cout << "Data : " << *data << std::endl;
}

int main()
{
    std::vector<std::thread> threads;

    std::atomic<bool> is_ready(false);
    int data = 0;

    threads.push_back(std::thread(producer, &is_ready, &data));
    threads.push_back(std::thread(consumer, &is_ready, &data));

    for (int i = 0; i < 2; i++)
    {
        threads[i].join();
    }
}
