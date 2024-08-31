/*
 * StackAsArray.cpp
 *
 *  Created on: Aug 31, 2024
 *      Author: anura
 */

#include <iostream>
using namespace std;

struct StackAsArray{
	char *array;
	int top;
	int capacity;
};

struct StackAsArray* createStackAsArray(int capacity);
int sizeOfStackAsArray(struct StackAsArray *stackAsArray);
int isFullStackAsArray(struct StackAsArray *stackAsArray);
int isEmptyStackAsArray(struct StackAsArray *stackAsArray);
int peekStackAsArray(struct StackAsArray *stackAsArray);
void traverseStackAsArray(struct StackAsArray *stackAsArray);
int pushToStackAsArray(struct StackAsArray *stackAsArray,char val);
int popFromStackAsArray(struct StackAsArray *stackAsArray);



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




int main(){


	cout<<"fuck off";

	return 0;
}


