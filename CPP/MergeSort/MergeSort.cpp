// MergeSort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

void Merge(std::vector<int>& _Vector, int _First, int _Middle, int _Last)
{
	std::vector<int> PartVector(_Last - _First + 1);

	int i = _First;
	int j = _Middle + 1;
	int k = 0;

	while (i <= _Middle && j <= _Last)
	{
		if (_Vector[i] <= _Vector[j])
		{
			PartVector[k++] = _Vector[i++];
		}
		else
		{
			PartVector[k++] = _Vector[j++];
		}
	}

	if (i > _Middle)
	{
		while (j <= _Last)
		{
			PartVector[k++] = _Vector[j++];
		}
	}
	else
	{
		while (i <= _Middle)
		{
			PartVector[k++] = _Vector[i++];
		}
	}

	for (i = _First, k = 0; i <= _Last; i++, k++)
	{
		_Vector[i] = PartVector[k];
	}
}

void MergeSort(std::vector<int>& _Vector, int _First, int _Last)
{
	if (_First < _Last)
	{
		int Middle = (_First + _Last) / 2;

		MergeSort(_Vector, _First, Middle);
		MergeSort(_Vector, Middle + 1, _Last);
		Merge(_Vector, _First, Middle, _Last);
	}
}

int main()
{
	std::vector<int> Vector = { 7, 3, 5, 8, 9, 1, 23, 6, 43, 23, 24, 50, 39 };

	const int VectorSize = static_cast<int>(Vector.size());

	MergeSort(Vector, 0, VectorSize - 1);

	for (int i = 0; i < VectorSize; ++i)
	{
		std::cout << Vector[i] << std::endl;
	}
}
