#include "types.h"
#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	//Variables
	char resp[2];
	int aux;
	int c;
	int opcionMenu=0;
	

	//Tipo de dato ArrayList puntero le pongo nombre self
    ArrayList* self;
    //Le asigno el puntero 
	self=newArrayList();

	//inicializo mi menu con sus distintas opciones
	opcionMenu=menu(opcionMenu);
while(opcionMenu!=1||2||3||4)
{
   switch(opcionMenu)
   {
	case 1:   
    system("cls");
    printf("INGRESAR\n");
    printf("_______________________\n");
	
	nuevoNumero(self);
	
    printf("_______________________\n\n\n\n");
	system("PAUSE");
    system("cls"); 
	opcionMenu=menu(opcionMenu);
    break;

    case 2:
    system("cls");
    printf("LISTAR\n");
    printf("_______________________\n");
    
    	for(c=0;c<self->size;c++){
		printf("Valor %d Indice %d\n",*(int*)(self->pElements[c]),c);

	}
    printf("_______________________\n\n\n\n");
	system("PAUSE");
    system("cls"); 
    opcionMenu=menu(opcionMenu);        
    break;
	
	case 3:
    system("cls");
    printf("ELIMINAR\n");
    printf("_______________________\n");

	do{
    	for(c=0;c<self->size;c++){
		printf("Valor %d Indice %d\n",*(int*)(self->pElements[c]),c);

	}
		printf("Indique un indice\n");
		scanf("%d",&aux);
		remover(self,aux);
        
		for(c=0;c<self->size;c++){
		printf("Valor %d Indice %d\n",*(int*)(self->pElements[c]),c);

	}
		printf("\nQuieres eliminar otro ? (s/n):  ");
		scanf("%s",resp);
	}while(strcmp(resp,"s")==0);
	
    system("PAUSE");
    system("cls"); 
    opcionMenu=menu(opcionMenu);     
    break; 

    case 4:
    system("PAUSE");	
    return 0;
    break;
  
    default:
    system("cls");
    printf("\t\tOPCIONES ARRAY LIST\n\n(Indique numero de la opcion que desea realizar)\n\n\n1-INGRESAR\n\n2-LISTAR\n\n3-ELIMINAR\n\n4-SALIR\n\n");
    printf("\nIngreso invalido, no existe opcion con ese numero\n");
    printf("\nSu opcion es: ");
    scanf("%d",&opcionMenu);
    break;  
     }
  }
		
	
	
	
	return 0;
}
