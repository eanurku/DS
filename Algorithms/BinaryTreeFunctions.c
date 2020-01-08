/*
 ============================================================================
 Name        : BinaryTree.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "commonDeclarations.h"


int  peekStack(struct LinkListWithBtreeNode* top){

	int val=top->data->data;
	return val;
}
int  peekFront(struct LinkListWithBtreeNode* front){

	int val=front->data->data;
	return val;
}
struct LinkListWithBtreeNode* getLinkListNode(struct BinaryTreeNode *binaryTreeNode) {

	struct LinkListWithBtreeNode *tmp = (struct LinkListWithBtreeNode*) malloc(sizeof(struct LinkListWithBtreeNode));

	tmp->data = binaryTreeNode;
	tmp->next = NULL;
	return tmp;
}
struct LinkListWithBtreeNode* getLinkListNodeWithMinMax(struct BinaryTreeNode *binaryTreeNode,int min,int max) {

	struct LinkListWithBtreeNode *tmp = (struct LinkListWithBtreeNode*) malloc(sizeof(struct LinkListWithBtreeNode));

	tmp->data = binaryTreeNode;
	tmp->next = NULL;
	tmp->min=min;
	tmp->max=max;
	return tmp;
}

struct BinaryTreeNode* getBinaryTreeNode(int data) {

	struct BinaryTreeNode *tmp = (struct BinaryTreeNode*) malloc(sizeof(struct BinaryTreeNode));

	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->parent=NULL;

	return tmp;
}
struct BinaryTreeNode* insertWithparentPointerInBST(struct BinaryTreeNode* root,int element){

	if(root==NULL){

		root=getBinaryTreeNode(element);
		return root;
	}
	if(element< root->data){

		root->left=insertWithparentPointerInBST(root->left,element);
		root->left->parent=root;
	}else if(element> root->data){
		root->right=insertWithparentPointerInBST(root->right,element);
		root->right->parent=root;
	}

	return root;
}
int getmaxnode(struct BinaryTreeNode* root,struct BinaryTreeNode* k1,struct BinaryTreeNode* k2){

	struct BinaryTreeNode* node=NULL;
	int max=-1;

	while (k1!= root) {
		if (max < k1->data) {
			max = k1->data;
			node = k1;
		}
		k1 = k1->parent;
	}
	while (k2 != root) {
		if (max < k2->data) {
			max = k2->data;
			node = k2;
		}
		k2 = k2->parent;
	}
	if (max < root->data) {
		max = root->data;
		node = root;
	}

	return node->data;
}
void traverseInorderBinaryTree(struct BinaryTreeNode *ptr) {

	if (ptr) {
		traverseInorderBinaryTree(ptr->left);
		printf("%d ", ptr->data);
		traverseInorderBinaryTree(ptr->right);
	}
}

void traversePreorderBinaryTree(struct BinaryTreeNode *ptr) {

	if (ptr) {
		printf("%d ", ptr->data);
		traversePreorderBinaryTree(ptr->left);
		traversePreorderBinaryTree(ptr->right);
	}
}

void traversePostorderBinaryTree(struct BinaryTreeNode *ptr) {

	if (ptr) {
		traversePostorderBinaryTree(ptr->left);
		traversePostorderBinaryTree(ptr->right);
		printf("%d ", ptr->data);
	}
}

int getDistanceFromRoot(struct BinaryTreeNode *root,int key){

	if(root->data==key) return 0;
	if(root->data>key)
		return 1+getDistanceFromRoot(root->left,key);

	return 1+ getDistanceFromRoot(root->right,key);
}
int heightOfBinaryTreeRecursive(struct BinaryTreeNode *ptr){

	if(!ptr){
		return 0;
	}

	return 1+maxoftwo(heightOfBinaryTreeRecursive(ptr->left),heightOfBinaryTreeRecursive(ptr->right));
}
int heightOfBinaryTree(struct BinaryTreeNode *ptr) {

	int leftTreeHeight, rightTreeHeight;
	if (ptr == NULL) {
		return 0;
	}
	leftTreeHeight = heightOfBinaryTree(ptr->left);
	rightTreeHeight = heightOfBinaryTree(ptr->right);

	if (leftTreeHeight >rightTreeHeight) {
		return 1 + leftTreeHeight;
	} else {
		return 1 + rightTreeHeight;
	}

}

void traverseLevelOfBinaryTree(struct BinaryTreeNode *root, int level) {

	if (root == NULL) {
		return;
	}
	if (level == 1) {
		printf("%d ", root->data);
		return;
	}
	traverseLevelOfBinaryTree(root->left, level - 1);
	traverseLevelOfBinaryTree(root->right, level - 1);

}
void traverseLevelorderBinaryTree(struct BinaryTreeNode *root){

	int treeHeight=heightOfBinaryTree(root);
	int level;

	for(level=1;level<=treeHeight;level++){

		traverseLevelOfBinaryTree(root,level);
		printf("\n");
	}
}
int sizeOfQueue(struct LinkListWithBtreeNode* front,struct LinkListWithBtreeNode* rear){

	struct LinkListWithBtreeNode* ptr=front;
	int count=1;
	if(ptr==NULL){
		return 0;
	}

	while (ptr != rear) {
		ptr = ptr->next;
		count++;
	}

	return count;
}
void addToQueue(struct BinaryTreeNode* node,struct LinkListWithBtreeNode **front,struct LinkListWithBtreeNode **rear){

	if(node==NULL){
		return;
	}
	if(*rear==NULL){
		*front=*rear=getLinkListNode(node);
	}else{
		(*rear)->next=getLinkListNode(node);
		(*rear)=(*rear)->next;
	}

}
void addToQueueWithMinMax(struct BinaryTreeNode* node,struct LinkListWithBtreeNode **front,struct LinkListWithBtreeNode **rear,int min,int max){

	if(node==NULL){
		return;
	}
	if(*rear==NULL){
		*front=*rear=getLinkListNodeWithMinMax(node,min,max);
	}else{
		(*rear)->next=getLinkListNodeWithMinMax(node,min,max);
		(*rear)=(*rear)->next;
	}

}

struct LinkListWithBtreeNode* deleteFromQueueWithMinMax(struct LinkListWithBtreeNode **front,struct LinkListWithBtreeNode **rear){

	struct LinkListWithBtreeNode* node;

	if(*front==NULL){
		return NULL;
	}else if((*front)->next==NULL){
		node=(*front);
		(*front)=(*rear)=(*front)->next;
		return node;
	} else {
		node = (*front);
		(*front) = (*front)->next;
		return node;
	}

}
struct BinaryTreeNode* deleteFromQueue(struct LinkListWithBtreeNode **front,struct LinkListWithBtreeNode **rear){

	struct BinaryTreeNode* node;

	if(*front==NULL){
		return NULL;
	}else if((*front)->next==NULL){
		node=(*front)->data;
		(*front)=(*rear)=(*front)->next;
		return node;
	} else {
		node = (*front)->data;
		(*front) = (*front)->next;
		return node;
	}

}
void traverseLevelOrderbyQueueOfBinaryTree(struct BinaryTreeNode *root){

	struct LinkListWithBtreeNode *front=NULL,*rear=NULL;

	struct BinaryTreeNode *tmp=root;
	while(tmp){
		printf("%d",tmp->data);
		addToQueue(tmp->left,&front,&rear);
		addToQueue(tmp->right,&front,&rear);
		tmp=deleteFromQueue(&front,&rear);

	}

}
int maxOfThree(int a,int b,int c){

	return a>b?(a>c?a:c):(b>c?b:c);
}
int maxoftwo(int a, int b){
	return a>b?a:b;
}
int minoftwo(int a, int b){
	return a>b?b:a;
}
int longestPathPassingThroughRoot(struct BinaryTreeNode* root){


	int leftheight=heightOfBinaryTree(root->left);
	int rightheight=heightOfBinaryTree(root->right);
	return leftheight+rightheight+1;
}
/* number of nodes on longest path in tree
 *
 */
int diameterOfBinaryTree(struct BinaryTreeNode* root){

	if(root==NULL){
		return 0;
	}
	int leftDiameter=diameterOfBinaryTree(root->left);
	int rightDiameter=diameterOfBinaryTree(root->right);
	int longestPathFromRoot=longestPathPassingThroughRoot(root);

	return maxOfThree(leftDiameter,rightDiameter,longestPathFromRoot);

}
int diameterOptimizedOfBinaryTree(struct BinaryTreeNode* root,int *height){

	int leftHeight,rightHeight;

	if(root==NULL){
		*height=0;
		return 0;
	}
	int leftDiameter=diameterOptimizedOfBinaryTree(root->left,&leftHeight);
	int rightDiameter=diameterOptimizedOfBinaryTree(root->right,&rightHeight);

	 *height=maxoftwo(leftHeight,rightHeight)+1;

	return maxOfThree(leftHeight+rightHeight+1,leftDiameter,rightDiameter);

}
void addToStack(struct LinkListWithBtreeNode** top,struct BinaryTreeNode* node){

	struct LinkListWithBtreeNode* tmp;
	if(node==NULL){
		return;
	}

	if(*top == NULL){
		(*top)=getLinkListNode(node);
	}
	else{
		tmp=getLinkListNode(node);
		tmp->next=*top;
		(*top)=tmp;
	}

}
struct BinaryTreeNode* deleteFromStack(struct LinkListWithBtreeNode** top){

	struct LinkListWithBtreeNode* tmp;

	if(*top==NULL){
		return NULL;
	}else{

		tmp=*top;
		(*top)=(*top)->next;
		tmp->next=NULL;
	}

	return tmp->data;
}
void inorderTraversalWithoutRecursionOfBinaryTree(struct BinaryTreeNode* root){
	struct LinkListWithBtreeNode* top=NULL;
	struct BinaryTreeNode* curr=root;

	while(1){
	if(curr==NULL && top==NULL){
		return;
	}
	while(curr!=NULL){
		addToStack(&top,curr);
		curr=curr->left;
	}
	curr=deleteFromStack(&top);
	printf("%d ",curr->data);
	curr=curr->right;
	}
}
void inorderTraversalWithoutRecursionAndStackOfBinaryTree(struct BinaryTreeNode* root){

	if(root==NULL){
		return;
	}
	struct BinaryTreeNode* curr=root,*CurrLeft;

	while(curr!=NULL){

		if(curr->left==NULL){
			printf("%d",curr->data);
			curr=curr->right;
		}else{

			CurrLeft=curr->left;
			while(CurrLeft->right!=NULL && CurrLeft->right!=curr ){
				CurrLeft=CurrLeft->right;
			}
			if(CurrLeft->right==NULL){

				CurrLeft->right=curr;
				curr=curr->left;
			}else{

				CurrLeft->right=NULL;
				printf("%d",curr->data);
				curr=curr->right;
			}

		}
	}

}
int getWidthAtLevelOfBinaryTree(struct BinaryTreeNode* root,int level){

	if(root==NULL){
		return 0;
	}
	if(level==1){
		return 1;
	}
	return getWidthAtLevelOfBinaryTree(root->left,level-1)+getWidthAtLevelOfBinaryTree(root->right,level-1);
}
int getMaxWidthOfbinaryTree(struct BinaryTreeNode* root){

	int height=heightOfBinaryTree(root);
	int level,width,maxWidth=0;
	for(level=1;level<=height;level++){

		width=getWidthAtLevelOfBinaryTree(root,level);
		if(maxWidth<width){
			maxWidth=width;

		}
	}

	return maxWidth;
}
/*
	while(curr){
		printf("%d",curr->data);
		addToQueue(curr->left,&front,&rear);
		addToQueue(curr->right,&front,&rear);
		curr=deleteFromQueue(&front,&rear);
	}*/
int getMaxWidthOptimizedOfbinaryTree(struct BinaryTreeNode* root) {
	int maxWidth = 0, count;

	struct LinkListWithBtreeNode*front = NULL, *rear = NULL;
	struct BinaryTreeNode* tmp;
	if (root == NULL) {
		return 0;
	}
	addToQueue(root, &front, &rear);
	while (front != NULL && rear != NULL) {

		count = sizeOfQueue(front, rear);
		maxWidth = maxoftwo(count, maxWidth);

		while (count > 0) {

			tmp = deleteFromQueue(&front, &rear);
			if (tmp->left)
				addToQueue(tmp->left, &front, &rear);
			if (tmp->right)
				addToQueue(tmp->right, &front, &rear);
			count--;
		}
	}
	return maxWidth;
}
void printNodesAtKthdistanceInBinaryTree(struct BinaryTreeNode* root,int k){

	if(root==NULL){
		return;
	}
	if(k==0){
		printf("%d ",root->data);
		return;
	}
	printNodesAtKthdistanceInBinaryTree(root->left,k-1);
	printNodesAtKthdistanceInBinaryTree(root->right,k-1);
}

int  printAncestorOfNode(struct BinaryTreeNode* root,int key){

	if(root==NULL){
		return 0;
	}
	if(root->data==key){
		return 1;
	}

		if (printAncestorOfNode(root->left,key)||printAncestorOfNode(root->right,key)){

			printf("%d ",root->data);
			return 1;
		}

    return 0;
}

int getElementIndex(int* inorderIndex ,int inStart,int inEnd,int key){

	int i;
	for(i=inStart;i<=inEnd;i++){

		if(*(inorderIndex+i)==key){
			return i;
		}
	}


	return -1;
}

int getIndexofLargerThanKeyElement(int* array ,int Start,int End,int key){

	int i;
	for(i=Start;i<=End;i++){

		if(*(array+i)>key){
			return i;
		}
	}


	return i;
}
struct BinaryTreeNode* buildBinaryTreefromInorderAndPreorderTraversals(int *inorderIndex,int **preorderIndex,int inStart,int inEnd){


	struct BinaryTreeNode* root=NULL;

	if(inStart>inEnd){
		return NULL;
	}
	int rootElement=**preorderIndex;
	(*preorderIndex)++;

	root=getBinaryTreeNode(rootElement);

	if(inStart==inEnd){

		return root;
	}
	int rootElementIndex=getElementIndex(inorderIndex,inStart,inEnd,rootElement);

	root->left=buildBinaryTreefromInorderAndPreorderTraversals(inorderIndex,preorderIndex,inStart,rootElementIndex-1);
	root->right=buildBinaryTreefromInorderAndPreorderTraversals(inorderIndex,preorderIndex,rootElementIndex+1,inEnd);

	return root;
}

struct BinaryTreeNode* buildBinaryTreefromInorderAndPostorderTraversals(int *inorderIndex,int **postorderLastIndex,int inStart,int inEnd){

	struct BinaryTreeNode* root=NULL;

	if(inStart>inEnd)
		return NULL;
	int rootElement=**postorderLastIndex;
	(*postorderLastIndex)--;
	root=getBinaryTreeNode(rootElement);
	if(inStart==inEnd){
		return root;
	}

	int rootElementIndex=getElementIndex(inorderIndex,inStart,inEnd,rootElement);
	root->right=buildBinaryTreefromInorderAndPostorderTraversals(inorderIndex,postorderLastIndex,rootElementIndex+1,inEnd);
	root->left=buildBinaryTreefromInorderAndPostorderTraversals(inorderIndex,postorderLastIndex,inStart,rootElementIndex-1);




	return root;
}

int isEqualBinaryTree(struct BinaryTreeNode* root1,struct BinaryTreeNode* root2){

	if(!root1 && !root2){
		return 1;
	}else if(root1==NULL || root2==NULL) {
	   return 0;
	}
	return root1->data==root2->data && isEqualBinaryTree(root1->left,root2->left) && isEqualBinaryTree(root1->right,root2->right) ;
}
int isSubtreeOfBinaryTree(struct BinaryTreeNode* root,struct BinaryTreeNode* subTreeRoot){

	if (subTreeRoot == NULL) {
		return 1;
	}
	if (root == NULL) {
		return 0;
	}

	if (root->data == subTreeRoot->data) {

		return isEqualBinaryTree(root, subTreeRoot);
	}

	return isSubtreeOfBinaryTree(root->left,subTreeRoot)||isSubtreeOfBinaryTree(root->right,subTreeRoot);

}
void connectNodeAtSameLevelBinaryTree(struct BinaryTreeNode* root){

	struct LinkListWithBtreeNode *front=NULL,*rear=NULL;
	struct BinaryTreeNode* tmp,*save,*dummyNode=getBinaryTreeNode(0);
	int count;
	if(!root){
		return ;
	}
	addToQueue(root,&front,&rear);

	while(front){

		count=sizeOfQueue(front,rear);


		save=dummyNode;
		while(count>0){

			tmp=deleteFromQueue(&front,&rear);
			save->nextRight=tmp;
			save=tmp;

			if( tmp->left){
				addToQueue(tmp->left,&front,&rear);
			}
			if(tmp->right){
				addToQueue(tmp->right,&front,&rear);
			}

			count--;
		}

		save->nextRight=NULL;

	}


}

int getCountOfNodesInBinaryTree(struct BinaryTreeNode* root){

	if(root==NULL){
		return 0;
	}

	return 1+getCountOfNodesInBinaryTree(root->left)+getCountOfNodesInBinaryTree(root->right);
}

void getInorderOfBInaryTreeInArray(struct BinaryTreeNode* root,int* array,int *size){

	if(!root){
		return;
	}
	getInorderOfBInaryTreeInArray(root->left,array,size);
	array[(*size)++]=root->data;
	getInorderOfBInaryTreeInArray(root->right,array,size);
}
