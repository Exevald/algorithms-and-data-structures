#include <iostream>
#include <fstream>

#define TreeType int
using namespace std;

struct Tree
{
	TreeType item;
	Tree* left;
	Tree* right;
};

void InitTree(Tree*& tree)
{
	tree = NULL;
}

void AddItem(Tree*& tree, TreeType item)
{
	if (tree == NULL)
	{
		tree = new Tree;
		tree->item = item;
		tree->left = NULL;
		tree->right = NULL;
	}
	else
	{
		if (item < tree->item)
		{
			AddItem(tree->left, item);
		}
		else
		{
			if (item >= tree->item)
			{
				AddItem(tree->right, item);
			}
		}
	}
}

void DeleteTree(Tree* tree)
{
	delete(tree);
	tree = NULL;
}

void DeleteItem(Tree*& tree, TreeType item)
{
	if (tree->item == item)
	{
		DeleteTree(tree);
	}
	if (item < tree->item)
	{
		DeleteItem(tree->left, item);
	}
	else
	{
		if (item >= tree->item)
		{
			DeleteItem(tree->right, item);
		}
	}
}

void PrefixPrintTree(Tree* tree)
{
	if (tree != NULL)
	{
		cout << tree->item << " ";
		PrefixPrintTree(tree->left);
		PrefixPrintTree(tree->right);
	}
}

void InfixPrintTree(Tree* tree)
{
	if (tree != NULL)
	{
		InfixPrintTree(tree->left);
		cout << tree->item << " ";
		InfixPrintTree(tree->right);
	}
}

void PostfixPrintTree(Tree* tree)
{
	if (tree != NULL)
	{
		PostfixPrintTree(tree->left);
		PostfixPrintTree(tree->right);
		cout << tree->item << " ";
	}
}

int main()
{
	ifstream inputFile("input.txt");
	TreeType item;
	Tree* tree;
	setlocale(LC_ALL, "ru");

	InitTree(tree);
	if (!inputFile.is_open())
	{
		puts("Error for opeing file input.txt");
		return 1;
	}
	else
	{
		if (!inputFile.eof())
		{
			do
			{
				inputFile >> item;
				AddItem(tree, item);
			} while (!inputFile.eof());
		}
	}
	cout << "Префиксный обход: ";
	PrefixPrintTree(tree);
	cout << endl;
	cout << endl << "Инфиксный обход: ";
	InfixPrintTree(tree);
	cout << endl;
	cout << endl << "Постфиксный обход: ";
	PostfixPrintTree(tree);
	cout << endl;
	return 0;
}
