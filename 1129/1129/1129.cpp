// 1129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
//#include <string>
#include <vector>
#include <map>
#include <unordered_map>
//#include <stack>
//#include <queue>
//#include <tuple>

using namespace std;

int c, n, input, cnt;
unordered_map<int,int> ret;
map<int, int> pu;


bool compareByValue(const pair<int, int>& a, const pair<int, int>& b) 
 {
    if (a.second == b.second)
    {
        return pu[a.first] < pu[b.first];

    }
    return a.second > b.second;
}
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> n >> c;


    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (ret.find(input) == ret.end())
        {
            ret.insert({ input,1 });
        }
        else
        {
            ret[input] = ret[input] += 1;
        }
     
        if (pu.find(input) == pu.end())
        {
            cnt += 1;
            pu[input] = cnt;
        }

    }

    vector<pair<int, int>> sortedRet(ret.begin(), ret.end());
    sort(sortedRet.begin(), sortedRet.end(), compareByValue);

    for (const auto& pair : sortedRet)
    {
        int max_count = pair.second;
        for (int j = 0; j < max_count; j++) 
        {
            cout << pair.first << '\n';
        }
    }

    return 0;
}