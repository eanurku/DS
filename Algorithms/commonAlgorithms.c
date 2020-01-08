/*
 * Algorithms.c
 *
 *  Created on: 12-Jan-2018
 *      Author: anurag
 */


#include<stdio.h>// Formatted console and file input/output operations
#include<stdlib.h>//for Utility functions like malloc,random,arc & argv as  command line arguments etc.
#include<string.h>//for String functions like strlen,strcmp etc.
#include<ctype.h>// character class test/conversion functions like isalnum,tolower etc.
#include<stdarg.h>//for Variable arguments uses in function by va_list,va_start,va_arg etc.
#include<time.h>//
#include<math.h>//
#include "commonAlgorithms.h"


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


long long power(long long n, long long exponent)
{ long long p=1,i;
   for(i=1;i<=exponent;i++)
      p=p*n;

   return p;
}
int sum_of_multiples(int limit,int number)
{   int multiples;
    multiples=limit/number;

    return (number * (multiples*(multiples+1))/2) ;
}


int prime_check(long long i)
{ if(i<=1)
  return 0;
  else
    for(long long j=2;j<i;j++)
      if(i%j==0)
       { return 0;}

   return 1;
}
int palindrome_check(long long p)
{   long long r=0,save=p;
int d;
       while(p>0)
      { d=p%10;
        p=p/10;
        r=r*10+d;
      }
      if(r==save)
       return 1;
      else
       return 0;
}

long long LCM(long long x,long long y)
{
  return((x*y)/HCF(x,y));
}

long long HCF(long long x,long long y)
{ if(x<y)
   return HCF(y,x);

  if(x%y==0)
    return y;
  else
  return HCF(y,x%y);
}



int isprime(long long n)
{  long long r,factor;
   if(n<=1)
     return 0;
   if(n<4)
    return 1;
   if(n%2==0)
      return 0;
   if(n<9)
      return 1;
   if(n%3==0)
      return 0;

     r=sqrt(n);
     for(factor=5;factor<=r;factor+=6)//prime_factor always in form of 6k+/- 1
      if((n%factor==0)||(n%(factor+2)==0))
        return 0;

      return 1;
}

int perfect_square_check(int z)
{  int x;
    x=pow(z,.5);
   if(x*x==z)
   return x;
   else
   return 0;
}
void sieve_of_eratosthenes(int *sieve,int *size)              //create an array with prime indices and a[index]=0;
{      //// generate primes <= limit                          // index are 0 to LIMIT
       int crosser, Last_Crosser ,multiples,i;             //crossed are 1 i.e array[index] are not prime but array[index]=0
       *size = LIMIT+1;                                    // are primes
       sieve[0]=CROSSED;
       sieve[1]=CROSSED;

       for(crosser =4 ;crosser <=LIMIT ; crosser+=2)    //cross out multiples of 2
         sieve[crosser] = CROSSED;

       Last_Crosser = sqrt(LIMIT);                       // nos <=n will cross out all composites nos before or < (n+1)^2

       for(crosser = 3 ;crosser <=Last_Crosser ;crosser += 2) {
         if(sieve[crosser]!=CROSSED)     //odd crosser
         for(multiples = crosser * crosser ;multiples <= LIMIT ; multiples += 2*crosser) // n^2 with inc of  2 *n will be crossed
          sieve[multiples]=CROSSED;
       }
       /*
       for(i=1;i<=LIMIT;i++)
        if(sieve[i]!=CROSSED)
       printf("%d ",i);
       */
}
void sieve_of_eratosthenes_fast(int *sieve,int *size)
{

             int Last_Crosser,number_index,multiples_index,i;
             *size=LIMIT/2+1;                              //index i means number 2i+1,i=0 to size-1
             sieve[0]=CROSSED;

             Last_Crosser = sqrt(LIMIT);

             for(number_index =1  ;2*number_index+1 <= Last_Crosser  ;number_index++){   //number=2*number_index+1

               if(sieve[number_index]!= CROSSED){
                 for(multiples_index = 2*number_index*(number_index+1) ;2*multiples_index+1 <= LIMIT ;multiples_index += 2*number_index+1)
                   sieve[multiples_index]=CROSSED;
               }
             }
         /*
          for(i=1;2*i+1<=LIMIT;i++)
            if(sieve[i]!=CROSSED)
              printf("%d ",2*i+1);   //2*i+1 is prime no
         */

}

int GCD(int big,int small){
	if(big<small)
		GCD(small,big);
	if(small==0)
		return big;
	return(GCD(small,big%small));
}

int sumOfAP(int firstTerm, int commondiff, int noOfTerms){

	return ((2*firstTerm+commondiff*(noOfTerms-1))*noOfTerms)/2;
}

long long reverseOfNumber(long long number){

	long long lastDigit;
	long long tmp=number;
	long long reverseNumber= 0;

	while(tmp){

		lastDigit=tmp%10;
		reverseNumber=reverseNumber*10+lastDigit;
		tmp=tmp/10;
	}

	return reverseNumber;
}
long long isPalindrome(long long number){

	long long originalNumber=number;
	long long reverseNumber=reverseOfNumber(number);

return (originalNumber==reverseNumber?1:0);
}

int isPrimeBasic(long long number) {
	long long i;
	for (i = 2; i < number; i++) {
		if (number % i ==0 ) {
			return 0;
		}
	}
	return 1;
}
int getAllPrimeUptoMaxLimit(long long primeArray[], long long maxLimit) {
	long long i, arrayIndex = 0;

	for (i = 2; i <= maxLimit; i++)
		if (isprime(i)) {
			primeArray[arrayIndex++] = i;
		}

	return arrayIndex;
}

int isPrimeFast(long long number) {

	long long  factor,r;
	if(number==1){
		return 0;
	}else if(number<4){
		return 1;
	}else if(number%2==0){
        return 0;
	}else if(number%3==0){
		return 0;
	}

	r=sqrt(number);
	for(factor=5;factor<=r;factor+=6)
         if((number%factor==0)||(number%(factor+2)==0)){
        	 return 0;
         }

	return 1;
}

int isPrimeBasicFast(long long number) {
	long long i;
	int r=sqrt(number);
	for (i = 2; i <= r; i++) {
		if (number % i ==0 ) {
			return 0;
		}
	}
	return 1;
}

//copyTargetSize >=so caseurceSize for valid
void copyArray(int *copyTarget, int *copyTargetSize, int *source,
		int *sourceSize) {
	int bigIndex,smallIndex;
	int startIndex = abs(*copyTargetSize - *sourceSize);
	for (bigIndex = startIndex, smallIndex = 0; bigIndex < *copyTargetSize && smallIndex < *sourceSize;
			smallIndex++, bigIndex++) {

		*(copyTarget + bigIndex) = *(source + smallIndex);

	}
}

void getSumOfTwoNumbers(int * bigNumber, int * bigNumberSize, int * smallNumber,
		int * smallNumberSize) {

	if (*bigNumberSize < *smallNumberSize)
		getSumOfTwoNumbers(smallNumber, smallNumberSize, bigNumber,
				bigNumberSize);

	int carry, smallIndex, remainingIndex,bigIndex;
	int *tmpBigNumber = (int *) malloc((*bigNumberSize) * 4);
	int tmpBigNumberSize = *bigNumberSize;
	int tmpSum = 0;

	copyArray(tmpBigNumber, bigNumberSize, bigNumber, bigNumberSize);
	printf("\n");
	carry = 0;

	for (smallIndex = *smallNumberSize - 1,bigIndex=*bigNumberSize-1; smallIndex >= 0 && bigIndex>=0 ;bigIndex--, smallIndex--) {

		tmpSum = *(bigNumber + bigIndex) + *(smallNumber + smallIndex)
				+ carry;
		*(tmpBigNumber + bigIndex) = tmpSum % 10;

		carry = tmpSum / 10;
	}

	for (remainingIndex = *bigNumberSize - *smallNumberSize - 1;
			remainingIndex >= 0; remainingIndex--) {

		tmpSum = *(bigNumber + remainingIndex) + carry;
		*(tmpBigNumber + remainingIndex) = tmpSum % 10;
		carry = tmpSum / 10;
	}

	if (carry != 0) {
		*(bigNumber) = carry;
		(*bigNumberSize)++;
		copyArray(bigNumber, bigNumberSize, tmpBigNumber, &tmpBigNumberSize);
	} else {
		copyArray(bigNumber, bigNumberSize, tmpBigNumber, &tmpBigNumberSize);
	}

}


void generatePrimesUptoGivenNumberFast(int *primeArray, int *primeArraySize,int maxLimit) {

	int indexArraySize, index, nextIndex,i;
	int *indexArray,lastIndex;

	indexArraySize = maxLimit / 2;
	indexArray = (int *) malloc(indexArraySize * 4);

	lastIndex = sqrt(maxLimit) / 2;
	for (index = 1; index <= lastIndex; index++) {
		if (indexArray[index] != CROSSED)
			for (nextIndex = 2*index*(index + 1);nextIndex<indexArraySize; nextIndex+=2*index+1) {
				indexArray[nextIndex]=CROSSED;
			}
	}

	primeArray[(*primeArraySize)++]=2;//add 2 as first prime

	for(i=1;i<indexArraySize;i++){
		if(indexArray[i]!=CROSSED){
			primeArray[(*primeArraySize)++]=2*i+1;
		}

	}

}

void generatePrimesUptoGivenNumber(int *primeArray, int *primeArraySize,int maxLimit) {

	int  crosserIndex, lastCrosserIndex, nextCrosserIndex, i;

	short *array=(short *)malloc(maxLimit*2);

	for (crosserIndex = 4; crosserIndex < maxLimit; crosserIndex += 2) {
		array[crosserIndex] = CROSSED;
	}

	lastCrosserIndex = sqrt(maxLimit)+1;

	for (crosserIndex = 3; crosserIndex <= lastCrosserIndex; crosserIndex += 2) {
		if (array[crosserIndex] != CROSSED) {

			for (nextCrosserIndex = crosserIndex * crosserIndex;
					nextCrosserIndex < maxLimit; nextCrosserIndex += (2 * crosserIndex)) {
				array[nextCrosserIndex] = CROSSED;
			}
		}

	}

	for (i = 2; i < maxLimit; i++) {
		if (array[i] != CROSSED) {

			primeArray[(*primeArraySize)] = i;
			*primeArraySize+=1;
		}
	}

}

int prime_check_with_primeArray(int number, int *primeNumberSequence, int sequenceSize) {

	int i;
	if(number<2){
		return 0;
	}
	for (i = 0; primeNumberSequence[i] <= sqrt(number); i++) {
		if (number % primeNumberSequence[i] == 0) {

			return 0;
		}
	}

	return 1;
}
void  generatePrimeNumbersBasic(int *primeNumberSequence,int *sequenceSize,int maxLimit){

	int number;
    primeNumberSequence[0] = 2;
	primeNumberSequence[1] = 3;
	*sequenceSize = 2;
	for (number = 5; number < maxLimit; number += 6) {

		if (prime_check_with_primeArray(number, primeNumberSequence, *sequenceSize)) {
			primeNumberSequence[(*sequenceSize)++] = number;
		}

		if ((number + 2) < maxLimit
				&& prime_check_with_primeArray(number + 2, primeNumberSequence, *sequenceSize)) {
			primeNumberSequence[(*sequenceSize)++] = number + 2;
		}
	}

}

long long getCollatzCount(long long number){
long long count=0;

	while (number != 1) {

		while (number % 2 == 0) {
			number /= 2;
			count++;
		}
		if (number % 2 && number != 1) {
			number = number * 3 + 1;
			count++;
		}
	}
return count+1;
}

void getMultiplication(int *firstNumberArray, int *firstNumberArraySize,
		int singleDigitNumber) {

	int i, carry = 0, digit, productSum;

	int *tmpArray = (int *) malloc(SIZE * sizeof(int));
	int tmpArraySize = *firstNumberArraySize;

	copyArray(tmpArray, firstNumberArraySize, firstNumberArray,
			firstNumberArraySize);

	for (i = tmpArraySize - 1; i >= 0; i--) {

		productSum = *(tmpArray + i) * singleDigitNumber + carry;

		digit = productSum % 10;
		*(tmpArray + i) = digit;
		carry = productSum / 10;

	}

	if (carry) {
		*(firstNumberArray) = carry;
		(*firstNumberArraySize)++;
		copyArray(firstNumberArray, firstNumberArraySize, tmpArray,
				&tmpArraySize);
	} else {
		copyArray(firstNumberArray, firstNumberArraySize, tmpArray,
				&tmpArraySize);
	}

}

void getPowerForSingleDigitBase(int number, int power, int *productArray, int *productArraySize) {

	int i;
	*(productArray + (*productArraySize)++) = 1;

	for (i = 1; i <= power; i++) {
		getMultiplication(productArray, productArraySize, number);
	}

}

int getDigitsCount(int number) { //number=0 return count=0

	int count = 0;
	while (number) {
		number /= 10;
		count++;
	}

	return count;
}


int * getProduct(int *finalNumArray, int *finalNumArraySize, int multiplier,int *tmpArray) {
	int i, prodSum, digit;
	int carry = 0, digitCounts;


	int tmpArraySize = *finalNumArraySize;

	copyArray(tmpArray, &tmpArraySize, finalNumArray, finalNumArraySize);

	for (i = tmpArraySize - 1; i >= 0; i--) {

		prodSum = *(tmpArray + i) * multiplier + carry;

		digit = prodSum % 10;
		carry = prodSum / 10;

		*(tmpArray + i) = digit;
	}

	if (carry) {
		digitCounts = getDigitsCount(carry);
		i = digitCounts - 1;
		while (carry) {

			*(finalNumArray + i--) = carry % 10;
			carry /= 10;
		}

		*finalNumArraySize += digitCounts;
		copyArray(finalNumArray, finalNumArraySize, tmpArray, &tmpArraySize);
	} else {
		copyArray(finalNumArray, finalNumArraySize, tmpArray, &tmpArraySize);
	}

}


void getPowerForAnyBase(int number, int power, int *productArray, int *productArraySize) {

	int i,j;
	int *tmpArray = (int *) malloc(sizeof(int) * SIZE);
	*(productArray + (*productArraySize)++) = 1;

	for (i = 1; i <= power; i++) {
		getProduct(productArray, productArraySize, number,tmpArray);

	}
}


int getProperDivisorsSum(int number){

	int i,sum=0;

	for(i=1;i<number;i++){
		if(number%i==0)
		sum+=i;
	}

	return sum;
}
int getProperDivisorsSumFast(int number){
	int sum=0,i;
	int numberSQRT=sqrt(number);

	for(i=2;i*i<number;i++){

		if(number%i==0){
			sum+=i;
			sum+=(number/i);
		}

	}
	if( (number!=1) && (numberSQRT*numberSQRT == number)){
		sum+=numberSQRT;
	}
	return sum+1;
}
int havingAmicablePair(int number) {

	int properDivSum, otherProperDivSum;

	properDivSum = getProperDivisorsSumFast(number);

	if (number != properDivSum) {
		otherProperDivSum = getProperDivisorsSumFast(properDivSum);
		if(number==otherProperDivSum)
			return 1;
	}

return 0;
}

enum Days {
	mon, sun, tue, wed, thr, fri, sat
};

int months[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int isLeapYear(int year) {

	return ((((year % 100)) && (!(year % 4))) || (!(year % 400)));
}
int getLeapYearsCount(int startYear, int lastyear) { //both included
	int count = 0, year;
	if (startYear > lastyear)
		return count;

	for (year = startYear; year <= lastyear; year++) {

		if (isLeapYear(year)) {
			count++;
		}
	}
	return count;
}
int getDayNumber(int startYear,int currentMonth, int currentYear) { //return no of days before this month past.
	int monthNumber, dayCount = 0, leapYearsCount, previousYear,
			daysToPreviousYear = 0;
	int daysInCurrentyear = 0;

	previousYear = currentYear - 1;
	leapYearsCount = getLeapYearsCount(startYear, previousYear);

	daysToPreviousYear = 365 * (previousYear - startYear + 1) + leapYearsCount;

	for (monthNumber = 1; monthNumber < currentMonth; monthNumber++) {

		if (monthNumber == 2 && isLeapYear(currentYear)) {
			daysInCurrentyear += (months[monthNumber] + 1);

		} else {
			daysInCurrentyear += months[monthNumber];
		}
	}

	dayCount = daysToPreviousYear + daysInCurrentyear;

	return dayCount;
}
void swap2(char **string,int i,int j){
char  *tmp=string[i];
string[i]=string[j];
string[j]=tmp;
}

void getSortedCharPointerArray(char **listOfCharPointers,int listOfCharPointersSize){

int i,j,n=listOfCharPointersSize;
char *t1,*t2,*tmp;
	for(i=0;i<=n-1;i++){
		for(j=0;j<=n-2-i;j++){
			if(strcmp(listOfCharPointers[j],listOfCharPointers[j+1])>0){
				swap(listOfCharPointers,j,j+1);

			}

		}
	}

}
int* getSumOfTwoBigNumbers(int *bigNumber, int bigNumberSize, int *smallNumber,int smalNumberSize,int *finalSum, int *finalSumSize,int *tmp) {

	if (bigNumberSize < smalNumberSize) {
		getSumOfTwoBigNumbers(smallNumber, smalNumberSize, bigNumber,
				bigNumberSize,finalSum, finalSumSize,tmp);
	}



	int smalNumberIndex, bigNumberIndex;

	int carry = 0;
	int tmpSum;

	for (smalNumberIndex = smalNumberSize - 1, bigNumberIndex = bigNumberSize
			- 1; smalNumberIndex >= 0 && bigNumberIndex >= 0;
			bigNumberIndex--, smalNumberIndex--) {

		tmpSum = *(bigNumber + bigNumberIndex)
				+ *(smallNumber + smalNumberIndex) + carry;

		*(finalSum + bigNumberIndex) = tmpSum % 10;
		carry = tmpSum / 10;
	}

	while (bigNumberIndex >= 0) {

		tmpSum = *(bigNumber + bigNumberIndex) + carry;
		*(finalSum + bigNumberIndex) = tmpSum % 10;
		carry = tmpSum / 10;
		bigNumberIndex--;
	}

	if (carry) {
		*finalSumSize = bigNumberSize + 1;
		copyArray(tmp, finalSumSize, finalSum, &bigNumberSize);
		*tmp = carry;
		copyArray(finalSum,finalSumSize,tmp,finalSumSize);

	} else {
		*finalSumSize = bigNumberSize;
	}

	return finalSum;
}

void concatenateAllNumbers(int *finalNumber, int *finalNumberSize,
		unsigned long long product, unsigned long long multiplier,
		unsigned long long multiplicand) {

	while (multiplier) {

		finalNumber[(*finalNumberSize)++] = multiplier % 10;
		multiplier /= 10;
	}

	while (multiplicand) {

		finalNumber[(*finalNumberSize)++] = multiplicand % 10;
		multiplicand /= 10;
	}
	while (product) {

		finalNumber[(*finalNumberSize)++] = product % 10;
		product /= 10;
	}

	/*int i;
	for(i=0;i<*finalNumberSize;i++){

		printf("%d",finalNumber[i]);
	}
*/
}

int getDigitsCountGeneral(int number) {

	int count = 0;

	if(number==0){
		return 1;
	}
	while (number) {
		number /= 10;
		count++;
	}

	return count;
}

int pandigitalArrayCheck(int *pandigitalArray,int numberOfDigits){




	int i;
	/*for(i=0;i<=9;i++){
    printf("%d,",pandigitalArray[i]);
	}*/

	for(i=1;i<=numberOfDigits;i++){

		if(pandigitalArray[i]!=1){
			return 0;
		}
	}

	return 1;
}

int isPandigital(long long  number){

	int digit,numberOfDigits,i;
	int pandigitalArray[10]={0};
    numberOfDigits=getDigitsCountGeneral(number);

    if(numberOfDigits>9){
    	return 0;
    }

	while(number){
		digit=number%10;
		pandigitalArray[digit]++;
		number/=10;
	}

	if(pandigitalArrayCheck(pandigitalArray,numberOfDigits)){
		return 1;
	}

	return 0;
}


int isCuriousFraction(int num,int den){

int numdigit1,numdigit2,dendigit1,dendigit2,finalNum,finalDen,gcd;

        finalNum=num/GCD(num,den);
		finalDen=den/GCD(num,den);

	numdigit1=num%10;
	num/=10;
	numdigit2=num%10;

	dendigit1=den%10;
	den/=10;
	dendigit2=den%10;

	if(numdigit1==dendigit2){

		gcd=GCD(numdigit2,dendigit1);
		numdigit2=numdigit2/gcd;
		dendigit1=dendigit1/gcd;
		if(finalNum==numdigit2 && finalDen==dendigit1){
			return 1;
		}
	}


return 0;

}

int getfactorial(int number){
int factorial=1,i;
for(i=1;i<=number;i++){
	factorial*=i;
}

	return factorial;
}
long long getSumOfFactorialofDigits(long long number){

	int digit;
	long long sum=0;

    while(number){

	digit=number%10;
	sum+=getfactorial(digit);
	number/=10;
}

	return sum;
}
int isCuriousNumber(long long number){

	long long sum;

	sum=getSumOfFactorialofDigits(number);

	if(sum==number){
		return 1;
	}

	return 0;
}

int rotateNumber(int number){//rotate a number by 1 digit

	int lastDigit,finalNumber;
	lastDigit=number%10;
	finalNumber=pow(10,getDigitsCount(number/10))*lastDigit+number/10;

return finalNumber;
}

int isCircularprime(int number,int *primeArray,int primeArraySize){//generate primes and then check

	int rotation,numberOfRotation;
    numberOfRotation=getDigitsCount(number);

    for(rotation=1;rotation<=numberOfRotation;rotation++){

    	number=rotateNumber(number);
    	if(!prime_check_with_primeArray(number,primeArray,primeArraySize)){
    		return 0;
    	}
    }

	return 1;
}

void reverseOfArray(int *binaryNumberArray,int binaryNumberArraySize){
int i,j,tmp;
for(i=0,j=binaryNumberArraySize-1;i<j;i++,j--){
	tmp=binaryNumberArray[i];
	binaryNumberArray[i]=binaryNumberArray[j];
	binaryNumberArray[j]=tmp;
}

}
void convertDecimalNumberToBinaryForm(int number,int *binaryNumberArray,int *binaryNumberArraySize){
//if number is zero then binaryNumberArraySize=0
int binaryDigit,i;
while(number>1){
	binaryDigit=number%2;
	binaryNumberArray[(*binaryNumberArraySize)++]=binaryDigit;
	number/=2;
}
if(number==1){
	binaryNumberArray[(*binaryNumberArraySize)++]=number;
}
//reverse the array
reverseOfArray(binaryNumberArray,*binaryNumberArraySize);

}

int isPalindromeInArrayForm(int *NumberArray,int NumberArraySize){

	int i,j;
	for(i=0,j=NumberArraySize-1;i<j;i++,j--){
            if(NumberArray[i]!=NumberArray[j]){
                  return 0;
            }
	}


	return 1;
}

int istruncatablePrime(int number ,int *primeArray,int primeArraySize){

int revNum;
int reverseNumber=reverseOfNumber(number);

	while(number){
		if(!prime_check_with_primeArray(number,primeArray,primeArraySize)){
			return 0;
		}
		number/=10;
	}

	while(reverseNumber && reverseNumber/10){

		reverseNumber/=10;
		revNum=reverseOfNumber(reverseNumber);
		if(!prime_check_with_primeArray(revNum,primeArray,primeArraySize)){
					return 0;
				}

	}

return 1;
}
int istruncatablePrime2(int number ,int *primeArray,int primeArraySize){

int revNum;
int reverseNumber=reverseOfNumber(number);

	while(number){
		if(!prime_check_with_primeArray(number,primeArray,primeArraySize)){
			return 0;
		}
		number/=10;
	}

	while(reverseNumber && reverseNumber/10){

		reverseNumber/=10;
		revNum=reverseOfNumber(reverseNumber);
		if(!prime_check_with_primeArray(revNum,primeArray,primeArraySize)){
					return 0;
				}

	}

return 1;
}

int compareArray(int *maxArray,int maxArraySize,int *numArray,int numArraySize){

int i;
if(maxArraySize>numArraySize){
	return 0;
}
else if(maxArraySize<numArraySize){
	return 1;
}

for(i=0;i<maxArraySize;i++){
if(maxArray[i]>numArray[i]){
	return 0;
}else if(maxArray[i]<numArray[i]){
	return 1;
}
}

return 1;
}

int oneToNinePandigitalCheckForNumberArray(int *NumberArray,int *NumberArraySize){

int i;
int pandigitalArray[10]={0};
if((*NumberArraySize)!=9){
	return 0;
}

for(i=0;i<*NumberArraySize;i++){

	pandigitalArray[NumberArray[i]]++;
}

/*
printf("\n");
for(i=0;i<=9;i++){

		printf("%d,",pandigitalArray[i]);
	}
*/
if(pandigitalArrayCheck(pandigitalArray,9)){
return 1;
}



	return 0;
}

int isTrinagleNumber(long long number){

int i;
long long sum=0;

for(i=1;i*i< 2*number;i++){
     sum+=i;
	if(number==sum){
		return 1;

	}

}

	return 0;
}


int isPermutationOfeachother(int number1, int number2) {

	int numArray1[10] = { 0 };
	int numArray2[10] = { 0 };
	int i;

	while (number1) {
		numArray1[number1 % 10]++;
		number1 /= 10;
	}
	while (number2) {
		numArray2[number2 % 10]++;
		number2 /= 10;
	}

	for (i = 0; i < 10; i++) {

		if (numArray1[i] != numArray2[i]) {
			return 0;
		}
	}

	return 1;
}

int getDistinctprimeFacorsCount(int number,int *primeArray,int primeArraySize){

	int count=0,i,tmp;

	tmp=number;
	for(i=0;primeArray[i]<=tmp/2 && i<=primeArraySize;i++){

		if(number%primeArray[i]==0){

			while(number%primeArray[i]==0){
				number/=primeArray[i];
			}
			count++;
		}

	}



	return count;


}
//do not use it if number~10^19
int isperfectSquare(double number)
{  double sqrtNumber=sqrt(number);
      long long tmpNumber=sqrtNumber;

      double tmp=tmpNumber;
      if(tmp==sqrtNumber)
       return 1;
       else
        return 0;

}
int IsGoldbachNumber(double number, int *primeNumberSequence, int sequenceSize){

int prime;
	for(prime=0;primeNumberSequence[prime]<number;prime++){

		if(isperfectSquare((number-primeNumberSequence[prime])/2)){

			return 1;
		}


	}

	return 0;
}
int isPentagonal(long long x)
{  double p=(1+sqrt(1+24*x))/6;
      long long q=p;
      double t=q;
      if(t==p)
       return 1;
       else
        return 0;

}

void swap(char *array,int p1,int p2){

	int tmp=array[p1];
	array[p1]=array[p2];
	array[p2]=tmp;

}

void getPermutation(char array[],int start,int end){

int i;
if(start==end){
/*	count++;
if(count==1000000)*/
	printf("%s\n",array);

return;

}

	for(i=start;i<=end;i++){
		swap(array,start,i);
		//sortMe(array,start+1,end);
		getPermutation(array,start+1,end);
		swap(array,start,i);


	}


}

int getNumberofFivesInFactorialOfNumber(int number){

	int i=0,tmp,count=0;

	for(i=5;i<=number;i=i*5){

		count+=number/i;
	}

	return count;
}

int phiFunction(int number,int *primeArray, int primeArraySize){

int i,phiFunctionValue=number;

    for(i=0; primeArray[i]<number && i<primeArraySize;i++){
         if((number%primeArray[i])==0){
        	 phiFunctionValue=(phiFunctionValue/primeArray[i])*(primeArray[i]-1);

        	 while((number%primeArray[i])==0){
        		 number/=primeArray[i];
        	 }
         }
    }

if(number>1){
	phiFunctionValue=(phiFunctionValue/number)*(number-1);
}

return phiFunctionValue;
}
//pe-70
int phiFunctionFaster(int number,int *primeArray, int primeArraySize,int *tmpCrossedPrimeArray,int tmpCrossedPrimeArraySize){

   int i,phiFunctionValue=number;

   if(tmpCrossedPrimeArray[number]){

	   return number-1;
   }

    for(i=0; primeArray[i]<number && i<primeArraySize;i++){
         if((number%primeArray[i])==0){
        	 phiFunctionValue=(phiFunctionValue/primeArray[i])*(primeArray[i]-1);

        	 while((number%primeArray[i])==0){
        		 number/=primeArray[i];
        	 }
         }
    }


   if(number>1)
	  phiFunctionValue=(phiFunctionValue/number)*(number-1);

   return phiFunctionValue;
}
