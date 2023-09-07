#include <iostream>
#include "StackModuleInterface.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	Stack stack;
	char answer;
	char item;

	InitStack(&stack);

	do
	{
		puts("������� 1, ����� �������� ������� � ����");
		puts("������� 2, ����� ������� ������� ������� � ������� ��� �� �����");
		puts("������� 3, ����� ������� ������� ������� ��� �������� �� �����");
		puts("������� 0, ����� ����� �� ���������");

		cin >> answer;
		switch (answer)
		{
		case '1':
			cout << "������� ������� ��� ������� � ����: ";
			cin >> item;
			Push(&stack, item);
			break;
		case '2':
			if (IsEmpty(&stack))
			{
				puts("���� ����");
			}
			else
			{
				Pop(&stack);
			}
			break;
		case '3':
			if (IsEmpty(&stack))
			{
				puts("���� ����");
			}
			else
			{
				GetHead(&stack);
			}
			break;
		case '0':
			break;
		default:
			puts("������� �� ����������");
			break;
		}

	} while (answer != '0');

	return 0;
}
