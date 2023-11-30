// 1129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>

int main() 
{
    std::string str;

    std::getline(std::cin, str);
    for (int i = 0; i < str.size(); i++)
    {
        // 대문자
        if (str[i] >= 65 && str[i] < 97)
        {
            if (str[i] + 13 > 90)
            {
                str[i] = str[i] + 13 - 26;
            }
            else
            {
                str[i] = str[i] + 13;
            }
        }

        else if (str[i] >= 97 && str[i] <= 122)
        {
            if (str[i] + 13 > 122)
            {
                str[i] = str[i] + 13 - 26;
            }
            else
            {
                str[i] = str[i] + 13;
            }
        }
        std::cout << str[i];
    }

    return 0;
}