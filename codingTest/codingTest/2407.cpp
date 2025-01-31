#include <iostream>
#include <vector>
using namespace std;

int n , m =0;
int ret = 0;

void combi(int start, vector<int>& b)
{
	if (b.size() == m)
	{
		++ret;
		return;
	}

	for (int i = start + 1; i < n; ++i)
	{
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}

	return;
}

int main()
{
	cin >> n >> m;

	vector<int> b;
	combi(-1, b);
	cout << ret;
}