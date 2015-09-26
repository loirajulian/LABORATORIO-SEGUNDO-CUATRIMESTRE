#include <stdio.h>
#include <stdlib.h>

//16.  	Diseñar un programa que imprima y sume la serie de números 3,6,9,12,...,99.

int main(int argc, char *argv[]) {
	
int i;
int suma=0;

for(i=0;i<100;i=i+3){

		printf("%d\n",i);	
	suma=suma+i;	
}
 
printf("\nLa suma desde 0 incrementado en 3 hasta %d es: %d",i-3,suma);
	
	return 0;
}
