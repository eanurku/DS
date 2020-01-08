/*
 ============================================================================
 Name        : Stack.c
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


struct StackAsArray* createStackAsArray(int capacity);
int sizeOfStackAsArray(struct StackAsArray *stackAsArray);
int isFullStackAsArray(struct StackAsArray *stackAsArray);
int isEmptyStackAsArray(struct StackAsArray *stackAsArray);
int peekStackAsArray(struct StackAsArray *stackAsArray);
void traverseStackAsArray(struct StackAsArray *stackAsArray);
int pushToStackAsArray(struct StackAsArray *stackAsArray,char val);
int popFromStackAsArray(struct StackAsArray *stackAsArray);

int pushToStackAsLinkList(struct LinkListNode **top,int val);
int popFromStackAsLinkList(struct LinkListNode **top);
int isEmptyStackAsLinkList(struct LinkListNode * top);
int sizeOfStackAslinkList(struct LinkListNode * top);

int isOperand(char character);
int Prec(char character);
void infixToPostfixCoversion(char *str);

int isNumber(char *string);
void postfixExpEvaluation(char *str);

int ismatchingPair(char firstChar,char secondChar);
int areParenthesesBalanced(char *str);

void reverseStringUsingStack(char *str);

void insertAtBottomOfStackAsArrayRecursive(struct StackAsArray *stack,char character);
void reverseStackAsArrayUsingRecursion(struct StackAsArray *stack);

void insertInIncreasingOrderInStackAsLinkListRecursive(struct LinkListNode **stack,int val);
void sortStackAsLinkListUsingRecursion(struct LinkListNode **stack);

void NextgreaterElement(int *array,int size);
void stockspanCalculation(int *array,int size,int *spanArray);


void implementTwoStackInArray(void);
void implementSpacialStackWithGetMinIn_O1_Time();
void implementStackWithMiddleElementOperationsIn_O1_Time();
void implementStackUsingMinHeap();
void implementStackWithGetMinin_O1_Space();
void sortStackbyusingAnotherTempStack();
void implementTowerOfHanoiByStack();

int isCelebrityExist(int array[4][4],int n);
int isCelebrityExistByStack(int array[4][4],int n);

void evaluateInfixExpression(char *str);
int findMaxDepthOfparentheses(char *str);
int longestValidParenthesesSubstring(char *str);
char * deParenthesesiationOfAlgebricExp(char *exp);
int reverseNumberByStack(int number);
int isStackpermutation(int first[],int second[],int size);

struct StackAsArray* createStackAsArray(int capacity){

	struct StackAsArray *stackAsArray=(struct StackAsArray *)malloc(sizeof(struct StackAsArray));

	stackAsArray->array=(char *)malloc(sizeof(char)*capacity);
	stackAsArray->capacity=capacity;
	stackAsArray->top=-1;

	return stackAsArray;

}
int sizeOfStackAsArray(struct StackAsArray *stackAsArray){

	return stackAsArray->top+1;
}
int peekStackAsArray(struct StackAsArray *stackAsArray){

	if(!isEmptyStackAsArray(stackAsArray)){
		return stackAsArray->array[stackAsArray->top];
	}

	return INT_MIN;
}
int isFullStackAsArray(struct StackAsArray *stackAsArray){

	return stackAsArray->top+1==stackAsArray->capacity;

}
int isEmptyStackAsArray(struct StackAsArray *stackAsArray){

	return stackAsArray->top==-1;

}

void traverseStackAsArray(struct StackAsArray *stackAsArray){
	int i;
	for(i=stackAsArray->top;i>=0;i--){
		printf("%c",stackAsArray->array[i]);
	}
	printf("\n");
}

int pushToStackAsArray(struct StackAsArray *stackAsArray,char val){

	if(isFullStackAsArray(stackAsArray)){
		printf("overflow:stack full");
		return 0;
	}
	stackAsArray->array[++stackAsArray->top]=val;

	return 1;

}

int popFromStackAsArray(struct StackAsArray *stackAsArray){

	if(isEmptyStackAsArray(stackAsArray)){
		printf("underflow:stack empty");
		return INT_MIN;
	}
	char retVal=stackAsArray->array[stackAsArray->top];
	stackAsArray->top=stackAsArray->top-1;

	return retVal;
}
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



	return retVal;
}
int isOperand(char character){

	if(isalpha(character)){
		return 1;
	}

	return 0;
}

int Prec(char character){
     if(character=='+'|| character=='-'){
    	 return 1;
     }else if(character=='*'){
    	 return 2;
     }else{
    	 return -1;
     }
}
void infixToPostfixCoversion(char *str) {

	struct StackAsArray *stack = createStackAsArray(100);
	int i;char ch;
	for (i = 0; str[i]; i++) {

		if (isOperand(str[i])) {

			printf("%c", str[i]);

		} else if (str[i] == '(') {

			pushToStackAsArray(stack, str[i]);

		} else if (str[i] == ')') {

			while (!isEmptyStackAsArray(stack) && peekStackAsArray(stack) != '(') {
				 printf("%c",popFromStackAsArray(stack));
		    }
			 popFromStackAsArray(stack);



		} else { //if str[i] is a operator

			while(!isEmptyStackAsArray(stack) && Prec(str[i])<= Prec(peekStackAsArray(stack))){

				 printf("%c",popFromStackAsArray(stack));
			}

			pushToStackAsArray(stack,str[i]);
        }


    }
	while(!isEmptyStackAsArray(stack)){
		printf("%c",popFromStackAsArray(stack));
	}
}
int isNumber(char *string){

	while(*string){

		if(!isdigit(*string)){
			return 0;
		}
		string++;
	}

	return 1;
}
void postfixExpEvaluation(char *str){

	struct LinkListNode *stack=NULL;
	int val1,val2;
	char *token,*delim="' '";
	token=strtok(str,delim);
	while(token){

		if(isNumber(token)){
			pushToStackAsLinkList(&stack,atoi(token));
		}else{

			val2=popFromStackAsLinkList(&stack);
			val1=popFromStackAsLinkList(&stack);
			switch(*token){
			case '+':pushToStackAsLinkList(&stack,val1+val2);break;
			case '-':pushToStackAsLinkList(&stack,val1-val2);break;
			case '*':pushToStackAsLinkList(&stack,val1*val2);break;
			}
		}
		token=strtok(NULL,delim);
	}

	printf("%d",popFromStackAsLinkList(&stack));
}

int ismatchingPair(char firstChar,char secondChar){

	if(firstChar=='(' && secondChar==')'){
		return 1;
	}else if(firstChar=='[' && secondChar==']'){
		return 1;
	}else if(firstChar=='{' && secondChar=='}'){
		return 1;
	}

	return 0;

}
int areParenthesesBalanced(char *str){

	struct StackAsArray *stack=createStackAsArray(100);
	char popChar;
	while(*str){

		if(*str=='('||*str=='['||*str=='{'){
			pushToStackAsArray(stack,*str);
		}else{

			if(isEmptyStackAsArray(stack)){
				return 0;
			}
			popChar=popFromStackAsArray(stack);
			if(!ismatchingPair(popChar,*str)){
				return 0;
			}
		}

		str++;
	}

	if(!isEmptyStackAsArray(stack)){
		return 0;
	}
	return 1;
}

void reverseStringUsingStack(char *str){

	struct StackAsArray *stack=createStackAsArray(100);
	int i;
	while(str[i]){

		pushToStackAsArray(stack,str[i]);
		i++;
	}

	i=0;
	while(!isEmptyStackAsArray(stack)){

		str[i++]=popFromStackAsArray(stack);
	}

	str[i]='\0';
}
void insertAtBottomOfStackAsArrayRecursive(struct StackAsArray *stack,char character){

	if(isEmptyStackAsArray(stack)){
		pushToStackAsArray(stack,character);
		return;
	}

	char tmp=popFromStackAsArray(stack);
	insertAtBottomOfStackAsArrayRecursive(stack,character);
	pushToStackAsArray(stack,tmp);
}
void reverseStackAsArrayUsingRecursion(struct StackAsArray *stack){

	if(isEmptyStackAsArray(stack)){
		return;
	}
	char tmp=popFromStackAsArray(stack);
	reverseStackAsArrayUsingRecursion(stack);
	insertAtBottomOfStackAsArrayRecursive(stack,tmp);
}

void insertInIncreasingOrderInStackAsLinkListRecursive(struct LinkListNode **stack,int val){

	if(isEmptyStackAsLinkList(*stack)|| val<(*stack)->data){
		pushToStackAsLinkList(stack,val);
		return;
	}
	int tmp=popFromStackAsLinkList(stack);
	insertInIncreasingOrderInStackAsLinkListRecursive(stack,val);
	pushToStackAsLinkList(stack,tmp);
}
void sortStackAsLinkListUsingRecursion(struct LinkListNode **stack){

	if(isEmptyStackAsLinkList(*stack)){
		return ;
	}
	int tmp=popFromStackAsLinkList(stack);
	sortStackAsLinkListUsingRecursion(stack);
	insertInIncreasingOrderInStackAsLinkListRecursive(stack,tmp);


}

void NextgreaterElement(int *array,int size){

	struct LinkListNode *stack=NULL;
	int i=0;

	pushToStackAsLinkList(&stack,array[i]);
	for(i=1;i<size;i++){

		if(!isEmptyStackAsLinkList(stack)){

			while(!isEmptyStackAsLinkList(stack) && array[i]>stack->data){

				printf("%d--->%d\n",popFromStackAsLinkList(&stack),array[i]);

			}
			pushToStackAsLinkList(&stack,array[i]);
		}

	}
	while(!isEmptyStackAsLinkList(stack)){

		printf("%d--->%d\n",popFromStackAsLinkList(&stack),-1);
	}
}

void stockspanCalculation(int *array,int size,int *spanArray){

	struct LinkListNode *stack=NULL;
	int i;

	spanArray[0]=1;
	pushToStackAsLinkList(&stack,0);
	for(i=1;i<size;i++){

		while(!isEmptyStackAsLinkList(stack) && array[i]>array[stack->data]){

			popFromStackAsLinkList(&stack);
		}
		if(!isEmptyStackAsLinkList(stack))
		spanArray[i]=i-stack->data;
		else{
			spanArray[i]=i+1;
		}
		pushToStackAsLinkList(&stack,i);
	}

}

struct TwoStacks{
	int *array;
	int leftTop;
	int rightTop;
	int capacity;
};

struct TwoStacks* createTwoStacks(int capacity){

	struct TwoStacks *stack=(struct TwoStacks *)malloc(sizeof(struct TwoStacks));
	stack->array=(int *)malloc(sizeof(int)*capacity);
	stack->leftTop=-1;
	stack->rightTop=capacity;
	stack->capacity=capacity;

}

int isFullTwoStacks(struct TwoStacks *stack){

	return stack->leftTop+1==stack->rightTop;
}
int isEmpty1TwoStacks(struct TwoStacks *stack){
	return stack->leftTop==-1;
}
int isEmpty2TwoStacks(struct TwoStacks *stack){
	return stack->rightTop==stack->capacity;
}
void push1TwoStacks(struct TwoStacks* stack,int val){

	if(isFullTwoStacks(stack)){
		printf("overflow:\n");
		return;
	}
	stack->array[++stack->leftTop]=val;


}
void push2TwoStacks(struct TwoStacks* stack,int val){

	if(isFullTwoStacks(stack)){
		printf("overflow:\n");
		return;
	}
	stack->array[--stack->rightTop]=val;
}
int pop1TwoStacks(struct TwoStacks *stack){

	if(isEmpty1TwoStacks(stack)){
		printf("underflow");
		return -1;
	}
	int item=stack->array[stack->leftTop];
	stack->leftTop--;
	return item;
}
int pop2TwoStacks(struct TwoStacks *stack){

	if(isEmpty2TwoStacks(stack)){
		printf("underflow");
		return -1;
	}
	int item=stack->array[stack->rightTop];
	stack->rightTop++;
	return item;
}
void implementTwoStackInArray(void){

	struct TwoStacks *stack=createTwoStacks(4);

	push1TwoStacks(stack,10);
	push1TwoStacks(stack,20);
	push2TwoStacks(stack,40);
	push2TwoStacks(stack,30);
	push2TwoStacks(stack,440);

	printf("val=%d\n",pop1TwoStacks(stack));
	printf("val=%d\n",pop1TwoStacks(stack));
	printf("val=%d\n",pop2TwoStacks(stack));
	printf("val=%d\n",pop2TwoStacks(stack));
}

struct SpecialStack{
	int *array;
	int *minArray;
	int top;
	int minTop;
	int capacity;
};

struct SpecialStack* createSpecialStack(int capacity){

	struct SpecialStack *stack=(struct SpecialStack *)malloc(sizeof(struct SpecialStack));
	stack->array=(int *)malloc(sizeof(int)*capacity);
	stack->minArray=(int *)malloc(sizeof(int)*capacity);
	stack->top=-1;
	stack->minTop=-1;
	stack->capacity=capacity;
	return stack;
}
int isFullSpecialStack(struct SpecialStack *stack){
	return stack->top==stack->capacity-1;
}
int isEmptySpecialStack(struct SpecialStack *stack){

	return stack->top==-1;
}
void pushSpecialStack(struct SpecialStack *stack,int val){

	if(isFullSpecialStack(stack)){
		printf("overflow");
		return;
	}
	stack->array[++stack->top]=val;
	int item;

	if(stack->minTop==-1){
		stack->minArray[++stack->minTop]=val;
	}else if(val > stack->minArray[stack->minTop]){
		item=stack->minArray[stack->minTop];
		stack->minArray[++stack->minTop]=item;

	}else{
		stack->minArray[++stack->minTop]=val;
	}

}
int popSpecialStack(struct SpecialStack *stack){

	if(isEmptySpecialStack(stack)){
		printf("underflow");
		return -1;
	}
	int item=stack->array[stack->top];
	stack->top--;
	stack->minTop--;
	return item;
}
int getMinSpecialStack(struct SpecialStack *stack){

	if(isEmptySpecialStack(stack)){
		printf("Empty stack");
		return -1;
	}
	return stack->minArray[stack->minTop];
}

void implementSpacialStackWithGetMinIn_O1_Time(void){

	struct SpecialStack *stack=createSpecialStack(100);

	pushSpecialStack(stack,11);
	pushSpecialStack(stack,3);
	pushSpecialStack(stack,5);
	pushSpecialStack(stack,1);
	pushSpecialStack(stack,2);
	pushSpecialStack(stack,4);

	printf("val=%d\n",getMinSpecialStack(stack));
	printf("val=%d\n",popSpecialStack(stack));
	printf("val=%d\n",getMinSpecialStack(stack));
	printf("val=%d\n",popSpecialStack(stack));
	printf("val=%d\n",getMinSpecialStack(stack));
	printf("val=%d\n",popSpecialStack(stack));
	printf("val=%d\n",getMinSpecialStack(stack));
	printf("val=%d\n",popSpecialStack(stack));
	printf("val=%d\n",getMinSpecialStack(stack));
	printf("val=%d\n",popSpecialStack(stack));
	printf("val=%d\n",getMinSpecialStack(stack));
	printf("val=%d\n",popSpecialStack(stack));
	printf("val=%d\n",getMinSpecialStack(stack));
	printf("val=%d\n",popSpecialStack(stack));
	printf("val=%d\n",getMinSpecialStack(stack));
	printf("val=%d\n",popSpecialStack(stack));
	printf("val=%d\n",getMinSpecialStack(stack));
	printf("val=%d\n",popSpecialStack(stack));
}


struct DoublyLinkList{
	int data;
	struct DoublyLinkList *next;
	struct DoublyLinkList *prev;
};
struct DoublyLinkList* getDLLNode(int val){

	struct DoublyLinkList *node=(struct DoublyLinkList *)malloc(sizeof(struct DoublyLinkList));
	node->data=val;
	node->next=NULL;
	node->prev=NULL;

	return node;
}
int isEmptyStackByDLL(struct DoublyLinkList *top){

	return top==NULL;
}
void pushToDLLWithMiddleOps(struct DoublyLinkList **stack,int *size,struct DoublyLinkList **mid,int val){

	if(isEmptyStackByDLL(*stack)){

		(*stack)=getDLLNode(val);
		(*size)++;
		(*mid)=(*stack);
		return;
	}
	struct DoublyLinkList *node=getDLLNode(val);
	(*stack)->prev=node;
	node->next=(*stack);
	(*stack)=node;
	(*size)++;
	if((*size)%2){
		(*mid)=(*mid)->prev;
	}

}
int popFromDLLWithMiddleOps(struct DoublyLinkList **stack,int *size,struct DoublyLinkList **mid){

	if(isEmptyStackByDLL(*stack)){
		printf("underflow:");
		return -1;
	}

	struct DoublyLinkList *node = *stack;
	int item = (*stack)->data;
	if ((*stack)->next) {
		(*stack)->next->prev = NULL;
	}
	(*stack) = (*stack)->next;
	node->next = NULL;

	(*size)--;
	if ((*size) % 2 == 0) {
		(*mid) = (*mid)->next;
	}

	free(node);
	return item;

}

int getMiddleElementInstackbyDLL(struct DoublyLinkList **stack,int *size,struct DoublyLinkList **mid){

	if(isEmptyStackByDLL(*stack)){

		printf("underflow");
		return -1;
	}

	return (*mid)->data;
}

int deleteMiddleElement(struct DoublyLinkList **stack,int *size,struct DoublyLinkList **mid){

	if(isEmptyStackByDLL(*stack)){
		printf("underflow");
		return -1;
	}

	struct DoublyLinkList *saveMid=NULL;
	if((*size)%2){
		saveMid=(*mid)->next;
	}else{
		saveMid=(*mid)->prev;
	}

	(*size)--;

	if((*mid)->prev)
	(*mid)->prev->next=(*mid)->next;
	if((*mid)->next)
	(*mid)->next->prev=(*mid)->prev;

	struct DoublyLinkList *node=*mid;
	int item=node->data;
	node->next=node->prev=NULL;
	free(node);
	(*mid)=saveMid;
	if((*mid)==NULL){
		*stack=NULL;
	}

	return item;

}
void implementStackWithMiddleElementOperationsIn_O1_Time(){

	struct DoublyLinkList *stack=NULL;
	int size=0;
	struct DoublyLinkList *midOfStack=NULL;

	pushToDLLWithMiddleOps(&stack,&size,&midOfStack,10);
	pushToDLLWithMiddleOps(&stack,&size,&midOfStack,20);
	pushToDLLWithMiddleOps(&stack,&size,&midOfStack,30);
	pushToDLLWithMiddleOps(&stack,&size,&midOfStack,40);
	pushToDLLWithMiddleOps(&stack,&size,&midOfStack,50);

	printf("deleted middle=%d\n",deleteMiddleElement(&stack,&size,&midOfStack));
	printf("current middle=%d\n",getMiddleElementInstackbyDLL(&stack,&size,&midOfStack));

	printf("deleted middle=%d\n",deleteMiddleElement(&stack,&size,&midOfStack));
	printf("current middle=%d\n",getMiddleElementInstackbyDLL(&stack,&size,&midOfStack));

	printf("deleted middle=%d\n",deleteMiddleElement(&stack,&size,&midOfStack));
	printf("current middle=%d\n",getMiddleElementInstackbyDLL(&stack,&size,&midOfStack));

	printf("deleted middle=%d\n",deleteMiddleElement(&stack,&size,&midOfStack));
	printf("current middle=%d\n",getMiddleElementInstackbyDLL(&stack,&size,&midOfStack));

	printf("deleted middle=%d\n",deleteMiddleElement(&stack,&size,&midOfStack));
	printf("current middle=%d\n",getMiddleElementInstackbyDLL(&stack,&size,&midOfStack));

	printf("deleted middle=%d\n",deleteMiddleElement(&stack,&size,&midOfStack));
	printf("current middle=%d\n",getMiddleElementInstackbyDLL(&stack,&size,&midOfStack));
/*
	printf("middle=%d\n",getMiddleElementInstackbyDLL(&stack,&size,&midOfStack));
	printf("pop val=%d\n",popFromDLLWithMiddleOps(&stack,&size,&midOfStack));

	printf("middle=%d\n",getMiddleElementInstackbyDLL(&stack,&size,&midOfStack));
	printf("pop val=%d\n",popFromDLLWithMiddleOps(&stack,&size,&midOfStack));

	printf("middle=%d\n",getMiddleElementInstackbyDLL(&stack,&size,&midOfStack));
	printf("pop val=%d\n",popFromDLLWithMiddleOps(&stack,&size,&midOfStack));

	printf("middle=%d\n",getMiddleElementInstackbyDLL(&stack,&size,&midOfStack));
	printf("pop val=%d\n",popFromDLLWithMiddleOps(&stack,&size,&midOfStack));

	printf("middle=%d\n",getMiddleElementInstackbyDLL(&stack,&size,&midOfStack));
	printf("pop val=%d\n",popFromDLLWithMiddleOps(&stack,&size,&midOfStack));

	printf("middle=%d\n",getMiddleElementInstackbyDLL(&stack,&size,&midOfStack));
	printf("pop val=%d\n",popFromDLLWithMiddleOps(&stack,&size,&midOfStack));
*/

}
void pushTostackWithMergeFunction(struct LinkListNode **top,struct LinkListNode **last ,int val){

	if(isEmptyStackAsLinkList(*top)){
		(*top)=getNewLinkListNode(val);
		*last=*top;
		return ;
	}
	struct LinkListNode *node=getNewLinkListNode(val);
	node->next=*top;
	*top=node;
}
int popFromstackWithMergeFunction(struct LinkListNode **top,struct LinkListNode **last){

	int item;
	if(isEmptyStackAsLinkList(*top)){

		printf("underflow");
		return -1;
	}else if(*top==*last){

		item=(*top)->data;
		free(*top);
		*top=*last=NULL;
	}else{
		struct LinkListNode *node=*top;
		*top=(*top)->next;
		node->next=NULL;
		item=node->data;
		free(node);
	}

	return item;
}

void mergeTwoStackFunction(struct LinkListNode **top1,
		struct LinkListNode **last1, struct LinkListNode **top2,
		struct LinkListNode **last2) {
	if(!isEmptyStackAsLinkList(*top1) && !isEmptyStackAsLinkList(*top2)){
	(*last1)->next=(*top2);
	*last1=*last2;
	}else if(isEmptyStackAsLinkList(*top1) && !isEmptyStackAsLinkList(*top2)){

		*top1=*top2;
		*last1=*last2;
	}



}
void implementStackWithMergeStackFunctionIn_O1_Time(){

	struct LinkListNode *top1=NULL;
	struct LinkListNode *last1=NULL;
	struct LinkListNode *top2=NULL;
	struct LinkListNode *last2=NULL;

	pushTostackWithMergeFunction(&top1,&last1,10);
	pushTostackWithMergeFunction(&top1,&last1,20);
	pushTostackWithMergeFunction(&top1,&last1,30);
	pushTostackWithMergeFunction(&top1,&last1,40);

	pushTostackWithMergeFunction(&top2,&last2,50);
	pushTostackWithMergeFunction(&top2,&last2,60);
	pushTostackWithMergeFunction(&top2,&last2,70);




	printf("poped val =%d\n",popFromstackWithMergeFunction(&top1,&last1));
	printf("poped val =%d\n",popFromstackWithMergeFunction(&top1,&last1));
	printf("poped val =%d\n",popFromstackWithMergeFunction(&top1,&last1));
	printf("poped val =%d\n",popFromstackWithMergeFunction(&top1,&last1));
	printf("poped val =%d\n",popFromstackWithMergeFunction(&top1,&last1));

	mergeTwoStackFunction(&top1,&last1,&top2,&last2);
	printLinklist(top1);

}

struct heapNode{
	int data;
	int priority;
};
struct BinHeap{
	struct heapNode *heapArray;
	int heapSize;
	int heapCapacity;
};

struct BinHeap* createBinheap(int capacity){

	struct BinHeap *heap=(struct BinHeap *)malloc(sizeof(struct BinHeap));
	heap->heapArray=(struct heapNode *)malloc(capacity*sizeof(struct heapNode));
	heap->heapCapacity=capacity;
	heap->heapSize=0;
	return heap;
}
int getParentIndexBinHeap(int childIndex) {

	return (childIndex - 1) / 2;
}

int getLeftIndexBinHeap(int parentIndex) {

	return 2 * parentIndex + 1;

}
int getRightIndexBinHeap(int parentIndex) {

	return 2 * parentIndex + 2;

}
void swap(struct heapNode *arr, int index1, int index2) {
	struct heapNode tmp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tmp;

}
void heapifyOperationBottomToTopMinHeap(struct BinHeap *minHeap,int index){

	while(index && minHeap->heapArray[getParentIndexBinHeap(index)].priority > minHeap->heapArray[index].priority){

		swap(minHeap->heapArray,index,getParentIndexBinHeap(index));
		index=getParentIndexBinHeap(index);
	}
}
void insertInMinHeap(struct BinHeap* minHeap,int data, int key) {

	if (minHeap->heapSize == minHeap->heapCapacity) {
		printf("Heap is full");
		return;
	}

	int index = minHeap->heapSize;
	minHeap->heapSize++;
	minHeap->heapArray[index].priority = key;
	minHeap->heapArray[index].data = data;

	heapifyOperationBottomToTopMinHeap(minHeap,index);

}

void heapifyOperationTopToBottomMinHeap(struct BinHeap* minHeap,int index){

	int left=getLeftIndexBinHeap(index);
	int right=getRightIndexBinHeap(index);

	int smallest=index;

    if(left<minHeap->heapSize && minHeap->heapArray[left].priority<minHeap->heapArray[index].priority){
    	smallest=left;
    }
    if(right<minHeap->heapSize && minHeap->heapArray[right].priority<minHeap->heapArray[smallest].priority){
    	smallest=right;
    }
    if(smallest!=index){

    	swap(minHeap->heapArray,index,smallest);
    	heapifyOperationTopToBottomMinHeap(minHeap,smallest);
    }

}
int extractMinInMinHeap(struct BinHeap* minheap){

	if(minheap->heapSize==0){
		printf("empty heap");
		return -1;
	}
	if(minheap->heapSize==1){
		minheap->heapSize--;
		return minheap->heapArray[0].data;
	}

    int minElement=minheap->heapArray[0].data;
    minheap->heapArray[0]=minheap->heapArray[minheap->heapSize-1];
    minheap->heapSize--;

    heapifyOperationTopToBottomMinHeap(minheap,0);

    return minElement;

}

int isEmptyStackByBinheap(struct BinHeap *heap){

	return heap->heapSize==0;
}

int isFullStackbyBinHeap(struct BinHeap *heap){

	return heap->heapSize==heap->heapCapacity;
}
pushToStackByMinHeap(struct BinHeap *heap,int val,int priority){

	insertInMinHeap(heap,val,priority);
}
int popFromStackByMinHeap(struct BinHeap *heap){


	return extractMinInMinHeap(heap);
}
void implementStackUsingMinHeap(){

	struct BinHeap *heap=createBinheap(100);
	int priority=INT_MAX;

	pushToStackByMinHeap(heap,2,priority);
	priority--;pushToStackByMinHeap(heap,5,priority);
	priority--;pushToStackByMinHeap(heap,3,priority);
	priority--;pushToStackByMinHeap(heap,6,priority);
	priority--;pushToStackByMinHeap(heap,1,priority);

	for(int i=0;i<heap->heapSize;i++){

		printf("%d,",heap->heapArray[i].data);
	}
	printf("\n");
	popFromStackByMinHeap(heap);priority++;
	popFromStackByMinHeap(heap);priority++;

	priority--;pushToStackByMinHeap(heap,6,priority);
	priority--;pushToStackByMinHeap(heap,1,priority);

	for(int i=0;i<heap->heapSize;i++){

		printf("%d,",heap->heapArray[i].data);
	}
}

void pushToStackGetMin_O1_space(struct StackAsArray *stack,int *min,int val){

	if(isFullStackAsArray(stack)){
		printf("stack full");
		return;

	}
	if(isEmptyStackAsArray(stack)){
		stack->array[++stack->top]=val;
		*min=val;
	}else{
		if(val<*min){
			stack->array[++stack->top]=2*val-*min;
			*min=val;
		}else{
			stack->array[++stack->top]=val;
		}

	}

}
int popfromstackGetMin_O1_space(struct StackAsArray *stack,int *min){

	if(isEmptyStackAsArray(stack)){

		printf("stack empty");
		return -1;
	}
	int item=stack->array[stack->top];
	stack->top--;
	if(item<*min){

		*min=2*(*min)-item;
	}

	return item;
}

int getminfromstackGetMin_O1_space(struct StackAsArray *stack,int *min){

	return *min;
}

void implementStackWithGetMinin_O1_Space(){

	struct StackAsArray *stack=createStackAsArray(100);
	int min=-1;
	pushToStackGetMin_O1_space(stack,&min,10);
	pushToStackGetMin_O1_space(stack,&min,5);
	pushToStackGetMin_O1_space(stack,&min,1);
	pushToStackGetMin_O1_space(stack,&min,6);
	pushToStackGetMin_O1_space(stack,&min,0);
	pushToStackGetMin_O1_space(stack,&min,7);


	printf("pop val=%d\n",popfromstackGetMin_O1_space(stack,&min));
	printf("pop val=%d\n",popfromstackGetMin_O1_space(stack,&min));

	printf("min=%d",getminfromstackGetMin_O1_space(stack,&min));




}

void sortStackbyusingAnotherTempStack(){

	struct LinkListNode *stack=NULL;
	struct LinkListNode *tmpStack=NULL;

	pushToStackAsLinkList(&stack,10);
	pushToStackAsLinkList(&stack,1);
	pushToStackAsLinkList(&stack,12);
	pushToStackAsLinkList(&stack,5);
	pushToStackAsLinkList(&stack,11);

	printLinklist(stack);

	int item;
	while(!isEmptyStackAsLinkList(stack)){

		item=popFromStackAsLinkList(&stack);
		while(!isEmptyStackAsLinkList(tmpStack) && item<tmpStack->data){

			pushToStackAsLinkList(&stack,popFromStackAsLinkList(&tmpStack));
		}

		pushToStackAsLinkList(&tmpStack,item);
	}

	while(!isEmptyStackAsLinkList(tmpStack)){

		pushToStackAsLinkList(&stack,popFromStackAsLinkList(&tmpStack));
	}
	printf("\n");
	printLinklist(stack);
}

void moveDisk(struct LinkListNode ** from,struct LinkListNode **to,char sour,char dest,int disk){

	printf("move disk number %d from %c to %c\n",disk,sour,dest);
}
void moveDiskLegally(struct LinkListNode ** stack1,struct LinkListNode **stack2,char first,char second){

	int item1=popFromStackAsLinkList(stack1);
	int item2=popFromStackAsLinkList(stack2);

	if(item2==INT_MIN){

		pushToStackAsLinkList(stack2,item1);
		moveDisk(stack1,stack2,first,second,item1);
	} else if(item1==INT_MIN){

		pushToStackAsLinkList(stack1,item2);
		moveDisk(stack2,stack1,second,first,item2);
	}else if(item1 > item2){

		pushToStackAsLinkList(stack1,item1);
		pushToStackAsLinkList(stack1,item2);
		moveDisk(stack2,stack1,second,first,item2);

	}else if(item2 > item1){

		pushToStackAsLinkList(stack2,item2);
		pushToStackAsLinkList(stack1,item1);
		moveDisk(stack1,stack2,first,second,item1);
	}

}
void implementTowerOfHanoiByStack(){

	int n=3,noOfMoves,counter;
	char s='S',d='D',a='A';
	struct LinkListNode *source=NULL;
	struct LinkListNode *aux=NULL;
	struct LinkListNode *dest=NULL;

	pushToStackAsLinkList(&source,3);
	pushToStackAsLinkList(&source,2);
	pushToStackAsLinkList(&source,1);
	printLinklist(source);

	if(n%2==0){
		char tmp=d;
		d=a;
		a=tmp;
	}

	noOfMoves=pow(2,n)-1;
	counter=1;
	while(counter<=noOfMoves){

		if(counter%3==1){

			moveDiskLegally(&source,&dest,s,d);
		}else if(counter%3==2){

			moveDiskLegally(&source,&aux,s,a);
		}else if(counter%3==0){

			moveDiskLegally(&aux,&dest,a,d);
		}

		counter++;
	}

}
void  applyOperatorAndpushResult(struct LinkListNode **stack,char operator){

	int value2=popFromStackAsLinkList(stack);
	int value1=popFromStackAsLinkList(stack);
	switch(operator){
	case '+':pushToStackAsLinkList(stack,value1+value2);break;
	case '-':pushToStackAsLinkList(stack,value1-value2);break;
	case '*':pushToStackAsLinkList(stack,value1*value2);break;
	case '/':pushToStackAsLinkList(stack,value1/value2);break;
	}
}
void evaluateInfixExpression(char *str){

	struct StackAsArray *stack =createStackAsArray(100);
	struct LinkListNode *AnotherStack=NULL;

	char *token;
	char *delim="' '";

	token=strtok(str,delim);
	while(token){

		if(isNumber(token)){
			pushToStackAsLinkList(&AnotherStack,atoi(token));
		}else if(*token=='('){

			pushToStackAsArray(stack,*token);
		}else if(*token==')'){

			while(!isEmptyStackAsArray(stack)&& peekStackAsArray(stack)!='('){
				applyOperatorAndpushResult(&AnotherStack,popFromStackAsArray(stack));
			}
			popFromStackAsArray(stack);
		}else{

			while(!isEmptyStackAsArray(stack) && Prec(*token)<=Prec(peekStackAsArray(stack))){

				applyOperatorAndpushResult(&AnotherStack,popFromStackAsArray(stack));
			}
			pushToStackAsArray(stack,*token);

		}
		token=strtok(NULL,delim);
	}
	while(!isEmptyStackAsArray(stack)){

		applyOperatorAndpushResult(&AnotherStack,popFromStackAsArray(stack));
	}

	printf("sum=%d\n",AnotherStack->data);
}
//a know b ?
int knows(int array[4][4],int a,int b){

	return array[a][b];
}
int isCelebrityExist(int array[4][4],int n){

	int a=0;
	int b=n-1;
	while(a<b){
		if(knows(array,a,b)){
			a++;
		}else{
			b--;
		}
	}
	int i;
	for(i=0;i<n;i++){

		if(i!=a && (knows(array,a,i) || !knows(array,i,a)) ){
			return -1;
		}
	}

	return a;
}
int isCelebrityExistByStack(int array[4][4],int n){

	struct LinkListNode *stack=NULL;
	int i;

	if(n<=1){
		return -1;
	}

	for(i=0;i<n;i++){
		pushToStackAsLinkList(&stack,i);
	}

	int a=popFromStackAsLinkList(&stack);
	int b=popFromStackAsLinkList(&stack);
	int c;
	if(n==2){
		if(knows(array,a,b)){
			c= b;
		}else{
			c= a;
		}
	}else {

		while(sizeOfLinkListRecursive(stack)>1){
			if(knows(array,a,b)){
				a=popFromStackAsLinkList(&stack);
			}else{
				b=popFromStackAsLinkList(&stack);
			}

		}
		c=popFromStackAsLinkList(&stack);
		if(knows(array,c,a)){
			c=a;
		}
		if(knows(array,c,b)){
			c=b;
		}

	}

	for(i=0;i<n;i++){

		if(i!=c && (knows(array,c,i) || !knows(array,i,c))){
			return -1;
		}
	}

	return c;

}

int findMaxDepthOfparentheses(char *str){

	struct StackAsArray *stack=createStackAsArray(100);
	int maxDepth,depth;
	maxDepth=0,depth=0;
	while(*str){
		if(*str=='('){
			pushToStackAsArray(stack,*str);
			depth++;
		}else if(isalnum(*str)||*str==' '){
			;
		}else{

			if(isEmptyStackAsArray(stack)){
				return -1;
			}
			if(!ismatchingPair(popFromStackAsArray(stack),*str)){
				return -1;
			}
			if(maxDepth<depth){
				maxDepth=depth;
			}
			depth--;
		}
		str++;
	}

	if(!isEmptyStackAsArray(stack)){
		return -1;
	}

	return maxDepth;
}

int longestValidParenthesesSubstring(char *str){

	struct StackAsArray *stack=createStackAsArray(100);

	int len,maxLen;
	len=maxLen=0;
	while(*str){

		if(*str=='('){
			pushToStackAsArray(stack,*str);
		} else {
			if (isEmptyStackAsArray(stack)) {
				pushToStackAsArray(stack, *str);
				len = 0;

			} else {

				if (ismatchingPair(popFromStackAsArray(stack), *str)) {
					len += 2;
					if (maxLen < len) {
						maxLen = len;
					}
				} else {
					len = 0;
				}

			}
		}
		str++;
	}

	return maxLen;
}
char * deParenthesesiationOfAlgebricExp(char *exp){

	int i,j=0;
	struct LinkListNode *stack=NULL;
	char *res=(char *)malloc(sizeof(char)*(strlen(exp)+1));

	pushToStackAsLinkList(&stack,0);
	for( i=0;exp[i]!='\0';i++){

		if(exp[i]=='(' && i==0){
			;
		}else if(exp[i]=='(' && i>0){

			if(exp[i-1]=='('){
				pushToStackAsLinkList(&stack,stack->data);
			}else if(exp[i-1]=='-'){

				pushToStackAsLinkList(&stack,(stack->data==1?0:1));

			}else if(exp[i-1]=='+'){
				pushToStackAsLinkList(&stack,stack->data);
			}
		}else if(exp[i]==')'){

			popFromStackAsLinkList(&stack);
		}else if(exp[i]=='+'){
			if(stack->data==0){
				res[j++]='+';
			}else{
				res[j++]='-';
			}
		}else if(exp[i]=='-'){

			if(stack->data==0){
				res[j++]='-';
			}else{
				res[j++]='+';
			}
		}else{
			res[j++]=exp[i];
		}
	}

	res[j]='\0';
	return res;


}

int reverseNumberByStack(int number){

	struct LinkListNode *stack=NULL;

	while(number){
		pushToStackAsLinkList(&stack,number%10);
		number=number/10;
	}

	int count=1;
	int rev=0;

	while(!isEmptyStackAsLinkList(stack)){

		rev=rev+count*popFromStackAsLinkList(&stack);
		count=count*10;
	}

	return rev;
}

int isStackpermutation(int first[],int second[],int size){

	struct LinkListNode *stack=NULL;
	int i,j,count=0;


	for(i=0,j=0;i<size && j<size;i++){

		if(!isEmptyStackAsLinkList(stack) && stack->data==second[j]){
			popFromStackAsLinkList(&stack);
			count++;
			j++;
			i--;
		}else if(first[i]==second[j]){
			pushToStackAsLinkList(&stack,first[i]);
			popFromStackAsLinkList(&stack);
			count++;
			j++;
		}else{
			pushToStackAsLinkList(&stack,first[i]);
		}
	}
	while(!isEmptyStackAsLinkList(stack)){

		if(second[j]==stack->data){
			popFromStackAsLinkList(&stack);
			count++;
			j++;
		}else{
			return 0;
		}
	}

	return i==3 && isEmptyStackAsLinkList(stack);

}
int main(void) {

/*
	struct StackAsArray *stackAsArray=createStackAsArray(100);

	pushToStackAsArray(stackAsArray,'a');
	pushToStackAsArray(stackAsArray,'b');
	pushToStackAsArray(stackAsArray,'c');
	pushToStackAsArray(stackAsArray,'d');

	while(!isEmptyStackAsArray(stackAsArray))
		printf("%c ",popFromStackAsArray(stackAsArray));
*/


/*
	struct LinkListNode *stackAsLinkList=NULL;

	pushToStackAsLinkList(&stackAsLinkList,1);
	pushToStackAsLinkList(&stackAsLinkList,2);
	pushToStackAsLinkList(&stackAsLinkList,3);
	pushToStackAsLinkList(&stackAsLinkList,4);
	pushToStackAsLinkList(&stackAsLinkList,5);

	while(!isEmptyStackAsLinkList(stackAsLinkList)){
		printf("%d ",popFromStackAsLinkList(&stackAsLinkList));

	}
*/
/*

	char str[100];
	gets(str);
	infixToPostfixCoversion(str);

*/

/*
	char *str=(char *)malloc(100*sizeof(char));
	gets(str);
	postfixExpEvaluation(str);
*/

/*
	char *str=(char *)malloc(100*sizeof(char));
	gets(str);
	int val=areParenthesesBalanced(str);
	printf("val=%d",val);
*/

/*
	char *str=(char *)malloc(100*sizeof(char));
	gets(str);
	reverseStringUsingStack(str);
	printf("%s",str);
*/

/*
	struct StackAsArray *stack=createStackAsArray(100);
	pushToStackAsArray(stack,'a');
	pushToStackAsArray(stack,'b');
	pushToStackAsArray(stack,'c');
	pushToStackAsArray(stack,'d');


	traverseStackAsArray(stack);
	reverseStackAsArrayUsingRecursion(stack);
	traverseStackAsArray(stack);
*/


/*
	struct LinkListNode *stack=NULL;
	pushToStackAsLinkList(&stack,9);
	pushToStackAsLinkList(&stack,1);
	pushToStackAsLinkList(&stack,4);
	pushToStackAsLinkList(&stack,2);

	printLinklist(stack);
	sortStackAsLinkListUsingRecursion(&stack);
	printLinklist(stack);
*/

/*
	int array[]={4,10,1,5,7};
	int size=5,i,j,next=-1;
	for (i = 0; i < size; i++) {
		next = -1;
		for (j = i + 1; j < size; j++) {

			if (array[j] > array[i]) {
				next = array[j];
				break;
			}
		}
		printf("%d--->%d\n", array[i], next);
	}
*/

/*
	int array[]={10,9,11,1,12,6};
	int size=6;
	NextgreaterElement(array,size);
*/

/*
	int array[]={100,80,60,70,60,75,85};
	int size=7,i,j;
	int spanArray[7]={0};

	for(i=0;i<size;i++){

		for(j=i;j>=0 && array[j] <=array[i];j--){
			spanArray[i]++;
		}
	}

	for(i=0;i<size;i++){
		printf("%d ",spanArray[i]);
	}
*/
/*
	int size=7,i;
	int array[]={100,80,60,70,60,75,85};

	int *spanArray=(int *)calloc(size,sizeof(int));

	stockspanCalculation(array,size,spanArray);

	for(i=0;i<size;i++){
		printf("%d ",spanArray[i]);
	}
*/

/*

	implementTwoStackInArray();

*/
/*

    implementSpacialStackWithGetMinIn_O1_Time();

*/

/*

	implementStackWithMiddleElementOperationsIn_O1_Time();
*/
/*

	implementStackWithMergeStackFunctionIn_O1_Time();
*/


/*

	implementStackUsingMinHeap();

*/

/*
	implementStackWithGetMinin_O1_Space();

*/

/*
	sortStackbyusingAnotherTempStack();
*/
/*
	implementTowerOfHanoiByStack();
*/

/*
	char *str = (char *) malloc(sizeof(char) * 100);
	gets(str);
	evaluateInfixExpression(str);

*/

/*
	int n=4;
	int array[4][4]={{0,0,0,1},
			       {0,0,0,0},
			       {0,0,0,1},
			       {0,0,0,0}};

	printf("celeb id=%d\n",isCelebrityExist(array,n));
	printf("celeb id=%d\n",isCelebrityExistByStack(array,n));

*/
/*

	char *s="( a(b) (c) (d(e(f)g)h) I (j(k)l)m)";
	printf("depth=%d",findMaxDepthOfparentheses(s));
*/
/*

	char *str=")()(()))";
	printf("longest valid parentheses substring=%d",longestValidParenthesesSubstring(str));

*/

/*
	char *str="(((a+b)-(c+d))+m)";
	printf("algebric exp without parenthese=%s",deParenthesesiationOfAlgebricExp(str));
*/

/*

	printf("rev of num=%d",reverseNumberByStack(1003));

*/

/*
	int arr1[]={1,2,3};
	int arr2[]={3,2,1};
	printf("are stack permutations =%d",isStackpermutation(arr1,arr2,3));

*/

	return EXIT_SUCCESS;
}
