//Write a method to generate the nth Fibonacci number
#include <iostream>
using namespace std;

//the iterative version should we way faster....
int fibonacci(int n){
	if(n==0||n==1) return 1;
	if(n>1){
		return fibonacci(n-1) + fibonacci(n-2);
	}else{
		return -1;
	}
}
