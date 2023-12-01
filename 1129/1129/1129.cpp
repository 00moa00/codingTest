// 1129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
typedef long long ll;
ll a, b, c;

ll go(ll a, ll b) 
{
    if (b == 1)
    {
        return a % c;
    }

    ll ret = go(a, b / 2);
    ret = (ret * ret) % c;
    if (b % 2)
    {
        ret = (ret * a) % c;
    }

    return ret;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> a >> b >> c;
    std::cout << go(a, b) << "\n";

    return 0;
}
