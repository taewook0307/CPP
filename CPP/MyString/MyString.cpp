// MyString.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <crtdbg.h>

class String
{
public:
    explicit String(int _Size)
    {
        Size = _Size;
        Data = new char[Size];
        std::cout << "Size : " << _Size << std::endl;
    }

    String(char c)
    {
        Size = 1;
        Data = new char[Size];
        Data[0] = c;
    }

    String(const char* _Data)
    {
        Size = static_cast<int>(strlen(_Data));
        Data = new char[Size];

        for (int i = 0; i < Size; ++i)
        {
            Data[i] = _Data[i];
        }
    }

    String(const String& _Other)
    {
        Size = _Other.Size;

        for (int i = 0; i < Size; ++i)
        {
            Data[i] = _Other.Data[i];
        }
    }

    ~String()
    {
        if (Data != nullptr)
        {
            delete[] Data;
            Data = nullptr;
        }
    }

    int GetSize() const
    {
        return Size;
    }

    String& Plus(const String& _Other)
    {
        int NewSize = Size + _Other.Size;
        char* PlusChar = new char[NewSize];

        for (int i = 0; i < Size; ++i)
        {
            PlusChar[i] = Data[i];
        }

        for (int i = Size; i < NewSize; ++i)
        {
            PlusChar[i] = _Other.Data[i - Size];
        }

        if (Data != nullptr)
        {
            delete[] Data;
        }

        Size = NewSize;
        Data = PlusChar;

        return *this;
    }

    bool Compare(const String& _Other) const
    {
        if (_Other.Size != Size)
        {
            return false;
        }

        for (int i = 0; i < Size; ++i)
        {
            if (_Other.Data[i] == Data[i])
            {
                return false;
            }
        }

        return true;
    }

    void Print() const
    {
        for (int i = 0; i < Size; ++i)
        {
            std::cout << Data[i];
        }
    }

    char PrintLoc(int _Loc) const
    {
        if (Size <= _Loc)
        {
            return NULL;
        }

        return Data[_Loc];
    }

private:
    char* Data;
    int Size = 0;
};

String DoSomething(String _String)
{
    _String.Print();
    return _String;
}

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    String S1 = "abc";
    String S2 = "def";

    S1.Plus(S2);

    S1.Print();
    std::cout << std::endl;

    DoSomething("random");
    std::cout << std::endl;
    String Test = DoSomething(String(3));         // 컴파일러에 의해 아예 코드 자체가 지워짐
}
