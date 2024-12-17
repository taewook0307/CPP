// StringView.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

void* operator new(std::size_t count)
{
	std::cout << count << " bytes 할당 " << std::endl;
	return malloc(count);
}

bool contains_very(const std::string& str)
{
	return str.find("very") != std::string::npos;
}

bool contains_very_view(std::string_view str)
{
	return str.find("very") != std::string::npos;
}

int main()
{
	std::cout << std::boolalpha << contains_very("c++ string is very easy to use") << std::endl;

	std::cout << contains_very("c++ string is not easy to use") << std::endl;

	std::cout << std::endl << "string_view 사용 --------------------------------------" << std::endl;

	std::cout << contains_very_view("c++ string is very easy to use") << std::endl;

	std::cout << contains_very_view("c++ string is not easy to use") << std::endl;
}
