// Variant.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <variant>
#include <string>

int main()
{
	std::variant<int, double, std::string> Test;

	size_t Size = sizeof(Test);
	std::cout << "Size = " << Size << std::endl;


	Test = 4.0;

	Size = sizeof(Test);
	std::cout << "Size = " << Size << std::endl;


	Test = "String";

	Size = sizeof(Test);
	std::cout << "Size = " << Size << std::endl;
}
