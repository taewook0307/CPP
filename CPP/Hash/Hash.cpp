// Hash.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>

class A
{
    friend struct std::hash<A>;

public:
    A(int _Num = 0)
        :Num(_Num)
    {

    }

    void PrintNum() const
    {
        std::cout << Num << std::endl;
    }

    bool operator==(const A& t) const
    {
        return Num == t.Num;
    }

private:
    int Num;
};

namespace std
{
    template<>
    struct hash<A>
    {
        size_t operator()(const A& _A) const
        {
            hash<int> hash_func;
            return hash_func(_A.Num);
        }
    };
};

int main()
{
    std::unordered_set<A> MyClassSet;
    MyClassSet.insert(A(4));
    MyClassSet.insert(A(5));
    MyClassSet.insert(A(2));
    MyClassSet.insert(A(1));

    for (const A& CurA : MyClassSet)
    {
        CurA.PrintNum();
    }
}
