// Random_mt19937.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <random>

int main()
{
	std::random_device rd;									// 시드값 생성을 위한 random_device 생성(컴퓨터의 주변환경과 무작위로 상호작용하면서 만들어지기 때문에 느림)
	// 초기화 할 때만 사용하고 이후에는 난수 엔진을 통해 생성하는 것이 좋음
	std::mt19937 gen(rd());									// random device를 이용해 난수 생성 엔진을 초기화

	std::uniform_int_distribution<int> dis(0, 99);			// 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "난수 : " << dis(gen) << std::endl;	// 균등 분포에 사용할 난수 엔진을 전달하는 것으로 균등 분포에서 무작위로 샘플 생성
	}
}
