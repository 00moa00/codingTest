
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
int n;
vector<string> v;
string s, ret;

void go() 
{
	while (true) 
	{
		//앞에 0이면 삭제
		if (ret.size() && ret.front() == '0')
		{
			ret.erase(ret.begin());
		}
		else
		{
			break;
		}
	}

	if (ret.size() == 0)
	{
		ret = "0";
	}

	v.push_back(ret);
	ret = "";
}

bool cmp(string a, string b)
{
	if (a.size() == b.size())
	{
		return a < b;
	}
	return a.size() < b.size();
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		ret = "";
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] < 65)
			{
				ret += s[j];
			}

			//숫자가 더이상 없으면
			else if (ret.size())
			{
				go();
			}
		}

		//숫자로 끝나면 (else if문에 들어가지 않음)
		if (ret.size())
		{
			go();
		}
	}
	sort(v.begin(), v.end(), cmp);

	for (string i : v)cout << i << "\n";
	return 0;
}