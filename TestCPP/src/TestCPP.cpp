//============================================================================
// Name        : TestCPP.cpp
// Author      : Anurag
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<vector>

using namespace std;

struct LinkListNode{

	int data;
	struct LinkListNode *next;
};

void printLinkList(struct LinkListNode *list){

	while(list!=NULL){
		printf("%d%s",list->data,list->next?"->":"->NULL");
		list=list->next;
	}
}
struct LinkListNode* getLinkListNode(int value){

	struct LinkListNode * node=(struct LinkListNode *)malloc(sizeof(struct LinkListNode));
	node->data=value;
	node->next=NULL;
	return node;


}
void  insertAtFrontLinkList(struct LinkListNode** listRef,int value){

	struct LinkListNode * node=getLinkListNode(value);
	node->next=*listRef;
	*listRef=node;


}

void reverseLinkList(struct LinkListNode **headRef){


	struct LinkListNode *head=*headRef;
	struct LinkListNode *curr=head;
	struct LinkListNode *prev=NULL;

	while(curr){

		head=head->next;
		curr->next=prev;
		prev=curr;
		curr=head;
	}

	*headRef=prev;

}


int main(void){

	//Reverse Link List
//	struct LinkListNode *head=NULL;
//	insertAtFrontLinkList(&head,12);
//	insertAtFrontLinkList(&head,13);
//	insertAtFrontLinkList(&head,87);
//	insertAtFrontLinkList(&head,14);
//	insertAtFrontLinkList(&head,11);
//
//
//	printLinkList(head);
//
//	reverseLinkList(&head);
//
//	printf("\n");
//	printLinkList(head);

	//XOR swap
//	int a=12;
//	int b=26;
//	printf("before: %d,%d",a,b);
//	a^=b^=a^=b;
//	printf("\nAfter: %d,%d",a,b);

//file copy
//	char c;
//	c=getchar();
//	while(c!=EOF){
//		putchar(c);
//		c=getchar();
//
//	}
//
	//power of x^y
//	int base=4;
//	int power=6;
//	int i,result=1;
//
//	for(i=1;i<=power;i++){
//		result *=base;
//	}
//	printf("result=%d",result);

	//NULL in c
//
//	printf("%d",(void(*))0);

//string container


//	string str;
//	getline(cin,str);
//	cout<<str;
//	printf("%s",str.c_str());

//	char strseq[20];
//	scanf("%s",&strseq);
//	printf("%s",string(strseq).c_str());


//vector

	vector<string> vect;

	int numbers;
	char str[20];
	scanf("%d",&numbers);

	while(numbers>0){

		scanf("%s",&str);
		//printf("\n%s",str);

		vect.push_back(string(str));
		numbers--;
	}

	for(string s:vect){

		cout<<s<<endl;
	}




}
