// 1129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

int main() 
{
    int memberCount = 0;    //멤버수
    int cnt[26] = {0,};            //알파벳
    std::string memberName;          //멤버 이름
    std::string ret;

    std::cin >> memberCount;
    for (int i = 0; i < memberCount; i++)
    {
        std::cin >> memberName;
        cnt[memberName[0] - 'a'] ++;    //첫글자만 필요
    }

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] >= 5)
        {
            ret += i + 'a';
        }
    }

    if (ret.size())
    {
        std::cout << ret << "\n";
    }
    else
    {
        std::cout << "PREDAJA" << "\n";
    }
}