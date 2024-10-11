#include "CQueue.h"

CQueue::CQueue(const std::string& name)
{
	m_name = name;
	m_head = nullptr;
	m_tail = nullptr;
}

bool CQueue::IsEmpty() const
{
	return !m_head;
}

QUEUE_TYPE CQueue::GetHead() const
{
	return m_head->value;
}

std::string CQueue::GetName() const
{
	return m_name;
}

void CQueue::Add(int value)
{
	auto newNode = std::make_unique<SQueueNode>(value);
	if (IsEmpty())
	{
		m_head = std::move(newNode);
		m_tail = m_head.get();
	}
	else
	{
		m_tail->next = std::move(newNode);
		m_tail = m_tail->next.get();
	}
}
void CQueue::DeleteHead()
{
	m_head = std::move(m_head->next);
	if (IsEmpty())
	{
		m_tail = nullptr;
	}
}