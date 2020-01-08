/*
 ============================================================================
 Name        : BinarySearchTreeCSDOperations.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct nodeBST{

	struct nodeBST *left;
	struct nodeBST *right;
	int data;
};

struct nodeBST * getnewNodeBST(int value){

	struct nodeBST *newNode=(struct nodeBST * )malloc(sizeof(struct nodeBST));
	newNode->data=value;
	newNode->left=NULL;
	newNode->right=NULL;

	return newNode;
}

struct nodeBST * insertBST(struct nodeBST *root,int value){
	if(root==NULL){
       return getnewNodeBST(value);
	}
	else if (value<root->data){
		root->left=insertBST(root->left,value);

	}
	else{
		root->right=insertBST(root->right,value);
	}

	return root;
}

traversePreorderBST(struct nodeBST *ptr) {
	if (ptr != NULL) {
		printf("%d,", ptr->data);
		traversePreorderBST(ptr->left);
		traversePreorderBST(ptr->right);
	}
}
int searchBST(struct nodeBST *root, int key) {

	if (root != NULL) {
		if (root->data == key) {
			return 1;
		} else if (key < root->data) {

			return searchBST(root->left, key);
		} else {
			return searchBST(root->right, key);
		}
	}

	return 0;
}
struct nodeBST * minValueBST(struct nodeBST *root){

	struct nodeBST *curr=root;
	while(curr->left !=NULL){
		curr=curr->left;
	}
	return curr;
}
deleteNodeBST(struct nodeBST *root, int key) {

	if (root != NULL) {
		if (key < root->data) {

			root->left = deleteNodeBST(root->left, key);
		} else if (key < root->data) {
			root->right = deleteNodeBST(root->right, key);
		} else {

			if (root->left == NULL) {

				struct nodeBST *tmp = root->right;
                free(root);
				return tmp;
			} else if (root->right == NULL) {
				struct nodeBST *tmp = root->left;
				free(root);
				return tmp;
			}

			struct nodeBST *tmp = minValueBST(root->right);
			root->data = tmp->data;
			root->right = deleteNodeBST(root->right, tmp->data);

		}
	}
	return root;
}


int main(void) {

struct nodeBST *root=NULL;
root=insertBST(root,4);
insertBST(root,3);
insertBST(root,5);
insertBST(root,8);
insertBST(root,7);

printf("search key result=%d\n",searchBST(root,3));
printf("tree before deletion\n");
traversePreorderBST(root);

root=deleteNodeBST(root,4);
printf("\ntree after deletion\n");
traversePreorderBST(root);

printf("min=%d",minValueBST(root)->data);


	return EXIT_SUCCESS;
}
