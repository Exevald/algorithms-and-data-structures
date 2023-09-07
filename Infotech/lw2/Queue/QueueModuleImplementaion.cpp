#include "QueueModuleInterface.h"

void InitQueue(Queue* Q)
{
	Q->head = new Node();
	Q->head->next = NULL;
	Q->tail = Q->head;
}

bool IsEmpty(Queue* Q)
{
	if (Q == NULL)
	{
		return 1;
	}
}

void GetHead(Queue* Q)
{
	cout << "Верхний элемент очереди: " << Q->head->next->item << endl;
}

void Add(Queue* Q, QueueType item)
{
	Q->tail->next = new Node();
	Q->tail = Q->tail->next;
	Q->tail->item = item;
	Q->tail->next = NULL;
}

void DelHead(Queue* Q)
{
	Node* temp;
	cout << "Верхний элемент очереди: " << Q->head->next->item << endl;
	temp = Q->head->next;
	delete(Q->head);
	Q->head = temp;
	delete(temp);
}