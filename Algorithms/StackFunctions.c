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
#include "commonDeclarations.h"



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

	return -INT_MIN;
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
		printf("underflow:stack empty");
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

			val1=popFromStackAsLinkList(&stack);
			val2=popFromStackAsLinkList(&stack);
			switch(*token){
			case '+':pushToStackAsLinkList(&stack,val2+val1);break;
			case '-':pushToStackAsLinkList(&stack,val2-val1);break;
			case '*':pushToStackAsLinkList(&stack,val2*val1);break;
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
	int i;

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

