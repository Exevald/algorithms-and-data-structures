#include "CStack.h"
#include "CQueue.h"
#include <iostream>

CStack::CStack()
{
	m_head = nullptr;
}

bool CStack::IsEmpty() const
{
	return !m_head;
}

CQueue& CStack::Top() const
{
	if (!IsEmpty())
	{
		return *(m_head->value);
	}
	else
	{
		throw std::logic_error("Cannot get top element from stack, because stack is empty");
	}
}

void CStack::Push(const std::string& name)
{
	auto queue = std::make_unique<CQueue>(name);
	auto stackNode = std::make_unique<SStackNode>(std::move(queue));
	if (m_head != nullptr)
	{
		stackNode->next = std::move(m_head);
	}
	m_head = std::move(stackNode);
}

void CStack::Pop()
{
	if (!IsEmpty())
	{
		m_head->value->ClearQueue();
		m_head = std::move(m_head->next);
	}
	else
	{
		throw std::logic_error("Cannot delete top element from stack, because stack is empty");
	}
}

void CStack::Print()
{
	SStackNode* currentNode = m_head.get();
	while (currentNode)
	{
		std::cout << "Queue: " << currentNode->value->GetName() << "{ ";
		currentNode->value->Print();
		std::cout << "}" << std::endl;
		currentNode = currentNode->next.get();
	}
}
