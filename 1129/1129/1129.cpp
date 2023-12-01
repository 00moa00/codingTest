// 1129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <map>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n; // 도감에 수록되어있는 포켓몬 수
	int m; // 맞춰야하는 포켓몬 수

	std::string str;
	std::map<std::string, int> SI_Map;
	std::map<int, std::string> IS_Map;


	std::cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		std::cin >> str;
		IS_Map[i + 1] = str;
		SI_Map[str] = i + 1;

	}

	for (int i = 0; i < m; i++)
	{
		std::cin >> str;

		//문자열에서 인트로 변환이 되지 않는다면
		if (atoi(str.c_str()) == 0)
		{
			std::cout << SI_Map[str] << "\n";
		}
		else
		{
			std::cout << IS_Map[atoi(str.c_str())] << "\n";
		}

	}
}
