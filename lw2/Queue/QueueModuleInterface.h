#include <iostream>
#define QueueType int

using namespace std;

struct Queue
{
	QueueType item;
	Queue* next;
};

void GetHead(Queue* Q);

void DelHead(Queue*& Q);

void Add(Queue*& Q, QueueType item);

bool IsEmpty(Queue* Q);

void PrintQueue(Queue* Q);