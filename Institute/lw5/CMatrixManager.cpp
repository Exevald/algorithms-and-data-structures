#include "CMatrixManager.h"
#include <algorithm>
#include <cstdint>
#include <fstream>
#include <queue>
#include <stdexcept>

Matrix CMatrixManager::CreateMatrix(const std::string& matrixFileName, int matrixSize)
{
	if (m_storage.find(matrixFileName) != m_storage.end())
	{
		return m_storage[matrixFileName];
	}

	std::ifstream inputFile;
	inputFile.open(matrixFileName);
	if (!inputFile.is_open())
	{
		throw std::runtime_error("Failed to open " + matrixFileName + " for reading");
	}

	Matrix matrix;
	std::string line;
	uint32_t linePos = 0;
	std::getline(inputFile, line);

	while (std::getline(inputFile, line))
	{
		if (linePos > MatrixMaxHeightSize - 1)
		{
			throw std::runtime_error("Labyrinth height bigger than " + std::to_string(MatrixMaxHeightSize));
		}
		if (line.length() < matrixSize || line.length() > MatrixMaxWidthSize - 1)
		{
			throw std::runtime_error("Labyrinth width bigger than " + std::to_string(MatrixMaxWidthSize) + " or less than " + std::to_string(matrixSize));
		}

		MatrixLine matrixLine;
		for (int i = 0; i < line.length(); i++)
		{
			matrixLine[i] = line[i];
		}
		matrix[linePos] = matrixLine;
		linePos++;
	}
	if (linePos < matrixSize)
	{
		throw std::runtime_error("Labyrinth height less than " + std::to_string(matrixSize));
	}

	m_storage[matrixFileName] = matrix;
	return matrix;
}

bool CMatrixManager::IsValidMove(const Matrix& matrix, int platformSize, int x, int y)
{
	for (int i = 0; i < platformSize; ++i)
	{
		for (int j = 0; j < platformSize; ++j)
		{
			if (matrix[x + i][y + j] == '@')
			{
				return false;
			}
		}
	}
	return true;
}

std::vector<std::pair<int, int>> CMatrixManager::ReconstructPath(DistanceMatrix& distanceMatrix, int matrixSize, int platformSize, int startX, int startY, int endX, int endY)
{
	std::vector<std::pair<int, int>> finalPath;
	if (distanceMatrix[endX][endY] == -1)
	{
		return finalPath;
	}

	while (endX != startX || endY != startY)
	{
		finalPath.emplace_back(endX + 1, endY + 1);
		bool found = false;

		for (int dx = -1; dx <= 1; ++dx)
		{
			for (int dy = -1; dy <= 1; ++dy)
			{
				if ((std::abs(dx) + std::abs(dy) == 1))
				{
					int newX = endX + dx;
					int newY = endY + dy;
					bool isNewXValid = newX >= 0 && newX <= matrixSize - platformSize;
					bool isNewYValid = newY >= 0 && newY <= matrixSize - platformSize;

					if (isNewXValid && isNewYValid && distanceMatrix[newX][newY] == distanceMatrix[endX][endY] - 1)
					{
						endX = newX;
						endY = newY;
						found = true;
						break;
					}
				}
			}
			if (found)
			{
				break;
			}
		}

		if (!found)
		{
			break;
		}
	}

	finalPath.emplace_back(startX + 1, startY + 1);
	std::reverse(finalPath.begin(), finalPath.end());

	return finalPath;
}

std::vector<std::pair<int, int>> CMatrixManager::FindShortestWay(Matrix& matrix, int matrixSize, int platformSize, int startX, int startY, int endX, int endY)
{
	DistanceMatrix distanceMatrix;
	CMatrixManager::PrepareDistanceMatrix(distanceMatrix);
	std::queue<std::pair<int, int>> tempQueue;
	std::vector<std::pair<int, int>> availableDirections = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

	tempQueue.emplace(startX, startY);
	distanceMatrix[startX][startY] = 0;

	while (!tempQueue.empty())
	{
		auto [x, y] = tempQueue.front();
		tempQueue.pop();

		if (x == endX && y == endY)
		{
			return CMatrixManager::ReconstructPath(distanceMatrix, matrixSize, platformSize, startX, startY, endX, endY);
		}

		for (auto [dx, dy] : availableDirections)
		{
			int newX = x + dx;
			int newY = y + dy;
			bool isNewXValid = newX >= 0 && newX <= matrixSize - platformSize;
			bool isNewYValid = newY >= 0 && newY <= matrixSize - platformSize;

			if (isNewXValid && isNewYValid && distanceMatrix[newX][newY] == -1 && CMatrixManager::IsValidMove(matrix, platformSize, newX, newY))
			{
				distanceMatrix[newX][newY] = distanceMatrix[x][y] + 1;
				tempQueue.emplace(newX, newY);
			}
		}
	}

	return {};
}

void CMatrixManager::PrepareDistanceMatrix(DistanceMatrix& distanceMatrix)
{
	for (auto& matrixLine : distanceMatrix)
	{
		for (auto& lineItem : matrixLine)
		{
			lineItem = -1;
		}
	}
}
