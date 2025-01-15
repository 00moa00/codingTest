#include <string>
#include <vector>
#include <tuple>


using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    vector<vector<int>> matrix(rows, vector<int>(columns));

    // 행렬 초기화
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < columns; ++j)
        {
            matrix[i][j] = i * columns + j + 1;
        }
    }

    // 쿼리 처리
    for (const auto& query : queries) 
    {
        int x1 = query[0] - 1, y1 = query[1] - 1;
        int x2 = query[2] - 1, y2 = query[3] - 1;

        int prev = matrix[x1][y1];
        int m = prev;

        // 상단 테두리 이동
        for (int y = y1 + 1; y <= y2; ++y)
        {
            swap(matrix[x1][y], prev);
            m = min(m, prev);
        }

        // 오른쪽 테두리 이동
        for (int x = x1 + 1; x <= x2; ++x) 
        {
            swap(matrix[x][y2], prev);
            m = min(m, prev);
        }

        // 하단 테두리 이동
        for (int y = y2 - 1; y >= y1; --y)
        {
            swap(matrix[x2][y], prev);
            m = min(m, prev);
        }

        // 왼쪽 테두리 이동
        for (int x = x2 - 1; x >= x1; --x)
        {
            swap(matrix[x][y1], prev);
            m = min(m, prev);
        }

        answer.push_back(m);
    }

    return answer;
}

//
//int main()
//{
//    solution(6, 6, { {2, 2, 5, 4},{3, 3, 6, 6},{5, 1, 6, 3} });
//        
//}