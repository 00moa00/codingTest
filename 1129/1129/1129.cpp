// 1129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <stack>

int main()
{
	int keywordCount, result;
	std::string str;
	std::cin >> keywordCount;

	for (int i = 0; i < keywordCount; i++)
	{
		std::cin >> str;
		std::stack<char> stk;

		for (char a : str)
		{
			if (stk.size() && stk.top() == a)
			{
				stk.pop();
			}
			else
			{
				stk.push(a);
			}
		}
		if (stk.size() == 0)
		{
			result++;
		}
	}

	std::cout << result << "\n";

	return 0;
}
