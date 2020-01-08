/*
 * commonDeclarations.h
 *
 *  Created on: 28-May-2018
 *      Author: anurag
 */


#ifndef commondef

#define commondef

struct LinkListNode{
	int data;
	struct LinkListNode *next;
	struct LinkListNode* down;
};

struct LinkListWithBtreeNode{
	struct BinaryTreeNode *data;
	struct LinkListWithBtreeNode *next;
	int min;
	int max;
};



struct BinaryTreeNode{

	int data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
	struct BinaryTreeNode *nextRight;
	struct BinaryTreeNode *parent;
};

#endif
