
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
int n; //골이 들어간 횟수
int InputTeamNum;
string InputTime;

string PrevTime = "00:00";

int ATaemTime;
int BTaemTime;

int ATeamScore;
int BTeamScore;

string ChangeToString(int a) 
{
	string d = "00" + to_string(a / 60);
	string e = "00" + to_string(a % 60);

	//뒤에서 두번째부터 자른다.
	return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);
}

int ChangeToInt(string a)
{
	return stoi(a.substr(0, 2).c_str()) * 60 + stoi(a.substr(3, 2).c_str());
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> InputTeamNum >> InputTime;

		if (ATeamScore > BTeamScore)
		{
			ATaemTime += (ChangeToInt(InputTime) - ChangeToInt(PrevTime));
		}
		else if (ATeamScore < BTeamScore)
		{
			BTaemTime += (ChangeToInt(InputTime) - ChangeToInt(PrevTime));
		}

		//점수 넣어준다.
		if (InputTeamNum == 1)
		{
			ATeamScore += 1;
		}
		else
		{
			BTeamScore += 1;
		}

		PrevTime = InputTime;
	
	}

	int lastGameTime = ChangeToInt("48:00");

	if (ATeamScore > BTeamScore)
	{
		ATaemTime += lastGameTime - ChangeToInt(PrevTime);
	}
	else if (ATeamScore < BTeamScore)
	{
		BTaemTime += lastGameTime - ChangeToInt(PrevTime);
	}

	cout << ChangeToString(ATaemTime) << "\n";
	cout << ChangeToString(BTaemTime) << "\n";

	return 0;
}