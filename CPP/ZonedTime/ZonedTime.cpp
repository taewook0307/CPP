// ZonedTime.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <chrono>

int main()
{
    //포맷을 사용해서 출력 가능
    std::chrono::zoned_time zt{ std::chrono::current_zone(), std::chrono::system_clock::now() };

    std::cout << std::format("{:%Y.%m.%d %A %H:%M:%S}", zt) << std::endl;

    //연도 월 날짜 등을 지원하는 클래스
    const std::chrono::time_point now{ std::chrono::system_clock::now() };
    const std::chrono::year_month_day ymd{ std::chrono::floor<std::chrono::days>(now) };

    std::cout << "Current Year: " << static_cast<int>(ymd.year()) << " Month: " << static_cast<unsigned>(ymd.month()) << " Day: " << static_cast<unsigned>(ymd.day()) << "\n" << "ymd: " << ymd << '\n';

    return 0;
}
