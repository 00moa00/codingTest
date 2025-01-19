#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_N 1000
#define MAX_M 20

int b[MAX_N][MAX_N];
int bSize = 0;
int mnSize = 0;

struct Result {
    int y, x;
};



//최적화 : 보드에서 상자(1)를 찾아서 조각지도의 9를 기준으로 회전시킨다. 그리고 [조각 지도]를 기준으로 일치하는지 확인한다. 
// FS를 통해 회전된 조각지도가 해당 좌표를 중심으로 보드와 일치하는지 확인한다.

void init(int N, int M, int Map[MAX_N][MAX_N]) 
{
    bSize = N;
    mnSize = M;
    for (int i = 0; i < bSize; ++i) 
    {
        memcpy(b[i], Map[i], sizeof(int) * bSize);
    }
}

void rotate(int src[MAX_M][MAX_M], int dst[MAX_M][MAX_M]) 
{
    for (int i = 0; i < mnSize; ++i) 
    {
        for (int j = 0; j < mnSize; ++j)
        {
            dst[j][mnSize - 1 - i] = src[i][j];
        }
    }
}


bool isMatch(int y, int x, int Pieces[MAX_M][MAX_M])
{
    for (int i = 0; i < mnSize; ++i) 
    {
        for (int j = 0; j < mnSize; ++j)
        {
            int py = y + i;
            int px = x + j;

            if (py >= bSize || px >= bSize)
            {
                return false;

            }
                
            int boardValue = b[py][px];
            int pieceValue = Pieces[i][j];

            if (pieceValue != 0 && boardValue != pieceValue && !(pieceValue == 9 && boardValue == 1)) 
            {
                return false;
            }
        }
    }
    return true;
}

Result findTreasureChest(int Pieces[MAX_M][MAX_M])
{
    vector<pair<int, int>> treasureCoords;

    // 보드에서 '1' 좌표 수집
    for (int i = 0; i < bSize; ++i) {
        for (int j = 0; j < bSize; ++j) {
            if (b[i][j] == 1) {
                treasureCoords.push_back(make_pair(i, j));
            }
        }
    }

    int rotatedPieces[MAX_M][MAX_M];
    memcpy(rotatedPieces, Pieces, sizeof(int) * MAX_M * MAX_M);

    for (int rotation = 0; rotation < 4; ++rotation)
    {
        // 조각의 '9' 좌표 찾기
        pair<int, int> pivot = make_pair(-1, -1);
        for (int i = 0; i < mnSize; ++i) {
            for (int j = 0; j < mnSize; ++j)
            {
                if (rotatedPieces[i][j] == 9)
                {
                    pivot = make_pair(i, j);
                    break;
                }
            }
            if (pivot.first != -1)
            {
                break;
            }
            
        }

        for (const auto& coord : treasureCoords)
        {
            int ty = coord.first, tx = coord.second;

            // '9'를 중심으로 보정된 좌표
            int startY = ty - pivot.first;
            int startX = tx - pivot.second;

            if (startY < 0 || startX < 0 || startY + mnSize > bSize || startX + mnSize > bSize)
            {
                continue;

            }


            if (isMatch(startY, startX, rotatedPieces))
            {
                return { ty, tx };
            }
        }

        // 조각지도 회전
        int temp[MAX_M][MAX_M];
        rotate(rotatedPieces, temp);
        memcpy(rotatedPieces, temp, sizeof(temp));
    }

    return { -1, -1 }; // 찾지 못한 경우
}
