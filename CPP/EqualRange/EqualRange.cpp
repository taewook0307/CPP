// EqualRange.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <map>

int main()
{
    std::multimap<int, int> Check;

    Check.insert(std::make_pair(1, 3));
    Check.insert(std::make_pair(1, 1));
    Check.insert(std::make_pair(1, 4));
    Check.insert(std::make_pair(1, 2));

    std::pair<std::multimap<int, int>::iterator, std::multimap<int, int>::iterator> EqualRange = Check.equal_range(1);

    std::multimap<int, int>::iterator BeginIter = EqualRange.first;
    std::multimap<int, int>::iterator EndIter = EqualRange.second;

    for (; BeginIter != EndIter; ++BeginIter)
    {
        std::cout << BeginIter->second << std::endl;
    }
}
