// Memory Padding.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class A
{
    char e;
    char d;
    short c;
    int b;
    int a;
};

class B
{
    int a;
    int b;
    short c;
    char d;
    char e;
};

class C
{
    int a;
    char b;
    short c;
    int d;
    char e;
};

class D
{
    int b;
    double a;
    int c;
};

class E
{
    int b;
    int c;
    double a;
};

class F
{
    int a;
    char b;
};

class G
{
    unsigned __int32 muint32; // (4/8) 1번패킹
    float mfloat; // (8/8) 1번패킹
    __int8 mint8; // (1/8) 2번패킹
    __int8 mpad[3]; // (4/8) 2번패킹 낭비 패딩이 3byte
    __int32 mint32; // (8/8) 2번패킹
    bool mbool; // (1/8) // 3번패킹
    __int8 mpad2[7]; // (8/8) 3번패킹 낭비 패딩이 7byte
    char* mcharpointer; // (8/8) 4번패킹
};

class H
{
    unsigned __int32 muint32; // (4/8) 1번패킹
    float mfloat; // (8/8) 1번패킹
    __int8 mint8; // (1/8) 2번패킹
    bool mbool; // (2/8) // 2번패킹
    __int8 mpad[2]; // (4/8) 2번패킹 낭비 패딩이 2byte
    __int32 mint32; // (8/8) 2번패킹
    char* mcharpointer; // (8/8) 3번패킹
};

class I
{
    char* mcharpointer;         // 8바이트
    unsigned __int32 muint32;   // 4바이트
    float mfloat;               // 4바이트
    __int32 mint32;             // 4바이트
    __int8 mint8;               // 1바이트
    __int8 mbool;               // 1바이트
    __int8 mpad[2];             // 2바이트
};

int main()
{
    size_t ASize = sizeof(A);
    size_t BSize = sizeof(B);
    size_t CSize = sizeof(C);
    size_t DSize = sizeof(D);
    size_t ESize = sizeof(E);
    size_t FSize = sizeof(F);
    size_t GSize = sizeof(G);
    size_t HSize = sizeof(H);
    size_t ISize = sizeof(I);

    std::cout << "ASize = " << ASize << std::endl;      // 12
    std::cout << "BSize = " << BSize << std::endl;      // 12
    std::cout << "CSize = " << CSize << std::endl;      // 16
    std::cout << "DSize = " << DSize << std::endl;      // 24
    std::cout << "ESize = " << ESize << std::endl;      // 16
    std::cout << "FSize = " << FSize << std::endl;      // 8
    std::cout << "GSize = " << GSize << std::endl;      // 32
    std::cout << "HSize = " << HSize << std::endl;      // 24
    std::cout << "ISize = " << ISize << std::endl;      // 24
}
