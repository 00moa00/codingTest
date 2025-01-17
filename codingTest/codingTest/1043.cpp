#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;


//int main()
//{
//
//	int n;	//��� ��
//	int m;	//��Ƽ ��
//
//	cin >> n >> m;
//
//	//������Ʈ
//	vector<bool> blacklist(n, false);
//
//
//	//������ �˰��ִ� ����� ��
//	int t = 0;
//	cin >> t;
//
//	//������ �˰��ִ� ��� üũ
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
//	//��Ƽ, ��Ƽ�� ������ ���
//	vector<vector<int>> guestlist(m);
//	vector<vector<int>> parties(n); // �� ����� �����ϴ� ��Ƽ
//
//	//��Ƽ �� ��ŭ ����
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
//	// ���� ���� (BFS)
//	vector<bool> visitedParty(m, false);
//	while (!q.empty())
//	{
//		int person = q.front();
//		q.pop();
//
//		//����� ������ ��Ƽ
//		for (int party : parties[person])
//		{
//			if (visitedParty[party] == true)
//			{
//				continue; // �̹� ó���� ��Ƽ�� �ǳʶٱ�
//			}
//
//			visitedParty[party] = true;
//
//			//�ش� ��Ƽ�� ������ �Խ�Ʈ ���
//			for (int guest : guestlist[party]) 
//			{
//				if (blacklist[guest] == false) 
//				{
//
//					//������Ʈ�� ����Ѵ�
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