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
//    //최적화 1. 입출력 
//
//    // C++ 입출력 스트림과 C 입출력을 동기화하지 않도록 설정
//    ios::sync_with_stdio(false);
//    cin.tie(NULL); //  cin과 cout의 연결을 끊어 버퍼 플러시를 최소화
//
//    for (int i = 0; i < n; ++i) 
//    {
//        cin >> A[i];
//    }
//
//    deque<int> dq;
//
//    //최적화 2. size()함수가 불필요하게 반복해서 호출되지 않도록 변경
//    int Asize = A.size();
//
//    for (int i = 0; i < Asize; ++i)
//    {
//        //삭제 1. 인덱스 범위를 초과하는 값 삭제
//        if (dq.empty() == false && dq.front() < i - l + 1)
//        {
//            dq.pop_front();
//        }
//       
//        //삭제 2. 현재 값보다 큰 값들  삭제
//        while (dq.empty() == false && A[i] < A[dq.back()])
//        {
//            dq.pop_back();
//        }
//
//        dq.push_back(i);
//
//
//        //최적화 3.ret에 저장하지 않고 바로 출력하도록 변경
//       // ret[i] = A[dq.front()];
//        cout << A[dq.front()] << " ";
//    }
//   
//}
//
//
