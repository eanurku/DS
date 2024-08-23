/*
 * ArrayReverse.cpp
 *
 *  Created on: Aug 24, 2024
 *      Author: anura
 */


#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main(){


	array<int,5 > arr{1,2,3,4,5};

	for_each(begin(arr),end(arr),[](auto e){cout<<e<<" ";});


	reverse(begin(arr), end(arr));

	cout<<endl;

	for_each(begin(arr),end(arr),[](auto e){cout<<e<<" ";});



	return 0;
}



