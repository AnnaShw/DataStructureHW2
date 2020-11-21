#ifndef _BINARY_TREE
#define _BINARY_TREE
typedef struct Node node;
struct Node {
	int data;
	node* left;
	node* right;
};
node* NewNode(int);
node* Left(node*);
node* Right(node*);
node* randomInsertInto(node*, int);
node* randomTree();
void deleteTree(node*);
int height(node*);
void PrintGivenLevel(node*, int);
void PrintLevelOrder(node*);
void pre_order_traversal(node*);
void in_order_traversal(node*);

int IsEmpty(node* root);
void PrintLeaves(node* root);
int Contains(node* root, int key);
int CountNodes(node* root);
int SumOfKeys(node* root);
void CountNodesInGivenLevel(node* root, int level, int* count);
void LevelStatistics(node* root, int level);
int isPerfect(node* root);
#endif
