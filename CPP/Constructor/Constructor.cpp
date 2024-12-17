// Constructor.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

class Object
{
public:
    Object()
        : Hp(10)
    {
        std::cout << "Object Constructor" << std::endl;
    }

    Object(int _Value)
        : Hp(_Value)
    {
        std::cout << "Object Constructor" << std::endl;
    }

    ~Object()
    {
        std::cout << "Object Destructor" << std::endl;
    }

protected:
    int Hp = 10;
};

class Warrior : public Object
{
public:
    //Warrior(int _Hp, int _ATK)
    //    : Object(_Hp), ATK(_ATK)
    //{
    //    std::cout << "Warrior Constructor" << std::endl;
    //}

    ~Warrior()
    {
        std::cout << "Warrior Destructor" << std::endl;
    }

    void PrintStat() const
    {
        std::cout << "HP : " << Hp << std::endl;
        std::cout << "ATK : " << ATK << std::endl;
    }

private:
    int ATK = 2;

    static int WarriorNum;
};

int Warrior::WarriorNum = 0;

int main()
{
    Warrior* Player = new Warrior();
    Player->PrintStat();
}
