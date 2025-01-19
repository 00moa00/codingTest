#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_N 1000
#define MAX_M 20

int b[MAX_N][MAX_N];
int bSize = 0;
int mnSize = 0;


// ���忡�� '1' ��ǥ�� �̸� ����
int treasureCoords[MAX_N * MAX_N][2];
int treasureCount = 0;

struct Result {
    int y, x;
};



//����ȭ 1 : ���忡�� ����(1)�� ã�Ƽ� ���������� 9�� �������� ȸ����Ų��. �׸��� [���� ����]�� �������� ��ġ�ϴ��� Ȯ���Ѵ�. 
// FS�� ���� ȸ���� ���������� �ش� ��ǥ�� �߽����� ����� ��ġ�ϴ��� Ȯ���Ѵ�.

//����ȭ 2 : �����Ҵ� ����, ���忡�� ����(1)�� �ִ� ��ǥ�� �̸� ����

void init(int N, int M, int Map[MAX_N][MAX_N]) 
{
    bSize = N;
    mnSize = M;
    for (int i = 0; i < bSize; ++i) 
    {
        memcpy(b[i], Map[i], sizeof(int) * bSize);
    }

    // '1' ��ǥ Ž��
    treasureCount = 0;
    for (int i = 0; i < bSize; ++i)
    {
        for (int j = 0; j < bSize; ++j)
        {
            if (b[i][j] == 1)
            {
                treasureCoords[treasureCount][0] = i; // y ��ǥ
                treasureCoords[treasureCount][1] = j; // x ��ǥ
                ++treasureCount;
            }
        }
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


    int rotatedPieces[MAX_M][MAX_M];
    memcpy(rotatedPieces, Pieces, sizeof(int) * MAX_M * MAX_M);

    for (int rotation = 0; rotation < 4; ++rotation)
    {
        int pivotY = -1, pivotX = -1;

        for (int i = 0; i < mnSize; ++i)
        {
            for (int j = 0; j < mnSize; ++j)
            {
                if (rotatedPieces[i][j] == 9)
                {
                    pivotY = i;
                    pivotX = j;
                    break;
                }
            }
            if (pivotY != -1)
            {
                break;
            }
            
        }

        for (int i = 0; i < treasureCount; ++i) 
        {
            int treasureY = treasureCoords[i][0];
            int treasureX = treasureCoords[i][1];

            // ������ ���� ��ǥ
            int startY = treasureY - pivotY;
            int startX = treasureX - pivotX;

            if (startY < 0 || startX < 0 || startY + mnSize > bSize || startX + mnSize > bSize)
            {
                continue;
            }

            if (isMatch(startY, startX, rotatedPieces))
            {
                return { treasureY, treasureX };
            }
        }


        // �������� ȸ��
        int temp[MAX_M][MAX_M];
        rotate(rotatedPieces, temp);
        memcpy(rotatedPieces, temp, sizeof(temp));
    }

    return { -1, -1 }; // ã�� ���� ���
}
