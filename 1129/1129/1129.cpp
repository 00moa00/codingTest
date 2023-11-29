// 1129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int n = 0;
	int Result = 0;


	std::cin >> n;
	int* nPtr = new int[n];

	for (int i = 0; i < n; i++)
	{
		std::cin >> nPtr[i];
	}

	int v = 0;
	std::cin >> v;
	int r = 0;

	for (int i = 0; i < n; i++)
	{
		if (nPtr[i] == v)
		{
			r++;
		}
	}

	std::cout << r;
}

