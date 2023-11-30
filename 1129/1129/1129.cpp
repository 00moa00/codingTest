// 1129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

std::string s, temp;
int main() 
{
    std::cin >> s;
    temp = s;
    reverse(temp.begin(), temp.end());
    if (temp == s)
    {
        std::cout << 1 << "\n";
    }
    else
    {
        std::cout << 0 << "\n";
    }
    return 0;
}