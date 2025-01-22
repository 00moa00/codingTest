#include <iostream>
#include <vector>
#include <deque>

using namespace std;



int main()
{
    int n, l;
    cin >> n >> l;

    vector<int> ret(n);
    vector<int> A(n);

    for (int i = 0; i < n; ++i) 
    {
        cin >> A[i];
    }

    deque<int> dq;
    int Asize = A.size();

    for (int i = 0; i < Asize; ++i)
    {

        //���� 1. �ε��� ������ �ʰ��ϴ� �� ����
        if (dq.empty() == false && dq.front() < i - l + 1)
        {
            dq.pop_front();
        }
       
        //���� 2. ���� ������ ū ����  ����
        while (dq.empty() == false && A[i] < A[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(i);

        ret[i] = A[dq.front()];

    }
   
    for (int i = 0; i < Asize; ++i)
    {
        cout << ret[i]<<" ";
    }
}


