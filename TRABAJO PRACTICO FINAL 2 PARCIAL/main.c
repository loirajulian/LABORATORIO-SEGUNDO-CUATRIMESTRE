#include "types.h"
#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	//Variables
	
	int opcionMenu=0;
	
	//Tipo de dato ArrayList puntero le pongo nombre self
    ArrayList* self;
    //Le asigno el puntero 
	self=newArrayList();

	//inicializo mi menu con sus distintas opciones
	opcionMenu=menu(opcionMenu);
while(opcionMenu!=1||2||3||4||5||6||7||8||9||10||11||12)
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
    
	listarDatos(self);
	
    		printf("_______________________\n\n\n\n");
			system("PAUSE");
    		system("cls"); 
   			opcionMenu=menu(opcionMenu);        
    		break;
	
	case 3:
    		system("cls");
    		printf("ELIMINAR POR INDICE\n");
    		printf("_______________________\n");

	eliminarPorIndice(self);

    		system("PAUSE");
    		system("cls"); 
    		opcionMenu=menu(opcionMenu);     
    		break; 

    case 4:
    		system("cls");
    		printf("BORRAR ARRAYLIST\n");
    		printf("_______________________\n");
    
	borrarTotalArrayList(self);

			system("PAUSE");
    		system("cls"); 
    		opcionMenu=menu(opcionMenu);        
    		break;
    
    case 5:
    		system("cls");
    		printf("INGRESAR DATO EN INDICE ESPECIFICO\n");
    		printf("_______________________\n");
    
    ingresoIndice(self);
   
			system("PAUSE");
    		system("cls"); 
    		opcionMenu=menu(opcionMenu);        
    		break;
		
    case 6:
    		system("cls");
    		printf("INDEX OF\n");
    		printf("_______________________\n");
    
	mostrarIndicePrimero(self); //Retorna el índice de la primera aparición de un valor en la ArrayList.

			system("PAUSE");
    		system("cls"); 
    		opcionMenu=menu(opcionMenu);        
    		break;    		

    case 7:
    		system("cls");
    		printf("TAMA\245O DE ARRAY LIST\n");
    		printf("_______________________\n");
    	
	tamanioArrayList(self);
  
			system("PAUSE");
    		system("cls"); 
    		opcionMenu=menu(opcionMenu);        
    		break;   
    case 8:
    		system("cls");
    		printf("PUSH\n");
    		printf("_______________________\n");
    	
    al_push(self);// Desplaza los elementos e inserta en la posición index
  
			system("PAUSE");
    		system("cls"); 
    		opcionMenu=menu(opcionMenu);        
    		break; 	
    case 9:
    		system("cls");
    		printf("ELIMINACION POP\n");
    		printf("_______________________\n");
    	
	eliminarPop(self);//Retorna un puntero al elemento que se encuentra en el índice especificado y luego lo elimina de la lista.
  
			system("PAUSE");
    		system("cls"); 
    		opcionMenu=menu(opcionMenu);        
    		break; 	
			
    case 10:
    		system("cls");
    		printf("EXISTE ELEMENTO\n");
    		printf("_______________________\n");
    	
	existeElemento(self);
  
			system("PAUSE");
    		system("cls"); 
    		opcionMenu=menu(opcionMenu);        
    		break; 	

    case 11:
    		system("cls");
    		printf("CLONAR ARRAYLIST\n");
    		printf("_______________________\n");
    	
	hacerClondeArrayList(self);
  
			system("PAUSE");
    		system("cls"); 
    		opcionMenu=menu(opcionMenu);        
    		break; 				
			
							

    case 12:
    		system("PAUSE");	
    		return 0;
    		break;
  
    default:
    		system("cls");
    		printf("\t\t\tOPCIONES ARRAY LIST\n\n\t(Indique numero de la opcion que desea realizar)\n\n\n \20 1-INGRESAR\t\t\t\t\t \20 2-LISTAR\n\n \20 3-ELIMINAR POR INDICE\t\t\t \20 4-BORRAR ARRAYLIST\n\n \20 5-INGRESAR DATO EN INDICE ESPECIFICO\t\t \20 6-INDEX OF\n\n \20 7-TAMA\245O ARRAY LIST\t\t\t\t \20 8-PUSH\n\n \20 9-ELIMINACION POP\t\t\t\t \20 10-EXISTE ELEMENTO\n\n \20 11-CLONAR ARRAY\n\n\n\n \20 12-SALIR\n\n");
    		printf("\nIngreso invalido, no existe opcion con ese numero\n");
    		printf("\nSu opcion es: ");
    		scanf("%d",&opcionMenu);
    		break;  
     }
  }
		
	return 0;
}
