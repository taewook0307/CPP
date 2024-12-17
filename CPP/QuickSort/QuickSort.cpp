// QuickSort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

void QuickSort(std::vector<int>& arr, int first, int last)
{
	if (first >= last) return;

	int Pivot = first;
	int Low = first + 1;
	int High = last;
	int tmp;

	while (Low <= High)
	{
		while (Low <= last && arr[Low] < arr[Pivot])
		{
			++Low;
		}

		while (High > first && arr[High] >= arr[Pivot])
		{
			--High;
		}

		if (Low >= High)
		{
			break;
		}

		std::swap(arr[Low], arr[High]);
	}

	std::swap(arr[Pivot], arr[High]);

	QuickSort(arr, first, High - 1);
	QuickSort(arr, High + 1, last);
}

int main()
{
	std::vector<int> SortVector = { 3, 7, 9, 4, 6, 5, 1, 2 };

	QuickSort(SortVector, 0, SortVector.size() - 1);

	for (int Num : SortVector)
	{
		std::cout << Num << " ";
	}
	std::cout << std::endl;
}
