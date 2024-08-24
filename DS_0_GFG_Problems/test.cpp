//============================================================================
// Name        : Test.cpp
// Author      : anurag
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void) {
	puts("!!!Hello World!!! Cpp_00_C++BegineerByKate");

	int array[]={1,2,3,4};
	int length=4;

	reverse(array, array+length);

	for_each(array, array+length, [](auto e){cout<<e<<" ";});
	return EXIT_SUCCESS;
}
