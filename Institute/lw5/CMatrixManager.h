#pragma once

#include <array>
#include <string>
#include <unordered_map>
#include <vector>

typedef char CellType;
const int MatrixMaxWidthSize = 500;
const int MatrixMaxHeightSize = 500;

typedef std::array<CellType, MatrixMaxWidthSize> MatrixLine;
typedef std::array<MatrixLine, MatrixMaxHeightSize> Matrix;
typedef std::array<int, MatrixMaxWidthSize - 1> DistanceMatrixLine;
typedef std::array<DistanceMatrixLine, MatrixMaxWidthSize> DistanceMatrix;

class CMatrixManager
{
public:
	Matrix CreateMatrix(const std::string& matrixFileName, int matrixSize);
	static std::vector<std::pair<int, int>> FindShortestWay(Matrix& matrix, int matrixSize, int platformSize, int startX, int startY, int endX, int endY);

private:
	static bool IsValidMove(const Matrix& matrix, int matrixSize, int x, int y);
	static std::vector<std::pair<int, int>> ReconstructPath(DistanceMatrix& distanceMatrix, int matrixSize, int platformSize, int startX, int startY, int endX, int endY);
	static void PrepareDistanceMatrix(DistanceMatrix& distanceMatrix);

	std::unordered_map<std::string, Matrix> m_storage;
};
