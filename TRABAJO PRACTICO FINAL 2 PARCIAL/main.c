#include "types.h"
#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
while(opcionMenu!=1||2||3||4||5||6)
{
   switch(opcionMenu)
   {
	case 1:   
    system("cls");
    printf("INGRESAR\n");
    printf("_______________________\n");
	
	nuevaPersona(self);
	
    printf("_______________________\n\n\n\n");
	system("PAUSE");
    system("cls"); 
	opcionMenu=menu(opcionMenu);
    break;

    case 2:
    system("cls");
    printf("LISTAR\n");
    printf("_______________________\n");
    if(al_isEmpty(self)==1){
    	printf("\nNo existen datos para mostrar!!\n\n");
    }
    else{ 
    	for(c=0;c<self->size;c++){
		printf("\nValor %d Indice %d\n",self->pElements[c]->edad,c);
		printf("Valor %s Indice %d\n",self->pElements[c]->nombre,c);	
	    }
	}
    printf("_______________________\n\n\n\n");
	system("PAUSE");
    system("cls"); 
    opcionMenu=menu(opcionMenu);        
    break;
	
	case 3:
    system("cls");
    printf("ELIMINAR POR INDICE\n");
    printf("_______________________\n");

	if(al_isEmpty(self)==0){
	do{
    	printf("\nIndices disponibles\n");
        printf("_______________________\n");
		for(c=0;c<self->size;c++){
		printf("\nValor %d Indice %d\n",self->pElements[c]->edad,c);
		printf("Valor %s Indice %d\n",self->pElements[c]->nombre,c);
	    }
	    
		printf("_______________________\n");
		printf("\nIndique el indice a borrar:  ");
		
		scanf("%d",&aux);
		remover(self,aux);
        system("cls"); 
        printf("\nIndices borrado: %d",aux);
		printf("\n\nIndices disponibles\n");
        printf("_______________________\n");
		for(c=0;c<self->size;c++){
		printf("\nValor %d Indice %d\n",self->pElements[c]->edad,c);
		printf("Valor %s Indice %d\n",self->pElements[c]->nombre,c);

	}	
		if(al_isEmpty(self)==1){
		printf("\nNo existen mas indices disponibles para borrar\n\n\n\n");
		break;
	    }
		printf("\nQuieres eliminar otro ? (s/n):  ");
		scanf("%s",resp); 
	    system("cls"); 
	}while(strcmp(resp,"s")==0&&al_isEmpty(self)==0);
    }
    else{
    printf("\nNo existen indices disponibles para borrar\n\n\n");	
	}
    system("PAUSE");
    system("cls"); 
    opcionMenu=menu(opcionMenu);     
    break; 

    case 4:
    system("cls");
    printf("BORRAR ARRAYLIST\n");
    printf("_______________________\n");
    
    if(al_isEmpty(self)==1){
    	printf("\nNo existen datos en ArrayList para borrar\n\n\n");
    }
    else{
    printf("\nUsted va a borrar todo el contenido!!! Desea continuar? (s/n):  ");
    scanf("%s",resp);
    
	if(strcmp(resp,"s")==0)
		{
		borrarArrayList(self);
    	}	
    }
    printf("______________________________________________________________\n\n");
    printf("Se borraron los datos con exito!!\n\n\n");
	system("PAUSE");
    system("cls"); 
    opcionMenu=menu(opcionMenu);        
    break;
    
    case 5:
    system("cls");
    printf("INGRESAR DATO EN INDICE ESPECIFICO\n");
    printf("_______________________\n");
    
        if(al_isEmpty(self)==1){
    	printf("\nNo se ingresaron datos aun!! Elija la opcion 1 del menu principal\n\n");
    }
    else{ 

    ingresoPorIndice(self);
	
	    }
	
    
   
	system("PAUSE");
    system("cls"); 
    opcionMenu=menu(opcionMenu);        
    break;

    case 6:
    system("PAUSE");	
    return 0;
    break;
  
    default:
    system("cls");
    printf("\t\tOPCIONES ARRAY LIST\n\n(Indique numero de la opcion que desea realizar)\n\n\n1-INGRESAR\n\n2-LISTAR\n\n3-ELIMINAR POR INDICE\n\n4-BORRAR ARRAYLIST\n\n5-INGRESAR DATO EN INDICE ESPECIFICO\n\n6-SALIR\n\n");
    printf("\nIngreso invalido, no existe opcion con ese numero\n");
    printf("\nSu opcion es: ");
    scanf("%d",&opcionMenu);
    break;  
     }
  }
		
	
	
	
	return 0;
}
