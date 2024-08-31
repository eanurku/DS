/*
 * Algorithms.h
 *
 *  Created on: 12-Jan-2018
 *      Author: anurag
 */

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#define LIMIT 10
#define CROSSED 1
#define SIZE 1000
//prime genearation
int minoftwo(int a,int b);
int minofthree(int a,int b,int c);
int maxoftwo(int a,int b);
int maxofthree(int a,int b,int c);

//getDivisorsCount PE 12
void sieve_of_eratosthenes(int *sieve,int *size) ;
void sieve_of_eratosthenes_fast(int *sieve,int *size) ;

prime_check_with_primeArray(int number, int *primeNumberSequence, int sequenceSize);//check prime with already generate prime earray
void  generatePrimeNumbersBasic(int *primeNumberSequence,int *sequenceSize,int maxLimit);

void generatePrimesUptoGivenNumber(int *primeArray, int *primeArraySize,int maxLimit);//create prime array with all primes upto maxLimit(excluded)
void generatePrimesUptoGivenNumberFast(int *primeArray, int *primeArraySize,int maxLimit);//create prime array with all primes upto maxLimit(excluded)
int getDistinctprimeFacorsCount(int number,int *primeArray,int primeArraySize);


//perfect square
int perfect_square_check(int z);
int isperfectSquare(double number);//do not use it if number~10^19



//reverse
long long reverseOfNumber(long long );
void reverseOfArray(int *binaryNumberArray,int binaryNumberArraySize);

int isPrimeBasic(long long number);
int isprime(long long n);
int prime_check(long long i);
int isPrimeBasicFast(long long );
int isPrimeFast(long long );

long long HCF(long long x,long long y);

long long LCM(long long x,long long y);
int GCD(int,int);

//plindrome
int palindrome_check(long long p);
long long isPalindrome(long long );//decimal form check
int isPalindromeInArrayForm(int *NumberArray,int NumberArraySize);//can be used for binary form check

int sum_of_multiples(int limit,int number);
long long power(long long n, long long exponent);
int sumOfAP(int , int , int );

//provide source size and target size,it will copy to target from end
void copyArray(int *copyTarget, int *copyTargetSize, int *source,int *sourceSize);//copy with different size of array specially for copying numbers
void getSumOfTwoNumbers(int * bigNumber, int * bigNumberSize, int * smallNumber,int * smallNumberSize);//bigNumber hold sum of both numbers

//add big numbers
int* getSumOfTwoBigNumbers(int *bigNumber, int bigNumberSize, int *smallNumber,int smalNumberSize,int *finalSum, int *finalSumSize,int *tmp);



long long getCollatzCount(long long number);

//permutation
void swap(char *array,int p1,int p2);
void getPermutation(char array[],int start,int end);  //Q24
int isPermutationOfeachother(int number1, int number2);

//multiply
void getMultiplication(int *firstNumberArray, int *firstNumberArraySize,int singleDigitNumber);//multiply a numAsArray to singledigitnumber
void getPowerForSingleDigitBase(int number, int power, int *productArray, int *productArraySize) ;//get n^k  as productArray

//multiplication
int getDigitsCount(int number);  //number=0 return count=0
int * getProduct(int *finalNumArray, int *finalNumArraySize, int multiplier,int *tmpArray);	//multiply an numArray to any number
void getPowerForAnyBase(int number, int power, int *productArray, int *productArraySize);

//divisors sum
int getProperDivisorsSum(int number);
int getProperDivisorsSumFast(int number);
int havingAmicablePair(int number) ;

//calendar
int isLeapYear(int year);
int getLeapYearsCount(int startYear, int lastyear) ; //both included
int getDayNumber(int startYear,int currentMonth, int currentYear) ;//return no of days before this month past.

//sort algorithm
void swap2(char **string,int i,int j);
void getSortedCharPointerArray(char **listOfCharPointers,int listOfCharPointersSize);

//euler totient function
int phiFunction(int number,int *primeArray, int primeArraySize);//PE69
int phiFunctionFaster(int number,int *primeArray, int primeArraySize,int *tmpCrossedPrimeArray,int tmpCrossedPrimeArraySize);



//pandigital nuumber
int getDigitsCountGeneral(int number);
int pandigitalArrayCheck(int *pandigitalArray,int numberOfDigits);//it is called to check based on populated array
int isPandigital(long long  number);
int oneToNinePandigitalCheckForNumberArray(int *NumberArray,int *NumberArraySize); //check for 1to9 pandigital or not


//concatenate numbers
void concatenateAllNumbers(int *finalNumber, int *finalNumberSize,unsigned long long product, unsigned long long multiplier,unsigned long long multiplicand);

//curious fraction
int isCuriousFraction(int num,int den);//for 2 digit number only

//curious nuumber
int getfactorial(int number);
long long getSumOfFactorialofDigits(long long number);
int isCuriousNumber(long long number);

//circular prime
int rotateNumber(int number);
int isCircularprime(int number,int *primeArray,int primeArraySize);

//decimal to binay
void convertDecimalNumberToBinaryForm(int number,int *binaryNumberArray,int *binaryNumberArraySize);

//truuncable prime
int istruncatablePrime(int number ,int *primeArray,int primeArraySize);//prime array should have all primee of that n digits numbers where n=no of digits in number


//compare int array
int compareArray(int *maxArray,int maxArraySize,int *numArray,int numArraySize);

//triangle number,pentagonal number
int isTrinagleNumber(long long number);
int isPentagonal(long long x);



//goldbach number
int IsGoldbachNumber(double number, int *primeNumberSequence, int sequenceSize);

//factorials
int getNumberofFivesInFactorialOfNumber(int number);


#endif /* ALGORITHMS_H_ */
