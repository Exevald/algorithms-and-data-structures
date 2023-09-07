#include "GraphModuleInterface.h"
#include <fstream>
#include <stack>
#include <queue>

#define GraphType int

void ReadMatrix(std::string inFile, int& amountVert, GraphType(&graphMatrix)[MAX_VERTEX][MAX_VERTEX])
{
	std::ifstream inputFile(inFile);
	GraphType item;

	if (!inputFile.is_open())
	{
		puts("Error for opening input file");
		exit(1);
	}
	else
	{
		inputFile >> amountVert;
		for (int i = 1; i <= amountVert; i++)
		{
			for (int j = 1; j <= amountVert; j++)
			{
				inputFile >> item;
				graphMatrix[i][j] = item;
			}
		}
	}
}

void PrintMatrix(std::string outFile, int amountVert, GraphType(graphMatrix)[MAX_VERTEX][MAX_VERTEX])
{
	std::ofstream outputFile(outFile);

	if (!outputFile.is_open())
	{
		puts("Error for opening output file");
		exit(1);
	}
	else
	{
		outputFile << amountVert << std::endl;
		for (int i = 1; i <= amountVert; i++)
		{
			for (int j = 1; j <= amountVert; j++)
			{
				outputFile << graphMatrix[i][j];
			}
			outputFile << std::endl;
		}
	}
}

void ReadList(std::string inFile, int& amountVert, int& amountEdge, SBranch(&listVertices)[MAX_EDGE])
{
	std::ifstream inputFile(inFile);
	GraphType vert1, vert2, weight;

	if (!inputFile.is_open())
	{
		puts("Error for opening input file");
		exit(1);
	}
	else
	{
		inputFile >> amountVert >> amountEdge;
		for (int i = 1; i <= amountEdge; i++)
		{
			inputFile >> vert1 >> vert2 >> weight;
			listVertices[i].Vert1 = vert1;
			listVertices[i].Vert2 = vert2;
			listVertices[i].Weight = weight;
		}
	}
}

void PrintList(std::string outFile, int amountVert, int amountEdge, SBranch(listVertices)[MAX_EDGE])
{
	std::ofstream outputFile(outFile);
	GraphType item;

	if (!outputFile.is_open())
	{
		puts("Error for opening output file");
		exit(1);
	}
	else
	{
		outputFile << amountVert << " " << amountEdge << std::endl;
		for (int i = 1; i <= amountEdge; i++)
		{
			outputFile << listVertices[i].Vert1 << " " << listVertices[i].Vert2 << " " << listVertices[i].Weight << std::endl;
		}
	}
}

void ConvertMatrixToList(int amountVert, int& amountEdge, GraphType(&graphMatrix)[MAX_VERTEX][MAX_VERTEX], SBranch(&listVertices)[MAX_EDGE])
{
	int i, j, divider = 2, temp = 1;
	for (i = 1; i <= amountVert; i++, divider++)
	{
		for (j = divider; j <= amountVert; j++)
		{
			if (graphMatrix[i][j] != 0)
			{
				listVertices[temp].Vert1 = i;
				listVertices[temp].Vert2 = j;
				listVertices[temp].Weight = graphMatrix[i][j];
				temp++;
			}
		}
	}
	amountEdge = temp - 1;
}

void ConvertListToMatrix(int amountVert, int amountEdge, GraphType(&graphMatrix)[MAX_VERTEX][MAX_VERTEX], SBranch(&listVertices)[MAX_EDGE])
{
	for (int i = 1; i <= amountVert; i++)
	{
		for (int j = 1; j <= amountVert; j++)
		{
			graphMatrix[i][j] = 0;
		}
	}
	for (int i = 1; i <= amountEdge; i++)
	{
		graphMatrix[listVertices[i].Vert1][listVertices[i].Vert2] = listVertices[i].Weight;
		graphMatrix[listVertices[i].Vert2][listVertices[i].Vert1] = listVertices[i].Weight;
	}
}

void DFS(int amountVert, GraphType(&graphMatrix)[MAX_VERTEX][MAX_VERTEX])
{
	bool visited[MAX_VERTEX];
	std::stack <int> tempStack;
	int currentVert;
	int i;

	for (i = 1; i <= amountVert; i++)
	{
		visited[i] = false;
	}
	i = 1;
	if (visited[i] == false)
	{
		tempStack.push(i);
		while (!tempStack.empty())
		{
			currentVert = tempStack.top();
			tempStack.pop();
			if (visited[currentVert] == false)
			{
				visited[currentVert] = true;
				std::cout << currentVert << " ";
			}
			for (i = 1; i <= amountVert; i++)
			{
				if (graphMatrix[currentVert][i] > 0 && visited[i] == false)
				{
					tempStack.push(i);
				}
			}
		}
	}
}

void BFS(int amountVert, GraphType(&graphMatrix)[MAX_VERTEX][MAX_VERTEX])
{
	bool visited[MAX_VERTEX];
	std::queue <int> tempQueue;
	int currentVert, i;
	for (i = 1; i <= amountVert; i++)
	{
		visited[i] = false;
	}
	i = 1;
	if (visited[i] == false)
	{
		tempQueue.push(i);
		while (!tempQueue.empty())
		{
			currentVert = tempQueue.front();
			tempQueue.pop();
			if (visited[currentVert] == false)
			{
				visited[currentVert] = true;
				std::cout << currentVert << " ";
			}
			for (i = 1; i <= amountVert; i++)
			{
				if (graphMatrix[currentVert][i] > 0 && visited[i] == false)
				{
					tempQueue.push(i);
				}
			}
		}
	}
}