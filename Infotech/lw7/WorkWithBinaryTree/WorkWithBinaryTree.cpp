#include <iostream>
#define TreeType int

struct STree
{
    TreeType item;      
    int level;            
    STree* children;
    STree* brother;
    STree* parent;
};


void printLeaves(STree* tree)
{
    if (tree != NULL)
    {
        printLeaves(tree->children);

        if (tree->children == NULL)
            std::cout << tree->item << " ";

        printLeaves(tree->brother);
    }
}

void printKnots(STree* tree)
{
    if (tree != NULL)
    {
        printKnots(tree->children);

        if (tree->children != NULL)
            std::cout << tree->item << " ";

        printKnots(tree->brother);
    }
}


void printParent(STree* tree, TreeType el)
{
    if (tree != NULL)
    {
        printParent(tree->children, el);

        if (tree->item == el)
        {
            std::cout << tree->parent->item;
            return;
        }

        printParent(tree->brother, el);
    }
}

void printTreeOnLevel(STree* tree, int level)
{
    if (tree != NULL)
    {
        printTreeOnLevel(tree->children, level);

        if (tree->level == level)
            std::cout << tree->item << " ";

        printTreeOnLevel(tree->brother, level);
    }
}

int main()
{
    STree* tree = new STree;

    tree->item = 1;
    tree->level = 0;
    tree->children = new STree;
    tree->brother = NULL;
    tree->parent = NULL;

    tree->children->level = 1;
    tree->children->item = 2;
    tree->children->brother = new STree;
    tree->children->children = NULL;
    tree->children->parent = tree;

    tree->children->brother->level = 1;
    tree->children->brother->item = 3;
    tree->children->brother->brother = new STree;
    tree->children->brother->children = new STree;
    tree->children->brother->parent = tree;

    tree->children->brother->brother->item = 4;
    tree->children->brother->brother->level = 1;
    tree->children->brother->brother->brother = NULL;
    tree->children->brother->brother->children = new STree;
    tree->children->brother->brother->parent = tree;

    tree->children->brother->brother->children->item = 50;
    tree->children->brother->brother->children->level = 2;
    tree->children->brother->brother->children->brother = NULL;
    tree->children->brother->brother->children->children = NULL;
    tree->children->brother->brother->children->parent = tree->children->brother->brother;

    tree->children->brother->children->level = 2;
    tree->children->brother->children->item = 10;
    tree->children->brother->children->brother = new STree;
    tree->children->brother->children->children = NULL;
    tree->children->brother->children->parent = tree->children->brother;

    tree->children->brother->children->brother->item = 12;
    tree->children->brother->children->brother->level = 2;
    tree->children->brother->children->brother->brother = NULL;
    tree->children->brother->children->brother->children = NULL;
    tree->children->brother->children->brother->parent = tree->children->brother;

    std::cout << "Leaves are: ";
    printLeaves(tree);
    std::cout << "\nKnots are: ";
    printKnots(tree);
    std::cout << "\nParent of 12 is: ";
    printParent(tree, 12);
    std::cout << "\nNodes of 2 level are: ";
    printTreeOnLevel(tree, 2);
    std::cout << std::endl;


    return 0;
}