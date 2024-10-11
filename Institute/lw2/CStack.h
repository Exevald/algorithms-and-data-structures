#pragma once
#define QUEUE_TYPE int

#include "CQueue.h"
#include <memory>

struct SStackNode
{
	std::unique_ptr<CQueue> value;
	std::unique_ptr<SStackNode> next;
	explicit SStackNode(std::unique_ptr<CQueue> queue)
		: value(std::move(queue))
		, next(nullptr)
	{
	}
};

class CStack
{
public:
	explicit CStack();
	[[nodiscard]] bool IsEmpty() const;
	[[nodiscard]] CQueue& Top() const;

	void Push(const std::string& name);
	void Pop();
	void Print();

private:
	std::unique_ptr<SStackNode> m_head;
};
