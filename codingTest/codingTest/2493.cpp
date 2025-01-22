#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> fun(const vector<int>& heights)
{
    int n = heights.size();
    vector<int> result(n);
    stack<pair<int, int>> s;

    for (int i = 0; i < n; ++i)
    {

        // 현재 탑의 높이보다 낮은 탑은 제거
        while (s.empty() == false && s.top().first < heights[i])
        {
            s.pop();
        }

        // 레이저가 닿는 첫 번째 탑을 결과에 저장
        if (s.empty())
        {
            result[i] = 0; // 닿는 탑이 없음
        }
        else
        {
            result[i] = s.top().second + 1; // 1-based index
        }

        // 현재 탑을 스택에 추가
        s.push({ heights[i], i });
    }

    return result;
}

//int main()
//{
//    int n;
//    cin >> n;
//
//    vector<int> heights(n);
//
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> heights[i];
//    }
//
//    vector<int> result = fun(heights);
//
//    for (int i = 0; i < n; ++i)
//    {
//        cout << result[i] << " ";
//    }
//
//    cout << endl;
//
//    return 0;
//}
