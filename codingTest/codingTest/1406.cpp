#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    string initial;
    int n;

    // �ʱ� ���ڿ��� ��ɾ� ���� �Է�
    cin >> initial;
    cin >> n;

    // �ʱ� ���ڿ��� list�� ��ȯ
    list<char> text(initial.begin(), initial.end());
    auto cursor = text.end(); // Ŀ���� ���ڿ��� �� �ڷ� ����

    while (n--)
    {
        string command;
        cin >> command;

        if (command == "L") 
        {
            // Ŀ���� �������� �̵�
            if (cursor != text.begin())
            {
                --cursor;
            }
        }
        else if (command == "D") 
        {
            // Ŀ���� ���������� �̵�
            if (cursor != text.end())
            {
                ++cursor;
            }
        }
        else if (command == "B") 
        {
            // Ŀ�� ������ ���� ����
            if (cursor != text.begin())
            {
                --cursor;
                cursor = text.erase(cursor); 
               
            }
        }
        else if (command == "P") 
        {
            // Ŀ�� ��ġ�� ���� ����
            char toInsert;
            std::cin >> toInsert;

            text.insert(cursor, toInsert);
        }
    }

    // ��� ���
    for (char c : text) 
    {
        cout << c;
    }

    return 0;
}
