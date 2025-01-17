#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;


//int main()
//{
//
//	int n;	//사람 수
//	int m;	//파티 수
//
//	cin >> n >> m;
//
//	//블랙리스트
//	vector<bool> blacklist(n, false);
//
//
//	//진실을 알고있는 사람의 수
//	int t = 0;
//	cin >> t;
//
//	//진실을 알고있는 사람 체크
//	queue<int> q;
//
//	for (int i = 0; i < t; ++i)
//	{
//		int person = 0;
//		cin >> person;
//		blacklist[person - 1] = true;
//		q.push(person - 1);
//	}
//
//	//파티, 파티에 참여한 사람
//	vector<vector<int>> guestlist(m);
//	vector<vector<int>> parties(n); // 각 사람이 참여하는 파티
//
//	//파티 수 만큼 진행
//	for (int i = 0; i < m; ++i)
//	{
//		int quest= 0;
//		cin >> quest;
//		bool bIsblack = false;
//
//		for (int j = 0; j < quest; ++j)
//		{
//			int w = 0;
//			cin >> w;
//			guestlist[i].push_back(w-1);
//			parties[w - 1].push_back(i);
//		}
//
//	}
//
//	// 진실 전파 (BFS)
//	vector<bool> visitedParty(m, false);
//	while (!q.empty())
//	{
//		int person = q.front();
//		q.pop();
//
//		//사람이 참여한 파티
//		for (int party : parties[person])
//		{
//			if (visitedParty[party] == true)
//			{
//				continue; // 이미 처리한 파티는 건너뛰기
//			}
//
//			visitedParty[party] = true;
//
//			//해당 파티에 참여한 게스트 목록
//			for (int guest : guestlist[party]) 
//			{
//				if (blacklist[guest] == false) 
//				{
//
//					//블랙리스트에 등록한다
//					blacklist[guest] = true;
//					q.push(guest);
//				}
//			}
//		}
//	}
//	int ret = 0;
//
//	for (auto party : guestlist)
//	{
//		bool able = true;
//
//		for (auto list : party)
//		{
//			if (blacklist[list] == true)
//			{
//				able = false;
//				break;
//			}
//		}
//
//		if (able == true)
//		{
//			ret++;
//		}
//	}
//
//
//	cout << ret;
//
//}