// 1129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <map>

int main()
{
    int cnt[26] = { 0, };      
    std::string Keyword;

    std::string mid, front, back;

    std::cin >> Keyword;
    for (int i = 0; i < Keyword.size(); i++)
    {
        cnt[Keyword[i] - 'A'] ++;
    }

    int oddNumber = 0;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] == 0)
        {
            continue;
        }
        if (cnt[i] & 1)
        {
            mid += char(i+ 'A');
            oddNumber++;
        }
    }

    if (oddNumber >= 2)
    {
        std::cout << "I'm Sorry Hansoo\n";
    }
    else
    {
        for (int i = 'A'; i <= 'Z'; i++)
        {
            if (cnt[i - 'A' ] > 1)
            {
                char temp = char(i);
                for (int j = 0; j < cnt[i - 'A'] / 2; j++)
                {
                    front += temp;
                }                
            }           
        }

        back = front;
        std::reverse(back.begin(), back.end());

        std::cout << front + mid + back;
    }
}
