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
        vector<int> survived; // ��Ƴ��� ����
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
                addedEnergy += t / 2; // ���� ������ ������� ��ȯ
            }
        }

        energy += addedEnergy;
        tree = move(survived); // ���� ����Ʈ ������Ʈ
    }
};

//����
//0 : ��, 1 : ����, 2 : ����, 3 : �ܿ�
int season = 0;

int n, m, k;
int x, y, z;

//��, �ʱ�ȭ
vector<vector<Soil>> a;
vector<vector<int>> winterEnergy;

bool isValid(int y, int x)
{
    return y >= 0 && y < n && x >= 0 && x < n;
}

//����
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
            a[i][j].energy = 5; // �ʱ� ����� 5
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        cin >> y >> x >> z;
        a[y - 1][x - 1].tree.push_back(z); // ���� �߰�
    }

    while (k--)
    {
        // ��: ���� ����
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                a[i][j].grow();
            }
        }

        // ����: ����
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                for (int t : a[i][j].tree)
                {
                    if (t % 5 == 0) // 5�� ����� ��� ����
                    {
                        breeding(i, j);
                    }
                }
            }
        }

        // �ܿ�: ��� �߰�
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                a[i][j].energy += winterEnergy[i][j];
            }
        }
    }

    // ��� ���
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
