#include <iostream> 
using namespace std; 

int gcd( int a, int b)
{
  if(a==0) return b;
  return gcd( b%a, a);
}

void usingExtraArray(int* v, int n, int i){
	int *vAux = new int[i];
	int j;
	for(j=0; j<i; j++) vAux[j]=v[j];
	while(j<n){
		v[j-i]=v[j];
		j++;
	}
	for(j=0; j<i; j++) v[n-i+j]=vAux[j];
}

//peeking at the solution...

void juggling(int* v, int n, int i){
	int tmp, aux, j, k;
	for(int h=0; h<gcd(i, n); h++){
		tmp = v[h];
		j=h;
		while(1){
			k = j+i;
			if(k>=n) k -= n;
			if(k == h) break;
			v[j] = v[k];
			j = k;
		}
		v[j] = tmp;
	} 
}

void printArray(int* v, int n){
	for(int i=0; i<n; i++) cout<< v[i];
	cout<<endl;
}

int main(){
	int n=8;
	int *v = new int[n];
	int i =3;
	for(int i=0; i<n; i++) v[i]=i;
	printArray(v, n);
	//usingExtraArray(v, n, i);
	juggling(v,n,i);
	printArray(v, n);
	return 0;
}