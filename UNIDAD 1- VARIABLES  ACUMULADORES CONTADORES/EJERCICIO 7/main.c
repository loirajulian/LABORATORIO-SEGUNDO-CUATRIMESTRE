#include <stdio.h>
#include <stdlib.h>

//7.  	Escribir el programa necesario para calcular y mostrar el cuadrado de un número. 
//El número debe ser mayor que cero, en caso de error que aparezca el mensaje "ERROR, el número debe ser mayor que cero"

int main(int argc, char *argv[]) {
	
    int a;

	int cuadrado;

	
	printf("\n\t    EJERCICIO 7\247 \n");
	printf("______________________________________\n\n");

	do{
	printf("\nIngrese 1\247 numero: ");
	scanf("%d",&a);
	printf("______________________________________\n");
		if(a<=0)
		{
		printf("\nERROR, el numero debe ser mayor que cero!!!\n");
		printf("______________________________________\n");
		}
    }while(a<=0);	
		
	system("cls");

	cuadrado=a*a;
    
	printf("\nEl cuadrado del valor %d es: %d \n",a,cuadrado);
	printf("______________________________________\n\n\n\n");	
	
	
	
	
	
	
	
	return 0;
}
