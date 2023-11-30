// 1129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	int count = 0;			//과목수

	std::cin >> count;
	float* scorePtr = new float[count];

	for (int i = 0; i < count; i++)
	{
		std::cin >> scorePtr[i];
	}
	
	float max = scorePtr[0];
	float prevMax;
	for (int i = 1; i < count; i++)
	{
		if (scorePtr[i] > max)
		{
			max = scorePtr[i];
		}
	}

	for (int i = 0; i < count; i++)
	{
		scorePtr[i] = (scorePtr[i] / max) * 100;
	}

	float TotalScore = 0.f;
	for (int i = 0; i < count; i++)
	{
		TotalScore += scorePtr[i];
	}

	float result = TotalScore / count;
	std::cout << result;
}

