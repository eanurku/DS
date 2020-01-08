/*
 ============================================================================
 Name        : BinaryTree-Create.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node * getNewNode(int value){

	struct node *newNode =(struct node *)malloc(sizeof(struct node));
	newNode->data=value;
	newNode->left=(void *)0;
	newNode->right=(void *)0;

	return newNode;
}

struct node * addToTree(struct node *root,int val){

	if(root==NULL){
		struct node *newNode =(struct node *)malloc(sizeof(struct node));
			newNode->data=val;
			newNode->left=(void *)0;
			newNode->right=(void *)0;

			return newNode;
	}
	else {

		if(val< root->data ){
			root->left=addToTree(root->left,val);
		}
		else{
			root->right=addToTree(root->right,val);

		}

	}
return root;
}

traverseBinaryTree(struct node *ptr){
	if(ptr!=NULL){
		traverseBinaryTree(ptr->left);
		printf("%d,",ptr->data);
		traverseBinaryTree(ptr->right);

	}
}

int getHeightOfBinaryTree(struct node *ptr){

	if(ptr!=NULL){

		int leftTreeHeight=getHeightOfBinaryTree(ptr->left);
		int rightTreeHeight=getHeightOfBinaryTree(ptr->right);

		if(leftTreeHeight>rightTreeHeight){
			return leftTreeHeight+1;
		}
		else
			return rightTreeHeight+1;
	}

	return 0;
}


printGivenLevelTreeNode(struct node *ptr,int level){

	if(ptr!=NULL){
		if(level==1){
			printf("%d,",ptr->data);
		}
		else{
		printGivenLevelTreeNode(ptr->left,level-1);
		printGivenLevelTreeNode(ptr->right,level-1);
		}
	}

}

levelOrderTraversal(struct node *root,int heightOfTree ){
int i;
	for(i=1;i<=heightOfTree;i++){
		printGivenLevelTreeNode(root,i);
	    }
 printf("\n");
}
int main(void) {

	int i,value=10,treeHeight;
	struct node *root=NULL;

	for(i=1;i<10;i+=2){
		root=addToTree(root,i);
	}
	for(i=2;i<=12;i+=2){
		addToTree(root,i);
	}

   treeHeight=getHeightOfBinaryTree(root);

   levelOrderTraversal(root,treeHeight);



	printf("height of tree=%d\n",treeHeight);

}
