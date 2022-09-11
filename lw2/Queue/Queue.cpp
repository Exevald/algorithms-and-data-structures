#include <iostream>
#define QUEUE_SIZE 10

using namespace std;

class Queue
{
	int* arr;
	int capasity;
	int front;
	int back;
	int count;

public:
	Queue(int size = QUEUE_SIZE);
	~Queue();

	void Add(int item);
	int Head();
	int DelHead();
	bool IsEmpty();
	bool IsFull();
};

Queue::Queue(int size)
{
	arr = new int[size];
	capasity = size;
	front = 0;
	back = -1;
	count = 0;
}

Queue::~Queue()
{
	delete[] arr;
}

void Queue::Add(int item)
{
	if (IsFull())
	{
		puts("Переполнение очереди!");
		exit(1);
	}
	back = (back + 1) % capasity;
	arr[back] = item;
	count++;
}

int Queue::Head()
{
	if (IsEmpty())
	{
		puts("Очередь пустая!");
		exit(1);
	}

	return arr[front];
}

int Queue::DelHead()
{
	if (IsEmpty())
	{
		puts("Очередь пустая!");
		exit(1);
	}
	int key = arr[front];
	front = (front + 1) % capasity;

	return key;
}

bool Queue::IsFull()
{
	return (count == capasity);
}

bool Queue::IsEmpty()
{
	return (count == 0);
}

int main()
{
	setlocale(LC_ALL, "rus");
	Queue queue(5);
}
