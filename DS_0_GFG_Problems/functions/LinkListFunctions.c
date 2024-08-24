/*
 ============================================================================
 Name        : linklist.c
 Author      : kanurag@
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "commonDeclarations.h"

struct LinkListNode* getNewLinkListNode(int val) {

	struct LinkListNode *tmp = (struct LinkListNode*) malloc(sizeof(struct LinkListNode));

	tmp->data = val;
	tmp->next = NULL;
	tmp->down = NULL;
	return tmp;
}


void insertAtFrontLinkList(struct LinkListNode **headRef,int key){

	struct LinkListNode *LinkListNode=(struct LinkListNode *)malloc(sizeof(struct LinkListNode));
	LinkListNode->data=key;LinkListNode->next=*headRef;

	*headRef=LinkListNode;
}
void printLinklist(struct LinkListNode *headPtr){

	while(headPtr!=NULL){

		printf("%d%s",headPtr->data,headPtr->next!=NULL?"->":"->NULL");
		headPtr=headPtr->next;
	}
	printf("\n");
}

int sizeOfLinkListRecursive(struct LinkListNode *ptr){

	if(ptr==NULL){
		return 0;
	}

	return 1+sizeOfLinkListRecursive(ptr->next);
}
void reverseLinkList(struct LinkListNode **headRef){

	struct LinkListNode *fwd,*curr,*prev;
		prev=NULL;
		fwd=curr=*headRef;

		while(curr!=NULL){

			fwd=fwd->next;
			curr->next=prev;
			prev=curr;
			curr=fwd;
		}

		*headRef=prev;
}

struct LinkListNode* mergeSortedLinkList(struct LinkListNode* listA,struct LinkListNode* listB){

	struct LinkListNode *dummy=(struct LinkListNode *)malloc(sizeof(struct LinkListNode));

	dummy->data=0;
	dummy->next=NULL;
	struct LinkListNode *head=dummy;

	while(1){
		if(listA==NULL){
			head->next=listB;break;
		}
		if(listB==NULL){
			head->next=listA;break;
		}

		if(listA->data<= listB->data){
			head->next=listA;
			listA=listA->next;
		}else{
			head->next=listB;
			listB=listB->next;
		}

		head=head->next;
		head->next=NULL;
	}
	return(dummy->next);
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
void rotateCounterClockwiseLinkList(struct LinkListNode **headRef, int k) {

	struct LinkListNode* curr = *headRef;

	while (k > 1 && curr != NULL) {

		curr = curr->next;
		k--;
	}

	if (curr == NULL || curr->next == NULL) {
		return;
	}
	struct LinkListNode* KthLinkListNodePtr = curr;

	//curr will become last LinkListNode pointer
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = *headRef;
	*headRef = KthLinkListNodePtr->next;
	KthLinkListNodePtr->next = NULL;
}
void removeLoopInLinkList(struct LinkListNode* head,struct LinkListNode* loopLinkListNode){

	struct LinkListNode* ptr1=head;
	struct LinkListNode* ptr2 ;

	while(ptr1){
		ptr2=loopLinkListNode;
		while(ptr2->next!=loopLinkListNode && ptr2->next!=ptr1){
			ptr2=ptr2->next;
		}
		if(ptr1 == ptr2->next){
			ptr2->next=NULL;
			break;
		}
		ptr1=ptr1->next;
	}

}
int isLoopExistThenRemoveitLinkList(struct LinkListNode* head){

    if(head ==NULL){

    	return 0;
    }
	struct LinkListNode* slowptr=head,*fastPtr=head->next;

	while(slowptr && fastPtr && fastPtr->next){

		if(slowptr==fastPtr){
			removeLoopInLinkList(head,slowptr);
			return 1;
		}
		slowptr=slowptr->next;
		fastPtr=fastPtr->next->next;
	}

	return 0;
}
struct LinkListNode* reverseInGroupOfSizeKLinkList(struct LinkListNode* head,int k){


	struct LinkListNode *save=NULL,*ptr=head,*curr=head;

	int count=1;
	while(count<=k && curr){

		curr=curr->next;
		ptr->next=save;
		save=ptr;
		ptr=curr;
		count++;
	}
	if(curr!=NULL){
		head->next=reverseInGroupOfSizeKLinkList(curr,k);
	}
	return save;
}
struct LinkListNode* AddTwoLinkListRecursive(struct  LinkListNode* listA,struct LinkListNode* listB,int carry){

	struct LinkListNode* result=(struct LinkListNode*)malloc(sizeof(struct LinkListNode));;
	int sum;

	if(listA==NULL && listB==NULL){
		if(!carry){
			return NULL;
		}
		result->data=carry;
		result->next=NULL;
		return result;
	}
	sum=(listA!=NULL?listA->data:0)+(listB!=NULL?listB->data:0)+carry;
	carry=sum/10;
	result->data=sum%10;

	result->next = (
			listA == NULL ?
					AddTwoLinkListRecursive(NULL, listB->next, carry) :
					(listB == NULL ?
							AddTwoLinkListRecursive(listA->next, NULL, carry) :
							AddTwoLinkListRecursive(listA->next, listB->next, carry)));

	return result;
}

struct LinkListNode* AddTwoLinkList(struct LinkListNode* listA,struct LinkListNode* listB){

	struct LinkListNode* result=NULL,*ptr;
	int carry=0,sum;

	while(listA!=NULL || listB!=NULL){

		sum=(listA?listA->data:0) + (listB?listB->data:0) +carry;
		carry=sum/10;
		struct LinkListNode* tmp=(struct LinkListNode*)malloc(sizeof(struct LinkListNode));
		tmp->data=sum%10;
		tmp->next=NULL;

		if(result==NULL){

			result=tmp;
		}else{
			ptr->next=tmp;
		}
		ptr=tmp;

		if(listA){
			listA=listA->next;
		}
		if(listB){
			listB=listB->next;
		}
	}

	if (carry) {

		struct LinkListNode* tmp = (struct LinkListNode*) malloc(sizeof(struct LinkListNode));
		tmp->data = sum % 10;
		tmp->next = NULL;

		ptr->next=tmp;
	}


	return result;
}

void splitLinkList(struct LinkListNode* head,struct LinkListNode** a,struct LinkListNode** b){

	struct LinkListNode *slow,*fast;
	if(head==NULL||head->next==NULL){

		*a=head;
		*b=NULL;
		return;
	}

	slow=head;
	fast=head->next;
	while(slow && fast && fast->next){

		slow=slow->next;
		fast=fast->next->next;
	}

	*a=head;
	*b=slow->next;
	slow->next=NULL;
}
struct LinkListNode * mergeSortOfLinkList(struct LinkListNode* head){

	struct LinkListNode *a=NULL,*b=NULL;

	if(head==NULL||head->next==NULL){
		return head;
	}

	splitLinkList(head,&a,&b);

	a=mergeSortOfLinkList(a);
	b=mergeSortOfLinkList(b);

	head=mergeSortedLinkListRecursive(a,b);
	return head;
}

