#include <iostream>
#include <vector>
#include <deque>

using namespace std;


//
//int main()
//{
//    int n, l;
//    cin >> n >> l;
//
//    vector<int> A(n);
//
//
//    //����ȭ 1. ����� 
//
//    // C++ ����� ��Ʈ���� C ������� ����ȭ���� �ʵ��� ����
//    ios::sync_with_stdio(false);
//    cin.tie(NULL); //  cin�� cout�� ������ ���� ���� �÷��ø� �ּ�ȭ
//
//    for (int i = 0; i < n; ++i) 
//    {
//        cin >> A[i];
//    }
//
//    deque<int> dq;
//
//    //����ȭ 2. size()�Լ��� ���ʿ��ϰ� �ݺ��ؼ� ȣ����� �ʵ��� ����
//    int Asize = A.size();
//
//    for (int i = 0; i < Asize; ++i)
//    {
//        //���� 1. �ε��� ������ �ʰ��ϴ� �� ����
//        if (dq.empty() == false && dq.front() < i - l + 1)
//        {
//            dq.pop_front();
//        }
//       
//        //���� 2. ���� ������ ū ����  ����
//        while (dq.empty() == false && A[i] < A[dq.back()])
//        {
//            dq.pop_back();
//        }
//
//        dq.push_back(i);
//
//
//        //����ȭ 3.ret�� �������� �ʰ� �ٷ� ����ϵ��� ����
//       // ret[i] = A[dq.front()];
//        cout << A[dq.front()] << " ";
//    }
//   
//}
//
//
