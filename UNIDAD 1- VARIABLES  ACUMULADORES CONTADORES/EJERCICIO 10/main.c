#include <stdio.h>
#include <stdlib.h>

//10.  	Diseñar un programa que calcule la superficie de un triángulo a partir del ingreso de su base y altura y muestre el resultado.

int main(int argc, char *argv[]) {
	
	int base;
	int altura;
	float resultado;

	
	printf("\n\t    EJERCICIO 10\247 \n");
	printf("______________________________________\n\n");
	
	printf("\nIngrese la base del triangulo: ");
	scanf("%d",&base);
	printf("\nIngrese la altura del triangulo: ");
	scanf("%d",&altura);
	resultado=base*((float)altura/2);
    
	printf("______________________________________\n");
	printf("\nLa superficie del triangulo es: %.2f \n",resultado);

	printf("______________________________________\n\n\n\n");	
			
	return 0;
}
