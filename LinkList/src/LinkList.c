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
#include <limits.h>
#include "commonDeclarations.h"
#include "/home/anurag/Desktop/CPROGG/DataStructure-geeksforgeeks_workspace/Algorithms/StackFunctions.c"
//function prototypes start

struct LinkListNode* getNewLinkListNode(int val);
void insertAtFrontLinkList(struct LinkListNode **headRef,int key);
void printLinklist(struct LinkListNode *headPtr);
int sizeOfLinkListRecursive(struct LinkListNode *ptr);

void reverseLinkList(struct LinkListNode **headRef);
struct LinkListNode* mergeSortedLinkList(struct LinkListNode* listA,struct LinkListNode* listB);
struct LinkListNode* mergeSortedLinkListRecursive(struct LinkListNode *listA,struct LinkListNode* listB);

void splitLinkList(struct LinkListNode* head,struct LinkListNode** a,struct LinkListNode** b);
struct LinkListNode * mergeSortOfLinkList(struct LinkListNode* head);

void rotateCounterClockwiseLinkList(struct LinkListNode **headRef,int k);

void removeLoopInLinkList(struct LinkListNode* head,struct LinkListNode* loopLinkListNode);
int isLoopExistThenRemoveitLinkList(struct LinkListNode* head);

struct LinkListNode* reverseInGroupOfSizeKLinkList(struct LinkListNode* head,int k);

struct LinkListNode* AddTwoLinkList(struct LinkListNode* listA,struct LinkListNode* listB);
struct LinkListNode* AddTwoLinkListRecursive(struct  LinkListNode* listA,struct LinkListNode* listB,int carry);

void swapTwoNodesInLinkList(struct LinkListNode **headRef,int x,int y);

struct LinkListNode* getNthNodeValueInLinklist(struct LinkListNode* head,int index);
struct LinkListNode* getNthNodeValueInLinklistRecursive(struct LinkListNode* head,int n);
struct LinkListNode* getMiddleNodeOfLinkList(struct LinkListNode* head);
struct LinkListNode* getNthNodeFromEndOfLinkList(struct LinkListNode* head,int n);
void deleteTheLinkList(struct LinkListNode** headref);
int isPalindromeLinkList(struct LinkListNode* head);
void printReverseOfLinkList(struct LinkListNode* head);

void removeConsecutiveDuplicatesFromLinklist(struct LinkListNode** headRef);
struct LinkListNode* getIntersectionOfTwoSortedlinkList(struct LinkListNode* list1,struct LinkListNode* list2);
struct LinkListNode* getIntersectionOfTwoSortedlinkListRecursive(struct LinkListNode* list1,struct LinkListNode* list2);
void deleteAlternateNodesinLinkList(struct LinkListNode** headRef);
void alternateSplitOfLinkList(struct LinkListNode* head);
int areIdenticalLinklistRecursive(struct LinkListNode* list1,struct LinkListNode* list2);

struct LinkListNode* reverseAlternateKNodeinLinkList(struct LinkListNode* head,int k);
void deleteNodeWithGreaterValueInRightLinklist(struct LinkListNode** headRef);
struct LinkListNode* isLoopExistInLinkList(struct LinkListNode* head);
int getLoopSizeInLinkList(struct LinkListNode* head);

struct LinkListNode* flattenLinkList(struct LinkListNode* head);
void getTripletWithGivenSumFromThreeLinkList(struct LinkListNode* list,struct LinkListNode* Ascenlist, struct LinkListNode* desclist,int sum);
void deleteUnderGivenConstraint(struct LinkListNode* head,struct LinkListNode* node) ;
void getSortedlisthavingZeroOneTwoAsElementsLinklist(struct LinkListNode* head);
void getSortedlisthavingZeroOneTwoAsElementsLinklistAlternative(struct LinkListNode* head);




//function prototypes end.
struct LinkListNode* getNewLinkListNode(int val) {

	struct LinkListNode *tmp = (struct LinkListNode*) malloc(sizeof(struct LinkListNode));

	tmp->data = val;
	tmp->next = NULL;
	tmp->down = NULL;
	return tmp;
}
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
void printLinklistDown(struct LinkListNode *headPtr){

	while(headPtr!=NULL){

		printf("%d%s",headPtr->data,headPtr->down!=NULL?"->":"->NULL");
		headPtr=headPtr->down;
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
void swapTwoNodesInLinkList(struct LinkListNode **headRef,int x,int y){

	struct LinkListNode *currX=*headRef,*currY=*headRef,*prevX=NULL,*PrevY=NULL;

	if(!(*headRef) || x==y){
		return;
	}
	while(currX && currX->data!=x){
		prevX=currX;
		currX=currX->next;
	}
	while(currY && currY->data!=y){

		PrevY=currY;
		currY=currY->next;
	}

	if(!currX || !currY){
		return ;
	}

	if(prevX){
		prevX->next=currY;
	}else{
		*headRef=currY;
	}
	if(PrevY){
		PrevY->next=currX;
	}else{
		*headRef=currX;
	}
	struct LinkListNode* tmp=currX->next;
	currX->next=currY->next;
	currY->next=tmp;

}
struct LinkListNode* getNthNodeValueInLinklist(struct LinkListNode* head,int n){


	while(head && n>1){

		head=head->next;
		n--;
	}
	return head;
}

struct LinkListNode* getNthNodeValueInLinklistRecursive(struct LinkListNode* head,int n){

	if(n==1||!head){
		return head;
	}
	return getNthNodeValueInLinklistRecursive(head->next,n-1);
}

struct LinkListNode* getMiddleNodeOfLinkList(struct LinkListNode* head){

	int size=sizeOfLinkListRecursive(head);
	int mid=size/2+1;
	return getNthNodeValueInLinklist(head,mid);
}
struct LinkListNode* getMiddleNodeOfLinkListOptimized(struct LinkListNode* head){

	struct LinkListNode* slow=head;
	struct LinkListNode* fast=head;

	while(slow && fast && fast->next){

		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

struct LinkListNode* getNthNodeFromEndOfLinkList(struct LinkListNode* head,int n){

	int size=sizeOfLinkListRecursive(head);
	int pos=size-n+1;
	return getNthNodeValueInLinklist(head,pos);

}

void deleteTheLinkList(struct LinkListNode** headref){

	struct LinkListNode* head=*headref;
	struct LinkListNode* tmp;
	while(head){
		tmp=head;
		head=head->next;
		tmp->next=NULL;
		free(tmp);
	}
	*headref=NULL;
}

int isPalindromeLinkList(struct LinkListNode* head){

	struct LinkListNode* stack=NULL;
	struct LinkListNode* ptr=head;
	int val;

	while(ptr){

		pushToStackAsLinkList(&stack,ptr->data);
		ptr=ptr->next;
	}
	while(head){

		val=popFromStackAsLinkList(&stack);
		if(head->data!=val){
			return 0;
		}
		head=head->next;
	}
	return 1;
}
void printReverseOfLinkList(struct LinkListNode* head){

	if(!head)
	return ;
	printReverseOfLinkList(head->next);
	printf("%d ",head->data);
}
void removeConsecutiveDuplicatesFromLinklist(struct LinkListNode** headRef){

	struct LinkListNode*  prev=*headRef;
	struct LinkListNode* ptr=prev->next;
	struct LinkListNode* tmp;

	while(ptr){

		tmp=ptr->next;
		if(prev->data==ptr->data){
			prev->next=ptr->next;
			free(ptr);
		}else{
			prev=ptr;
		}
		ptr=tmp;;
	}
}

struct LinkListNode* getIntersectionOfTwoSortedlinkList(struct LinkListNode* list1,struct LinkListNode* list2){

	struct LinkListNode* dummy=(struct LinkListNode*)malloc(sizeof(struct LinkListNode));
	struct LinkListNode* ptr=dummy;

	while(list1 && list2){

		if(list1->data<list2->data){
			list1=list1->next;
		}else if(list1->data>list2->data){

			list2=list2->next;
		}else{

			ptr->next=getNewLinkListNode(list1->data);
			ptr=ptr->next;
			list1=list1->next;
			list2=list2->next;

		}

	}
	return dummy->next;
}
struct LinkListNode* getIntersectionOfTwoSortedlinkListRecursive(struct LinkListNode* list1,struct LinkListNode* list2){

	if(!list1||!list2){
		return NULL;
	}

	if(list1->data<list2->data){
		return getIntersectionOfTwoSortedlinkListRecursive(list1->next,list2);
	}else if(list1->data>list2->data){
		return getIntersectionOfTwoSortedlinkListRecursive(list1,list2->next);
	}

	struct LinkListNode* tmp=getNewLinkListNode(list1->data);
	tmp->next=getIntersectionOfTwoSortedlinkListRecursive(list1->next,list2->next);
	return tmp;
}

void deleteAlternateNodesinLinkList(struct LinkListNode** headRef){

	if(!*headRef){
		return ;
	}
	struct LinkListNode* head=*headRef;
	struct LinkListNode* ptr=head->next;
	struct LinkListNode* tmp;

	while(ptr && head){

		tmp=ptr;
		if(ptr->next)
		ptr=ptr->next->next;
		head->next=tmp->next;
		free(tmp);
		if(head)
		head=head->next;
	}
}

void alternateSplitOfLinkList(struct LinkListNode* head){


	struct LinkListNode* head1=head,*ptr1=head;
	struct LinkListNode* head2=head->next,*ptr2=head->next;

	while(ptr1 && ptr2){

		ptr1->next=ptr2->next;
		ptr1=ptr1->next;
		if(ptr1){
			ptr2->next=ptr1->next;
			ptr2=ptr2->next;
		}
	}

	printLinklist(head1);
	printLinklist(head2);
}
int areIdenticalLinklistRecursive(struct LinkListNode* list1,struct LinkListNode* list2){

	if(!list1 && !list2)
		return 1;
	if(!list1 || !list2)
		return 0;
	if(list1->data!=list2->data)
		return 0;
	return areIdenticalLinklistRecursive(list1->next,list2->next);
}

struct LinkListNode* reverseAlternateKNodeinLinkList(struct LinkListNode* head,int k){


	struct LinkListNode* curr=head;
	struct LinkListNode* ptr=head;
	struct LinkListNode* prev=NULL;

	int count=0;
	while(curr && count<k){

		curr=curr->next;
		ptr->next=prev;
		prev=ptr;
		ptr=curr;
		count++;

	}
	if(head)
	head->next=curr;
	head=prev;
	count=0;
	while(curr && count<k){
		prev=curr;
		curr=curr->next;
		ptr=curr;
		count++;
	}

	if(curr){
		prev->next=reverseAlternateKNodeinLinkList(curr,k);
	}

	return head;

}
void deleteNodeWithGreaterValueInRightLinklist(struct LinkListNode** headRef){

	struct LinkListNode* ptr=*headRef;
	struct LinkListNode* nextptr=ptr->next;
	struct LinkListNode* prev=NULL;

	while (ptr && nextptr) {

		if (ptr->data < nextptr->data) {

			if (ptr == *headRef) {
				*headRef = ptr->next;
			} else {

				prev->next = nextptr;

			}
			free(ptr);
			ptr = nextptr;
			nextptr = nextptr->next;

		} else {

			prev = ptr;
			ptr = nextptr;
			nextptr = nextptr->next;
		}
	}
}

struct LinkListNode* isLoopExistInLinkList(struct LinkListNode* head){

	if(!head) return NULL;
	struct LinkListNode* slow=head;
	struct LinkListNode* fast=head->next;

	while(slow && fast && fast->next){

		if(slow==fast){
			return slow;
		}
		slow=slow->next;
		fast=fast->next->next;
	}

	return NULL;
}

int getLoopSizeInLinkList(struct LinkListNode* head){

	if(!head) return 0;
	struct LinkListNode* loopNode=isLoopExistInLinkList(head);

	struct LinkListNode* ptr=loopNode;

	int count=0;
	while(ptr && ptr->next!=loopNode){
		printf("%d ",ptr->data);
		ptr=ptr->next;
		count++;
	}
	printf("%d ",ptr->data);
	return count+1;
}

struct LinkListNode* mergeSortedDownAndNextList(struct LinkListNode* a,struct LinkListNode* b){

	if(a==NULL)
		return b;
	if(b==NULL)
		return a;

	struct LinkListNode* result=NULL;
	if(a->data<b->data){
		result=a;
		result->down=mergeSortedDownAndNextList(a->down,b);
	}else{
		result=b;
		result->down=mergeSortedDownAndNextList(a,b->down);
	}

	return result;
}
struct LinkListNode* flattenLinkList(struct LinkListNode* head){

	if(!head||!head->next){
		return head;
	}

	return mergeSortedDownAndNextList(head,flattenLinkList(head->next));
}
struct LinkListNode* flattenLinkListUnsorted(struct LinkListNode* head){

	if(!head){
		return NULL;
	}

	struct LinkListNode* lastPtrDown=head;
	while(lastPtrDown->down){

		lastPtrDown=lastPtrDown->down;
	}
	lastPtrDown->down=flattenLinkListUnsorted(head->next);

	return head;

}

void getTripletWithGivenSumFromThreeLinkList(struct LinkListNode* list,struct LinkListNode* Ascenlist, struct LinkListNode* desclist,int sum) {

	struct LinkListNode* ptr1,*ptr2;
	while(list){

		ptr1=Ascenlist;
		ptr2=desclist;
		while(ptr1 && ptr2){

			if(list->data+ptr1->data+ptr2->data<sum){

				ptr1=ptr1->next;

			}else if(list->data+ptr1->data+ptr2->data>sum){
				ptr2=ptr2->next;
			}else{
				printf("%d %d %d",list->data,ptr1->data,ptr2->data);
				return;
			}
		}
		list=list->next;
	}
}
void deleteUnderGivenConstraint(struct LinkListNode* head,struct LinkListNode* node) {

	struct LinkListNode* ptr = head;
	struct LinkListNode* prev = ptr;
	while (ptr != node) {
		prev = ptr;
		ptr = ptr->next;
	}
	if (ptr) {
		if (ptr == head) {
			head->data = head->next->data;
			ptr = ptr->next;

		}
		prev->next = ptr->next;
		free(ptr);
	}

}

void getSortedlisthavingZeroOneTwoAsElementsLinklist(struct LinkListNode* head){

	struct LinkListNode* ptr=head;
	int c0=0,c1=0,c2=0;

	while(ptr){

		if(ptr->data==0) c0++;
		if(ptr->data==1) c1++;
		if(ptr->data==2) c2++;

		ptr=ptr->next;
	}

	ptr=head;

	while(c0){
		ptr->data=0;
		ptr=ptr->next;
		c0--;
	}

	while(c1){
		ptr->data=1;
		ptr=ptr->next;
		c1--;
	}


	while(c2){
		ptr->data=2;
		ptr=ptr->next;
		c2--;
	}

}
void getSortedlisthavingZeroOneTwoAsElementsLinklistAlternative(struct LinkListNode* head){

	struct LinkListNode* ptr=head;
	int count[10]={0};

	while(ptr){

		count[ptr->data]++;
		ptr=ptr->next;
	}

	ptr=head;
	int i,c;

	for(i=0;i<9;i++){

		c=count[i];
		while(c>0){
			ptr->data=i;
			c--;
			ptr=ptr->next;
		}
	}
}

void sortAbsoluteValueSortedLinkList(struct LinkListNode** headRef){

	struct LinkListNode* ptr=*headRef;
	struct LinkListNode* prev=NULL;
	struct LinkListNode* tmp=NULL;

	while(ptr){

		if(ptr->data>0 || ptr==*headRef){
			prev=ptr;
			ptr=ptr->next;
		}else{
			prev->next=ptr->next;
			tmp=*headRef;
			*headRef=ptr;
			ptr->next=tmp;

			ptr=prev->next;
		}
	}
}
int main(void) {

	struct LinkListNode *head = NULL;


	insertAtFrontLinkList(&head, 5);
	insertAtFrontLinkList(&head, 4);
	insertAtFrontLinkList(&head, 3);
	insertAtFrontLinkList(&head, 2);
	insertAtFrontLinkList(&head, 1);


	struct LinkListNode *listA = NULL;
	insertAtFrontLinkList(&listA, 5);
	insertAtFrontLinkList(&listA, 4);
	insertAtFrontLinkList(&listA, 3);
	insertAtFrontLinkList(&listA, 2);
	insertAtFrontLinkList(&listA, 1);

	struct LinkListNode *listB = NULL;
	insertAtFrontLinkList(&listB, 7);
	insertAtFrontLinkList(&listB, 3);
	insertAtFrontLinkList(&listB, 1);
/*
	printLinklist(head);
	printf("\nsize=%d\n", sizeOfLinkListRecursive(head));
	reverseLinkList(&head);
	printLinklist(head);
*/
/*
	 printLinklist(listA);
	 printf("\n");
	 printLinklist(listB);
	 printf("\n");
	 printLinklist(mergeSortedLinkList(listA,listB));
	 printf("\n");
*/

/*	 printLinklist(listA);
	 printf("\n");
	 printLinklist(listB);
	 printf("\n");
	 printLinklist(mergeSortedLinkListRecursive(listA,listB));
	 printf("\n");
*/
/*	printLinklist(head);
	printf("\n");
	head = mergeSortOfLinkList(head);
	printf("\n");
	printLinklist(head);
*/
/*
	 printLinklist(head);
	 rotateLinkList(&head,2);
	 printf("\n");
	 printLinklist(head);
*/
/*
	 printLinklist(head);
	 rotateCounterClockwiseLinkList(&head,1);
	 printf("\n");
	 printLinklist(head);
*/

//create loop in linklist

/*
	struct LinkListNode* save, *ptr = head;
	int count = 0;

	while (ptr != NULL && ptr->next!=NULL) {
		count++;
		if (count == 3)
			save = ptr;
		ptr = ptr->next;
	}

	ptr->next=save;
*/

/*
	struct LinkListNode* loopNode=isLoopExistInLinkList(head);
	printf("is loop present: %s",loopNode ?"yes ":"no");
*/

/*
	printf("loop size=%d",getLoopSizeInLinkList(head));
*/

/*
	printf("\n%s\n",isLoopExistThenRemoveitLinkList(head)==1?"yes loop exist":"no loop exist");
	printLinklist(head);
*/


/*	printLinklist(head);
	head=reverseInGroupOfSizeKLinkList(head,4);
	printf("\n");
	printLinklist(head);
*/

/*	printLinklist(listA);
	printf("\n");
	printLinklist(listB);
	printf("\n");

	struct LinkListNode* result =AddTwoLinkList(listA,listB);
	printLinklist(result);
*/
/*
	printLinklist(listA);
	printf("\n");
	printLinklist(listB);
	printf("\n");
	struct LinkListNode* result = AddTwoLinkListRecursive(listA, listB, 0);
	printLinklist(result);
*/


/*
	printLinklist(head);
	swapTwoNodesInLinkList(&head,2,5);
	printLinklist(head);
*/
/*
	printLinklist(head);
	struct LinkListNode* ptr=getNthNodeValueInLinklist(head,10);
	printf("nth node value =%d",ptr?ptr->data:INT_MIN);
*/
/*
	printLinklist(head);
	printf("mid node=%d\n",getMiddleNodeOfLinkList(head)->data);

	printf("mid node=%d\n",getMiddleNodeOfLinkListOptimized(head)->data);
*/
/*
	printLinklist(head);
	printf("node value=%d",getNthNodeFromEndOfLinkList(head,5)->data);
*/
/*
	printLinklist(head);
	deleteTheLinkList(&head);
	printLinklist(head);
*/
/*
	printLinklist(head);
	printf("is palindrome=%d",isPalindromeLinkList(head));
*/
/*
	printLinklist(head);
	printReverseOfLinkList(head);
*/
/*
	printLinklist(head);
	removeConsecutiveDuplicatesFromLinklist(&head);
	printLinklist(head);
*/

/*
	printLinklist(listA);
	printLinklist(listB);
	struct LinkListNode* commonlist=getIntersectionOfTwoSortedlinkList(listA,listB);
	printLinklist(commonlist);
*/
/*
	printLinklist(listA);
	printLinklist(listB);
	struct LinkListNode* commonlist=getIntersectionOfTwoSortedlinkListRecursive(listA,listB);
	printLinklist(commonlist);
*/
/*
	printLinklist(head);
	deleteAlternateNodesinLinkList(&head);
	printLinklist(head);
*/
/*
	printLinklist(head);
	alternateSplitOfLinkList(head);
*/

/*
	printLinklist(listA);
	printLinklist(listB);head
	printf("are identical: %d",areIdenticalLinklistRecursive(listA,listB));
*/

/*
	printLinklist(head);
	head=reverseAlternateKNodeinLinkList(head,3);
	printLinklist(head);
*/

/*
	printLinklist(listA);
	deleteNodeWithGreaterValueInRightLinklist(&listA);
	printLinklist(listA);
*/


	//printLinklist(head);
    printf("\n");
	head->down=getNewLinkListNode(5);
	head->down->down=getNewLinkListNode(7);
	head->next->next->down=getNewLinkListNode(10);
	head->next->next->down->down=getNewLinkListNode(15);


    head=flattenLinkList(head);

/*    while(head){
    	printf(" %d",head->data);
    	head=head->down;
    }*/

/*
	printLinklist(head);
	printLinklist(listA);
	printLinklist(listB);
	getTripletWithGivenSumFromThreeLinkList(head,listA,listB,101);
*/

/*
	printLinklist(head);
	deleteUnderGivenConstraint(head,head->next);
	printLinklist(head);
*/

/*
	printLinklist(head);
	getSortedlisthavingZeroOneTwoAsElementsLinklist(head);
	printLinklist(head);
*/
/*
	printLinklist(head);
	getSortedlisthavingZeroOneTwoAsElementsLinklistAlternative(head);
	printLinklist(head);
*/

/*
	printLinklist(listA);
	sortAbsoluteValueSortedLinkList(&listA);
	printLinklist(listA);
*/



	return EXIT_SUCCESS;
}
