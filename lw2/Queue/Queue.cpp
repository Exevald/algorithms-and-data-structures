#include <iostream>
using namespace std;

struct Node
{
	char data;
	Node* next;
};

struct Queue
{
	int size;
	Node* first;
	Node* last;
};

void InitQueue(Queue* Q)
{
	Q->first = new Node;
	Q->first->next = NULL;
	Q->last = Q->first;
	Q->size = 0;
}

int GetHead(Queue* Q)
{
	char head = Q->first->next->data;
	cout << "Верхний элемент очереди: " << head << endl;
	return head;
}

int DelHead(Queue* Q)
{
	char head = Q->first->next->data;
	Q->first = Q->first->next;
	Q->size--;
	cout << "Верхний элемент очереди: " << head << endl;
	return head;
}

void Add(Queue* Q, char item)

{
	Q->last->next = new Node;
	Q->last = Q->last->next;
	Q->last->data = item;
	Q->last->next = NULL;
	Q->size++;
}

bool IsFull(Queue* Q)
{
	return ((Q->first == Q->last) && Q->size != 0);
}

bool IsEmpty(Queue* Q)
{
	return (Q->size == 0);
}

int main()
{
	setlocale(LC_ALL, "ru");
	Queue queue;
	char answer;
	char item;

	InitQueue(&queue);

	do {
		puts("Введите 1, чтобы добавить элемент в очередь");
		puts("Введите 2, чтобы вывести верхний элемент и удалить его из очереди");
		puts("Введите 3, чтобы вывести верхний элемент без удаления из очереди");
		puts("Введите 0, чтобы выйти из программы");

		cin >> answer;

		switch (answer)
		{
		case '1':
			if (IsFull(&queue))
			{
				puts("Очередь полная!");
			}
			else
			{
				puts("Введите элемент для вставки в очерредь: ");
				cin >> item;
				Add(&queue, item);
			}
			break;
		case '2':
			if (IsEmpty(&queue))
			{
				puts("Очередь пустая!");
			}
			else 
			{
				DelHead(&queue);
				break;
			}
		case '3':
			if (IsEmpty(&queue))
			{
				puts("Очередь пустая!");
			}
			else
			{
				GetHead(&queue);
				break;
			}
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
