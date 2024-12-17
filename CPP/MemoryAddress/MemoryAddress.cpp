// MemoryAddress.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

int main()
{
	//std::vector<int> IntVector(3, 0);

	//int* VecPtr0 = &IntVector[0];
	//__int64 VecPtr0Add = reinterpret_cast<__int64>(VecPtr0);

	//int* VecPtr1 = &IntVector[1];
	//__int64 VecPtr1Add = reinterpret_cast<__int64>(VecPtr1);

	//int* VecPtr2 = &IntVector[2];
	//__int64 VecPtr2Add = reinterpret_cast<__int64>(VecPtr2);

	//std::cout << "IntVector[0] Address : " << VecPtr0Add << std::endl;
	//std::cout << "IntVector[1] Address : " << VecPtr1Add << std::endl;
	//std::cout << "IntVector[2] Address : " << VecPtr2Add << std::endl;

	//std::deque<int> IntDeque(3, 0);

	//int* DeqPtrF = &(IntDeque.front());
	//__int64 DeqPtrFAdd = reinterpret_cast<__int64>(DeqPtrF);

	//int* DeqPtrB = &(IntDeque.back());
	//__int64 DeqPtrBAdd = reinterpret_cast<__int64>(DeqPtrB);

	//IntDeque.push_front(3);
	//int* NewFrontPtr = &(IntDeque.front());
	//__int64 NewPtrFAdd = reinterpret_cast<__int64>(NewFrontPtr);

	//IntDeque.push_back(0);
	//int* NewBackPtr = &(IntDeque.back());
	//__int64 NewPtrBAdd = reinterpret_cast<__int64>(NewBackPtr);

	//std::cout << "Deque Front Address     : " << DeqPtrFAdd << std::endl;
	//std::cout << "Deque Back Address      : " << DeqPtrBAdd << std::endl;
	//std::cout << "Deque new Front Address : " << NewPtrFAdd << std::endl;
	//std::cout << "Deque new Back Address  : " << NewPtrBAdd << std::endl;

	//IntDeque.push_front(2);
	//int* TwoFPtr = &(IntDeque.front());
	//__int64 TwoPtrFAdd = reinterpret_cast<__int64>(TwoFPtr);

	//IntDeque.push_front(2);
	//int* ThreeFPtr = &(IntDeque.front());
	//__int64 ThreePtrFAdd = reinterpret_cast<__int64>(ThreeFPtr);

	//std::cout << "Deque one push Front Address   : " << NewPtrFAdd << std::endl;
	//std::cout << "Deque two push Front Address   : " << TwoPtrFAdd << std::endl;
	//std::cout << "Deque three push Front Address : " << ThreePtrFAdd << std::endl;

	//size_t MaxSize = IntDeque.max_size();
	//std::cout << "deque max size : " << MaxSize << std::endl;

	std::deque<int> IntDeque(1, 0);

	int* DeqPtrB = &(IntDeque.back());
	__int64 DeqPtrBAdd = reinterpret_cast<__int64>(DeqPtrB);

	std::cout << "Start Deque Back Address     : " << DeqPtrBAdd << std::endl;

	for (int i = 0; i < 120; ++i)
	{
		IntDeque.push_back(0);
		int* NewDeqPtrB = &(IntDeque.back());
		__int64 NewDeqPtrBAdd = reinterpret_cast<__int64>(NewDeqPtrB);

		std::cout << i << " Push Deque Back Address : " << NewDeqPtrBAdd << std::endl;
	}
}
