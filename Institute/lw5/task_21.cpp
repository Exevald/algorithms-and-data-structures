#include "CMatrixManager.h"
#include <fstream>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

struct Args
{
	std::string inputFileName;
	std::string outputFileName;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid argument count" << std::endl
				  << "Usage: task_21.exe <inputFileName> <outputFileName>" << std::endl;
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];

	return args;
}

std::pair<int, std::vector<std::pair<int, int>>> GetPathInfo(const std::string& inputFileName)
{
	std::ifstream inputFile;
	inputFile.open(inputFileName);
	if (!inputFile.is_open())
	{
		throw std::runtime_error("Failed to open " + inputFileName + " for reading");
	}

	int matrixSize, platformSize;
	inputFile >> matrixSize >> platformSize;

	if (platformSize > matrixSize || platformSize < 1)
	{
		throw std::runtime_error("Platform size is invalid");
	}

	CMatrixManager matrixManager;
	auto matrix = matrixManager.CreateMatrix(inputFileName, matrixSize);
	auto shortestWay = CMatrixManager::FindShortestWay(matrix, matrixSize, platformSize, 0, 0, matrixSize - platformSize, matrixSize - platformSize);

	return { shortestWay.size() - 1, shortestWay };
}

void PrintPathInfo(const std::string& outputFilaName, const std::pair<int, std::vector<std::pair<int, int>>>& pathInfo)
{
	std::ofstream outputFile;
	outputFile.open(outputFilaName);
	if (!outputFile.is_open())
	{
		throw std::runtime_error("Failed to open " + outputFilaName + " for writing");
	}

	outputFile << pathInfo.first << std::endl;
	for (const auto& coord : pathInfo.second)
	{
		outputFile << coord.first << " " << coord.second << std::endl;
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
		auto pathInfo = GetPathInfo(args->inputFileName);
		PrintPathInfo(args->outputFileName, pathInfo);
	}
	catch (const std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}