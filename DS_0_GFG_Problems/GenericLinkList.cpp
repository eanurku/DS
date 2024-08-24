/*
 ============================================================================
 Name        : LinkList-GenericLinkList.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


struct GenericLinkListNode{
	void *data;
	struct GenericLinkListNode *next;
};

void insertAtStart(struct GenericLinkListNode **headRef,void * element ,int sizeOfDataType){

	struct GenericLinkListNode *tmp=(struct GenericLinkListNode *)malloc(sizeof(struct GenericLinkListNode));

		tmp->data=malloc(sizeOfDataType);
		memcpy(tmp->data,element,sizeOfDataType);

		tmp->next=*headRef;
		*headRef=tmp;

}
void printInt(void *data){

	printf("%d ",*(int *)data);
}
void printChar(void *data){

	printf("%c ",*(char *)data);
}
void printLinkList(struct GenericLinkListNode *head,void (*fptr)(void *)){

	struct GenericLinkListNode *ptr=head;
	while(ptr){
		fptr(ptr->data);
		ptr=ptr->next;
	}
}
int main(void) {


	struct GenericLinkListNode *head=NULL;
	int i;
	int array1[]={2,3,4};
	for(i=0;i<3;i++)
		insertAtStart(&head,&array1[i],sizeof(array1[0]));
	printLinkList(head,printInt);
	head=NULL;
	printf("\n");
	char array2[]={'A','B','C'};
	for(i=0;i<3;i++)
			insertAtStart(&head,&array2[i],sizeof(array2[0]));
		printLinkList(head,printChar);



	return EXIT_SUCCESS;
}
