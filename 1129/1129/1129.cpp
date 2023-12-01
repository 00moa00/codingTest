// 1129.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <map>

int main()
{
	int n; //해빈이가 가진 의상의 수
    int t; //테스트 케이스

    std::string Clothes, Type;
    std::cin >> t; 

    while (t--) 
    {
        std::map<std::string, int> _map;
        std::cin >> n;

        //의상의 수만큼
        for (int i = 0; i < n; i++) 
        {
            std::cin >> Clothes >> Type;

            //해당 종류의 개수 추가
            _map[Type]++;
        }

        //경우의 수는 커질 수 있기 때문에 long long
        long long ret = 1;

        for (auto c : _map) 
        {
            //종류마다 아무것도 안입는 경우
            ret *= ((long long)c.second + 1);
        }

        //모든 종류의 옷을 아무것도 안입는 경우
        ret--;
        std::cout << ret << "\n";
    }

    return 0;
}
