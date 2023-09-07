#include <iostream>
#include <fstream>

#define TreeType int

struct STree
{
	STree* left;
	STree* right;
	STree* parent;
	TreeType item;
	int level;
};

void InitTree();

void InfixFind(STree*& ptr, TreeType& item);

STree* FindPtr(TreeType& item);

void CreateTree(std::string file);

void InfixPrintTree(STree* tree);