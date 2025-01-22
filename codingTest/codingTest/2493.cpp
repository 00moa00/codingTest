#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> fun(const vector<int>& heights)
{
    int n = heights.size();
    vector<int> result(n);
    stack<pair<int, int>> s;

    for (int i = 0; i < n; ++i)
    {

        // ���� ž�� ���̺��� ���� ž�� ����
        while (s.empty() == false && s.top().first < heights[i])
        {
            s.pop();
        }

        // �������� ��� ù ��° ž�� ����� ����
        if (s.empty())
        {
            result[i] = 0; // ��� ž�� ����
        }
        else
        {
            result[i] = s.top().second + 1; // 1-based index
        }

        // ���� ž�� ���ÿ� �߰�
        s.push({ heights[i], i });
    }

    return result;
}

//int main()
//{
//    int n;
//    cin >> n;
//
//    vector<int> heights(n);
//
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> heights[i];
//    }
//
//    vector<int> result = fun(heights);
//
//    for (int i = 0; i < n; ++i)
//    {
//        cout << result[i] << " ";
//    }
//
//    cout << endl;
//
//    return 0;
//}
