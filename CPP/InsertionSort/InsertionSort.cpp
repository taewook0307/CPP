// InsertionSort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

void InsertionSort(std::vector<int>& _Vector)
{
    int SortIndex = 0;
    int CheckIndex = 1;

    const int VectorSize = static_cast<int>(_Vector.size());

    while (CheckIndex < VectorSize)
    {
        int CheckValue = _Vector[CheckIndex];
        int MoveIndex = CheckIndex;

        for (int i = SortIndex; i >= 0; --i)
        {
            if (CheckValue < _Vector[i])
            {
                int Temp = _Vector[i];
                _Vector[i] = _Vector[MoveIndex];
                _Vector[MoveIndex] = Temp;

                --MoveIndex;
            }
        }

        ++SortIndex;
        ++CheckIndex;
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

    InsertionSort(IntVec);

    printf_s("Sort : ");
    for (int Num : IntVec)
    {
        printf_s("%d ", Num);
    }
    printf_s("\n");
}
