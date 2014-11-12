/*Write a program to swap odd and even bits in an integer with as few instructions as
possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, etc)*/

#include <iostream>
using namespace std;

int swapOddEven(int n){
	// hex: 5 = 0101
	int aux= 0x55555555;
	int even = (n&aux);
	int odd  = n&(aux<<1);
	return (odd>>1)|(even<<1);
}

int theirSwappOddEven(int n){
	return (((n&0xaaaaaaaa)>>1) | ((n&0x55555555)<<1));
}

int main(){
	int n=36;
	cout<<"My swapOddEven: "<<swapOddEven(n)<<endl;
	cout<<"Book's swapping: "<<theirSwappOddEven(n)<<endl;
}
