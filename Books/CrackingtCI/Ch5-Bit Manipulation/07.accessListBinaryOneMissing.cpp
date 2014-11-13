/*An array A[1...n] contains all the integers from 0 to n except for one number
which is missing. In this problem, we cannot access an entire integer in A with
a single operation. The elements of A are represented in binary, and the only 
operation we can use to access them is “fetch the jth bit of A[i]”, which takes
constant time. Write code to find the missing integer. Can you do it in O(n) 
time?*/

#include <iostream>
using namespace std;

//the last bit should be changin from 0 to 1 in every integer. 
//(NOTE: I understood that it was a sorted list, which isn't right)

int fetchNthBit(int *a, int i, int j){
	return (a[i]>>j)%2;
}

int findMissingIntegerInSortedList(int *A, int n){
	int prev = 1;
	for(int i=0; i<n; i++){
		if(fetchNthBit(A, i, 0)==prev)
			return i;
		prev ^=1;
	}
	return -1;
}

int main(){
	int n = 15;
	int *A = new int[n];
	int missing=13;
	for(int i= 0; i<missing; i++) A[i]= i;		
	for(int i= missing+1; i<n; i++) A[i]= i;		
	cout<<"The missing integer in a sorted list is: "<<findMissingIntegerInSortedList(A,n)<<endl;
	delete [] A;
	return 0;
}