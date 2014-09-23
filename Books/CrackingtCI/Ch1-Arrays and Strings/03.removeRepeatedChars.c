//Design an algorithm and write code to remove the duplicate characters in a string 
//without using any additional buffer. NOTE: One or two additional variables are fine.
//An extra copy of the array is not.

#include<stdio.h>

void myFirstRemoveRepeatedChars(char *string){
	
	char* aux, *aux2;
	aux = string;
	aux++;
	int found;

	while(*aux){
		aux2 = string;
		found = 0;
		while(aux2<aux){
			if(*aux == *aux2){
				found = 1;
				break;
			}
			aux2++;			 		
		}
		if(found==0){
			*aux2 = *aux;	
		} 
		aux++;
	}
}

int main(){
	char str[] = "jijajo";
	myFirstRemoveRepeatedChars(str);
	printf("%s\n", str);

	return 0;
}