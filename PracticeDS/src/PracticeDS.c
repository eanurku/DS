/*
 ============================================================================
 Name        : PracticeDS.c
 Author      : Anurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct LinkListNode{
	int data;
	struct LinkListNode *next;
	struct LinkListNode* down;
};

void insertAtFrontLinkList(struct LinkListNode **headRef,int key){

	struct LinkListNode *node=(struct LinkListNode *)malloc(sizeof(struct LinkListNode));
	node->data=key;
	node->next=*headRef;
	*headRef=node;
}
void printLinklist(struct LinkListNode *headPtr){

	while(headPtr!=NULL){

		printf("%d%s",headPtr->data,headPtr->next!=NULL?"->":"->NULL");
		headPtr=headPtr->next;
	}
	printf("\n");
}
struct LinkListNode* mergeSortedLinkListRecursive(struct LinkListNode *listA,struct LinkListNode* listB){

	struct LinkListNode *finalList=NULL;
	if(listA==NULL){
		return listB;
	}else if(listB==NULL){
		return listA;
	}

	if(listA->data<=listB->data){

		finalList=listA;
		finalList->next=mergeSortedLinkListRecursive(listA->next,listB);
	}else{
		finalList=listB;
		finalList->next=mergeSortedLinkListRecursive(listA,listB->next);
	}

	return finalList;
}
int main(void) {

    struct LinkedListNode *listA=NULL;
    struct LinkedListNode *listB=NULL;

    insertAtFrontLinkList(&listA,30);
    insertAtFrontLinkList(&listA,20);
    insertAtFrontLinkList(&listA,10);
    insertAtFrontLinkList(&listA,3);
    insertAtFrontLinkList(&listA,2);
    insertAtFrontLinkList(&listA,1);


    insertAtFrontLinkList(&listB,22);
    insertAtFrontLinkList(&listB,17);
    insertAtFrontLinkList(&listB,13);
    insertAtFrontLinkList(&listB,11);


    printLinklist(listA);
    printf("\n");
    printLinklist(listB);
    printf("\n");
    printLinklist(mergeSortedLinkListRecursive(listA,listB));


	return EXIT_SUCCESS;
}
