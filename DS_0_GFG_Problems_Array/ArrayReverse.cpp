/*
 * ArrayReverse.cpp
 *
 *  Created on: Aug 24, 2024
 *      Author: anura
 */


#include <iostream>
#include <array>
#include <stack>
#include <algorithm>

using namespace std;

int main(){


	//using reverse method
	array<int,5 > arr{1,2,3,4,5};

	for_each(begin(arr),end(arr),[](auto e){cout<<e<<" ";});


	reverse(begin(arr), end(arr));

	cout<<endl;

	for_each(begin(arr),end(arr),[](auto e){cout<<e<<" ";});

	cout<<endl;



	//using stack

	stack<int> stack1;

	for_each(begin(arr),end(arr),[&stack1](auto e){stack1.push(e);});

	while(!stack1.empty()){

		cout<<stack1.top()<<" ";
		stack1.pop();
	}



	return 0;
}



