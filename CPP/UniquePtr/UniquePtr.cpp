// UniquePtr.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class MyClass
{
public:
	MyClass()
	{
		std::cout << "MyClass Print Constructor" << std::endl;
	}

	~MyClass()
	{
		std::cout << "MyClass Print Destructor" << std::endl;
	}

	void Print()
	{
		std::cout << "MyClass Print Function" << std::endl;
	}
};

int main()
{
	std::unique_ptr<MyClass> UP = std::make_unique<MyClass>();
	UP->Print();

	// std::unique_ptr<MyClass> UP2 = UP;				// 컴파일 오류
	std::unique_ptr<MyClass> UP2 = std::move(UP);

	if (nullptr == UP)
	{
		std::cout << "UP is nullptr" << std::endl;
	}

	std::cout << "UP2 Print : ";
	UP2->Print();
}
