#include <iostream>
#include "QueueModuleInterface.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	Queue* queue;
	char answer;
	QueueType item;

	queue = NULL;

	do {
		puts("Введите 1, чтобы добавить элемент в очередь");
		puts("Введите 2, чтобы вывести верхний элемент и удалить его из очереди");
		puts("Введите 3, чтобы вывести верхний элемент без удаления из очереди");
		puts("Введите 4, чтобы вывести всю очередь");
		puts("Введите 0, чтобы выйти из программы");

		cin >> answer;

		switch (answer)
		{
		case '1':
			puts("Введите элемент для вставки в очередь: ");
			cin >> item;
			Add(queue, item);
			break;
		case '2':
			if (IsEmpty(queue))
			{
				puts("Очередь пустая!");
			}
			else
			{
				DelHead(queue);
			}
			break;
		case '3':
			GetHead(queue);
			break;
		case '4':
			PrintQueue(queue);
			cout << endl;
			break;
		case '0':
			puts("Выход");
			break;
		default:
			puts("Команда не определена!");
			break;
		}
	} while (answer != '0');

	return 0;
}