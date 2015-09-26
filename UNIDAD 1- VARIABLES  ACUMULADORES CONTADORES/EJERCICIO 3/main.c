#include <stdio.h>
#include <stdlib.h>

//3.	Escribir  un programa que realice las siguientes acciones
//	Limpie la pantalla
//	Asigne a 2 variables numero1 y numero2 valores distintos de cero
//	Efectúe el producto de dichas variables
//	Muestre el resultado pos pantalla
//	Obtenga el cuadrado de numero1 y lo muestre par pantalla


int main(int argc, char *argv[]) {
		
	int a;
	int b;
	int producto;
	int cuadrado;

	
	printf("\n\t    EJERCICIO 3\247 \n");
	printf("______________________________________\n\n");
	
	system("PAUSE");
	system("cls");
	
	do{
	printf("\nIngrese 1\247 numero: ");
	scanf("%d",&a);
	printf("______________________________________\n");
		if(a==0)
		{
		printf("\nIngrese numero mayor a 0\n");
		printf("______________________________________\n");
		}
    }while(a==0);	
	
	do{
	printf("\nIngrese 2\247 numero: ");
	scanf("%d",&b);
	printf("______________________________________\n");
		if(b==0)
		{
		printf("\nIngrese numero mayor a 0\n");
		printf("______________________________________\n");
		}
    }while(b==0);	
	
	producto=a*b;
	cuadrado=a*a;
    
	printf("\nEl valor 1\247: %d\nEl valor 2\247: %d\n\nEl producto es: %d\n\nEl cuadrado del 1\247 valor %d es: %d \n",a,b,producto,a,cuadrado);
	printf("______________________________________\n\n\n\n");	
	

	
	return 0;
}
