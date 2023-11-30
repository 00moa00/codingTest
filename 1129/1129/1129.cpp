// 1129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>

int main()
{
	int n; //파일의 개수
	std::string search;

	std::cin >> n;
	std::cin >> search;
	int pos = search.find('*');

	std::string prefix = search.substr(0, pos);
	std::string suffix = search.substr(pos + 1);

	std::string str;
	for (int i = 0; i < n; i++)
	{
		std::cin >> str;

		//비교 문자열이 주어진 문자열보다 클 때. 비교부터 안된다
		if (prefix.size() + suffix.size() > str.size())
		{
			std::cout << "NE\n";
		}
		else
		{
			if (prefix == str.substr(0, prefix.size())
				&& suffix == str.substr(str.size() - suffix.size()))
			{
				std::cout << "DA\n";
			}
			else
			{
				std::cout << "NE\n";
			}
		}

	}
	return 0;
}
