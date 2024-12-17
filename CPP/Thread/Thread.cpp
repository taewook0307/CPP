// Thread.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <vector>

void worker(std::vector<int>::iterator start, std::vector<int>::iterator end, int* result)
{
    int sum = 0;

    for (std::vector<int>::iterator itr = start; itr < end; ++itr)
    {
        sum += *itr;
    }

    *result = sum;

    std::thread::id this_id = std::this_thread::get_id();

    printf_s("쓰레드 %x 에서 %d 부터 %d 까지 계산한 결과 : %d \n", this_id, *start, *(end - 1), sum);

    //std::cout << "쓰레드 " << std::hex << this_id << " 에서 " << std::dec << *start << " 부터 " << *(end - 1) << " 까지 계산한 결과 : " << sum << std::endl;
}

int main()
{
    std::vector<int> data(10000);

    for (int i = 0; i < 10000; i++)
    {
        data[i] = i;
    }

    // 각 쓰레드에서 계산된 부분 합들을 저장하는 벡터
    std::vector<int> partial_sums(4);

    std::vector<std::thread> workers;

    for (int i = 0; i < 4; i++)
    {
        workers.push_back(std::thread(worker, data.begin() + i * 2500, data.begin() + (i + 1) * 2500, &partial_sums[i]));
    }

    for (int i = 0; i < 4; i++)
    {
        workers[i].join();
    }

    int total = 0;

    for (int i = 0; i < 4; i++)
    {
        total += partial_sums[i];
    }

    std::cout << "전체 합 : " << total << std::endl;
}
