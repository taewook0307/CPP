// DataType.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int main()
{
	std::cout << "char 크기 : " << sizeof(char) << std::endl;
	std::cout << "unsigned char 크기 : " << sizeof(unsigned char) << std::endl;
	std::cout << "short 크기 : " << sizeof(short) << std::endl;
	std::cout << "unsigned short 크기 : " << sizeof(unsigned short) << std::endl;
	std::cout << "int 크기 : " << sizeof(int) << std::endl;
	std::cout << "unsigned int 크기 : " << sizeof(unsigned int) << std::endl;
	std::cout << "long 크기 : " << sizeof(long) << std::endl;
	std::cout << "long long 크기 : " << sizeof(long long) << std::endl;
	std::cout << "float 크기 : " << sizeof(float) << std::endl;
	std::cout << "double 크기 : " << sizeof(double) << std::endl;
	std::cout << "long double 크기 : " << sizeof(long double) << std::endl;
}