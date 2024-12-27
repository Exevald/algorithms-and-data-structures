#include <iostream>
#include <fstream>
#include <map>
#include <stack>
#define StackType char

using namespace std;

int ArithmExpr(string inf)
{
	stack <StackType> tempStack;
	map<StackType, int> PriorityDict =
	{
		{'(', 0},
		{'+', 1},
		{'-', 1},
		{'*', 2},
		{'/', 2},
	};
	map<StackType, int> ::iterator tempIterator;
	ifstream inputFile(inf);

	StackType ch;

	if (!inputFile.is_open())
	{
		puts("�� ������� ������� ���� ��� ������");
		return 1;
	}
	while (inputFile.get(ch))
	{
		if ((ch >= '0') && (ch <= '9'))
		{
			cout << ch;
		}
		else
		{
			if (ch == '(')
			{
				tempStack.push(ch);
			}
			else
			{
				if (ch == ')')
				{
					while (!tempStack.empty() && (tempStack.top() != '('))
					{
						cout << tempStack.top();
						tempStack.pop();
					}
					tempStack.pop();
				}
				else
				{
					tempIterator = PriorityDict.find(ch);
					if (tempIterator != PriorityDict.end())
					{
						while ((!tempStack.empty()) && PriorityDict[tempStack.top()] >= PriorityDict[ch])
						{
							cout << tempStack.top();
							tempStack.pop();
						}
						tempStack.push(ch);
					}
				}
			}
		}
	}

	while (!tempStack.empty())
	{
		cout << tempStack.top();
		tempStack.pop();
	}
	cout << endl;

	inputFile.close();
}

int main()
{
	setlocale(LC_ALL, "rus");

	ArithmExpr("physicalEffectsInput.txt");

	return 0;
}