// PromiseFuture.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <thread>
#include <future>

void Worker(std::promise<std::string>& _PromiseRef)
{
	_PromiseRef.set_value("Data");
}

int main()
{
	std::promise<std::string> P;

	std::future<std::string> F = P.get_future();

	std::thread T(Worker, std::ref(P));

	F.wait();

	// get 사용 후 해당 객체는 이동을 수행하게 되므로 다시 get을 호출하면 오류
	std::cout << "FutureData : " << F.get() << std::endl;

	if (false == F.valid())
	{
		std::cout << "Future is empty" << std::endl;
	}

	T.join();
}
