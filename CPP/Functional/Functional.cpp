// Functional.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <functional>

void Print()
{
	std::cout << "Function Run" << std::endl;
}

void Print(int n)
{
	std::cout << "Parameter Function Run : " << n << std::endl;
}

struct FunctionObject
{
	void operator()()
	{
		std::cout << "Test Function Object" << std::endl;
	}
};

class Test
{
public:
	Test(int _Num = 0)
		: Num(_Num)
	{

	}

	void GetNum() const
	{
		std::cout << "Member Function Run : " << Num << std::endl;
	}

	void SetNum(int _Num)
	{
		std::cout << "Before Setting Num : " << Num << std::endl;
		Num = _Num;
		std::cout << "After Setting Num : " << Num << std::endl;
	}

private:
	int Num;
};

int Sub(int _Num1, int _Num2)
{
	return _Num1 - _Num2;
}

int main()
{
	// 오버라이드 함수
	std::function<void()> F1 = static_cast<void(*)()>(Print);
	F1();

	// 오버라이드 함수
	std::function<void(int)> F2 = static_cast<void(*)(int)>(Print);
	F2(3);

	// 함수 객체
	std::function<void()> F3 = FunctionObject();
	F3();

	// 람다 함수
	std::function<void()> LambdaF = []()
		{
			std::cout << "Lambda Function" << std::endl;
		};

	LambdaF();

	// 멤버 함수
	Test NewTest = Test();

	std::function<void(Test&, int)> MemberF_S = &Test::SetNum;
	MemberF_S(NewTest, 3);

	std::function<void(Test&)> MemberF_G = &Test::GetNum;
	MemberF_G(NewTest);

	// bind 사용 --------------------------------------------------------------------------------------------------------------

	std::function<int(int, int)> BindF1 = std::bind(Sub, std::placeholders::_1, std::placeholders::_2);
	int a = 5;
	int b = 3;
	std::cout << "BindF1 " << a << " - " << b << " = " << BindF1(a, b) << std::endl;

	std::function<int(int, int)> BindF1Reverse = std::bind(Sub, std::placeholders::_2, std::placeholders::_1);
	std::cout << "BindF1Reverse " << a << " - " << b << " = " << BindF1Reverse(a, b) << std::endl;
}
