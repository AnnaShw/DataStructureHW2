#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"BinaryTree.h"

int main()
{
	srand(time(NULL));
	node* root;
	int H, num, NumToSearch;
	root = randomTree();
	H = height(root);
	printf("\n\nHeight of tree is %d\n", H);
	printf("\nLevels of Bynary Tree:\n");
	PrintLevelOrder(root);
	printf("\nPreorder Traversal tree\n");
	pre_order_traversal(root);
	printf("\n\nIn_order Traversal tree\n");
	in_order_traversal(root);
	
	/*if (IsEmpty(root) == 0)
		printf("\nTree isn't empty!");
	else
		printf("\nTree is empty");
	PrintLeaves(root);
	if (Contains(root, 12) == 1)
		printf("\n%d in the tree.\n", 12);
	else
		printf("\n%d  not in the tree.\n", 12);
	printf("\nSum of all keys of the tree is: %d\n", SumOfKeys(root));
	printf("\nCount of node's in this tree is: %d\n", CountNodes(root));*/
	printf("\n\n");
	LevelStatistics(root, 3);

	deleteTree(root);
	printf("\nTree deleted\n");

	return 0;
}