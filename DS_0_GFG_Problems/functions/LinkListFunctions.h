/*
 * LinkListFunctions.h
 *
 *  Created on: 13-Sep-2018
 *      Author: anurag
 */

#ifndef LINKLISTFUNCTIONS_H
#define LINKLISTFUNCTIONS_H

struct LinkListNode* getNewLinkListNode(int val);

void insertAtFrontLinkList(struct LinkListNode **headRef,int key);
void printLinklist(struct LinkListNode *headPtr);
int sizeOfLinkListRecursive(struct LinkListNode *ptr);

void reverseLinkList(struct LinkListNode **headRef);
struct LinkListNode* reverseInGroupOfSizeKLinkList(struct LinkListNode* head,int k);

struct LinkListNode* mergeSortedLinkList(struct LinkListNode* listA,struct LinkListNode* listB);
struct LinkListNode* mergeSortedLinkListRecursive(struct LinkListNode *listA,struct LinkListNode* listB);

void splitLinkList(struct LinkListNode* head,struct LinkListNode** a,struct LinkListNode** b);
struct LinkListNode * mergeSortOfLinkList(struct LinkListNode* head);

void rotateCounterClockwiseLinkList(struct LinkListNode **headRef,int k);

void removeLoopInLinkList(struct LinkListNode* head,struct LinkListNode* loopLinkListNode);
int isLoopExistThenRemoveitLinkList(struct LinkListNode* head);

struct LinkListNode* AddTwoLinkList(struct LinkListNode* listA,struct LinkListNode* listB);
struct LinkListNode* AddTwoLinkListRecursive(struct  LinkListNode* listA,struct LinkListNode* listB,int carry);


#endif /* LINKLISTFUNCTIONS_H_ */
