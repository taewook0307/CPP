// SystemClock.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

//int main()
//{
//    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
//    std::time_t t = std::chrono::system_clock::to_time_t(now);
//    std::cout << "현재 시간은 : " << std::put_time(std::localtime(&t), "%F %T %z") << '\n';
//}

int main()
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm tm_info;
    localtime_s(&tm_info, &t);
    std::cout << "현재 시간은 : " << std::put_time(&tm_info, "%F %T %z") << '\n';
}
