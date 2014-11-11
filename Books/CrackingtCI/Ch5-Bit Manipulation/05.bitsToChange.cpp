/*Write a function to determine the number of bits required to convert integer A to
integer B*/

#include <iostream> 
using namespace std; 

int bitsToChange(int A, int B){
	int n = A & B;
	int sum = 0;
	int max= A>B? A : B;
	for(int i=0; max!=0; i++){
		sum +=((n>>i)+1)%2;
		max>>=1;
	}
	return sum;
}

int theirBitsToChange(int A, int B){
	int sum=0;
	for(int c= A^B; c!=0; c>>1)
		sum += c&1;
	return sum;
}

int main(){
	int from = 31; 
	int to = 14;

	cout<<"Bits to change from "<<from<<" to "<<to<<" given by my function: "<<bitsToChange(from, to)<<endl;
	cout<<"Bits to change from "<<from<<" to "<<to<<" given by the book's function: "<<bitsToChange(from, to)<<endl;
}