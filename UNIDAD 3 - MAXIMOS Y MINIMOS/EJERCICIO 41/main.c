#include <stdio.h>
#include <stdlib.h>

//41.  	Diseñar un programa que lea 4 números e imprima el mayor de los cuatro

int main(int argc, char *argv[]) {
	
	int i;
	int num;
	int max;
	int inicial=0;
	
	for(i=0;i<4;i++){
		
		printf("\nIngrese un valor: ");
		scanf("%d",&num);
			
		if(inicial==0)
        {max=num;
        inicial=1;}
        if(num>max)
        {max=num;} 	
	}
	
	printf("\nEl maximo es: %d",max);
	
	
	return 0;
}
