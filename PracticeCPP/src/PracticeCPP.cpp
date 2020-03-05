//============================================================================
// Name        : TestCPP.cpp
// Author      : Anurag
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<algorithm>
using namespace std;


void show(int array[],int size){
	for(int i=0;i<7;i++){
	  printf("%d ",array[i]);
	}
	cout<<"\n";

}
int compare(int a,int b){

	return a-b;
}

int main(){

//sorting
//int array[]={2,1,3,4,11,22,13};
//int size=7;
//sort(array,array+size);
//show(array,size);
//sort(array,array+size,greater<int>());
//show(array,size);
//sort(array,array+size,compare);
//show(array,size);
//

//binary search
//int array[]={2,1,3,4,11,22,13};
//int size=7;
//sort(array,array+size);
//int found=binary_search(array,array+size,242);
//cout<<"found="<<found;
//

//Pair
pair<int,char> pair_1(11,'w');

cout<<pair_1.first<<" "<<pair_1.second<<endl;
pair_1=make_pair(12,'2');
cout<<pair_1.first<<" "<<pair_1.second<<endl;

































return 0;
}
