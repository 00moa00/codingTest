
#include <iostream>
#include <algorithm>
//#include <string>
#include <vector>
#include <string>

//#include <map>
//#include <unordered_map>
//#include <stack>
//#include <queue>
//#include <tuple>
//#include <cctype>

using namespace std;


int n, m; 
string s;
int a[104][104];


int main()
{
	cin >> n >> m; //n :y, m:x
	for (int i = 0; i < n; i++) {
		cin >> s;

		for (int j = 0; j < m; j++) {
			if (s[j] == '.')
			{
				//구름이 없당
				a[i][j] = -1;
			}
			else
			{
				//구름이 있었당
				a[i][j] = 0;
			}
		}
	}

	//구름을 이동시킨다
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			if (a[i][j] == 0) 
			{
				int cnt = 1;
				while (a[i][j + 1] == -1) 
				{
					a[i][j + 1] = cnt++;
					j++;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}