/*
 ============================================================================
 Name        : HackerRank.c
 Author      : Anurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxoftwo(int a,int b){
	return a>b?a:b;
}

#define MAX 10
int areEqualNumber(char *a,char *b){

	int array1[MAX]={0};
	int array2[MAX]={0};
	int i,j;

	int l1=strlen(a);
	int l2=strlen(b);

	if(l1!=l2) return 0;

	for(i=0;i<l1;i++){
		array1[a[i]-'0']++;
	}

	for(i=0;i<l1;i++){
		array2[b[i]-'0']++;
	}

	for(i=0;i<MAX;i++){

		if(array1[i]!=array2[i]){
			return 0;
		}
	}

	return 1;
}

long  factorial(int n){

	long i, prod=1;
	for(i=1;i<=n;i++){
		prod*=i;
	}
	return prod;
}
int getPermuationCount(char *a){

	int freqArray[MAX]={0};
	int len=strlen(a);
	int i;
	for(i=0;i<len;i++){
		freqArray[a[i]-'0']++;
	}

	long fact;


	fact=factorial(len);
	for(i=0;i<len;i++){
		if(freqArray[i]>1){
			fact=fact/factorial(freqArray[i]);
		}
	}

     int zerofact;


	if(freqArray[0]>0){

		zerofact=factorial(len-1);
		zerofact=(zerofact)/factorial(freqArray[0]-1);
		for(i=1;i<len;i++){
			if(freqArray[i]>1){
				zerofact=zerofact/factorial(freqArray[i]);
			}
		}
		return fact-zerofact;

	}
/*

	printf("zerofact=%d",zerofact);
	printf("fact=%d",fact);
*/



	return fact;
}
long findSimilar(char* a, char* b) {


	int count;
	if(a[0]!='0' && b[0]!='0' && areEqualNumber(a,b)){

		count= getPermuationCount(a);
	}else{
		count= getPermuationCount(b);
	}

	return count;
}



void printSquareWithmaxSum(int **array2D, int row_num, int col_num,int squareSize){

	int i,j;
	for (i = row_num; i <= row_num + squareSize - 1; i++) {

		for (j = col_num; j <= col_num + squareSize - 1; j++) {

			printf("%d ",array2D[i][j]);
		}

		printf("\n");
	}

}

int getSubSquareBoundarySum(int **array2D, int row_num, int col_num,int squareSize) {

	int i, j, sum = 0;

	for (i = row_num; i <= row_num + squareSize - 1; i++) {

		for (j = col_num; j <= col_num + squareSize - 1; j++) {

			if (i == row_num || i == row_num + squareSize - 1 || j == col_num|| j == col_num + squareSize - 1) {


				sum+=array2D[i][j];

			}
		}

	}

	return sum;
}

int getSquareWithMaxBoundarySum(int **array2D,int cols,int rows,int squareSize){


	int i,j,max_row,max_col;
	int maxSum=-1,sum;

	for(i=0;i<=rows-squareSize;i++){

		for(j=0;j<=cols-squareSize;j++){

			sum=getSubSquareBoundarySum(array2D,i,j,squareSize);
			if(sum>maxSum){
				maxSum=sum;
				max_row=i;
				max_col=j;
			}
		}

	}

   printSquareWithmaxSum(array2D,max_row,max_col,squareSize);
}





























int main(void) {


	printf("anurag");






























/*	int width,height,i,j,element,squareSize;

	scanf("%d%d",&width,&height);

	int **array2d=(int **)malloc(sizeof(int *)*height);

	for(i=0;i<height;i++){
		*(array2d+i)=(int *)malloc(sizeof(int)*width);
	}

	for(i=0;i<height;i++){

		for(j=0;j<width;j++){
			scanf("%d",&element);
			array2d[i][j]=element;
		}
	}

	scanf("%d",&squareSize);



	getSquareWithMaxBoundarySum(array2d,width,height,squareSize);*/

	return 0;
}
