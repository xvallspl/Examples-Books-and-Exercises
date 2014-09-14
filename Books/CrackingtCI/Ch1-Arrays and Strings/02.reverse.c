#include<stdio.h>

void myReverse(char *str){
	char* i;
	char aux;
	char* size = str; 
	while(*size != '\0') size++;
	size --;
	for (i=str; i<size; i++){
		aux = *i;
		*i = *size;
		*size = aux;
		size --;
	}
}

void theirReverse(char *str){
	char* end=str;
	char tmp;
	if(str){
		while(*end){
			++end;
		}
		--end;

		while(str<end){
			tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}
	}
}


int main(){
	char str[] = "jijajo";
	myReverse(str);
	printf("%s\n", str);
	theirReverse(str);
	printf("%s\n",str);

	return 0;
}