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
	cout << "������� ������� �����: " << S->head->data << endl;
}

void Pop(Stack* S)
{
	Node* temp;
	cout << "������� ������� �����: " << S->head->data << endl;
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
