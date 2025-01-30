#include <iostream>

using namespace std;

int a[1000000] = { 0, };
int ret[1000000] = { 0, };


int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n = 0;
	cin >> n;


	for (int i = n-1; i >= 0; --i)
	{
		cin >> a[i];
	}

	for (int i = n - 1; i >= 0; --i)
	{
		int min = -1;

		for (int j = i; j >= 0; --j)
		{
			if (a[j] > a[i])
			{
				min = a[j];
				break;
			}
		}

		cout<<min;
	}

	return 0;
}