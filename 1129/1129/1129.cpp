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

int a[101][101], e[101][101], visited[101][101], n, m, k, temp, inputLX, inputLY, inputRX, inputRY;
int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
vector<int> ret;

void dfs(int y, int x) 
{
    visited[y][x] = 1;
    ret.back() += 1;

    for (int i = 0; i < 4; i++) 
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= m || nx < 0 || nx >= n || visited[ny][nx] == 1) continue;
        if (a[ny][nx] == 1) continue;

        dfs(ny, nx);
    }

    return;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> inputLX >> inputLY >> inputRX >> inputRY;

        for (int x = inputLX; x < inputRX; x++)
        {
            for (int y = inputLY; y < inputRY; y++)
            {
                a[y][x] = 1;
            }
        }
    }


    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (a[i][j] != 1 && visited[i][j] == 0)
            {
                ret.push_back(0);
                dfs(i, j);
            }
        }
    }

    cout<< ret.size() << '\n';
    sort(ret.begin(), ret.end());

    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << ' ';
    }
    return 0;

}