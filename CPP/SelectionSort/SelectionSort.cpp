// SelectionSort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

void SelectionSort(std::vector<int>& _Value)
{
    int SortIndex = 0;
    int MinValue = _Value[0];
    int MinValueIndex = 0;

    const size_t VectorSize = _Value.size();

    while (SortIndex != VectorSize - 1)
    {
        // 가장 작은 값 찾기
        for (size_t i = SortIndex; i < VectorSize; i++)
        {
            if (MinValue > _Value[i])
            {
                MinValue = _Value[i];
                MinValueIndex = i;
            }
        }

        // 작은 값과 위치 변경
        int Temp = _Value[SortIndex];
        _Value[SortIndex] = _Value[MinValueIndex];
        _Value[MinValueIndex] = Temp;

        ++SortIndex;
        MinValue = _Value[SortIndex];
        MinValueIndex = SortIndex;
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

    SelectionSort(IntVec);

    printf_s("Sort : ");
    for (int Num : IntVec)
    {
        printf_s("%d ", Num);
    }
    printf_s("\n");
}
