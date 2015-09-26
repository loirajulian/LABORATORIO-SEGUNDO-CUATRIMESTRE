#include <stdio.h>
#include <stdlib.h>

//42.  	Se ingresa por consola la cantidad de agua caída, en milímetros día a día durante un mes. 
//Se pide determinar el día de mayor lluvia, el de menor y el promedio

int main(int argc, char *argv[]) {
	
	int i;
	int num;
	int max;
	int min;
	int diamax=0;
	int diamin=0;
	float prom=0;
	int inicial=0;
	
	for(i=0;i<4;i++){
		
		printf("\nIngrese un valor del dia %d\247 de lluvia caida: ",i+1);
		scanf("%d",&num);	
		if(inicial==0)
        {max=num;
        min=num;
        inicial=1;}
        if(num>max)
        {max=num;
		diamax=i;
		}
        if(num<min)
        {min=num;
		diamin=i;
		}	
		prom=(float)prom+num;		
	}
	prom=prom/i;
	
	printf("\nEl maximo es: %d",max);
	printf("\nEl minimo es: %d",min);
	printf("\nEl dia minimo es el %d\247",diamin+1);
	printf("\nEl dia maximo es el %d\247",diamax+1);
	
	printf("\nEl promedio es: %.2f\n",prom);
	
	
	
	return 0;
}
