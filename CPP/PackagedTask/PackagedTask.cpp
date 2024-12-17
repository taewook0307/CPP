// PackagedTask.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <future>

int Worker(int _Num)
{
	return _Num + 10;
}

int main()
{
	std::packaged_task<int(int)> Task(Worker);

	std::future<int> F = Task.get_future();

	std::thread t(std::move(Task), 20);

	std::cout << "Result = " << F.get() << std::endl;

	t.join();
}
