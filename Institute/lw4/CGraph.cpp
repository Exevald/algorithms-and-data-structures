#include "CGraph.h"
#include <iostream>
#include <stack>

void CGraph::AddEffect(const Effect& effect)
{
	m_effects.push_back(effect);
	m_adjList[effect.input].push_back(effect);
}

std::vector<std::vector<int>> CGraph::FindEffectsChains(int start, int target, int maxDepth)
{
	std::vector<std::vector<int>> chains;
	std::vector<int> currentChain;
	std::set<std::string> visitedChains;
	DFS(start, target, maxDepth, chains, visitedChains);

	return chains;
}

void CGraph::DFS(int current, int target, int maxDepth, std::vector<std::vector<int>>& chains, std::set<std::string>& visitedChains)
{
	std::stack<std::tuple<int, int, std::vector<int>>> stack;
	stack.push({ current, 0, { current } });

	while (!stack.empty())
	{
		auto [node, depth, chain] = stack.top();
		stack.pop();

		if (depth > maxDepth)
		{
			continue;
		}

		if (node == target && depth > 0)
		{
			std::string chainKey = ChainToString(chain);
			if (visitedChains.find(chainKey) == visitedChains.end())
			{
				chains.push_back(chain);
				visitedChains.insert(chainKey);
			}
		}

		for (const auto& effect : m_adjList[node])
		{
			std::vector<int> newChain = chain;
			newChain.push_back(effect.output);

			stack.emplace(effect.output, depth + 1, newChain);
		}
	}
}

void CGraph::PrintEffectsChainsToFile(const std::vector<std::vector<int>>& chains, const std::string& fileName)
{
	std::ofstream outputFile(fileName);
	if (!outputFile)
	{
		throw std::runtime_error("Failed to open " + fileName + " for writing");
	}

	if (chains.empty())
	{
		outputFile << "No chains found." << std::endl;
		return;
	}

	for (const auto& chain : chains)
	{
		outputFile << "Chain: ";
		for (size_t i = 0; i < chain.size(); ++i)
		{
			outputFile << chain[i];
			if (i < chain.size() - 1)
			{
				outputFile << " -> ";
			}
		}
		outputFile << std::endl;

		outputFile << "Effects: " << std::endl;
		for (size_t i = 0; i < chain.size() - 1; ++i)
		{
			int current = chain[i];
			int next = chain[i + 1];
			for (const auto& effect : m_adjList[current])
			{
				if (effect.output == next)
				{
					outputFile << effect.name;
					if (i < chain.size() - 2)
					{
						outputFile << " -> ";
					} else {
						outputFile << std::endl;
					}
				}
			}
		}
		outputFile << std::endl;
	}

	if (!outputFile.flush())
	{
		throw std::runtime_error("Failed to save data on disk");
	}
}

std::string CGraph::ChainToString(const std::vector<int>& chain)
{
	std::string result;
	for (const auto& node : chain)
	{
		result += std::to_string(node) + ",";
	}

	return result;
}