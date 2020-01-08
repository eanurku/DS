/*
 ============================================================================
 Name        : DivideAndConquerProgramming.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define MAX_VALUE 10000

#include "/home/anurag/Desktop/CPROGG/DataStructure-geeksforgeeks_workspace/Algorithms/LinkListFunctions.h"
#include "/home/anurag/Desktop/CPROGG/DataStructure-geeksforgeeks_workspace/Algorithms/LinkListFunctions.c"

int binarySearchByDAndCRecursive(int array[],int start,int end,int element);
int binarySearchByDAndCIterative(int array[],int size,int element);
int randomizedBinarySearchRecursive(int array[],int start,int end,int key);

void splitArrayInTwoSubArray(int *array,int l,int r,int *m);
void mergeSortedArray(int *first,int *second,int l,int r,int m,int *array);
void mergeSortByDAndC(int *array,int l,int r);

void mergeSortedArray2(int *array,int l,int mid,int r);
void mergeSortByDAndCOptimized(int *array,int l,int r);

int partitionWithLastElementAsPivot(int array[],int start,int end);
int partitionWithFirstElementAsPivot(int array[],int start,int end);
void quickSortByDAndC(int array[],int start,int end);


int powerByDAndC(int x,int n);
int powerByDAndCOptimized(int x,int n);

int getElementWithSingleAppearenceByDAndC(int array[],int l,int r);

int mergeAndGetInversionCount(int *array,int l,int mid,int r);
int getInversionCount(int *array,int l,int r);

int getMaxSumCrossingMid(int *array,int start,int mid,int end);
int getMaxContiguousSubArraySum(int *array,int start,int end);

char * getCommonPrefixOfTwoString(char *str1,char *str2);
char * getLongestCommonPrefixInListOfWords(char *arrayOfWords[],int start,int end);

int searchInRowWiseAndColWiseSortedMatrix(int *matrix,int fromRow,int toRow,int fromCol,int toCol,int RowSize,int ColSize,int key);

int getMedian(int array[],int l,int r);
int getMedianOfEqualSizeSortedArrays(int a1[],int a2[],int l1,int r1,int l2,int r2);
int getMedianOfEqualSizeSortedArrays2(int *a1,int *a2,int n);

int getFloorOfElementInSortedArray(int *array,int start,int end,int key);
int getCeilingOfElementInSortedArray(int *array,int start,int end,int key);

int getClosestNumberInSortedArray(int *array,int start,int end,int key);
int getFixPointInSortedArray(int *array,int start,int end);

int getPeakElementInArray(int *array,int start,int end);

int getFirstIndexByBinarySearch(int *array,int start,int end,int key);
int getFirstIndexByBinarySearch2(int *array,int start,int end,int key);
int getLastIndexByBinarySearch(int *array,int start,int end,int key);

int isMajorityElementExistInSortedArray(int *array,int n,int key);
int getFrequencyOfElementInSortedArray(int *array,int size,int key);

int getKthElementFromTwoSortedArrays(int *array1,int *end1,int *array2,int *end2,int k);
int getElementWithSingleAppearanceInDuplicatedSortedArray(int *array,int start,int end);

int getIndexOfExtraElementInArray1(int *array1,int *array2,int n );
int getDuplicateElementInSortedArray(int *array,int size);

int getRotationCountInSortedArray(int *array,int start,int end);
int getIndexOfMinInSorteAndRotateddArray(int *array,int start,int end);

int getMaximumInBitonicArray(int *array,int l,int r,int n);

struct LinkListNode* getMiddleInLinkList(struct LinkListNode* start,struct LinkListNode *end );
struct LinkListNode* binarySearchInLinkList(struct LinkListNode* start,struct LinkListNode *end ,int key);

int getCountOfZeros(int *array,int l,int r,int n);

int getMissingNumberOfAPUtil(int *array,int l,int r,int firstTerm,int commonDiff,int n);
int getMissingNumberOfAP(int *array,int l,int r,int n);

int getCountOfTrailingZerosInFactorial(int num);
int getCountOfTrailingZerosInFactorial2(int num);
int getCountOfTrailingZerosInFactorial3(int num);

int getNumbersWhosefactorialsEndWithNZeros(int n);

int getBitonicPointInBitonicSequence(int *array,int l,int r,int n);

int getInversionPointInMonotonicallyIncreasingFunctionOptimizedUtil(int l,int r);
int getInversionPointInMonotonicallyIncreasingFunctionOptimized();


int getMinDayToEmptyTank(int capacity,int l);



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



int binarySearchByDAndCRecursive(int array[],int start,int end,int element){

	if(start>end) return -1;
	int mid=(start+end)/2;

	if(element<array[mid]){
		return binarySearchByDAndCRecursive(array,start,mid-1,element);
	}else if(element>array[mid]){
		return binarySearchByDAndCRecursive(array,mid+1,end,element);
	}
	return mid;
}
int binarySearchByDAndCIterative(int array[],int size,int element){

	int l=0;
	int r=size-1;
	int mid;
	while(l<=r){

		mid=(l+r)/2;
		if(element<array[mid]){
			r=mid-1;
		}else if(element>array[mid]){
			l=mid+1;
		}else if(element==array[mid]){
			return mid;
		}
	}
	return -1;
}

int getRandomValue(int start,int end){

	srand(time(NULL));

	return start+random()%(end-start+1);
}
int randomizedBinarySearchRecursive(int array[],int start,int end,int key){

	if(start>end) return -1;

	int randomMid=getRandomValue(start,end);

	if(key==array[randomMid])
		return randomMid;
	else if(key<array[randomMid])
		return randomizedBinarySearchRecursive(array,start,randomMid-1,key);
	else
		return randomizedBinarySearchRecursive(array,randomMid+1,end,key);



}
void splitArrayInTwoSubArray(int *array,int l,int r,int *m){

	int slow,fast;

	slow=l;
	fast=l;

	while(slow<=r && fast<=r && fast+2<=r){

		slow+=1;
		fast+=2;
	}

	*m=slow;
}

void mergeSortedArray(int *first,int *second,int l,int r,int m,int *array){

	int leftSize=m-l+1;
	int rightSize=r-m;

	int left[leftSize];
	int right[rightSize];

	int i,j,k;

	for(i=0;i<leftSize;i++){
		left[i]=array[l+i];
	}
	for(i=0;i<rightSize;i++){
		right[i]=array[m+1+i];
	}

	i=0;j=0,k=l;;

	while(i<leftSize && j<rightSize){

		if(left[i]<right[j]){
			array[k++]=left[i];
			i++;
		}else {

			array[k++]=right[j];
			j++;
		}
	}
	while(i<leftSize){

		array[k++]=left[i];
		i++;
	}
	while(j<rightSize){
		array[k++]=right[j];
		j++;
	}
}


void mergeSortByDAndC(int *array,int l,int r){


	if(l>=r) return;
	int m;
	int *first=array;
	int *second=array;

	splitArrayInTwoSubArray(array,l,r,&m);

	mergeSortByDAndC(first,l,m);
	mergeSortByDAndC(second,m+1,r);

	mergeSortedArray(first,second,l,r,m,array);
}

void mergeSortedArray2(int *array,int l,int mid,int r){

	int leftArraySize=mid-l+1;
	int rightArraySize=r-mid;

	int leftArray[leftArraySize];
	int rightArray[rightArraySize];

	int i,j;
	for(i=0;i<leftArraySize;i++){
		leftArray[i]=array[l+i];
	}
	for(j=0;j<rightArraySize;j++){
		rightArray[j]=array[j+mid+1];
	}
	i=0;j=0;
	int k=l;
	while(i<leftArraySize && j<rightArraySize){

		if(leftArray[i]<rightArray[j]){
			array[k++]=leftArray[i];
			i++;
		}else {
			array[k++]=rightArray[j];
			j++;
		}
	}
	while(i<leftArraySize){
		array[k++]=leftArray[i];
		i++;
	}
	while(j<rightArraySize){
		array[k++]=rightArray[j];
		j++;
	}

}

void mergeSortByDAndCOptimized(int *array,int l,int r){

	if(l>=r)
		return ;

	int mid=(l+r)/2;
	mergeSortByDAndCOptimized(array,l,mid);
	mergeSortByDAndCOptimized(array,mid+1,r);

	mergeSortedArray2(array,l,mid,r);

}
void swap(int *arr, int index1, int index2) {
	int tmp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tmp;

}

int partitionWithLastElementAsPivot(int array[],int start,int end){

	int i,j,pivot=array[end];

	i=start-1;

	for(j=start;j<=end-1;j++){

		if(array[j]<pivot){
			i++;
			swap(array,i,j);
		}
	}

	swap(array,i+1,end);

	return i+1;
}

int partitionWithFirstElementAsPivot(int array[],int start,int end){

	int i,j,pivot=array[start];

	i=start;

	for(j=start+1;j<=end;j++){

		if(array[j]<pivot){
			i++;
			swap(array,i,j);
		}
	}

	swap(array,i,start);

	return i;
}


void quickSortByDAndC(int array[],int start,int end){

	if(start>=end) return ;

	int pivotIndex=partitionWithFirstElementAsPivot(array,start,end);

	quickSortByDAndC(array,start,pivotIndex-1);
	quickSortByDAndC(array,pivotIndex+1,end);
}

int powerByDAndC(int x,int n){

	if(n==0) return 1;

	int val=powerByDAndC(x,n/2)*powerByDAndC(x,n/2);

	if(n%2){
		val*=x;
	}

	return val;
}
int powerByDAndCOptimized(int x,int n){

	if(n==0) return 1;

	int val=powerByDAndC(x,n/2);

	if(n%2){
		return x*val*val;
	}

	return val*val;
}

int getElementWithSingleAppearenceByDAndC(int array[],int l,int r){


	if(l>r) return -1;
	if(l==r)
		return array[l];
	int mid=(l+r)/2;

	if(mid%2){

		    if(array[mid]==array[mid-1])
				return getElementWithSingleAppearenceByDAndC(array,mid+1,r);

			else
				return getElementWithSingleAppearenceByDAndC(array,l,mid-1);

	}else{

	    if(array[mid]==array[mid+1])
			return getElementWithSingleAppearenceByDAndC(array,mid+2,r);

		else
			return getElementWithSingleAppearenceByDAndC(array,l,mid-2);

	}

}
int mergeAndGetInversionCount(int *array,int l,int mid,int r){

	int n1=mid-l+1;
	int n2=r-mid;
	int left[n1];
	int right[n2];
	int i,j,k;

	for(i=0;i<n1;i++){
		left[i]=array[l+i];
	}
	for(j=0;j<n2;j++){
		right[j]=array[mid+1+j];
	}

	i=0,j=0,k=l;
	int count=0;
	while(i<n1 && j<n2){

		if(left[i]<right[j]){

			array[k++]=left[i++];
		}else{
			count+=mid-i+1;
			array[k++]=right[j++];
		}
	}

	while(i<n1){
		array[k++]=left[i++];
	}
	while(j<n2){
		array[k++]=right[j++];
	}

	return count;
}
int getInversionCount(int *array,int l,int r){

	if(l>=r) return 0;
	int mid;

	 mid=(l+r)/2;
	int leftCount=getInversionCount(array,l,mid);
	int rightCount=getInversionCount(array,mid+1,r);

	int crossCount=mergeAndGetInversionCount(array,l,mid,r);

	return leftCount+rightCount+crossCount;
}
int getMaxSumCrossingMid(int *array,int start,int mid,int end){

	int sum=0;
	int i,leftSum=INT_MIN;
	for(i=mid;i>=start;i--){

		sum+=array[i];
		if(sum>leftSum){
			leftSum=sum;
		}
	}

	sum=0;
	int j,rightSum=INT_MIN;
	for(j=mid+1;j<=end;j++){
		sum+=array[j];
		if(sum>rightSum){
			rightSum=sum;
		}
	}

	return leftSum+rightSum;

}
int getMaxContiguousSubArraySum(int *array,int start,int end){


	if(start==end) return array[start];
	int mid=(start+end)/2;

	return maxofthree(getMaxContiguousSubArraySum(array,start,mid),getMaxContiguousSubArraySum(array,mid+1,end),
			getMaxSumCrossingMid(array,start,mid,end));
}

char * getCommonPrefixOfTwoString(char *str1,char *str2){


	int len=1+minoftwo(strlen(str1),strlen(str2));
	char *pre=(char *)malloc(sizeof(char)*len);

	int i=0;
	while(*str1==*str2){

		*(pre+i)=*str1;
		i++;
		str1++;
		str2++;
	}
	*(pre+i)='\0';
	return pre;

}
char * getLongestCommonPrefixInListOfWords(char *arrayOfWords[],int start,int end){


	if(start==end) return arrayOfWords[start];
	int mid=(start+end)/2;
	char *leftPrefix=getLongestCommonPrefixInListOfWords(arrayOfWords,start,mid);
	char *rightPrefix=getLongestCommonPrefixInListOfWords(arrayOfWords,mid+1,end);

	return getCommonPrefixOfTwoString(leftPrefix,rightPrefix);
}


int searchInRowWiseAndColWiseSortedMatrix(int *matrix,int fromRow,int toRow,int fromCol,int toCol,int RowSize,int ColSize,int key){


	if(fromRow>toRow||fromCol>toCol) return 0;
	int mid_row=(fromRow+toRow)/2;
	int mid_col=(fromCol+toCol)/2;

	if(key==*(matrix+ColSize*mid_row+mid_col)) return 1;
	else{

		if(key<*(matrix+ColSize*mid_row+mid_col)){

			return searchInRowWiseAndColWiseSortedMatrix(matrix,fromRow,mid_row-1,mid_col,toCol,RowSize,ColSize,key)||
					 searchInRowWiseAndColWiseSortedMatrix(matrix,fromRow,toRow,fromCol,mid_col-1,RowSize,ColSize,key);
		}else{
			return searchInRowWiseAndColWiseSortedMatrix(matrix,fromRow,mid_row,mid_col+1,toCol,RowSize,ColSize,key)||
					searchInRowWiseAndColWiseSortedMatrix(matrix,mid_row+1,toRow,fromCol,toCol,RowSize,ColSize,key);
		}

	}

}

int getMedian(int array[],int l,int r){

	int size=r-l+1;
	int median;
	if(size%2){
		median=array[l+size/2];
	}else{
		median=array[l+size/2-1]+array[l+size/2];
	}

	return median;
}

int getMedianOfEqualSizeSortedArrays(int a1[],int a2[],int l1,int r1,int l2,int r2){


	if(r1-l1+1==1)
		return (a1[l1]+a2[l2])/2;
	if(r1-l1+1==2)
		return (maxoftwo(a1[l1],a2[l2])+minoftwo(a1[r1],a2[r2]))/2;

	int median1=getMedian(a1,l1,r1);
	int median2=getMedian(a2,l2,r2);

	if(median1==median2)
		return median1;
	else if(median1<median2){

		if((r1-l1+1)%2)
		return getMedianOfEqualSizeSortedArrays(a1,a2,l1+(r1-l1+1)/2,r1,l2,l2+(r2-l2+1)/2);
		else
		return getMedianOfEqualSizeSortedArrays(a1,a2,l1+(r1-l1+1)/2-1,r1,l2,l2+(r2-l2+1)/2);

	}else{
		if((r1-l1+1)%2)
		return getMedianOfEqualSizeSortedArrays(a1,a2,l1,l1+(r1-l1+1)/2 ,l2+(r2-l2+1)/2,r2);
		else
			return getMedianOfEqualSizeSortedArrays(a1,a2,l1,l1+(r1-l1+1)/2,l2+(r2-l2+1)/2-1,r2);
	}


}

int getMedianOfEqualSizeSortedArrays2(int *a1,int *a2,int n){


	if(n==1)
		return (a1[0]+a2[0])/2;
	if(n==2)
		return (maxoftwo(a1[0],a2[0])+minoftwo(a1[1],a2[1]))/2;

	int median1=getMedian(a1,0,n-1);
	int median2=getMedian(a2,0,n-1);

	if(median1==median2)
		return median1;
	else if(median1<median2){

		if(n%2)
			return getMedianOfEqualSizeSortedArrays2(a1+n/2,a2,n-n/2);
		else
			return getMedianOfEqualSizeSortedArrays2(a1+n/2-1,a2,n/2+1);

	}else{
		if(n%2)
			return getMedianOfEqualSizeSortedArrays2(a1,a2+n/2,n-n/2);
		else
			return getMedianOfEqualSizeSortedArrays2(a1,a2+n/2-1,n/2+1);
	}


}

int getFloorOfElementInSortedArray(int *array,int start,int end,int key){


	if(key>=array[end])
		return array[end];

	if(start>end)
		return -1;

	int mid=(start+end)/2;


	if(mid>0 && key>=array[mid-1] && key<array[mid])
		return array[mid-1];

	if(key==array[mid])
		return array[mid];
	if(key<array[mid])
		return getFloorOfElementInSortedArray(array,start,mid-1,key);
	else
		return getFloorOfElementInSortedArray(array,mid+1,end,key);

}

int getCeilingOfElementInSortedArray(int *array,int start,int end,int key){

	if(start>end)
		return -1;

	if(key<=array[start])
		return array[start];

	int mid=(start+end)/2;

	if(mid>0 && key<array[mid] && key>array[mid-1])
		return array[mid];

	if(key==array[mid])
		return array[mid];

	else if(key<array[mid])
		return getCeilingOfElementInSortedArray(array,start,mid-1,key);
	else
		return getCeilingOfElementInSortedArray(array,mid+1,end,key);

}

int getClosestValue(int val1,int val2,int key){
	if(key-val1<val2-key)
		return val1;
	else
		return val2;

}
int getClosestNumberInSortedArray(int *array,int start,int end,int key){

	if(key<=array[start])
		return array[start];

	if(key>=array[end])
		return array[end];

	int mid=(start+end)/2;

	if(key==array[mid])
		return array[mid];

	if (key < array[mid]) {

		if (mid > 0 && key > array[mid - 1] && key < array[mid])
			return getClosestValue(array[mid-1],array[mid],key);

		return getClosestNumberInSortedArray(array, start, mid - 1, key);
	} else {


		if (mid < end && key > array[mid] && key < array[mid + 1])
			return getClosestValue(array[mid],array[mid+1],key);


		return getClosestNumberInSortedArray(array, mid + 1, end, key);
	}
}

int getFixPointInSortedArray(int *array,int start,int end){

	if(start>end) return -1;

	int mid=(start+end)/2;

	if(mid==array[mid])
		return mid;
	else if(mid<array[mid])
		return getFixPointInSortedArray(array,start,mid-1);
	else
		return getFixPointInSortedArray(array,mid+1,end);

}

int getPeakElementInArray(int *array,int start,int end){

	int mid=(start+end)/2;

	if((mid==0 || array[mid]>=array[mid-1]) && (mid==end || array[mid]>=array[mid+1])){
		return array[mid];
	}else if(mid>0 && array[mid-1]>array[mid]){
		return getPeakElementInArray(array,start,mid-1);
	}else{
		return getPeakElementInArray(array,mid+1,end);
	}

}

int getFirstIndexByBinarySearch(int *array,int start,int end,int key){

	if(start>end)
		return -1;
	int mid=(start+end)/2;

	if( array[mid]==key && (mid==0|| array[mid-1]!=array[mid]))
		return mid;

	else if(key<array[mid]|| (mid>0 &&  key==array[mid-1])){
		return getFirstIndexByBinarySearch(array,start,mid-1,key);
	}else {
		return getFirstIndexByBinarySearch(array,mid+1,end,key);
	}


}

int getFirstIndexByBinarySearch2(int *array,int start,int end,int key){

	if(start>end)
		return -1;
	int mid=(start+end)/2;

	if( array[mid]==key && (mid==0|| key>array[mid-1]))
		return mid;

	else if(key<=array[mid]){
		return getFirstIndexByBinarySearch(array,start,mid-1,key);
	}else {
		return getFirstIndexByBinarySearch(array,mid+1,end,key);
	}

}
int isMajorityElementExistInSortedArray(int *array,int n,int key){


	int firstIndex=getFirstIndexByBinarySearch2(array,0,n-1,key);

	if(firstIndex==-1)
		return 0;

	if(firstIndex+n/2<=n-1 && array[firstIndex+n/2]==key){
		return 1;
	}

	return 0;
}

int getKthElementFromTwoSortedArrays(int *array1,int *end1,int *array2,int *end2,int k){

	if(array1==end1){
		return array2[k];
	}
	if(array2==end2){
		return array1[k];
	}


	int mid1=(end1-array1)/2;
	int mid2=(end2-array2)/2;


	if (k > mid1 + mid2) {

		if (array1[mid1] > array2[mid2]) {
			return getKthElementFromTwoSortedArrays(array1,end1,array2+mid2+1,end2,k-(mid2+1));
		} else {
			return getKthElementFromTwoSortedArrays(array1+mid1+1,end1,array2,end2,k-(mid1+1));
		}

	} else {

		if (array1[mid1] > array2[mid2]) {
			return getKthElementFromTwoSortedArrays(array1,array1+mid1,array2,end2,k);
		} else {
			return getKthElementFromTwoSortedArrays(array1,end1,array2,array2+mid2,k);
		}
	}
}
int getLastIndexByBinarySearch(int *array,int start,int end,int key){

	if(start>end)
		return -1;

	int mid=(start+end)/2;

	if(array[mid]==key && (mid==end||key!=array[mid+1]))
		return mid;
	else if(key>=array[mid]){
		return getLastIndexByBinarySearch(array,mid+1,end,key);
	}else{
		return getLastIndexByBinarySearch(array,start,mid-1,key);
	}

}

int getFrequencyOfElementInSortedArray(int *array,int size,int key){

	int firstIndex=getFirstIndexByBinarySearch2(array,0,size-1,key);

	if(firstIndex==-1)
		return 0;
	int lastIndex=getLastIndexByBinarySearch(array,0,size-1,key);

	return lastIndex-firstIndex+1;

}

int getElementWithSingleAppearanceInDuplicatedSortedArray(int *array,int start,int end){

	if(start==end)
		return array[start];
	int mid=(start+end)/2;
	if(mid%2){
		if(array[mid]==array[mid-1]){
			return getElementWithSingleAppearanceInDuplicatedSortedArray(array,mid+1,end);
		}else{
			return getElementWithSingleAppearanceInDuplicatedSortedArray(array,start,mid-1);
		}
	}else{
		if(array[mid]==array[mid+1]){
			return getElementWithSingleAppearanceInDuplicatedSortedArray(array,mid+2,end);
		}else{
			return getElementWithSingleAppearanceInDuplicatedSortedArray(array,start,mid-2);
		}

	}

}


int getIndexOfExtraElementInArray1(int *array1,int *array2,int n ){

	int index=n;
	int l=0;
	int r=n-1;
	int mid;

	while(l<=r){

		mid=(l+r)/2;
		if(array1[mid]==array2[mid]){
			l=mid+1;
		}else{
			index=mid;
			r=mid-1;
		}
	}

	return index;
}


int getDuplicateElementInSortedArray(int *array,int size){


	int index=-1;;
	int mid;


	int l=0;
	int r=size-1;
	while(l<=r){

		mid=(l+r)/2;
		if(mid+1==array[mid]){
			l=mid+1;
		}else{
			index=mid;
			r=mid-1;
		}
	}

	return array[index];
}

int getRotationCountInSortedArray(int *array,int start,int end){


	if(start>end)
		return 0;

	int mid=(start+end)/2;
	if(mid<end && array[mid]>array[mid+1]){
		return mid+1;
	}else if(array[mid]<array[start]){
		return getRotationCountInSortedArray(array,start,mid-1);
	}else{
		return getRotationCountInSortedArray(array,mid+1,end);
	}
}

int getIndexOfMinInSorteAndRotateddArray(int *array,int start,int end){

	if(start>end)
		return 0;

	int mid=(start+end)/2;

	if(mid>0 && array[mid-1]>array[mid])
		return mid;

	if(mid<end && array[mid]>array[mid+1])
		return mid+1;

	if(array[start]>array[mid]){
		return getIndexOfMinInSorteAndRotateddArray(array,start,mid-1);
	}else{
		return getIndexOfMinInSorteAndRotateddArray(array,mid+1,end);
	}
}

int getMaximumInBitonicArray(int *array,int l,int r,int n){

	int mid=(l+r)/2;

	if((mid==0||array[mid]>array[mid-1])  && (mid==n-1 || array[mid]>array[mid+1])){
		return array[mid];
	}

	if(mid>0 && array[mid-1]>array[mid]){
		return getMaximumInBitonicArray(array,l,mid-1,n);
	}else{
		return getMaximumInBitonicArray(array,mid+1,r,n);
	}
}

struct LinkListNode* getMiddleInLinkList(struct LinkListNode* start,struct LinkListNode *end ){

	if(start==NULL) return NULL;
	if(start->next==end) return start;

	struct LinkListNode *slow=start;
	struct LinkListNode *fast=start;

	while(fast !=end && fast->next!=end){

		slow=slow->next;
		fast=fast->next->next;
	}

	return slow;



}
struct LinkListNode* binarySearchInLinkList(struct LinkListNode* start,struct LinkListNode *end ,int key){


	struct LinkListNode *mid=getMiddleInLinkList(start,end);



	if(mid->data ==key)
		return mid;
	else if(key>mid->data){
		return binarySearchInLinkList(mid->next,end,key);
	}else{
		return binarySearchInLinkList(start,mid,key);
	}
}

int getCountOfZeros(int *array,int l,int r,int n){

	if(l>r) return 0;
	int mid=(l+r)/2;

	if(array[mid]==0 && (mid==0 || array[mid-1]==1))
		return n-mid+1;
	else if(array[mid]==1){
		return getCountOfZeros(array,mid+1,r,n);
	}else{
		return getCountOfZeros(array,l,mid-1,n);
	}
}

int getMissingNumberOfAPUtil(int *array,int l,int r,int firstTerm,int commonDiff,int n){


	int mid=(l+r)/2;

	if(mid>0 && array[mid]-array[mid-1]!=commonDiff){

		return array[mid]-commonDiff;
	}
	if(mid<n && array[mid+1]-array[mid] !=commonDiff){
		return array[mid]+commonDiff;
	}

	if(firstTerm+mid*commonDiff==array[mid]){
		return getMissingNumberOfAPUtil(array,mid+1,r,firstTerm,commonDiff,n);
	}else{
		return getMissingNumberOfAPUtil(array,l,mid-1,firstTerm,commonDiff,n);
	}
}

int getMissingNumberOfAP(int *array,int l,int r,int n){

	int cd=(array[r]-array[l])/n;
	return getMissingNumberOfAPUtil(array,l,r,array[l],cd,n);

}

int getCountOfTrailingZerosInFactorial(int num){

	int i,count=0;

	for(i=1;(int)pow(5,i)<=num;i++){

		count+=num/(int)pow(5,i);
	}
	return count;
}
int getCountOfTrailingZerosInFactorial2(int num){

	int i,count=0;
	while(num>0){

		count+=num/5;
		num=num/5;
	}

	return count;
}
int getCountOfTrailingZerosInFactorial3(int num){

	int i,count=0;

	for(i=5;i<=num;i=i*5){

		count+=num/i;
	}

	return count;
}
int getNumbersWhosefactorialsEndWithNZeros(int n){

	//get first number with trailing zeros ==n
	int low=1;
	int high=MAX_VALUE;

	int mid,count;

	while(low<high){

		mid=(low+high)/2;
		count=getCountOfTrailingZerosInFactorial3(mid);

		if(count>=n){
			high=mid;
		}else{
			low=mid+1;
		}
	}
	for(int i=0;i<5;i++)
	  printf("%d, ",low+i);
}

int getBitonicPointInBitonicSequence(int *array,int l,int r,int n){


	if(l>r) return -1;

	int mid=(l+r)/2;

	if(mid>0 && array[mid]>array[mid-1] && mid<n && array[mid]>array[mid+1]){
		return array[mid];
	}else if(mid>0 && array[mid-1]>array[mid]){
		return getBitonicPointInBitonicSequence(array,l,mid-1,n);
	}else{
		return getBitonicPointInBitonicSequence(array,mid+1,r,n);
	}
}

int fun(int x){
	return (x*x - 10*x - 20);
}

int getInversionPointInMonotonicallyIncreasingFunction(int l, int r){

	if(fun(l)<=0 && fun(r)<=0){
		r=2*r;
    }
	if(fun(l)>0 && fun(r)>0){
		l=l/2;
	}
	int mid=(l+r)/2;


	if(fun(mid)>0 && fun(mid-1)<=0){
		return mid;
	}else if(fun(mid)>0){
		return getInversionPointInMonotonicallyIncreasingFunction(l,mid-1);
	}else{
		return getInversionPointInMonotonicallyIncreasingFunction(mid+1,r);
	}
}

int getInversionPointInMonotonicallyIncreasingFunctionOptimizedUtil(int l,int r){

	if(l>r) return -1;

	int mid=(l+r)/2;
	if(fun(mid)>0 && (mid==l||fun(mid-1)<=0)){

		return mid;
	}else if(fun(mid)>0){
		return getInversionPointInMonotonicallyIncreasingFunctionOptimizedUtil(l,mid-1);
	}else{
		return getInversionPointInMonotonicallyIncreasingFunctionOptimizedUtil(mid+1,r);
	}
}
int getInversionPointInMonotonicallyIncreasingFunctionOptimized(){


	if(fun(0)>0) return 0;

	int i=1;
	//get i for which f(i) is positive in logn
	while(fun(i)<=0){
		i=i*2;
	}
	//so inversion pont exist in [i/2,i]

	return getInversionPointInMonotonicallyIncreasingFunctionOptimizedUtil(i/2,i);
}

int getMinDayToEmptyTank(int capacity,int l){

	if(l>=capacity)
		return capacity;

	int low=0;
	int high=MAX_VALUE;//use max as <10^5 as mid*mid is there

	int mid;
	while(low<high){


		mid=(low+high)/2;

		if(capacity-(mid*(mid+1))/2 <=l){
			high=mid;

		}else{
			low=mid+1;
		}

	}

	return l+1+low-1;

}


int main(void) {
	/* Binary Search in a sorted Array
	 *
	 */
/*
	int array[]={2,4,6,9,20,40};
	int size=sizeof(array)/sizeof(array[0]);

	printf("\n%d",binarySearchByDAndCRecursive(array,0,size-1,9));
	printf("\n%d",binarySearchByDAndCIterative(array,size,9));
*/
	/* Merge Sort of an Array
	 *
	 */
/*
	int array[]={3,2,1,12,5,7,10,4};
	int size=sizeof(array)/sizeof(array[0]);
	mergeSortByDAndCOptimized(array,0,size-1);
	printf("\n");
	for(int i=0;i<size;i++){
		printf("%d ",array[i]);
	}

*/
	/* Quick Sort
	 *
	 */
/*
	int array[]={5,5,6,4,7,10,1,2,10,3,12};
	int size=sizeof(array)/sizeof(array[0]);

	quickSortByDAndC(array,0,size-1);
	printf("\n");

	for(int i=0;i<size;i++){
		printf("%d ",array[i]);
	}

*/
	/* calculate pow(x,n)=x^n
	 *
	 */
/*
	printf("\n%d",powerByDAndC(2,6));
	printf("\n%d",powerByDAndCOptimized(2,0));
*/

	/* Find the element that appears once in a sorted array
	 * Given a sorted array in which all elements appear twice (one after one) and one element appears only once. Find that element
	 * in O(log n) complexity.
	 *
	 * Input:   arr[] = {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8}
     * Output:  4
	 */

/*

	int array[]={1, 1, 2, 4, 4, 5, 5,6,6};
	int size=sizeof(array)/sizeof(array[0]);

	printf("%d",getElementWithSingleAppearenceByDAndC(array,0,size-1));
*/

	/*
	 * Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion
	 * count is 0. If array is sorted in reverse order that inversion count is the maximum.
     * Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
     * Example:
     * The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
	 */

/*
	int array[]={1, 20, 6, 4, 5};
	int size=sizeof(array)/sizeof(array[0]);

	printf("%d",getInversionCount(array,0,size-1));
*/

	/*
	 *
	 */
/*
	int array[]={-2, -5, 6, -2, -3, 1, 5, -6};
	int size=sizeof(array)/sizeof(array[0]);

	printf("%d",getMaxContiguousSubArraySum(array,0,size-1));
*/


	/*
	 * Longest Common prefix in list of words
	 */


/*
	char *arrayOfWords[]={"geeksforgeeks","geeks","geeker","geek","geela"};
	int size=sizeof(arrayOfWords)/sizeof(char *);

	printf("%s",getLongestCommonPrefixInListOfWords(arrayOfWords,0,size-1));
*/

/*
	int m=4;
	int n=4;
	int mat[4][4]={{2,6,8,10},
			         {5,11,13,16},
					 {9,12,21,27},
					 {20,25,26,29}};


	int element=100;
	printf("%d",searchInRowWiseAndColWiseSortedMatrix(mat,0,m-1,0,n-1,m,n,element));
*/

	/*
	 * Randomized Binary Search
	 */

/*
	int array[]={2,4,6,9,20,40};
	int size=sizeof(array)/sizeof(array[0]);

	printf("index of element  = %d",randomizedBinarySearchRecursive(array,0,size-1,4));

*/

	/*
	 * median of equal size sorted array
	 */

/*

	int array1[]={1,12,15,26,38};
	int array2[]={2,13,17,30,45};
	int size1=sizeof(array1)/sizeof(array1[0]);
	int size2=sizeof(array2)/sizeof(array2[0]);

	printf("%d\n",getMedianOfEqualSizeSortedArrays(array1,array2,0,size1-1,0,size2-1));
	printf("%d\n",getMedianOfEqualSizeSortedArrays2(array1,array2,size1));
*/

	/*
	 * Floor in a Sorted Array
	 * Ceil in Sorted Array
	 */
/*
	int array[]={2,4,6};
	int size=sizeof(array)/sizeof(array[0]);

	printf("%d\n",getFloorOfElementInSortedArray(array,0,size-1,5));
	printf("%d\n",getCeilingOfElementInSortedArray(array,0,size-1,11));
*/

	/*
	 * find closest no in sorted array
	 */

/*
	int array[]={1, 2, 8, 10, 13, 19,21};
	int size=sizeof(array)/sizeof(array[0]);

	printf("%d\n",getClosestNumberInSortedArray(array,0,size-1,11));
*/

	/*
	 * Find a Fixed Point (Value equal to index) in a given array
	 *
	 * Given an array of n distinct integers sorted in ascending order, write a function that returns a Fixed Point in the array,
	 * if there is any Fixed Point present in array, else returns -1. Fixed Point in an array is an index i such that arr[i] is
	 * equal to i. Note that integers in array can be negative.
	 */
/*

	int array[]={-10, -5, 0, 3, 7};
	int size=sizeof(array)/sizeof(array[0]);

	printf("%d",getFixPointInSortedArray(array,0,size-1));
*/

	/*
	 * find peak element in sorted array
	 * Given an array of integers. Find a peak element in it. An array element is peak if it is NOT smaller than its neighbors.
	 * For corner elements, we need to consider only one neighbor. For example, for input array {5, 10, 20, 15}, 20 is the only
	 * peak element. For input array {10, 20, 15, 2, 23, 90, 67}, there are two peak elements: 20 and 90. Note that we need to
	 * return any one peak element.
	 */
/*
	int array[]={5,10};
	int size=sizeof(array)/sizeof(array[0]);

	printf("%d",getPeakElementInArray(array,0,size-1));
*/

	/*
	 * Write a C function to find if a given integer x appears more than n/2 times in a sorted array of n integers.
	 */

/*
	int array[]={1,1,1,2,3};
	int size=sizeof(array)/sizeof(array[0]);

	printf("%d",isMajorityElementExistInSortedArray(array,size,1));

*/
	int array1[]={1,2,3,8,10,12};
	int array2[]={-1,0,5,9,11};
	int size1=sizeof(array1)/sizeof(array1[0]);
	int size2=sizeof(array2)/sizeof(array2[0]);

	int k=6;
	printf("kth=%d",getKthElementFromTwoSortedArrays(array1,array1+size1,array2,array2+size2,k-1));

	/*
	 * count freq of x in sorted array
	 */

/*
	int array[]={1, 1, 2, 2, 2, 2, 3};
	int size=sizeof(array)/sizeof(array[0]);
	int key=2;
	printf("%d",getFrequencyOfElementInSortedArray(array,size,key));
*/

	/*
	 * Find the element that appears once in a sorted array
	 */
/*
	int array[] = { 1, 2, 2, 4, 4, 5, 5, 6, 6 };
	int size = sizeof(array) / sizeof(array[0]);

	printf("%d",getElementWithSingleAppearanceInDuplicatedSortedArray(array, 0,size - 1));
*/

	/*
	 * Find index of an extra element present in one sorted array
	 */
/*
	int array1[]={1,2,4,6};
	int array2[]={2,4,6};
	int size1=sizeof(array1)/sizeof(array1[0]);
	int size2=sizeof(array2)/sizeof(array2[0]);

	printf("%d",getIndexOfExtraElementInArray1(array1,array2,size2));
*/


	/*
	 * Find the only repeating element in a sorted array of size n
	 */
/*
	int array[]={1,2,3,3,4,5};
	int size=sizeof(array)/sizeof(array[0]);

	printf("%d",getDuplicateElementInSortedArray(array,size));
*/


	/*
	 * Find the Rotation Count in Rotated Sorted array
	 */

/*
	int array[]={8,10,12,18,2,4,6};
	int size=sizeof(array)/sizeof(array[0]);

	printf("%d",getRotationCountInSortedArray(array,0,size-1));
*/

	/*
	 * Find the minimum element in a sorted and rotated array
	 */
/*
	int array[]={1};
	int size=sizeof(array)/sizeof(array[0]);

	printf("%d",getIndexOfMinInSorteAndRotateddArray(array,0,size-1));

*/
/*
	int array[]={1,2,3};
	int size=sizeof(array)/sizeof(array[0]);

	printf("%d",getMaximumInBitonicArray(array,0,size-1,size));

*/

/*
	struct LinkListNode *head=NULL;

	insertAtFrontLinkList(&head,5);
	insertAtFrontLinkList(&head,4);
	insertAtFrontLinkList(&head,3);
	insertAtFrontLinkList(&head,2);
	insertAtFrontLinkList(&head,1);


	printf("%d",binarySearchInLinkList(head,NULL,1)->data);
*/

	/*
	 * Given an array of 1s and 0s which has all 1s first followed by all 0s.Find the number of 0s. Count the number of
	 * zeroes in the given array.
	 */
/*
	int array[]={1,1,1,1};
	int size=sizeof(array)/sizeof(array[0]);

	printf("%d",getCountOfZeros(array,0,size-1,size-1));
*/

	/*
	 * Given an array that represents elements of arithmetic progression in order. One element is missing in the progression,
	 * find the missing number.
	 */
/*
	int array[]={2,4,8,10,12,14,16,18};
	int size=sizeof(array)/sizeof(array[0]);

	printf("%d",getMissingNumberOfAP(array,0,size-1,size-1));

*/

	/*
	 * Given an integer n, we need to find the number of positive integers whose factorial ends with n zeros.
	 */
/*

	printf("%d\n",getCountOfTrailingZerosInFactorial3(1000));
	getNumbersWhosefactorialsEndWithNZeros(20);
*/

	/* You are given a bitonic sequence, the task is to find Bitonic Point in it. A Bitonic Sequence is a sequence of numbers
	 * which is first strictly increasing then after a point strictly decreasing.
	 * A Bitonic Point is a point in bitonic sequence
	 * before which elements are strictly increasing and after which elements are strictly decreasing. A Bitonic point doesn’t
	 * exist if array is only decreasing or only increasing.
	 *
	 */
/*
	int array[]={6, 7, 8, 11};
	int size=sizeof(array)/sizeof(array[0]);

	printf("%d",getBitonicPointInBitonicSequence(array,0,size-1,size-1));

*/
	/* Given a function ‘int f(unsigned int x)’ which takes a non-negative integer ‘x’ as input and returns an integer as output.
	 * The function is monotonically increasing with respect to value of x, i.e., the value of f(x+1) is greater than f(x) for
	 * every input x. Find the value ‘n’ where f() becomes positive for the first time. Since f() is monotonically increasing,
	 * values of f(n+1), f(n+2),… must be positive and values of f(n-2), f(n-3), .. must be negative.Find n in O(logn) time,
	 * you may assume that f(x) can be evaluated in O(1) time for any input x.
	 *
	 */
/*
	printf("%d\n",getInversionPointInMonotonicallyIncreasingFunction(0,10));// 0 and 10 as initial random values.
    printf("%d\n",getInversionPointInMonotonicallyIncreasingFunctionOptimized());

*/
	/*
	 * Given a tank with capacity C liters which is completely filled in starting. Everyday tank is filled with l liters of water
	 * and in the case of overflow extra water is thrown out. Now on i-th day i liters of water is taken out for drinking. We need
	 * to find out the day at which tank will become empty the first time.
	 */
/*

	printf("%d",getMinDayToEmptyTank(5,2));

*/

	return EXIT_SUCCESS;
}
