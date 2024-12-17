// RValueRef.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class A
{
public:
    A()
        : num(0)
    {
        std::cout << "기본 생성자" << std::endl;
    }

    A(const A& _Other)
        : num(_Other.num)
    {
        std::cout << "복사 생성자" << std::endl;
    }

    A(A&& _Value)
    {
        std::cout << "이동 생성자" << std::endl;
    }

private:
    int num;
};

int main()
{
    A a = A();
    A b = A(a);

    A c = A(std::move(b));
}
