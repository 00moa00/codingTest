// 1129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

int main()
{
	typedef long long ll;
	int n;

	//입력을 계속해서 받는다
	while (scanf("%d", &n) != EOF) 
	{
		int cnt = 1, ret = 1;

		while (true) 
		{
			if (cnt % n == 0) 
			{
				printf("%d\n", ret);
				break;
			}
			else 
			{
				cnt = (cnt * 10) + 1;
				cnt %= n;
				ret++;
			}
		}
	}

    return 0;
}
