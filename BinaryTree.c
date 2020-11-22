#include<stdio.h>
#include<time.h>
#include<stdlib.h>
typedef struct Node node;
struct Node {
	int data;
	node* left;
	node* right;
};
node* NewNode(int value)
{
	node* p = (node*)malloc(sizeof(node));
	p->data = value;
	p->left = NULL;
	p->right = NULL;
	return p;
}

node* Left(node* root)
{
	return root->left;
}

node* Right(node* root)
{
	return root->right;
}

node* randomInsertInto(node* root, int value)
{
	if (root == NULL)
		root = NewNode(value);
	else if (rand() % 2 == 0)
		root->left = randomInsertInto(root->left, value);
	else
		root->right = randomInsertInto(root->right, value);
	return root;
}

node* randomTree()
{
	node* root = NULL;
	int size = 1 + rand() % 15;
	printf("\nsize=%d\n", size);
	int i;
	for (i = 1; i <= size; i++)
		root = randomInsertInto(root, 1 + rand() % 50);
	return root;
}

void deleteTree(node* root)
{
	if (root == NULL)
		return;
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
}

int height(node* root)
{
	int Lh, Rh;
	if (root == NULL)
		return -1;
	Lh = height(root->left);
	Rh = height(root->right);
	if (Lh > Rh)
		return Lh + 1;
	else
		return Rh + 1;
}
void PrintGivenLevel(node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d  ", root->data);
	else if (level > 1)
	{
		PrintGivenLevel(root->left, level - 1);
		PrintGivenLevel(root->right, level - 1);
	}
}
void PrintLevelOrder(node* root)
{
	int h = height(root);
	int i;
	for (i = 0; i <= h + 1; i++)
	{
		PrintGivenLevel(root, i);
		printf("\n");
	}
}

void pre_order_traversal(node* root)
{
	if (root != NULL)
	{
		printf("%d  ", root->data);
		pre_order_traversal(root->left);
		pre_order_traversal(root->right);
	}
}

void in_order_traversal(node* root)
{
	if (root != NULL)
	{
		in_order_traversal(root->left);
		printf("%d  ", root->data);
		in_order_traversal(root->right);
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------
//targil 1
int IsEmpty(node* root) { //check if tree is empty
	if (root->data == NULL)
		return 1;
	return 0;
}

//targil 2
void PrintLeaves(node* root) { //print all leaves
		if (root != NULL) {
			if (root->left == NULL && root->right == NULL) {
				printf("\n%d", root->data);
			}
			PrintLeaves(root->left);
			PrintLeaves(root->right);
		}
}

//targil 3
int Contains(node* root, int key) { // go throw all nodes and find key value
	if (root != NULL) {
		if (root->data == key)
			return 1;
		Contains(root->left, key);
		Contains(root->right, key);
	}
	return 0;
}

//targil 4
int CountNodes(node* root) {//count ammount of node
	if (root != NULL) {
		return 1 + CountNodes(root->left) + CountNodes(root->right);
	}
	else if (root == NULL)
		return 0;
}
//targil 5


int SumOfKeys(node* root) {//sum all values of the tree
	if (root != NULL) {
		return root->data + SumOfKeys(root->left) + SumOfKeys(root->right);
	}
	else if (root == NULL)
		return 0;
}
//targil 6
//help function
void CountNodesInGivenLevel(node* root, int level,int* count) {//help fucntion count nodes in specific level
	if (root == NULL)
		return;
	if (level == 1) {
		(*count)++;
	}
	else if (level > 1)
	{
		CountNodesInGivenLevel(root->left, level - 1,count);
		CountNodesInGivenLevel(root->right, level - 1,count);	
	}
}
//targil 6 function
void LevelStatistics(node* root, int level) {//using help function count and then print values of level
	int count = 0;
	CountNodesInGivenLevel(root, level, &count);
	if (count == 0)
		printf("This level not in the tree.");
	else {
		PrintGivenLevel(root, level);
		printf("\nNumber of node's in %d level is:%d\n", level, count);
	}
}
//targil 7
int isPerfect(node* root)//check with help function heigth if each leaves in the same heigth
{
	if (height(root->left) != height(root->right))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
