// 1129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

int main()
{
	int n;
	int Paper[100][100] = {0,};
	int count = 0;

	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		int cmdX, cmdY;
		std::cin >> cmdX >> cmdY;


		for (int a = cmdX; a < cmdX + 10; a++)
		{
			for (int b = cmdY; b < cmdY + 10; b++)
			{
				// 기존에 마킹된 부분인지 확인
				if (Paper[a][b] == 0)
				{
					Paper[a][b] = 1;
					count += 1;
				}
			}
		}
	}

	std::cout << count;

	return 0;
}
