#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Soil
{
    int energy = 0;
    vector<int> tree;

    void grow()
    {
        vector<int> survived; // 살아남은 나무
        int addedEnergy = 0;

        sort(tree.begin(), tree.end());

        for (int t : tree)
        {
            if (energy >= t)
            {
                energy -= t;
                survived.push_back(t + 1);
            }
            else
            {
                addedEnergy += t / 2; // 죽은 나무는 양분으로 변환
            }
        }

        energy += addedEnergy;
        tree = move(survived); // 나무 리스트 업데이트
    }
};

//계절
//0 : 봄, 1 : 여름, 2 : 가을, 3 : 겨울
int season = 0;

int n, m, k;
int x, y, z;

//땅, 초기화
vector<vector<Soil>> a;
vector<vector<int>> winterEnergy;

bool isValid(int y, int x)
{
    return y >= 0 && y < n && x >= 0 && x < n;
}

//번식
void breeding(int y, int x)
{
    static const int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static const int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (int d = 0; d < 8; ++d)
    {
        int ny = y + dy[d], nx = x + dx[d];
        if (isValid(ny, nx))
        {
            a[ny][nx].tree.push_back(1);
        }
    }
}


int main()
{
    cin >> n >> m >> k;

    a.resize(n, vector<Soil>(n));
    winterEnergy.resize(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> winterEnergy[i][j];
            a[i][j].energy = 5; // 초기 양분은 5
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        cin >> y >> x >> z;
        a[y - 1][x - 1].tree.push_back(z); // 나무 추가
    }

    while (k--)
    {
        // 봄: 나무 성장
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                a[i][j].grow();
            }
        }

        // 가을: 번식
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                for (int t : a[i][j].tree)
                {
                    if (t % 5 == 0) // 5의 배수인 경우 번식
                    {
                        breeding(i, j);
                    }
                }
            }
        }

        // 겨울: 양분 추가
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                a[i][j].energy += winterEnergy[i][j];
            }
        }
    }

    // 결과 출력
    int result = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            result += a[i][j].tree.size();
        }
    }

    cout << result << endl;
    return 0;
}
