/*
 ============================================================================
 Name        : DynamicProgramming.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "/home/anurag/Desktop/CPROGG/DataStructure-geeksforgeeks_workspace/Algorithms/commonDeclarations.h"
#include "/home/anurag/Desktop/CPROGG/DataStructure-geeksforgeeks_workspace/Algorithms/LinkListFunctions.c"
#include "/home/anurag/Desktop/CPROGG/DataStructure-geeksforgeeks_workspace/Algorithms/StackFunctions.c"

#define MAX 20
struct GameArea{
	int v1;
	int v2;
};
struct Pair{
	int a;
	int b;
};
int getNthUglyNumberByDP(int n);

int getNthFibonacciNumber(int n);
int getNthFibonacciNumberByMemorization(int n);
int getNthFibonacciNumberByDP(int n);
int getNthFibonacciNumberByMatrix(int n);
int getNthFibonacciNumberByMatrixOptimized(int n);

int getNthCatalanNumber(int n);
int getNthCatalanNumberByDP(int n);

int getNoOfWaysToPartiotionASetByDP(int n);

int getBinomialCoefficient(int n,int k);
int getBinomialCoefficientByDP(int n,int k);
int getBinomialCoefficientByDPSpaceOptimized(int n,int k);

int getPermutationCoefficient(int n,int k);
int getPermutationCoefficientByDP(int n,int k);
int getPermutationCoefficientOptimized(int n,int k );
int getPermutationCoefficientSpaceOptimized(int n,int k );

int getNoOfWaysToTileThe2byNBoard(int n);
int getMaxGoldFromMine(int gold[][4],int m,int n);

int getNoOfWaysToMakeNFromGivenCoins(int coins[],int coinSize,int n);
int getNoOfWaysToMakeNFromGivenCoinsByDP(int coins[],int coinSize,int n);
int getNoOfWaysToMakeNFromGivenCoinsByDPOptimized(int coins[],int coinSize,int n);

int getNoOfWaysFriendsPairedOrRemainSingle(int n);
int getNoOfWaysFriendsPairedOrRemainSingleByDP(int n);

int isSubsetSumExist(int set[],int size,int sum);
int isSubsetSumExistByDP(int set[],int size,int sum);
int isSubsetSumExistByDPSpaceOptimized(int set[],int size,int sum);

int getLargestDivisiblePairSubset(int set[],int size);

int getnCrModp(int n,int r,int p);

int getMaximumSurvivalTimeInAreaUtil(int A,int B,struct GameArea *X,struct GameArea *Y,struct GameArea *Z,int lastArea);
int getMaximumSurvivalTimeInArea(int A,int B,struct GameArea *X,struct GameArea *Y,struct GameArea *Z);

int getMaxValueByCuttingRod(int len[],int price[],int size);
int getMaxValueByCuttingRodByDP(int len[],int price[],int size);

int getMinTimeInAssemblyLineByDP(int **A,int **T,int e[],int x[],int n);

void getMaxLengthSnakeSequenceByDP(int **mat,int row,int col);
void printMaxLengthSnakeSequence(int **mat,int **len,int row,int col,int i,int j);

int getLongestCommonSubSequenceLength(char* s1,char* s2,int m,int n);
int getLongestCommonSubSequenceLengthByDP(char* s1,char* s2,int m,int n);
int getLongestRepeatedSubsequenceLength(char* s1,char* s2,int m,int n);
int getLongestRepeatedSubsequenceLengthByDP(char* s1,char* s2,int m,int n);
int getLCSLengthOfThreeString(char *s1,char* s2,char* s3,int m,int n,int p);
int getLCSLengthOfThreeStringByDP(char *s1,char* s2,char* s3,int m,int n,int p);

int getLongestIncreasingSubsequenceLength(int arr[],int start,int end,int element);
int getLongestIncreasingSubsequenceLengthByDP(int arr[],int size);
int getLongestBitonicSubSequenceLengthByDP(int arr[], int size) ;
int getMaxlengthOfChainOfpairs(struct Pair arr[],int start,int end,struct Pair element);
int getMaxlengthOfChainOfpairsByDP(struct Pair arr[],int size);

double getPathWithMaxAvergaeByDP(int ** matrix,int rows ,int cols);
int getMaxPathSumInTriangleByDP(int **matrix,int rows ,int cols);
int getMaxPathSumInMatrixWithStartingFromFirstRowAndEndAtLastRowByDP(int **matrix,int rows, int cols);

int getMinJumpsToReachEnd(int array[],int start,int end);
int getMinJumpsToReachEndByDP(int array[],int size);

int getMinCostToFillBag(int cost[],int start,int end,int capacity);
int getMinCostToFillBagByDP(int cost[],int size,int capacity);

int getMaxValueIn_0_1_Knapsack(int weight[],int value[],int start,int end,int capacity);
int getMaxValueIn_0_1_KnapsackRecursive2(int weight[],int value[],int size,int capacity);
int getMaxValueIn_0_1_KnapsackByDP(int weight[],int value[],int size,int capacity);

int getMinEditsToConvertS1toS2(char *s1,char *s2,int m,int n);
int getMinEditsToConvertS1toS2ByDP(char *s1,char *s2,int m,int n);

int getLongestCommonSubString(char *s1,char *s2,int m,int n);
int getLongestCommonSubStringByDP2(char *s1,char *s2,int m,int n);

int getLargestSumOfContigousSubArray(int array[],int size);
int getSmallestSumOfContigousArray(int array[],int size);

int minoftwo(int a,int b){
	return a>b?b:a;
}
int minofthree(int a,int b,int c){

	return minoftwo(a,minoftwo(b,c));
}

int maxofthree(int a,int b,int c){
	return maxoftwo(a,maxoftwo(b,c));
}
int maxoftwo(int a,int b){
	return a>b?a:b;
}


int getNthUglyNumberByDP(int n){

	int ugly[150]={1};
	int i2,i3,i5;
	int multipleOf2,multipleOf3,multipleOf5;
	int i,nextUglyNumber;
	i2=i3=i5=0;

	multipleOf2=ugly[i2]*2;
	multipleOf3=ugly[i3]*3;
	multipleOf5=ugly[i5]*5;

	for(i=1;i<n;i++){

		nextUglyNumber=minofthree(multipleOf2,multipleOf3,multipleOf5);
		ugly[i]=nextUglyNumber;

		if(nextUglyNumber==multipleOf2){
			i2++;
			multipleOf2=ugly[i2]*2;
		}
		 if(nextUglyNumber==multipleOf3){
			i3++;
			multipleOf3=ugly[i3]*3;
		}
		 if(nextUglyNumber==multipleOf5){
			i5++;
			multipleOf5=ugly[i5]*5;
		}
	}

	return ugly[n-1];
}

int getNthFibonacciNumber(int n){

	if(n<2) return n;
	return getNthFibonacciNumber(n-1)+getNthFibonacciNumber(n-2);
}

int fibbo[1000];
int getNthFibonacciNumberByMemorization(int n){

	if(n<2) return n;
	if(fibbo[n]==-1){
		 fibbo[n]=getNthFibonacciNumberByMemorization(n-1)+getNthFibonacciNumberByMemorization(n-2);
	}
	return  fibbo[n];
}

int getNthFibonacciNumberByDP(int n){

	int i;
	int fibbo[1000];
	fibbo[0]=0;
	fibbo[1]=1;
	for(i=2;i<=n;i++){
		fibbo[i]=fibbo[i-1]+fibbo[i-2];
	}

	return fibbo[n];
}
void multiplyMatrix(int F[2][2],int M[2][2]){

	int x=F[0][0]*M[0][0]+F[0][1]*M[1][0];
	int y=F[0][0]*M[0][1]+F[0][1]*M[1][1];

	int z=F[1][0]*M[0][0]+F[1][1]*M[1][0];
	int w=F[1][0]*M[0][1]+F[1][1]*M[1][1];

	F[0][0]=x;
	F[0][1]=y;
	F[1][0]=z;
	F[1][1]=w;
}
void powerOfMatrix(int F[2][2],int n){

	int M[2][2]={{1,1},
	             {1,0}};
	for(int i=2;i<=n;i++){

		multiplyMatrix(F,M);
	}
}
int getNthFibonacciNumberByMatrix(int n){

	if(n<2) return n;
	int F[2][2]={{1,1},
	             {1,0}};

	powerOfMatrix(F,n-1);
	return F[0][0];
}
void powerOfMatrixOptimized(int F[2][2],int n){

	if(n<2) return ;
	powerOfMatrixOptimized(F,n/2);

	int M[2][2]={{1,1},
		             {1,0}};
	multiplyMatrix(F,F);
	if(n%2){
		multiplyMatrix(F,M);
	}
}
int getNthFibonacciNumberByMatrixOptimized(int n){

	if(n<2) return n;
	int F[2][2]={{1,1},
	             {1,0}};

	powerOfMatrixOptimized(F,n-1);
	return F[0][0];
}


int getNthCatalanNumber(int n){

	if(n<=1) return 1;

	int catalanNumber=0,i;
	for(i=0;i<n;i++){

		catalanNumber+=getNthCatalanNumber(i)*getNthCatalanNumber(n-1-i);
	}
	return catalanNumber;
}

int getNthCatalanNumberByDP(int n){

	int i,j,catalan[n+1];

	catalan[0]=1;
	catalan[1]=1;

	for(i=2;i<=n;i++){
		catalan[i]=0;
		for(j=0;j<i;j++){
			catalan[i]+=catalan[j]*catalan[i-1-j];
		}
	}

	return catalan[n];

}

int getNoOfWaysToPartiotionASetByDP(int n){

	int bell[n+1][n+1];
	bell[0][0]=1;
	int i,j;
	for (i = 1; i <= n; i++) {

		for (j = 0; j <=i; j++) {

			if (j == 0) {
				bell[i][j]  = bell[i - 1][i - 1];
			} else {
				bell[i][j] = bell[i][j - 1] + bell[i - 1][j - 1];
			}
		}
	}
	return bell[n][0];
}


int getBinomialCoefficient(int n,int k){

	if(n==k || k==0) return 1;

	return getBinomialCoefficient(n-1,k-1)+getBinomialCoefficient(n-1,k);
}
int getBinomialCoefficientByDP(int n,int k){

	int binomial[n+1][k+1];
	int i,j;

	for(i=0;i<=n;i++){
		for(j=0;j<=i && j<=k;j++){
			if(j==0||j==i)
				binomial[i][j]=1;
			else
				binomial[i][j]=binomial[i-1][j-1]+binomial[i-1][j];
		}
	}

	return binomial[n][k];
}
int getBinomialCoefficientByDPSpaceOptimized(int n,int k){

	int coeff[k+1];

	coeff[0]=1;
	int i,j;
	for(i=1;i<=n;i++){
		for(j=minoftwo(i,k);j>=0;j--){
			if(j==0||j==i)
				coeff[j]=1;
			else
			    coeff[j]=coeff[j]+coeff[j-1];
		}
	}

	return coeff[k];
}
int getPermutationCoefficient(int n,int k){

	if(n<k) return 0;
	if(k==0) return 1;
	return k*getPermutationCoefficient(n-1,k-1)+getPermutationCoefficient(n-1,k);
}
int getPermutationCoefficientByDP(int n,int k){

	int perm[n+1][k+1];
	int i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=k;j++){
			perm[i][j]=0;
		}
	}
	for (i = 0; i <= n; i++) {
		for (j = 0; j<=i && j <= k; j++) {

			if(j==0)
				perm[i][j]=1;
			else
				perm[i][j]=j*perm[i-1][j-1]+perm[i-1][j];
		}
	}
	return perm[n][k];
}

int getPermutationCoefficientOptimized(int n,int k ){

	int fact[n+1];
	fact[0]=1;
	int i;
	for(i=1;i<=n;i++){
		fact[i]=fact[i-1]*i;
	}

	return fact[n]/fact[n-k];
}
int getPermutationCoefficientSpaceOptimized(int n,int k ){

	int fact=1,factk;
	int i;
	for(i=1;i<=n;i++){
		fact=fact*i;
		if(i==n-k)
			factk=fact;
	}

	return fact/factk;
}
int getNoOfWaysToTileThe2byNBoard(int n){

	return getNthFibonacciNumberByMatrixOptimized(n+1);
}

int getMaxGoldFromMine(int gold[][4],int m,int n){

	int goldTable[m][n];
	memset(goldTable,0,sizeof(goldTable));
	int row,col,right,rightUp,rightDown;
	int max=0;
	for(col=n-1;col>=0;col--){
		for(row=0;row<m;row++){

			right=(col==n-1)?0:goldTable[row][col+1];
			rightUp=(col==n-1 || row==0)?0:goldTable[row-1][col+1];
			rightDown=(col==n-1||row==m-1)?0:goldTable[row+1][col+1];

			goldTable[row][col]=gold[row][col]+maxofthree(right,rightUp,rightDown);

		}
	}


	for(row=0;row<m;row++){
		if(max<goldTable[row][0]){
			max=goldTable[row][0];
		}
	}

	return max;
}
int getNoOfWaysToMakeNFromGivenCoins(int coins[],int coinSize,int target){

	if(target==0) return 1;
	if(coinSize==0 && target!=0) return 0;
	if(target-coins[coinSize-1]<0){
		return getNoOfWaysToMakeNFromGivenCoins(coins,coinSize-1,target);
	}

	return getNoOfWaysToMakeNFromGivenCoins(coins,coinSize-1,target)+getNoOfWaysToMakeNFromGivenCoins(coins,coinSize,target-coins[coinSize-1]);
}
int getNoOfWaysToMakeNFromGivenCoinsByDP(int coins[],int coinSize,int target){


	int DPtable[coinSize+1][target+1];
	int i,j;

	for(i=0;i<=target;i++){
		DPtable[0][i]=0;
	}


	for(i=0;i<=coinSize;i++){
		DPtable[i][0]=1;
	}


	for(i=1;i<=coinSize;i++){
		for(j=1;j<=target;j++){
			if(j-coins[i-1]<0){
				DPtable[i][j]=DPtable[i-1][j];
			}else{
				DPtable[i][j]=DPtable[i-1][j]+DPtable[i][j-coins[i-1]];
			}

		}
	}


	return DPtable[coinSize][target];
}


int getNoOfWaysToMakeNFromGivenCoinsByDPOptimized(int coins[],int coinSize,int n){

	int i,j;
	int ways[n+1];
	for(i=0;i<=n;i++)
		ways[i]=0;
	ways[0]=1;

	for(i=0;i<coinSize;i++){
		for(j=coins[i];j<=n;j++){
			ways[j]+=ways[j-coins[i]];

		}
	}

	return ways[n];
}

int getNoOfWaysFriendsPairedOrRemainSingle(int n){

	if(n<0) return 0;
	if(n<=1) return 1;
	return getNoOfWaysFriendsPairedOrRemainSingle(n-1)+(n-1) *getNoOfWaysFriendsPairedOrRemainSingle(n-2);

}


int getNoOfWaysFriendsPairedOrRemainSingleByDP(int n){

	int DPArray[n+1];
	DPArray[0]=1;
	DPArray[1]=1;
	int i;
	for(i=2;i<=n;i++){
		DPArray[i]=DPArray[i-1]+(i-1)*DPArray[i-2];
	}

	return DPArray[n];
}
int isSubsetSumExist(int set[],int size,int sum){

	if(sum==0) return 1;
	if(size==0 && sum) return 0;
	if(sum-set[size-1]<0){

		return  isSubsetSumExist(set,size-1,sum);
	}

	return isSubsetSumExist(set,size-1,sum) || isSubsetSumExist(set,size-1,sum-set[size-1]);
}
int isSubsetSumExistByDP(int set[],int size,int sum){

	int DPTable[size+1][sum+1];
	int i,j;

	for(i=0;i<=sum;i++){
		DPTable[0][i]=0;
	}
	for(i=0;i<=size;i++){
		DPTable[i][0]=1;
	}

	for(i=1;i<=size;i++){
		for(j=1;j<=sum;j++){

			if(j-set[i-1]<0){
				DPTable[i][j]=DPTable[i-1][j];
			}else{
				DPTable[i][j]=DPTable[i-1][j]||DPTable[i-1][j-set[i-1]];
			}
		}
	}

	return DPTable[size][sum];
}
int isSubsetSumExistByDPSpaceOptimized(int set[],int size,int sum){

	int i,j;
	int DPtable[2][sum+1];
	for(i=0;i<=size;i++){
		for(j=0;j<=sum;j++){

			if(j==0){
				DPtable[i%2][j]=1;
			}else if(i==0){
				DPtable[i][j]=0;
			}else if(j-set[i-1]<0){
				DPtable[i%2][j]=DPtable[(i+1)%2][j];
			}else{
				DPtable[i%2][j]=DPtable[(i+1)%2][j]||DPtable[(i+1)%2][j-set[i-1]];
			}
		}
	}
	return DPtable[size%2][sum];
}
int compare(void *a,void *b){
	int x=*(int *)a;
	int y=*(int *)b;
	return x>y?1:-1;
}
int getLargestDivisiblePairSubset(int set[],int size){

	int i,j,max;
	int DP[size];
	for(i=0;i<size;i++){
		DP[i]=0;
	}

	qsort(set,size,sizeof(int),compare);

	for(i=size-2;i>=0;i--){
		for(j=i+1;j<size;j++){

			if(set[j]%set[i]==0){
				DP[i]=maxoftwo(DP[i],DP[j]+1);
			}
		}
	}
    max=0;
	for(i=0;i<size;i++){
		max=maxoftwo(max,DP[i]);
	}
	return max+1;
}
int getnCrModp(int n,int r,int p){

	int coeff[r+1];
	coeff[0]=1;
	int i,j;
	for(i=1;i<=n;i++){
		for(j=minoftwo(i,r);j>=0;j--){
			if(j==0||j==i){
				coeff[j]=1;
			}else{
				coeff[j]=(coeff[j]+coeff[j-1])%p;
			}

		}
	}

	return coeff[r];
}


int getMaximumSurvivalTimeInAreaUtil(int A,int B,struct GameArea *X,struct GameArea *Y,struct GameArea *Z,int lastArea){

	if(A<0 ||B<0) return 0;

	int temp;

	switch(lastArea){

	case 1: temp=1+maxoftwo(getMaximumSurvivalTimeInAreaUtil(A+Y->v1,B+Y->v2,X,Y,Z,2),getMaximumSurvivalTimeInAreaUtil(A+Z->v1,B+Z->v2,X,Y,Z,3));break;
	case 2:temp=1+maxoftwo(getMaximumSurvivalTimeInAreaUtil(A+X->v1,B+X->v2,X,Y,Z,1),getMaximumSurvivalTimeInAreaUtil(A+Z->v1,B+Z->v2,X,Y,Z,3));break;
	case 3:temp=1+maxoftwo(getMaximumSurvivalTimeInAreaUtil(A+X->v1,B+X->v2,X,Y,Z,1),getMaximumSurvivalTimeInAreaUtil(A+Y->v1,B+Y->v2,X,Y,Z,2));
	       break;
	}


	return temp;
}
int getMaximumSurvivalTimeInArea(int A,int B,struct GameArea *X,struct GameArea *Y,struct GameArea *Z){


	if(A<0 ||B<0) return 0;


	return maxofthree(getMaximumSurvivalTimeInAreaUtil(A+X->v1,B+X->v2,X,Y,Z,1),getMaximumSurvivalTimeInAreaUtil(A+Y->v1,B+Y->v2,X,Y,Z,2),
			getMaximumSurvivalTimeInAreaUtil(A+Z->v1,B+Z->v2,X,Y,Z,3));
}

int getMaxValueByCuttingRod(int len[],int price[],int size){

	int i;
	int max;

	if(size==0) return 0;

	max=0;
	for(i=0;i<size;i++){

		max=maxoftwo(max,price[i]+getMaxValueByCuttingRod(len,price,size-i-1));
	}

	return max;
}

int getMaxValueByCuttingRodByDP(int len[],int price[],int size){


	int max;
	int cost[size+1];
	cost[0]=0;//cost[i] =max value obtained by cutting rod of length i
	int i,j;

	for(i=1;i<=size;i++){

		max=0;
		for(j=0;j<i;j++){
			max=maxoftwo(max,price[j]+cost[i-j-1]);
		}
		cost[i]=max;
	}

	return cost[size];
}


int getMinTimeInAssemblyLineByDP(int **A,int **T,int e[],int x[],int n){

	int *a=A;
	int *t=T;

	int T1[n];
	int T2[n];
	T1[0]=e[0]+*(a+n*0+0);
	T2[0]=e[1]+*(a+n*1+0);

	for(int i=1;i<n;i++){
		T1[i]=minoftwo(T1[i-1]+*(a+n*0+i),T2[i-1]+*(t+n*1+i)+*(a+n*0+i));
		T2[i]=minoftwo(T2[i-1]+*(a+n*1+i),T1[i-1]+*(t+n*0+i)+*(a+n*1+i));

	}
	return minoftwo(x[0]+T1[n-1],x[1]+T2[n-1]);
}


void printMaxLengthSnakeSequence(int **mat,int **len,int row,int col,int i,int j){

	int *cell=mat;
	int *lengrid=len;

	printf("\n(%d,%d),value=%d",i,j,*(cell+col*i+j));

	while(*(lengrid+col*i+j)){

		if(i>0 && *(lengrid+col*i+j)-1==*(lengrid+col*(i-1)+j)){
			printf("\n(%d,%d),value=%d",i-1,j,*(cell+col*(i-1)+j));
			i--;
		}else if(j>0 && *(lengrid+col*i+j)-1==*(lengrid+col*i+j-1)){
			printf("\n(%d,%d),value=%d",i,j-1,*(cell+col*i+j-1));
			j--;
		}

	}

}
void getMaxLengthSnakeSequenceByDP(int **mat,int row,int col){

	int *cell=mat;
	int len[row][col];
	memset(len,0,sizeof(len));
	int i,j;
	int max_row,max_col,max_len=0;;

	for(i=0;i<row;i++){
		for(j=0;j<col;j++){

			if(i>0 && abs(*(cell+row*i+j)-*(cell+row*(i-1)+j))==1){
				len[i][j]=maxoftwo(len[i][j],1+len[i-1][j]);

				if (max_len < len[i][j]) {
					max_len = len[i][j];
					max_row = i;max_col = j;
				}
			}
			if(j>0 && abs(*(cell+row*i+j)-*(cell+row*(i)+j-1))==1 ){
				len[i][j]=maxoftwo(len[i][j],1+len[i][j-1]);

				if (max_len < len[i][j]) {
					max_len = len[i][j];
					max_row = i;max_col = j;
				}
			}

		}
	}


	printf("\nmax len seq size=%d",max_len);

	printMaxLengthSnakeSequence(mat,len,row,col,max_row,max_col);
}

int getLongestCommonSubSequenceLength(char* s1,char* s2,int m,int n){

	if(m==0||n==0) return 0;

	if(s1[m-1]==s2[n-1])
		return 1+getLongestCommonSubSequenceLength(s1,s2,m-1,n-1);

	return maxoftwo(getLongestCommonSubSequenceLength(s1,s2,m-1,n),getLongestCommonSubSequenceLength(s1,s2,m,n-1));
}

int getLongestCommonSubSequenceLengthByDP(char* s1,char* s2,int m,int n){

	int DPtable[m+1][n+1];
	memset(DPtable,0,sizeof(DPtable));

	int i,j;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(s1[i-1]==s2[j-1]){
				DPtable[i][j]=1+DPtable[i-1][j-1];
			}else{
				DPtable[i][j]=maxoftwo(DPtable[i][j-1],DPtable[i-1][j]);
			}
		}
	}

    for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			printf("%d ",DPtable[i][j]);
		}
		printf("\n");
	}

	return DPtable[m][n];
}
int getLongestCommonSubSequenceLengthByDPSpaceOptimized(char* s1,char* s2,int m,int n){

	int DPtable[2][n+1];
	int i,j;
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){

			if(i==0||j==0){
				DPtable[i%2][j]=0;
			}else if(s1[i-1]==s2[j-1]){
				DPtable[i%2][j]=1+DPtable[(i+1)%2][j-1];
			}else{
				DPtable[i%2][j]=maxoftwo(DPtable[(i+1)%2][j],DPtable[i%2][j-1]);
			}
		}
	}
    for(i=0;i<=1;i++){
		for(j=0;j<=n;j++){
			printf("%d ",DPtable[i][j]);
		}
		printf("\n");
	}

    if(m%2){
    	return DPtable[1][n];
    }else {
    	return DPtable[0][n];
    }
}
int getLongestRepeatedSubsequenceLength(char* s1,char* s2,int m,int n){

	if(m==0 || n==0) return 0;
	if(s1[m-1]==s2[n-1] && m-1 != n-1){
		return 1+getLongestRepeatedSubsequenceLength(s1,s2,m-1,n-1);
	}

	return maxoftwo(getLongestRepeatedSubsequenceLength(s1,s2,m,n-1),getLongestRepeatedSubsequenceLength(s1,s2,m-1,n));
}

int getLongestRepeatedSubsequenceLengthByDP(char* s1,char* s2,int m,int n){

	int DPtable[n+1][n+1];
	memset(DPtable,0,sizeof(DPtable));
	int i,j;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(s1[i-1]==s2[j-1] && i-1!=j-1){
				DPtable[i][j]=1+DPtable[i-1][j-1];
			}else{
				DPtable[i][j]=maxoftwo(DPtable[i][j-1],DPtable[i-1][j]);
			}
		}
	}
	return DPtable[m][n];
}

int getLongestIncreasingSubsequenceLength(int arr[],int start,int end,int element){

	int i,max;

	if(start>end)
		return 0;
	max=0;
	for(i=start;i<=end;i++){
		if(arr[i]>element){
			max=maxoftwo(max,1+getLongestIncreasingSubsequenceLength(arr,i+1,end,arr[i]));
		}
	}
	return max;
}
int getLongestDecreasingSubsequenceLength(int arr[],int start,int end,int element){

	int i,max;

	if(start>end)
		return 0;
	max=0;
	for(i=end;i>=start;i--){
		if(arr[i]>element){
			max=maxoftwo(max,1+getLongestDecreasingSubsequenceLength(arr,start,i-1,arr[i]));
		}
	}
	return max;
}

int getLongestIncreasingSubsequenceLengthByDP(int arr[],int size){

	int maxSeqLength[size];
	int i,j;
	for(i=0;i<size;i++){
		maxSeqLength[i]=1;
	}


	maxSeqLength[0]=1;

	for(i=1;i<size;i++){

		for(j=0;j<i;j++){
			if(arr[j] < arr[i]){
				maxSeqLength[i]=maxoftwo(maxSeqLength[i],1+maxSeqLength[j]);

			}
		}
	}

	int max=0;
	for(i=0;i<size;i++){
		max=maxoftwo(max,maxSeqLength[i]);
	}
	return max;
}

int getLCSLengthOfThreeString(char *s1,char* s2,char* s3,int m,int n,int p){

	if(m==0||n==0||p==0) return 0;

	if(s1[m-1]==s2[n-1] && s2[n-1]==s3[p-1]&& s3[p-1]==s1[m-1]){
		return 1+getLCSLengthOfThreeString(s1,s2,s3,m-1,n-1,p-1);
	}

	return maxofthree(getLCSLengthOfThreeString(s1,s2,s3,m-1,n,p),getLCSLengthOfThreeString(s1,s2,s3,m,n-1,p),getLCSLengthOfThreeString(s1,s2,s3,m,n,p-1));
}

int getLCSLengthOfThreeStringByDP(char *s1,char* s2,char* s3,int m,int n,int p){

	int DPTable[m+1][n+1][p+1];
	int i,j,k;

	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			for(k=0;k<=p;k++){
				if(i==0||j==0||k==0){
					DPTable[i][j][k]=0;
				}else if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1]&& s3[k-1]==s1[i-1]){
					DPTable[i][j][k]=1+DPTable[i-1][j-1][k-1];
				}else{
					DPTable[i][j][k]=maxofthree(DPTable[i-1][j][k],DPTable[i][j-1][k],DPTable[i][j][k-1]);
				}
			}
		}
	}

	return DPTable[m][n][k];
}

int getLongestBitonicSubSequenceLength(int arr[],int start,int end,int element){//incomplete

	if(start>end) return 0;
	int i,max=0;

	for(i=start;i<=end;i++){

		max=maxoftwo(max,getLongestBitonicSubSequenceLength(arr,i+1,end,arr[i]));
	}
}


int getLongestBitonicSubSequenceLengthByDP(int arr[], int size) {

	int Lis[size]; //lis[i]=max length increasing sequence end at i.
	int Lds[size]; //lds[i]=max length decreasing sequence starts at lds[i].
	int i, j;

	//calc LIS
	for (i = 0; i < size; i++) {
		Lis[i] = 1;
	}
	Lis[0] = 1; //base case
	for (i = 1; i < size; i++) {
		for (j = 0; j < i; j++) {
			if (arr[j] < arr[i])
				Lis[i] = maxoftwo(Lis[i], 1 + Lis[j]);
		}
	}


	//calc LDS
	for (i = 0; i < size; i++) {
		Lds[i] = 1;
	}
	Lds[size-1]=1;//base case

	for(i=size-2;i>=0;i--){
		for(j=size-1;j>i;j--){
			if(arr[j]<arr[i])
				Lds[i]=maxoftwo(Lds[i],1+Lds[j]);
		}
	}


	for (i = 0; i < size; i++) {
		printf("%d ",Lis[i]);
	}
	printf("\n");
	for (i = 0; i < size; i++) {
		printf("%d ",Lds[i]);
	}

	//calc LBS[i]=LIS[i]+LDS[i]-1

	int max=0;
	for(i=0;i<size;i++){
		max=maxoftwo(max,Lis[i]+Lds[i]-1);
	}

	return max;
}
int getMaxlengthOfChainOfpairs(struct Pair arr[],int start,int end,struct Pair element){

	if(start>end ) return 0;

	int i, max=0;
	for(i=start;i<=end;i++){
		if(arr[i].a>element.b)
		max=maxoftwo(max,1+getMaxlengthOfChainOfpairs(arr,i+1,end,arr[i]));
	}
	return max;
}
int getMaxlengthOfChainOfpairsByDP(struct Pair arr[],int size){

	int maxlenChain[size];
	int i,j;
	for(i=0;i<size;i++){
		maxlenChain[i]=1;
	}
	maxlenChain[0]=1;//base case

	for(i=1;i<size;i++){
		for(j=0;j<i;j++){
			if(arr[j].b<arr[i].a){
				maxlenChain[i]=maxoftwo(maxlenChain[i],1+maxlenChain[j]);
			}
		}
	}

	int max=0;
	for(i=0;i<size;i++){
		max=maxoftwo(max,maxlenChain[i]);
	}
	return max;
}

double getPathWithMaxAvergaeByDP(int ** matrix,int rows ,int cols){

	int *mat=matrix;
	double DPTable[rows][cols];

	int i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			if(i==0 && j==0){
				DPTable[i][j]=*(mat+i*cols+j);
			}else if(i==0){
				DPTable[i][j]=*(mat+i*cols+j)+DPTable[i][j-1];
			}else if(j==0){
				DPTable[i][j]=*(mat+i*cols+j)+DPTable[i-1][j];
			}else{
				DPTable[i][j]=*(mat+i*cols+j)+maxoftwo(DPTable[i][j-1],DPTable[i-1][j]);
			}
		}
	}

/*	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			printf("%d ",DPTable[i][j]);
		}
		printf("\n");
	}*/

	return DPTable[rows-1][cols-1]/(rows+cols-1);
}
int getMaxPathSumInTriangleByDP(int **matrix,int rows ,int cols){

	int *mat=matrix;
	int DPTable[rows][cols];
	int i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<=i;j++){

			if(i==0 && j==0){
				DPTable[i][j]=*(mat+i*cols+j);
			}
			else if(j==0){
				DPTable[i][j]=*(mat+i*cols+j)+DPTable[i-1][j];
			}else if(i>j){
				DPTable[i][j]=*(mat+i*cols+j)+maxoftwo(DPTable[i-1][j],DPTable[i-1][j-1]);
			}else {
				DPTable[i][j]=*(mat+i*cols+j)+DPTable[i-1][j-1];
			}
		}
	}

/*
	for (i = 0; i < rows; i++) {
		for (j = 0; j <= i; j++) {
			printf("%d ", DPTable[i][j]);
		}
		printf("\n");
  	}
*/

	int max=0;
	for(i=0;i<cols;i++){
		max=maxoftwo(max,DPTable[rows-1][i]);
	}
	return max;
}

int getMaxPathSumInMatrixWithStartingFromFirstRowAndEndAtLastRowByDP(int **matrix,int rows, int cols) {
	int *mat = matrix;
	int DPTable[rows][cols];
	int i, j;
	//copy first row
	for (j = 0; j < cols; j++) {
		DPTable[0][j] = *(mat + 0 * cols + j);
	}

	for (i = 1; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if (j == 0) {
				DPTable[i][j] = *(mat + i * cols + j)
						+ maxoftwo(DPTable[i - 1][j], DPTable[i - 1][j + 1]);
			} else if (j == cols - 1) {
				DPTable[i][j] = *(mat + i * cols + j)
						+ maxoftwo(DPTable[i - 1][j], DPTable[i - 1][j - 1]);
			} else {
				DPTable[i][j] = *(mat + i * cols + j)
						+ maxofthree(DPTable[i - 1][j], DPTable[i - 1][j - 1],
								DPTable[i - 1][j + 1]);
			}
		}
	}

/*		for (i = 0; i < rows; i++) {
			for (j = 0; j <cols; j++) {
				printf("%d ", DPTable[i][j]);
			}
			printf("\n");
	  	}*/

	int max=0;
	for(i=0;i<cols;i++){
		max=maxoftwo(max,DPTable[rows-1][i]);
	}
	return max;
}
int getMinJumpsToReachEnd(int array[],int start,int end){

	if(start>=end) return 0;
	if(array[start]==0) return INT_MAX;

	int i,tmp,min=INT_MAX;
	for(i=start+1;i<=end && i<=start+array[start];i++){
		tmp=getMinJumpsToReachEnd(array,i,end);
		if(tmp!=INT_MAX){
			min=minoftwo(min,1+tmp);
		}

	}

	return min;
}
int getMinJumpsToReachEndByDP(int array[],int size){

	int DP[size];//dp[i]=min jumps to reach ith element;
	int i,j;
	DP[0]=0;//base case
	for(i=1;i<size;i++){
		DP[i]=INT_MAX;
		for(j=0;j<i;j++){
			if(i<=j+array[j] && DP[j]!=INT_MAX ){ /*DP[j]!=INT_MAX is to handle case of {0,1,21,0,2,3},{}*/
				DP[i]=minoftwo(DP[i],1+DP[j]);
				break;
			}
		}
	}

	return DP[size-1];

}

int getMinCostToFillBag(int cost[],int start,int end,int capacity){

	if(start>end) return INT_MAX;
	if(capacity<0) return INT_MAX;
	if(capacity==0) return 0;
	if(start+1>capacity) return INT_MAX;

	int i,j,tmp;
	int min=INT_MAX;

	for(i=start;i<=end;i++){
		if(cost[i]!=-1)
		for(j=i+1;j<=capacity;j+=(i+1)){
			tmp=getMinCostToFillBag(cost,i+1,end,capacity-(j));
			if(tmp!=INT_MAX)
			min=minoftwo(min,j*cost[i]+tmp);
		}
	}
	return min;
}
int getMinCostToFillBagByDP(int cost[],int size,int capacity){

	int val[size];
	int wt[size];
	int i,j=0;
	for(i=0;i<size;i++){
		if(cost[i]!=-1){
			wt[j]=i+1;
			val[j]=cost[i];
			j++;
		}
	}

	size=j;

	int DPtable[size+1][capacity+1];



	for(i=0;i<=size;i++){
		for(j=0;j<=capacity;j++){
			if(j==0){
				DPtable[i][j]=0;
			}else if(i==0){
				DPtable[i][j]=INT_MAX;
			}else if(wt[i-1]>j){
				DPtable[i][j]=DPtable[i-1][j];
			}else{
				DPtable[i][j]=minoftwo(DPtable[i-1][j],val[i-1]+DPtable[i][j-wt[i-1]]);
			}
		}
	}




   return DPtable[size][capacity]!=INT_MAX ?DPtable[size][capacity]:-1;
}
int getMaxValueIn_0_1_Knapsack(int weight[],int value[],int start,int end,int capacity){

	int max=0,i;

	if(start>end) return 0;
	if(weight[start]>capacity)
		return getMaxValueIn_0_1_Knapsack(weight,value,i+1,end,capacity);

	if(capacity==0) return 0;
	for(i=start;i<=end;i++){
		max=maxoftwo(max,value[i]+getMaxValueIn_0_1_Knapsack(weight,value,i+1,end,capacity-weight[i]));
	}

	return max;
}
int getMaxValueIn_0_1_KnapsackRecursive2(int weight[],int value[],int size,int capacity){

	if(capacity==0||size==0){
		return 0;
	}

	if(weight[size-1]>capacity)
		return getMaxValueIn_0_1_KnapsackRecursive2(weight,value,size-1,capacity);

	return maxoftwo(getMaxValueIn_0_1_KnapsackRecursive2(weight,value,size-1,capacity),value[size-1]+getMaxValueIn_0_1_KnapsackRecursive2(weight,value,size-1,capacity-weight[size-1]));
}
int getMaxValueIn_0_1_KnapsackByDP(int weight[],int value[],int size,int capacity){

	int i,j;
	int dptable[size+1][capacity+1];
	memset(dptable,0,sizeof(dptable));
	for(i=1;i<=size;i++){
		for(j=1;j<=capacity;j++){
			if(j>=weight[i-1])
			dptable[i][j]=maxoftwo(dptable[i-1][j],value[i-1]+dptable[i-1][j-weight[i-1]]);
			else{
				dptable[i][j]=dptable[i-1][j];
			}
		}
	}
	return dptable[size][capacity];
}
int getMinEditsToConvertS1toS2(char *s1,char *s2,int m,int n){

	if(m==0) return n;
	if(n==0) return m;

	if(s1[m-1]==s2[n-1]){
		return getMinEditsToConvertS1toS2(s1,s2,m-1,n-1);
	}

	return minofthree(1+getMinEditsToConvertS1toS2(s1,s2,m,n-1),1+getMinEditsToConvertS1toS2(s1,s2,m-1,n-1),
			1+getMinEditsToConvertS1toS2(s1,s2,m-1,n));
}
int getMinEditsToConvertS1toS2ByDP(char *s1,char *s2,int m,int n){


	int DPTable[m+1][n+1];
	int i,j;
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if(i==0){
				DPTable[i][j]=j;
			}else if(j==0){
				DPTable[i][j]=i;
			}else if(s1[i-1]==s2[j-1]){
				DPTable[i][j]=DPTable[i-1][j-1];
			}else{
				DPTable[i][j]=minofthree(1+DPTable[i][j-1],1+DPTable[i-1][j-1],1+DPTable[i-1][j]);
			}
		}
	}
	printf("\n");
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			printf("%d ",DPTable[i][j]);
		}
		printf("\n");
	}
	return DPTable[m-1][n-1];
}
int getLongestCommonSubString(char *s1,char *s2,int m,int n){

	if(m==0||n==0) return 0;

	int len=0;;
	if (s1[m - 1] == s2[n - 1]) {

		while (s1[m - 1] == s2[n - 1] && m>0 && n>0) {
			len++;
			m--;
			n--;
		}
		return maxoftwo(len,getLongestCommonSubString(s1,s2,m,n));
	}

	return maxoftwo(getLongestCommonSubString(s1,s2,m-1,n),getLongestCommonSubString(s1,s2,m,n-1));
}
int getLongestCommonSubStringByDP1(char *s1,char *s2,int m,int n){


	int DPTable[m+1][n+1];
	int i,j,len,x,y;

	for(i=0;i<=m;i++){

		for(j=0;j<=n;j++){
			if(i==0||j==0){
				DPTable[i][j]=0;
			}else if(s1[i-1]==s2[j-1]){
				len=0;
				x=i;y=j;
				while (s1[x-1] == s2[y - 1] && x>0 && y>0) {
							len++;x--;y--;
					}
				DPTable[i][j]=maxoftwo(len,DPTable[i-1][j-1]);
			}else{
				DPTable[i][j]=maxoftwo(DPTable[i][j-1],DPTable[i-1][j]);
			}
		}
	}
	printf("\n");
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			printf("%d ",DPTable[i][j]);
		}
		printf("\n");
	}
	return DPTable[m][n];
}

int getLongestCommonSubStringByDP2(char *s1,char *s2,int m,int n){


	int DPTable[m+1][n+1];

	int i,j,result=0;

	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if(i==0||j==0){
				DPTable[i][j]=0;
			}else if(s1[i-1]!=s2[j-1]){
				DPTable[i][j]=0;
			}else{
				DPTable[i][j]=1+DPTable[i-1][j-1];
				result=maxoftwo(result,DPTable[i][j]);
			}
		}
	}

	return result;
}

int getLongestCommonSubStringByDPSpaceOptimized(char *s1,char *s2,int m,int n){

	int DPtable[2][n+1];
	int i,j,result=0;

	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if(i==0||j==0){
				DPtable[i%2][j]=0;
			}else if(s1[i-1]!=s2[j-1]){
				DPtable[i%2][j]=0;
			}else{
				DPtable[i%2][j]=1+DPtable[(i+1)%2][j-1];
				result=maxoftwo(result,DPtable[i%2][j]);
			}

		}
	}

	return result;
}

int getLargestSumOfContigousSubArray(int array[],int size){

	int i,max_ending_here,max_so_far;

	max_ending_here=0;
	max_so_far=INT_MIN;
	for(i=0;i<size;i++){

		max_ending_here+=array[i];
		if(max_so_far<max_ending_here){
			max_so_far=max_ending_here;
		}
		if(max_ending_here<0){
			max_ending_here=0;
		}

	}

	return max_so_far;
}

int getSmallestSumOfContigousArray(int array[],int size){

	int i,min_so_far,min_ending_here;

	min_ending_here=0;
	min_so_far=INT_MAX;

	for(i=0;i<size;i++){

		min_ending_here+=array[i];
		if(min_so_far>min_ending_here){
			min_so_far=min_ending_here;
		}
		if(min_ending_here>0){
			min_ending_here=0;
		}
	}

	return min_so_far;
}
int main(void) {
	/*
	 Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, …
	 shows the first 11 ugly numbers. By convention, 1 is included.Given a number n, the task is to find n’th Ugly number.
	 */

/*
	 printf("\n%d", getNthUglyNumberByDP(150));

*/

	/*
	 Given a number n, print n-th Fibonacci Number.
	 */

/*
	printf("\n %d",getNthFibonacciNumber(20));

	for(int i=0;i<=1000;i++){
		fibbo[i]=-1;
	}
	printf("\n %d",getNthFibonacciNumberByMemorization(20));

	printf("\n %d",getNthFibonacciNumberByDP(20));

	printf("\n %d",getNthFibonacciNumberByMatrix(20));

	printf("\n %d",getNthFibonacciNumberByMatrixOptimized(20));
*/

	/*
	  catalan number
	 C(0)=1 ;  C(n)=C(i)*C(n-1-i) for i=0 to n-1 ;
	 */

/*
	printf("\n%d",getNthCatalanNumber(9));

	printf("\n%d",getNthCatalanNumberByDP(9));

*/

	/*
	 Given a set of n elements, find number of ways of partitioning it.
	 First few Bell numbers are 1, 1, 2, 5, 15, 52, 203, ….
	 Bell Triangle
	 1
     1 2
     2 3 5
	 5 7 10 15
     15 20 27 37 52
	 */
/*
	printf("%d",getNoOfWaysToPartiotionASetByDP(7));
*/

	/*
	 Write a function that takes two parameters n and k and returns the value of Binomial Coefficient C(n, k).
	  C(n, k) = C(n-1, k-1) + C(n-1, k);
	 */

/*
	printf("\n%d",getBinomialCoefficient(5,2));
	printf("\n%d",getBinomialCoefficientByDP(5,2));
	printf("\n%d",getBinomialCoefficientByDPSpaceOptimized(5,2));
*/
/*

	printf("\n%d",getPermutationCoefficient(10,2));
	printf("\n%d",getPermutationCoefficientByDP(10,2));
	printf("\n%d",getPermutationCoefficientOptimized(10,2));
	printf("\n%d",getPermutationCoefficientSpaceOptimized(10,2));
*/

	/* Tiling problem
	 Given a “2 x n” board and tiles of size “2 x 1”, count the number of ways to tile the given board
	 using the 2 x 1 tiles.A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically
	 i.e., as 2 x 1 tile.
	 count(n) = n if n = 1 or n = 2
      count(n) = count(n-1) + count(n-2)
	 */
/*
	printf("\n%d",getNoOfWaysToTileThe2byNBoard(4));
*/

	/* Gold Mine problem
	 Given a gold mine of n*m dimensions. Each field in this mine contains a positive integer which
	 is the amount of gold in tons. Initially the miner is at first column but can be at any row. He
	 can move only (right->,right up /,right down\) that is from a given cell, the miner can move to
	 the cell diagonally up towards the right or right or diagonally down towards the right. Find out
	 maximum amount of gold he can collect.

	 Hint: start calculation from end Column and total values get accumulated in first column.get max
	 value in this column.
	 */
/*
	int gold[4][4]= { {1, 3, 1, 5},
	        {2, 2, 4, 1},
	        {5, 0, 2, 3},
	        {0, 6, 1, 2}};
	printf("\n%d",getMaxGoldFromMine(gold,4,4));
*/

	/*
	 * Given a value N, if we want to make change for N cents, and we have infinite supply of each of
	 * S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.
	 *
	 * coin change problem
	 */

/*
	int coins[]={1,2,3};
	int size=sizeof(coins)/sizeof(int);
	printf("\n%d",getNoOfWaysToMakeNFromGivenCoins(coins,size,6));
	printf("\n%d",getNoOfWaysToMakeNFromGivenCoinsByDP(coins,size,6));
	printf("\n%d",getNoOfWaysToMakeNFromGivenCoinsByDPOptimized(coins,size,6));
*/

	/*Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be
	 *paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
	 * friends pairing problem
	 */
/*
	printf("\n%d",getNoOfWaysFriendsPairedOrRemainSingle(3));
	printf("\n%d",getNoOfWaysFriendsPairedOrRemainSingleByDP(3));
*/

	/*
	 * subset Sum problem
	 * Given a set of non-negative integers, and a value sum, determine if there is a subset of the given
	 * set with sum equal to given sum.
	 * Examples: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
	 * Output:  True  //There is a subset (4, 5) with sum 9.
	 */

/*
	int set[]={3, 34, 4, 12, 5, 2};
	int sum=9;
	int size=6;
	printf("\n%d",isSubsetSumExist(set,size,sum));
	printf("\n%d",isSubsetSumExistByDP(set,size,sum));
*/


	/*
	 * largest divisible pair subset
	 * Given an array of n distinct elements, find length of the largest subset such that every pair in the
	 * subset is such that the larger element of the pair is divisible by smaller element.
	 * Input : arr[] = {10, 5, 3, 15, 20}
	 * Output : 3
	 * Explanation: The largest subset is 10, 5, 20. 10 is divisible by 5, and 20 is divisible by 10.
	 */

/*
	int set[]= {18, 1, 3, 6, 13, 17} ;
	int size=sizeof(set)/sizeof(set[0]);
	printf("%d",getLargestDivisiblePairSubset(set,size));
*/

	/*
	 * Given three numbers n, r and p, compute value of nCr mod p.
	 * Input:  n = 10, r = 2, p = 13
     * Output: 6
     * Explanation: 10C2 is 45 and 45 % 13 is 6.
	 */
/*
	printf("%d",getnCrModp(10,2,13));
*/
	/* Choice of Area
	 * Consider a game, in which you have two types of powers, A and B and there are 3 types of Areas X, Y and Z.
	 * Every second you have to switch between these areas, each area has specific properties by which your power A
	 * and power B increase or decrease. We need to keep choosing areas in such a way that our survival time is
	 * maximized. Survival time ends when any of the powers, A or B reaches less than 0.
	 * example A=20,B=8
	 * area X(3,2),area Y(-5,-10),area Z(-20,5);
	 * solution:
	 * It is possible to choose any area in our first step.
	 * We can survive at max 5 unit of time by following
	 * these choice of areas :
	 * X -> Z -> X -> Y -> X
	 */
/*
	int A=20,B=8;
	struct GameArea X={3,2};
	struct GameArea Y={-5,-10};
	struct GameArea Z={-20,5};
	printf("%d",getMaximumSurvivalTimeInArea(A,B,&X,&Y,&Z));

	 /*cutting a rod
	 * Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n.
	 * Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if length of
	 * the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22
	 * (by cutting in two pieces of lengths 2 and 6)
	 * length   | 1   2   3   4   5   6   7   8
	 * --------------------------------------------
	 * price    | 1   5   8   9  10  17  17  20
	 *
	 */

/*
	int length[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int price[] = { 3, 5, 8, 9, 10, 17, 17, 20 };
	int size=sizeof(length)/sizeof(length[0]);
	printf("\n%d",getMaxValueByCuttingRod(length,price,size));
	printf("\n%d",getMaxValueByCuttingRodByDP(length,price,size));
*/

	/*Assembly line scheduling
	 * A car factory has two assembly lines, each with n stations. A station is denoted by S(i,j) where i is either 1 or 2
	 * and indicates the assembly line the station is on, and j indicates the number of the station. The time taken per
	 * station is denoted by a(i,j). Each station is dedicated to some sort of work like engine fitting, body fitting,
	 * painting and so on. So, a car chassis must pass through each of the n stations in order before exiting the factory.
	 * The parallel stations of the two assembly lines perform the same task. After it passes through station S(i,j), it will
	 * continue to station Si,j+1 unless it decides to transfer to the other line. Continuing on the same line incurs no
	 * extra cost, but transferring from line i at station j – 1 to station j on the other line takes time ti,j. Each
	 * assembly line takes an entry time ei and exit time xi which may be different for the two lines. Give an algorithm
	 * for computing the minimum time it will take to build a car chassis.
	 *
	 */

/*
	int A[][4]={ {4, 5, 3, 2},
		    	{2, 10, 1, 4}};
	int T[][4]={{0, 7, 4, 5},
               {0, 9, 2, 8}};

	int e[]={10,12};
	int x[]={18,7};
	int n=4;


	printf("\n%d",	getMinTimeInAssemblyLineByDP(A,T,e,x,n));
*/
	/*max length snake sequence
	 * Given a grid of numbers, find maximum length Snake sequence and print it. If multiple snake sequences exists with the
	 * maximum length, print any one of them.
	 * A snake sequence is made up of adjacent numbers in the grid such that for each number, the number on the right or the
	 * number below it is +1 or -1 its value. For example, if you are at location (x, y) in the grid, you can either move right
	 * i.e. (x, y+1) if that number is ± 1 or move down i.e. (x+1, y) if that number is ± 1.
	 *
	 * For example,
	 * 9, 6, 5, 2
	 * 8, 7, 6, 5
	 * 7, 3, 1, 6
	 * 1, 1, 1, 7
	 *
	 * In above grid, the longest snake sequence is: (9, 8, 7, 6, 5, 6, 7)
	 */
	 int cell[][4] =
	    {
	        {9, 6, 5, 2},
	        {8, 7, 6, 5},
	        {7, 3, 1, 6},
	        {1, 1, 1, 7},
	    };
	 getMaxLengthSnakeSequenceByDP(cell,4,4);

	/*Longest Common SubSequence
	 * LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. A subsequence is
	 * a sequence that appears in the same relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”,
	 * ‘”acefg”, .. etc are subsequences of “abcdefg”.
	 * Examples:
	 * LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
	 * LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
	 *
	 */
/*
	char *s1="ABCDGH";
	char *s2="AEDFHR";
	int m=6,n=7;
	printf("\nlcs=%d\n",getLongestCommonSubSequenceLength(s1,s2,m,n));

	printf("\nlcs=%d\n",getLongestCommonSubSequenceLengthByDP(s1,s2,m,n));

	printf("\nlcs=%d\n",getLongestCommonSubSequenceLengthByDPSpaceOptimized(s1,s2,m,n));
*/


	/*Longest Repeated subsequence
	 * Given a string, print the longest repeating subsequence such that the two subsequence don’t have same string character at
	 * same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.
	 * Input: str = "aabebcdd"
	 * Output:abd
	 * Input: str = "aabb"
	 * Output: "ab"
	 * Input: str = "aab"
	 * Output: "a"
	 *
	 * hint:
	 * This problem is just the modification of Longest Common Subsequence problem. The idea is to find the LCS(str, str) where
	 * str is the input string with the restriction that when both the characters are same, they shouldn’t be on the same index
	 * in the two strings.
	 *
	 */

/*
	char* str="AABEBCDD";
	int n=8;
	printf("\n%d",getLongestRepeatedSubsequenceLength(str,str,n,n));
	printf("\n%d",getLongestRepeatedSubsequenceLengthByDP(str,str,n,n));

*/
	/* Longest Increasing SubSequence
	 * The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that
	 * all elements of the subsequence are sorted in increasing order. For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60,80}
	 * is 6 and LIS is {10, 22, 33, 50, 60, 80}.
	 */

/*
		int arr[]= { 10, 22, 9, 33, 21, 50, 41, 60,2 };
		int size=sizeof(arr)/sizeof(arr[0]);

		printf("\n%d",getLongestIncreasingSubsequenceLength(arr,0,size-1,0));
		printf("\n%d",getLongestIncreasingSubsequenceLengthByDP(arr,size));
*/

		/*
		 * Longest decreasing subSequence
		 */

/*
		int arr[]= { 10, 22, 9, 33, 21, 50, 41, 60,2 };
		int size=sizeof(arr)/sizeof(arr[0]);
		printf("\n%d",getLongestDecreasingSubsequenceLength(arr,0,size-1,0));
*/

	/* LCS of three String
	 *
	 */
/*
	char* str1 = "AGGT12";
	char* str2 = "12TXAYB";
	char* str3 = "12XBA";
	int m = 6, n = 7, p = 5;
	printf("\n%d", getLCSLengthOfThreeString(str1, str2, str3, m, n, p));
*/

	/* Longest Bitonic Subsequence
	 *
	 * Given an array arr[0 … n-1] containing n positive integers, a subsequence of arr[] is called Bitonic if it is first increasing,
	 * then decreasing. Write a function that takes an array as argument and returns the length of the longest bitonic subsequence.
	 * A sequence, sorted in increasing order is considered Bitonic with the decreasing part as empty. Similarly, decreasing order sequence
	 * is considered Bitonic with the increasing part as empty.
	 *
	 * Input arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
	 * Output: 6 (A Longest Bitonic Subsequence of length 6 is 1, 2, 10, 4, 2, 1)
	 *
	 * Input arr[] = {80, 60, 30, 40, 20, 10}
	 * Output: 5 (A Longest Bitonic Subsequence of length 5 is 80, 60, 30, 20, 10)
	 *
	 */
/*
	int array[]={80, 60,  40, 20, 10};
	int size=sizeof(array)/sizeof(array[0]);
	printf("\n%d",getLongestBitonicSubSequenceLengthByDP(array,size));
*/

	/* Maximum Length Chain of Pairs
	 * You are given n pairs of numbers. In every pair, the first number is always smaller than the second number. A pair (c, d) can
	 * follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. Find the longest chain which can be formed
	 * from a given set of pairs
	 *
	 * For example, if the given pairs are {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} }, then the longest chain that can be
	 * formed is of length 3, and the chain is {{5, 24}, {27, 40}, {50, 90}}
	 */

/*
	struct Pair arr[]= {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
	int size=sizeof(arr)/sizeof(arr[0]);
	struct Pair element={0,0};
	printf("\n%d",getMaxlengthOfChainOfpairs(arr,0,size-1,element));
	printf("\n%d",getMaxlengthOfChainOfpairsByDP(arr,size));
*/

	/* Path with maximum average value
	 * Given a square matrix of size N*N, where each cell is associated with a specific cost. A path is defined as a specific sequence
	 * of cells which starts from top left cell move only right or down and ends on bottom right cell. We want to find a path with maximum
	 * average over all existing paths. Average is computed as total cost divided by number of cells visited in path.
	 *  .---->
	 *  |
	 *  |
	 * \|/
	 *
	 */
/*
	int mat[][3]={{1,2,3},
			 {4,5,6},
			 {7,8,9}};
	int m=3,n=3;

	printf("\n%f",getPathWithMaxAvergaeByDP(mat,m,n));
*/

	/* Maximum path sum in a triangle
	 * We have given numbers in form of triangle, by starting at the top of the triangle and moving to adjacent numbers on the row below,
	 * find the maximum total from top to bottom.
	 */
/*
	int mat[4][4]={{3,0,0,0},
				 {7,4,0,0},
				 {2,4,6,0},
				 {8,5,9,3}};
    int m=4,n=4;

    printf("\n%d",getMaxPathSumInTriangleByDP(mat,m,n));
*/
	/* Maximum path sum that starting with any cell of 0-th row and ending with any cell of (N-1)-th row
	 *
	 */
/*
	int mat[4][4]={ {4, 2, 3, 4},
					{2, 9, 1, 10},
					{15, 1, 3, 0},
					{16, 92, 41, 44}};
    int m=4,n=4;
    printf("\n%d",getMaxPathSumInMatrixWithStartingFromFirstRowAndEndAtLastRowByDP(mat,m,n));
*/

	/* Minimum number of jumps to reach end
	 * Given an array of integers where each element represents the max number of steps that can be made forward from that element.
	 * Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). If an
	 * element is 0, then cannot move through that element.
	 * Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
	 * Output: 3 (1-> 3 -> 8 ->9)
	 * explanation:
	 * First element is 1, so can only go to 3. Second element is 3, so can make at most 3 steps eg to 5 or 8 or 9.
	 */
/*
	int array[]= {0,1,3};
	int size=sizeof(array)/sizeof(array[0]);

	printf("\n%d",getMinJumpsToReachEnd(array,0 ,size-1));
	printf("\n%d",getMinJumpsToReachEndByDP(array,size));
*/


	/* Minimum cost to fill given weight in a bag
	 * You are given a bag of size W kg and you are provided costs of packets different weights of oranges in array cost[] where cost[i]
	 * is basically cost of ‘i’ kg packet of oranges. Where cost[i] = -1 means that ‘i’ kg packet of orange is unavailable.
	 *
	 * Find the minimum total cost to buy exactly W kg oranges and if it is not possible to buy exactly W kg oranges then print -1. It
	 * may be assumed that there is infinite supply of all available packet types.
	 *
	 * Input  : W = 5, cost[] = {1, 10, 4, 50, 100}
	 * Output : 5
	 * We can choose five oranges of weight 1 kg.
	 *
	 * Input  : W = 5, cost[] = {-1, -1, 4, 5, -1}
	 * Output : -1
	 */
/*
	int cost[]={1, 10, 4, 50, 100};
	int size=sizeof(cost)/sizeof(cost[0]);

	printf("\n%d",getMinCostToFillBag(cost,0,size-1,5)!=INT_MAX?getMinCostToFillBag(cost,0,size-1,5):-1);

	printf("\n%d",getMinCostToFillBagByDP(cost,size,5));
*/

	/*
	 * 0-1 Knapsack Problem)
	 */
/*
	int weight[]={10,20,30};
	int value[]={60,100,120};
	int size=sizeof(weight)/sizeof(weight[0]);

	printf("\n%d",getMaxValueIn_0_1_Knapsack(weight,value,0,size-1,50));
	printf("\n%d",getMaxValueIn_0_1_KnapsackRecursive2(weight,value,size,50));
	printf("\n%d",getMaxValueIn_0_1_KnapsackByDP(weight,value,size,50));
*/

	/*
	 * Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of
	 *  edits (operations) required to convert ‘str1’ into ‘str2’.
	 *  Insert
	 *  Remove
	 *  Replace
	 *  All of the above operations are of equal cost.
	 *  Input:   str1 = "geek", str2 = "gesek"
	 *  Output:  1
	 *  We can convert str1 into str2 by inserting a 's'.
	 *  Input:   str1 = "sunday", str2 = "saturday"
	 *  Output:  3
	 */

/*
	char *s1="sunday";
	char *s2="saturday";

	printf("\n%d",getMinEditsToConvertS1toS2(s1,s2,strlen(s1),strlen(s2)));
	printf("\n%d",getMinEditsToConvertS1toS2ByDP(s1,s2,strlen(s1),strlen(s2)));
*/


	/* Longest Common Substring)
	 * Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.
	 */
/*
	char *s1="abcde";
	char *s2="dacdfe";

	printf("\n%d",getLongestCommonSubString(s1,s2,strlen(s1),strlen(s2)));
	printf("\n%d",getLongestCommonSubStringByDP1(s1,s2,strlen(s1),strlen(s2)));
	printf("\n%d",getLongestCommonSubStringByDP2(s1,s2,strlen(s1),strlen(s2)));
	printf("\n%d",getLongestCommonSubStringByDPSpaceOptimized(s1,s2,strlen(s1),strlen(s2)));
*/

	/* Largest Sum Contiguous Subarray
	 * Write an efficient C program to find the sum of contiguous subarray within a one-dimensional array of numbers
	 * which has the largest sum.
	 * input array {-2,-3,4,-1,-2,1,5,-3}
	 * output 7
	 * explaination:
	 * sub array {4,-1,-2,1,5}=7
	 */
/*
	int array[]={-2,-3,-1,-2,-3};
	int size=sizeof(array)/sizeof(array[0]);

	printf("\n%d",getLargestSumOfContigousSubArray(array,size));
*/


	/* Smallest sum contiguous subarray
	 * Given an array containing n integers. The problem is to find the sum of the elements of the contiguous subarray
	 * having the smallest(minimum) sum.
	 * Input : arr[] = {3, -4, 2, -3, -1, 7, -5}
	 * Output : -6
	 * Subarray is {-4, 2, -3, -1} = -6
	 */

/*

	int array[] = {3, -4, 2, -3, -1, 7, -5};
	int size=sizeof(array)/sizeof(array[0]);

	printf("\n%d",getSmallestSumOfContigousArray(array,size));


*/
	return EXIT_SUCCESS;
}
