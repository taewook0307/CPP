// String.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

int main()
{
	std::string S1 = "Hello World";

	std::cout << "S1 Size : " << S1.size() << std::endl;
	std::cout << "S1 Length : " << S1.length() << std::endl;
	std::cout << "S1 Capacity : " << S1.capacity() << std::endl << std::endl;

	S1.clear();

	std::cout << "S1 Clear 후" << std::endl;
	std::cout << "S1 Size : " << S1.size() << std::endl;
	std::cout << "S1 Length : " << S1.length() << std::endl;
	std::cout << "S1 Capacity : " << S1.capacity() << std::endl << std::endl;

	S1 = "Hello World";
	S1.erase();

	std::cout << "S1 Erase 후" << std::endl;
	std::cout << "S1 Size : " << S1.size() << std::endl;
	std::cout << "S1 Length : " << S1.length() << std::endl;
	std::cout << "S1 Capacity : " << S1.capacity() << std::endl << std::endl;

	S1 = "Hello World";
	int Index = S1.find('o');
	int FirstIndex = S1.find_first_of('o');
	int LastIndex = S1.find_last_of('o');
	int FirstNotIndex = S1.find_first_not_of('o');			// 해당 문자를 제외한 첫번째 문자 : o를 제외한 첫번째 문자는 H 이므로 0
	int LastNotIndex = S1.find_last_not_of('o');			// 해당 문자를 제외한 뒤에서 첫번째 문자 : o를 제외한 뒤에서 첫번째 문자는 d 이므로 10

	std::cout << "S1 find o : " << Index << std::endl;
	std::cout << "S1 first find o : " << FirstIndex << std::endl;
	std::cout << "S1 last find o : " << LastIndex << std::endl;
	std::cout << "S1 first not find o : " << FirstNotIndex << std::endl;
	std::cout << "S1 last not find o : " << LastNotIndex << std::endl << std::endl;

	std::string S2 = "ABCDEFG";
	std::string S3 = S1;
	std::string S4 = "Input";

	std::cout << "S1 compare S2 : " << S1.compare(S2) << std::endl;
	std::cout << "S1 compare S3 : " << S1.compare(S3) << std::endl;
	std::cout << "S1 compare S4 : " << S1.compare(S4) << std::endl;
	std::cout << "S1 == S2 : " << (S1 == S2) << std::endl;
	std::cout << "S1 == S3 : " << (S1 == S3) << std::endl;
	std::cout << "S1 == S4 : " << (S1 == S4) << std::endl << std::endl;

	int Num = 1;
	std::string NumString;

	NumString += std::to_string(Num);
	NumString += "20";
	Num = std::stoi(NumString);

	std::cout << "Num : " << Num << std::endl;
	std::cout << "NumString : " << NumString << std::endl << std::endl;
}
