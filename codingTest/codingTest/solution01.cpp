#include <iostream>

using namespace std;
#define MAX_N 1000
#define MAX_M 20

int bSize = 0;
int mnSize = 0;


//미니조각 배율
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

//M * M 크기의 보물상자 조각 지도 Pieces[][] 의 기준 보물 좌표를 리턴한다.
//Pieces[][] 조각 지도에서 기준 보물은 9 로 표시 되어 있다.
//Pieces[][] 조각 지도에서 기준 보물은 반드시 1개이다.
//Pieces[][] 조각 지도는 1, 9, 0 으로 구성되어 있고, 보물은 1 또는 9 로 표시 되어 있다.
//Pieces[][] 조각 지도에서 보물의 개수는 5 이상 20 이하이다.
//Pieces[][] 조각 지도는 지도상에서 90도, 180도, 270도 회전되어서 존재할 수 있으며, 리턴하는 결과값이 1개임이 반드시 보장된다.
//또한, 동일한 조각 지도에 대해서 findTreasureChest() 함수가 두 번 이상 호출되는 경우는 없다

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
            //초기화
            res.y = res.x = -1;

            int mnY = 0;
            int mnX = 0;
           

            //보드 순회
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

                    //일치하는 지 검사
                    if (b[i][j] == currentPieces[mnY][mnX])
                    {
                    
                        bIsmatched = true;
                    }

                    //보물이 있는 상자
                    else if (currentPieces[mnY][mnX] == 9 && b[i][j] == 1)
                    {
                        bIsmatched = true;

                        res.y = i;
                        res.x = j;

                    }

                    //else
                    //{
                    //    //하나라도 일치하지 않는다면 for문 종료
                    //    bIsmatched = false;
                    //    break;
                    //}

                    //미니맵 X증가

                    ++mnX;
                }

                if (matchedCount != matchedCount)
                {
                    bIsmatched = false;
                    break;

                }
                //미니맵 Y증가
                ++mnY;
                mnX = 0;


            }

            //다 순회했는데 모두가 일치했다. 그러면 보물을 찾은것이다.
            if (bIsmatched == true && matchedCount == chestCount)
            {
                return res;

            }


            //못찾았으면 일단 회전을 해본다.
            //근데 이미 회전 카운트를 다 소비했다면 종료
            if (rotationCount > 3)
            {
                bIsmatched = false;
                break;
            }

            ++rotationCount;

            //초기화
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

        //초기화
        memcpy(currentPieces, Pieces, sizeof(currentPieces));

        if (xStart < bSize - mnSize)
        {
            ++xStart;
        }
        else
        {
            //x를 끝까지 순회했다.
            if (yStart < bSize - mnSize)
            {
                ++yStart;
                xStart = 0;
            }

            else
            {
                //보드를 전부 순회했다.
                break;
            }

        }

    }


	return res;
}