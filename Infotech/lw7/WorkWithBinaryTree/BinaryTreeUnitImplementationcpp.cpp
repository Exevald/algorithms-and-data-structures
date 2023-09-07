/*#include <iostream>
#include "BinaryTreeUnitInterface.h"

STree* newPtr;
STree* tempPtr;
STree* root;

void InitTree()
{
	root = NULL;
}

void InfixFind(STree*& ptr, TreeType& item)
{
	if (ptr != NULL && tempPtr == NULL)
	{
		if (ptr->item == item)
		{
			tempPtr = ptr;
		}
		else
		{
			InfixFind(ptr->left, item);
			InfixFind(ptr->right, item);
		}
	}
}

STree* FindPtr(TreeType& item)
{
	STree* tree;
	STree* temp;
	tree = root;
	if (tree != NULL)
	{
		InfixFind(tree, item);
	}
	/*temp = tempPtr;
	tempPtr = NULL;
	return tempPtr;
}

void CreateTree(std::string file)
{
	int countOfPairs;
	TreeType parent, child;
	STree* tree;
	std::ifstream inputFile(file);

	if (!inputFile.is_open())
	{
		puts("Error for opening input file");
		exit(1);
	}
	else
	{
		inputFile >> countOfPairs;
		for (int i = 1; i <= countOfPairs; i++)
		{
			inputFile >> parent >> child;
			tree = FindPtr(parent);
			newPtr->item = child;
			if (root != NULL)
			{
				if (tree != NULL)
				{
					if (tree->left != NULL)
					{
						newPtr->parent = tree;
						tree = tree->left;
						while (tree->right != NULL)
						{
							tree = tree->right;
						}
						tree->right = newPtr;
						newPtr->level = tree->level;
					}
					else
					{
						tree->left = newPtr;
						newPtr->parent = tree;
						newPtr->level = tree->level + 1;
					}
				}
				else
				{
					std::cout << "Head " << parent << " is missing";
				}
			}
			else
			{
				root->item = parent;
				root->level = 0;
				root->left = newPtr;
				root->parent = NULL;
				newPtr->level = 1;
			}
		}
	}
}

void InfixPrintTree(STree* tree)
{
	if (tree != NULL)
	{
		InfixPrintTree(tree->left);
		std::cout << tree->item << " ";
		InfixPrintTree(tree->right);
	}
}*/