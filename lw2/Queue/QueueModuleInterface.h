#include <iostream>
#define QueueType char

using namespace std;

struct Node
{
	QueueType data;
	Node* next;
};

struct Queue
{
	int size;
	Node* head;
	Node* tail;
};

void InitQueue(Queue* Q);

void GetHead(Queue* Q);

void DelHead(Queue* Q);

void Add(Queue* Q, char item);

bool IsEmpty(Queue* Q);