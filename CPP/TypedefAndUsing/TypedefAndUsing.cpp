// TypedefAndUsing.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

template <typename T>
class MyClass
{
public:
    MyClass()
        : a(0)
    {
        std::cout << "MyClass 생성자" << std::endl;
    }

    MyClass(T _Num)
        : a(_Num)
    {
        std::cout << "MyClass 생성자" << std::endl;
    }

    ~MyClass()
    {
        std::cout << "MyClass 소멸자" << std::endl;
    }

private:
    T a = 0;
};

//template <typename T>
//typedef MyClass<T> MCTD;

template <typename T>
using MCU = MyClass<T>;

int main()
{
    //MCTD* NewTD = new MCTD();

    MCU<int>* NewU = new MCU<int>();

    delete NewU;
    //delete NewTD;
}
