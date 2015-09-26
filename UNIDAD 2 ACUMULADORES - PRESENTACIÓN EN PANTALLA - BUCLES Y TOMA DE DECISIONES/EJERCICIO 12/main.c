#include <stdio.h>
#include <stdlib.h>

//12.  	Escribir en C un programa que muestre los números impares entre 0 y 100 y que imprima cuantos impares hay

int main(int argc, char *argv[]) {

int i;
int num=0;
int cantidad;

for(i=0;i<100;i++){
	num=num+1;
	if(num%2!=0){
		printf("%d\n",num);
	cantidad=cantidad+1;	
	}	
}

printf("\n\nLa cantidad de numeros impares es: %d\n\n",cantidad);

	return 0;
}
