#include <iostream>
#include <stack>

using namespace std;

int a[1000000] = { 0, };
int ret[1000000] = { -1, };


int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n = 0;
	cin >> n;


	stack<int> s;

	memset(ret, -1, sizeof(ret));

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];

		//내가 이전의 인덱스보다 크면 내가 오큰수
		while (s.empty() == false() && a[s.top()] < a[i])
		{
			//결과값이 정해졌으니 스택에서 제거해준다.
			ret[s.top()] = a[i];
			s.pop();
		}

		//아직 정해지지 않은 인덱스 저장
		s.push(i);
	}


	for (int i = 0; i < n; ++i)
	{
		cout << ret[i] << " ";
	}

	return 0;
}