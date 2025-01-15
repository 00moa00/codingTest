#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
//
//int main()
//{
//
//    //배열 크기
//    int n, m;
//
//
//
//    //판
//    char a[51][51];
//
//    int visited[51][51] = { 0, };
//    int y, x;
//    int dy[4] = { -1, 0, 1, 0 };
//    int dx[4] = { 0,1,0,-1 };
//    int max_time = 0;
//
//    cin >> n >> m;
//
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < m; ++j)
//        {
//            cin >> a[i][j];
//        }
//    }
//
//    //시작 지점 
//
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < m; ++j)
//        {
//            if (a[i][j] == 'L')
//            {
//                memset(visited, 0, sizeof(visited));
//                queue<pair<int, int>> q;
//                q.push({ i,j });
//                visited[i][j] = 1;
//
//                while (q.size())
//                {
//                    tie(y, x) = q.front();
//                    q.pop();
//
//                    for (int i = 0; i < 4; ++i)
//                    {
//                        int ny = y + dy[i];
//                        int nx = x + dx[i];
//
//                        if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 'W')
//                        {
//                            continue;
//                        }
//
//                        //방문한 곳이라면
//                        if (visited[ny][nx] > 0)
//                        {
//                            continue;
//                        }
//
//                        visited[ny][nx] = visited[y][x] + 1;
//                        q.push({ ny,nx });
//
//                        //최다거리 저장
//                        if (visited[ny][nx] > max_time)
//                        {
//                            max_time = visited[ny][nx] - 1;
//                        }
//                    }
//
//                }
//
//            }
//        }
//    }
//
//
//    cout << max_time;
//    return 0;
//}
