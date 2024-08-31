/*
 * StackAsLinkList.cpp
 *
 *  Created on: Aug 31, 2024
 *      Author: anura
 */

#include <iostream>
using namespace std;

struct LinkListNode{
	int data;
	struct LinkListNode *next;
	struct LinkListNode* down;
};

int pushToStackAsLinkList(struct LinkListNode **top,int val);
int popFromStackAsLinkList(struct LinkListNode **top);
int isEmptyStackAsLinkList(struct LinkListNode * top);
int sizeOfStackAslinkList(struct LinkListNode * top);


int sizeOfStackAslinkList(struct LinkListNode *top){

	struct LinkListNode *ptr=top;
	int size=0;
	while(ptr){

		size++;
		ptr=ptr->next;
	}
	return size;
}
int isEmptyStackAsLinkList(struct LinkListNode * top){

	return top==NULL;
}
int pushToStackAsLinkList(struct LinkListNode **top,int val){

	struct LinkListNode* newNode=(struct LinkListNode*)malloc(sizeof(struct LinkListNode));
	newNode->data=val;
	newNode->next=(*top);
	*top=newNode;
	return 1;

}

int popFromStackAsLinkList(struct LinkListNode **top){

	if(isEmptyStackAsLinkList(*top)){
		printf("underflow:stack empty  ");
		return INT_MIN;
	}
	struct LinkListNode *deletedNode=(*top);
	(*top)=(*top)->next;
	int retVal=deletedNode->data;

	free(deletedNode);
	deletedNode->next=NULL;



	return retVal;
}

int main(){


	cout<<"wtff..";

	return 0;
}


