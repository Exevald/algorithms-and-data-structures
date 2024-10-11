/*
	Организовать в основной памяти с помощью указателей стек из очередей.
	Обеспечить операции введения очереди из вершины стека, расширения и сокращения стека,
	выдачи содержимого стека

	Автор: Калинин Константин, ПС-21
	Среда выполнения: JetBrains Clion 2023.3.4
*/

#include "CQueue.h"
#include "CStack.h"
#include <iostream>
#include <string>

void QueueController(CQueue& queue)
{
	std::string action;
	do
	{
		std::cout << std::endl
				  << "Queue: " << queue.GetName() << std::endl
				  << "Usage:" << std::endl
				  << "1. Add to queue: Press 'add'" << std::endl
				  << "2. Delete head from queue: Press 'delete'" << std::endl
				  << "3. Get head from queue: Press 'top'" << std::endl
				  << "4. Exit from queue: Press 'exit'" << std::endl
				  << "> ";
		std::cin >> action;

		if (action == "add")
		{
			QUEUE_TYPE value;
			std::cout << "Enter a value to add: ";
			std::cin >> value;
			queue.Add(value);
			std::cout << "Value added to queue" << std::endl;
		}
		else if (action == "delete")
		{
			try
			{
				queue.DeleteHead();
				std::cout << "Item deleted" << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		else if (action == "top")
		{
			try
			{
				QUEUE_TYPE headValue = queue.GetHead();
				std::cout << "Head value: " << headValue << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		else
		{
			std::cout << "Invalid command. Please try again" << std::endl;
		}
	} while (action != "exit");
}

void StackController(CStack& stack)
{
	std::string action;
	do
	{
		std::cout << std::endl
				  << "Stack" << std::endl
				  << "1. Usage:" << std::endl
				  << "2. Push to stack: Press 'push'" << std::endl
				  << "3. Pop element from stack: Press 'pop'" << std::endl
				  << "4. Work with top element of stack: Press 'top'" << std::endl
				  << "5. Print all stack items: Press 'print'" << std::endl
				  << "6. Exit from program: Press 'exit'" << std::endl
				  << "> ";
		std::cin >> action;

		if (action == "push")
		{
			std::string name;
			std::cout << "Enter queue name: ";
			std::cin >> name;
			stack.Push(name);
		}
		else if (action == "pop")
		{
			try
			{
				stack.Pop();
				std::cout << "Popped top queue" << std::endl;
			}
			catch (const std::exception& exception)
			{
				std::cout << exception.what() << std::endl;
			}
		}
		else if (action == "top")
		{
			try
			{
				CQueue& queue = stack.Top();
				QueueController(queue);
			}
			catch (const std::exception& exception)
			{
				std::cout << exception.what() << std::endl;
			}
		}
		else if (action == "print")
		{
			stack.Print();
		}
		else
		{
			std::cout << "Invalid command. Please try again" << std::endl;
		}
	} while (action != "exit");
}

int main()
{
	CStack stack;
	StackController(stack);

	return EXIT_SUCCESS;
}