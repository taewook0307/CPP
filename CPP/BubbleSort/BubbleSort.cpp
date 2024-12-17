// BubbleSort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

void BubbleSort(std::vector<int>& _Vector)
{
    const int VectorSize = static_cast<int>(_Vector.size());
    int Count = 0;

    while (Count < VectorSize)
    {
        for (int i = 0; i < VectorSize - (1 + Count); ++i)
        {
            int FirstValue = _Vector[i];
            int SecondValue = _Vector[i + 1];

            if (FirstValue > SecondValue)
            {
                _Vector[i + 1] = FirstValue;
                _Vector[i] = SecondValue;
            }
        }

        ++Count;
    }
}

int main()
{
    std::vector<int> IntVec = { 3, 44, 38, 5, 47, 15, 36, 26 };

    printf_s("Not Sort : ");
    for (int Num : IntVec)
    {
        printf_s("%d ", Num);
    }
    printf_s("\n");

    BubbleSort(IntVec);

    printf_s("Sort : ");
    for (int Num : IntVec)
    {
        printf_s("%d ", Num);
    }
    printf_s("\n");
}
