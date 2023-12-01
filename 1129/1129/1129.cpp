// 1129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <stack>

//구간합
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n = 0, k = 0, temp = 0, result = -1000000;
	int psum[100001] = {0,};

	std::cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		std::cin >> temp; 
		psum[i] = psum[i - 1] + temp;
	}

	for (int i = k; i <= n; i++) 
	{
		result = std::max(result, psum[i] - psum[i - k]);
	}

	std::cout << result << "\n";
	return 0;
}
