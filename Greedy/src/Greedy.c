/*
 ============================================================================
 Name        : Greedy.c
 Author      : Anurag
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../../Algorithms/Algorithms.h"

struct Job{
	char jobId;
	int deadline;
	int profit;
};
struct Item{

	double value;
	int weight;
};

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


int getMaxActivityPerformedSortedByGreedy(int start[],int finish[],int size){

	//if activity not sorted then sort activity in increasing oreder of finish time.
	if(size==0) return 0;
	int i,count=0;
	int prevFinish=finish[0];


	printf("[%d,%d],",start[0],finish[0]);
	count++;

	for(i=1;i<size;i++){
		if(start[i]>=prevFinish){
			printf("[%d,%d],",start[i],finish[i]);
			prevFinish=finish[i];
			count++;
		}
	}


	return count;
}

void getEgyptianFraction(double num,double den){

	int localDen;
	while(num){

		localDen=ceil(den/num);
		num=num*localDen-den;
		den=den*localDen;
		printf("%d/%d%s",1,localDen,num?" + ":"");
	}
}
int compareJob(void *job1,void *job2){

	struct Job *j1=(struct Job *)job1;
	struct Job *j2=(struct Job *)job2;

	return j2->profit-j1->profit;
}

int getMaxProfitInJobSequenceProblem(struct Job JobArray[],int size){

	int i,time,maxDeadline=0,maxProfit=0;

	qsort(JobArray,size,sizeof(struct Job),compareJob);

	for(i=0;i<size;i++){

		printf("{%c,%d,%d},",JobArray[i].jobId,JobArray[i].deadline,JobArray[i].profit);
	}
	printf("\n");
	for(i=0;i<size;i++){
		maxDeadline=maxoftwo(maxDeadline,JobArray[i].deadline);
	}


	printf("max dedline=%d\n",maxDeadline);

	for(i=0,time=0;i<size && time<maxDeadline;i++){

		if(time<JobArray[i].deadline){
			time++;
			maxProfit+=JobArray[i].profit;
		}
	}

	return maxProfit;
}
int compareItem(void *item1,void *item2){

	struct Item *i1=(struct Item *)item1;
	struct Item *i2=(struct Item *)item2;

	return i1->value/i1->weight < i2->value/i2->weight;

}
int getMaxValueFractionalKnapsackProblem(struct Item items[],int size,int capacity){

	qsort(items,size,sizeof(struct Item),compareItem);
	int i;
	double maxvalue=0;
	for(i=0;i<size;i++){
		printf("%lf ",items[i].value);
	}

	printf("\n");
	for(i=0;i<size;i++){

		if(items[i].weight>capacity){

			maxvalue+=(items[i].value/items[i].weight)*capacity;
			break;
		}else{
			maxvalue+=items[i].value;
			capacity-=items[i].weight;
		}
	}

	return maxvalue;
}

int getMinNumberOfCoinsRequired(int coins[],int size,int Amount){

	int i,j,count=0;
	for(i=size-1;i>=0 && Amount>0;i--){

		if(coins[i]<=Amount){

			count+=Amount/coins[i];
			Amount=Amount%coins[i];
		}
	}

	return count;
}
int main(void) {


	/* Activity Selection problem
	 * You are given n activities with their start and finish times. Select the maximum number of activities that can be
	 * performed by a single person, assuming that a person can only work on a single activity at a time.
	 *
	 * start[]  =  {10, 12, 20};
	 * finish[] =  {20, 25, 30};
	 *
	 * output:  2
	 */
/*
	int start[] =  {1,3,0,5,8,5};
	int finish[]   =  {2,4,6,7,9,9};
	int size=sizeof(start)/sizeof(start[0]);
	printf("\n%d",getMaxActivityPerformedSortedByGreedy(start,finish,size));
*/

	/* Every positive fraction can be represented as sum of unique unit fractions. A fraction is unit fraction if numerator is
	 * 1 and denominator is a positive integer, for example 1/3 is a unit fraction. Such a representation is called Egyptian
	 * Fraction as it was used by ancient Egyptians.
	 *
	 * Egyptian Fraction Representation of 2/3 is 1/2 + 1/6
	 * Egyptian Fraction Representation of 6/14 is 1/3 + 1/11 + 1/231
	 * Egyptian Fraction Representation of 12/13 is 1/2 + 1/3 + 1/12 + 1/156
	 *
	 */

/*
	getEgyptianFraction(12,13);

*/

	/*  Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. It is also given that
	 *  every job takes single unit of time, so the minimum possible deadline for any job is 1. How to maximize total profit if only one job can be
	 *  scheduled at a time.
	 *
	 *   Input:  Five Jobs with following deadlines and profits

         JobID     Deadline     Profit
     	 a         2           100
     	 b         1           19
     	 c         2           27
     	 d         1           25
     	 e         3           15

         Output: Following is maximum profit sequence of jobs
        c, a, e
	 *
	 */

	struct Job jobArray[]={ {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
            {'d', 1, 25}, {'e', 3, 15}};

	int size=sizeof(jobArray)/sizeof(jobArray[0]);

	printf("max profit=%d",	getMaxProfitInJobSequenceProblem(jobArray,size));




	/*
	 * Fractional Knapsack problem
	 */

/*
	struct Item itemArray[]={{60, 10}, {100, 20}, {120, 30}};
	int size=sizeof(itemArray)/sizeof(itemArray[0]);
	printf("max value=%d",getMaxValueFractionalKnapsackProblem(itemArray,size,50));
*/


	/* Minimum number of Coins to make change for X Rs.
	 * Given a value V, if we want to make change for V Rs, and we have infinite supply of each of the denominations in Indian currency,
	 * i.e., we have infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins
	 * and/or notes needed to make the change?
	 */

/*
	int coins[]={1,2,5,10,20,50,100,500,1000};
	int size=sizeof(coins)/sizeof(coins[0]);

	printf("%d",getMinNumberOfCoinsRequired(coins,size,121));
*/


	return EXIT_SUCCESS;
}
