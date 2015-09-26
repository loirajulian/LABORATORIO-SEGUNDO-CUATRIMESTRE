#include <stdio.h>
#include <stdlib.h>

//2.	Escribir el programa necesario para calcular la suma de dos números. Mostrar el resultado//

int main(int argc, char *argv[]) {
	
	int a;
	int b;
	int resultado;

	
	printf("\n\t    EJERCICIO 2\247 \n");
	printf("______________________________________\n\n");
	
	printf("\nIngrese 1\247 numero: ");
	scanf("%d",&a);
	printf("\nIngrese 2\247 numero: ");
	scanf("%d",&b);
	resultado=a+b;
    
	printf("______________________________________\n");
	printf("\nEl resultado es: %d \n",resultado);
	printf("______________________________________\n\n\n\n");	
	
	
	
	return 0;
}
