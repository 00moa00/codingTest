
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


		//커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
		if (cmd == "L")
		{
			if (cursor > 0)
			{
				--cursor;
			}
		}

		//커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
		if (cmd == "D")
		{
			if (cursor < text.size()) 
			{
				cursor++;
			}
		}

		//	커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
		//삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임
		if (cmd == "B")
		{
			
			if (cursor > 0)
			{
				text.erase(cursor - 1, 1);
				--cursor;
			}

			//일단 삭제
			//string buff;

			////커서가 문장의 맨 앞이면 무시
			//if (cursor != 0)
			//{
			//	//맨 앞에 있는 문자라면 앞글자 삭제
			//	if (cursor - 2 <= 0)
			//	{
			//		buff = text.substr(1);
			//	}

			//	//맨 뒤에 있는 문자라면
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


			////문자열 잘라내기
			////cmd = cmd.substr(2);
			//cin >> cmd;

			////중간에 추가하기
			//string buff;

			////만약 마지막글자라면
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

			////커서도 증가
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