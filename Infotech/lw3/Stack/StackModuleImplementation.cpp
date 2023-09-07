#include <iostream>
#include "StackModuleInterface.h"

using namespace std;

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

void Push(Stack* S, StackType item)
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