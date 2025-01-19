#include <iostream>
#include <cstring>

using namespace std;
#define MAX_N 1000
#define MAX_M 20

int bSize = 0;
int mnSize = 0;


int b[MAX_N][MAX_N];

struct Result
{
    int y, x;
};

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

bool match(int yStart, int xStart, int Pieces[MAX_M][MAX_M], Result& res)
{
    int matchedCount = 0;
    int totalTreasures = 0;
    int resY = -1, resX = -1;

    for (int i = 0; i < mnSize; ++i)
    {
        for (int j = 0; j < mnSize; ++j)
        {
            int boardValue = b[yStart + i][xStart + j];
            int pieceValue = Pieces[i][j];

            if (pieceValue == 1 || pieceValue == 9)
            {
                ++totalTreasures;
            }

            if ((pieceValue == 1 || pieceValue == 9) && boardValue == 1)
            {
                ++matchedCount;
                if (pieceValue == 9)
                {
                    resY = yStart + i;
                    resX = xStart + j;
                }
            }

            if (pieceValue != 0 && boardValue != pieceValue && !(pieceValue == 9 && boardValue == 1))
            {
                return false;
            }
        }
    }

    if (matchedCount == totalTreasures && resY != -1 && resX != -1)
    {
        res.y = resY;
        res.x = resX;
        return true;
    }

    return false;
}

Result findTreasureChest(int Pieces[MAX_M][MAX_M])
{
    Result res = { -1, -1 };
    int rotatedPieces[MAX_M][MAX_M];

    memcpy(rotatedPieces, Pieces, sizeof(int) * MAX_M * MAX_M);

    for (int rotation = 0; rotation < 4; ++rotation)
    {
        for (int yStart = 0; yStart <= bSize - mnSize; ++yStart)
        {
            for (int xStart = 0; xStart <= bSize - mnSize; ++xStart)
            {
                if (match(yStart, xStart, rotatedPieces, res))
                {
                    return res;
                }
            }
        }

 
        int temp[MAX_M][MAX_M];
        rotate(rotatedPieces, temp);

        memcpy(rotatedPieces, temp, sizeof(temp));
    }

    return res;
}
