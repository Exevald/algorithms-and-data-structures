#include <iostream>
using namespace std;

#define StackType char

struct Node
{
	StackType data;
	Node* next;
};

struct Stack
{
	int size;
	Node* head;
};

void InitStack(Stack* S);

void GetHead(Stack* S);

void Pop(Stack* S);

void Push(Stack* S, char item);

bool IsEmpty(Stack* S);
