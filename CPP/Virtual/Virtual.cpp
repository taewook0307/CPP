// Virtual.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Object
{
public:
    Object()
    {
        std::cout << "Object 생성자" << std::endl;
    }

    virtual ~Object()
    {
        std::cout << "Object 소멸자" << std::endl;
    }
};

class Actor : public Object
{
public:
    Actor()
    {
        std::cout << "Actor 생성자" << std::endl;
    }

    ~Actor()
    {
        std::cout << "Actor 소멸자" << std::endl;
    }
};

class Level : public Object
{
public:
    Level()
    {
        std::cout << "Level 생성자" << std::endl;
    }

    ~Level()
    {
        std::cout << "Level 소멸자" << std::endl;
    }
};

class Warrior : public Actor
{
public:
    Warrior()
    {
        std::cout << "Warrior 생성자" << std::endl;
    }

    ~Warrior()
    {
        std::cout << "Warrior 소멸자" << std::endl;
    }
};

class FirstLevel : public Level
{
public:
    FirstLevel()
    {
        std::cout << "FirstLevel 생성자" << std::endl;
    }

    ~FirstLevel()
    {
        std::cout << "FirstLevel 소멸자" << std::endl;
    }
};

int main()
{
    //Actor TestActor = Actor();
    Object* NewActor = new Actor();
    delete NewActor;
}
