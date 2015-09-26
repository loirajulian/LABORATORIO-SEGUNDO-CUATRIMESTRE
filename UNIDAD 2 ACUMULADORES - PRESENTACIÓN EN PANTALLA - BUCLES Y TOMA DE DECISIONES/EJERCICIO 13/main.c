#include <stdio.h>
#include <stdlib.h>

//13.  	Hacer el programa que imprima los números pares entre el 1 y el 100

int main(int argc, char *argv[]) {
	
	
int i;
int num=0;
int cantidad;

for(i=0;i<100;i++){
	num=num+1;
	if(num%2==0){
		printf("%d\n",num);
	cantidad=cantidad+1;	
	}	
}

	return 0;
}
