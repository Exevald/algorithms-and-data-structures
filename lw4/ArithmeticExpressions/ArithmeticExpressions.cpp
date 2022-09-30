#include <iostream>
#include <fstream>
#include <map>
#include <stack>
#define StackType char

using namespace std;

int main()
{
	int i = 0, j = 0;
	StackType ch;

	ifstream inputFile("input.txt");
	stack <StackType> tempStack;

	map<StackType, int> PriorityDict =
	{
		{'(', 0},
		{'+', 1},
		{'-', 1},
		{'*', 2},
		{'/', 2},
		{'^', 3},
	};
	map<StackType, int> ::iterator tempIterator;

	setlocale(LC_ALL, "rus");

	if (!inputFile.is_open())
	{
		puts("Не удалось открыть файл для чтения");
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

	return 0;
}