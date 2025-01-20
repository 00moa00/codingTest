#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int count = 0;
	int ret = 0;

	std::cin >> count;

	stack<int> numStack;

	while (count--)
	{
		int num = 0;
		cin >> num;

		if (num == 0 && numStack.empty() == false)
		{
			numStack.pop();
		}

		else
		{
			numStack.push(num);
		}

	}

	while (numStack.empty() == false)
	{
		ret += numStack.top();
		numStack.pop();
	}

	std::cout << ret;

}