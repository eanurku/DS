/*
 ============================================================================
 Name        : test.c
 Author      : Anurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int minoftwo(int a,int b){
	return a>b?b:a;
}
int minofthree(int a,int b,int c){

	return minoftwo(a,minoftwo(b,c));
}
int maxoftwo(int a,int b){
	return a>b?a:b;
}
int maxofthree(int a,int b,int c){
	return maxoftwo(a,maxoftwo(b,c));
}

int getMedian(int *array,int n){
	int median;
	if(n%2){
		median=array[n/2];
	}else{
		median=array[n/2-1]+array[n/2];
	}
	return median;
}

int getMedianOfEqualSizeSortedArrays2(int *a1,int *a2,int n){
	if(n==1)
		return (a1[0]+a2[0])/2;
	if(n==2)
		return (maxoftwo(a1[0],a2[0])+minoftwo(a1[1],a2[1]))/2;

	int median1=getMedian(a1,n);
	int median2=getMedian(a2,n);

	if(median1==median2)
		return median1;
	else if(median1<median2){
		if(n%2)
			return getMedianOfEqualSizeSortedArrays2(a1+n/2,a2,n-n/2);
		else
			return getMedianOfEqualSizeSortedArrays2(a1+n/2-1,a2,n-n/2+1);
	}else{
		if(n%2)
			return getMedianOfEqualSizeSortedArrays2(a1,a2+n/2,n-n/2);
		else
			return getMedianOfEqualSizeSortedArrays2(a1,a2+n/2-1,n-n/2+1);
	}
}
int main(void) {


/*
	int size1,size2;

	scanf("%d",&size1);
	int array1[size1];
	for(int i=0;i<size1;i++){
		scanf("%d",&array1[i]);
	}
	scanf("%d",&size2);
	int array2[size2];
	for(int i=0;i<size2;i++){
		scanf("%d",&array2[i]);
	}
*/
	int array1[]={1,12,15,26,38};
	int array2[]={2,13,17,30,45};
	int size1=sizeof(array1)/sizeof(array1[0]);
	int size2=sizeof(array2)/sizeof(array2[0]);
	printf("%d",getMedianOfEqualSizeSortedArrays2(array1,array2,size1));

	return 0;
}
