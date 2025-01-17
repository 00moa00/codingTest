#include <vector>

using namespace std;

vector<vector<int>> m;

//검사용 변수
vector<pair<int, int>> comboblocks;

int wSize = 0;
int hSize = 0;

int p1Score = 0;
int p2Score = 0;

//테스트 케이스에 대한 초기화하는 함수. 각 테스트 케이스의 최초 1회 호출된다.
//W와 H는 각각 게임판의 폭과 높이이다.
//초기 게임판에는 어떤 블록도 없다.
//게임판에서 맨 왼쪽 열은 열 0이고 맨 오른쪽 열은 열 "W – 1"이다.

void init(int W, int H)
{
    wSize = W;
    hSize = H;

    m = vector<vector<int>>(H, vector<int>(W, 0));
}

void removeBlocks(vector<vector<int>>& removeBlock, int dx, int dy, int player)
{
    for (int i = 0; i < hSize; ++i)
    {
        for (int j = 0; j < wSize; ++j)
        {
            comboblocks.clear();

            for (int k = 0;; ++k)
            {
                int x = i + k * dx;
                int y = j + k * dy;

                if (x >= hSize || y >= wSize || x < 0 || y < 0)
                {
                    break;
                }

                if (m[x][y] == player)
                {
                    comboblocks.push_back({ x, y });
                }
                else
                {
                    break;
                }
            }

            if (comboblocks.size() >= 5)
            {
                for (auto& b : comboblocks)
                {
                    removeBlock[b.first][b.second] = player;
                }
            }
        }
    }
}

void applyGravity()
{
    for (int col = 0; col < wSize; ++col)
    {
        int writeRow = hSize - 1;

        for (int row = hSize - 1; row >= 0; --row)
        {
            if (m[row][col] != 0)
            {
                m[writeRow--][col] = m[row][col];
            }
        }

        while (writeRow >= 0)
        {
            m[writeRow--][col] = 0;
        }
    }
}

int getScore(int mPlayer)
{
    int ret = 0;

    while (true)
    {
        vector<vector<int>> removeBlock(hSize, vector<int>(wSize, 0));

        removeBlocks(removeBlock, 0, 1, mPlayer);
        removeBlocks(removeBlock, 1, 1, mPlayer);
        removeBlocks(removeBlock, 1, 0, mPlayer);

        bool hasRemoved = false;
        for (int i = 0; i < hSize; ++i)
        {
            for (int j = 0; j < wSize; ++j)
            {
                if (removeBlock[i][j] == mPlayer)
                {
                    m[i][j] = 0;
                    ++ret;
                    hasRemoved = true;
                }
            }
        }

        if (!hasRemoved)
        {
            break;
        }

        applyGravity();
    }

    if (mPlayer == 1)
    {
        p1Score += ret;
    }
    else if (mPlayer == 2)
    {
        p2Score += ret;
    }

    return ret;
}

int dropBlocks(int mPlayer, int mCol)
{
    for (int offset = 0; offset < 3; ++offset)
    {
        int col = mCol + offset;
        for (int row = hSize - 1; row >= 0; --row)
        {
            if (m[row][col] == 0)
            {
                m[row][col] = mPlayer;
                break;
            }
        }
    }

    return getScore(mPlayer);
}

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

vector<vector<int>> visited;

void dfs(int y, int x, int opponentPlayer, int player)
{
    visited[y][x] = 1;
    m[y][x] = player;

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= hSize || nx >= wSize || visited[ny][nx] || m[ny][nx] != opponentPlayer)
        {
            continue;
        }

        dfs(ny, nx, opponentPlayer, player);
    }
}

int changeBlocks(int mPlayer, int mCol)
{
    visited = vector<vector<int>>(hSize, vector<int>(wSize, 0));

    int opponent = (mPlayer == 1) ? 2 : 1;

    if (m[hSize - 1][mCol] == opponent)
    {
        dfs(hSize - 1, mCol, opponent, mPlayer);
    }

    return getScore(mPlayer);
}

int getResult(int mBlockCnt[2])
{
    mBlockCnt[0] = 0;
    mBlockCnt[1] = 0;

    for (int i = 0; i < hSize; ++i)
    {
        for (int j = 0; j < wSize; ++j)
        {
            if (m[i][j] == 1)
            {
                mBlockCnt[0]++;
            }
            else if (m[i][j] == 2)
            {
                mBlockCnt[1]++;
            }
        }
    }

    if (p1Score > p2Score)
    {
        return 1;
    }
    else if (p1Score < p2Score)
    {
        return 2;
    }
    return 0;
}



int main()
{
    init(10, 10);  // 예시로 10x10 보드 초기화

    // 예시 입력
    dropBlocks(1, 4);
    dropBlocks(2, 6);
    dropBlocks(1, 1);
    dropBlocks(2, 4);
    dropBlocks(1, 3);
    dropBlocks(2, 2);
    dropBlocks(1, 7);
    dropBlocks(2, 5);

    // 보드 출력
    //printBoard();
    //cout << "Player 1 Score: " << p1Score << endl;
    //cout << "Player 2 Score: " << p2Score << endl;

    return 0;
}