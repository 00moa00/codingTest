#include <vector>
#include <cstring> // memset 사용을 위해 추가

using namespace std;


// 테스트용 함수
const int MAX_H = 201; // 최대 높이
const int MAX_W = 201; // 최대 폭


//검사용 변수
//vector<pair<int, int>> p1Comboblocks;
//vector<pair<int, int>> p2Comboblocks;

int board[MAX_H][MAX_W];
int visited[MAX_H][MAX_W];
int removeBlock[MAX_H][MAX_W];

int wSize = 0;
int hSize = 0;

int p1Score = 0;
int p2Score = 0;



int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

// 네 방향 탐색
const int directions[4][2] =
{
    {1, 0},  // 아래쪽
    {0, 1},  // 오른쪽
    {1, 1},  // 오른쪽 아래 대각선
    {1, -1}  // 왼쪽 아래 대각선
};



//테스트 케이스에 대한 초기화하는 함수. 각 테스트 케이스의 최초 1회 호출된다.
//W와 H는 각각 게임판의 폭과 높이이다.
//초기 게임판에는 어떤 블록도 없다.
//게임판에서 맨 왼쪽 열은 열 0이고 맨 오른쪽 열은 열 "W – 1"이다.

void init(int W, int H)
{
    wSize = W;
    hSize = H;

    for (int i = 0; i < hSize; ++i) 
    {
        for (int j = 0; j < wSize; ++j)
        {
            board[i][j] = 0;
            visited[i][j] = 0;
            removeBlock[i][j] = 0;
        }
    }
    // visited 벡터의 용량을 미리 예약
    //for (int i = 0; i < hSize; ++i)
    //{
    //    visited[i].reserve(wSize);
    //}


    p1Score = 0;
    p2Score = 0;

}

void applyGravity()
{

    int writeRow = 0;

    for (int col = 0; col < wSize; ++col)
    {
        writeRow = hSize - 1;

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


//최적화 전의 코드

//void removeBlocks(vector<vector<int>>& removeBlock, int dx, int dy, int player, int opponent)
//{
//    //내 블럭
//    for (int i = 0; i < hSize; ++i)
//    {
//        for (int j = 0; j < wSize; ++j)
//        {
//            p1Comboblocks.clear();
//
//            for (int k = 0;; ++k)
//            {
//                int x = i + k * dx;
//                int y = j + k * dy;
//
//                if (x >= hSize || y >= wSize || x < 0 || y < 0)
//                {
//                    break;
//                }
//
//                if (board[x][y] == player)
//                {
//                    p1Comboblocks.push_back({ x, y });
//                }
//                else
//                {
//                    break;
//                }
//            }
//
//            if (p1Comboblocks.size() >= 5)
//            {
//                for (auto& b : p1Comboblocks)
//                {
//                    removeBlock[b.first][b.second] = player;
//                }
//            }
//
//        }
//    }
//
//    //상대블럭
//    for (int i = 0; i < hSize; ++i)
//    {
//        for (int j = 0; j < wSize; ++j)
//        {
//            p2Comboblocks.clear();
//
//            for (int k = 0;; ++k)
//            {
//                int x = i + k * dx;
//                int y = j + k * dy;
//
//                if (x >= hSize || y >= wSize || x < 0 || y < 0)
//                {
//                    break;
//                }
//
//               if (board[x][y] == opponent)
//                {
//                    p2Comboblocks.push_back({ x, y });
//                }
//
//                else
//                {
//                    break;
//                }
//            }
//
//            if (p2Comboblocks.size() >= 5)
//            {
//                for (auto& b : p2Comboblocks)
//                {
//                    removeBlock[b.first][b.second] = opponent;
//                }
//            }
//        }
//    }
//}



void dfsRemove(int y, int x, int dx, int dy, int player, vector<pair<int, int>>& comboblocks)
{
    if (y < 0 || x < 0 || y >= hSize || x >= wSize || board[y][x] != player)
    {
        return;
    }

    comboblocks.push_back({ y, x });
    dfsRemove(y + dy, x + dx, dx, dy, player, comboblocks);
}


void removeBlocks(int player, int opponent, bool& bIsremove)
{
    vector<pair<int, int>> comboblocks;
    comboblocks.reserve(20);
    int currentPlayer  = 0;

    for (int i = 0; i < hSize; ++i)
    {
        for (int j = 0; j < wSize; ++j)
        {
            if (board[i][j] == player || board[i][j] == opponent)
            {

                currentPlayer = board[i][j]; // 현재 탐색 대상 (player 또는 opponent)          

                for (auto& dir : directions)
                {
                    comboblocks.clear();
                    dfsRemove(i, j, dir[0], dir[1], currentPlayer, comboblocks);

                    // 5개 이상 연속된 블록을 찾은 경우
                    if (comboblocks.size() >= 5)
                    {
                        for (auto& b : comboblocks)
                        {
                            removeBlock[b.first][b.second] = currentPlayer;
                            bIsremove = true;
                        }
                    }
                }
            }
        }
    }
}


int getScore(int mPlayer, int mOpponent)
{
    int ret = 0;
    bool hasRemoved = false;
    while (true)
    {   
        hasRemoved = false;


        removeBlocks( mPlayer, mOpponent, hasRemoved);
        //removeBlocks(removeBlock, -1, 1, mPlayer, mOpponent); // 왼쪽 아래
        //removeBlocks(removeBlock, -1, -1, mPlayer, mOpponent); // 왼쪽 위
        //removeBlocks(removeBlock, 1, -1, mPlayer, mOpponent); // 오른쪽 위
        //removeBlocks(removeBlock, 0, 1, mPlayer, mOpponent);
        //removeBlocks(removeBlock, 1, 0, mPlayer, mOpponent);


        //제거 할 블럭이 더이상 없다면 반복문 종료
        if (hasRemoved == false)
        {
            break;
        }



        if (hasRemoved == true)
        {
            for (int i = 0; i < hSize; ++i)
            {
                for (int j = 0; j < wSize; ++j)
                {
                    if (removeBlock[i][j] != 0)
                    {
                        board[i][j] = 0; // 블록 제거

                        if (removeBlock[i][j] == mPlayer)
                        {
                            ++ret;
                        }
                       // hasRemoved = true;
                    }
                }
            }

        }
   

        applyGravity();

        // removeBlock 배열을 초기화
        memset(removeBlock, 0, sizeof(removeBlock));

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
    int col = 0;

    for (int offset = 0; offset < 3; ++offset)
    {
         col = mCol + offset;
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

    int ny = 0;
    int nx = 0;

    for (int i = 0; i < 4; ++i)
    {
         ny = y + dy[i];
         nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= hSize || nx >= wSize || visited[ny][nx] || board[ny][nx] != opponentPlayer)
        {
            continue;
        }

        dfs(ny, nx, opponentPlayer, player);
    }
}

int changeBlocks(int mPlayer, int mCol)
{

    //fill(visited.begin(), visited.end(), vector<int>(wSize, 0));

    memset(visited, 0, sizeof(visited));

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

