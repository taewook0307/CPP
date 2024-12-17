// Permutation.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> A;
    A.reserve(5);
    std::vector<int> B;
    B.reserve(5);

    A.push_back(5);
    A.push_back(4);
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);

    B.push_back(5);
    B.push_back(4);
    B.push_back(1);
    B.push_back(2);
    B.push_back(3);

    sort(B.begin(), B.end());

    do
    {
        for (int Num : A)
        {
            std::cout << Num << " ";
        }
        std::cout << std::endl;
    } while (true == std::next_permutation(A.begin(), A.end()));

    std::cout << std::endl;

    do
    {
        for (int Num : B)
        {
            std::cout << Num << " ";
        }
        std::cout << std::endl;
    } while (true == std::next_permutation(B.begin(), B.end()));

    std::cout << "Hello World!\n";
}
