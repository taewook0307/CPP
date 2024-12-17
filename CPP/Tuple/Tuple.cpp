// Tuple.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <tuple>

struct Test
{
	std::string c = "Test";
	double b = 5.0;
	int a = 3;
};

int main()
{
	std::tuple<int, double, std::string> PersonInfo;
	PersonInfo = std::make_tuple(182, 72.5, "Shun");

	std::cout << std::get<2>(PersonInfo) << "의 키 : " << std::get<0>(PersonInfo) << ", 몸무게 : " << std::get<1>(PersonInfo) << std::endl;

	auto& [Height, Weight, Name] = PersonInfo;

	std::cout << Name << "의 키 : " << Height << ", 몸무게 : " << Weight << std::endl;

	Test StructTest;

	auto& [StructS, StructB, StructA] = StructTest;

	std::cout << "StructS : " << StructS << " StructB : " << StructB << " StructA : " << StructA << std::endl;
}
