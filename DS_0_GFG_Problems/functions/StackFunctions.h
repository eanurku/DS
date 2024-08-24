/*
 * StackFunctions.h
 *
 *  Created on: 13-Sep-2018
 *      Author: anurag
 */

#ifndef STACKFUNCTIONS_H
#define STACKFUNCTIONS_H

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


#endif /* STACKFUNCTIONS_H_ */
