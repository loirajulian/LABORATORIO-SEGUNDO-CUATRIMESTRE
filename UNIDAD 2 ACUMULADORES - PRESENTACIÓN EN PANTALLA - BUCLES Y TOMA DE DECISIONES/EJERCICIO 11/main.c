#include <stdio.h>
#include <stdlib.h>

//11.  	Escribir un programa que realice lea por teclado 20 caracteres.
// Luego de la lectura indicar cuantas "a" se ingresaron, cuantas "e, i, o, u"

int main(int argc, char *argv[]) {
	
	char letras;
	int j;
	int contadorA=0;
	int contadorE=0;
	int contadorI=0;
	int contadorO=0;
	int contadorU=0;
	
	
	
	for(j=0;j<20;j++){
	
	printf("\nIngrese la %d\247 vocal:  ",j+1);
	scanf("%s",&letras);
	printf("\n____________________________________\n");
	while(letras!='a'&&letras!='e'&&letras!='i'&&letras!='o'&&letras!='u')
	{	
	printf("\nLo ingresado no es vocal!!!\n\nIngrese nuevamente vocal  \n");
	printf("\n____________________________________\n");
	printf("\nIngrese la %d\247 vocal:  ",j+1);
	scanf("%s",&letras);
    }
    
	switch(letras)
	{	
	case 'a':
	contadorA=contadorA+1;
	break;	
		case 'e':
	contadorE=contadorE+1;
	break;
		case 'i':
	contadorI=contadorI+1;
	break;
		case 'o':
	contadorO=contadorO+1;
	break;
		case 'u':
	contadorU=contadorU+1;
	break;
    }
		
		
	}
	
	printf("\nSe ingresaron %d letras A  ",contadorA);
	printf("\nSe ingresaron %d letras E  ",contadorE);
	printf("\nSe ingresaron %d letras I  ",contadorI);
	printf("\nSe ingresaron %d letras O  ",contadorO);
	printf("\nSe ingresaron %d letras U  ",contadorU);
	
	
	
	
	return 0;
}





//||'e'||'i'||'o'||'u'
