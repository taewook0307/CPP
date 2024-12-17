// Span.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <span>
#include <numeric>
#include <list>

template <typename T>
void print(const std::span<T>& _DataContainer)
{
    for (const T& Data : _DataContainer)
    {
        std::cout << Data << " ";
    }

    std::cout << std::endl;
}

int main()
{
    std::vector<int> vecNums{ 1,2,3 };
    std::array<int, 3> arrStrs{ 4,5,6 };
    int arrNums[] = { 7,8,9 };
    std::string str = "Hello World!";

    print(std::span<int>(vecNums));
    print(std::span<int>(arrStrs));
    print(std::span<int>(arrNums, 2));
    print(std::span<char>(str));

    std::list<int> TestList;
    for (int i = 0; i < 10; ++i)
    {
        TestList.push_back(0);
    }
    std::iota(TestList.begin(), TestList.end(), 1);

    for (int Num : TestList)
    {
        std::cout << Num << std::endl;
    }
}
