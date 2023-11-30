// 1129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<algorithm>
#include <vector>


using namespace std;
int a[9], sum;
std::vector<int> v;
pair<int, int> ret;

void solve()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (sum - a[i] - a[j] == 100)
			{
				ret = { i, j };
				return;
			}
		}
	}
}

int main() 
{

	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		sum += a[i];
	}
	solve();
	for (int i = 0; i < 9; i++) 
	{
		if (ret.first == i || ret.second == i) continue;
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	return 0;
}