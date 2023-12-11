
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string>
#include <sstream>

//#include <map>
//#include <unordered_map>
//#include <stack>
//#include <queue>
//#include <tuple>
//#include <cctype>
//#include <istream>
using namespace std;

//typedef unsigned long long ll;
int n; 



int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	int cnt = 666;
	while (true)
	{
		if (to_string(cnt).find("666") != string::npos)
		{
			n--;
		}

		if (n == 0)
		{
			break;
		}

		cnt++;
	}

	cout << cnt << endl;
	return 0;
}