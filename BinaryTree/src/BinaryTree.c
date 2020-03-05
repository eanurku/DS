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
#include <limits.h>

struct LinkListWithBtreeNode {
	struct BinaryTreeNode *data;
	struct LinkListWithBtreeNode *next;
};

struct BinaryTreeNode{

	int data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
	struct BinaryTreeNode *nextRight;
	int vLineNumber;
};

struct BinaryTreeNode* getBinaryTreeNode(int data);

int getheightOfBinaryTree(struct BinaryTreeNode *ptr);
int getheightOfBinaryTreeOptimized(struct BinaryTreeNode *ptr);

int getSizeOfBinaryTree(struct BinaryTreeNode* root);
int isLeafNodeBinaryTree(struct BinaryTreeNode *node);
int getCountOfLeavesInBinaryTree(struct BinaryTreeNode *root);
int getLevelOfNodeInBinaryTree(struct BinaryTreeNode *root,int key);


void traverseInorderBinaryTree(struct BinaryTreeNode *ptr);
void traversePreorderBinaryTree(struct BinaryTreeNode *ptr);
void traversePostorderBinaryTree(struct BinaryTreeNode *ptr);

void traverseTheLevelOfBinaryTree(struct BinaryTreeNode *root, int level);
void traverseLevelorderBinaryTree(struct BinaryTreeNode *root);

void traverseLevelOrderbyQueueOfBinaryTree(struct BinaryTreeNode *root);

void leavesTraversalLeftToRightIterativeBinaryTree(struct BinaryTreeNode *root);
int areHavingSameLeavesOptimizedSpaceBinaryTree(struct BinaryTreeNode *root1,struct BinaryTreeNode *root2);


int longestPathPassingThroughRootOfBinaryTree(struct BinaryTreeNode* root);
int diameterOfBinaryTreeRecursive(struct BinaryTreeNode* root);
int diameterOfBinaryTreeRecursiveOptimized(struct BinaryTreeNode* root,int *height);

void inorderTraversalWithoutRecursionOfBinaryTree(struct BinaryTreeNode* root);
void inorderTraversalWithoutRecursionAndStackOfBinaryTree(struct BinaryTreeNode* root);

int getWidthAtLevelOfBinaryTreeRecursive(struct BinaryTreeNode* root,int level);
int getMaxWidthOfbinaryTree(struct BinaryTreeNode* root);
int getMaxWidthOfbinaryTreeOptimized(struct BinaryTreeNode* root);

void printNodesAtKthdistanceInBinaryTreeRecursive(struct BinaryTreeNode* root,int k);

int  printAncestorOfNode(struct BinaryTreeNode* root,int key);

struct BinaryTreeNode* buildBinaryTreefromInorderAndPreorderTraversals(int *inorderIndex,int **preorderIndex,int inStart,int inEnd);
struct BinaryTreeNode* buildBinaryTreefromInorderAndPostorderTraversals(int *inorderIndex,int **postorderLastIndex,int inStart,int inEnd);

int isEqualBinaryTreeRecursive(struct BinaryTreeNode* root1,struct BinaryTreeNode* root2);
int isSubtreeOfBinaryTree(struct BinaryTreeNode* root,struct BinaryTreeNode* subTreeRoot);

void connectNodeAtSameLevelBinaryTree(struct BinaryTreeNode* root);





struct LinkListWithBtreeNode* getLinkListWithBtreeNode(struct BinaryTreeNode *binaryTreeNode);

int sizeOfQueue(struct LinkListWithBtreeNode* front,struct LinkListWithBtreeNode* rear);
void addToQueue(struct BinaryTreeNode* node,struct LinkListWithBtreeNode **front,struct LinkListWithBtreeNode **rear);
struct BinaryTreeNode* deleteFromQueue(struct LinkListWithBtreeNode **front,struct LinkListWithBtreeNode **rear);

void addToStack(struct LinkListWithBtreeNode** top,struct BinaryTreeNode* node);
struct BinaryTreeNode* deleteFromStack(struct LinkListWithBtreeNode** top);

//problems

void rightToLeftLevelOrderTraversalBinaryTree(struct BinaryTreeNode *root);
void bottomToToplevelOrderTraversalRecursiveBinaryTree(struct BinaryTreeNode *root);
void bottomToToplevelOrderTraversalOptimizedBinaryTree(struct BinaryTreeNode *root);

void lineByLineLevelOrderTraversalByQueueBinaryTree(struct BinaryTreeNode *root);
void lineByLineLevelOrderTraversalByTwoQueueBinaryTree(struct BinaryTreeNode *root);

void diagonalTraversalByQueueBinaryTree(struct BinaryTreeNode *root);
void diagonalTraversalByQueue2BinaryTree(struct BinaryTreeNode *root);

void getleavesLeftToRightInArrayBinarytree(struct BinaryTreeNode *root,int *array,int *top);
int areHavingSameLeavesBinaryTree(struct BinaryTreeNode *root1,struct BinaryTreeNode *root2);

int areHavingSameLeavesOptimizedSpaceBinaryTree(struct BinaryTreeNode *root1,struct BinaryTreeNode *root2);

void leavesTraversalLeftToRightRecursiveBinaryTree(struct BinaryTreeNode *root);
void leavesTraversalLeftToRightIterativeBinaryTree(struct BinaryTreeNode *root);



void getMinMaxOfVerticalLineNumbersBinaryTree(struct BinaryTreeNode *root,int *min,int *max,int dist);
void traverseTheVerticalLineNumberOfBinarytree(struct BinaryTreeNode *root,int line,int dist);
void verticalTraversalOptimizedSpaceBinaryTree(struct BinaryTreeNode *root);

void getVLineNumberForAllNodesInBinaryTree(struct BinaryTreeNode *root,int vLine);
void verticalLineTraversalBinaryTree(struct BinaryTreeNode *root,int vLine);


void leftboundryInternalNodesTraversalBinaryTree(struct BinaryTreeNode *root);
void rightBoundaryInternalNodestraversalBinaryTree(struct BinaryTreeNode *root);
void getLeafOfVerticalLineBinaryTree(struct BinaryTreeNode *root,int line,int dist);

void boundryTraversalAntiClockwiseBinaryTree(struct BinaryTreeNode *root);
void boundryTraversalAntiClockwiseOptimizedBinaryTree(struct BinaryTreeNode *root);

void getSpecificOrderOutputQueue(struct LinkListWithBtreeNode *front,struct LinkListWithBtreeNode *rear,int size);
void specificLevelOrderTraversalPerfectBinarytree(struct BinaryTreeNode *root);

void specificLevelOrderTraversalOptimizedPerfectBinarytree(struct BinaryTreeNode *root);

void specificLevelOrderTraversalBottomToTopPerfectBinarytree(struct BinaryTreeNode *root);

void getPostOrderTraversalFromInorderAndPreOrderBinaryTree(int* in,int* pre,int n);
void getPreOrderTraversalFromInOrderAndPostOrderBinaryTree(int *in,int *post,int n);


void preOrderTraversalIterativeByStackBinaryTree(struct BinaryTreeNode *root);
void preOrderTraversalIterativeByStackMethod2BinaryTree(struct BinaryTreeNode *root);
void preOrderTraversalIterativeWithoutStackBinarytree(struct BinaryTreeNode *root);









struct LinkListWithBtreeNode* getLinkListWithBtreeNode(struct BinaryTreeNode *binaryTreeNode) {

	struct LinkListWithBtreeNode *tmp = (struct LinkListWithBtreeNode*) malloc(sizeof(struct LinkListWithBtreeNode));

	tmp->data = binaryTreeNode;
	tmp->next = NULL;
	return tmp;
}

struct BinaryTreeNode* getBinaryTreeNode(int data) {

	struct BinaryTreeNode *tmp = (struct BinaryTreeNode*) malloc(sizeof(struct BinaryTreeNode));

	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;

	return tmp;
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

int maxoftwo(int a, int b){
	return a>b?a:b;
}

int getheightOfBinaryTreeOptimized(struct BinaryTreeNode *ptr){

	if(!ptr) return 0;

	return 1+maxoftwo(getheightOfBinaryTreeOptimized(ptr->left),getheightOfBinaryTreeOptimized(ptr->right));
}
int getheightOfBinaryTree(struct BinaryTreeNode *ptr) {

	int leftTreeHeight, rightTreeHeight;

	if (ptr == NULL) {
		return 0;
	}
	leftTreeHeight = getheightOfBinaryTree(ptr->left);
	rightTreeHeight = getheightOfBinaryTree(ptr->right);

	if (leftTreeHeight >rightTreeHeight) {
		return 1 + leftTreeHeight;
	} else {
		return 1 + rightTreeHeight;
	}

}

int getSizeOfBinaryTree(struct BinaryTreeNode* root){

	if(root==NULL){
		return 0;
	}

	return 1+getSizeOfBinaryTree(root->left)+getSizeOfBinaryTree(root->right);
}

void traverseTheLevelOfBinaryTree(struct BinaryTreeNode *root, int level) {

	if (root == NULL) {
		return;
	}
	if (level == 1) {
		printf("%d ", root->data);
		return;
	}
	traverseTheLevelOfBinaryTree(root->left, level - 1);
	traverseTheLevelOfBinaryTree(root->right, level - 1);

}
void traverseLevelorderBinaryTree(struct BinaryTreeNode *root){

	int treeHeight=getheightOfBinaryTreeOptimized(root);
	int level;

	for(level=1;level<=treeHeight;level++){

		traverseTheLevelOfBinaryTree(root,level);
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
		*front=*rear=getLinkListWithBtreeNode(node);
	}else{
		(*rear)->next=getLinkListWithBtreeNode(node);
		(*rear)=(*rear)->next;
	}

}
struct BinaryTreeNode* deleteFromQueue(struct LinkListWithBtreeNode **front,struct LinkListWithBtreeNode **rear){

	struct BinaryTreeNode* node;

	if(*front==NULL){
		return NULL;
	}else if((*front)==(*rear)){
		node=(*front)->data;
		(*front)=(*rear)=NULL;
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
		printf("%d ",tmp->data);
		addToQueue(tmp->left,&front,&rear);
		addToQueue(tmp->right,&front,&rear);
		tmp=deleteFromQueue(&front,&rear);

	}

}

int longestPathPassingThroughRootOfBinaryTree(struct BinaryTreeNode* root){

	int leftheight=getheightOfBinaryTreeOptimized(root->left);
	int rightheight=getheightOfBinaryTreeOptimized(root->right);
	return leftheight+rightheight+1;
}

int maxOfThree(int a,int b,int c){

	return a>b?(a>c?a:c):(b>c?b:c);
}

/* number of nodes on longest path in tree
 *
 */
int diameterOfBinaryTreeRecursive(struct BinaryTreeNode* root){

	if(root==NULL){
		return 0;
	}
	int leftDiameter=diameterOfBinaryTreeRecursive(root->left);
	int rightDiameter=diameterOfBinaryTreeRecursive(root->right);
	int longestPathFromRoot=longestPathPassingThroughRootOfBinaryTree(root);

	return maxOfThree(leftDiameter,rightDiameter,longestPathFromRoot);

}
int diameterOfBinaryTreeRecursiveOptimized(struct BinaryTreeNode* root,int *height){

	int leftHeight,rightHeight;

	if(root==NULL){
		*height=0;
		return 0;
	}
	int leftDiameter=diameterOfBinaryTreeRecursiveOptimized(root->left,&leftHeight);
	int rightDiameter=diameterOfBinaryTreeRecursiveOptimized(root->right,&rightHeight);

	 *height=maxoftwo(leftHeight,rightHeight)+1;

	return maxOfThree(leftHeight+rightHeight+1,leftDiameter,rightDiameter);

}
void addToStack(struct LinkListWithBtreeNode** top,struct BinaryTreeNode* node){

	struct LinkListWithBtreeNode* tmp;
	if(node==NULL){
		return;
	}

	if(*top == NULL){
		(*top)=getLinkListWithBtreeNode(node);
	}
	else{
		tmp=getLinkListWithBtreeNode(node);
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
			printf("%d ",curr->data);
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
				printf("%d ",curr->data);
				curr=curr->right;
			}

		}
	}

}
int getWidthAtLevelOfBinaryTreeRecursive(struct BinaryTreeNode* root,int level){

	if(root==NULL){
		return 0;
	}
	if(level==1){
		return 1;
	}
	return getWidthAtLevelOfBinaryTreeRecursive(root->left,level-1)+getWidthAtLevelOfBinaryTreeRecursive(root->right,level-1);
}
int getMaxWidthOfbinaryTree(struct BinaryTreeNode* root){

	int height=getheightOfBinaryTreeOptimized(root);
	int level,width,maxWidth=0;
	for(level=1;level<=height;level++){

		width=getWidthAtLevelOfBinaryTreeRecursive(root,level);
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
int getMaxWidthOfbinaryTreeOptimized(struct BinaryTreeNode* root) {
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
void printNodesAtKthdistanceInBinaryTreeRecursive(struct BinaryTreeNode* root,int k){

	if(root==NULL){
		return;
	}
	if(k==0){
		printf("%d ",root->data);
		return;
	}
	printNodesAtKthdistanceInBinaryTreeRecursive(root->left,k-1);
	printNodesAtKthdistanceInBinaryTreeRecursive(root->right,k-1);
}

int  printAncestorOfNode(struct BinaryTreeNode* root,int key){

	if(root==NULL){
		return 0;
	}
	if(root->data==key){
		return 1;
	}

	if (printAncestorOfNode(root->left, key) || printAncestorOfNode(root->right, key)) {

		printf("%d ", root->data);
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

int isEqualBinaryTreeRecursive(struct BinaryTreeNode* root1,struct BinaryTreeNode* root2){

	if(!root1 && !root2){
		return 1;
	}else if(root1==NULL || root2==NULL) {
	   return 0;
	}
	return root1->data==root2->data && isEqualBinaryTreeRecursive(root1->left,root2->left) && isEqualBinaryTreeRecursive(root1->right,root2->right) ;
}
int isSubtreeOfBinaryTree(struct BinaryTreeNode* root,struct BinaryTreeNode* subTreeRoot){

	if (subTreeRoot == NULL) {
		return 1;
	}
	if (root == NULL) {
		return 0;
	}

	if (root->data == subTreeRoot->data && isEqualBinaryTreeRecursive(root, subTreeRoot)) {

		return 1;
	}

	return isSubtreeOfBinaryTree(root->left,subTreeRoot)||isSubtreeOfBinaryTree(root->right,subTreeRoot);

}
void connectNodeAtSameLevelBinaryTree(struct BinaryTreeNode* root){

	struct LinkListWithBtreeNode *front=NULL,*rear=NULL;
	struct BinaryTreeNode* tmp,*save,*dummyNode=getBinaryTreeNode(0);
	int count,result=0;
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

void rightToLeftLevelOrderTraversalBinaryTree(struct BinaryTreeNode *root){

	struct LinkListWithBtreeNode *front=NULL;
	struct LinkListWithBtreeNode *rear=NULL;
	struct BinaryTreeNode *tmp;
	int count=0;

	if(!root){
		return;
	}
	addToQueue(root,&front,&rear);

	while(front){
		count=sizeOfQueue(front,rear);

		while(count>0){
			tmp=deleteFromQueue(&front,&rear);
			printf("%d ",tmp->data);
			if(tmp->right){
				addToQueue(tmp->right,&front,&rear);
			}
			if(tmp->left){
				addToQueue(tmp->left,&front,&rear);
			}

			count--;
		}
		printf("\n");

	}
}

void bottomToToplevelOrderTraversalRecursiveBinaryTree(struct BinaryTreeNode *root){

	int height=getheightOfBinaryTreeOptimized(root);
	printf("height=%d\n",height);

	for(int i=height;i>0;i--){
		traverseTheLevelOfBinaryTree(root,i);
		printf("\n");

	}

}

void bottomToToplevelOrderTraversalOptimizedBinaryTree(struct BinaryTreeNode *root){

	struct LinkListWithBtreeNode *front=NULL;
	struct LinkListWithBtreeNode *rear=NULL;
	struct LinkListWithBtreeNode *stack=NULL;

	struct BinaryTreeNode *tmp=root;
	while(tmp){
		addToStack(&stack,tmp);
		if(tmp->right){
			addToQueue(tmp->right,&front,&rear);
		}
		if(tmp->left){
			addToQueue(tmp->left,&front,&rear);
		}
		tmp=deleteFromQueue(&front,&rear);
	}

	while(stack){
		printf("%d ",deleteFromStack(&stack)->data);
	}
}


void lineByLineLevelOrderTraversalByQueueBinaryTree(struct BinaryTreeNode *root){

	struct LinkListWithBtreeNode *front=NULL;
	struct LinkListWithBtreeNode *rear=NULL;
	struct BinaryTreeNode *tmp;
	addToQueue(root,&front,&rear);
	int count;

	while(front){

		count=sizeOfQueue(front,rear);

		while(count>0){

			tmp=deleteFromQueue(&front,&rear);
			printf("%d ",tmp->data);
			addToQueue(tmp->left,&front,&rear);
			addToQueue(tmp->right,&front,&rear);
			count--;
		}
		printf("\n");
	}
}

void lineByLineLevelOrderTraversalByTwoQueueBinaryTree(struct BinaryTreeNode *root){

	struct LinkListWithBtreeNode *front1,*front2,*rear1,*rear2;
	front1=front2=rear1=rear2=NULL;
	struct BinaryTreeNode *tmp;
	addToQueue(root,&front1,&rear1);

	while(front1 || front2 ){

		while(front1){
			tmp=deleteFromQueue(&front1,&rear1);
			printf("%d ",tmp->data);
			addToQueue(tmp->left,&front2,&rear2);
			addToQueue(tmp->right,&front2,&rear2);
		}
		printf("\n");
		while(front2){
			tmp=deleteFromQueue(&front2,&rear2);
			printf("%d ",tmp->data);
			addToQueue(tmp->left,&front1,&rear1);
			addToQueue(tmp->right,&front1,&rear1);
		}
		printf("\n");
	}

}


void diagonalTraversalByQueueBinaryTree(struct BinaryTreeNode *root){


	struct LinkListWithBtreeNode *front=NULL;
	struct LinkListWithBtreeNode *rear=NULL;
	struct BinaryTreeNode *tmp=NULL;
	int count;

	addToQueue(root,&front,&rear);
	while (front) {

		count = sizeOfQueue(front, rear);

		while (count > 0) {

			tmp = deleteFromQueue(&front, &rear);

			while (tmp) {
				printf("%d ", tmp->data);
				if (tmp->left) {
					addToQueue(tmp->left, &front, &rear);
				}
				tmp = tmp->right;
			}
			count--;
		}
		printf("\n");
	}
}
void diagonalTraversalByQueue2BinaryTree(struct BinaryTreeNode *root){

	struct LinkListWithBtreeNode * front=NULL;
	struct LinkListWithBtreeNode * rear=NULL;


	while(root || sizeOfQueue(front,rear)){


		if(root){
			printf("%d ",root->data);
			addToQueue(root->left,&front,&rear);
			root=root->right;
		}else{

			root=deleteFromQueue(&front,&rear);
		}
	}



}


int isLeafNodeBinaryTree(struct BinaryTreeNode *node){

	if(node==NULL) return 0;
	if(node->left||node->right){
		return 0;
	}

	return 1;
}


int getCountOfLeavesInBinaryTree(struct BinaryTreeNode *root){

	if(!root){
		return 0;
	}
	if(isLeafNodeBinaryTree(root)){
		return 1;
	}

	return getCountOfLeavesInBinaryTree(root->left)+getCountOfLeavesInBinaryTree(root->right);
}

void getleavesLeftToRightInArrayBinarytree(struct BinaryTreeNode *root,int *array,int *top){

	if(!root){
		return;
	}
	if(isLeafNodeBinaryTree(root)){
		array[*top]=root->data;
		(*top)++;
		return;

	}
		getleavesLeftToRightInArrayBinarytree(root->left,array,top);
		getleavesLeftToRightInArrayBinarytree(root->right,array,top);
}


int areHavingSameLeavesBinaryTree(struct BinaryTreeNode *root1,struct BinaryTreeNode *root2){

	int result=0;
	int top1=0;
	int top2=0;
	int numberOfLeaves1=getCountOfLeavesInBinaryTree(root1);
	int numberOfleaves2=getCountOfLeavesInBinaryTree(root2);

	if(numberOfLeaves1!=numberOfleaves2){
		return 0;
	}
	int *firstArr=(int *)malloc(sizeof(int)*numberOfLeaves1);
	int *secondArr=(int *)malloc(sizeof(int)*numberOfleaves2);



	getleavesLeftToRightInArrayBinarytree(root1,firstArr,&top1);
	getleavesLeftToRightInArrayBinarytree(root2,secondArr,&top2);

	for(int i=0;i<numberOfLeaves1;i++){

		if(firstArr[i]!= secondArr[i]){
			return 0;
		}
	}

	return 1;
}

int areHavingSameLeavesOptimizedSpaceBinaryTree(struct BinaryTreeNode *root1,struct BinaryTreeNode *root2){

	struct LinkListWithBtreeNode *stack1=NULL;
	struct LinkListWithBtreeNode *stack2=NULL;

	struct BinaryTreeNode *tmp1=NULL;
	struct BinaryTreeNode *tmp2=NULL;
	addToStack(&stack1,root1);
	addToStack(&stack2,root2);

	while(stack1 || stack2){


		tmp1=deleteFromStack(&stack1);
		while(tmp1!=NULL && !isLeafNodeBinaryTree(tmp1)){

			addToStack(&stack1,tmp1->right);
			addToStack(&stack1,tmp1->left);
			tmp1=deleteFromStack(&stack1);
		}

		tmp2=deleteFromStack(&stack2);
		while(tmp2!=NULL && !isLeafNodeBinaryTree(tmp2)){
			addToStack(&stack2,tmp2->right);
			addToStack(&stack2,tmp2->left);
			tmp2=deleteFromStack(&stack2);
		}

		if(tmp1 && tmp2){
			if(tmp1->data!=tmp2->data){
				return 0;
			}
		}else if(tmp1 && !tmp2){
			return 0;
		}else if(!tmp1 && tmp2){
            return 0;
		}

	}

	return 1;
}
void leavesTraversalLeftToRightRecursiveBinaryTree(struct BinaryTreeNode *root){

	if(!root){
		return;
	}
	if(isLeafNodeBinaryTree(root)){
		printf("%d ",root->data);
		return;
	}
	leavesTraversalLeftToRightRecursiveBinaryTree(root->left);
	leavesTraversalLeftToRightRecursiveBinaryTree(root->right);

}
void leavesTraversalLeftToRightIterativeBinaryTree(struct BinaryTreeNode *root){

	struct LinkListWithBtreeNode *stack=NULL;
	struct BinaryTreeNode *tmp=NULL;

	addToStack(&stack,root);

	while(stack){

		tmp=deleteFromStack(&stack);
		while(!isLeafNodeBinaryTree(tmp)){

			addToStack(&stack,tmp->right);
			addToStack(&stack,tmp->left);
			tmp=deleteFromStack(&stack);
		}

		printf("%d ",tmp->data);
	}
}
void getVLineNumberForAllNodesInBinaryTree(struct BinaryTreeNode *root,int vLine){

	if(!root) return;

	root->vLineNumber=vLine;
	getVLineNumberForAllNodesInBinaryTree(root->left,vLine-1);
	getVLineNumberForAllNodesInBinaryTree(root->right,vLine+1);
}
void verticalLineTraversalBinaryTree(struct BinaryTreeNode *root,int vLine){
	if(!root)return;
	if(root->vLineNumber==vLine){
		printf("%d ",root->data);
	}
	verticalLineTraversalBinaryTree(root->left,vLine);
	verticalLineTraversalBinaryTree(root->right,vLine);

}

void getMinMaxOfVerticalLineNumbersBinaryTree(struct BinaryTreeNode *root,int *min,int *max,int dist){

	if(!root) return;
	if(dist<*min){
		*min=dist;
	}
	if(dist>*max){
		*max=dist;
	}

	getMinMaxOfVerticalLineNumbersBinaryTree(root->left,min,max,dist-1);
	getMinMaxOfVerticalLineNumbersBinaryTree(root->right,min,max,dist+1);

}

void traverseTheVerticalLineNumberOfBinarytree(struct BinaryTreeNode *root,int vLine,int dist){
	if(!root) return;
	if(dist==vLine){
		printf("%d ",root->data);
	}
	traverseTheVerticalLineNumberOfBinarytree(root->left,vLine,dist-1);
	traverseTheVerticalLineNumberOfBinarytree(root->right,vLine,dist+1);
}
void verticalTraversalOptimizedSpaceBinaryTree(struct BinaryTreeNode *root){

	int min=0,max=0;
	getMinMaxOfVerticalLineNumbersBinaryTree(root,&min,&max,0);
	printf("min=%d max=%d\n",min,max);

	for(int vline=min;vline<=max;vline++){
		traverseTheVerticalLineNumberOfBinarytree(root,vline,0);
		printf("\n");
	}

}
void getLeafOfVerticalLineBinaryTree(struct BinaryTreeNode *root,int line,int dist){

	if(!root) return;

	if(line==dist && isLeafNodeBinaryTree(root)){
		printf("%d ",root->data);
	}
	getLeafOfVerticalLineBinaryTree(root->left,line,dist-1);
	getLeafOfVerticalLineBinaryTree(root->right,line,dist+1);

}
void boundryTraversalAntiClockwiseBinaryTree(struct BinaryTreeNode *root){

	int min=0,max=0,i;
	if(!root)return;

	leftboundryInternalNodesTraversalBinaryTree(root);

	getMinMaxOfVerticalLineNumbersBinaryTree(root,&min,&max,0);

	for( i=min;i<=max;i++){
		getLeafOfVerticalLineBinaryTree(root,i,0);

	}
	rightBoundaryInternalNodestraversalBinaryTree(root->right);
}

void leftboundryInternalNodesTraversalBinaryTree(struct BinaryTreeNode *root){
	if(!root) return;
	if(root->left){
		printf("%d ",root->data);
		leftboundryInternalNodesTraversalBinaryTree(root->left);
		return;
	}
	if(root->right){
		printf("%d ",root->data);
		leftboundryInternalNodesTraversalBinaryTree(root->right);
		return;
	}
}
void rightBoundaryInternalNodestraversalBinaryTree(struct BinaryTreeNode *root){

	if(!root)return;
	if(root->right){
		rightBoundaryInternalNodestraversalBinaryTree(root->right);
		printf("%d ",root->data);
		return;
	}

	if(root->left){
		rightBoundaryInternalNodestraversalBinaryTree(root->left);
		printf("%d ",root->data);
		return;
	}
}
void boundryTraversalAntiClockwiseOptimizedBinaryTree(struct BinaryTreeNode *root){

	if(!root)return;
	leftboundryInternalNodesTraversalBinaryTree(root);

	leavesTraversalLeftToRightRecursiveBinaryTree(root->left);
	leavesTraversalLeftToRightRecursiveBinaryTree(root->right);

	rightBoundaryInternalNodestraversalBinaryTree(root->right);
}
void getSpecificOrderOutputQueue(struct LinkListWithBtreeNode *front,struct LinkListWithBtreeNode *rear,int size){

	struct LinkListWithBtreeNode *front1=NULL;
	struct LinkListWithBtreeNode *rear1=NULL;
	struct LinkListWithBtreeNode *stack=NULL;

	struct BinaryTreeNode *tmp=NULL;
	int count=size/2;

	if(size==1){
		tmp=deleteFromQueue(&front,&rear);
		printf("%d ",tmp->data);
		addToQueue(tmp,&front,&rear);
		return;
	}
	//copy first half to another queue
	while(count>0){
		tmp=deleteFromQueue(&front,&rear);
		addToQueue(tmp,&front1,&rear1);
		addToQueue(tmp,&front,&rear);
		count--;
	}
	count=size/2;
	while(count>0){
		tmp=deleteFromQueue(&front,&rear);
		addToStack(&stack,tmp);
		addToQueue(tmp,&front,&rear);
		count--;
	}

	while(stack && front1){

		printf("%d ",deleteFromQueue(&front1,&rear1)->data);
		printf("%d ",deleteFromStack(&stack)->data);

	}

}
void specificLevelOrderTraversalPerfectBinarytree(struct BinaryTreeNode *root){

	struct LinkListWithBtreeNode *front=NULL;
	struct LinkListWithBtreeNode *rear=NULL;

	struct BinaryTreeNode *tmp=NULL;
	int count;

	addToQueue(root,&front,&rear);
	while(front){

		count=sizeOfQueue(front,rear);
		getSpecificOrderOutputQueue(front,rear,count);
		while(count>0){
			tmp=deleteFromQueue(&front,&rear);
			addToQueue(tmp->left,&front,&rear);
			addToQueue(tmp->right,&front,&rear);
			count--;
		}

	}
}


void specificLevelOrderTraversalOptimizedPerfectBinarytree(struct BinaryTreeNode *root){

	struct LinkListWithBtreeNode *front=NULL;
	struct LinkListWithBtreeNode *rear=NULL;

	struct BinaryTreeNode *tmp1=NULL;
	struct BinaryTreeNode *tmp2=NULL;
	int count;

	if(!root)return;

	printf("%d ",root->data);
	addToQueue(root->left,&front,&rear);
	addToQueue(root->right,&front,&rear);
	while(front){

		count=sizeOfQueue(front,rear);

		while(count>0){
			tmp1=deleteFromQueue(&front,&rear);
			tmp2=deleteFromQueue(&front,&rear);
			printf("%d ",tmp1->data);
			printf("%d ",tmp2->data);
			addToQueue(tmp1->left,&front,&rear);
			addToQueue(tmp2->right,&front,&rear);

			addToQueue(tmp1->right,&front,&rear);
			addToQueue(tmp2->left,&front,&rear);
			count-=2;
		}

	}
}

void specificLevelOrderTraversalBottomToTopPerfectBinarytree(struct BinaryTreeNode *root){

	struct LinkListWithBtreeNode *front=NULL;
	struct LinkListWithBtreeNode *rear=NULL;

	struct LinkListWithBtreeNode *stack=NULL;

	struct BinaryTreeNode *tmp1=NULL;
	struct BinaryTreeNode *tmp2=NULL;
	int count;

	if(!root)return;

	addToStack(&stack,root);
	addToQueue(root->left,&front,&rear);
	addToQueue(root->right,&front,&rear);
	while(front){

		count=sizeOfQueue(front,rear);

		while(count>0){
			tmp1=deleteFromQueue(&front,&rear);
			tmp2=deleteFromQueue(&front,&rear);
			addToStack(&stack,tmp2);
			addToStack(&stack,tmp1);

			addToQueue(tmp1->right,&front,&rear);
			addToQueue(tmp2->left,&front,&rear);

			addToQueue(tmp1->left,&front,&rear);
			addToQueue(tmp2->right,&front,&rear);


			count-=2;
		}

	}

	while(stack){
		printf("%d ",deleteFromStack(&stack)->data);
	}
}
void getPostOrderTraversalFromInorderAndPreOrderBinaryTree(int* in,int* pre,int n){

	int index=getElementIndex(in,0,n-1,*pre);

	if(index!=0){
		getPostOrderTraversalFromInorderAndPreOrderBinaryTree(in,pre+1,index);
	}
	if(index!=n-1){
		getPostOrderTraversalFromInorderAndPreOrderBinaryTree(in+index+1,pre+index+1,n-index-1);
	}

	printf("%d ",in[index]);
}

void getPreOrderTraversalFromInOrderAndPostOrderBinaryTree(int *in,int *post,int n){

	int index=getElementIndex(in,0,n-1,*post);
	printf("%d ",in[index]);
	if(index!=0){
		getPreOrderTraversalFromInOrderAndPostOrderBinaryTree(in,post-(n-index),index);
	}
	if(index!=n-1){
		getPreOrderTraversalFromInOrderAndPostOrderBinaryTree(in+index+1,post-1,n-index-1);
	}
}

void preOrderTraversalIterativeByStackBinaryTree(struct BinaryTreeNode *root){

	struct LinkListWithBtreeNode *stack=NULL;
	while(root||stack){

		if(root){
			printf("%d ",root->data);
			addToStack(&stack,root);
			root=root->left;
		}else{
			root=deleteFromStack(&stack);
			root=root->right;
		}
	}
}

void preOrderTraversalIterativeByStackMethod2BinaryTree(struct BinaryTreeNode *root){

	struct LinkListWithBtreeNode *stack=NULL;
	struct BinaryTreeNode *tmp=NULL;

	addToStack(&stack,root);

	while(stack){

		tmp=deleteFromStack(&stack);
		printf("%d ",tmp->data);
		addToStack(&stack,tmp->right);
		addToStack(&stack,tmp->left);
	}
}
void preOrderTraversalIterativeWithoutStackBinarytree(struct BinaryTreeNode *root){

	struct BinaryTreeNode *lroot=NULL;
	while(root){
		if(root->left==NULL){
			printf("%d ",root->data);
			root=root->right;
		}else{
			lroot=root->left;
			while(lroot->right && lroot->right!=root){
				lroot=lroot->right;
			}
			if(lroot->right==NULL){
				lroot->right=root;
				printf("%d ",root->data);
				root=root->left;
			}else{
				lroot->right=NULL;
				root=root->right;
			}
		}

	}

}

void postOrderTraversalIterativeByOneStack(struct BinaryTreeNode *root){

	struct LinkListWithBtreeNode *stack=NULL;

	while(root||stack){

		if(root){
			addToStack(&stack,root->right);
			addToStack(&stack,root);
			root=root->left;
		}else{
			root=deleteFromStack(&stack);

			if(root->right && stack &&  stack->data == root->right){
				deleteFromStack(&stack);
				addToStack(&stack,root);
				root=root->right;
			}else{
				printf("%d ",root->data);
				root=NULL;

			}
		}
	}
}

/*
 * do VRL traversal.so post order is reverse of VRL which is LRV.
 */
void postOrderTraversalIterativeByTwoStack(struct BinaryTreeNode *root){
	struct LinkListWithBtreeNode *saveStack=NULL;
	struct LinkListWithBtreeNode *stack=NULL;

	while(root||stack){

		if(root){
			addToStack(&saveStack,root);
			addToStack(&stack,root);
			root=root->right;
		}else{
			root=deleteFromStack(&stack);
			root=root->left;
		}
	}
	while(saveStack){
		printf("%d ",deleteFromStack(&saveStack)->data);
	}

}
int searInBinaryTree(struct BinaryTreeNode *root,int key){
	struct LinkListWithBtreeNode *stack=NULL;

	while(root||stack){
		if(root){
			addToStack(&stack,root);
			root=root->left;
		}else{

			root=deleteFromStack(&stack);
			if(root->data==key){
				return 1;
			}
			root=root->right;
		}
	}
	return 0;
}
struct BinaryTreeNode* lcaBinaryTree(struct BinaryTreeNode *root,int key1,int key2){

	if(!root) return NULL;

	if(searInBinaryTree(root->left,key1)&& searInBinaryTree(root->left,key2)){
		return lcaBinaryTree(root->left,key1,key2);
	}
	if(searInBinaryTree(root->right,key1)&& searInBinaryTree(root->right,key2)){
		return lcaBinaryTree(root->right,key1,key2);
	}

	return root;

}
int  getPathInArrayBinaryTree(struct BinaryTreeNode *root,int key,int *array,int *size){

	if(!root) return 0;


	if(root->data==key || getPathInArrayBinaryTree(root->left,key,array,size)||getPathInArrayBinaryTree(root->right,key,array,size)){
		array[(*size)++]=root->data;

		return 1;

	}

	return 0;
}
int lcaNonSpaceOptimizedBinaryTree(struct BinaryTreeNode *root,int key1,int key2){
	int path1[100],path2[100];
	int path1Size=0,path2Size=0;

	if(	!getPathInArrayBinaryTree(root,key1,path1,&path1Size)|| !getPathInArrayBinaryTree(root,key2,path2,&path2Size)){
		return -1;
	}

	for(int i=path1Size-1,j=path2Size-1;i>=0 && j>=0;i--,j--){
		if(path1[i]!=path2[j]){
			return path1[i+1];
		}
	}
}
struct BinaryTreeNode* lcaOptimizedBinaryTree(struct BinaryTreeNode *root,int key1,int key2){

	if(!root) return NULL;
	if(root->data==key1||root->data==key2){
		return root;
	}

	struct BinaryTreeNode *leftLca=lcaOptimizedBinaryTree(root->left,key1,key2);
	struct BinaryTreeNode *rightLca=lcaOptimizedBinaryTree(root->right,key1,key2);

	if(leftLca && rightLca) return root;
	return (leftLca!=NULL?leftLca:rightLca);
}

int getLevelOfNodeInBinaryTree(struct BinaryTreeNode *root,int key){

	if(!root) return 0;

	if(root->data==key){
		return 1;
	}
	int leftValue=getLevelOfNodeInBinaryTree(root->left,key);
	int rightValue=getLevelOfNodeInBinaryTree(root->right,key);

	if(!leftValue && !rightValue){
		return 0;
	}
	return (leftValue?1+leftValue:1+rightValue);


}
int getDistBtwTwoNodesBinaryTree(struct BinaryTreeNode *root,int key1,int key2){

	struct BinaryTreeNode *lca=lcaOptimizedBinaryTree(root,key1,key2);

	int levelLca=getLevelOfNodeInBinaryTree(root,lca->data);
	int levelKey1=getLevelOfNodeInBinaryTree(lca,key1);
	int levelKey2=getLevelOfNodeInBinaryTree(lca,key2);

	//printf("k1=%d,k2=%d,lca=%d\n",levelKey1,levelKey2,levelLca);

	return levelKey1+levelKey2-2;
}

int  getPathFromRootBinaryTree(struct BinaryTreeNode *root,int key){

	if(!root)return 0;
	if(root->data==key||getPathFromRootBinaryTree(root->left,key)||getPathFromRootBinaryTree(root->right,key)){
		printf("%d ",root->data);
		return 1;
	}

}
void getCommonAncestorsOfTwoNodes(struct BinaryTreeNode *root,int key1,int key2){

	struct BinaryTreeNode *lca=lcaOptimizedBinaryTree(root,key1,key2);


	if(lca==root){
		return;
	}

	getPathFromRootBinaryTree(root,lca->data);
}
int* extractKeysForNewLevel(int *inorder,int start,int end,int* levelorder,int size){

	int *newLevel=(int *)malloc(sizeof(int)*(end-start+1));
	int j=0;
	for(int i=0;i<size;i++){
		if(getElementIndex(inorder,start,end,levelorder[i])!=-1){
			newLevel[j++]=levelorder[i];
		}
	}

	return newLevel;
}

struct BinaryTreeNode*  buildBinaryTreeFromInOrderAndLevelOrderTraversal(int *inorder,int start,int end,int *levelorder,int size){

	if(start>end)return NULL;
	struct BinaryTreeNode *root=getBinaryTreeNode(*levelorder);

	if(start==end) return root;

	int index=getElementIndex(inorder,start,end,*levelorder);

	int *llevel=extractKeysForNewLevel(inorder,start,index-1,levelorder,size);
	int *rlevel=extractKeysForNewLevel(inorder,index+1,end,levelorder,size);


	root->left=buildBinaryTreeFromInOrderAndLevelOrderTraversal(inorder,start,index-1,llevel,index);
	root->right=buildBinaryTreeFromInOrderAndLevelOrderTraversal(inorder,index+1,end,rlevel,size-index-1);

	return root;
}


struct BinaryTreeNode*  buildBinaryTreeFromInOrderAndLevelOrderTraversalOptimized(int *inorder,int start,int end,int *levelorder,int size){

	int *llevel, *rlevel,i,j,k;
	if(start>end) return NULL;
	struct BinaryTreeNode *root=getBinaryTreeNode(*levelorder);

	if(start==end) return root;

	int index=getElementIndex(inorder,start,end,*levelorder);
	int hashtable[100]={0};

	for(i=start;i<index;i++){
		hashtable[inorder[i]]=1;
	}

	llevel=(int *)malloc(sizeof(int)*index);
	rlevel=(int *)malloc(sizeof(int)*(size-index-1));

	j=0;
	k=0;
	for(i=1;i<size;i++){
		if(hashtable[levelorder[i]]){
			llevel[j++]=levelorder[i];
		}else{
			rlevel[k++]=levelorder[i];
		}
	}


	root->left=buildBinaryTreeFromInOrderAndLevelOrderTraversal(inorder,start,index-1,llevel,index);
	root->right=buildBinaryTreeFromInOrderAndLevelOrderTraversal(inorder,index+1,end,rlevel,size-index-1);

	return root;
}

struct BinaryTreeNode* buildBinaryTreeFromParentArrayRepresentation(int* parent,int n,int searchElement){

	int index=getElementIndex(parent,0,n,searchElement);
	parent[index]=-1;
	if(index==-1)return NULL;

	struct BinaryTreeNode* root=getBinaryTreeNode(index);

	root->left=buildBinaryTreeFromParentArrayRepresentation(parent,n,index);
	root->right=buildBinaryTreeFromParentArrayRepresentation(parent,n,index);

	return root;
}

void createNode(int *parent,int index,struct BinaryTreeNode** created,struct BinaryTreeNode **root){


	if(created[index]!=NULL) return;

	created[index]=getBinaryTreeNode(index);

	if(parent[index]==-1){
		*root=created[index];
		 return;
	}


	if(created[parent[index]]==NULL){
		createNode(parent,parent[index],created,root);
	}
	struct BinaryTreeNode* p=created[parent[index]];
	if(!p->left){
		p->left=created[index];
	}else{
		p->right=created[index];
	}

}
struct BinaryTreeNode* buildBinaryTreeFromParentArrayRepresentationOptimized(int* parent,int n){


	struct BinaryTreeNode** created=(struct BinaryTreeNode **)malloc(sizeof(struct BinaryTreeNode *)*n);
    int i;
	for(i=0;i<n;i++){

		created[i]=NULL;
	}

	struct BinaryTreeNode* root=NULL;
	for(i=0;i<n;i++){
		createNode(parent,i,created,&root);
	}
	return root;
}
struct BinaryTreeNode* buildDLLUtil(struct BinaryTreeNode* root){

	if(root->left){

		struct BinaryTreeNode* left=buildDLLUtil(root->left);

		//find predecessor of root
		while(left->right){
			left=left->right;
		}
		root->left=left;
		left->right=root;
	}
	if(root->right){

		struct BinaryTreeNode* right=buildDLLUtil(root->right);
		//get the succesor of root
		while(right->left){
			right=right->left;
		}
		root->right=right;
		right->left=root;

	}
	return root;
}
struct BinaryTreeNode* buildDLLWithLeftAndRightPointersFromBinaryTree(struct BinaryTreeNode *root){


	if (!root) return NULL;

	root=buildDLLUtil(root);

	while(root->left){
		root=root->left;
	}

	return root;
}

void buildDLLWithLeftAndRightPointersByInorderFromBinaryTree(struct BinaryTreeNode* root,struct BinaryTreeNode **headRef,int *count){

	if(!root) return ;
	buildDLLWithLeftAndRightPointersByInorderFromBinaryTree(root->left,headRef,count);

	if(*headRef==NULL){
		*headRef=root;
		(*count)++;

	}else{

	struct BinaryTreeNode *ptr=*headRef;
	int save=*count;
	while(save>1){
		ptr=ptr->right;
		save--;
	}
	ptr->right=root;
	root->left=ptr;
	(*count)++;

	}

	buildDLLWithLeftAndRightPointersByInorderFromBinaryTree(root->right,headRef,count);

}

void buildDLLWithLeftAndRightPointersByReverseInorderFromBinaryTree(struct BinaryTreeNode* root,struct BinaryTreeNode **headRef){


	if(!root) return ;
	buildDLLWithLeftAndRightPointersByReverseInorderFromBinaryTree(root->right,headRef);

	root->right=*headRef;
	if(*headRef)
	(*headRef)->left=root;

	*headRef=root;
	buildDLLWithLeftAndRightPointersByReverseInorderFromBinaryTree(root->left,headRef);


}

void buildDLLWithLeftAndRightPointersbyInorderOptimizedFromBinaryTree(struct BinaryTreeNode* root,struct BinaryTreeNode **headRef,struct BinaryTreeNode **prev){

	if(!root)return;
	buildDLLWithLeftAndRightPointersbyInorderOptimizedFromBinaryTree(root->left,headRef,prev);

	if(*headRef==NULL){
		*headRef=root;
	}else{

		(*prev)->right=root;
		root->left=*prev;
	}

	*prev=root;

	buildDLLWithLeftAndRightPointersbyInorderOptimizedFromBinaryTree(root->right,headRef,prev);


}

void traverseChildSiblingRepresentation(struct BinaryTreeNode* root){

	if(!root) return;
	while(root){
		printf("%d ",root->data);
		if(root->left){
			traverseChildSiblingRepresentation(root->left);

		}
		root=root->right;
	}
}


void convertToChildSiblingRepFromBinaryTree(struct BinaryTreeNode* root){

	if(!root)return;
	if(root->left){

		convertToChildSiblingRepFromBinaryTree(root->left);

		root->left->right=root->right;
		root->right=NULL;
		convertToChildSiblingRepFromBinaryTree(root->left->right);
	}else if(root->right){

		root->left=root->right;
		root->right=NULL;
		convertToChildSiblingRepFromBinaryTree(root->left->right);
	}
}

void convertToChildSiblingRepOptimizedFronBinaryTree(struct BinaryTreeNode* root){

	if(!root) return;
	convertToChildSiblingRepOptimizedFronBinaryTree(root->left);
	convertToChildSiblingRepOptimizedFronBinaryTree(root->right);

	if(!root->left){

		root->left=root->right;
	}else{

		root->left->right=root->right;
	}
	root->right=NULL;
}

int  convertToSumFromBinarytree(struct BinaryTreeNode* root){

	int value;
	if(!root)return 0;

	value=root->data;
	root->data=convertToSumFromBinarytree(root->left)+convertToSumFromBinarytree(root->right);

	return root->data+value;

}
int convertToLeftTreeSumFromBinaryTree(struct BinaryTreeNode* root){
	if(!root) return 0;

	root->data=root->data+convertToLeftTreeSumFromBinaryTree(root->left);

	return root->data+convertToLeftTreeSumFromBinaryTree(root->right);
}

struct BinaryTreeNode* convertToMirrorViewFromBinaryTree(struct BinaryTreeNode* root){
	if(root==NULL) return NULL;
	if(isLeafNodeBinaryTree(root)) return root;

	struct BinaryTreeNode * left=convertToMirrorViewFromBinaryTree(root->left);
	struct BinaryTreeNode * right=convertToMirrorViewFromBinaryTree(root->right);

	root->left=right;
	root->right=left;
	return root;

}

void convertToMirrorViewMethod2FromBinaryTree(struct BinaryTreeNode* root){

	if(!root) return ;
	struct BinaryTreeNode* tmp;
	convertToMirrorViewMethod2FromBinaryTree(root->left);
	convertToMirrorViewMethod2FromBinaryTree(root->right);

	tmp=root->left;
	root->left=root->right;
	root->right=tmp;

}
void convertToMirrorViewIterativeFromBinaryTree(struct BinaryTreeNode* root){

	if(!root) return;
	struct LinkListWithBtreeNode* front=NULL;
	struct LinkListWithBtreeNode* rear=NULL;

	struct BinaryTreeNode* tmp=root;
	struct BinaryTreeNode* ptr;
	while(tmp){

		addToQueue(tmp->left,&front,&rear);
		addToQueue(tmp->right,&front,&rear);
		ptr=tmp->left;
		tmp->left=tmp->right;
		tmp->right=ptr;
		tmp=deleteFromQueue(&front,&rear);
	}
}
void getSortedNodesInArrayFromBinarytree(struct BinaryTreeNode* root,int* array,int *index){

	if(root==NULL) return;

	getSortedNodesInArrayFromBinarytree(root->left,array,index);
	array[(*index)++]=root->data;
	getSortedNodesInArrayFromBinarytree(root->right,array,index);

}
struct BinaryTreeNode* buildBalanceBSTUtil(int *array,int start,int end){

	if(start>end) return NULL;

	int mid=(start+end)/2;
	struct BinaryTreeNode* root=getBinaryTreeNode(array[mid]);

	root->left=buildBalanceBSTUtil(array,start,mid-1);
	root->right=buildBalanceBSTUtil(array,mid+1,end);

	return root;
}
struct BinaryTreeNode* convertBSTToBalanceBST(struct BinaryTreeNode* root){

	int *array=(int *)malloc(sizeof(int)* getSizeOfBinaryTree(root));
	int index=0;
	getSortedNodesInArrayFromBinarytree(root,array,&index);

	return buildBalanceBSTUtil(array,0,index-1);

}
struct BinaryTreeNode* concatCircularDLLUtil(struct BinaryTreeNode* head1,struct BinaryTreeNode* head2){

	if(head1==NULL) return head2;
	if(head2==NULL) return head1;

	struct BinaryTreeNode* lastNodhead1=head1->left;
	struct BinaryTreeNode* lastNodeHead2=head2->left;

	lastNodhead1->right=head2;
	head2->left=lastNodhead1;

	head1->left=lastNodeHead2;
	lastNodeHead2->right=head1;
	return head1;


}
struct BinaryTreeNode* convertToCircularDLLFrombinarytree(struct BinaryTreeNode* root){

	if(root==NULL) return NULL;
	struct BinaryTreeNode* left=convertToCircularDLLFrombinarytree(root->left);
	struct BinaryTreeNode* right=convertToCircularDLLFrombinarytree(root->right);

	// single node convert to a circular list
	root->left=root;
	root->right=root;

	return concatCircularDLLUtil(concatCircularDLLUtil(left,root),right);

}
struct BinaryTreeNode*  convertToLogicalANDNodesFromBinaryTree(struct BinaryTreeNode* root){
	if(!root) return -1 ;
	int left=convertToLogicalANDNodesFromBinaryTree(root->left);
	int right=convertToLogicalANDNodesFromBinaryTree(root->right);

	if(left==-1||right==-1){
		return root->data;
	}
		root->data=left && right;
		return root->data;

}

struct BinaryTreeNode* convertTerniaryoperationTobinarytree(char *string,int len){

	if(!len)return NULL;

	struct BinaryTreeNode* root=getBinaryTreeNode(string[0]-'0');
	root->right=getBinaryTreeNode(string[len-1]-'0');
	struct BinaryTreeNode *ptr=root;

	int i,j;
	for(i=1,j=len-2;i<len && j>=0 && i<j;){
		if(!isdigit(string[i])&& !isdigit(string[j])){
			i++;j--;
		}else{

			ptr->left=getBinaryTreeNode(string[i]-'0');
			ptr=ptr->left;
			ptr->right=getBinaryTreeNode(string[j]-'0');
			i++;j--;
		}
	}
	if(i==j){
		ptr->left=getBinaryTreeNode(string[i]-'0');
	}
	return root;
}

struct BinaryTreeNode* deleteBinarytree(struct BinaryTreeNode* root){
	if(root==NULL) return NULL;
	deleteBinarytree(root->left);
	deleteBinarytree(root->right);
	root->left=NULL;
	root->right=NULL;
	free(root);
	root=NULL;
	return root;
}

int isRootToLeafPathSumEqualToGivenValueBinarytree(struct BinaryTreeNode* root,int value){

	if(root==NULL) return 0;
	if(isLeafNodeBinaryTree(root)){
		return root->data-value?0:1;
	}

	return isRootToLeafPathSumEqualToGivenValueBinarytree(root->left,value-root->data)||isRootToLeafPathSumEqualToGivenValueBinarytree(root->right,value-root->data);
}
int isBalanceBinaryTree(struct BinaryTreeNode* root){

	if(root==NULL) return 1;
	if (!isBalanceBinaryTree(root->left)||!isBalanceBinaryTree(root->right))
	{
		return 0;
	}
	int leftSubTreeHeight=getheightOfBinaryTreeOptimized(root->left);
	int rightSubTreeHeaight=getheightOfBinaryTreeOptimized(root->right);

	return abs(leftSubTreeHeight-rightSubTreeHeaight)<=1?1:0;
}

int isBalanceBinaryTreeOptimized(struct BinaryTreeNode* root,int *height){

	int leftHeight,rightHeight;
	if(root==NULL){
		*height=0;
		return 1;
	}
	if (!isBalanceBinaryTreeOptimized(root->left,&leftHeight)||!isBalanceBinaryTreeOptimized(root->right,&rightHeight))
		{
			return 0;
		}
	*height=maxoftwo(leftHeight,rightHeight)+1;
	return abs(leftHeight-rightHeight)<=1?1:0;
}
int isChildrenSumPropertySatisfiedInBinaryTree(struct BinaryTreeNode* root){

	if(root==NULL) return 1;
	if(isLeafNodeBinaryTree(root)) return 1;
	if(isChildrenSumPropertySatisfiedInBinaryTree(root->left)==0 || isChildrenSumPropertySatisfiedInBinaryTree(root->right)==0){
		return 0;
	}
	int leftValue=root->left!=NULL?root->left->data:0;
	int rightvalue=root->right!=NULL?root->right->data:0;

	return root->data==leftValue+rightvalue?1:0;
}
int isCompleteBinaryTreeIterative(struct BinaryTreeNode* root){

	struct LinkListWithBtreeNode* front=NULL;
	struct LinkListWithBtreeNode* rear=NULL;

	struct BinaryTreeNode* tmp=NULL;
	int flag=0;
	addToQueue(root,&front,&rear);

	while(front){

		tmp=deleteFromQueue(&front,&rear);
		if(tmp->left){

			if(flag) return 0;
			addToQueue(tmp->left,&front,&rear);
		}else {
			flag=1;
		}
		if(tmp->right){

			if(flag) return 0;
			addToQueue(tmp->right,&front,&rear);
		}else{
			flag=1;
		}

	}

	return 1;
}
int minOfTwo(int a,int b){
	return a<b?a:b;
}
int getMinDepthOfBinaryTree(struct BinaryTreeNode* root){

	if(!root) return 0;
	if(isLeafNodeBinaryTree(root)) return 1;

	if(!root->right) return 1+getMinDepthOfBinaryTree(root->left);
	if(!root->left) return 1+getMinDepthOfBinaryTree(root->right);

	return 1+minOfTwo(getMinDepthOfBinaryTree(root->left),getMinDepthOfBinaryTree(root->right));
}
int getMinDepthOfBinaryTreeOptimized(struct BinaryTreeNode* root){

	struct LinkListWithBtreeNode* front=NULL;
	struct LinkListWithBtreeNode* rear=NULL;
	struct BinaryTreeNode* tmp=NULL;
	int minDepth=0,count;
	addToQueue(root,&front,&rear);
	while(front){
		count=sizeOfQueue(front,rear);
		minDepth++;
		while(count>0){
			tmp=deleteFromQueue(&front,&rear);
			if(isLeafNodeBinaryTree(tmp)){
				return minDepth;
			}
			addToQueue(tmp->left,&front,&rear);
			addToQueue(tmp->right,&front,&rear);
			count--;
		}
	}
	return minDepth;
}

void getMaxInBinaryTree(struct BinaryTreeNode* root,int *max){

	if(!root) return ;
	getMaxInBinaryTree(root->left,max);
	if(*max <root->data){
		*max=root->data;
	}
	getMaxInBinaryTree(root->right,max);
}
int getMaxInBinaryTreeOptimized(struct BinaryTreeNode* root){

	if(!root) return -1;
	if(isLeafNodeBinaryTree(root)) return root->data;

	int leftMax=getMaxInBinaryTreeOptimized(root->left);
	int rightMax=getMaxInBinaryTreeOptimized(root->right);

	return maxOfThree(root->data,leftMax,rightMax);
}
void  getLeftLeavesSumBinaryTree(struct BinaryTreeNode* root,int *sum){

	if(root==NULL) return ;
	getLeftLeavesSumBinaryTree(root->left,sum);

	if(isLeafNodeBinaryTree(root->left)){
		(*sum)+=root->left->data;
	}
	getLeftLeavesSumBinaryTree(root->right,sum);
}
int getLeftLeavesSumOfBinaryTreeOptimized(struct BinaryTreeNode* root){


	if(root==NULL) return 0;
	int result=0;
	if(isLeafNodeBinaryTree(root->left)){
		result+=root->left->data;
	}else{
		result+=getLeftLeavesSumOfBinaryTreeOptimized(root->left);
	}
	result+=getLeftLeavesSumOfBinaryTreeOptimized(root->right);

	return result;

}
struct BinaryTreeNode* getParentInBinaryTree(struct BinaryTreeNode* root,int childvalue){

	if(!root) return NULL;
	if((root->left && root->left->data==childvalue)||(root->right && root->right->data==childvalue)) return root;

	struct BinaryTreeNode* left=getParentInBinaryTree(root->left,childvalue);
	struct BinaryTreeNode* right=getParentInBinaryTree(root->right,childvalue);

	if(!left && !right) return NULL;
	return left?left:right;
}
int areCousinsInBinarytree(struct BinaryTreeNode* root,int a,int b){

	if(!root) return 0;

	int levelA=getLevelOfNodeInBinaryTree(root,a);
	int levelB=getLevelOfNodeInBinaryTree(root,b);

	if(levelA!=levelB){
		return 0;
	}

	struct BinaryTreeNode* parentA=getParentInBinaryTree(root,a);
	struct BinaryTreeNode* parentB=getParentInBinaryTree(root,b);

	if(parentA==parentB){
		return 0;
	}
	return 1;
}
int areSiblingsInBinaryTree(struct BinaryTreeNode* root,int a,int b){

	if(!root) return 0;
	if(root->left && root->right && ((root->left->data==a && root->right->data==b)||(root->right->data==a && root->left->data==b))){
		return 1;
	}
	return areSiblingsInBinaryTree(root->left,a,b)||areSiblingsInBinaryTree(root->right,a,b);

}
int areCousinsInBinarytreeOptimized(struct BinaryTreeNode* root,int a,int b){

	if(!root) return 0;

	return (getLevelOfNodeInBinaryTree(root,a)== getLevelOfNodeInBinaryTree(root,b)) && !areSiblingsInBinaryTree(root,a,b);
}

void createDepthArray(int* parent ,int index,int* depth){

	if(depth[index]) return;
	if(parent[index]==-1) {
		depth[index]=1;
		return;
	}
	if(depth[parent[index]]==0){
		createDepthArray(parent,parent[index],depth);
	}
	depth[index]=1;
	int parentDepth=depth[parent[index]];
	depth[index]+=parentDepth;
}
int getHeightFromParentArrayRepOfBinaryTree(int* parent,int size){

	int* depth=(int *)calloc(size,sizeof(int));
	int i,max=0;

	for(i=0;i<size;i++){
		createDepthArray(parent,i,depth);
	}

	for(i=0;i<size;i++){
		if(max<depth[i])
			max=depth[i];
	}

   return max;
}

void topViewTraversalOfBinaryTree(struct BinaryTreeNode* root){

	getVLineNumberForAllNodesInBinaryTree(root,0);
	struct LinkListWithBtreeNode* front=NULL;
	struct LinkListWithBtreeNode* rear=NULL;

	struct BinaryTreeNode* tmp=NULL;
	int c,max=0,min=0;

	printf("%d ",root->data);
	addToQueue(root->left,&front,&rear);
	addToQueue(root->right,&front,&rear);

	while(front){

		c=sizeOfQueue(front,rear);
		while(c>0){
			tmp=deleteFromQueue(&front,&rear);

			if(tmp->vLineNumber<min){
				printf("%d ",tmp->data);
				min=tmp->vLineNumber;
			}

			if(tmp->vLineNumber>max){
				printf("%d ",tmp->data);
				max=tmp->vLineNumber;
			}

			addToQueue(tmp->left,&front,&rear);
			addToQueue(tmp->right,&front,&rear);
			c--;
		}
	}

}

void diagonalSumTraversalOfBinaryTree(struct BinaryTreeNode* root){

	struct LinkListWithBtreeNode* front=NULL;
	struct LinkListWithBtreeNode* rear=NULL;
	struct BinaryTreeNode* tmp=NULL;

	addToQueue(root,&front,&rear);

	int c,sum;
	while (front) {

		c = sizeOfQueue(front, rear);
		sum=0;
		while (c > 0) {
			tmp = deleteFromQueue(&front, &rear);
			while (tmp) {

				sum+=tmp->data;
				if (tmp->left) {
					addToQueue(tmp->left, &front, &rear);
				}
				tmp = tmp->right;
			}

			c--;
		}

		printf("%d \n",sum);
	}

}
void storeInorderInArray(struct BinaryTreeNode* root,int* array,int *size){

	if(!root){
		array[(*size)++]=-1;
		return;
	}
	storeInorderInArray(root->left,array,size);
	array[(*size)++]=root->data;
	storeInorderInArray(root->right,array,size);
}
void storePreorderInArray(struct BinaryTreeNode* root,int* array,int *size){

	if(!root){
		array[(*size)++]=-1;
		return;
	}
	array[(*size)++]=root->data;
	storePreorderInArray(root->left,array,size);
	storePreorderInArray(root->right,array,size);
}
int searchSubArrayInArray(int *subArray,int subSize,int* array,int size){

	int i,j,k;
	for(i=0;i<size;i++){

		k=i;
		for(j=0;j<subSize && k<size;j++,k++){

			if(subArray[j]!=array[k]){
				break;
			}

		}
		if(j==subSize){
			return 1;
		}
	}


	return 0;
}
int isSubtreeOfBinaryTreeOptimized(struct BinaryTreeNode* subtree,struct BinaryTreeNode* tree){

	int i;
	int intree[100],insubtree[100];
	int intreeSize=0,insubtreeSize=0;

	int pretree[100],presubtree[100];
	int pretreeSize=0,presubtreeSize=0;
	storeInorderInArray(subtree,insubtree,&insubtreeSize);
	storeInorderInArray(tree,intree,&intreeSize);


	if(!searchSubArrayInArray(insubtree,insubtreeSize,intree,intreeSize)){
		return 0;
	}

	storePreorderInArray(subtree,presubtree,&presubtreeSize);
	storePreorderInArray(tree,pretree,&pretreeSize);

	if(!searchSubArrayInArray(presubtree,presubtreeSize,pretree,pretreeSize)){
		return 0;
	}

	return 1;
}

int areIsomorphicBinaryTree(struct BinaryTreeNode* root1,struct BinaryTreeNode* root2){

	if(!root1 && !root2 ) return 1;
	if(!root1|| !root2) return 0;

	if(root1->data!=root2->data) return 0;

	return (areIsomorphicBinaryTree(root1->left,root2->left) && areIsomorphicBinaryTree(root1->right,root2->right)) ||
			(areIsomorphicBinaryTree(root1->left,root2->right) && areIsomorphicBinaryTree(root1->right,root2->left));
}

int areLeavesAtSameLevelUtil(struct BinaryTreeNode* root,int height){

	struct LinkListWithBtreeNode* front=NULL;
	struct LinkListWithBtreeNode* rear=NULL;
	struct BinaryTreeNode* tmp=NULL;
	int c,level=0;
	addToQueue(root,&front,&rear);

	while(front){
		c=sizeOfQueue(front,rear);
		level++;

		while(c>0){
			tmp=deleteFromQueue(&front,&rear);
			if(isLeafNodeBinaryTree(tmp) && level!=height){
				return 0;
			}
			addToQueue(tmp->left,&front,&rear);
			addToQueue(tmp->right,&front,&rear);
			c--;
		}
	}

	return 1;
}
int areLeavesAtSameLevelInBinaryTree(struct BinaryTreeNode* root){

	int height=getheightOfBinaryTreeOptimized(root);

	return areLeavesAtSameLevelUtil(root,height);
}

void rightViewTraversalOfBinaryTree(struct BinaryTreeNode* root){

	struct LinkListWithBtreeNode* front=NULL;
	struct LinkListWithBtreeNode* rear=NULL;
	struct BinaryTreeNode* tmp=NULL;
	int count;

	addToQueue(root,&front,&rear);
	while(front){
		count=sizeOfQueue(front,rear);
		while(count>0){
			tmp=deleteFromQueue(&front,&rear);
			if(count==1){
				printf("%d ",tmp->data);
			}
			addToQueue(tmp->left,&front,&rear);
			addToQueue(tmp->right,&front,&rear);
			count--;
		}
	}
}

void withoutSiblingNodesTraversalBinaryTree(struct BinaryTreeNode* root){

	if(!root) return;
	if(isLeafNodeBinaryTree(root)) return;
	if(!root->left || !root->right){
		printf("%d ",root->left?root->left->data:root->right->data);
	}
	withoutSiblingNodesTraversalBinaryTree(root->left);
	withoutSiblingNodesTraversalBinaryTree(root->right);
}

void leftViewTraversalOfBinaryTree(struct BinaryTreeNode* root){

	struct LinkListWithBtreeNode* front=NULL;
	struct LinkListWithBtreeNode* rear=NULL;
	struct BinaryTreeNode* tmp=NULL;

	int count;

	addToQueue(root,&front,&rear);

	while(front){

		count=sizeOfQueue(front,rear);
		while(count){

			tmp=deleteFromQueue(&front,&rear);
			if(count==1){
				printf("%d ",tmp->data);
			}
			addToQueue(tmp->right,&front,&rear);
			addToQueue(tmp->left,&front,&rear);
			count--;
		}
	}
}

void leftViewTraversalOfBinaryTreeUtil(struct BinaryTreeNode* root,int level,int* max){

	if(!root) return;
	if(level>*max){
		printf("%d ",root->data);
		*max=level;
	}
	leftViewTraversalOfBinaryTreeUtil(root->left,level+1,max);
	leftViewTraversalOfBinaryTreeUtil(root->right,level+1,max);
}
void leftViewTraversalOfBinaryTreeSpaceOptimized(struct BinaryTreeNode* root){

	int max=0;
	 leftViewTraversalOfBinaryTreeUtil(root,1,&max);

}


int getDepthOfDeppestOddLevelLeafnodeBinaryTree(struct BinaryTreeNode* root){

	struct LinkListWithBtreeNode* front=NULL;
	struct LinkListWithBtreeNode* rear=NULL;
	struct BinaryTreeNode* tmp=NULL;

	int count,level=0,maxDepth=0;

	addToQueue(root,&front,&rear);

	while(front){

		count=sizeOfQueue(front,rear);
		level++;
		while(count){

			tmp=deleteFromQueue(&front,&rear);
			if(isLeafNodeBinaryTree(tmp) && level%2){
				maxDepth=level;
			}
			addToQueue(tmp->right,&front,&rear);
			addToQueue(tmp->left,&front,&rear);
			count--;
		}
	}
return maxDepth;
}
void  getDepthOfDeppestOddLevelLeafnodeUtil(struct BinaryTreeNode* root,int level,int* max){

	if(!root) return ;
	if(isLeafNodeBinaryTree(root) && level%2){
		if(level>*max)
		*max=level;
		return;
	}
	getDepthOfDeppestOddLevelLeafnodeUtil(root->left,level+1,max);
	getDepthOfDeppestOddLevelLeafnodeUtil(root->right,level+1,max);
}

int getDepthOfDeppestOddLevelLeafnodeBinaryTreeOptimized(struct BinaryTreeNode* root){

	int max=0;

	getDepthOfDeppestOddLevelLeafnodeUtil(root,1,&max);

	return max;
}

void getDiffOfSumOfoddlevelAndEvenlevelUtil(struct BinaryTreeNode* root,int level,int* sumOdd,int* sumEven){

	if(!root) return;
	if(level%2){
		(*sumOdd)+=root->data;
	}else{
		(*sumEven)+=root->data;
	}
	getDiffOfSumOfoddlevelAndEvenlevelUtil(root->left,level+1,sumOdd,sumEven);
	getDiffOfSumOfoddlevelAndEvenlevelUtil(root->right,level+1,sumOdd,sumEven);
}
int getDiffOfSumOfoddlevelAndEvenlevelBinaryTree(struct BinaryTreeNode* root){

	int sumOdd=0,sumEven=0;
	getDiffOfSumOfoddlevelAndEvenlevelUtil(root,1,&sumOdd,&sumEven);
	return sumOdd-sumEven;
}

int getDiffOfSumOfoddlevelAndEvenlevelBinaryTreeSpaceOptimized(struct BinaryTreeNode* root){

	if(!root) return 0;
	return root->data-getDiffOfSumOfoddlevelAndEvenlevelBinaryTreeSpaceOptimized(root->left)-
			getDiffOfSumOfoddlevelAndEvenlevelBinaryTreeSpaceOptimized(root->right);
}

void reverseAlternateLevelNodesBinaryTree(struct BinaryTreeNode* root){


	struct LinkListWithBtreeNode* front=NULL;
	struct LinkListWithBtreeNode* rear=NULL;
	struct LinkListWithBtreeNode* stack=NULL;

	struct BinaryTreeNode* tmp=NULL;

	int count,level=0;

	addToQueue(root,&front,&rear);

	while(front){

		count=sizeOfQueue(front,rear);
		level++;
		while(count){

			tmp=deleteFromQueue(&front,&rear);
			if(level%2==0){

				tmp->data=deleteFromStack(&stack)->data;
			}
			addToQueue(tmp->left,&front,&rear);
			addToQueue(tmp->right,&front,&rear);

			if(level%2){
				addToStack(&stack,getBinaryTreeNode(tmp->left->data));
				addToStack(&stack,getBinaryTreeNode(tmp->right->data));
			}

			count--;
		}
	}

}
void reverseAlternateLevelNodesUtil(struct BinaryTreeNode* root1,struct BinaryTreeNode* root2,int level){

	int tmp;
	if(!root1||!root2) return;
	if(level%2){
		tmp=root1->data;
		root1->data=root2->data;
		root2->data=tmp;
	}

	reverseAlternateLevelNodesUtil(root1->left,root2->right,level+1);
	reverseAlternateLevelNodesUtil(root1->right,root2->left,level+1);
}
void reverseAlternateLevelNodesBinaryTreeOptimized(struct BinaryTreeNode* root){

	if(!root) return;
	reverseAlternateLevelNodesUtil(root->left,root->right,1);
}


void getNodesAtKDistanceFromGivenNodeBinaryTree(struct BinaryTreeNode* topRoot,struct BinaryTreeNode* root,struct BinaryTreeNode* node,int k){

	if(!root) return;

	if(getDistBtwTwoNodesBinaryTree(topRoot,node->data,root->data)==k){
		printf("%d ",root->data);
	}

	getNodesAtKDistanceFromGivenNodeBinaryTree(topRoot,root->left,node,k);
	getNodesAtKDistanceFromGivenNodeBinaryTree(topRoot,root->right,node,k);
}

void getNodesAtKLevelHigherThanLeafNodesUtil(struct BinaryTreeNode* root,int k,int *path,int size,int *visited){

	if(!root) return;
	path[(size)++]=root->data;
	getNodesAtKLevelHigherThanLeafNodesUtil(root->left,k,path,size,visited);
	getNodesAtKLevelHigherThanLeafNodesUtil(root->right,k,path,size,visited);

	if(isLeafNodeBinaryTree(root)){
		if(k<=size-1 && !visited[path[size-1-k]]){

			printf("%d ",path[size-1-k]);
			visited[path[size-1-k]]=1;

		}
	}

}
void getNodesAtKLevelHigherThanLeafNodesBinaryTree(struct BinaryTreeNode* root,int k){

	int height=getheightOfBinaryTree(root);
	int* path=(int *)malloc(sizeof(int)*(height));
	int size=0;
	int visited[100]={0};
	getNodesAtKLevelHigherThanLeafNodesUtil(root,k,path,size,visited);
}
void closestLeafFromGivenNodeUtil(struct BinaryTreeNode* topRoot,struct BinaryTreeNode* root,int key ,int* minDist,int **cleaf){

	int dist;
	if(!root)return;
	if(isLeafNodeBinaryTree(root)){
		dist=getDistBtwTwoNodesBinaryTree(topRoot,root->data,key);
		if(dist<*minDist){
			*minDist=dist;
			*cleaf=root;
		}
	}
	closestLeafFromGivenNodeUtil(topRoot,root->left,key,minDist,cleaf);
	closestLeafFromGivenNodeUtil(topRoot,root->right,key,minDist,cleaf);
}
struct BinaryTreeNode* closestLeafFromGivenNodeBinaryTree(struct BinaryTreeNode* root,int key){


	int closestDist=INT_MAX;
	struct BinaryTreeNode *closestleaf=NULL;
	closestLeafFromGivenNodeUtil(root,root,key,&closestDist,&closestleaf);
	return closestleaf;
}
struct BinaryTreeNode* deleteNodesLiesOnRootToLeafPathOfLengthlessThanKUtil(struct BinaryTreeNode* root,int k,int level){
	if(!root) return NULL;
	root->left=deleteNodesLiesOnRootToLeafPathOfLengthlessThanKUtil(root->left,k,level+1);
	root->right=deleteNodesLiesOnRootToLeafPathOfLengthlessThanKUtil(root->right,k,level+1);

	if(isLeafNodeBinaryTree(root) && level<k){

		free(root);
		return NULL;

	}
	return root;
}
struct BinaryTreeNode* deleteNodesLiesOnRootToLeafPathOfLengthlessThanKBinaryTree(struct BinaryTreeNode* root,int k){


	return deleteNodesLiesOnRootToLeafPathOfLengthlessThanKUtil(root,k,1);

}
int getMinHeightOfBinaryTree(struct BinaryTreeNode* root){

	if(!root) return 0;
	return 1+minOfTwo(getMinHeightOfBinaryTree(root->left),getMinHeightOfBinaryTree(root->right));
}
int isRedBlackLikeBalancedBinaryTree(struct BinaryTreeNode* root){

	if(!root) return 1;

	return getheightOfBinaryTree(root)<= 2* getMinHeightOfBinaryTree(root) && isRedBlackLikeBalancedBinaryTree(root->left) &&
			isRedBlackLikeBalancedBinaryTree(root->right);
}
struct BinaryTreeNode* deleteNodesLiesOnRootToLeafPathOfSumlessThanKUtil(struct BinaryTreeNode* root,int k,int sum) {

	if (!root) return NULL;

	root->left=deleteNodesLiesOnRootToLeafPathOfSumlessThanKUtil(root->left,k,sum + root->data);
	root->right=deleteNodesLiesOnRootToLeafPathOfSumlessThanKUtil(root->right,k,sum + root->data);

	if(isLeafNodeBinaryTree(root) && sum+root->data<k){
		free(root);
		return NULL;
	}
	return root;

}
struct BinaryTreeNode* deleteNodesLiesOnRootToLeafPathOfSumlessThanKBinaryTree(struct BinaryTreeNode* root,int k){

	return deleteNodesLiesOnRootToLeafPathOfSumlessThanKUtil(root,k,0);

}

struct BinaryTreeNode* extractLeavesToDLLFromBinarytree(struct BinaryTreeNode* root,struct BinaryTreeNode** head,struct BinaryTreeNode** prev){

	if (!root)
		return NULL;
	if (isLeafNodeBinaryTree(root)) {

		if (*prev == NULL) {

			*head = root;
		} else {

			(*prev)->right = root;
			root->left = (*prev);

		}
		*prev = root;
		return NULL;
	}
	root->left=extractLeavesToDLLFromBinarytree(root->left,head,prev);
	root->right=extractLeavesToDLLFromBinarytree(root->right,head,prev);


	return root;

}
void deepestLeftLeafNodeUtil(struct BinaryTreeNode* root,struct BinaryTreeNode** reqleaf,int * maxDepth,int level){

	if(!root) return ;
	if(isLeafNodeBinaryTree(root->left)){

		if(level+1>*maxDepth){
			*maxDepth=level+1;
			*reqleaf=root->left;
		}
		return;
	}

	deepestLeftLeafNodeUtil(root->left,reqleaf,maxDepth,level+1);
	deepestLeftLeafNodeUtil(root->right,reqleaf,maxDepth,level+1);

}
struct BinaryTreeNode* deepestLeftLeafNodeBinaryTree(struct BinaryTreeNode* root){

	struct BinaryTreeNode* reqleaf=NULL;
	int maxDepth=0;
	deepestLeftLeafNodeUtil(root,&reqleaf,&maxDepth,1);
	return reqleaf;
}

int getNextRightNodeOfGivenKeyBinaryTree(struct BinaryTreeNode* root,int key){

	struct LinkListWithBtreeNode* front=NULL;
	struct LinkListWithBtreeNode* rear=NULL;

	struct BinaryTreeNode* tmp=NULL;
	int count;

	addToQueue(root,&front,&rear);

	while(front){
		count=sizeOfQueue(front,rear);

		while(count>0){

			tmp=deleteFromQueue(&front,&rear);
			if(tmp->data==key){
				tmp=deleteFromQueue(&front,&rear);
				if(tmp)
					return tmp->data;
				else{
					return -1;
				}
			}
			addToQueue(tmp->left,&front,&rear);
			addToQueue(tmp->right,&front,&rear);
			count--;
		}
	}
}

int  sumOfAllNumbersFormFromRootToLeafPathUtil(struct BinaryTreeNode* root, int val){

	if(!root ) return 0;

	val=val*10+root->data;

	if(isLeafNodeBinaryTree(root)) return val;

	return sumOfAllNumbersFormFromRootToLeafPathUtil(root->left,val)+ sumOfAllNumbersFormFromRootToLeafPathUtil(root->right,val);


}
int sumOfAllNumbersFormFromRootToLeafPathBinaryTree(struct BinaryTreeNode* root){

	return sumOfAllNumbersFormFromRootToLeafPathUtil(root,0);
}

int getMaxSumRootToLeafPathUtil(struct BinaryTreeNode* root,int val){

	if(!root) return 0;
	val=val+root->data;
	if(isLeafNodeBinaryTree(root)) return val;

	int left=getMaxSumRootToLeafPathUtil(root->left,val);
	int right=getMaxSumRootToLeafPathUtil(root->right,val);
	if(left>right){

		return left;
	}else{

		return right;
	}

}
int getMaxSumRootToLeafPathInBinaryTree(struct BinaryTreeNode * root){

	return getMaxSumRootToLeafPathUtil(root,0);
}
void  printMaxSumRootToLeafPathUtil(struct BinaryTreeNode* root,int* path,int size,int val,int maxsum){


	if(!root) return;
	val=val+root->data;
	path[size++]=root->data;
	printMaxSumRootToLeafPathUtil(root->left,path,size,val,maxsum);
	printMaxSumRootToLeafPathUtil(root->right,path,size,val,maxsum);

	if(isLeafNodeBinaryTree(root) && val==maxsum){
		for(int i=0;i<size;i++){
			printf("%d ",path[i]);
		}
	}
}
void printMaxSumRootToLeafPathInBinaryTree(struct BinaryTreeNode* root){


	int height=getheightOfBinaryTree(root);
	int* path=(int *)malloc(sizeof(int)*height);
	int size=0;

	int maxSum=getMaxSumRootToLeafPathUtil(root,0);

	printMaxSumRootToLeafPathUtil(root,path,size,0,maxSum);
}

void printAllRootToLeafPathUtil(struct BinaryTreeNode* root,int* path,int size){

	if(!root) return;
	path[size++]=root->data;
	printAllRootToLeafPathUtil(root->left,path,size);
	printAllRootToLeafPathUtil(root->right,path,size);

	if(isLeafNodeBinaryTree(root)){
		for(int i=0;i<size;i++)
			printf(" %d",path[i]);
		printf("\n");
	}

}
void printAllRootToLeafPathBinaryTree(struct BinaryTreeNode* root){


	int height=getheightOfBinaryTree(root);
	int* path=(int *)malloc(sizeof(int)*height);
	int size=0;


	printAllRootToLeafPathUtil(root,path,size);

}
int main(void) {

	struct BinaryTreeNode *root=NULL;

/*
                  2
                /   \
               1     3
              / \   / \
             8   6 9   7
             \        /
              5      4
               \	  \
               10      11
               	   	   /
               	   	 12
 */
	root=getBinaryTreeNode(2);

	root->left=getBinaryTreeNode(1);
	root->left->left=getBinaryTreeNode(8);
	root->left->right=getBinaryTreeNode(6);
	root->left->left->right=getBinaryTreeNode(5);
	root->left->left->right->right=getBinaryTreeNode(10);

	root->right=getBinaryTreeNode(3);
	root->right->left=getBinaryTreeNode(9);
	root->right->right=getBinaryTreeNode(7);
	root->right->right->left=getBinaryTreeNode(4);
	root->right->right->left->right=getBinaryTreeNode(11);
	root->right->right->left->right->left=getBinaryTreeNode(12);
/*                    1
 *                   / \
 *                  8   6
 *                   \
 *                    5
 *
 */
	struct BinaryTreeNode *subTreeroot=NULL;

	subTreeroot=getBinaryTreeNode(1);

	subTreeroot->left=getBinaryTreeNode(8);
	subTreeroot->left->right=getBinaryTreeNode(5);
	//subTreeroot->left->right->right=getBinaryTreeNode(10);
	subTreeroot->right=getBinaryTreeNode(6);
/*

	printf("height=%d\n",getheightOfBinaryTreeOptimized(root));
	printf("height=%d\n",getheightOfBinaryTree(root));
*/

/*
	 traverseLevelorderBinaryTree(root);
	 printf("\n");
	 printf("number of nodes=%d",getSizeOfBinaryTree(root));
*/

/*
    traversePreorderBinaryTree(root);
    printf("\n");
    traversePostorderBinaryTree(root);
    printf("\n");
    traverseInorderBinaryTree(root);
    printf("\n");
*/

/*
	traverseTheLevelOfBinaryTree(root,3);
	printf("\n");
    traverseLevelorderBinaryTree(root);
*/

/*
    traverseLevelOrderbyQueueOfBinaryTree(root);
*/

/*
	printf("diameter=%d\n",diameterOfBinaryTreeRecursive(root));
*/

/*
	int height=0;
	printf("diameter=%d\n",diameterOfBinaryTreeRecursiveOptimized(root,&height));
*/

/*
	inorderTraversalWithoutRecursionOfBinaryTree(root);
*/

/*
	inorderTraversalWithoutRecursionAndStackOfBinaryTree(root);
*/

/*
	traverseLevelorderBinaryTree(root);
	printf("maxWidth of binary Tree=%d",getMaxWidthOfbinaryTree(root));

	printf("\nmaxWidth of binary Tree=%d",getMaxWidthOfbinaryTreeOptimized(root));
*/

/*
	printNodesAtKthdistanceInBinaryTreeRecursive(root,2);
*/

/*
	printAncestorOfNode(root,2);
*/

/*	int in[]={4,2,5,1,6,3};
	int *pre=(int *)malloc(5*sizeof(int));
	pre[0]=1;pre[1]=2;pre[2]=4;pre[3]=5;pre[4]=3;pre[5]=6;

	struct BinaryTreeNode* r=buildBinaryTreefromInorderAndPreorderTraversals(in,&pre,0,5);
	traverseLevelorderBinaryTree(r);
*/

/*	int in[]={4,2,5,1,6,3};
	int *post=(int *)malloc(5*sizeof(int));
	post[0]=4;post[1]=5;post[2]=2;post[3]=6;post[4]=3;post[5]=1;

	int *lastPost=post+5;
	struct BinaryTreeNode* r=buildBinaryTreefromInorderAndPostorderTraversals(in,&lastPost,0,5);
	traverseLevelorderBinaryTree(r);
*/

/*
	traverseLevelorderBinaryTree(root);
	printf("\n");
	traverseLevelorderBinaryTree(subTreeroot);
	printf("\n");
	printf("is equal=%s",isEqualBinaryTreeRecursive(subTreeroot,root)?"YES":"NO");

*/

/*
	traverseLevelorderBinaryTree(root);
	printf("\n");
	traverseLevelorderBinaryTree(subTreeroot);
	printf("\n");
	printf("\n");
	printf("subTreeroot is subtree of root=%s",isSubtreeOfBinaryTree(root,subTreeroot)?"YES":"NO");

*/

/*

	connectNodeAtSameLevelBinaryTree(root);
	printf("%d",root->left->left->right->nextRight->data);

*/
/*
    rightToLeftLevelOrderTraversalBinaryTree(root);
*/
/*
	bottomToToplevelOrderTraversalRecursiveBinaryTree(root);
*/
/*
	bottomToToplevelOrderTraversalOptimizedBinaryTree(root);
*/

/*
	int in[]={4,2,5,1,3,6};
	int pre[]={1,2,4,5,3,6};
	int n=6;
	getPostOrderTraversalFromInorderAndPreOrderBinaryTree(in,pre,n);
*/


/*
	int in[]={4,2,5,1,3,6};
	int post[]={4,5,2,6,3,1};
	int n=6;

	getPreOrderTraversalFromInOrderAndPostOrderBinaryTree(in,post+n-1,n);
*/

/*
	lineByLineLevelOrderTraversalByQueueBinaryTree(root);
*/
/*
 	lineByLineLevelOrderTraversalByTwoQueueBinaryTree(root);

*/
/*
	diagonalTraversalByQueueBinaryTree(root);
	printf("\n");
    diagonalTraversalByQueue2BinaryTree(root);
*/

/*

	struct BinaryTreeNode *root1=getBinaryTreeNode(1);

    root1->left = getBinaryTreeNode(2);
    root1->right = getBinaryTreeNode(3);
    root1->left->left = getBinaryTreeNode(4);
    root1->right->left = getBinaryTreeNode(6);
    root1->right->right = getBinaryTreeNode(7);

    struct BinaryTreeNode *root2=getBinaryTreeNode(0);
    root2->left=getBinaryTreeNode(1);
    root2->left->right=getBinaryTreeNode(4);
    root2->right=getBinaryTreeNode(5);
    root2->right->left=getBinaryTreeNode(6);
    root2->right->right=getBinaryTreeNode(7);

	printf("is having same leaves = %d\n",areHavingSameLeavesBinaryTree(root1,root2));
*/
/*

	struct BinaryTreeNode *root1=getBinaryTreeNode(1);

    root1->left = getBinaryTreeNode(2);
    root1->right = getBinaryTreeNode(3);
    root1->left->left = getBinaryTreeNode(4);
    root1->right->left = getBinaryTreeNode(6);
    root1->right->right = getBinaryTreeNode(7);

    struct BinaryTreeNode *root2=getBinaryTreeNode(0);
    root2->left=getBinaryTreeNode(1);
    root2->left->right=getBinaryTreeNode(4);
    root2->right=getBinaryTreeNode(5);
    root2->right->left=getBinaryTreeNode(6);
    root2->right->right=getBinaryTreeNode(7);

	printf("is having same leaves = %d\n",areHavingSameLeavesOptimizedSpaceBinaryTree(root1,root2));

*/
/*

	leavesTraversalLeftToRightRecursiveBinaryTree(root);
*/
/*
	leavesTraversalLeftToRightIterativeBinaryTree(root);
*/
/*
	verticalTraversalOptimizedSpaceBinaryTree(root);
*/

/*

	boundryTraversalAntiClockwiseBinaryTree(root);

*/

/*

    boundryTraversalAntiClockwiseOptimizedBinaryTree(root);

*/
/*
	 root = getBinaryTreeNode(1);

	printAllRootToLeafPathBinaryTree(root);


	 root->left        = getBinaryTreeNode(2);
	 root->right       = getBinaryTreeNode(3);

	 root->left->left  = getBinaryTreeNode(4);
	 root->left->right = getBinaryTreeNode(5);
	 root->right->left  = getBinaryTreeNode(6);
	 root->right->right = getBinaryTreeNode(7);

	 root->left->left->left  = getBinaryTreeNode(8);
	 root->left->left->right  = getBinaryTreeNode(9);
	 root->left->right->left  = getBinaryTreeNode(10);
	 root->left->right->right  = getBinaryTreeNode(11);
	 root->right->left->left  = getBinaryTreeNode(12);
	 root->right->left->right  = getBinaryTreeNode(13);
	 root->right->right->left  = getBinaryTreeNode(14);
	 root->right->right->right  = getBinaryTreeNode(15);

	 root->left->left->left->left  = getBinaryTreeNode(16);
	 root->left->left->left->right  = getBinaryTreeNode(17);
	 root->left->left->right->left  = getBinaryTreeNode(18);
	 root->left->left->right->right  = getBinaryTreeNode(19);
	 root->left->right->left->left  = getBinaryTreeNode(20);
	 root->left->right->left->right  = getBinaryTreeNode(21);
	 root->left->right->right->left  = getBinaryTreeNode(22);
	 root->left->right->right->right  = getBinaryTreeNode(23);
	 root->right->left->left->left  = getBinaryTreeNode(24);
	 root->right->left->left->right  = getBinaryTreeNode(25);
	 root->right->left->right->left  = getBinaryTreeNode(26);
	 root->right->left->right->right  = getBinaryTreeNode(27);
	 root->right->right->left->left  = getBinaryTreeNode(28);
	 root->right->right->left->right  = getBinaryTreeNode(29);
	 root->right->right->right->left  = getBinaryTreeNode(30);
	 root->right->right->right->right  = getBinaryTreeNode(31);

	 lineByLineLevelOrderTraversalByQueueBinaryTree(root);
	 printf("\n");
	 specificLevelOrderTraversalPerfectBinarytree(root);
	 printf("\n");
	 specificLevelOrderTraversalOptimizedPerfectBinarytree(root);
	 printf("\n");
	 specificLevelOrderTraversalBottomToTopPerfectBinarytree(root);
*/

/*
	traversePreorderBinaryTree(root);
	printf("\n");
	preOrderTraversalIterativeByStackBinaryTree(root);
	printf("\n");
	preOrderTraversalIterativeByStackMethod2BinaryTree(root);
	printf("\n");
	preOrderTraversalIterativeWithoutStackBinarytree(root);
*/

/*
	root=getBinaryTreeNode(1);;

	root->left=getBinaryTreeNode(2);
	root->left->left=getBinaryTreeNode(4);
	root->left->right=getBinaryTreeNode(5);


	root->right=getBinaryTreeNode(3);
	root->right->left=getBinaryTreeNode(6);
	root->right->right=getBinaryTreeNode(7);



	traversePostorderBinaryTree(root);
	printf("\n");
	postOrderTraversalIterativeByOneStack(root);
	printf("\n");
	postOrderTraversalIterativeByTwoStack(root
	printAllRootToLeafPathBinaryTree(root);

	);
*/

/*
	root=getBinaryTreeNode(1);;

	root->left=getBinaryTreeNode(2);
	root->left->left=getBinaryTreeNode(4);
	root->left->right=getBinaryTreeNode(5);


	root->right=getBinaryTreeNode(3);
	root->right->left=getBinaryTreeNode(6);
	root->right->right=getBinaryTreeNode(7);

	int key1=50,key2=4;
	struct BinaryTreeNode *lca=lcaBinaryTree(root,key1,key2);
	printf("lca =%d \n",lca?lca->data:-1);

	printf("lca =%d \n",lcaNonSpaceOptimizedBinaryTree(root,key1,key2));

	printAllRootToLeafPathBinaryTree(root);


	printf("lca=%d",lcaOptimizedBinaryTree(root,key1,key2)->data);
*/

/*
	root=getBinaryTreeNode(1);;

	root->left=getBinaryTreeNode(2);
	root->left->left=getBinaryTreeNode(4);
	root->left->right=getBinaryTreeNode(5);


	root->right=getBinaryTreeNode(3);
	root->right->left=getBinaryTreeNode(6);
	root->right->right=getBinaryTreeNode(7);

	int key1=4,key2=3;
	printf("dist btw nodes=%d ",getDistBtwTwoNodesBinaryTree(root,key1,key2));
*/
/*
	root=getBinaryTreeNode(1);;

	root->left=getBinaryTreeNode(2);
	root->left->left=getBinaryTreeNode(4);
	root->left->right=getBinaryTreeNode(5);


	root->right=getBinaryTreeNode(3);
	root->right->left=getBinaryTreeNode(6);
	root->right->right=getBinaryTreeNode(7);


	int key1=6,key2=7;
	getCommonAncestorsOfTwoNodes(root,key1,key2);
*/
/*
	int inorder[]={4, 8, 10, 12, 14, 20, 22};
	int levelorder[]= {20, 8, 22, 4, 12, 10, 14};
	int size=7;
	struct BinaryTreeNode *root1=buildBinaryTreeFromInOrderAndLevelOrderTraversalOptimized(inorder,0,size-1,levelorder,size);
	traverseInorderBinaryTree(root1);
*/
/*
	int parent[]={1, 5, 5, 2, 2, -1, 3};
	int n=7;

	struct BinaryTreeNode* root1=buildBinaryTreeFromParentArrayRepresentation(parent,n-1,-1);
    lineByLineLevelOrderTraversalByQueueBinaryTree(root1);
*/
/*
	int parent[]={1, 5, 5, 2, 2, -1, 3};
	int n=7;

	struct BinaryTreeNode* root2=buildBinaryTreeFromParentArrayRepresentationOptimized(parent,n);
	lineByLineLevelOrderTraversalByQueueBinaryTree(root2);
*/
/*
 	traverseInorderBinaryTree(root);
	printf("\n");
	struct BinaryTreeNode *head1=buildDLLWithLeftAndRightPointersFromBinaryTree(root);
	while(head1){
		printf("%d ",head1->data);
		head1=head1->right;
	}
*/
/*
 	traverseInorderBinaryTree(root);
	printf("\n");
	struct BinaryTreeNode* head2=NULL;
	int count=0;
	buildDLLWithLeftAndRightPointersByInorderFromBinaryTree(root,&head2,&count);
	while(head2){
		printf("%d ",head2->data);
		head2=head2->right;
	}
*/
/*
	traverseInorderBinaryTree(root);
	printf("\n");
	struct BinaryTreeNode* head3 = NULL;
	buildDLLWithLeftAndRightPointersByReverseInorderFromBinaryTree(root, &head3);
	while (head3) {
		printf("%d ", head3->data);
		head3 = head3->right;
	}
*/
/*
	traverseInorderBinaryTree(root);	traverseInorderBinaryTree(root);
    printf("\n");
	struct BinaryTreeNode* head=NULL;
	struct BinaryTreeNode *prev=NULL;
	buildDLLWithLeftAndRightPointersbyInorderOptimizedFromBinaryTree(root,&head,&prev);
	while (head) {
		printf("%d ", head->data);
		head = head->right;
	}

    printf("\n");
	struct BinaryTreeNode* head=NULL;
	struct BinaryTreeNode *prev=NULL;
	buildDLLWithLeftAndRightPointersbyInorderOptimizedFromBinaryTree(root,&head,&prev);
	while (head) {
		printf("%d ", head->data);
		head = head->right;
	}
*/
/*
	struct BinaryTreeNode *rt = getBinaryTreeNode(1);
	rt->left = getBinaryTreeNode(2);
	rt->left->right = getBinaryTreeNode(9);
	rt->right = getBinaryTreeNode(3);
	rt->right->left = getBinaryTreeNode(4);
	rt->right->right = getBinaryTreeNode(5);
	rt->right->left->left = getBinaryTreeNode(6);
	rt->right->right->left = getBinaryTreeNode(7);
	rt->right->right->right = getBinaryTreeNode(8);

	convertToChildSiblingRepFromBinaryTree(root);
	traverseChildSiblingRepresentation(root);
*/
/*
	struct BinaryTreeNode *rt = getBinaryTreeNode(1);
	rt->left = getBinaryTreeNode(2);
	rt->left->right = getBinaryTreeNode(9);
	rt->right = getBinaryTreeNode(3);
	rt->right->left = getBinaryTreeNode(4);
	rt->right->right = getBinaryTreeNode(5);
	rt->right->left->left = getBinaryTreeNode(6);
	rt->right->right->left = getBinaryTreeNode(7);
	rt->right->right->right = getBinaryTreeNode(8);
	convertToChildSiblingRepOptimizedFronBinaryTree(root);
	traverseChildSiblingRepresentation(root);
*/
/*
	struct BinaryTreeNode *rt = getBinaryTreeNode(10);
	rt->left = getBinaryTreeNode(-2);
	rt->left->right = getBinaryTreeNode(8);
	rt->left->left=getBinaryTreeNode(8);
	rt->left->right=getBinaryTreeNode(-4);
	rt->right = getBinaryTreeNode(6);
	rt->right->left = getBinaryTreeNode(7);
	rt->right->right = getBinaryTreeNode(5);

	convertToSumFromBinarytree(rt);    //https://www.geeksforgeeks.org/convert-a-given-tree-to-sum-tree/
	traverseLevelOrderbyQueueOfBinaryTree(rt);
*/
/*
	struct BinaryTreeNode *rt = getBinaryTreeNode(1);
	rt->left = getBinaryTreeNode(2);
	rt->left->right = getBinaryTreeNode(5);
	rt->left->left=getBinaryTreeNode(4);
	rt->left->right->right=getBinaryTreeNode(7);
	rt->right = getBinaryTreeNode(3);
	rt->right->right = getBinaryTreeNode(6);

	lineByLineLevelOrderTraversalByQueueBinaryTree(rt);
	printf("\n");
	convertToLeftTreeSumFromBinaryTree(rt); //https://www.geeksforgeeks.org/change-a-binary-tree-so-that-every-node-stores-sum-of-all-nodes-in-left-subtree/
	lineByLineLevelOrderTraversalByQueueBinaryTree(rt);
*/
/*
	struct BinaryTreeNode *rt = getBinaryTreeNode(1);
	rt->left = getBinaryTreeNode(3);
	rt->left->left = getBinaryTreeNode(6);

	rt->right = getBinaryTreeNode(2);
	rt->right->right = getBinaryTreeNode(4);
	rt->right->left=getBinaryTreeNode(5);

	lineByLineLevelOrderTraversalByQueueBinaryTree(rt);
	convertToMirrorViewFromBinaryTree(rt);
	lineByLineLevelOrderTraversalByQueueBinaryTree(rt);
*/
/*
	struct BinaryTreeNode *rt = getBinaryTreeNode(1);
	rt->left = getBinaryTreeNode(3);
	rt->left->left = getBinaryTreeNode(6);

	rt->right = getBinaryTreeNode(2);
	rt->right->right = getBinaryTreeNode(4);
	rt->right->left=getBinaryTreeNode(5);

	lineByLineLevelOrderTraversalByQueueBinaryTree(rt);
	convertToMirrorViewMethod2FromBinaryTree(rt);
	lineByLineLevelOrderTraversalByQueueBinaryTree(rt);
*/
/*
	struct BinaryTreeNode *rt = getBinaryTreeNode(1);
	rt->left = getBinaryTreeNode(3);
	rt->left->left = getBinaryTreeNode(6);

	rt->right = getBinaryTreeNode(2);
	rt->right->right = getBinaryTreeNode(4);
	rt->right->left=getBinaryTreeNode(5);

	lineByLineLevelOrderTraversalByQueueBinaryTree(rt);
	printf("\n");
	convertToMirrorViewIterativeFromBinaryTree(rt);
	lineByLineLevelOrderTraversalByQueueBinaryTree(rt);
*/
/*
	struct BinaryTreeNode *rt = getBinaryTreeNode(4);
	rt->left = getBinaryTreeNode(3);
	rt->left->left = getBinaryTreeNode(2);
	rt->left->left->left=getBinaryTreeNode(1);

	lineByLineLevelOrderTraversalByQueueBinaryTree(rt);
	 rt=convertBSTToBalanceBST(rt);
	 printf("\n");
	lineByLineLevelOrderTraversalByQueueBinaryTree(rt);
*/
/*
	struct BinaryTreeNode *rt = getBinaryTreeNode(10);
	rt->left = getBinaryTreeNode(12);
	rt->left->left = getBinaryTreeNode(25);
	rt->left->right = getBinaryTreeNode(30);

	rt->right = getBinaryTreeNode(15);
	rt->right->left=getBinaryTreeNode(36);

	//lineByLineLevelOrderTraversalByQueueBinaryTree(rt);
	printf("\n");
	struct BinaryTreeNode* head=convertToCircularDLLFrombinarytree(rt);


	struct BinaryTreeNode* ptr=head;
	printf("%u %u\n",ptr,head);

	while(1){

		printf("%d ",ptr->data);
		ptr=ptr->right;
		if(ptr==head){
			break;
		}
	}
*/
/*
	struct BinaryTreeNode *rt = getBinaryTreeNode(1);
	rt->left = getBinaryTreeNode(1);
	rt->left->left = getBinaryTreeNode(0);
	rt->left->right = getBinaryTreeNode(1);

	rt->right = getBinaryTreeNode(0);
	rt->right->left = getBinaryTreeNode(1);
	rt->right->right = getBinaryTreeNode(1);

	lineByLineLevelOrderTraversalByQueueBinaryTree(rt);
	convertToLogicalANDNodesFromBinaryTree(rt);
	lineByLineLevelOrderTraversalByQueueBinaryTree(rt);
*/
/*
	char *string="1?2?3:4:5";
	int len=9;
	struct BinaryTreeNode* rt=convertTerniaryoperationTobinarytree(string,9);
	lineByLineLevelOrderTraversalByQueueBinaryTree(rt);
*/
/*
	struct BinaryTreeNode *rt = getBinaryTreeNode(10);
	rt->left = getBinaryTreeNode(12);
	rt->left->left = getBinaryTreeNode(25);
	rt->left->right = getBinaryTreeNode(30);

	rt->right = getBinaryTreeNode(15);
	rt->right->left = getBinaryTreeNode(36);

	traverseInorderBinaryTree(rt);
	rt=deleteBinarytree(rt);
	printf("\n");
	traverseInorderBinaryTree(rt);
*/
/*
	struct BinaryTreeNode *rt = getBinaryTreeNode(0);
	rt->left = getBinaryTreeNode(0);
	rt->left->left = getBinaryTreeNode(1);
	rt->left->right = getBinaryTreeNode(0);

	rt->right = getBinaryTreeNode(0);
	rt->right->left = getBinaryTreeNode(0);


	int value=0;
	printf("is exist=%d",isRootToLeafPathSumEqualToGivenValueBinarytree(rt,value));

*/

/*
	struct BinaryTreeNode *rt = getBinaryTreeNode(1);
	rt->left = getBinaryTreeNode(2);

	rt->left->right = getBinaryTreeNode(4);

	rt->right = getBinaryTreeNode(3);


	printf("is balanced=%d \n",isBalanceBinaryTree(rt));

	int height=0;
	printf("is balanced=%d \n",isBalanceBinaryTreeOptimized(rt,&height));
*/
/*
	struct BinaryTreeNode *rt = getBinaryTreeNode(10);
	rt->left = getBinaryTreeNode(8);
	rt->left->left=getBinaryTreeNode(3);
	rt->left->right = getBinaryTreeNode(5);

	rt->right = getBinaryTreeNode(2);
	rt->right->left = getBinaryTreeNode(2);

	lineByLineLevelOrderTraversalByQueueBinaryTree(rt);

	printf("is children sum property satisfied=%d ",isChildrenSumPropertySatisfiedInBinaryTree(rt));
*/
/*
	struct BinaryTreeNode *rt = getBinaryTreeNode(1);
	rt->left = getBinaryTreeNode(2);
	rt->left->left=getBinaryTreeNode(4);
	rt->left->right = getBinaryTreeNode(5);

	rt->right = getBinaryTreeNode(3);
	rt->right->right = getBinaryTreeNode(6);
	printf("is complet btree = %d",isCompleteBinaryTreeIterative(rt));
*/
/*
	struct BinaryTreeNode *rt = getBinaryTreeNode(1);
	rt->left = getBinaryTreeNode(2);
	rt->left->right = getBinaryTreeNode(4);

	rt->right = getBinaryTreeNode(3);

	printf("min depth=%d ",getMinDepthOfBinaryTree(rt));
	printf("min depth=%d ",getMinDepthOfBinaryTreeOptimized(root));
*/

/*
	int max=0;
	getMaxInBinaryTree(root,&max);
	printf("max=%d\n",max);

	printf("max=%d",getMaxInBinaryTreeOptimized(root));
*/
/*
	int sum=0;
	getLeftLeavesSumBinaryTree(root,&sum);
	printf("left leaves sum=%d\n",sum);

	printf("left leaves sum=%d",getLeftLeavesSumOfBinaryTreeOptimized(root));
*/

/*
	printf("are cousins=%d",areCousinsInBinarytree(root,6,2));
	printf("are cousins= %d",areCousinsInBinarytreeOptimized(root,6,2));
*/
/*

	int parent[]={-1, 0, 0, 1, 1, 3, 5};
	int size=7;
	printf("height of btree=%d",getHeightFromParentArrayRepOfBinaryTree(parent,size));
*/
/*
	struct BinaryTreeNode *rt = getBinaryTreeNode(1);
	rt->left = getBinaryTreeNode(2);
	rt->right = getBinaryTreeNode(3);
	rt->left->right = getBinaryTreeNode(4);
	rt->left->right->right = getBinaryTreeNode(5);
	rt->left->right->right->right = getBinaryTreeNode(6);

	topViewTraversalOfBinaryTree(root);
*/
/*

	diagonalSumTraversalOfBinaryTree(root);

*/
/*
	struct BinaryTreeNode *tree = getBinaryTreeNode(1);
	tree->left = getBinaryTreeNode(2);
	tree->right = getBinaryTreeNode(4);
	tree->right->right = getBinaryTreeNode(5);
	tree->left->left = getBinaryTreeNode(3);

	struct BinaryTreeNode *subtree = getBinaryTreeNode(1);
	subtree->left = getBinaryTreeNode(2);
	subtree->right = getBinaryTreeNode(4);
	subtree->left->left = getBinaryTreeNode(3);


	printf("\nis subtree= %d\n",isSubtreeOfBinaryTreeOptimized(subTreeroot,root));
	printf("\nis subtree= %d",isSubtreeOfBinaryTree(root,subTreeroot));
*/
/*
	struct BinaryTreeNode *tree = getBinaryTreeNode(1);
	tree->left = getBinaryTreeNode(2);
	tree->left->left = getBinaryTreeNode(4);
	tree->left->right = getBinaryTreeNode(5);
	tree->left->right->left = getBinaryTreeNode(7);
	tree->left->right->right = getBinaryTreeNode(8);

	tree->right = getBinaryTreeNode(3);
	tree->right->left = getBinaryTreeNode(6);

	struct BinaryTreeNode *anotherTree = getBinaryTreeNode(1);
	anotherTree->left = getBinaryTreeNode(3);
	anotherTree->left->right = getBinaryTreeNode(6);

	anotherTree->right = getBinaryTreeNode(2);
	anotherTree->right->left = getBinaryTreeNode(4);
	anotherTree->right->right = getBinaryTreeNode(5);
	anotherTree->right->right->left = getBinaryTreeNode(8);
	anotherTree->right->right->right = getBinaryTreeNode(7);

	lineByLineLevelOrderTraversalByQueueBinaryTree(tree);
	lineByLineLevelOrderTraversalByQueueBinaryTree(anotherTree);

	printf("is isomorphic= %d ",areIsomorphicBinaryTree(tree,tree));
*/

/*
	struct BinaryTreeNode *tree = getBinaryTreeNode(1);
	tree->left = getBinaryTreeNode(2);
	tree->left->left = getBinaryTreeNode(4);
	tree->right = getBinaryTreeNode(3);
	//tree->right->left = getBinaryTreeNode(6);

	printf("are leaves at same level=%d",areLeavesAtSameLevelInBinaryTree(tree));

*/
/*
	rightViewTraversalOfBinaryTree(root);
*/
/*

	withoutSiblingNodesTraversalBinaryTree(root);

*/
/*
	struct BinaryTreeNode *tree = getBinaryTreeNode(4);
	tree->left = getBinaryTreeNode(5);
	tree->right = getBinaryTreeNode(2);
	tree->right->left = getBinaryTreeNode(3);
	tree->right->right = getBinaryTreeNode(1);
	tree->right->left->left = getBinaryTreeNode(6);
	tree->right->left->right = getBinaryTreeNode(7);
	//tree->right->left = getBinaryTreeNode(6);

	leftViewTraversalOfBinaryTree(tree);
	printf("\n");
	leftViewTraversalOfBinaryTreeSpaceOptimized(tree);
*/
/*
	lineByLineLevelOrderTraversalByQueueBinaryTree(root);
	printf("depth of deepest odd level leaf node =%d \n",getDepthOfDeppestOddLevelLeafnodeBinaryTree(root));

	printf("depth of deepest odd level leaf node =%d ",getDepthOfDeppestOddLevelLeafnodeBinaryTreeOptimized(root));
*/

/*
	printf("%d \n",getDiffOfSumOfoddlevelAndEvenlevelBinaryTree(root));
	printf("%d \n",getDiffOfSumOfoddlevelAndEvenlevelBinaryTreeSpaceOptimized(root));
*/

/*
	struct BinaryTreeNode *tree = getBinaryTreeNode(1);
	tree->left = getBinaryTreeNode(2);
	tree->left->left = getBinaryTreeNode(4);
	tree->left->right = getBinaryTreeNode(5);
	tree->left->left->left = getBinaryTreeNode(8);
	tree->left->left->right = getBinaryTreeNode(9);
	tree->left->right->left = getBinaryTreeNode(10);
	tree->left->right->right = getBinaryTreeNode(11);

	tree->right = getBinaryTreeNode(3);
	tree->right->left = getBinaryTreeNode(6);
	tree->right->right = getBinaryTreeNode(7);
	tree->right->left->left = getBinaryTreeNode(12);
	tree->right->left->right = getBinaryTreeNode(13);
	tree->right->right->left = getBinaryTreeNode(14);
	tree->right->right->right = getBinaryTreeNode(15);

	lineByLineLevelOrderTraversalByQueueBinaryTree(tree);
	reverseAlternateLevelNodesBinaryTree(tree);
	lineByLineLevelOrderTraversalByQueueBinaryTree(tree);
*/

/*
	struct BinaryTreeNode *tree = getBinaryTreeNode(1);
	tree->left = getBinaryTreeNode(2);
	tree->left->left = getBinaryTreeNode(4);
	tree->left->right = getBinaryTreeNode(5);
	tree->left->left->left = getBinaryTreeNode(8);
	tree->left->left->right = getBinaryTreeNode(9);
	tree->left->right->left = getBinaryTreeNode(10);
	tree->left->right->right = getBinaryTreeNode(11);

	tree->right = getBinaryTreeNode(3);
	tree->right->left = getBinaryTreeNode(6);
	tree->right->right = getBinaryTreeNode(7);
	tree->right->left->left = getBinaryTreeNode(12);
	tree->right->left->right = getBinaryTreeNode(13);
	tree->right->right->left = getBinaryTreeNode(14);
	tree->right->right->right = getBinaryTreeNode(15);

	lineByLineLevelOrderTraversalByQueueBinaryTree(tree);
	reverseAlternateLevelNodesBinaryTreeOptimized(tree);
	lineByLineLevelOrderTraversalByQueueBinaryTree(tree);
*/
/*
	struct BinaryTreeNode *tree = getBinaryTreeNode(20);
	tree->left = getBinaryTreeNode(8);
	tree->left->left = getBinaryTreeNode(4);
	tree->left->right = getBinaryTreeNode(12);

	tree->left->right->left = getBinaryTreeNode(10);
	tree->left->right->right = getBinaryTreeNode(14);

	tree->right = getBinaryTreeNode(22);

	struct BinaryTreeNode* node=tree->left->right->right;
	int k=3;
	lineByLineLevelOrderTraversalByQueueBinaryTree(tree);
	getNodesAtKDistanceFromGivenNodeBinaryTree(tree,tree,node,k);
*/
/*
	struct BinaryTreeNode *tree = getBinaryTreeNode(1);

	tree->left = getBinaryTreeNode(2);

	tree->left->left = getBinaryTreeNode(4);
	tree->left->right = getBinaryTreeNode(5);


	tree->right = getBinaryTreeNode(3);

	tree->right->left = getBinaryTreeNode(6);
	tree->right->right = getBinaryTreeNode(7);
	tree->right->left->right = getBinaryTreeNode(12);


	getNodesAtKLevelHigherThanLeafNodesBinaryTree(tree,1);
*/
/*
	struct BinaryTreeNode *tree = getBinaryTreeNode(1);

	tree->left = getBinaryTreeNode(2);

	tree->right = getBinaryTreeNode(3);

	tree->right->left = getBinaryTreeNode(4);
	tree->right->right = getBinaryTreeNode(5);

	tree->right->left->left = getBinaryTreeNode(6);
	tree->right->left->left->left = getBinaryTreeNode(8);
	tree->right->left->left->right = getBinaryTreeNode(9);

	tree->right->right->right = getBinaryTreeNode(7);
	tree->right->right->right->left = getBinaryTreeNode(10);

   // lineByLineLevelOrderTraversalByQueueBinaryTree(tree);
	printf("closest leaf =%d ",closestLeafFromGivenNodeBinaryTree(tree,1)->data);
*/
/*
	struct BinaryTreeNode *tree = getBinaryTreeNode(1);

	tree->left = getBinaryTreeNode(2);
	tree->left->left = getBinaryTreeNode(4);
	tree->left->right = getBinaryTreeNode(5);

	tree->right = getBinaryTreeNode(3);

	tree->right->left = getBinaryTreeNode(6);
	tree->right->left->left = getBinaryTreeNode(9);

	tree->right->right = getBinaryTreeNode(7);
	tree->right->right->right = getBinaryTreeNode(8);

	lineByLineLevelOrderTraversalByQueueBinaryTree(tree);
	tree=deleteNodesLiesOnRootToLeafPathOfLengthlessThanKBinaryTree(tree,4);
	lineByLineLevelOrderTraversalByQueueBinaryTree(tree);
*/
/*
	struct BinaryTreeNode *tree = getBinaryTreeNode(1);
    tree->left = getBinaryTreeNode(2);
	tree->right = getBinaryTreeNode(3);
	tree->right->left = getBinaryTreeNode(4);
	tree->right->right = getBinaryTreeNode(5);


	printf("is RB like balaced= %d",isRedBlackLikeBalancedBinaryTree(tree));
*/
/*
	struct BinaryTreeNode *tree = getBinaryTreeNode(1);

	tree->left = getBinaryTreeNode(2);
	tree->left->left = getBinaryTreeNode(4);
	tree->left->left->left = getBinaryTreeNode(8);
	tree->left->left->right = getBinaryTreeNode(9);
	tree->left->left->right->left = getBinaryTreeNode(13);
	tree->left->left->right->right = getBinaryTreeNode(14);
	tree->left->left->right->right->left = getBinaryTreeNode(15);
	tree->left->right = getBinaryTreeNode(5);
	tree->left->right->left = getBinaryTreeNode(12);

	tree->right = getBinaryTreeNode(3);
	tree->right->left = getBinaryTreeNode(6);
	tree->right->right = getBinaryTreeNode(7);
	tree->right->right->left = getBinaryTreeNode(10);
	tree->right->right->left->right = getBinaryTreeNode(11);

	lineByLineLevelOrderTraversalByQueueBinaryTree(tree);
	deleteNodesLiesOnRootToLeafPathOfSumlessThanKBinaryTree(tree,20);
	lineByLineLevelOrderTraversalByQueueBinaryTree(tree);
*/
/*
 	struct BinaryTreeNode *tree = getBinaryTreeNode(1);

	tree->left = getBinaryTreeNode(2);
	tree->left->left = getBinaryTreeNode(4);
	tree->left->left->left = getBinaryTreeNode(7);
	tree->left->left->right = getBinaryTreeNode(8);
	tree->left->right = getBinaryTreeNode(5);


	tree->right = getBinaryTreeNode(3);
	tree->right->right = getBinaryTreeNode(6);
	tree->right->right->left = getBinaryTreeNode(9);
	tree->right->right->right = getBinaryTreeNode(10);

	//lineByLineLevelOrderTraversalByQueueBinaryTree(tree);
	struct BinaryTreeNode* head=NULL;
	struct BinaryTreeNode*  prev=NULL;

	extractLeavesToDLLFromBinarytree(tree,&head,&prev);
	lineByLineLevelOrderTraversalByQueueBinaryTree(tree);
	while(head){
		printf("%d ",head->data);
		head=head->right;
	}
*/

/*

	printf("deepest left node=%d",deepestLeftLeafNodeBinaryTree(root)->data);

*/
/*

	printf("next node=%d",getNextRightNodeOfGivenKeyBinaryTree(root,5));

*/
/*
	struct BinaryTreeNode *tree = getBinaryTreeNode(6);

	tree->left = getBinaryTreeNode(3);
	tree->left->left = getBinaryTreeNode(2);
	tree->left->right = getBinaryTreeNode(5);
	tree->left->right->left = getBinaryTreeNode(7);
	tree->left->right->right = getBinaryTreeNode(4);

	tree->right = getBinaryTreeNode(5);
	tree->right->right = getBinaryTreeNode(4);

	lineByLineLevelOrderTraversalByQueueBinaryTree(tree);
	printf("sum=%d",sumOfAllNumbersFormFromRootToLeafPathBinaryTree(tree));
*/
/*
	struct BinaryTreeNode *tree = getBinaryTreeNode(10);

	tree->left = getBinaryTreeNode(-2);
	tree->left->left = getBinaryTreeNode(8);
	tree->left->right = getBinaryTreeNode(-4);


	tree->right = getBinaryTreeNode(7);


	printf("sum=%d\n",getMaxSumRootToLeafPathInBinaryTree(tree));
	printMaxSumRootToLeafPathInBinaryTree(tree);
*/
/*

	printAllRootToLeafPathBinaryTree(root);

*/

	return EXIT_SUCCESS;
}
