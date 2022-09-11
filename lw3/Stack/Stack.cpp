#include <iostream>
#define STACK_SIZE 20

using namespace std;

class Stack
{
	int* stackArr;
	int capasity;
	int top;

public:
	Stack(int size = STACK_SIZE);
	~Stack();

	void Push(int key);
	int Pop();
	int GetTop();
	bool isFull();
	bool isEmpty();
};

Stack::Stack(int size)
{
	stackArr = new int[size];
	capasity = size;
	top = -1;
}

Stack::~Stack()
{
	delete[] stackArr;
}

void Stack::Push(int key)
{
	if (isFull())
	{
		puts("Стек переполнен!");
		exit(1);
	}
	top++;
	stackArr[top] = key;
}

int Stack::Pop()
{
	if (isEmpty())
	{
		puts("Стек пустой!");
		exit(1);
	}
	int key = stackArr[top];
	top--;
	return key;
}

int Stack::GetTop()
{
	if (isEmpty())
	{
		puts("Стек пустой");
		exit(1);
	}
	return stackArr[top];
}

bool Stack::isEmpty()
{
	return (top == -1);
}

bool Stack::isFull()
{
	return (top == capasity - 1);
}

int main()
{
	setlocale(LC_ALL, "rus");
	Stack stack(5);

	return 0;
}
