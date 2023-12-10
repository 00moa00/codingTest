
#include <iostream>
#include <algorithm>
//#include <string>
#include <vector>
#include <map>
#include <unordered_map>
//#include <stack>
//#include <queue>
//#include <tuple>
#include <cctype>

using namespace std;

int vcnt;   //모음
int ccnt;   //자음
bool v = false;     //모음 들어갔는지 체크

bool ret = true;

string InputStr;


bool vCheck(char str)
{
    if (str == 'a' || str == 'e' || str == 'i' || str == 'o' || str == 'u')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    while (true)
    {
        cin >> InputStr;
        if (InputStr == "end")
        {
            break;
        }

        //초기화
        vcnt = 0;
        ccnt = 0;
        ret = true;
        v = false;

        for (int i = 0; i < InputStr.size(); i++)
        {
            //소문자로 바꿔주는 함수
            if (vCheck(tolower(InputStr[i])))
            {
                v = true;
                ccnt = 0;
                vcnt += 1;

            }
            else
            {
                vcnt = 0;
                ccnt += 1;
            }

            //모음 혹은 자음이 연속 3번으로 들어오면 false
            if (ccnt >= 3 || vcnt >= 3)
            {
                ret = false;
                break;
            }

            //3. 연속된 같은 문자열 체크
            if (i > 0 && InputStr[i] == InputStr[i - 1])
            {
                string checkStr3 = (i > 1) ? string(1, InputStr[i - 2]) : " ";
                string check = string(1, InputStr[i]) + InputStr[i - 1] + checkStr3;

                if (check.find("ee") != std::string::npos || check.find("oo") != std::string::npos)
                {
                    if (check == ("eee") || check == ("ooo"))
                    {
                        ret = false;
                        break;
                    }

                    continue;
                }

                ret = false;
                break;
            }
        }

        if (ret == false || v == false)
        {
            cout << "<" << InputStr << ">" << " is not acceptable.\n";
        }
        else
        {
            cout << "<" << InputStr << ">" << " is acceptable.\n";
        }
    }

    return 0;
}