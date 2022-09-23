#include "QueueModuleInterface.h"

bool IsEmpty(Queue* Q)
{
	if (Q == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GetHead(Queue* Q)
{
	cout << "Верхний элемент очереди: " << Q->item << endl;
}

void Add(Queue*& Q, QueueType item)
{
	if (Q == NULL)
	{
		Q = new Queue;
		Q->item = item;
		Q->next = NULL;
	}
	else
	{
		Add(Q->next, item);
	}
}

void DelHead(Queue*& Q)
{
	struct Queue* temp = new Queue;

	cout << "Верхний элемент очереди: " << Q->item << endl;
	temp = Q->next;
	delete(Q);
	Q = temp;
	delete(temp);
}

void PrintQueue(Queue* Q) {
	if (Q != NULL)
	{
		cout << Q->item << " ";
		PrintQueue(Q->next);
	}
}