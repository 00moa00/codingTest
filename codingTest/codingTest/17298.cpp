#include <iostream>
#include <stack>

using namespace std;

int a[1000000] = { 0, };
int ret[1000000] = { 0, };


int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n = 0;
	cin >> n;


	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	stack<int> s;

	for (int i = n - 1; i >= 0; --i)
	{
		//현재값보다 작은 수 삭제.
		//현재값을 어차피 넣을거고, 현재값(가장 왼쪽)보다 작은 값들은 오큰수에서 의미가 없음. 
		while (s.empty() == false && s.top() <= a[i])
		{
			s.pop();
		}
		
		if (s.empty() == true)
		{
			ret[i] = - 1;
		}

		else
		{
			ret[i] = s.top();
		}

		s.push(a[i]);
	}


	for (int i = 0; i < n; ++i)
	{
		cout << ret[i] << " ";
	}

	return 0;
}