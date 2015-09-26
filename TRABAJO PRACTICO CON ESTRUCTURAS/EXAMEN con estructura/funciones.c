#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define CAN 5


int menu(int opcionMenu)
{
  printf("\t\tOPCIONES\n\n(Indique numero de la opcion que desea realizar)\n\n\n1-ALTA\n\n2-MODIFICAR\n\n3-BAJA\n\n4-INFORMAR\n\n5-LISTAR\n\n6-Salir\n\n");
  printf("\nSu opcion es: ");
  scanf("%d",&opcionMenu);
  printf("\n_______________________\n\n\n\n"); 
  return opcionMenu;     
}

void altaProducto(int p,struct carga C[])
{   
        printf("\n%d         %.2f           %d                  %s\n",C[p].codigo,C[p].importe,C[p].cantidad,C[p].producto);
		printf("\nIngrese Codigo Producto: ");
        scanf("%d",&C[p].codigo);
        fflush(stdin);
        
		printf("\nIngrese Producto: ");
        scanf("%s",C[p].producto);
        fflush(stdin);
        
        printf("\nIngrese Cantidad: ");
        scanf("%d",&C[p].cantidad);
        fflush(stdin);
        
        printf("\nIngrese Importe: ");
        scanf("%f",&C[p].importe);
        fflush(stdin);
        
		system("cls");
}

void listar(int limite,int p,struct carga C[])
{
  int i; 
     
      for(i=0;i<limite;i++)
      {
         if(C[i].codigo!=-1)
         {
         
		 
		 printf("\n%d         %.2f           %d                  %s\n",C[i].codigo,C[i].importe,C[i].cantidad,C[i].producto);
      		
		 }   
      }
	  
	  
	      
printf("\n_______________________\n\n\n\n");
system("PAUSE");
system("cls");
}

