#include <iostream>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n = 0;

	cin >> n;

	int a[10000001] = {0,};
	int ret[10000001] = { 0, };


	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}


	for (int i =0; i < n; ++i)
	{
		int min = -1;

		for (int j = (n - 1); j >= 0 + i; --j)
		{
			if (a[j] > a[i])
			{
				min = a[j];
			}
		}

		cout<<min;
	}

}