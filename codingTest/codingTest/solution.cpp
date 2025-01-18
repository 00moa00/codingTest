#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> board;

//검사용 변수
vector<pair<int, int>> p1Comboblocks;
vector<pair<int, int>> p2Comboblocks;

int wSize = 0;
int hSize = 0;

int p1Score = 0;
int p2Score = 0;



int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

vector<vector<int>> visited;


//테스트 케이스에 대한 초기화하는 함수. 각 테스트 케이스의 최초 1회 호출된다.
//W와 H는 각각 게임판의 폭과 높이이다.
//초기 게임판에는 어떤 블록도 없다.
//게임판에서 맨 왼쪽 열은 열 0이고 맨 오른쪽 열은 열 "W – 1"이다.

void init(int W, int H)
{


    wSize = W;
    hSize = H;

    board = vector<vector<int>>(H, vector<int>(W, 0));
   // visited = vector<vector<int>>(H, vector<int>(W, 0));

    // visited 벡터의 용량을 미리 예약
    for (int i = 0; i < hSize; ++i)
    {
        visited[i].reserve(wSize);
    }


    p1Score = 0;
    p2Score = 0;

    // 연결된 블록 리스트 초기화
    p1Comboblocks.clear();
    p2Comboblocks.clear();
}

void applyGravity()
{
    for (int col = 0; col < wSize; ++col)
    {
        int writeRow = hSize - 1;

        for (int row = hSize - 1; row >= 0; --row)
        {
            if (board[row][col] != 0)
            {
                board[writeRow--][col] = board[row][col];
            }
        }

        while (writeRow >= 0)
        {
            board[writeRow--][col] = 0;
        }
    }
}

void removeBlocks(vector<vector<int>>& removeBlock, int dx, int dy, int player, int opponent)
{

    //내 블럭
    for (int i = 0; i < hSize; ++i)
    {
        for (int j = 0; j < wSize; ++j)
        {

            //if (removeBlock[i][j] != 0)
            //{
            //    // 이미 처리된 블록은 건너뜁니다.
            //    continue;
            //}


            p1Comboblocks.clear();

            for (int k = 0;; ++k)
            {
                int x = i + k * dx;
                int y = j + k * dy;

                if (x >= hSize || y >= wSize || x < 0 || y < 0)
                {
                    break;
                }

                if (board[x][y] == player)
                {
                    p1Comboblocks.push_back({ x, y });
                }
                else
                {
                    break;
                }
            }

            if (p1Comboblocks.size() >= 5)
            {
                for (auto& b : p1Comboblocks)
                {
                    removeBlock[b.first][b.second] = player;
                }
            }

        }
    }

    //상대블럭
    for (int i = 0; i < hSize; ++i)
    {
        for (int j = 0; j < wSize; ++j)
        {
            p2Comboblocks.clear();

            for (int k = 0;; ++k)
            {
                int x = i + k * dx;
                int y = j + k * dy;

                if (x >= hSize || y >= wSize || x < 0 || y < 0)
                {
                    break;
                }

               if (board[x][y] == opponent)
                {
                    p2Comboblocks.push_back({ x, y });
                }

                else
                {
                    break;
                }
            }

            if (p2Comboblocks.size() >= 5)
            {
                for (auto& b : p2Comboblocks)
                {
                    removeBlock[b.first][b.second] = opponent;
                }
            }
        }
    }
}


int getScore(int mPlayer, int mOpponent)
{
    int ret = 0;

    while (true)
    {
        vector<vector<int>> removeBlock(hSize, vector<int>(wSize, 0));

        removeBlocks(removeBlock, 1, 1, mPlayer, mOpponent);  // 오른쪽 아래
        removeBlocks(removeBlock, -1, 1, mPlayer, mOpponent); // 왼쪽 아래
        removeBlocks(removeBlock, -1, -1, mPlayer, mOpponent); // 왼쪽 위
        removeBlocks(removeBlock, 1, -1, mPlayer, mOpponent); // 오른쪽 위
        removeBlocks(removeBlock, 0, 1, mPlayer, mOpponent);
        removeBlocks(removeBlock, 1, 0, mPlayer, mOpponent);

        bool hasRemoved = false;
        for (int i = 0; i < hSize; ++i)
        {
            for (int j = 0; j < wSize; ++j)
            {
                if (removeBlock[i][j] == mPlayer)
                {
                    board[i][j] = 0;
                    ++ret;
                    hasRemoved = true;
                }

                //상대 블럭이라면 없애지만 점수를 추가하지 않는다
                if (removeBlock[i][j] == mOpponent)
                {
                    board[i][j] = 0;
                    hasRemoved = true;
                }
            }
        }

        if (hasRemoved == false)
        {
            break;
        }

        applyGravity();
    }

    if (mPlayer == 1)
    {
        p1Score += ret;
    }
    else
    {
        p2Score += ret;
    }
    //cout << "삭제후----------------------" << endl;
    //for (int i = 0; i < hSize; ++i) 
    //{
    //    for (int j = 0; j < wSize; ++j)
    //    {
    //        cout << board[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    //cout << "----------------------" << endl;
    //cout << ret << endl;

    return ret;
}

int dropBlocks(int mPlayer, int mCol)
{
    if (mCol == 12)
    {
        int a = 0;
    }
    for (int offset = 0; offset < 3; ++offset)
    {
        int col = mCol + offset;
        for (int row = hSize - 1; row >= 0; --row)
        {
            if (board[row][col] == 0)
            {
                board[row][col] = mPlayer;
                break;
            }
        }
    }
    //cout << "블럭 쌓음----------------------" << endl;
    //for (int i = 0; i < hSize; ++i) 
    //{
    //    for (int j = 0; j < wSize; ++j) 
    //    {
    //        cout << board[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    //cout << "----------------------" << endl;

    int opponent = (mPlayer == 1) ? 2 : 1;

    return getScore(mPlayer, opponent);
}

void dfs(int y, int x, int opponentPlayer, int player)
{
    visited[y][x] = 1;
    board[y][x] = player;

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= hSize || nx >= wSize || visited[ny][nx] || board[ny][nx] != opponentPlayer)
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

    if (board[hSize - 1][mCol] == opponent)
    {
        dfs(hSize - 1, mCol, opponent, mPlayer);
    }

    return getScore(mPlayer, opponent);
}

int getResult(int mBlockCnt[2])
{
    mBlockCnt[0] = 0;
    mBlockCnt[1] = 0;

    for (int i = 0; i < hSize; ++i)
    {
        for (int j = 0; j < wSize; ++j)
        {
            if (board[i][j] == 1)
            {
                mBlockCnt[0]++;
            }
            else if (board[i][j] == 2)
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

