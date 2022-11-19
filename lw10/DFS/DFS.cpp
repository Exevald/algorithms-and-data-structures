#include <iostream>
#include "GraphModuleInterface.h"

int main()
{
	setlocale(LC_ALL, "ru");

	int amountVert = 0, amountEdge = 0;
	GraphType adjMatrix[MAX_VERTEX][MAX_VERTEX];
	SBranch edgeList[MAX_EDGE];

	ReadList("ListEdg.txt", amountVert, amountEdge, edgeList);
	ConvertListToMatrix(amountVert, amountEdge, adjMatrix, edgeList);

	PrintMatrix("OutputMatrix.txt", amountVert, adjMatrix);

	DFS(amountVert, adjMatrix);

	return 0;
}