/*
 ============================================================================
 Name        : Queue.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "/home/anurag/Desktop/CPROGG/DataStructure-geeksforgeeks_workspace/Algorithms/commonDeclarations.h"
#include "/home/anurag/Desktop/CPROGG/DataStructure-geeksforgeeks_workspace/Algorithms/LinkListFunctions.c"
#include "/home/anurag/Desktop/CPROGG/DataStructure-geeksforgeeks_workspace/Algorithms/StackFunctions.c"

struct QueueAsArray{
	int *array;
	int front;
	int rear;
	int size;
	int capacity;
};

struct LinkListChar{
	char *string;
	struct LinkListChar *next;
};

struct QueueAsArray* createQueueAsArray(int capacity);
int isFullQueueAsArray(struct QueueAsArray *queueAsArray);
int isEmptyQueueAsArray(struct QueueAsArray *queueAsArray);
void enqueueQueueAsArray(struct QueueAsArray *queueAsArray,int item);
int dequeueQueueAsArray(struct QueueAsArray *queueAsArray);

int isEmptyQueueAsLinkList(struct LinkListNode *front,struct LinkListNode *rear);
int sizeOfQueueAsLinkList(struct LinkListNode *front,struct LinkListNode *rear);
int dequeueQueueAsLinkList(struct LinkListNode **front,struct LinkListNode **rear);
void enqueueQueueAsLinkList(struct LinkListNode **front,struct LinkListNode **rear,int item);

struct QueueAsArray* createDeque(int capacity);
int isFullDeque(struct QueueAsArray *deque);
int isEmptyDeque(struct QueueAsArray *deque);
void insertAtFrontDeque(struct QueueAsArray *deque, int item);
void insertAtRearDeque(struct QueueAsArray *deque, int item);
int deleteAtRearDeque(struct QueueAsArray *deque) ;
int deleteAtFrontDeque(struct QueueAsArray *deque);

char * deleteFromLinkListCharQueue(struct LinkListChar **front,struct LinkListChar **rear);
void addToLinkListCharQueue(struct LinkListChar **front,struct LinkListChar **rear,char *str);
void generateBinaryNumbersTillGivenvalue(int n);


void implementQueueFromStack(void);

void moveElementsFromQueue(struct LinkListNode **,struct LinkListNode **,struct LinkListNode **,struct LinkListNode **);
void AddToStackbyQueue(struct LinkListNode **,struct LinkListNode **,struct LinkListNode **,struct LinkListNode **,int );
int  deleteFromStackByQueue(struct LinkListNode **,struct LinkListNode **,struct LinkListNode **,struct LinkListNode **);
int implementStackFromQueue(void);

struct QueueAsArray* createQueueAsArray(int capacity){

	struct QueueAsArray *queueAsArray=(struct QueueAsArray *)malloc(sizeof(struct QueueAsArray));
	queueAsArray->array=(int *)malloc(capacity*sizeof(int));
	queueAsArray->capacity=capacity;

	queueAsArray->front=0;
	queueAsArray->rear=capacity-1;
	queueAsArray->size=0;

	return queueAsArray;
}

int isFullQueueAsArray(struct QueueAsArray *queueAsArray){
	return queueAsArray->size==queueAsArray->capacity;
}

int isEmptyQueueAsArray(struct QueueAsArray *queueAsArray){

	return queueAsArray->size==0;
}

void enqueueQueueAsArray(struct QueueAsArray *queueAsArray,int item){

	if(isFullQueueAsArray(queueAsArray)){
		printf("overflow:cant enqueue ");
		return;
	}

	queueAsArray->rear=(queueAsArray->rear+1)%queueAsArray->capacity;

	queueAsArray->array[queueAsArray->rear]=item;
	queueAsArray->size++;

}

int dequeueQueueAsArray(struct QueueAsArray *queueAsArray){

	if(isEmptyQueueAsArray(queueAsArray)){
		printf("underflow:cant dequeue ");
		return INT_MIN;
	}

	if(queueAsArray->front==queueAsArray->rear){

		int item=queueAsArray->array[queueAsArray->front];

		queueAsArray->rear=queueAsArray->capacity-1;
		queueAsArray->front=0;
		queueAsArray->size--;
		return item;;
	}
	int item=queueAsArray->array[queueAsArray->front];
	queueAsArray->front=(queueAsArray->front+1)%queueAsArray->capacity;
	queueAsArray->size--;
	return item;
}

int isEmptyQueueAsLinkList(struct LinkListNode *front,struct LinkListNode *rear){

	return front==NULL;
}

int sizeOfQueueAsLinkList(struct LinkListNode *front,struct LinkListNode *rear){

	int size=0;
	while(front!=NULL){
		front=front->next;
		size++;
	}
	return size;
}
void enqueueQueueAsLinkList(struct LinkListNode **front,struct LinkListNode **rear,int item){

	if(*rear==NULL){
		*rear=getNewLinkListNode(item);
		*front=*rear;
		return;
	}
	struct LinkListNode *node=getNewLinkListNode(item);
	(*rear)->next=node;
	(*rear)=node;
}

int dequeueQueueAsLinkList(struct LinkListNode **front,struct LinkListNode **rear){

	if(isEmptyQueueAsLinkList(*front,*rear)){
		printf("underflow:cant dequeue ");
		return INT_MIN;
	}
	if(*front==*rear){
		struct LinkListNode *node=*front;
		int item=node->data;
		*front=*rear=NULL;
		free(node);
		return item;
	}

	struct LinkListNode *node=*front;
	int item=node->data;
	*front=(*front)->next;
	free(node);
	return item;

}

struct QueueAsArray* createDeque(int capacity){

	struct QueueAsArray *deque=(struct QueueAsArray*)malloc(sizeof(struct QueueAsArray));
	deque->array=(int *)malloc(capacity*sizeof(int));
	deque->capacity=capacity;
	deque->front=-1;
	deque->rear=0;

	return deque;

}

int isFullDeque(struct QueueAsArray *deque){

	return (deque->front==0 && deque->rear==deque->capacity-1)||(deque->front==deque->rear+1);
}

int isEmptyDeque(struct QueueAsArray *deque){

	return (deque->front==-1 && deque->rear==0);
}

void insertAtFrontDeque(struct QueueAsArray *deque, int item) {

	if (isFullDeque(deque)) {

		printf("overflow: can't insert ");
		return;
	}
	if (deque->front == -1) {

		deque->front++;

	} else if (deque->front == 0) {
		deque->front = deque->capacity - 1;

	} else {
		deque->front = deque->front - 1;
	}

	deque->array[deque->front] = item;
}

int deleteAtFrontDeque(struct QueueAsArray *deque) {

	int item;
	if (isEmptyDeque(deque)) {
		printf("underflow:cant delete ");
		return INT_MIN;
	}
	if (deque->front == deque->rear) {

		item = deque->array[deque->front];

		deque->front = -1;
		deque->rear = 0;
		return item;;
	}
	item = deque->array[deque->front];
	deque->front = (deque->front + 1) % deque->capacity;

	return item;

}
int deleteAtRearDeque(struct QueueAsArray *deque) {

	int item;

	if (isEmptyDeque(deque)) {
		printf("underflow:cant delete ");
		return INT_MIN;
	}
	if (deque->front == deque->rear) {

		item = deque->array[deque->rear];

		deque->front = -1;
		deque->rear = 0;
		return item;;
	}
	if (deque->rear == 0) {

		item = deque->array[deque->rear];

		deque->rear = deque->capacity - 1;
		return item;;
	}

	item = deque->array[deque->rear];
	deque->rear = (deque->rear - 1);
	return item;

}
void insertAtRearDeque(struct QueueAsArray *deque, int item) {

	if (isFullDeque(deque)) {

		printf("overflow: can't insert ");
		return;
	}

	if (deque->front == -1) {
		deque->front++;

	} else {
		deque->rear = (deque->rear + 1) % deque->capacity;
	}
	deque->array[deque->rear] = item;
}

void slidingWindowMaximum(int *arr,int size,int k){

	int i;
	struct QueueAsArray *deque=createDeque(k);
	for(i=0;i<k;i++){

		while(!isEmptyDeque(deque)&& arr[i]>arr[deque->array[deque->rear]]){

			deleteAtRearDeque(deque);
		}
		insertAtRearDeque(deque,i);
	}

	printf("%d ",arr[deque->array[deque->front]]);
	for(;i<size;i++){

		//remove element less than sliding window size
		while(!isEmptyDeque(deque) && deque->array[deque->front] <=i-k){
			deleteAtFrontDeque(deque);
		}

		while(!isEmptyDeque(deque) && arr[i]>arr[deque->array[deque->rear]]){
			deleteAtRearDeque(deque);
		}
		insertAtRearDeque(deque,i);

		printf("%d ",arr[deque->array[deque->front]]);
	}
}

void addToLinkListCharQueue(struct LinkListChar **front,struct LinkListChar **rear,char *str){

	if(*rear==NULL){
		*rear=(struct LinkListChar*)malloc(sizeof(struct LinkListChar));
		(*rear)->string=(char *)malloc(sizeof(str));
		strcpy((*rear)->string,str);
		*front=*rear;

	}else{
		struct LinkListChar *node=(struct LinkListChar*)malloc(sizeof(struct LinkListChar));
		node->string=(char *)malloc(sizeof(str));
		strcpy(node->string,str);

		(*rear)->next=node;
		*rear=node;

	}

}
char * deleteFromLinkListCharQueue(struct LinkListChar **front,struct LinkListChar **rear){
	struct LinkListChar *node=NULL;
	if(*front==NULL){
		printf("underflow:cant delete from empty queue");
		return NULL;
	}
	if(*front==*rear){
		node=*front;
		*front=NULL;
		*rear=NULL;

	}else{
		node=*front;
		*front=(*front)->next;
	}


	char *str=node->string;
	free(node);

	return str;

}
void generateBinaryNumbersTillGivenvalue(int n){


	struct LinkListChar *front=NULL;
	struct LinkListChar *rear=NULL;

	addToLinkListCharQueue(&front,&rear,"1");
	char *str,copyStr[100];
	while(n>0){

		str=deleteFromLinkListCharQueue(&front,&rear);
		printf("%s\n",str);
		strcpy(copyStr,str);
		addToLinkListCharQueue(&front,&rear,strcat(str,"0"));
		addToLinkListCharQueue(&front,&rear,strcat(copyStr,"1"));

		n--;
	}

}

void moveElementsFromStack(struct LinkListNode **fromStack,struct LinkList **toStack){

	while(!isEmptyStackAsLinkList(*fromStack)){
		pushToStackAsLinkList(toStack,popFromStackAsLinkList(fromStack));
	}
}
void AddToQueueByStack(struct LinkListNode **stack1,struct LinkList **stack2,int val){

	if (isEmptyStackAsLinkList(*stack1)) {

		pushToStackAsLinkList(stack1, val);
	} else {

		moveElementsFromStack(stack1, stack2);
		pushToStackAsLinkList(stack1, val);
		moveElementsFromStack(stack2, stack1);

	}
}
int deleteFromQueueByStack(struct LinkListNode **stack1,struct LinkList **stack2){

	if(isEmptyStackAsLinkList(*stack1)){

		return -1;
	}
	return popFromStackAsLinkList(stack1);

}
void implementQueueFromStack(void){

	struct LinkListNode *stack1=NULL;
	struct LinkListNode *stack2=NULL;

	AddToQueueByStack(&stack1,&stack2,10);
	AddToQueueByStack(&stack1,&stack2,20);
	AddToQueueByStack(&stack1,&stack2,40);

	printf("value=%d\n",	deleteFromQueueByStack(&stack1,&stack2));
	printf("value=%d\n",	deleteFromQueueByStack(&stack1,&stack2));
	printf("value=%d\n",	deleteFromQueueByStack(&stack1,&stack2));

}

void moveElementsFromQueue(struct LinkListNode **front1,struct LinkListNode **rear1,struct LinkListNode **front2,struct LinkListNode **rear2){

	while(!isEmptyQueueAsLinkList(*front1,*rear1)){
		enqueueQueueAsLinkList(front2,rear2,dequeueQueueAsLinkList(front1,rear1));
	}
}

void AddToStackbyQueue(struct LinkListNode **front1,struct LinkListNode **rear1,struct LinkListNode **front2,struct LinkListNode **rear2,int val){

	if(isEmptyQueueAsLinkList(*front1,*rear1)){

		enqueueQueueAsLinkList(front1,rear1,val);

	}else{

		moveElementsFromQueue(front1,rear1,front2,rear2);
		enqueueQueueAsLinkList(front1,rear1,val);
		moveElementsFromQueue(front2,rear2,front1,rear1);
	}


}

int  deleteFromStackByQueue(struct LinkListNode **front1,struct LinkListNode **rear1,struct LinkListNode **front2,struct LinkListNode **rear2){

	if(isEmptyQueueAsLinkList(*front1,*rear1)){
		printf("underflow:cant insert");
		return -1;
	}

	return dequeueQueueAsLinkList(front1,rear1);

}
int implementStackFromQueue(void){

	struct LinkListNode *front1=NULL;
	struct LinkListNode *rear1=NULL;
	struct LinkListNode *front2=NULL;
	struct LinkListNode *rear2=NULL;

	AddToStackbyQueue(&front1,&rear1,&front2,&rear2,10);
	AddToStackbyQueue(&front1,&rear1,&front2,&rear2,20);
	AddToStackbyQueue(&front1,&rear1,&front2,&rear2,30);

	printf("value=%d\n",	deleteFromStackByQueue(&front1,&rear1,&front2,&rear2));
	printf("value=%d\n",	deleteFromStackByQueue(&front1,&rear1,&front2,&rear2));
	printf("value=%d\n",	deleteFromStackByQueue(&front1,&rear1,&front2,&rear2));

}
int main(void) {

/*	struct QueueAsArray *queue=createQueueAsArray(100);
	enqueueQueueAsArray(queue,10);
	enqueueQueueAsArray(queue,20);
	enqueueQueueAsArray(queue,30);

	printf("queue size=%d\n",queue->size);

	printf("element=%d\n",dequeueQueueAsArray(queue));
	printf("element=%d\n",dequeueQueueAsArray(queue));
	printf("element=%d\n",dequeueQueueAsArray(queue));

	printf("element=%d\n",dequeueQueueAsArray(queue));
	printf("queue size=%d\n",queue->size);
*/

/*
	struct LinkListNode *front=NULL;
	struct LinkListNode *rear=NULL;

	enqueueQueueAsLinkList(&front,&rear,10);
	enqueueQueueAsLinkList(&front,&rear,20);
	enqueueQueueAsLinkList(&front,&rear,30);
	printf("size=%d\n",sizeOfQueueAsLinkList(front,rear));

	printf("element=%d\n",dequeueQueueAsLinkList(&front,&rear));

	printf("element=%d\n",dequeueQueueAsLinkList(&front,&rear));
	printf("element=%d\n",dequeueQueueAsLinkList(&front,&rear));
	printf("element=%d\n",dequeueQueueAsLinkList(&front,&rear));
	printf("element=%d\n",dequeueQueueAsLinkList(&front,&rear));
	printf("element=%d\n",dequeueQueueAsLinkList(&front,&rear));

	printf("size=%d\n",sizeOfQueueAsLinkList(front,rear));

*/

/*
	struct QueueAsArray *deque=createDeque(100);

	insertAtFrontDeque(deque,10);
	insertAtFrontDeque(deque,20);
	insertAtRearDeque(deque,30);
	insertAtFrontDeque(deque,40);

	printf("element=%d\n",deleteAtFrontDeque(deque));
	printf("element=%d\n",deleteAtFrontDeque(deque));
	printf("element=%d\n",deleteAtFrontDeque(deque));
	printf("element=%d\n",deleteAtFrontDeque(deque));
	printf("element=%d\n",deleteAtFrontDeque(deque));
*/

/*
	struct QueueAsArray *deque=createDeque(100);

	insertAtFrontDeque(deque,10);
	insertAtFrontDeque(deque,20);
	insertAtRearDeque(deque,30);
	insertAtFrontDeque(deque,40);

	printf("element=%d\n",deleteAtRearDeque(deque));
	printf("element=%d\n",deleteAtRearDeque(deque));
	printf("element=%d\n",deleteAtRearDeque(deque));
	printf("element=%d\n",deleteAtRearDeque(deque));
	printf("element=%d\n",deleteAtFrontDeque(deque));
*/


/*
	int arr[]={3,2,1,1,5,6};
	int k=3;
	int size=6;
	slidingWindowMaximum(arr,size,k);
*/

/*
	generateBinaryNumbersTillGivenvalue(5);
*/

/*
	implementQueueFromStack();
*/

/*
	implementStackFromQueue();

*/

	return EXIT_SUCCESS;
}














