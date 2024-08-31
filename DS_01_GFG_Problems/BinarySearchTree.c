/*
 ============================================================================
 Name        : BinarySearchTree.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#include "/home/anurag/Desktop/CPROGG/DataStructure-geeksforgeeks_workspace/Algorithms/BinaryTreeFunctions.c"
#include "/home/anurag/Desktop/CPROGG/DataStructure-geeksforgeeks_workspace/Algorithms/LinkListFunctions.c"
#include "/home/anurag/Desktop/CPROGG/DataStructure-geeksforgeeks_workspace/Algorithms/StackFunctions.c"



struct BinaryTreeNode* insertInBST(struct BinaryTreeNode* root,int element);
struct BinaryTreeNode* deleteInBST(struct BinaryTreeNode* root,int key);
struct BinaryTreeNode* searchInBST(struct BinaryTreeNode* root,int key);
struct BinaryTreeNode* minimumInBST(struct BinaryTreeNode* root);
struct BinaryTreeNode* maximumInBST(struct BinaryTreeNode* root);
struct BinaryTreeNode* maximumInBSTRecursive(struct BinaryTreeNode* root);


int isBinaryTreeABSTWrong2(struct BinaryTreeNode* root);
int isBinaryTreeABSTWrong1(struct BinaryTreeNode* root);

int isBinaryTreeABSTRecursive(struct BinaryTreeNode* root);
int isBinarytreeABSTByinordertraversalRecursive(struct BinaryTreeNode* root,struct BinaryTreeNode** prev);
int isABSTByMinMaxRecursive(struct BinaryTreeNode* root,int min,int max);
int isABSTBySuccAndPredecRecursive(struct BinaryTreeNode* root,struct BinaryTreeNode* succ,struct BinaryTreeNode* pred);


void getInorderSuccessorAndPredecessorInBSTRecursive(struct BinaryTreeNode* root,struct BinaryTreeNode** predec,struct BinaryTreeNode** succ,int key);
struct BinaryTreeNode* getInorderSuccessorInBST(struct BinaryTreeNode* root,struct BinaryTreeNode* node);

int getLevelOfAKeyInBST(struct BinaryTreeNode* root,int key);

struct BinaryTreeNode*  getlowestCommonAncestorInBSTRecursive(struct BinaryTreeNode* root,int key1,int key2);
struct BinaryTreeNode* getLowestCommonAncestorBST(struct BinaryTreeNode* root,int key1,int key2);

void kthSmallestNodeInBST(struct BinaryTreeNode* root,int k,struct BinaryTreeNode** smallestNode);
void kthLargestNodeInBST(struct BinaryTreeNode* root,int k,struct BinaryTreeNode** largestNode);

struct BinaryTreeNode* ceilInBST(struct BinaryTreeNode* root,int key);
struct BinaryTreeNode* floorInBST(struct BinaryTreeNode* root,int key);

struct BinaryTreeNode* MergeTwoBSTByRecursiveInorderTraversal(struct BinaryTreeNode* rootx,struct BinaryTreeNode* rooty);
struct BinaryTreeNode* MergeTwoBSTByNonRecursiveInorderTraversal(struct BinaryTreeNode* rootx,struct BinaryTreeNode* rooty);

void fixForTwoNodeSwappedWronglyinBST(struct BinaryTreeNode* ptr,struct BinaryTreeNode** rightBST);
void fixForTwoNodeSwappedWronglyinBSTOptimized(struct BinaryTreeNode* wrongBST);

int isPairPresentWithTargetSumInBST(struct BinaryTreeNode* root,int target);
int isPairPresentWithTargetSumInBSTOptimized(struct BinaryTreeNode* root,int target);

struct BinaryTreeNode* sortedArrayConversionToBalanceBST(int array[],int start,int end);
struct BinaryTreeNode* binaryTreeConversionToBSTWithoutChangingStructure(struct BinaryTreeNode * root);




struct BinaryTreeNode* insertInBST(struct BinaryTreeNode* root,int element){

	if(root==NULL){

		root=getBinaryTreeNode(element);
		return root;
	}
	if(element< root->data){

		root->left=insertInBST(root->left,element);
	}else if(element> root->data){
		root->right=insertInBST(root->right,element);
	}

	return root;
}
struct BinaryTreeNode* deleteInBST(struct BinaryTreeNode* root,int key){

	if(root==NULL){
		return NULL;
	}

	if(key<root->data){

		root->left=deleteInBST(root->left,key);
	}else if(key>root->data){

		root->right=deleteInBST(root->right,key);
	}else {
		if(root->left==NULL){

			struct BinaryTreeNode* tmp =root->right;
			free(root);
			return tmp;
		}
		if(root->right==NULL){
			struct BinaryTreeNode* tmp=root->left;
			free(root);
			return tmp;
		}

		struct BinaryTreeNode* inorderSuccesor=minimumInBST(root->right);

		root->data=inorderSuccesor->data;

		root->right=deleteInBST(root->right,inorderSuccesor->data);

	}

	return root;

}

struct BinaryTreeNode* searchInBST(struct BinaryTreeNode* root,int key){

	if(root==NULL ){
		return NULL;
	}

	if(key==root->data){
		return root;
	}else if(key<root->data){

		return searchInBST(root->left,key);
	}else {
		return searchInBST(root->right,key);
	}
}

struct BinaryTreeNode* minimumInBST(struct BinaryTreeNode* root){

	if(root==NULL || root->left==NULL){
		return root;
	}

	return minimumInBST(root->left);
}
struct BinaryTreeNode* maximumInBST(struct BinaryTreeNode* root){

	if(root==NULL){
		return root;
	}

	while(root->right!=NULL){
	root=root->right;
	}

	return root;

}

struct BinaryTreeNode* maximumInBSTRecursive(struct BinaryTreeNode* root){

	if(root==NULL||root->right==NULL){
		return root;
	}

	return maximumInBSTRecursive(root->right);
}

int isBinaryTreeABSTWrong1(struct BinaryTreeNode* root){

	if(root==NULL ){
		return 1;
	}

	return root->left ?
			(root->left->data < root->data ?
					(root->right ? (root->right->data > root->data ? 1 : 0) : 1) :0) :
			(root->right ? (root->right->data > root->data ? 1 : 0) : 1)
					&& isBinaryTreeABSTWrong1(root->left)
					&& isBinaryTreeABSTWrong1(root->right);

}
int isBinaryTreeABSTWrong2(struct BinaryTreeNode* root){

	if(root==NULL ){
		return 1;
	}

	if(root->left && root->left->data > root->data ){

		return 0;
	}
	if(root->right && root->right->data < root->data){

		return 0;
	}

	if(isBinaryTreeABSTWrong2(root->left)==0||isBinaryTreeABSTWrong2(root->right)==0){

		return 0;
	}

	return 1;

}
int isBinaryTreeABSTRecursive(struct BinaryTreeNode* root){

	if(root==NULL ){
		return 1;
	}

	if(root->left && root->data< maximumInBST(root->left)->data){

		return 0;
	}
	if(root->right &&  root->data>minimumInBST(root->right)->data){

		return 0;
	}

	if(isBinaryTreeABSTRecursive(root->left)==0||isBinaryTreeABSTRecursive(root->right)==0){

		return 0;
	}

	return 1;

}
int isBinarytreeABSTByinordertraversalRecursive(struct BinaryTreeNode* root,struct BinaryTreeNode** prev){

	if (root != NULL) {

		if (isBinarytreeABSTByinordertraversalRecursive(root->left, prev) == 0) {
			return 0;
		}

		if ((*prev) && root->data <= (*prev)->data) {

			return 0;
		}
		*prev = root;

		if (isBinarytreeABSTByinordertraversalRecursive(root->right, prev) == 0) {
			return 0;
		}

	}

	return 1;
}
int isABSTByMinMaxRecursive(struct BinaryTreeNode* root,int min,int max){

	if(root==NULL){
		return 1;
	}
	if(root->data<= min ||root->data>=max){

		return 0;
	}

	return isABSTByMinMaxRecursive(root->left,min,root->data)&& isABSTByMinMaxRecursive(root->right,root->data,max);

}

int isABSTBySuccAndPredecRecursive(struct BinaryTreeNode* root,struct BinaryTreeNode* predec,struct BinaryTreeNode* succ){


	if(root==NULL){
		return 1;
	}
	if(succ && root->data > succ->data){
		return 0;
	}
	if(predec && root->data < predec->data){
		return 0;
	}

	return isABSTBySuccAndPredecRecursive(root->left,predec,root) && isABSTBySuccAndPredecRecursive(root->right,root,succ);

}

void getInorderSuccessorAndPredecessorInBSTRecursive(struct BinaryTreeNode* root,struct BinaryTreeNode** predecessor,struct BinaryTreeNode** successor,int key){

	if(root==NULL) return;

	if(key<root->data){

		(*successor)=root;
		getInorderSuccessorAndPredecessorInBSTRecursive(root->left,predecessor,successor,key);

	}else if(key>root->data){

		(*predecessor)=root;
		getInorderSuccessorAndPredecessorInBSTRecursive(root->right,predecessor,successor,key);
	}else{
		if(root->right)
		(*successor)=minimumInBST(root->right);
		if(root->left)
		(*predecessor)=maximumInBST(root->left);
	}
}
struct BinaryTreeNode* getInorderSuccessorInBST(struct BinaryTreeNode* root,struct BinaryTreeNode* node){

	if(node->right){

		return minimumInBST(root->right);
	}

	struct BinaryTreeNode* succ=NULL;

	while(root!=node){
		if(node->data<root->data){
			succ=root;
			root=root->left;
		}else if(node->data>root->data){

			root=root->right;
		}
	}
	return succ;
}

int getLevelOfAKeyInBST(struct BinaryTreeNode* root,int key){

	if(root==NULL){
		return -1;
	}

	if(key==root->data){
		return 1;
	}else if(key<root->data){

		return 1+getLevelOfAKeyInBST(root->left,key);
	}else if(key>root->data){
		return 1+getLevelOfAKeyInBST(root->right,key);
	}

}
struct BinaryTreeNode*  getlowestCommonAncestorInBSTRecursive(struct BinaryTreeNode* root,int key1,int key2){

	if(!root){
		return NULL;
	}

	if(root->data>key1 && root->data>key2){

		return getlowestCommonAncestorInBSTRecursive(root->left,key1,key2);
	}else if(root->data<key1 && root->data<key2){

		return getlowestCommonAncestorInBSTRecursive(root->right,key1,key2);
	}

	return root;
}


struct BinaryTreeNode* getLowestCommonAncestorBST(struct BinaryTreeNode* root,int key1,int key2){

	if(!root)return NULL;

	while(1){
		if(root->data>key1 && root->data>key2){
			root=root->left;
		}else if(root->data<key1 && root->data<key2){
			root=root->right;
		}else{
			break;
		}
	}
	return root;
}

void kthSmallestNodeInBST(struct BinaryTreeNode* root,int k,struct BinaryTreeNode** smallestNode){

	static int counter=0;
	if(root){

		  kthSmallestNodeInBST(root->left,k,smallestNode);

		  counter++;
		  if(counter==k){
			  *smallestNode=root;
		  }
		 kthSmallestNodeInBST(root->right,k,smallestNode);
	}
}

void kthLargestNodeInBST(struct BinaryTreeNode* root,int k,struct BinaryTreeNode** largestNode){

	static int counter=0;
	if(root){

		kthLargestNodeInBST(root->right,k,largestNode);
		counter++;
		if(counter==k){
			*largestNode=root;
		}
		kthLargestNodeInBST(root->left,k,largestNode);
	}
}
//node data larger or equal to K
struct BinaryTreeNode* ceilInBST(struct BinaryTreeNode* root,int key){

	if(!root)return NULL;
	if(key<minimumInBST(root)->data){
		return minimumInBST(root);
	}

	if(key>maximumInBST(root)->data)
		return NULL;
	struct BinaryTreeNode* succ=NULL;
	while(root){
		if(key==root->data){
			return root;
		}else if(key<root->data){
			succ=root;
			root=root->left;
		}else if(key>root->data){
			root=root->right;
		}
	}
	return succ;
}

//node value smaller or equal to K
struct BinaryTreeNode* floorInBST(struct BinaryTreeNode* root,int key){

	if(!root) return NULL;
	if(key<minimumInBST(root)->data){
		return NULL;
	}
	if(key>maximumInBST(root)->data)
		return maximumInBST(root);
    struct BinaryTreeNode* predecessor=NULL;
    while(root){
    	if(key==root->data){
    		return root;
    	}else if(key<root->data){
    		root=root->left;
    	}else if(key>root->data){
    		predecessor=root;
    		root=root->right;
    	}
    }
    return predecessor;
}

struct BinaryTreeNode* ceilInBSTMethod2(struct BinaryTreeNode* root,int key){

	if(root==NULL||root->data==key) return root;

	struct BinaryTreeNode* left=NULL;
	struct BinaryTreeNode* right=NULL;

	if(key<root->data){
		left= ceilInBSTMethod2(root->left,key);
	}
	else{
		right= ceilInBSTMethod2(root->right,key);
	}
	struct BinaryTreeNode* ceil=left?left:(right?right:root);

	return ceil;

}
void traverseInorder(struct BinaryTreeNode* ptr,struct BinaryTreeNode** root){

	if(ptr){
		traverseInorder(ptr->left,root);
		*root=insertInBST(*root,ptr->data);
		traverseInorder(ptr->right,root);
	}

}
struct BinaryTreeNode* MergeTwoBSTByRecursiveInorderTraversal(struct BinaryTreeNode* rootx,struct BinaryTreeNode* rooty){

	struct BinaryTreeNode* root=NULL;
	traverseInorder(rootx,&root);
	traverseInorder(rooty,&root);
	return root;
}
struct BinaryTreeNode* MergeTwoBSTByNonRecursiveInorderTraversal(struct BinaryTreeNode* rootx,struct BinaryTreeNode* rooty){

	struct LinkListWithBtreeNode* topStack1=NULL;
	struct LinkListWithBtreeNode* topStack2=NULL;

	struct BinaryTreeNode* curr1=rootx;
	struct BinaryTreeNode* curr2=rooty;
	while(1){

		if(curr1==NULL && topStack1==NULL && curr2==NULL && topStack2==NULL){
           break;
		}
		while(curr1!=NULL){

			addToStack(&topStack1,curr1);
			curr1=curr1->left;
		}
		while (curr2 != NULL) {

			addToStack(&topStack2, curr2);
			curr2 = curr2->left;
		}

		curr1=deleteFromStack(&topStack1);
		curr2=deleteFromStack(&topStack2);
		if (curr1 && curr2) {
			if (curr1->data < curr2->data) {
				printf("%d ", curr1->data);
				curr1 = curr1->right;
				addToStack(&topStack2, curr2);
				curr2 = NULL;
			} else if (curr1->data > curr2->data) {
				printf("%d ", curr2->data);
				curr2 = curr2->right;
				addToStack(&topStack1, curr1);
				curr1 = NULL;
			}
		}else if(curr1==NULL && curr2!=NULL){
			printf("%d ",curr2->data);
			curr2=curr2->right;

		}else if(curr2==NULL && curr1!=NULL){
			printf("%d ",curr1->data);
			curr1=curr1->right;
		}
	}

}

void fixForTwoNodeSwappedWronglyinBST(struct BinaryTreeNode* ptr,struct BinaryTreeNode** rightBST){

	if(ptr){

		*rightBST=insertInBST(*rightBST,ptr->data);
		fixForTwoNodeSwappedWronglyinBST(ptr->left,rightBST);
		fixForTwoNodeSwappedWronglyinBST(ptr->right,rightBST);

	}
}
void fixForTwoNodeSwappedWronglyinBSTOptimizedUtil(struct BinaryTreeNode *ptr,
		struct BinaryTreeNode** first, struct BinaryTreeNode** middle,
		struct BinaryTreeNode** last,struct BinaryTreeNode** prev) {

	if(ptr){
		fixForTwoNodeSwappedWronglyinBSTOptimizedUtil(ptr->left,first,middle,last,prev);
		if(*prev && (*first)==NULL && (*prev)->data >ptr->data){

			(*first)=*prev;;
			(*middle)=ptr;
		}else if(*prev && *first && (*prev)->data >ptr->data ){

			(*last)=ptr;
		}

		*prev=ptr;

		fixForTwoNodeSwappedWronglyinBSTOptimizedUtil(ptr->right,first,middle,last,prev);

	}

}
void fixForTwoNodeSwappedWronglyinBSTOptimized(struct BinaryTreeNode* wrongBST) {

	int tmp;
	struct BinaryTreeNode *first, *middle, *last, *prev;
	first = middle = last = prev = NULL;
	fixForTwoNodeSwappedWronglyinBSTOptimizedUtil(wrongBST, &first, &middle,
			&last, &prev);
	if (last) {
		tmp = first->data;
		first->data = last->data;
		last->data = tmp;
	} else {
		tmp = first->data;
		first->data = middle->data;
		middle->data = tmp;
	}
}
int isPairPresentWithTargetSumInBST(struct BinaryTreeNode* root,int target){

	if (root) {
		if (isPairPresentWithTargetSumInBST(root->left, target) == 1) {
			return 1;
		}

		struct BinaryTreeNode* otherNode = searchInBST(root,target - root->data);
		if (otherNode && otherNode->data + root->data == target) {

			return 1;
		}

		if (isPairPresentWithTargetSumInBST(root->right, target) == 1) {
			return 1;
		}
	}
	return 0;
}
int isPairPresentWithTargetSumInBSTOptimized(struct BinaryTreeNode* root,int target){


	struct LinkListWithBtreeNode* topStack1=NULL;
	struct LinkListWithBtreeNode* topStack2=NULL;

	struct BinaryTreeNode* curr1=root;
	struct BinaryTreeNode* curr2=root;

	while (1) {
		if ((curr1 == NULL && topStack1 == NULL) || (curr2 == NULL && topStack2 == NULL)) {
			break;
		}

		while (curr1 != NULL) {
			addToStack(&topStack1, curr1);
			curr1 = curr1->left;
		}

		while (curr2 != NULL) {
			addToStack(&topStack2, curr2);
			curr2 = curr2->right;
		}

		curr1 = deleteFromStack(&topStack1);
		curr2 = deleteFromStack(&topStack2);
		if (curr1 && curr2) {
			if ((curr1->data + curr2->data) < target) {

				addToStack(&topStack2, curr2);
				curr2=NULL;
				curr1 = curr1->right;
			} else if (curr1->data + curr2->data > target) {

				addToStack(&topStack1, curr1);
				curr1=NULL;
				curr2 = curr2->left;
			} else if(curr1->data + curr2->data == target) {
				return 1;
			}

		}

	}
return 0;
}

struct BinaryTreeNode* sortedArrayConversionToBalanceBST(int array[], int start,int end) {

	struct BinaryTreeNode* root = NULL;
	int mid;

	if (start > end) {
		return NULL;
	}

	mid = (start + end) / 2;
	root = getBinaryTreeNode(array[mid]);
	root->left = sortedArrayConversionToBalanceBST(array, start, mid - 1);
	root->right = sortedArrayConversionToBalanceBST(array, mid + 1, end);

	return root;

}
void addNodesToList(struct BinaryTreeNode* root,struct LinkListNode** list){

	if(root){

		addNodesToList(root->left,list);
		insertAtFrontLinkList(list,root->data);
		addNodesToList(root->right,list);
	}
}
void replaceNodeValueInbinaryTree(struct BinaryTreeNode* root,struct LinkListNode** list){
	if(root){
		replaceNodeValueInbinaryTree(root->left,list);

		root->data=(*list)->data;
		(*list)=(*list)->next;
		replaceNodeValueInbinaryTree(root->right,list);
	}

}
struct BinaryTreeNode* binaryTreeConversionToBSTWithoutChangingStructure(struct BinaryTreeNode * broot){

	struct LinkListNode* list = NULL;

	addNodesToList(broot, &list);
	list = mergeSortOfLinkList(list);
	replaceNodeValueInbinaryTree(broot, &list);

	return broot;
}
struct BinaryTreeNode* buildBSTFromPreorderTraversal(int* pre,int size){

	struct BinaryTreeNode* root=NULL;
	int i;
	for(i=0;i<size;i++){
		root=insertInBST(root,pre[i]);
	}
	return root;
}

struct BinaryTreeNode* buildBSTFromPreorderTraversalRecursive(int* pre,int start,int end){

	if(start>end) return NULL;
	struct BinaryTreeNode* root=getBinaryTreeNode(pre[start]);

	if(start==end) return root;

	int index=getIndexofLargerThanKeyElement(pre,start,end,pre[start]);

	root->left=buildBSTFromPreorderTraversalRecursive(pre,start+1,index-1);
	root->right=buildBSTFromPreorderTraversalRecursive(pre,index,end);

	return root;
}
struct BinaryTreeNode* buildBSTFromPreorderTraversalUtil(int* pre,int* index,int size,int min,int max){

	struct BinaryTreeNode* root=NULL;

	if(max!=INT_MAX ){
		if(pre[*index]<max && pre[*index]>min)
		root=getBinaryTreeNode(pre[*index]);
		else{
			return NULL;
		}

	}else if(min!=INT_MIN){
		if(pre[*index]>min && pre[*index]<max){
			root=getBinaryTreeNode(pre[*index]);
		}else{
			return NULL;
		}

	}else if(pre[*index]<INT_MAX && pre[*index]>INT_MIN){

		root=getBinaryTreeNode(pre[*index]);
	}

	(*index)++;
	root->left=buildBSTFromPreorderTraversalUtil(pre,index,size,min,root->data);
	root->right=buildBSTFromPreorderTraversalUtil(pre,index,size,root->data,max);

	return root;
}
struct BinaryTreeNode* buildBSTFromPreorderTraversalOptimized(int* pre,int size){

	int min=INT_MIN;
	int max=INT_MAX;
	int index=0;

	return buildBSTFromPreorderTraversalUtil(pre,&index,size,min,max);
}
struct BinaryTreeNode* buildBSTFromPreorderTraversalUtil2(int* pre,int* index,int key,int size,int min,int max){

	if(*index>=size) return NULL;

	struct BinaryTreeNode* root=NULL;
	if(key>min && key<max){


		root=getBinaryTreeNode(key);
		(*index)++;
		if(*index<size){
		root->left=buildBSTFromPreorderTraversalUtil2(pre,index,pre[*index],size,min,key);
		root->right=buildBSTFromPreorderTraversalUtil2(pre,index,pre[*index],size,key,max);
		}

	}
	return root;
}
struct BinaryTreeNode* buildBSTFromPreorderTraversalOptimized2(int* pre,int size){

	int min=INT_MIN;
	int max=INT_MAX;
	int index=0;

	return buildBSTFromPreorderTraversalUtil2(pre,&index,pre[index],size,min,max);
}


struct BinaryTreeNode* buildBSTFrompPeorderTraversalIterative(int* pre,int size){

	struct LinkListWithBtreeNode* stack=NULL;

	struct BinaryTreeNode* root=getBinaryTreeNode(pre[0]);
	struct BinaryTreeNode* tmp;
	addToStack(&stack,root);
	int i;
	for(i=1;i<size;i++){
		tmp=NULL;
		while(stack && pre[i] > peekStack(stack)){
			tmp=deleteFromStack(&stack);
		}
		if(tmp){
			tmp->right=getBinaryTreeNode(pre[i]);
			addToStack(&stack,tmp->right);

		}else{

			tmp=deleteFromStack(&stack);
			tmp->left=getBinaryTreeNode(pre[i]);
			addToStack(&stack,tmp);
			addToStack(&stack,tmp->left);
		}
	}
	return root;
}

void getBTreeFromBSTByAddingGreaterKeysUtil(struct BinaryTreeNode* root,int* sum){

	if(!root) return;
	getBTreeFromBSTByAddingGreaterKeysUtil(root->right,sum);

	root->data+=*sum;
	(*sum)=root->data;
	getBTreeFromBSTByAddingGreaterKeysUtil(root->left,sum);
}
void getBTreeFromBSTByAddingSumOfAllGreaterKeysToEveryKey(struct BinaryTreeNode* root){

	int sum=0;
	 getBTreeFromBSTByAddingGreaterKeysUtil(root,&sum);
}


struct BinaryTreeNode* buildBSTFromSortedLinkListUtil(struct LinkListNode** list,int n){

	if(n<=0) return NULL;

	struct BinaryTreeNode* left=buildBSTFromSortedLinkListUtil(list,n/2);
	struct BinaryTreeNode* root=getBinaryTreeNode((*list)->data);
	root->left=left;
	(*list)=(*list)->next;
	root->right=buildBSTFromSortedLinkListUtil(list,n-n/2-1);
}
struct BinaryTreeNode* buildBSTFromSortedLinkList(struct LinkListNode *list){

	int n=sizeOfLinkListRecursive(list);
	return buildBSTFromSortedLinkListUtil(&list,n);

}
void transformBSTByReplacingEveryKeyWithSumOfAllGreaterKeysUtil(struct BinaryTreeNode* root,int* sum){

	int save;
	if(!root) return;
	transformBSTByReplacingEveryKeyWithSumOfAllGreaterKeysUtil(root->right,sum);

	save=root->data;
	root->data=*sum;
	(*sum)+=save;

	transformBSTByReplacingEveryKeyWithSumOfAllGreaterKeysUtil(root->left,sum);
}
void transformBSTByReplacingEveryKeyWithSumOfAllGreaterKeys(struct BinaryTreeNode* root){

	int sum=0;
	transformBSTByReplacingEveryKeyWithSumOfAllGreaterKeysUtil(root,&sum);
}

void replaceBSTKeyWithMinHeapKeys(struct BinaryTreeNode* root,int* array,int index){

	if(!root) return;
	root->data=array[index];
	replaceBSTKeyWithMinHeapKeys(root->left,array,2*index+1);
	replaceBSTKeyWithMinHeapKeys(root->right,array,2*index+2);

}

void inPlaceConvertBSTToMinHeap(struct BinaryTreeNode* root){

	int size=getCountOfNodesInBinaryTree(root);
	int* array=(int*)malloc(sizeof(int)*size);
	size=0;
	getInorderOfBInaryTreeInArray(root,array,&size);

	int index=0;
	replaceBSTKeyWithMinHeapKeys(root,array,index);
}

struct BinaryTreeNode* buildBSTFRomLevelOrderTraversal(int* levelOrder,int size){

	struct LinkListWithBtreeNode* front=NULL;
	struct LinkListWithBtreeNode* rear=NULL;

	struct BinaryTreeNode* root=getBinaryTreeNode(levelOrder[0]);

	addToQueueWithMinMax(root,&front,&rear,INT_MIN,INT_MAX);


	int i=1;
	while (i<size) {

		struct LinkListWithBtreeNode* tmp=deleteFromQueueWithMinMax(&front,&rear);
		struct BinaryTreeNode* bnode=tmp->data;

		if(i<size && levelOrder[i]> tmp->min && levelOrder[i]< bnode->data){

			bnode->left=getBinaryTreeNode(levelOrder[i]);

			addToQueueWithMinMax(bnode->left,&front,&rear,INT_MIN,bnode->data);
			i++;
		}
		if(i<size && levelOrder[i]>bnode->data && levelOrder[i]< tmp->max){

			bnode->right=getBinaryTreeNode(levelOrder[i]);

			addToQueueWithMinMax(bnode->right ,&front,&rear,bnode->data,INT_MAX);;
			i++;
		}
	}
	return root;
}

int isSortedSubSequenceExistInBST(struct BinaryTreeNode* root,int* subSequence,int size,int* count){

	if(!root) return 0;

	int left=isSortedSubSequenceExistInBST(root->left,subSequence,size,count);

	if(root->data==subSequence[*count]){
		(*count)++;
	}
	if(*count==size){
		return 1;
	}
	int right=isSortedSubSequenceExistInBST(root->right,subSequence,size,count);


    return left||right;
}



int isBSTInternalNodesHavingSingleChildUtil(int* pre,int start,int end){

	if(start>end)
		return 0;
	if(start==end)
		return 1;
	int index=getIndexofLargerThanKeyElement(pre,start,end,pre[start]);
	if(index> start+1 && index<=end)
		return 0;


	if(index>end)
	return isBSTInternalNodesHavingSingleChildUtil(pre,start+1,index-1);
	else
	return isBSTInternalNodesHavingSingleChildUtil(pre,index,end);

}
int isBSTInternalNodesHavingSingleChild(int* pre,int size){


	return isBSTInternalNodesHavingSingleChildUtil(pre,0,size-1);
}

int isBSTInternalNodesHavingSingleChildOptimized(int* pre,int size){

	int i,diff1,diff2;
	for(i=0;i<size-2;i++){
		diff1=pre[i]-pre[i+1];
		diff2=pre[i]-pre[size-1];
		if(diff1*diff2<0)
			return 0;
	}

	return 1;
}
int isBSTInternalNodesHavingSingleChildOptimized2(int* pre,int size){

	int min,max,i;

	if(pre[size-1]>pre[size-2]){
		min=pre[size-2];
		max=pre[size-1];
	}else{
		min=pre[size-2];
		max=pre[size-1];
	}

	for(i=size-3;i>=0;i--){

		if(pre[i]<min){
			min=pre[i];
		}else if(pre[i]>max){
			max=pre[i];
		}else{
			return 0;
		}
	}
	return 1;
}
int isDeadEndExistInBSTUtil(struct BinaryTreeNode* root,int min,int max){

	if(!root) return 0;
	if(!root->left && !root->right && (root->data-1==min||root->data==min) && root->data+1==max){
		return 1;
	}

	return isDeadEndExistInBSTUtil(root->left,min,root->data)||isDeadEndExistInBSTUtil(root->right,root->data,max);

}
int isDeadEndExistInBST(struct BinaryTreeNode* root){

	return isDeadEndExistInBSTUtil(root,0,INT_MAX);
}

int isDeadEndExistInBSTM2Util(struct BinaryTreeNode* root,int min,int max){

	if(!root) return 0;
	if(min==max){
		return 1;
	}
	return isDeadEndExistInBSTM2Util(root->left,min,root->data-1)||isDeadEndExistInBSTM2Util(root->right,root->data+1,max);

}
int isDeadEndExistInBSTM2(struct BinaryTreeNode* root){

	return isDeadEndExistInBSTM2Util(root,0,INT_MAX);
}

void sortArrayWhichRepresentLevelOrderTraversalOfBST(int* array,int start,int end){

	if(start>end) return;

	sortArrayWhichRepresentLevelOrderTraversalOfBST(array,2*start+1,end);
	printf("%d ",array[start]);
	sortArrayWhichRepresentLevelOrderTraversalOfBST(array,2*start+2,end);
}

void getSortedKeysOfBSTFromGivenRange(struct BinaryTreeNode* root,int key1,int key2){

	if(!root) return;
	getSortedKeysOfBSTFromGivenRange(root->left,key1,key2);
	if(root->data>=key1 && root->data<=key2){
		printf("%d ",root->data);
	}

	getSortedKeysOfBSTFromGivenRange(root->right,key1,key2);
}

void getSortedKeysOfBSTFromGivenRangeOptimized(struct BinaryTreeNode* root,int key1,int key2){
	if(!root) return;
	if(root->data>key1)
		getSortedKeysOfBSTFromGivenRangeOptimized(root->left,key1,key2);

	if(root->data>=key1 && root->data<=key2)
		printf("%d ",root->data);
	if(root->data<key2)
		getSortedKeysOfBSTFromGivenRangeOptimized(root->right,key1,key2);
}

int getMaxSizeOfBSTPresentInBinaryTree(struct BinaryTreeNode* root){

	if(!root) return 0;
	if(isABSTByMinMaxRecursive(root,INT_MIN,INT_MAX))
		return getCountOfNodesInBinaryTree(root);
	return maxoftwo(getMaxSizeOfBSTPresentInBinaryTree(root->left),getMaxSizeOfBSTPresentInBinaryTree(root->right));
}

int isTripletpresentInBST(struct BinaryTreeNode* root,int sum){

	int count=getCountOfNodesInBinaryTree(root);
	int* array=(int *)malloc(sizeof(int)* count);
	int size=0;
	getInorderOfBInaryTreeInArray(root,array,&size);
	int i,l,r;

	for(i=0;i<size-2;i++){

		l=i+1;
		r=size-1;
		while(l<r){

			if(array[i]+array[l]+array[r]==sum){
				return 1;
			}
			else if(array[i]+array[l]+array[r]<sum){

				l++;
			}else{
				r--;
			}
		}
	}

	return 0;
}
void convertBSTtoDLL(struct BinaryTreeNode* root,struct BinaryTreeNode** headRef,struct BinaryTreeNode** tailRef){

	if(!root) return;
	convertBSTtoDLL(root->right,headRef,tailRef);
	if(!*headRef){
		*headRef=*tailRef=root;
	}else{
		root->right=*headRef;
		(*headRef)->left=root;
		*headRef=root;
	}
	convertBSTtoDLL(root->left,headRef,tailRef);
}
int isTripletpresentInBSTOptimized(struct BinaryTreeNode* root,int sum){

	struct BinaryTreeNode* head=NULL;
	struct BinaryTreeNode* tail =NULL;
	convertBSTtoDLL(root,&head,&tail);


	struct BinaryTreeNode* ptr1;
	struct BinaryTreeNode* ptr2=tail;
	while(head!=tail->left){

		ptr1=head->right;
		ptr2=tail;
		while(ptr1!=ptr2){

			if(head->data+ptr1->data+ptr2->data==sum){
				return 1;
			}else if(head->data+ptr1->data+ptr2->data<sum){
				ptr1=ptr1->right;
			}else{
				ptr2=ptr2->left;
			}
		}

	}

	return 0;
}

struct BinaryTreeNode*  deleteNodesOutsideOfGivenRangeinBST(struct BinaryTreeNode* root,int key1,int key2){

	if(!root) return NULL;
	root->left=deleteNodesOutsideOfGivenRangeinBST(root->left,key1,key2);
	root->right=deleteNodesOutsideOfGivenRangeinBST(root->right,key1,key2);

	if(root->data<key1 || root->data>key2){
		return deleteInBST(root,root->data);

	}

	return root;
}


struct BinaryTreeNode*  deleteNodesOutsideOfGivenRangeinBSTOptimized(struct BinaryTreeNode* root,int key1,int key2){

	if(!root) return NULL;
	root->left=deleteNodesOutsideOfGivenRangeinBSTOptimized(root->left,key1,key2);
	root->right=deleteNodesOutsideOfGivenRangeinBSTOptimized(root->right,key1,key2);

	if(root->data<key1){
		struct BinaryTreeNode* rchild=root->right;
		free(root);
		return rchild;
	}
	if(root->data>key2){
		struct BinaryTreeNode* lchild=root->left;
		free(root);
		return lchild;
	}

	return root;
}

void getCountOfNodesInGivenRangeBST(struct BinaryTreeNode* root,int key1,int key2,int* count){

	if(!root) return;
	if(root->data>key1)
	getCountOfNodesInGivenRangeBST(root->left,key1,key2,count);
	if(root->data>=key1 && root->data<=key2)
	(*count)++;
	if(root->data<key2)
	getCountOfNodesInGivenRangeBST(root->right,key1,key2,count);

}

int getCountOfNodesInGivenRangeBSTOptimized(struct BinaryTreeNode* root,int key1,int key2){

	if(!root) return 0;

	if(root->data<key1){
		getCountOfNodesInGivenRangeBSTOptimized(root->right,key1,key2);

	}else if(root->data>key2){

		return getCountOfNodesInGivenRangeBSTOptimized(root->left,key1,key2);
	}else{
		return 1+		getCountOfNodesInGivenRangeBSTOptimized(root->right,key1,key2)+
				getCountOfNodesInGivenRangeBSTOptimized(root->left,key1,key2);
	}
}
struct Interval{
	int low;
	int high;
};
struct IntervalTreeNode{
	struct Interval *interval;
	int max;
	struct IntervalTreeNode* left;
	struct IntervalTreeNode* right;
};

struct IntervalTreeNode* getintervalTreeNode(struct Interval in){

	struct IntervalTreeNode* itnode =(struct IntervalTreeNode *) malloc(sizeof(struct IntervalTreeNode));
	itnode->interval=(struct Interval*) malloc(sizeof(struct Interval));
	itnode->interval->low=in.low;itnode->interval->high=in.high;
	itnode->max=in.high;
	itnode->left=itnode->right=NULL;
	return itnode;

}
struct IntervalTreeNode* insertInIntervalTree(struct IntervalTreeNode* root,struct Interval interval){

	if(root==NULL)
		return getintervalTreeNode(interval);

	int low=root->interval->low;
	if(interval.low<low)
		root->left=insertInIntervalTree(root->left,interval);
	else{
		root->right=insertInIntervalTree(root->right,interval);
	}

	if(root->max<interval.high){
		root->max=interval.high;
	}
	return root;
}
void inorderTraversalOfIntervalTree(struct IntervalTreeNode* root){

	if(!root) return ;
	inorderTraversalOfIntervalTree(root->left);
	printf("[%d,%d] ",root->interval->low,root->interval->high);
	inorderTraversalOfIntervalTree(root->right);

}
int areIntervalsOverlapping(struct Interval* i1,struct Interval* i2){

	return i1->low < i2->high && i2->low < i1->high;
}

struct Interval* searchOverlapintervalInIntervalTree(struct IntervalTreeNode* root,struct Interval in){

	if(!root) return NULL;

	if(areIntervalsOverlapping(root->interval,&in))
		return root->interval;

	if(root->left && in.low <= root->left->max)
		return searchOverlapintervalInIntervalTree(root->left,in);


	return searchOverlapintervalInIntervalTree(root->right,in);
}
void getAllConflictingAppointments(struct Interval in[],int size){

	int i;
	struct IntervalTreeNode* root=NULL;

	root=insertInIntervalTree(root,in[0]);


	struct Interval* overlap=NULL;
	for(i=1;i<size;i++){
		overlap=searchOverlapintervalInIntervalTree(root,in[i]);
		if(overlap){
			printf("\n[%d,%d] overlapping with [%d,%d]",in[i].low,in[i].high,overlap->low,overlap->high);
		}
		root=insertInIntervalTree(root,in[i]);
	}
}


int getCountOdSubtreeLiesinGivenRangeInBSTutil(struct BinaryTreeNode* root,int key1,int key2,int *isSubtreeInRange){

	int leftFlag=0;
	int rightflag=0;

	if(!root){
		*isSubtreeInRange=0;
		return 0;
	}
	if(!root->left && !root->right){

		if(root->data>=key1 && root->data<=key2){
			*isSubtreeInRange=1;
			return 1;
		}else{
			*isSubtreeInRange=0;
			return 0;
		}
	}

	int left=getCountOdSubtreeLiesinGivenRangeInBSTutil(root->left,key1,key2,isSubtreeInRange);
	if(*isSubtreeInRange){
		leftFlag=1;
	}
	int right=getCountOdSubtreeLiesinGivenRangeInBSTutil(root->right,key1,key2,isSubtreeInRange);
	if(*isSubtreeInRange){
		rightflag=1;
	}

	if(leftFlag && rightflag) {
		*isSubtreeInRange=1;
		return 1+left+right;
	}

	if(leftFlag||rightflag){
		if((!root->right||!root->left) && root->data>=key1 && root->data<=key2){
			*isSubtreeInRange=1;
			return 1+maxoftwo(left,right);
		}else{
			*isSubtreeInRange=0;
			return left+right;

		}
	}
	*isSubtreeInRange=0;
	return left+right;
}
int getCountOdSubtreeLiesinGivenRangeInBST(struct BinaryTreeNode* root,int key1,int key2){
	int isSubtreeInRange=0;
	return getCountOdSubtreeLiesinGivenRangeInBSTutil(root,key1,key2,&isSubtreeInRange);
}
void storeMedianElementsFrominorderBST(struct BinaryTreeNode* root,int n,int* count,int* first,int* second){

	if(!root|| *count > n/2+1) return;

	storeMedianElementsFrominorderBST(root->left,n,count,first,second);

	if(*count== n/2)
		*first=root->data;
	if(*count == n/2+1)
		*second=root->data;
	(*count)++;
	storeMedianElementsFrominorderBST(root->right,n,count,first,second);

}
int getMedianOfBST(struct BinaryTreeNode* root){

	int n=getCountOfNodesInBinaryTree(root);
	int first,second,count=0;

	storeMedianElementsFrominorderBST(root,n,&count,&first,&second);

	printf("first=%d,second=%d\n",first,second);
	if(n%2){

		return first;
	}else{
		return (first+second)/2;;
	}
}
struct BinaryTreeNode* deleteAllLeafNodesOfBST(struct BinaryTreeNode* root){

	if(!root->left && !root->right){
		free(root);
		return NULL;
	}
	root->left=deleteAllLeafNodesOfBST(root->left);
	root->right=deleteAllLeafNodesOfBST(root->right);
	return root;
}


int compareInt(const void* x,const void* y){

	return *((int*)x)-*((int*)y);
}

void getAllLeafNodesFromPreOrderTraversalUtil(int* pre,int * in,int l,int r,int* index,int n){

	if(l==r){
		printf("%d ",in[l]);
		(*index)++;
		return;
	}
	if(l>r||l<0||r>=n) return;

	int loc=getElementIndex(in,l,r,pre[*index]);
	(*index)++;
	getAllLeafNodesFromPreOrderTraversalUtil(pre,in,l,loc-1,index,n);
	getAllLeafNodesFromPreOrderTraversalUtil(pre,in,loc+1,r,index,n);
}
void getAllLeafNodesFromPreOrderTraversal(int* pre,int size){

	int* in=(int *)malloc(sizeof(int)*size);
	int i;
	for(i=0;i<size;i++){
		in[i]=pre[i];
	}
	qsort(in,size,sizeof(int),compareInt);

	int preindex=0;
	getAllLeafNodesFromPreOrderTraversalUtil(pre,in,0,size-1,&preindex,size);
}
void getAllLeafNodesFromPreOrderTraversalOptimized(int* pre,int size){

	struct LinkListNode* stack=NULL;
	int i,j,found;

	for(i=0,j=1;j<size;j++,i++){

		found=0;
		if(pre[i]>pre[j])
			pushToStackAsLinkList(&stack,pre[i]);
		else{
			while(stack){

				if(pre[j]>stack->data){
					popFromStackAsLinkList(&stack);
					found=1;
				}else{
					break;
				}
			}
		}
		if(found){
			printf("%d ",pre[i]);
		}
	}
	printf("%d ",pre[i]);
}
int getDistanceBetweenTwoNodes(struct BinaryTreeNode* root,int key1,int key2){

	if(!root) return 0;

	if(root->data>key1 && root->data>key2)

		getDistanceBetweenTwoNodes(root->left,key1,key2);

	else if(root->data<key1 && root->data<key2){
		getDistanceBetweenTwoNodes(root->right,key1,key2);
	}else{
		return getDistanceFromRoot(root,key1)+getDistanceFromRoot(root,key2);
	}
}
int getCountOfPairsWithGivenSumInBST(struct BinaryTreeNode* root1,struct BinaryTreeNode* root2,int sum){

	struct LinkListWithBtreeNode* stack1=NULL;
	struct LinkListWithBtreeNode* stack2=NULL;
	struct BinaryTreeNode* curr1=root1;
	struct BinaryTreeNode* curr2=root2;
	int count=0;
	while(1){

		if((!curr1 && !stack1)||(!curr2 && !stack2)){
			break;
		}
		while(curr1){
			addToStack(&stack1,curr1);
			curr1=curr1->left;
		}
		while(curr2){
			addToStack(&stack2,curr2);
			curr2=curr2->right;
		}

		curr1=deleteFromStack(&stack1);
		curr2=deleteFromStack(&stack2);

			if(curr1->data+curr2->data==sum){
				printf("%d,%d\n",curr1->data,curr2->data);
				count++;
				curr1=curr1->right;
				curr2=curr2->left;
			}else if(curr1->data+curr2->data<sum){
				curr1=curr1->right;
				addToStack(&stack2,curr2);
				curr2=NULL;

			}else{

				curr2=curr2->left;
				addToStack(&stack1,curr1);
				curr1=NULL;
			}
	}
	return count;
}
int getMaxNodeOnPathinBST(struct BinaryTreeNode* root,int k1,int k2 ){

	if(root->data>k1 && root->data>k2)
		return getMaxNodeOnPathinBST(root->left,k1,k2);
	else if(root->data<k1 && root->data<k2)
		return getMaxNodeOnPathinBST(root->right,k1,k2);
	else{

		struct BinaryTreeNode* k1node=searchInBST(root,k1);
		struct BinaryTreeNode* k2node=searchInBST(root,k2);

		return getmaxnode(root,k1node,k2node);

	}
}
int getMaxNodeOnPath(struct BinaryTreeNode* root,int key){

	int max=-1;
	while(root->data!=key){

		if(root->data>key){
			max=maxoftwo(max,root->data);
			root=root->left;
		}else{
			max=maxoftwo(max,root->data);
			root=root->right;
		}
	}

	return maxoftwo(max,root->data);
}
int getMaxNodeOnPathinBSTOptimized(struct BinaryTreeNode* root,int k1,int k2 ){

	if(root->data>k1 && root->data>k2)
		return getMaxNodeOnPathinBST(root->left,k1,k2);
	else if(root->data<k1 && root->data<k2)
		return getMaxNodeOnPathinBST(root->right,k1,k2);
	else{

		return maxoftwo(getMaxNodeOnPath(root,k1),getMaxNodeOnPath(root,k2));

	}
}
void getClosestElementInBSTUtil(struct BinaryTreeNode* root,int k,int *min,int *nodeValue){

	if(!root) return ;
	if(root->data==k){
		*nodeValue=root->data;
		*min=abs(root->data-k);
		return;
	}

	if(root->data>k){
		if(*min>abs(root->data-k)){
			*nodeValue=root->data;
			*min=abs(root->data-k);
		}

		getClosestElementInBSTUtil(root->left,k,min,nodeValue);
	}
	else if(root->data<k){
		if(*min>abs(root->data-k)){
			*nodeValue=root->data;
			*min=abs(root->data-k);
		}
		getClosestElementInBSTUtil(root->right,k,min,nodeValue);
	}
}
int getClosestElementInBST(struct BinaryTreeNode* root,int k){\

	int min=INT_MAX;
    int nodevalue;
	getClosestElementInBSTUtil(root,k,&min,&nodevalue);

	return nodevalue;
}
struct BinaryTreeNode* insertAndgetsucc(struct BinaryTreeNode* root,int k,struct BinaryTreeNode** succ){

	if(!root){
		return getBinaryTreeNode(k);
	}

	if(k<root->data){
		*succ=root;
		root->left= insertAndgetsucc(root->left,k,succ);
	}else{
		root->right= insertAndgetsucc(root->right,k,succ);
	}

	return root;
}
int replaceElementWithLeastGreaterElementOnRight(int *array,int size){

	int i;
	struct BinaryTreeNode* root=NULL;
	for(i=size-1;i>=0;i--){

		struct BinaryTreeNode* succ=NULL;
		root=insertAndgetsucc(root,array[i],&succ);
		if(succ){
			array[i]=succ->data;
		}else{
			array[i]=-1;;
		}
	}
}

void getCommonNodesFromTwoBST(struct BinaryTreeNode* root1,struct BinaryTreeNode* root2){

	struct LinkListWithBtreeNode* stack1=NULL;
	struct LinkListWithBtreeNode* stack2=NULL;
	struct BinaryTreeNode* curr1=root1;
	struct BinaryTreeNode* curr2=root2;

	while(1){

		if((!curr1 && !stack1)||(!curr2 && !stack2))
			break;


		while(curr1){
			addToStack(&stack1,curr1);
			curr1=curr1->left;
		}
		while(curr2){
			addToStack(&stack2,curr2);
			curr2=curr2->left;
		}

		curr1=deleteFromStack(&stack1);
		curr2=deleteFromStack(&stack2);

		if(curr1->data==curr2->data){
			printf("%d ",curr1->data);
			curr1=curr1->right;
			curr2=curr2->right;
		}else if(curr1->data < curr2->data){
			curr1=curr1->right;
			addToStack(&stack2,curr2);
			curr2=NULL;
		}else{
			curr2=curr2->right;
			addToStack(&stack1,curr1);
			curr1=NULL;
		}
	}
}
int main(void) {

	/*
	 *            10
	 *           /  \
	 *          5    8
	 *         /\
	 *        2  20
	 */
/*
	struct BinaryTreeNode* wrongBST=getBinaryTreeNode(10);
	wrongBST->left=getBinaryTreeNode(5);
	wrongBST->right=getBinaryTreeNode(8);
	wrongBST->left->left=getBinaryTreeNode(2);
	wrongBST->left->right=getBinaryTreeNode(20);
*/

	/*
	 *            10
	 *           /  \
	 *          2    7
	 *         /\
	 *        8  4
	 */

/*
	struct BinaryTreeNode* binaryTree=getBinaryTreeNode(10);
	binaryTree->left=getBinaryTreeNode(2);
	binaryTree->right=getBinaryTreeNode(7);
	binaryTree->left->left=getBinaryTreeNode(8);
	binaryTree->left->right=getBinaryTreeNode(4);
*/



	/*
     *         3
     *        / \
     *       1   5
     */

/*
	struct BinaryTreeNode* rootx=getBinaryTreeNode(3);
	rootx->left=getBinaryTreeNode(1);
	rootx->right=getBinaryTreeNode(5);
*/

	/*
	 *         44
	 *        / \
	 *       22   66
	 */

/*
	struct BinaryTreeNode* rooty=getBinaryTreeNode(44);
	rooty->left=getBinaryTreeNode(22);
	rooty->right=getBinaryTreeNode(66);
*/




	/*
	      3
		 / \
		2   5
	   / \
	  1   7

	*/
/*	struct BinaryTreeNode* root1=getBinaryTreeNode(3);
	root1->left=getBinaryTreeNode(2);
	root1->right=getBinaryTreeNode(5);
	root1->left->left=getBinaryTreeNode(1);
	root1->left->right=getBinaryTreeNode(7);*/

/*
           50
          /  \
        30    70
       / \    / \
      20  40 60  80
           \
            42
    */

/*	struct BinaryTreeNode* root=NULL;
	int array[8]={50,30,70,20,40,60,80,42};

	int i;
	for(i=0;i<8;i++){
	root=insertInBST(root,array[i]);
	}*/

/*
	traverseLevelorderBinaryTree(root);
	deleteInBST(root,30);
	printf("\n");
	traverseLevelorderBinaryTree(root);
*/

/*
	traverseLevelorderBinaryTree(root);
	printf("%s",searchInBST(root,40)?"YES":"NO");
*/

/*
    traverseLevelorderBinaryTree(root);
	struct BinaryTreeNode* min=minimumInBST(root);
	printf("min=%d",min?min->data:-1);
*/

/*
	traverseLevelorderBinaryTree(root);
	struct BinaryTreeNode* max=maximumInBSTRecursive(root);
	printf("max=%d",max?max->data:-1);
*/

/*
	traverseLevelorderBinaryTree(root1);
	printf("is binary tree a BST =%s",isBinaryTreeABSTRecursive(root1)?"YES":"NO");
*/

/*
	traverseLevelorderBinaryTree(root1);
	struct BinaryTreeNode* prev=NULL;
	printf("is binary tree a BST =%s",isBinarytreeABSTByinordertraversalRecursive(root1,&prev)?"YES":"NO");
*/

/*
	traverseLevelorderBinaryTree(root1);
	printf("is binary tree a BST =%s",isABSTByMinMaxRecursive(root1,INT_MIN,INT_MAX)?"YES":"NO");
*/

/*
	traverseLevelorderBinaryTree(root1);
	printf("is binary tree a BST =%s",isABSTBySuccAndPredecRecursive(root1,NULL,NULL)?"YES":"NO");
*/

/*
	traverseLevelorderBinaryTree(root);
	struct BinaryTreeNode *predecessor,*succesor;
	predecessor=succesor=NULL;
	getInorderSuccessorAndPredecessorInBSTRecursive(root,&predecessor,&succesor,50);
	printf("\npredecessor=%d,successor=%d",predecessor?predecessor->data:-1,succesor?succesor->data:-1);
*/

/*
	traverseLevelorderBinaryTree(root);
	struct BinaryTreeNode* node=root->right->left;
	struct BinaryTreeNode* successor=getInorderSuccessorInBST(root,node);
	printf("\n inorder successor of %d is =%d",node->data,successor?successor->data:-1);
*/

/*
	traverseLevelorderBinaryTree(root);
	printf("node with value %d has level=%d",42,getLevelOfAKeyInBST(root,50));
*/

/*
	traverseLevelorderBinaryTree(root);
	struct BinaryTreeNode* lca=getlowestCommonAncestorInBSTRecursive(root,20,30);
	printf("lca=%d\n",lca?lca->data:-1);
*/

/*
	traverseLevelorderBinaryTree(root);
	struct BinaryTreeNode* lca = getLowestCommonAncestorBST(root, 20, 30);
	printf("lca=%d\n", lca ? lca->data : -1);
*/

/*
	traverseLevelorderBinaryTree(root);
	struct BinaryTreeNode* smallestNode = NULL;
    kthSmallestNodeInBST(root,3,&smallestNode);
	printf("k=%d smallest node value=%d\n", 3,smallestNode ? smallestNode->data : -1);
*/

/*
	traverseLevelorderBinaryTree(root);
	struct BinaryTreeNode* largestNode = NULL;
	kthLargestNodeInBST(root, 3, &largestNode);
	printf("k=%d largest node value=%d", 3,largestNode ? largestNode->data : -1);
*/

/*
	traverseLevelorderBinaryTree(root);
	struct BinaryTreeNode* ceilNode=ceilInBSTMethod2(root,41);
	printf("\nceil=%d",ceilNode?ceilNode->data:-1);

	struct BinaryTreeNode* floorNode=floorInBST(root,41);
	printf("\nfloor=%d",floorNode?floorNode->data:-1);
*/

/*
	traverseInorderBinaryTree(root);	printf("\n");
	traverseInorderBinaryTree(rooty);	printf("\n");
	struct BinaryTreeNode* finalBST=MergeTwoBSTByRecursiveInorderTraversal(root,rooty);
	traverseInorderBinaryTree(finalBST);
*/

/*
	traverseInorderBinaryTree(root);printf("\n");
	traverseInorderBinaryTree(rooty);printf("\n");
	struct BinaryTreeNode* finalBST = MergeTwoBSTByNonRecursiveInorderTraversal(root, rooty);
	traverseInorderBinaryTree(finalBST);
*/

/*
	traverseInorderBinaryTree(wrongBST);printf("\n");
	struct BinaryTreeNode* rightBST=NULL;
	fixForTwoNodeSwappedWronglyinBST(wrongBST,&rightBST);
	traverseInorderBinaryTree(rightBST);
*/
/*

	traverseInorderBinaryTree(wrongBST);
	printf("\n");
	fixForTwoNodeSwappedWronglyinBSTOptimized(wrongBST);
	traverseInorderBinaryTree(wrongBST);
*/

/*
	traverseLevelorderBinaryTree(root);printf("\n");
	printf("is pair present with target of %d: %s",100,isPairPresentWithTargetSumInBST(root,100)?"YES\n":"NO\n");
*/


/*
	traverseInorderBinaryTree(root);printf("\n");
	int val=isPairPresentWithTargetSumInBSTOptimized(root,71);
	printf("%s",val?"YES":"NO");
*/



/*	int arr[]={1,2,3,4,5,6,7,8};
	struct BinaryTreeNode* balanceBST=sortedArrayConversionToBalanceBST(arr,0,7);
	//traverseInorderBinaryTree(balanceBST);
	traverseLevelorderBinaryTree(balanceBST);*/

/*
	traverseLevelorderBinaryTree(binaryTree);
	printf("\n");
	traverseInorderBinaryTree(binaryTree);
	struct BinaryTreeNode* btToBST=binaryTreeConversionToBSTWithoutChangingStructure(binaryTree);
	printf("\n");
	traverseLevelorderBinaryTree(btToBST);
	printf("\n");
	traverseInorderBinaryTree(btToBST);
*/

/*
	int pre[]={10,5,1,7,40,50};
	int size=6;
	struct BinaryTreeNode* r=buildBSTFromPreorderTraversal(pre,size);
	traverseInorderBinaryTree(r);
*/

/*
	int pre[]={20,10,11,13,12};
	int size=5;
	struct BinaryTreeNode* r=buildBSTFromPreorderTraversalRecursive(pre,0,size-1);
	traverseLevelorderBinaryTree(r);
*/

/*
	int pre[]={10,5,1,7,40,50};
	int size=6;
	struct BinaryTreeNode* r=buildBSTFromPreorderTraversalOptimized2(pre,size);
	traverseInorderBinaryTree(r);
*/

/*
	int pre[]={10,5,1,7,40,50};
	int size=6;
	struct BinaryTreeNode* r=buildBSTFrompPeorderTraversalIterative(pre,size);
	traverseInorderBinaryTree(r);
*/


/*
	             10
	            /  \
	           5    40
	          /\	  \
	         1  7     50
*/
/*


	struct BinaryTreeNode* bst=getBinaryTreeNode(10);
	bst->left = getBinaryTreeNode(5);
	bst->left->left = getBinaryTreeNode(1);
	bst->left->right = getBinaryTreeNode(7);
	bst->right = getBinaryTreeNode(40);
	bst->right->right = getBinaryTreeNode(50);

	traverseLevelorderBinaryTree(bst);
	printf("\n");
	getBTreeFromBSTByAddingSumOfAllGreaterKeysToEveryKey(bst);
	traverseLevelorderBinaryTree(bst);
*/

/*
	struct LinkListNode* list=getNewLinkListNode(1);
	list->next=getNewLinkListNode(2);
	list->next->next=getNewLinkListNode(3);
	list->next->next->next=getNewLinkListNode(4);
	list->next->next->next->next=getNewLinkListNode(5);
	list->next->next->next->next->next=getNewLinkListNode(6);
	list->next->next->next->next->next->next=getNewLinkListNode(7);

	struct BinaryTreeNode* r=buildBSTFromSortedLinkList(list);
	traverseLevelorderBinaryTree(r);
*/

/*
	struct BinaryTreeNode* bst = getBinaryTreeNode(11);
	bst->left = getBinaryTreeNode(2);
	bst->left->left = getBinaryTreeNode(1);
	bst->left->right = getBinaryTreeNode(7);

	bst->right = getBinaryTreeNode(29);
	bst->right->left = getBinaryTreeNode(15);
	bst->right->right = getBinaryTreeNode(40);
	bst->right->right->left = getBinaryTreeNode(35);

	traverseLevelorderBinaryTree(bst);
	printf("\n");
	transformBSTByReplacingEveryKeyWithSumOfAllGreaterKeys(bst);
	traverseLevelorderBinaryTree(bst);
*/

/*
	struct BinaryTreeNode* bst = getBinaryTreeNode(8);
	bst->left = getBinaryTreeNode(4);
	bst->left->left = getBinaryTreeNode(2);
	bst->left->right = getBinaryTreeNode(6);

	bst->right = getBinaryTreeNode(12);
	bst->right->left = getBinaryTreeNode(10);
	bst->right->right = getBinaryTreeNode(14);

	traverseLevelorderBinaryTree(bst);
	inPlaceConvertBSTToMinHeap(bst);
	traverseLevelorderBinaryTree(bst);
*/

/*
	int levelOrder[]={7,4,12,3,6,8,1,5,10};
	int size=9;
	struct BinaryTreeNode* r=buildBSTFRomLevelOrderTraversal(levelOrder,size);

	traverseLevelorderBinaryTree(r);
*/
/*
	struct BinaryTreeNode* bst = getBinaryTreeNode(4);
	bst->left = getBinaryTreeNode(3);
	bst->left->left = getBinaryTreeNode(1);
	bst->left->right = getBinaryTreeNode(2);

	bst->right = getBinaryTreeNode(5);
	bst->right->right = getBinaryTreeNode(6);
	bst->right->right->right = getBinaryTreeNode(8);

	int subSeq[]={2,4,7};
	int size=3;
	int count=0;
	printf("is subseq exist=%d",isSortedSubSequenceExistInBST(bst,subSeq,size,&count));
*/

/*
	int pre[]={20,10,11,12};
	int size=4;

	printf("is having one child only in internal nodes=%d\n",isBSTInternalNodesHavingSingleChild(pre,size));
	printf("is having one child only in internal nodes=%d\n",isBSTInternalNodesHavingSingleChildOptimized(pre,size));
	printf("is having one child only in internal nodes=%d\n",isBSTInternalNodesHavingSingleChildOptimized2(pre,size));

*/
/*
	struct BinaryTreeNode* bst = getBinaryTreeNode(8);
	bst->left = getBinaryTreeNode(5);
	bst->left->left = getBinaryTreeNode(2);
	bst->left->right = getBinaryTreeNode(7);
	bst->left->left->left = getBinaryTreeNode(1);

	bst->right = getBinaryTreeNode(9);



	printf("is dead end exit=%d",isDeadEndExistInBST(bst));
*/

/*
	int array[]={4,2,5,1,3};//
	int size=5;

	sortArrayWhichRepresentLevelOrderTraversalOfBST(array,0,size-1);
*/
/*
	struct BinaryTreeNode* bst = getBinaryTreeNode(20);
	bst->left = getBinaryTreeNode(8);
	bst->left->left = getBinaryTreeNode(4);
	bst->left->right = getBinaryTreeNode(12);

	bst->right = getBinaryTreeNode(22);



	getSortedKeysOfBSTFromGivenRange(bst,10,22);
	printf("\n");
	getSortedKeysOfBSTFromGivenRangeOptimized(bst,10,22);
*/

/*
	struct BinaryTreeNode* tree = getBinaryTreeNode(5);
	tree->left = getBinaryTreeNode(2);
	tree->left->left = getBinaryTreeNode(1);
	tree->left->right = getBinaryTreeNode(3);

	tree->right = getBinaryTreeNode(4);

	struct BinaryTreeNode* tree2 = getBinaryTreeNode(50);
	tree2->left = getBinaryTreeNode(30);
	tree2->left->left = getBinaryTreeNode(5);
	tree2->left->right = getBinaryTreeNode(20);

	tree2->right = getBinaryTreeNode(60);
	tree2->right->left = getBinaryTreeNode(45);
	tree2->right->right = getBinaryTreeNode(70);
	tree2->right->right->left = getBinaryTreeNode(65);
	tree2->right->right->right = getBinaryTreeNode(80);

	printf("size of max BST=%d\n",getMaxSizeOfBSTPresentInBinaryTree(tree2));
*/

/*
	struct BinaryTreeNode* tree = getBinaryTreeNode(6);
	tree->left = getBinaryTreeNode(-13);
	tree->left->right = getBinaryTreeNode(-8);


	tree->right = getBinaryTreeNode(14);
	tree->right->left = getBinaryTreeNode(13);
	tree->right->left->left = getBinaryTreeNode(7);
	tree->right->right = getBinaryTreeNode(15);
	traverseLevelorderBinaryTree(tree);
	printf("is triplet present=%d",isTripletpresentInBST(tree,0));
	printf("\nis triplet present=%d",isTripletpresentInBSTOptimized(tree,0));
*/
/*
	struct BinaryTreeNode* tree = getBinaryTreeNode(6);
	tree->left = getBinaryTreeNode(-13);
	tree->left->right = getBinaryTreeNode(-8);


	tree->right = getBinaryTreeNode(14);
	tree->right->left = getBinaryTreeNode(13);
	tree->right->left->left = getBinaryTreeNode(7);
	tree->right->right = getBinaryTreeNode(15);
	traverseLevelorderBinaryTree(tree);

	tree=deleteNodesOutsideOfGivenRangeinBST(tree,7,14);
	traverseLevelorderBinaryTree(tree);
*/
/*
	struct BinaryTreeNode* tree = getBinaryTreeNode(6);
	tree->left = getBinaryTreeNode(-13);
	tree->left->right = getBinaryTreeNode(-8);


	tree->right = getBinaryTreeNode(14);
	tree->right->left = getBinaryTreeNode(13);
	tree->right->left->left = getBinaryTreeNode(7);
	tree->right->right = getBinaryTreeNode(15);
	traverseLevelorderBinaryTree(tree);

	tree=deleteNodesOutsideOfGivenRangeinBSTOptimized(tree,7,14);
	traverseLevelorderBinaryTree(tree);
*/
/*
	struct BinaryTreeNode* tree = getBinaryTreeNode(10);
	tree->left = getBinaryTreeNode(5);
	tree->left->left = getBinaryTreeNode(1);


	tree->right = getBinaryTreeNode(50);
	tree->right->left = getBinaryTreeNode(40);
	tree->right->right = getBinaryTreeNode(100);
	traverseLevelorderBinaryTree(tree);

	int count=0;
	getCountOfNodesInGivenRangeBST(tree,5,45,&count);
	printf("count=%d\n",count);

	printf("count=%d",getCountOfNodesInGivenRangeBSTOptimized(tree,5,45));
*/
/*
	struct Interval in[] ={ {1, 5}, {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}};
	int size=6;
	getAllConflictingAppointments(in,size);
*/
/*

	struct BinaryTreeNode* tree = getBinaryTreeNode(10);
	tree->left = getBinaryTreeNode(5);
	tree->left->left = getBinaryTreeNode(1);

	tree->right = getBinaryTreeNode(50);
	tree->right->left = getBinaryTreeNode(40);
	tree->right->right = getBinaryTreeNode(100);
	traverseLevelorderBinaryTree(tree);

	printf("count=%d",getCountOdSubtreeLiesinGivenRangeInBST(tree,1,100));
*/

/*
	struct BinaryTreeNode* tree = getBinaryTreeNode(20);
	tree->left = getBinaryTreeNode(8);
	tree->left->left = getBinaryTreeNode(4);
	tree->left->right = getBinaryTreeNode(12);
	tree->left->right->left = getBinaryTreeNode(10);
	tree->left->right->right = getBinaryTreeNode(14);

	tree->right = getBinaryTreeNode(22);

	traverseLevelorderBinaryTree(tree);

	printf("median of bst=%d",getMedianOfBST(tree));

*/
/*
	struct BinaryTreeNode* tree = getBinaryTreeNode(20);
	tree->left = getBinaryTreeNode(10);
	tree->left->left = getBinaryTreeNode(5);
	tree->left->right = getBinaryTreeNode(15);


	tree->right = getBinaryTreeNode(30);
	tree->right->left= getBinaryTreeNode(25);
	tree->right->right = getBinaryTreeNode(35);

	tree=deleteAllLeafNodesOfBST(tree);
	traverseLevelorderBinaryTree(tree);
*/

/*
	int pre[]={20,10,5,15,14,17,30,25,35};
	int size=9;
	getAllLeafNodesFromPreOrderTraversal(pre,size);
	printf("\n");
	getAllLeafNodesFromPreOrderTraversalOptimized(pre,size);
*/
/*
	struct BinaryTreeNode* tree = getBinaryTreeNode(5);
	tree->left = getBinaryTreeNode(2);
	tree->left->left = getBinaryTreeNode(1);
	tree->left->right = getBinaryTreeNode(3);


	tree->right = getBinaryTreeNode(12);
	tree->right->left= getBinaryTreeNode(9);
	tree->right->right = getBinaryTreeNode(21);
	tree->right->right->left = getBinaryTreeNode(19);
	tree->right->right->right = getBinaryTreeNode(25);

	printf("distance btw nodes=%d",getDistanceBetweenTwoNodes(tree,1,25));
*/
/*
	struct BinaryTreeNode* bst1 = getBinaryTreeNode(5);
	bst1->left = getBinaryTreeNode(3);
	bst1->left->left = getBinaryTreeNode(2);
	bst1->left->right = getBinaryTreeNode(4);

	bst1->right = getBinaryTreeNode(7);
	bst1->right->left= getBinaryTreeNode(6);
	bst1->right->right = getBinaryTreeNode(8);

	struct BinaryTreeNode* bst2 = getBinaryTreeNode(10);
	bst2->left = getBinaryTreeNode(6);
	bst2->left->left = getBinaryTreeNode(3);
	bst2->left->right = getBinaryTreeNode(8);

	bst2->right = getBinaryTreeNode(15);
	bst2->right->left= getBinaryTreeNode(11);
	bst2->right->right = getBinaryTreeNode(18);

	traverseLevelorderBinaryTree(bst1);
	traverseLevelorderBinaryTree(bst2);
	printf("count of pairs=%d",getCountOfPairsWithGivenSumInBST(bst1,bst2,16));

*/

/*
	int array[]={ 18, 36, 9, 6, 12, 10, 1, 8 } ;
	int size=8;
	struct BinaryTreeNode* bst=NULL;
	for(int i=0;i<size;i++){
		bst=insertWithparentPointerInBST(bst,array[i]);
	}
	traverseLevelorderBinaryTree(bst);
	printf("max node on path=%d\n",getMaxNodeOnPathinBST(bst,1,10));

	printf("max node on path=%d",getMaxNodeOnPathinBSTOptimized(bst,1,10));
*/
/*
	struct BinaryTreeNode* bst1 = getBinaryTreeNode(9);
	bst1->left = getBinaryTreeNode(4);
	bst1->left->left = getBinaryTreeNode(3);
	bst1->left->right = getBinaryTreeNode(6);
	bst1->left->right->right = getBinaryTreeNode(7);

	bst1->right = getBinaryTreeNode(17);
	bst1->right->right= getBinaryTreeNode(22);
	bst1->right->right->left = getBinaryTreeNode(20);

	traverseLevelorderBinaryTree(bst1);
	printf("closest node %d",getClosestElementInBST(bst1,12));
*/

/*
	int array[]={8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
	int size=sizeof(array)/sizeof(array[0]);
	replaceElementWithLeastGreaterElementOnRight(array,size);

	for(int i=0;i<size;i++){
		printf("%d ",array[i]);
	}
*/

/*
	struct BinaryTreeNode* bst1 = getBinaryTreeNode(5);
	bst1->left = getBinaryTreeNode(1);
	bst1->left->left = getBinaryTreeNode(0);
	bst1->left->right = getBinaryTreeNode(4);

	bst1->right = getBinaryTreeNode(10);
	bst1->right->left = getBinaryTreeNode(7);
	bst1->right->left->right = getBinaryTreeNode(9);

	struct BinaryTreeNode* bst2 = getBinaryTreeNode(10);
	bst2->left = getBinaryTreeNode(7);
	bst2->left->left = getBinaryTreeNode(4);
	bst2->left->right = getBinaryTreeNode(9);

	bst2->right = getBinaryTreeNode(20);

	getCommonNodesFromTwoBST(bst1,bst2);
*/

	return EXIT_SUCCESS;
}

