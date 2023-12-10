
#include <iostream>
#include <algorithm>
//#include <string>
#include <vector>
#include <string>

//#include <map>
//#include <unordered_map>
//#include <stack>
//#include <queue>
//#include <tuple>
//#include <cctype>

using namespace std;

int n;
vector<string> Nember;

bool cmp(string a, string b) 
{
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

string processNumber(const string& numText)
{
    // 맨 앞의 숫자가 0이면서 0이 여러 개인 경우 처리
    int cnt = 0;
    while (cnt < numText.size() && numText[cnt] == '0')
    {
        cnt++;
    }

    string result = numText.substr(cnt);

    if (result.empty())
    {
        result = "0"; // 숫자가 모두 0인 경우
    }

    return result;
}


int main() 
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string InputText = "";
        string NumText = "";

        cin >> InputText;

        for (int j = 0; j < InputText.size(); j++)
        {
            //숫자만 넣기
            if (isdigit(InputText[j]))
            {
                NumText += InputText[j];
            }

            //숫자가 아니라면 그동안 저장한 것들 넣기
            else
            {
                if (!NumText.empty())
                {
                    Nember.push_back(processNumber(NumText));
                    NumText.clear();
                }
            }
        }

        // 입력 문자열이 숫자로 끝나는 경우(else문에 들어가지 않으니까)에 대한 처리
        if (!NumText.empty())
        {
            Nember.push_back(processNumber(NumText));
            NumText.clear();
        }
    }

    std::sort(Nember.begin(), Nember.end(), cmp);

    for (const auto& n : Nember)
    {
        cout << n << '\n';
    }

    return 0;
}