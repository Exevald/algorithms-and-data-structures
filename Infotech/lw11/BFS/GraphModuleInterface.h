#include <iostream>

#define GraphType int

#define MAX_VERTEX 100
#define MAX_EDGE MAX_VERTEX*MAX_VERTEX

struct SBranch
{
	GraphType Vert1;
	GraphType Vert2;
	int Weight;
};

void ReadMatrix(std::string inf, int& amountVert, GraphType(&graphMatrix)[MAX_VERTEX][MAX_VERTEX]);

void PrintMatrix(std::string outFile, int amountVert, GraphType(graphMatrix)[MAX_VERTEX][MAX_VERTEX]);

void ReadList(std::string inFile, int& amountVert, int& amountEdge, SBranch(&listVertices)[MAX_EDGE]);

void PrintList(std::string outFile, int amountVert, int amountEdge, SBranch(listVertices)[MAX_EDGE]);

void ConvertMatrixToList(int amountVert, int& amountEdge, GraphType(&graphMatrix)[MAX_VERTEX][MAX_VERTEX], SBranch(&listVertices)[MAX_EDGE]);

void ConvertListToMatrix(int amountVert, int amountEdge, GraphType(&graphMatrix)[MAX_VERTEX][MAX_VERTEX], SBranch(&listVertices)[MAX_EDGE]);

void DFS(int amountVert, GraphType(&graphMatrix)[MAX_VERTEX][MAX_VERTEX]);

void BFS(int amountVert, GraphType(&graphMatrix)[MAX_VERTEX][MAX_VERTEX]);
