// 1129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <map>

int main()
{
	std::map<int, int> mp;
	std:: vector<int> v{1,1,2,2,3,3};
	for (int i : v)
	{
		if (mp[i])
		{
			continue;
		}
		else
		{
			mp[i] = 1;
		}
	}

	std::vector<int> ret;
	for (auto it : mp)
	{
		ret.push_back(it.first);
	}
}

