//============================================================================
// Name        : BST.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
#include<stdio.h>
using namespace std;

//  node structure
struct node
{
    int key;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do preorder traversal of BST
void preorder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
vector<struct node*> buildAllBSTForNumbers1ToN(int start,int end){

	vector<struct node*> list;
	int i,j,k;

	if(start>end){
		list.push_back(NULL);
		return list;
	}
	for(i=start;i<=end;i++){
		vector<struct node*> left=buildAllBSTForNumbers1ToN(start,i-1);
		vector<struct node*> right=buildAllBSTForNumbers1ToN(i+1,end);


		for(j=0;j<left.size();j++){

			struct node* leftnode=left[j];

			for(k=0;k<right.size();k++){

				struct node* root=newNode(i);
				root->left=leftnode;
				root->right=right[k];
				list.push_back(root);

			}
		}
	}

	return list;
}
int main() {

	vector<struct node*> list=buildAllBSTForNumbers1ToN(1,3);
	for(int i=0;i<list.size();i++){
		preorder(list[i]);
		printf("\n");
	}


	return 0;
}
