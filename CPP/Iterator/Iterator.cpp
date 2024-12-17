// Iterator.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

template <typename T>
void PrintVector(const std::vector<T>& _Vec)
{
    for (typename std::vector<T>::const_iterator BeginIter = _Vec.begin(); BeginIter != _Vec.end(); ++BeginIter)
    {
        std::cout << *BeginIter << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> IntVec(3, 0);
    std::vector<char> CharVec(3, 'A');
    std::vector<float> FloatVec(3, 3.0f);

    PrintVector(IntVec);
    PrintVector(CharVec);
    PrintVector(FloatVec);
}
