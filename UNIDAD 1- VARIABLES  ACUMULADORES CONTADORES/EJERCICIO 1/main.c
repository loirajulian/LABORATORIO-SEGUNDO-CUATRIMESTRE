#include <stdio.h>
#include <stdlib.h>

//1-Ingresar 5 números y calcular su media


int main(int argc, char *argv[]) {
	
	int a;
	int b;
	int posicion=1;
	int suma;
	float promedio;
	int i;
	
	printf("\n\t    EJERCICIO 1\247 \n");
	printf("______________________________________\n\n");
	printf("Cuantos numeros desea promediar: ");
	scanf("%d",&b);
	printf("______________________________________\n\n");
	for(i=0;i<b;i++)
	{
	printf("\nIngrese %d\247 numero: ",posicion);
	scanf("%d",&a);
	suma=suma+a;
    posicion=posicion+1;
	}  
	promedio=(float)suma/b;
	printf("______________________________________\n");
	printf("\nEl promedio es: %.2f \n",promedio);
	printf("______________________________________\n\n\n\n");
	
	system("PAUSE");
	
	return 0;
}
