#pragma once
#define QUEUE_TYPE int

#include <memory>

struct SQueueNode
{
	QUEUE_TYPE value;
	std::unique_ptr<SQueueNode> next;

	explicit SQueueNode(QUEUE_TYPE value)
		: value(value)
		, next(nullptr)
	{
	}
};

class CQueue
{
public:
	explicit CQueue(const std::string& name);
	[[nodiscard]] bool IsEmpty() const;
	[[nodiscard]] QUEUE_TYPE GetHead() const;
	[[nodiscard]] std::string GetName() const;

	void Add(QUEUE_TYPE value);
	void DeleteHead();

private:
	std::string m_name;
	std::unique_ptr<SQueueNode> m_head;
	SQueueNode* m_tail;
};
