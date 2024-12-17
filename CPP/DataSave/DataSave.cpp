// DataSave.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*
Big Endian : 데이터 저장 시 큰 값이 메모리 주소가 작은 곳에 위치하는 방식

Little Endian : 데이터 저장 시 작은 값이 메모리 주소가 작은 곳에 위치하는 방식

*/

#include <iostream>

int main()
{
	int arr[2] = { 0,0 };

	arr[0] = 0b00000001000000100000001100000100;

	char* Ptr = reinterpret_cast<char*>(&arr[0]);

	++Ptr;
	std::cout << static_cast<int>(*Ptr) << std::endl;
	++Ptr;
	std::cout << static_cast<int>(*Ptr) << std::endl;
	++Ptr;
	std::cout << static_cast<int>(*Ptr) << std::endl;
}
