/* 

Gray Code

The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2 

*/

#include <stdio.h>
#include <math.h>

int calc(int );

int main(){

	int number;
	printf("\nEnter the number: ");
	scanf("%d", &number);
	for(int i=0; i<pow(2,number); i++)
		printf("\n%d", calc(i));
	return 1;
}

int calc(int n){
	return((n>>1)^n);
}
