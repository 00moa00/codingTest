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

		//���� ������ �ε������� ũ�� ���� ��ū��
		while (s.empty() == false() && a[s.top()] < a[i])
		{
			//������� ���������� ���ÿ��� �������ش�.
			ret[s.top()] = a[i];
			s.pop();
		}

		//���� �������� ���� �ε��� ����
		s.push(i);
	}


	for (int i = 0; i < n; ++i)
	{
		cout << ret[i] << " ";
	}

	return 0;
}