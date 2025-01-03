#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include<string>

#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <sstream>
#include <list>
#include <set>

using namespace std;


//프로그래머스 프렌즈 4블록
int solution(int m, int n, vector<string> board)
{
    int answer = 0;

    // 반복적으로 블록을 제거
    while (true)
    {
        set<pair<int, int>> toRemove; // 제거할 블록 위치 저장

        // 2x2 블록 탐색
        for (int i = 0; i < m - 1; ++i)
        {
            for (int j = 0; j < n - 1; ++j)
            {
                char current = board[i][j];

                if (current != '0'
                    && current == board[i][j + 1]
                    && current == board[i + 1][j]
                    && current == board[i + 1][j + 1])
                {
                    // 2x2 블록 위치 추가
                    toRemove.insert({ i, j });
                    toRemove.insert({ i, j + 1 });
                    toRemove.insert({ i + 1, j });
                    toRemove.insert({ i + 1, j + 1 });
                }
            }
        }

        // 제거할 블록이 없으면 종료
        if (toRemove.empty()) break;

        // 블록 제거
        for (auto& pos : toRemove)
        {
            board[pos.first][pos.second] = '0'; // 제거된 블록을 '0'으로 표시
        }

        // 제거된 블록 개수 누적
        answer += toRemove.size();

        // 블록 떨어뜨리기
        for (int j = 0; j < n; ++j)
        {
            string column = "";
            // 열을 위에서 아래로 스캔하여 블록만 남김
            for (int i = 0; i < m; ++i)
            {
                if (board[i][j] != '0')
                {
                    column += board[i][j];
                }
            }
            // 빈 공간은 위쪽에 '0'으로 채우고 나머지 블록 아래로 채움
            int emptySpaces = m - column.size();
            for (int i = 0; i < emptySpaces; ++i)
            {
                board[i][j] = '0';
            }
            for (int i = 0; i < column.size(); ++i)
            {
                board[emptySpaces + i][j] = column[i];
            }
        }
    }

    return answer;
};

vector<string> split (const string& _s, const char _find)
{
    vector<string> ret;
    string temp;

    for (char c : _s)
    {
        if (c == _find)
        {
            ret.push_back(temp);
            temp.clear();
        }
        else 
        {
            temp += c;
        }
    }

    if (!temp.empty()) 
    {
        ret.push_back(temp);
    }

    return ret;

}


vector<string> solution(vector<string> record) 
{
    vector<string> answer;
    map<string, string> InfoList; //first: ID, second : 닉네임

    vector<pair<string, string>> commandlist; //first: ID, second : command

    for (auto s : record)
    {
        vector <string> info = split(s, ' ');
        commandlist.push_back({info[1], info[0]});

        if (info.size() > 2)
        {
            InfoList[info[1]] = info[2];

        }
    }

    for (auto list : commandlist)
    {
        string chat = InfoList[list.first] + "님이 ";
        string cmd = list.second;
        if (cmd == "Enter")
        {
            chat += "들어왔습니다.";
        }
        else if (cmd == "Leave")
        {
            chat += "나갔습니다.";
        }

        else if (cmd == "Change")
        {
            continue;
        }

        answer.push_back(chat);
    }

    return answer;
}


int main()
{
    solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });
    //solution(4,4, { "CCBDE", "AAADE", "AAABF", "CCBBF"});
    return 0;
}



// 문자열의 길이를 구하는 함수
int getStringLength(const char* str)
{
    int length = 0;

    // 널 종료 문자를 만날 때까지 카운트
    while (str[length] != '\0') {
        ++length;
    }

    return length;
}


// 특정 문자열이 주어진 위치에서 시작되는지 확인
bool startsWith(const char* str, const char* prefix) 
{
    int prefixLength = getStringLength(prefix);
    for (int i = 0; i < prefixLength; ++i) 
    {
        if (str[i] != prefix[i]) {
            return false;
        }
    }
    return true;
}


bool FindText(const char* _input, const char* _find)
{
    int length = 0;
    int findEndCound = getStringLength(_find);
    int findCount = 0;
    // 널 종료 문자를 만날 때까지 카운트
    while (_input[length] != '\0') 
    {

        if (_input[length] == _find[findCount])
        {
            ++findCount;
            if (findEndCound == findCount)
            {
                return true; // 매칭 성공
            }
        }

        else
        {
            findCount = 0;
        }
        ++length;

    }

    return false; // 매칭 실패

}

// 두 점을 연결하는 방향 벡터를 계산
vector<int> getVector(const vector<int>& a, const vector<int>& b) {
    return {b[0] - a[0], b[1] - a[1]};
}

// 두 벡터가 평행한지 확인 (외적 계산)
bool areParallel(const vector<int>& v1, const vector<int>& v2) {
    return v1[0] * v2[1] - v1[1] * v2[0] == 0;
}

//최대공약수
int fun(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    else
    {
        return fun(b, a % b);
    }
}

//최소공배수
int fun2(int a, int b)
{
    return (a * b) / fun(a , b);
}
