
#include <iostream>
#include <vector>

using namespace std;



int main()
{


	string text = "";
	int cursor = 0 ;
	int cursorMax = 0;
	int cursorMin = 0;

	cin >> text;

	cursorMax = text.size();
	cursor = cursorMax;

	int count;

	cin >> count;
	count += 1;

	while (--count)
	{	
		string cmd;
		cin >> cmd;


		//Ŀ���� �������� �� ĭ �ű� (Ŀ���� ������ �� ���̸� ���õ�)
		if (cmd == "L")
		{
			if (cursor > 0)
			{
				--cursor;
			}
		}

		//Ŀ���� �������� �� ĭ �ű� (Ŀ���� ������ �� ���̸� ���õ�)
		if (cmd == "D")
		{
			if (cursor < text.size()) 
			{
				cursor++;
			}
		}

		//	Ŀ�� ���ʿ� �ִ� ���ڸ� ������ (Ŀ���� ������ �� ���̸� ���õ�)
		//������ ���� Ŀ���� �� ĭ �������� �̵��� ��ó�� ��Ÿ������, ������ Ŀ���� �����ʿ� �ִ� ���ڴ� �״����
		if (cmd == "B")
		{
			
			if (cursor > 0)
			{
				text.erase(cursor - 1, 1);
				--cursor;
			}

			//�ϴ� ����
			//string buff;

			////Ŀ���� ������ �� ���̸� ����
			//if (cursor != 0)
			//{
			//	//�� �տ� �ִ� ���ڶ�� �ձ��� ����
			//	if (cursor - 2 <= 0)
			//	{
			//		buff = text.substr(1);
			//	}

			//	//�� �ڿ� �ִ� ���ڶ��
			//	if (cursor == cursorMax)
			//	{
			//		buff = text.substr(0, cursor);
			//	}

			//	else
			//	{
			//		buff = text.substr(0, cursor - 2);
			//		buff += text.substr(cursor + 1);
			//	}

			//	text = buff;

			//	int temp = text.size();

			//	if (temp > cursor)
			//	{
			//		cursor = temp;
			//	}

			//	cursorMax = temp;

			//}

			//if (cursor < cursorMax)
			//{
			//	++cursor;
			//}
		}

		if (cmd == "P")
		{

			char toInsert;
			cin >> toInsert;
			text.insert(cursor, 1, toInsert);
			++cursor;


			////���ڿ� �߶󳻱�
			////cmd = cmd.substr(2);
			//cin >> cmd;

			////�߰��� �߰��ϱ�
			//string buff;

			////���� ���������ڶ��
			//if (cursor == cursorMax)
			//{
			//	buff = text;
			//	buff += cmd;
			//}

			//else
			//{
			//	for (int i = 0; i < text.size(); ++i)
			//	{
			//		if (cursor == i)
			//		{
			//			buff += cmd;
			//		}

			//		buff += text[i];
			//	}
			//}

			////Ŀ���� ����
			//++cursor;

			//int temp = buff.size();

			//if (temp < cursor)
			//{
			//	cursor = temp;
			//}
			//text = buff;
			//cursorMax = temp; 
		}



	}

	std::cout << text;
	

}