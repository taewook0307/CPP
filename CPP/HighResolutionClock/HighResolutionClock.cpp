// HighResolutionClock.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

int main()
{
    std::random_device RD;
    std::mt19937_64 gen(RD());

    std::uniform_int_distribution<> Dist(0, 1000);

    int Init = Dist(gen);

    for (int total = 1; total <= 100000; total *= 10)
    {
        std::vector<int> RandomNums;
        RandomNums.reserve(total);

        std::chrono::time_point<std::chrono::high_resolution_clock> Start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < total; ++i)
        {
            RandomNums.push_back(Dist(gen));
        }

        std::chrono::time_point<std::chrono::high_resolution_clock> End = std::chrono::high_resolution_clock::now();

        std::chrono::nanoseconds Term = End - Start;

        std::cout << std::setw(7) << total << "개 난수 생성 시 틱 횟수 : " << Term.count() << std::endl;
    }
}
