#include <vector>
#include <iostream>

using namespace std;


int main()
{
	int k = 0;
	int n = 0;

	vector<int> female ( 7,0 );
	vector<int> male  ( 7,0 );

	cin >> k >> n;

	for (int i = 0; i < k; ++i)
	{
		int s = 0;
		int y = 0;
		cin >> s >> y;

		//여학생이라면
		if (s == 0)
		{
			female[y] += 1;
		}

		else
		{
			male[y] += 1;
		}
	}

	int ret = 0;

	for (auto& f : female)
	{
		ret += f / n;
		if (f % n != 0)
		{
			ret += 1;
		}
	}


	for (auto& m : male)
	{
		ret += m / n;
		if (m % n != 0)
		{
			ret += 1;
		}
	}

	cout << ret;
}