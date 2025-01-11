// codingTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{

    long long answer = 0;

    int d_index = n - 1;
    int p_index = n - 1;

    while (d_index >= 0 || p_index >= 0)
    {
        // 마지막으로 방문해야 할 배달/수거 위치 찾기
        while (d_index >= 0 && deliveries[d_index] == 0)
        {
            --d_index;
        }
        while (p_index >= 0 && pickups[p_index] == 0)
        {
            --p_index;
        }

        // 왕복 거리 계산
        int max_distance = max(d_index, p_index) + 1;
        answer += max_distance * 2;

        // 배달 처리
        int remaining_cap = cap;
        while (d_index >= 0 && remaining_cap > 0)
        {
            if (deliveries[d_index] <= remaining_cap) 
            {
                remaining_cap -= deliveries[d_index];
                deliveries[d_index] = 0;
                --d_index;
            }
            else {
                deliveries[d_index] -= remaining_cap;
                remaining_cap = 0;
            }
        }

        // 수거 처리
        remaining_cap = cap;
        while (p_index >= 0 && remaining_cap > 0) 
        {
            if (pickups[p_index] <= remaining_cap) 
            {
                remaining_cap -= pickups[p_index];
                pickups[p_index] = 0;
                --p_index;
            }
            else
            {
                pickups[p_index] -= remaining_cap;
                remaining_cap = 0;
            }
        }
    }

    return answer;
}

