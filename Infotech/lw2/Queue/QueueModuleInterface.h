#include <iostream>
#define QueueType int

using namespace std;

struct Node
{
	QueueType item;
	Node* next;
};

struct Queue
{
	Node* head;
	Node* tail;
};

void InitQueue(Queue* Q);

void GetHead(Queue* Q);

void DelHead(Queue* Q);

void Add(Queue* Q, QueueType item);

bool IsEmpty(Queue* Q);