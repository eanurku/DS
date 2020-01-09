/*
 ============================================================================
 Name        : C.c
 Author      : Anurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void xorSwap(int *x,int *y){

//	*x=*x^*y;
//	*y=*x^*y;
//	*x=*x^*y;
	//or
//	*x=(*y=*y^(*x=*x^*y))^*x;

	//or

	*x^=*y^=*x^=*y;




}
int main(void) {


//---------------------
//	int array1[]={1,2,3,4};
//	int array2[4]={0};
//	int array3[4]={1};
//
//	for(int i=0;i<4;i++){
//		printf("%d ",array1[i]);
//	}
//
//	printf("\n");
//	for(int i=0;i<4;i++){
//		printf("%d ",array2[i]);
//	}
//	printf("\n");
//	for(int i=0;i<4;i++){
//		printf("%d ",array3[i]);
//	}
//	printf("\n");

//-------------------------
//
//	int cap=10;
//	int array4[cap];
//	array4[0]=12;
//	array4[1]=13;
//	int size=2;
//
//	for(int i=0;i<size;i++){
//		printf("%d ",array4[i]);
//	}
//	printf("\n");

//-------------------
//	int cap=10;
//	int *array5=(int *)malloc(sizeof(int)*cap);
//	array5[0]=15;
//	array5[1]=16;
//
//	for(int i=0;i<5;i++){
//		printf("%d ",array5[i]);
//	}
//	printf("\n");


	/*
	 * array of pointers
	 */

//
//	char *arrayOfPointers[]={"anurag","monu","gonu"};
//
//	for(int i=0;i<3;i++){
//		printf("%d ",strlen(arrayOfPointers[i]));
//	}
//	printf("\n");



	/*
	 * random number generation
	 * 	 srand(time(NULL))- it changes initial seed value
	 *
	 */

	 srand(time(NULL));
     for(int i=1;i<=10;i++){

    	 printf("%d ",random()%100);
     }

//	int a=2;
//	int b=3;
//	printf("before swap :a=%d,b=%d\n",a,b);
//	xorSwap(&a,&b);
//	printf("after swap :a=%d,b=%d\n",a,b);

	return EXIT_SUCCESS;
}
