#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct Effect
{
	std::string name;
	int input;
	int output;
};

class CGraph
{
public:
	void AddEffect(const Effect& effect);
	std::vector<std::vector<int>> FindEffectsChains(int start, int target, int maxDepth = 4);
	void PrintEffectsChainsToFile(const std::vector<std::vector<int>>& chains, const std::string& fileName);

private:
	void DFS(int current, int target, int maxDepth, std::vector<std::vector<int>>& chains, std::set<std::string>& visitedChains);
	static std::string ChainToString(const std::vector<int>& chain);

	std::vector<Effect> m_effects;
	std::unordered_map<int, std::vector<Effect>> m_adjList;
};
