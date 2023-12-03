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

//최단거리

int main() {
    const int max_n = 104;

    int dy[4] = { -1, 0, 1, 0 };
    int dx[4] = { 0, 1, 0, -1 };

    int n, m, a[max_n][max_n], visited[max_n][max_n], y, x;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            scanf("%1d", &a[i][j]);
        }
    }

    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.push({ 0, 0 });

    while (q.size()) 
    {
        tie(y, x) = q.front();  //탐색할 좌표를 빼고
        q.pop();                //자료구조에서 제외

        for (int i = 0; i < 4; i++) 
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue;
            if (visited[ny][nx]) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny, nx }); //갈 수 있는 곳이라면 push
        }
    }

    printf("%d", visited[n - 1][m - 1]);
    return 0;
}