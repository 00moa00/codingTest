// 1129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;
string str;
int cnt[26];

int main() {
	cin >> str;
	for (char a : str) {
		cnt[a - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		cout << cnt[i] << " ";
	}

	return 0;
}