#include <iostream>

using namespace std;
#define MAX_N 1000
#define MAX_M 20

int bSize = 0;
int mnSize = 0;


//�̴����� ����
int rate = 0;

int b[MAX_N][MAX_N] ;

struct Result 
{
	int y, x;
};

void init(int N, int M, int Map[MAX_N][MAX_N])
{
    bSize = N;
    mnSize = M;

    rate = bSize / mnSize;
    for (int i = 0; i < bSize; ++i)
    {
        for (int j = 0; j < bSize; ++j)
        {
            b[i][j] = Map[i][j];
        }
    }
}

//M * M ũ���� �������� ���� ���� Pieces[][] �� ���� ���� ��ǥ�� �����Ѵ�.
//Pieces[][] ���� �������� ���� ������ 9 �� ǥ�� �Ǿ� �ִ�.
//Pieces[][] ���� �������� ���� ������ �ݵ�� 1���̴�.
//Pieces[][] ���� ������ 1, 9, 0 ���� �����Ǿ� �ְ�, ������ 1 �Ǵ� 9 �� ǥ�� �Ǿ� �ִ�.
//Pieces[][] ���� �������� ������ ������ 5 �̻� 20 �����̴�.
//Pieces[][] ���� ������ �����󿡼� 90��, 180��, 270�� ȸ���Ǿ ������ �� ������, �����ϴ� ������� 1������ �ݵ�� ����ȴ�.
//����, ������ ���� ������ ���ؼ� findTreasureChest() �Լ��� �� �� �̻� ȣ��Ǵ� ���� ����

Result findTreasureChest(int Pieces[MAX_M][MAX_M])
{
    //for (int i = 0; i < bSize; ++i)
    //{
    //    for (int j = 0; j < bSize; ++j)
    //    {
    //        board[i][j] = Map[i][j];
    //    }
    //}


	Result res;

	res.y = res.x = 0;

    int yStart = 0;
    int xStart = 0;


    int currentPieces[MAX_M][MAX_M] = {-1,};

    memcpy(currentPieces, Pieces, sizeof(currentPieces));

    while (true)
    {

        bool bIsmatched = false;
        int rotationCount = 0;
        int matchedCount = 0;
        int chestCount = 0;

        while (true)
        {
            //�ʱ�ȭ
            res.y = res.x = -1;

            int mnY = 0;
            int mnX = 0;
           

            //���� ��ȸ
            for (int i = yStart; i < yStart + mnSize; ++i)
            {
                for (int j = xStart; j < xStart + mnSize; ++j)
                {
                    if (currentPieces[mnY][mnX] == 1 || currentPieces[mnY][mnX] == 9)
                    {
                        ++chestCount;
                    }

                    if (b[i][j] == 1 && (currentPieces[mnY][mnX] == 1 || currentPieces[mnY][mnX] == 9))
                    {
                        ++matchedCount;
                       // ++chestCount;
                    }


                    if (matchedCount != matchedCount)
                    {
                        bIsmatched = false;
                         break;

                    }

                    //��ġ�ϴ� �� �˻�
                    if (b[i][j] == currentPieces[mnY][mnX])
                    {
                    
                        bIsmatched = true;
                    }

                    //������ �ִ� ����
                    else if (currentPieces[mnY][mnX] == 9 && b[i][j] == 1)
                    {
                        bIsmatched = true;

                        res.y = i;
                        res.x = j;

                    }

                    //else
                    //{
                    //    //�ϳ��� ��ġ���� �ʴ´ٸ� for�� ����
                    //    bIsmatched = false;
                    //    break;
                    //}

                    //�̴ϸ� X����

                    ++mnX;
                }

                if (matchedCount != matchedCount)
                {
                    bIsmatched = false;
                    break;

                }
                //�̴ϸ� Y����
                ++mnY;
                mnX = 0;


            }

            //�� ��ȸ�ߴµ� ��ΰ� ��ġ�ߴ�. �׷��� ������ ã�����̴�.
            if (bIsmatched == true && matchedCount == chestCount)
            {
                return res;

            }


            //��ã������ �ϴ� ȸ���� �غ���.
            //�ٵ� �̹� ȸ�� ī��Ʈ�� �� �Һ��ߴٸ� ����
            if (rotationCount > 3)
            {
                bIsmatched = false;
                break;
            }

            ++rotationCount;

            //�ʱ�ȭ
            bIsmatched = false;
            res.y = res.x = -1;
            matchedCount = 0;
            chestCount = 0;

            int temp[MAX_M][MAX_M];
            for (int i = 0; i < mnSize; ++i) 
            {
                for (int j = 0; j < mnSize; ++j
                    ) {
                    temp[j][mnSize - 1 - i] = currentPieces[i][j];
                }
            }

            memcpy(currentPieces, temp, sizeof(temp));

        }

        //�ʱ�ȭ
        memcpy(currentPieces, Pieces, sizeof(currentPieces));

        if (xStart < bSize - mnSize)
        {
            ++xStart;
        }
        else
        {
            //x�� ������ ��ȸ�ߴ�.
            if (yStart < bSize - mnSize)
            {
                ++yStart;
                xStart = 0;
            }

            else
            {
                //���带 ���� ��ȸ�ߴ�.
                break;
            }

        }

    }


	return res;
}