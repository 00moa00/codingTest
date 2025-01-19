#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_N 1000
#define MAX_M 20

int b[MAX_N][MAX_N];
int bSize = 0;
int mnSize = 0;


// 보드에서 '1' 좌표를 미리 저장
pair<int, int> treasureCoords[MAX_N * MAX_N];
int treasureCount = 0;

struct Result 
{
    int y, x;
};



//최적화 1 : 보드에서 상자(1)를 찾아서 조각지도의 9를 기준으로 회전시킨다. 그리고 [조각 지도]를 기준으로 일치하는지 확인한다. 
// FS를 통해 회전된 조각지도가 해당 좌표를 중심으로 보드와 일치하는지 확인한다.

//최적화 2 : 동적할당 삭제, 보드에서 상자(1)가 있는 좌표를 미리 저장

//최적화 3 : 좌표를 정렬한다. 조각 지도의 회전을 단순화 해서 메모리 복사 줄임

//최적화 4 : 조각지도의 회전을 미리 시킴



void init(int N, int M, int Map[MAX_N][MAX_N]) 
{
    bSize = N;
    mnSize = M;
    for (int i = 0; i < bSize; ++i) 
    {
        memcpy(b[i], Map[i], sizeof(int) * bSize);
    }

    // '1' 좌표 탐색
    treasureCount = 0;
    for (int i = 0; i < bSize; ++i)
    {
        for (int j = 0; j < bSize; ++j)
        {
            if (b[i][j] == 1)
            {
                treasureCoords[treasureCount] = { i, j };

                treasureCount += 1;
            }
        }
    }

    // 좌표를 정렬하여 탐색 최적화
    sort(treasureCoords, treasureCoords + treasureCount);
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
    int py = 0;
    int px = 0;


    int boardValue = 0;
    int pieceValue = 0;

    for (int i = 0; i < mnSize; ++i) 
    {
        for (int j = 0; j < mnSize; ++j)
        {
             py = y + i;
             px = x + j;

            if (py >= bSize || px >= bSize)
            {
                return false;

            }
                
             boardValue = b[py][px];
             pieceValue = Pieces[i][j];

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

    // 회전된 조각 지도를 미리 계산
    int rotatedPieces[4][MAX_M][MAX_M];
    memcpy(rotatedPieces[0], Pieces, sizeof(int) * MAX_M * MAX_M);
    for (int r = 1; r < 4; ++r)
    {
        rotate(rotatedPieces[r - 1], rotatedPieces[r]);
    }

    for (int rotation = 0; rotation < 4; ++rotation)
    {
        int pivotY = -1, pivotX = -1;
        bool foundPivot = false;

        for (int i = 0; i < mnSize; ++i)
        {
            for (int j = 0; j < mnSize; ++j)
            {
                if (rotatedPieces[rotation][i][j] == 9)
                {
                    pivotY = i;
                    pivotX = j;
                    foundPivot = true;
                    break;
                }
            }
            if (foundPivot == true)
            {
                break; // 9가 없는 경우;
            }
            
        }

        for (int i = 0; i < treasureCount; ++i) 
        {
            int treasureY = treasureCoords[i].first;
            int treasureX = treasureCoords[i].second;

            // 보정된 시작 좌표
            int startY = treasureY - pivotY;
            int startX = treasureX - pivotX;

            if (startY < 0 || startX < 0 || startY + mnSize > bSize || startX + mnSize > bSize)
            {
                continue;
            }

            if (isMatch(startY, startX, rotatedPieces[rotation]))
            {
                return { treasureY, treasureX };
            }
        }


        // 조각지도 회전
       // rotate(rotatedPieces);

    }

    return { -1, -1 }; // 찾지 못한 경우
}
