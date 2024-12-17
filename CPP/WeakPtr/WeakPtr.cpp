// WeakPtr.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

class Actor
{
public:
    Actor()
    {
        std::cout << "Actor Constructor" << std::endl;
    }

    virtual ~Actor()
    {
        std::cout << "Actor Destructor" << std::endl;
    }

    void Attack(std::weak_ptr<Actor> _Other)
    {
        if (std::shared_ptr<Actor> Ptr = _Other.lock())
        {
            std::cout << this->Name + "이 " + Ptr->Name + "을 공격" << std::endl;
        }
        else
        {
            std::cout << "타겟이 이미 지워졌습니다" << std::endl;
        }
    }

    std::string Name = "";
};

class Warrior : public Actor
{
public:
    Warrior()
    {
        std::cout << "Warrior Constructor" << std::endl;
        Name = "Warrior";
    }

    ~Warrior()
    {
        std::cout << "Warrior Destructor" << std::endl;
    }
};

class Monster : public Actor
{
public:
    Monster()
    {
        std::cout << "Monster Constructor" << std::endl;
        Name = "Monster";
    }

    ~Monster()
    {
        std::cout << "Monster Destructor" << std::endl;
    }
};

int main()
{
    std::shared_ptr<Actor> Player = std::make_shared<Warrior>();
    std::shared_ptr<Actor> Devil = std::make_shared<Monster>();
    std::weak_ptr<Actor> DevilWeak = Devil;

    Player->Attack(DevilWeak);
    Player->Attack(DevilWeak);
}
