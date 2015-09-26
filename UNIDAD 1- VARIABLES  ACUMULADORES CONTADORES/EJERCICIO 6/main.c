#include <stdio.h>
#include <stdlib.h>

//6.  	Escribir un programa que realice las siguientes acciones:
//"	Limpie la pantalla
//"	Declare 2 variables y les asigne sendos valores
//"	Realice la resta de dichas variables y muestre por pantalla la leyenda "Resultado positivo" en caso de ser mayor que cero o "Resultado negativo" si es menor que cero


int main(int argc, char *argv[]) {
	
	int a;
	int b;
	int resultado;

	
	printf("\n\t    EJERCICIO 6\247 \n");
	printf("______________________________________\n\n");
	
	printf("\nIngrese 1\247 numero: ");
	scanf("%d",&a);
	printf("\nIngrese 2\247 numero: ");
	scanf("%d",&b);
	resultado=a-b;
    
	printf("______________________________________\n");
	printf("\nEl resultado es: %d \n",resultado);
	if(resultado>0){
	printf("\nResultado positivo \n");	
	}
	if(resultado<0){
	printf("\nResultado negativo \n");	
	}
	printf("______________________________________\n\n\n\n");	
	
	
	return 0;
}
