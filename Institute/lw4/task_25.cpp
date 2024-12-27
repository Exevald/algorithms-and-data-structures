/*
	На диске имеется база  данных  по  физическим  эффектам
	(ФЭ).  Каждый  ФЭ  записан в виде тройки компонент:  название,
	входная  физическая  величина  (вход),   выходная   физическая
	величина  (выход).  Имеется  не более 100 различных физических
	величин. Требуется построить в основной памяти граф связи ФЭ и
	обеспечить  поиск  цепочек  ФЭ от одного до четырех звеньев по
	заданным входу и выходу по возрастанию количества звеньев

	Автор: Калинин Константин, ПС-21
	Среда выполнения: JetBrains Clion 2023.3.4
*/

#include "CGraph.h"
#include <fstream>
#include <iostream>
#include <optional>
#include <string>
#include <unordered_map>

struct Args
{
	std::string physicalQuantitiesInputFileName;
	std::string physicalEffectsInputFileName;
	int startPhysicalQuantity = 0;
	int endPhysicalQuantity = 0;
	std::string outputFileName;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 6)
	{
		std::cout << "Invalid argument count" << std::endl
				  << "Usage: task_25.exe <physicalQuantitiesInputFile> <physicalEffectsInputFile>" << std::endl;
		return std::nullopt;
	}

	Args args;
	args.physicalQuantitiesInputFileName = argv[1];
	args.physicalEffectsInputFileName = argv[2];
	args.outputFileName = argv[5];
	try
	{
		args.startPhysicalQuantity = std::stoi(argv[3]);
		args.endPhysicalQuantity = std::stoi(argv[4]);
	}
	catch (const std::invalid_argument& ex)
	{
		std::cout << "Invalid argument: start or end physical quantity is not a valid number" << std::endl;
		return std::nullopt;
	}

	return args;
}

void LoadPhysicalQuantities(const std::string& fileName, std::unordered_map<std::string, int>& nameToId)
{
	std::ifstream inputFile(fileName);
	if (!inputFile.is_open())
	{
		throw std::runtime_error("Failed to open " + fileName + " for reading");
	}

	std::string line;
	while (std::getline(inputFile, line))
	{
		size_t delimiterPos = line.find(':');
		int id = std::stoi(line.substr(0, delimiterPos));
		std::string name = line.substr(delimiterPos + 1);

		nameToId[name] = id;
	}
}

void LoadEffects(const std::string& fileName, CGraph& graph)
{
	std::ifstream inputFile(fileName);
	if (!inputFile.is_open())
	{
		throw std::runtime_error("Failed to open " + fileName + " for reading");
	}

	std::string line;
	while (std::getline(inputFile, line))
	{
		size_t firstDelimiter = line.find(';');
		size_t secondDelimiter = line.find(';', firstDelimiter + 1);

		std::string effectName = line.substr(0, firstDelimiter);

		graph.AddEffect({ effectName,
			std::stoi(line.substr(firstDelimiter + 1, secondDelimiter - firstDelimiter - 1)),
			std::stoi(line.substr(secondDelimiter + 1)) });
	}
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return EXIT_FAILURE;
	}

	std::unordered_map<std::string, int> physicalQuantitiesMap;
	CGraph graph;

	try
	{
		LoadPhysicalQuantities(args->physicalQuantitiesInputFileName, physicalQuantitiesMap);
		LoadEffects(args->physicalEffectsInputFileName, graph);
		auto chains = graph.FindEffectsChains(args->startPhysicalQuantity, args->endPhysicalQuantity);
		graph.PrintEffectsChainsToFile(chains, args->outputFileName);
	}
	catch (const std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}