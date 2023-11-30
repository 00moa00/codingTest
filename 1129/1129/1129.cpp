// 1129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;
int A, B, C, a, b, cnt[104], ret;

int main() {
	cin >> A >> B >> C; //주차요금
	for (int i = 0; i < 3; i++) 
	{
		cin >> a >> b;	//도착, 떠난 시간. 이상 미만
		for (int j = a; j < b; j++)
		{
			cnt[j]++;
		}
	}

	for (int j = 1; j < 100; j++) 
	{
		//트럭이 도착했다면
		if (cnt[j]) 
		{
			if (cnt[j] == 1) ret += A;
			else if (cnt[j] == 2)ret += B * 2;
			else if (cnt[j] == 3)ret += C * 3;
		}
	}
	cout << ret << "\n";
	return 0;
}