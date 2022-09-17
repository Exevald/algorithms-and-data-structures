#include "QueueModuleInterface.h"

void InitQueue(Queue* Q)
{
	Q->head = new Node;
	Q->head->next = NULL;
	Q->tail = Q->head;
	Q->size = 0;
}

void GetHead(Queue* Q)
{
	QueueType head = Q->head->next->data;
	cout << "Верхний элемент очереди: " << head << endl;
}

void DelHead(Queue* Q)
{
	char head = Q->head->next->data;
	Q->head = Q->head->next;
	Q->size--;
	cout << "Верхний элемент очереди: " << head << endl;
}

void Add(Queue* Q, char item)

{
	Q->tail->next = new Node;
	Q->tail = Q->tail->next;
	Q->tail->data = item;
	Q->tail->next = NULL;
	Q->size++;
}

bool IsEmpty(Queue* Q)
{
	return (Q->size == 0);
}