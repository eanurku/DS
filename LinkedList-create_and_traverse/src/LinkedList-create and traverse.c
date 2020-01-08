/*
 ============================================================================
 Name        : LinkedList-create.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
	int info;
	struct node *next;
};

void traversLinkList(struct node *ptr){

	while(ptr!=NULL){

	    	printf("%d%s",ptr->info,ptr->next!=NULL?",":"");
	    	ptr=ptr->next;
	    }
}
int main(void) {


	struct node *first=(struct node *)malloc(sizeof(struct node));
	struct node *second=(struct node *)malloc(sizeof(struct node));
	struct node *third=(struct node *)malloc(sizeof(struct node));


	first->info=1;
    first->next=second;
    second->info=2;
    second->next=third;
    third->info=3;
    third->next=NULL;


    traversLinkList(first);



	return EXIT_SUCCESS;
}
