/*You are given two 32-bit numbers, N and M, and two bit positions, i and j. 
Write a method to set all bits between i and j in N equal to M */

#include<stdio.h>

int setBits( long int start, long int end, long int N, long int M){
	long int copy;
	copy = N;
	
	N=N >> (end+1);
	N=N << (end+1);

	copy=copy << (32-start);
	copy=copy >> (32-start);

	M=M<<start;

	N = N | M;
	N = N | copy;

	return N;
}

int main(){
	long int N, M, res;
	N=25;
	M=5;
	res=setBits(1,3, N, M);
	printf("%ld\n", res);
	return 0;
}
