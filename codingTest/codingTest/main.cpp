#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <vector>
#include <chrono> // 시간 측정 라이브러리
#include <iostream>
using namespace std;
using namespace chrono; // 편리성을 위해 chrono 네임스페이스 사용

#define INIT			(100)
#define DROP_BLOCKS		(200)
#define CHANGE_BLOCKS	(300)
#define GET_RESULT		(400)

extern void init(int W, int H);
extern int dropBlocks(int mPlayer, int mCol);
extern int changeBlocks(int mPlayer, int mCol);
extern int getResult(int mBlockCnt[2]);

static bool run()
{
	int Q, W, H;

	int mPlayer, mCol;

	int ret = -1, ans;
	int mBlockCnt[2] = {};
	int r1, r2;

	scanf("%d", &Q);

	bool okay = false;
	for (int q = 0; q < Q; ++q)
	{
		int cmd;
		scanf("%d", &cmd);
		switch (cmd)
		{
		case INIT:
			scanf("%d %d", &W, &H);
			init(W, H);
			okay = true;
			break;
		case DROP_BLOCKS:
			scanf("%d %d", &mPlayer, &mCol);
			if (okay)
				ret = dropBlocks(mPlayer, mCol);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;
		case CHANGE_BLOCKS:
			scanf("%d %d", &mPlayer, &mCol);
			if (okay)
				ret = changeBlocks(mPlayer, mCol);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;
		case GET_RESULT:
			if (okay)
				ret = getResult(mBlockCnt);
			scanf("%d %d %d", &ans, &r1, &r2);
			if (ans != ret || mBlockCnt[0] != r1 || mBlockCnt[1] != r2)
				okay = false;
			break;
		default:
			okay = false;
			break;
		}
	}

	return okay;
}

int main()
{


	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d%d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{    // 시간 측정 시작
		auto start = high_resolution_clock::now();

		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);

		// 시간 측정 끝
		auto end = high_resolution_clock::now();

		// 경과 시간 계산
		auto duration = duration_cast<milliseconds>(end - start);
		cout << "getScore() Time: " << duration.count() << " ms" << endl;
	}

	return 0;
}