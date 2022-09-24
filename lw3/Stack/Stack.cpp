#include <iostream>

using namespace std;

struct Node
{
	char data;
	Node* next;
};

struct Stack
{
	int size;
	Node* head;
};

void InitStack(Stack* S)
{
	S->head = new Node;
	S->head->next = NULL;
	S->size = 0;
}

void GetHead(Stack* S)
{
	cout << "Верхний элемент стека: " << S->head->data << endl;
}

void Pop(Stack* S)
{
	Node* temp;
	cout << "Верхний элемент стека: " << S->head->data << endl;
	temp = S->head->next;
	delete(S->head);
	S->head = temp;
	delete(temp);
	S->size--;
}

void Push(Stack* S, char item)
{
	S->head->next = new Node();
	S->head = S->head->next;
	S->head->data = item;
	S->head->next = NULL;
	S->size++;
}

bool IsEmpty(Stack* S)
{
	if (S->size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

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
