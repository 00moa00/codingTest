#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    string initial;
    int n;

    // 초기 문자열과 명령어 개수 입력
    cin >> initial;
    cin >> n;

    // 초기 문자열을 list로 변환
    list<char> text(initial.begin(), initial.end());
    auto cursor = text.end(); // 커서를 문자열의 맨 뒤로 설정

    while (n--)
    {
        string command;
        cin >> command;

        if (command == "L") 
        {
            // 커서를 왼쪽으로 이동
            if (cursor != text.begin())
            {
                --cursor;
            }
        }
        else if (command == "D") 
        {
            // 커서를 오른쪽으로 이동
            if (cursor != text.end())
            {
                ++cursor;
            }
        }
        else if (command == "B") 
        {
            // 커서 왼쪽의 문자 삭제
            if (cursor != text.begin())
            {
                --cursor;
                cursor = text.erase(cursor); 
               
            }
        }
        else if (command == "P") 
        {
            // 커서 위치에 문자 삽입
            char toInsert;
            std::cin >> toInsert;

            text.insert(cursor, toInsert);
        }
    }

    // 결과 출력
    for (char c : text) 
    {
        cout << c;
    }

    return 0;
}
