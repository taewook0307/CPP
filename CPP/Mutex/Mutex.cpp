// Mutex.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

//void worker(int& counter)
//{
//    for (int i = 0; i < 10000; i++)
//    {
//        counter += 1;
//    }
//}

//void worker(int& result, std::mutex& m)
//{
//    for (int i = 0; i < 10000; i++)
//    {
//        m.lock();
//        result += 1;
//        m.unlock();
//    }
//}

void worker(int& result, std::mutex& m)
{
    for (int i = 0; i < 10000; i++)
    {
        std::lock_guard<std::mutex> lock(m);
        result += 1;
    }
}

int main()
{
    int counter = 0;
    std::mutex m;

    std::vector<std::thread> workers;

    for (int i = 0; i < 4; i++)
    {
        workers.push_back(std::thread(worker, std::ref(counter), std::ref(m)));
    }

    for (int i = 0; i < 4; i++)
    {
        workers[i].join();
    }

    std::cout << "Counter 최종 값 : " << counter << std::endl;
}
