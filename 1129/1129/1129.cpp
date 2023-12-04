// 1129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

int n, m, j, temp, l, r,ret = 0;



int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> n >> m >> j;
    l = 1;

    for (int i = 0; i <= j; i++)
    {
        //콜리전 생각하면 된다
        r = l + m - 1;
        cin >> temp;

        //범위체크
        if (temp >= l && temp <= r)
        {
            continue;
        }
        
        else 
        {
            //temp가 left보다 왼쪽에 있다. 
            if (temp < l) 
            {
                ret += (l - temp);
                l = temp;
            }

            //temp가 right보다 오른쪽에 있다. 
            else
            {
                l += (temp - r);
                ret += (temp - r);
            }
        }
    }

    cout << ret << "\n";
    return 0;
}