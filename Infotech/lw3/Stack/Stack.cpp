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
		puts("Введите 1, чтобы добавить элемент в стек");
		puts("Введите 2, чтобы вывести верхний элемент и удалить его из стека");
		puts("Введите 3, чтобы вывести верхний элемент без удаления из стека");
		puts("Введите 0, чтобы выйти из программы");

		cin >> answer;
		switch (answer)
		{
		case '1':
			cout << "Введите элемент для вставки в стек: ";
			cin >> item;
			Push(&stack, item);
			break;
		case '2':
			if (IsEmpty(&stack))
			{
				puts("Стек пуст");
			}
			else
			{
				Pop(&stack);
			}
			break;
		case '3':
			if (IsEmpty(&stack))
			{
				puts("Стек пуст");
			}
			else
			{
				GetHead(&stack);
			}
			break;
		case '0':
			break;
		default:
			puts("Команда не определена");
			break;
		}

	} while (answer != '0');

	return 0;
}
