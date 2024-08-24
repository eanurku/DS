/*
 * BinaryTreeFunctions.h
 *
 *  Created on: 13-Sep-2018
 *      Author: anurag
 */

#ifndef BINARYTREEFUNCTIONS_H_
#define BINARYTREEFUNCTIONS_H_

struct BinaryTreeNode* getBinaryTreeNode(int data);
struct BinaryTreeNode* insertWithparentPointerInBST(struct BinaryTreeNode* root,int element);
int getmaxnode(struct BinaryTreeNode* root,struct BinaryTreeNode* k1,struct BinaryTreeNode* k2);

void traverseInorderBinaryTree(struct BinaryTreeNode *ptr);
void traversePreorderBinaryTree(struct BinaryTreeNode *ptr);
void traversePostorderBinaryTree(struct BinaryTreeNode *ptr);

int getDistanceFromRoot(struct BinaryTreeNode *root,int key);
int heightOfBinaryTree(struct BinaryTreeNode *ptr);
int heightOfBinaryTreeRecursive(struct BinaryTreeNode *ptr);
int getCountOfNodesInBinaryTree(struct BinaryTreeNode* root);
void getInorderOfBInaryTreeInArray(struct BinaryTreeNode* root,int* array,int *size);

void traverseLevelOfBinaryTree(struct BinaryTreeNode *root, int level);
void traverseLevelorderBinaryTree(struct BinaryTreeNode *root);
void traverseLevelOrderbyQueueOfBinaryTree(struct BinaryTreeNode *root);
int longestPathPassingThroughRoot(struct BinaryTreeNode* root);
int diameterOfBinaryTree(struct BinaryTreeNode* root);
int diameterOptimizedOfBinaryTree(struct BinaryTreeNode* root,int *height);
void inorderTraversalWithoutRecursionOfBinaryTree(struct BinaryTreeNode* root);
void inorderTraversalWithoutRecursionAndStackOfBinaryTree(struct BinaryTreeNode* root);
int getWidthAtLevelOfBinaryTree(struct BinaryTreeNode* root,int level);
int getMaxWidthOfbinaryTree(struct BinaryTreeNode* root);
int getMaxWidthOptimizedOfbinaryTree(struct BinaryTreeNode* root);
void printNodesAtKthdistanceInBinaryTree(struct BinaryTreeNode* root,int k);
int  printAncestorOfNode(struct BinaryTreeNode* root,int key);
struct BinaryTreeNode* buildBinaryTreefromInorderAndPreorderTraversals(int *inorderIndex,int **preorderIndex,int inStart,int inEnd);
struct BinaryTreeNode* buildBinaryTreefromInorderAndPostorderTraversals(int *inorderIndex,int **postorderLastIndex,int inStart,int inEnd);
void connectNodeAtSameLevelBinaryTree(struct BinaryTreeNode* root);
int isSubtreeOfBinaryTree(struct BinaryTreeNode* root,struct BinaryTreeNode* subTreeRoot);
int isEqualBinaryTree(struct BinaryTreeNode* root1,struct BinaryTreeNode* root2);



//add tree node to queue
void addToQueue(struct BinaryTreeNode* node,struct LinkListWithBtreeNode **front,struct LinkListWithBtreeNode **rear);
//delete tree node from queue
struct BinaryTreeNode* deleteFromQueue(struct LinkListWithBtreeNode **front,struct LinkListWithBtreeNode **rear);
//add tree node to stack
void addToStack(struct LinkListWithBtreeNode** top,struct BinaryTreeNode* node);
//delete tree node from stack
struct BinaryTreeNode* deleteFromStack(struct LinkListWithBtreeNode** top);

int  peekStack(struct LinkListWithBtreeNode* top);
int  peekFront(struct LinkListWithBtreeNode* front);


#endif /* BINARYTREEFUNCTIONS_H_ */
