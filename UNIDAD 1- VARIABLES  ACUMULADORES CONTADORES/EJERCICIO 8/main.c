#include <stdio.h>
#include <stdlib.h>

//8.  	De 10 números ingresadas indicar cuantos son mayores a cero y cuantos son menores a cero

int main(int argc, char *argv[]) {

	int a;
	int posicion=1;
	int contadorPosivos=0;
	int contadorNegativos=0;
	int i;
	
	printf("\n\t    EJERCICIO 8\247 \n");
	printf("______________________________________\n\n");

	for(i=0;i<10;i++)
	{
		printf("\nIngrese %d\247 numero:\t",posicion);
		scanf("%d",&a);
	
			if(a>0)
			{
			contadorPosivos=contadorPosivos+1;	
			}
			if(a<0)
			{
			contadorNegativos=contadorNegativos+1;	
			}
	
				while(a==0)
				{
				printf("\nIngrese valor distinto a 0!!! ");
				scanf("%d",&a);
					if(a>0)
					{
					contadorPosivos=contadorPosivos+1;	
					}
					if(a<0)
					{
					contadorNegativos=contadorNegativos+1;	
					}
				}
    
	posicion=posicion+1;
	}  

	printf("\n______________________________________\n");
	printf("\nCANTIDAD NUMEROS POSITIVOS: %d\n\nCANTIDAD NUMEROS NEGATIVOS: %d\n\n",contadorPosivos,contadorNegativos);
	printf("______________________________________\n\n\n\n");
	








	return 0;
}
