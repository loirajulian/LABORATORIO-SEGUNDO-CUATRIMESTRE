#include <stdio.h>
#include <stdlib.h>

//9.  	Diseñar un programa que calcule la longitud de la circunferencia y el área del círculo de radio dado.

int main(int argc, char *argv[]) {
	
	float radio;
	float diametro;
	float longCircunferencia;
	float areaCirculo;
	double pi=3.1415926535897931;
	
		
	printf("\n\t    EJERCICIO 9\247 \n");
	printf("______________________________________\n\n");
	
	printf("Ingrese el valor de radio del circulo:  ");
	scanf("%f",&radio);
	printf("______________________________________\n\n");
	
	diametro=radio*2;
    longCircunferencia=diametro*pi;
	areaCirculo=pi*(radio*radio);
	
		printf("\nEl radio es : %.f\n",radio);
		printf("\nNumero pi: %.16f\n",pi);
		printf("\nEl diametro es: %.f\n",diametro);
		printf("\nLa circunferencia es: %.2f\n",longCircunferencia);
		printf("\nEl area es: %.2f\n",areaCirculo);
		
	printf("______________________________________\n\n");
	
	
	return 0;
}
