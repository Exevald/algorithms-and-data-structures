/*
	В  листьях  И-ИЛИ  дерева,  соответствующего некоторому
	множеству  конструкций,  заданы   значения   массы.   Известно
	максимально допустимое значение массы изделия. Требуется усечь
	дерево   так,   чтобы   дерево    включало    все    элементы,
	соответствующие  допустимым  значениям массы,  но не содержало
	"лишних" вершин.  Конечное дерево выдать на экран в  наглядном
	виде

	Автор: Калинин Константин, ПС-21
	Среда выполнения: JetBrains Clion 2023.3.4
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

struct Args
{
	std::string inputFileName;
	std::string outputFileName;
};

enum class NodeType
{
	LEAF,
	AND,
	OR
};

struct Node
{
	std::string name;
	NodeType type;
	int weight;
	int minMass;
	int maxMass;
	std::vector<std::shared_ptr<Node>> children;

	Node(std::string n, NodeType t, int w = 0)
		: name(std::move(n))
		, type(t)
		, weight(w)
		, minMass(w)
		, maxMass(w)
	{
	}
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid argument count" << std::endl
				  << "Usage: task_24.exe <inputFile> <outputFile>" << std::endl;
		return std::nullopt;
	}

	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];
	return args;
}

std::shared_ptr<Node> ParseTree(std::ifstream& inputFile, int& maxMass)
{
	std::string line;
	if (!std::getline(inputFile, line))
	{
		throw std::runtime_error("Failed to read max mass");
	}

	maxMass = std::stoi(line);
	std::vector<std::pair<int, std::shared_ptr<Node>>> stack;

	while (std::getline(inputFile, line))
	{
		unsigned long level = line.find_first_not_of('.');
		std::stringstream ss(line.substr(level));
		std::string name;
		ss >> name;

		std::string typeOrWeight;
		ss >> typeOrWeight;

		std::shared_ptr<Node> node;
		if (std::isdigit(typeOrWeight[0]))
		{
			node = std::make_shared<Node>(name, NodeType::LEAF, std::stoi(typeOrWeight));
		}
		else
		{
			NodeType type = (typeOrWeight == "a") ? NodeType::AND : NodeType::OR;
			node = std::make_shared<Node>(name, type);
		}

		while (!stack.empty() && stack.back().first >= level)
		{
			stack.pop_back();
		}

		if (!stack.empty())
		{
			stack.back().second->children.push_back(node);
		}

		stack.emplace_back(level, node);
	}

	return stack.empty() ? nullptr : stack.front().second;
}

void CalculateMasses(const std::shared_ptr<Node>& node)
{
	if (!node)
	{
		return;
	}

	if (node->type == NodeType::LEAF)
	{
		node->minMass = node->weight;
		node->maxMass = node->weight;
		return;
	}

	node->minMass = (node->type == NodeType::AND) ? 0 : std::numeric_limits<int>::max();
	node->maxMass = 0;

	for (const auto& child : node->children)
	{
		CalculateMasses(child);

		if (node->type == NodeType::AND)
		{
			node->minMass += child->minMass;
			node->maxMass += child->maxMass;
		}
		else if (node->type == NodeType::OR)
		{
			node->minMass = std::min(node->minMass, child->minMass);
			node->maxMass = std::max(node->maxMass, child->maxMass);
		}
	}
}

void PruneTree(const std::shared_ptr<Node>& node, int remainingMass)
{
	if (!node)
	{
		return;
	}

	if (node->type == NodeType::LEAF)
	{
		if (node->weight > remainingMass)
		{
			node->minMass = 0;
			node->maxMass = 0;
		}
		return;
	}

	std::vector<std::shared_ptr<Node>> newChildren;
	size_t originalChildCount = node->children.size();

	for (const auto& child : node->children)
	{
		if (child->minMass <= remainingMass)
		{
			int childRemainingMass = (node->type == NodeType::AND)
				? remainingMass - (node->minMass - child->minMass)
				: remainingMass;
			PruneTree(child, childRemainingMass);

			if (!child->children.empty() || (child->type == NodeType::LEAF && child->weight <= remainingMass))
			{
				newChildren.push_back(child);
			}
		}
	}

	node->children = std::move(newChildren);

	if (node->type == NodeType::AND && node->children.size() != originalChildCount)
	{
		node->children.clear();
	}

	if (node->children.empty() && node->type != NodeType::LEAF)
	{
		node->minMass = 0;
		node->maxMass = 0;
	}
}

void PrintTree(const std::shared_ptr<Node>& node, std::ofstream& file, int level = 0)
{
	if (!node || (node->children.empty() && node->type != NodeType::LEAF))
	{
		return;
	}

	file << std::string(level, '.') << node->name;
	if (node->type == NodeType::LEAF)
	{
		file << " " << node->weight;
	}
	else
	{
		file << " " << (node->type == NodeType::AND ? "a" : "o");
	}
	file << std::endl;

	for (const auto& child : node->children)
	{
		PrintTree(child, file, level + 1);
	}

	if (!file.flush())
	{
		throw std::runtime_error("Failed to save data on disk");
	}
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return EXIT_FAILURE;
	}
	try
	{
		std::ifstream inputFile(args->inputFileName);
		if (!inputFile.is_open())
		{
			throw std::runtime_error("Failed to open " + args->inputFileName + " for reading");
		}

		std::ofstream outputFile(args->outputFileName);
		if (!outputFile)
		{
			throw std::runtime_error("Failed to open " + args->outputFileName + " for writing");
		}

		int maxMass;
		auto root = ParseTree(inputFile, maxMass);

		CalculateMasses(root);
		PruneTree(root, maxMass);
		PrintTree(root, outputFile);
	}
	catch (const std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}