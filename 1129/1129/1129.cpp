// 1129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <map>

int main()
{
	int TotalCount;				// 갑옷을 만드는데 필요한 수
	int MatertialCount;			// 총 재료의 개수
	int MatertialNumber[15001];	// 재료의 번호

	int Result = 0;


	std::cin >> MatertialCount >> TotalCount;

	for (int i = 0; i < MatertialCount; ++i)
	{
		std::cin >> MatertialNumber[i];
	}

	for (int i = 0; i < MatertialCount; ++i)
	{

		for (int j = i + 1; j < MatertialCount; ++j)
		{
			if (MatertialNumber[i] + MatertialNumber[j] == TotalCount)
			{
				Result += 1;
			}
		}
	}

	std::cout << Result;

}
