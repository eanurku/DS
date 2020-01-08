
/*
 ============================================================================
 Name        : BinaryHeap.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "/home/anurag/Desktop/CPROGG/DataStructure-geeksforgeeks_workspace/Algorithms/BinaryTreeFunctions.c"
#include "/home/anurag/Desktop/CPROGG/DataStructure-geeksforgeeks_workspace/Algorithms/LinkListFunctions.c"

#define N 4
#define INF INT_MAX

struct Binaryheap {
	int *heapArray;
	int heapSize;
	int capacity;
};

void InitializeBinaryHeap(struct Binaryheap* heap, int capacity);

struct Binaryheap * createBinaryHeap(int capacity);
int getLeftIndexBinHeap(int parentIndex);
int getRightIndexBinHeap(int parentIndex);
int getParentIndexBinHeap(int childIndex);

void traverseBinHeap(struct Binaryheap* heap);

int getMinimumInMinHeap(struct Binaryheap* minHeap);
void heapifyOperationTopToBottomMinHeap(struct Binaryheap* minHeap,int index);
void heapifyOperationBottomToTopMinHeap(struct Binaryheap* minheap,int index);

void insertInMinHeap(struct Binaryheap* minHeap, int key);
void decreaseKeyInMinHeap(struct Binaryheap* minHeap, int index, int newValue);
void increaseKeyInMinHeap(struct Binaryheap* minHeap, int index, int newValue);
int extractMinInMinHeap(struct Binaryheap* minheap);
int deleteKeyInMinHeap(struct Binaryheap* minheap,int index);
int deleteKeyMethod2InMinHeap(struct Binaryheap* minHeap,int index);
int replaceMinInMinHeap(struct Binaryheap* minheap,int key);

void buildMinHeap(struct Binaryheap* minheap,int arr[],int size);
//sort elements in decreasing order
void heapSortMinHeap(struct Binaryheap* minHeap);

void KLargestElementsMethod2(int arr[], int sizeArr, int k);
void KLargestElementsMethod2ByMinHeap(int arr[], int sizeArr, int k);
void KLargestElementsMethod1(int arr[], int sizeArr, int k);
void KLargestElementsOptimizedByMinHeap(int arr[], int sizeArr, int k);

//sort a k sorted array
void KSortedArraySortByInsertionSort(int array[],int size,int k);
void KSortedArraySortByMinHeap(int arr[], int size, int k);

//check if a array of conntinuous elements form a minheap
int isMinHeapUtil(struct Binaryheap* heap,int index);
int isMinHeap(struct Binaryheap* heap,int arr[],int size);
int isMinHeapMethod2(int arr[],int size,int index);
int isMinHeapIterative(int arr[],int size);

//check if a Binary tree is Min Heap
int isCompleteBinaryTree(struct BinaryTreeNode* root,int index,int numberOfNodes);
int isCompletedBinaryTreeAMinheap(struct BinaryTreeNode* root);
int isBinaryTreeAMinHeap(struct BinaryTreeNode* root);

//print a rowwise/colwise sorted matrix in sorted format
void youngifyMatrix(int matrix[][N],int rowIndex,int colIndex);
int extractMinElementAndRunYoungify(int matrix[][N]);
void printSortedmatrix(int matrix[][N]);



void swap(int *arr, int index1, int index2) {
	int tmp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tmp;

}

struct Binaryheap * createBinaryHeap(int capacity) {
	struct Binaryheap* heap=(struct Binaryheap *)malloc(sizeof(struct Binaryheap));
	heap->capacity = capacity;
	heap->heapSize = 0;
	heap->heapArray = (int *) malloc(capacity * sizeof(int));

	return heap;
}

void InitializeBinaryHeap(struct Binaryheap* heap, int capacity) {

	heap->capacity = capacity;
	heap->heapSize = 0;
	heap->heapArray = (int *) malloc(capacity * sizeof(int));

}
int getParentIndexBinHeap(int childIndex) {

	return (childIndex - 1) / 2;
}

int getLeftIndexBinHeap(int parentIndex) {

	return 2 * parentIndex + 1;

}
int getRightIndexBinHeap(int parentIndex) {

	return 2 * parentIndex + 2;

}

int getMinimumInMinHeap(struct Binaryheap* minHeap) {

	return minHeap->heapArray[0];
}
void traverseBinHeap(struct Binaryheap* heap) {

	int i;
	for (i = 0; i < heap->heapSize; i++) {
		printf("%d ", heap->heapArray[i]);

	}
	printf("\n");
}


void heapifyOperationTopToBottomMinHeap(struct Binaryheap* minHeap,int index){

	int left=getLeftIndexBinHeap(index);
	int right=getRightIndexBinHeap(index);

	int smallest=index;

    if(left<minHeap->heapSize && minHeap->heapArray[left]<minHeap->heapArray[index]){
    	smallest=left;
    }
    if(right<minHeap->heapSize && minHeap->heapArray[right]<minHeap->heapArray[smallest]){
    	smallest=right;
    }
    if(smallest!=index){

    	swap(minHeap->heapArray,index,smallest);
    	heapifyOperationTopToBottomMinHeap(minHeap,smallest);
    }

}

void heapifyOperationBottomToTopMinHeap(struct Binaryheap* minHeap,int index){

	while(index && minHeap->heapArray[getParentIndexBinHeap(index)] > minHeap->heapArray[index]){

		swap(minHeap->heapArray,index,getParentIndexBinHeap(index));
		index=getParentIndexBinHeap(index);
	}
}

void insertInMinHeap(struct Binaryheap* minHeap, int key) {

	if (minHeap->heapSize == minHeap->capacity) {
		printf("Heap is full");
		return;
	}

	int index = minHeap->heapSize;
	minHeap->heapSize++;
	minHeap->heapArray[index] = key;

	heapifyOperationBottomToTopMinHeap(minHeap,index);

}

void decreaseKeyInMinHeap(struct Binaryheap* minHeap, int index, int newValue) {

	minHeap->heapArray[index] = newValue;
    heapifyOperationBottomToTopMinHeap(minHeap,index);

}
void increaseKeyInMinHeap(struct Binaryheap* minHeap, int index, int newValue){

	minHeap->heapArray[index]=newValue;
	heapifyOperationTopToBottomMinHeap(minHeap,index);

}

int extractMinInMinHeap(struct Binaryheap* minheap){

	if(minheap->heapSize==0){
		return -1;
	}
	if(minheap->heapSize==1){
		minheap->heapSize--;
		return minheap->heapArray[0];
	}

    int minElement=minheap->heapArray[0];
    minheap->heapArray[0]=minheap->heapArray[minheap->heapSize-1];
    minheap->heapSize--;

    heapifyOperationTopToBottomMinHeap(minheap,0);

    return minElement;

}

int deleteKeyInMinHeap(struct Binaryheap* minHeap,int index){

	int element=minHeap->heapArray[index];
	minHeap->heapArray[index]=minHeap->heapArray[minHeap->heapSize-1];
	minHeap->heapSize--;
	heapifyOperationTopToBottomMinHeap(minHeap,index);

	return element;
}

int deleteKeyMethod2InMinHeap(struct Binaryheap* minHeap,int index){

	int element=minHeap->heapArray[index];

	decreaseKeyInMinHeap(minHeap,index,INT_MIN);
	extractMinInMinHeap(minHeap);

	return element;

}
int replaceMinInMinHeap(struct Binaryheap* minheap,int key){

	int root=minheap->heapArray[0];
	minheap->heapArray[0]=key;
	if(key>root){
		heapifyOperationTopToBottomMinHeap(minheap,0);
	}
	return root;
}
void buildMinHeap(struct Binaryheap* minheap,int arr[],int size){

	int i;
	for(i=0;i<size;i++){
		minheap->heapArray[i]=arr[i];

	}

	minheap->heapSize=size;


	for(i=(size-2)/2;i>=0;i--){

		heapifyOperationTopToBottomMinHeap(minheap,i);
	}
}
//sort elements in decreasing order
void heapSortMinHeap(struct Binaryheap* minheap){

	int i,size=minheap->heapSize;

	for(i=1;i<=size-1;i++){
	swap(minheap->heapArray,0,minheap->heapSize-1);
	minheap->heapSize--;
	heapifyOperationTopToBottomMinHeap(minheap,0);
	}

	minheap->heapSize=size;

}

void KLargestElementsMethod1(int arr[], int sizeArr, int k) {

	int i, j, min, minIndex, temp;
	int *tmp = (int *) malloc(sizeof(int) * k);

	for (i = 0; i < k; i++) {
		tmp[i] = arr[i];
	}
	for (i = 0; i < k; i++) {
		printf("%d,", tmp[i]);
	}

	printf("\n");
	min=tmp[0];
	minIndex=0;
	for (j = 0; j < k; j++) {//O(k)
		if (tmp[j] < min) {
			min = tmp[j];
			minIndex = j;
		}
	}

	for (i = k; i < sizeArr; i++) {//O(n-k)

		if (arr[i] > min) {

			tmp[minIndex] = arr[i];
			min=arr[i];
			for (j = 0; j < k; j++) { //O(k)
				if (tmp[j] < min) {
					min = tmp[j];
					minIndex = j;
				}
			}

		}
	}

	for (i = 0; i < k; i++) {
		printf("%d,", tmp[i]);
	}
}
//array[]={1,23,12,9,30,2,50};
void KLargestElementsMethod2(int arr[], int sizeArr, int k) {

	int i, j, min, minIndex, temp;
	int *tmp = (int *) malloc(sizeof(int) * k);

	for (i = 0; i < k; i++) {
		tmp[i] = arr[i];
	}
	for (i = 0; i < k; i++) {
		printf("%d,", tmp[i]);
	}
    printf("\n");
	for (i = 0; i < k; i++) {
		min = tmp[0];
		minIndex = 0;
		//find min element
		for (j = 0; j < k; j++) {//O(k)
			if (tmp[j] < min) {
				min = tmp[j];
				minIndex = j;
			}
		}
		//x in arr[k,n] if x >min then swap
		for (j = k; j < sizeArr; j++) {//O(n-k)
			if (arr[j] > min) {

				temp = tmp[minIndex];
				tmp[minIndex] = arr[j];
				arr[j] = temp;
				min = tmp[minIndex];
			}
		}
	}

	for (i = 0; i < k; i++) {
		printf("%d,", tmp[i]);
	}

}
//array[]={1,23,12,9,30,2,50};
void KLargestElementsMethod2ByMinHeap(int arr[], int sizeArr, int k) {

	int i, j, min, temp;

	// build a min heap with k elements of array
	struct Binaryheap heap;
	InitializeBinaryHeap(&heap, 100);

	for (i = 0; i < k; i++) {
		insertInMinHeap(&heap, arr[i]);
	}

	traverseBinHeap(&heap);

	//building min heap done

	for (i = 0; i < k; i++) {
		min = heap.heapArray[0];//O(1)
		for (j = k; j < sizeArr; j++) { //O(n-k)
			if (arr[j] > min) {
				temp = arr[j];
				arr[j] = min;
				heap.heapArray[0] = temp;
				min = temp;
			}
		}

		heapifyOperationTopToBottomMinHeap(&heap, 0);//O(logk)
	}

	for (i = 0; i < k; i++) {
		printf("%d,", heap.heapArray[i]);
	}

}

//array[]={1,23,12,9,30,2,50};
void KLargestElementsOptimizedByMinHeap(int arr[], int sizeArr, int k) {

	int i, j, min, temp;

	// build a min heap with k elements of array
	struct Binaryheap minheap;
	InitializeBinaryHeap(&minheap, 100);

	for (i = 0; i < k; i++) {
		insertInMinHeap(&minheap, arr[i]);
	}

	traverseBinHeap(&minheap);
	//building min heap done

		min = minheap.heapArray[0];//O(1)
		for (j = k; j < sizeArr; j++) { //O(n-k)
			if (arr[j] > min) {
				minheap.heapArray[0] = arr[j];
				heapifyOperationTopToBottomMinHeap(&minheap, 0);//O(logk)
				min = minheap.heapArray[0];
			}
		}

	traverseBinHeap(&minheap);
}

void KSortedArraySortByInsertionSort(int array[],int size,int k){

	int i,j,key,save=k;;

	for(i=1;i<=size-1;i++){

		key=array[i];
		j=i-1;
		k=save;
		while(j>=0 && array[j]>key && k>0){

			array[j+1]=array[j];
			j--;
			k--;
		}
		array[j+1]=key;
	}

}
void KSortedArraySortByMinHeap(int arr[], int size, int k) {

	int i,j;
	struct Binaryheap minheap;
	InitializeBinaryHeap(&minheap, 100);
	// construct heap of k+1 elements
	for (i = 0; i <= k; i++) {
		insertInMinHeap(&minheap, arr[i]);
	}

    traverseBinHeap(&minheap);

    for(i=k+1,j=0;j<size;i++,j++){

    	if(i<size){

    		arr[j]=replaceMinInMinHeap(&minheap,arr[i]);
    	}else{
    		arr[j]=extractMinInMinHeap(&minheap);
    	}
    }



}

int isMinHeapUtil(struct Binaryheap* heap,int index){

	int left=getLeftIndexBinHeap(index);
	int right=getRightIndexBinHeap(index);

	if(left>= heap->heapSize && right>= heap->heapSize){
		return 1;
	}

	int smallest=index;
	if(left< heap->heapSize && heap->heapArray[left]< heap->heapArray[smallest]){
		smallest=left;
	}

	if(right< heap->heapSize && heap->heapArray[right]< heap->heapArray[smallest]){
		smallest=right;
	}

	if(smallest!=index){

		return 0;
	}
	return isMinHeapUtil(heap,left) && isMinHeapUtil(heap,right);
}
int isMinHeap(struct Binaryheap* heap,int arr[],int size){

	int i;
	for(i=0;i<size;i++){
		heap->heapArray[heap->heapSize++]=arr[i];
	}
	traverseBinHeap(heap);

	return isMinHeapUtil(heap,0);
}
int isMinHeapMethod2(int arr[],int size,int index){

	//leaf node return 1
	if(index>(size-2)/2){
        return 1;
	}
    if(2*index+2> size-1 && arr[index]<arr[2*index+1]){

    	return 1;
    }

	if(arr[index]<arr[2*index+1] && arr[index]<arr[2*index+2] && isMinHeapMethod2(arr,size,2*index+1) && isMinHeapMethod2(arr,size,2*index+2)){
      return 1;
	}

	return 0;
}

int isMinHeapIterative(int arr[], int size) {

	int i;
	for (i = 0; i <= (size - 2) / 2; i++) {

		if (2 * i + 2 > size - 1 ) {
			if(arr[i] > arr[2 * i + 1])
			return 0;
		} else if (arr[i] > arr[2 * i + 1] || arr[i] > arr[2 * i + 2]) {
			return 0;
		}
	}

	return 1;
}
int isCompleteBinaryTree(struct BinaryTreeNode* root,int index,int numberOfNodes){

	if(root==NULL){
		return 1;
	}
	if(index>=numberOfNodes){
		return 0;
	}


	return isCompleteBinaryTree(root->left,2*index+1,numberOfNodes) && isCompleteBinaryTree(root->right,2*index+2,numberOfNodes);
}
int isCompletedBinaryTreeAMinheap(struct BinaryTreeNode* root){

	if(root==NULL ||(root->left==NULL && root->right==NULL)){
		return 1;
	}

    int smallest=root->data;
    if(root->left && root->left->data <root->data){
    	smallest=root->left->data;
    }
    if(root->right && root->right->data <root->data){
    	smallest=root->right->data;
    }

    if(smallest!=root->data){
    	return 0;
    }

	return isCompletedBinaryTreeAMinheap(root->left) && isCompletedBinaryTreeAMinheap(root->right);
}

int isBinaryTreeAMinHeap(struct BinaryTreeNode* root){

	int numberOfNodes=getCountOfNodesInBinaryTree(root);
    int index=0;

	return isCompleteBinaryTree(root,index,numberOfNodes) && isCompletedBinaryTreeAMinheap(root);


}

void youngifyMatrix(int matrix[][N],int rowIndex,int colIndex){

	int downValue=(rowIndex+1<N)?matrix[rowIndex+1][colIndex]:INF;
    int rightValue=(colIndex+1<N)?matrix[rowIndex][colIndex+1]:INF;

    if(downValue==INF && rightValue==INF){
    	return;
    }
    if(downValue<rightValue){
    	matrix[rowIndex][colIndex]=downValue;
    	matrix[rowIndex+1][colIndex]=INF;
    	youngifyMatrix(matrix,rowIndex+1,colIndex);
    }else{

    	matrix[rowIndex][colIndex]=rightValue;
    	matrix[rowIndex][colIndex+1]=INF;
    	youngifyMatrix(matrix,rowIndex,colIndex+1);
    }
}
int extractMinElementAndRunYoungify(int matrix[][N]){

	int min=matrix[0][0];
	matrix[0][0]=INF;

	youngifyMatrix(matrix,0,0);

	return min;
}
void printSortedmatrix(int matrix[][N]){

	int i;
	for(i=0;i<N*N;i++){

		printf("%d ",extractMinElementAndRunYoungify(matrix));
	}


}

struct heapNode {
	int data;
	int i;
	int j;
};
struct BHeap {

	struct heapNode *heapArray;
	int heapSize;
	int capacity;

};

struct BHeap* createBHeap(int capacity){

	struct BHeap *heap=(struct BHeap *)malloc(sizeof(struct BHeap));

	heap->heapArray=(struct heapNode *)malloc(sizeof(struct heapNode)*capacity);
	heap->capacity=capacity;
	heap->heapSize=0;


	return heap;
}

void swapBHeap(struct heapNode *arr, int index1, int index2) {
	struct heapNode tmp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tmp;

}
void heapifyOperationBottomToTopMinHeapBHeap(struct BHeap* minHeap,int index){

	while(index && minHeap->heapArray[getParentIndexBinHeap(index)].data > minHeap->heapArray[index].data){

		swapBHeap(minHeap->heapArray,index,getParentIndexBinHeap(index));
		index=getParentIndexBinHeap(index);
	}
}
void insertInMinHeapBHeaP(struct BHeap* minHeap, int key,int i,int j) {

	if (minHeap->heapSize == minHeap->capacity) {
		printf("Heap is full");
		return;
	}

	int index = minHeap->heapSize;
	minHeap->heapSize++;
	minHeap->heapArray[index].data = key;
	minHeap->heapArray[index].i = i;
	minHeap->heapArray[index].j = j;

	heapifyOperationBottomToTopMinHeapBHeap(minHeap,index);

}

void heapifyOperationTopToBottomMinHeapBHeap(struct BHeap* minHeap,int index){

	int left=getLeftIndexBinHeap(index);
	int right=getRightIndexBinHeap(index);

	int smallest=index;

    if(left<minHeap->heapSize && minHeap->heapArray[left].data <minHeap->heapArray[index].data){
    	smallest=left;
    }
    if(right<minHeap->heapSize && minHeap->heapArray[right].data<minHeap->heapArray[smallest].data){
    	smallest=right;
    }
    if(smallest!=index){

    	swapBHeap(minHeap->heapArray,index,smallest);
    	heapifyOperationTopToBottomMinHeap(minHeap,smallest);
    }

}
struct heapNode extractMinInMinHeapBHeap(struct BHeap* minheap){

	struct heapNode minElement={0};
	if(minheap->heapSize==0){
		return minElement;
	}
	if(minheap->heapSize==1){
		minheap->heapSize--;
		return minheap->heapArray[0];
	}

    minElement=minheap->heapArray[0];
    minheap->heapArray[0]=minheap->heapArray[minheap->heapSize-1];
    minheap->heapSize--;

    heapifyOperationTopToBottomMinHeapBHeap(minheap,0);

    return minElement;

}

void printSortedMatrixByMinHeap(int matrix[][4],int k,int n){

	struct BHeap *minHeap=createBHeap(100);
	int i,j;
	for(i=k-1;i>=0;i--){
		insertInMinHeapBHeaP(minHeap,matrix[i][0],i,0);

	}
/*	 printf("%d \n",extractMinInMinHeapBHeap(minHeap).data);
	 printf("%d \n",extractMinInMinHeapBHeap(minHeap).data);
	 printf("%d \n",extractMinInMinHeapBHeap(minHeap).data);
	 printf("%d \n",extractMinInMinHeapBHeap(minHeap).data);
	 printf("%d \n",extractMinInMinHeapBHeap(minHeap).data);*/

	/*	for(j=0;j<k;j++){
	 printf("%d ",minHeap->heapArray[j].data);
	 }*/

	for (int c = 1; c <= n * k; c++) {

		struct heapNode min=extractMinInMinHeapBHeap(minHeap);
		printf("%d ",min.data);
		if(min.j+1>n-1){
	           ;

		}else{
			insertInMinHeapBHeaP(minHeap,matrix[min.i][min.j+1],min.i,min.j+1);
		}
	}
}
void minCostOfConnectingRopes(int *len,int n){

	struct Binaryheap *minheap=createBinaryHeap(100);

	buildMinHeap(minheap,len,n);
	int min,secondMin,cost=0;

	while(minheap->heapSize>1){

		 min=extractMinInMinHeap(minheap);
		 secondMin=extractMinInMinHeap(minheap);
		 cost+=min+secondMin;

		 insertInMinHeap(minheap,min+secondMin);
	}

	printf("cost=%d",cost);


}
int main(void) {

	struct Binaryheap minHeap;
	InitializeBinaryHeap(&minHeap, 10);

	insertInMinHeap(&minHeap,30);
	insertInMinHeap(&minHeap,40);
	insertInMinHeap(&minHeap,10);
	insertInMinHeap(&minHeap,33);
	insertInMinHeap(&minHeap,70);
	insertInMinHeap(&minHeap,44);

/*
	 printf("heap capacity=%d\n",minHeap.capacity);
	 printf("heap size=%d\n",minHeap.heapSize);
	 traverseBinHeap(&minHeap);
*/

/*
	 traverseBinHeap(&minHeap);
	 printf("min=%d\n",getMinimumInMinHeap(&minHeap));
*/

/*
	traverseBinHeap(&minHeap);
	decreaseKeyInMinHeap(&minHeap, 4, 5);
	traverseBinHeap(&minHeap);
*/

/*
	traverseBinHeap(&minHeap);
	insertInMinHeap(&minHeap,5);
	traverseBinHeap(&minHeap);
	int min=extractMinInMinHeap(&minHeap);
	printf("min=%d\n",min);
	traverseBinHeap(&minHeap);
*/

/*
	traverseBinHeap(&minHeap);
	insertInMinHeap(&minHeap,5);
	traverseBinHeap(&minHeap);
	int delkey=deleteKeyInMinHeap(&minHeap,2);
	printf("del key=%d\n",delkey);
	traverseBinHeap(&minHeap);
*/


/*
	insertInMinHeap(&minHeap,5);
	traverseBinHeap(&minHeap);
	int delkey=deleteKeyMethod2InMinHeap(&minHeap,2);
	printf("del key=%d\n",delkey);
	traverseBinHeap(&minHeap);
*/

/*
	insertInMinHeap(&minHeap,5);
	traverseBinHeap(&minHeap);
	increaseKeyInMinHeap(&minHeap,0,200);
	traverseBinHeap(&minHeap);
*/

/*
	int array[8]={22,11,12,40,2,1,5,7};
	int size=8;
	struct Binaryheap mHeap;
	InitializeBinaryHeap(&mHeap, 10);

	buildMinHeap(&mHeap,array,size);
	traverseBinHeap(&mHeap);
	heapSortMinHeap(&mHeap);
	traverseBinHeap(&mHeap);
*/


/*
	traverseBinHeap(&minHeap);
	replaceMinInMinHeap(&minHeap,300);
	traverseBinHeap(&minHeap);
*/

/*
	int array[]={1,230,102,900,30,200,50};
	int size=7,k=3;
	//KLargestElementsMethod2(array,size,k);
	//KLargestElementsMethod2ByMinHeap(array,size,k);
	//KLargestElementsMethod1(array,size,k);
	KLargestElementsOptimizedByMinHeap(array,size,k);
*/

/*
	int array[]={3,5,2,6,4};
	int size=5,k=2;
	KSortedArraySortByInsertionSort(array,size,k);
	for(int i=0;i<5;i++){
       printf("%d,",array[i]);
	}
*/

/*	 int array[]={3,5,2,6,4};
	 int size=5,k=2;
	 KSortedArraySortByMinHeap(array,5,2);
	 printf("\n");
*/


/*
	 int array[]={1,2,3,4};
	 int size=4;
	 printf("\n%s\n",isMinHeapIterative(array,4)?"YES":"NO");

	 for(int i=0;i<size;i++){
	     printf("%d,",array[i]);
	 }
*/

/*
	struct Binaryheap mHeap;
	InitializeBinaryHeap(&mHeap,100);
	int array[]={20,30,100,10};
	buildMinHeap(&mHeap,array,4);//O(n)?
	traverseBinHeap(&mHeap);
*/

/*
	struct Binaryheap heap;
	InitializeBinaryHeap(&heap,100);
	int array[]={5,14,23,32,41,87,90,50,64,53};
	int size=10;
	printf("\n%s",isMinHeap(&heap,array,size)?"YES":"NO");
*/

/*
	int array[]={10,20,30,100};
	printf("\n%s",isMinHeapMethod2(array,4,0)?"YES":"NO");
*/
/*

	int array[]={200,30,120,100};
	printf("\n%s",isMinHeapIterative(array,4)?"YES":"NO");
*/

	/*
	 *            10
	 *           /  \
	 *          20    30
	 *           \
	 *           100
	 */
/*
	struct BinaryTreeNode* root = getBinaryTreeNode(10);
	root->left = getBinaryTreeNode(20);
	root->right = getBinaryTreeNode(30);
	root->left->right = getBinaryTreeNode(100);

	traverseLevelorderBinaryTree(root);
	printf("%s", isBinaryTreeAMinHeap(root) ? "YES" : "NO");
*/

/*
	int i,j;
	int matrix[][4]={{10,20,30,40},
			        {15,25,35,45},
					{27,29,37,48},
					{32,33,39,50}
	                };

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printSortedmatrix(matrix);
*/


	int i,j;
	int matrix[][4]={{10,20,30,40},
			        {1,25,35,45},
					{12,29,37,48},
					{11,33,39,50}
	                };

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	//k is number of rows
	int K=4;
	int n=4;
	printSortedMatrixByMinHeap(matrix,K,n);


	//insertion sort simplified
/*
	int array[]={25,1,-13,10,-12,33,21};
	int n=7,j,i;
	for(i=1;i<n;i++){

		j=i-1;
		while(array[j]>array[j+1] && j>=0){
			swap(array,j,j+1);
			j--;
		}
	}
	for(i=0;i<7;i++){
		printf("%d,",array[i]);
	}
*/

/*
	int arr[]={4,3,2,6};
	int n=4;
	minCostOfConnectingRopes(arr,n);
*/

	return EXIT_SUCCESS;
}
