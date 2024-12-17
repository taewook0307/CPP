// TMP_Pratice_01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <type_traits>

template <typename T>
void GetType()
{
    if (std::is_void<T>::value)
    {
        std::cout << "T 는 void ! \n";
    }
    else
    {
        std::cout << "T 는 void 가 아니다. \n";
    }
}

int main()
{
    int a = 3;
    int b = 5;

    GetType<int>();
    GetType<void>();
}
