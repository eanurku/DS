//============================================================================
// Name        : DS_ZEXP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct LinkList{
	int data;
	struct LinkList* next;

};

struct LinkList*  getLinkListNode(int val){

	struct LinkList *node=(struct LinkList *)malloc(sizeof(struct LinkList));
	node->data=val;
	node->next=NULL;
	return node;
}

void printLinkList(struct LinkList* head){

	cout<<endl;
	while(head){
		cout<<head->data<<" ";
		head=head->next;
	}

}

int main() {

	struct LinkList* head=getLinkListNode(1);
	struct LinkList*ptr=head;

	ptr->next=getLinkListNode(2);
	ptr=ptr->next;

	ptr->next=getLinkListNode(3);
	ptr=ptr->next;

	ptr->next=getLinkListNode(4);
	ptr=ptr->next;

	ptr->next=getLinkListNode(5);
	ptr=ptr->next;


	printLinkList(head);





	return 0;
}
