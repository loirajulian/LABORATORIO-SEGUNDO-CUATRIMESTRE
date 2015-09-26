#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define CAN 5


int main(int argc, char *argv[]) {
	
int opcionMenu=0;
struct carga C[CAN];
int i;
int posicion=0;
int codigoModificar;
int posicionUltima;
int inicial;
float max;

	
opcionMenu=menu(opcionMenu);
	
	for(i=0;i<CAN;i++)
    {             
       C[i].codigo=-1;
       C[i].importe=-1;
       C[i].cantidad=-1;                  
	   strcpy(C[i].producto,"Juan");          
    }
	
while(opcionMenu!=1||2||3||4||5||6||7||8)
{
   switch(opcionMenu)
   {
	case 1:   
    system("cls");
    printf("ALTA PRODUCTO\n");
    printf("_______________________\n");
    altaProducto(posicion,C);
    posicion=posicion+1;
    posicionUltima=posicion;
	opcionMenu=menu(opcionMenu);
    break;

    case 2:
    system("cls");
    printf("\nMODIFICAR\n");
    printf("_______________________\n");
   	printf("\nCodigo a editar: ");
    scanf("%d",&codigoModificar);
    printf("\n_______________________");
    		
            for(i=0;i<CAN;i++)
            {
                if(codigoModificar==C[i].codigo)
    		    {
    			printf("\nIngrese nuevos datos");
    			printf("\n_______________________\n");
    			posicion=i;
    			altaProducto(posicion,C);	
                }           
            }
            posicion=posicionUltima;
    opcionMenu=menu(opcionMenu);        
    break;
	
	case 3:
    system("cls");
    printf("\nBAJA\n");
   	printf("\nCodigo a dar de BAJA: ");
    scanf("%d",&codigoModificar);
    		
            for(i=0;i<CAN;i++)
            {
                if(codigoModificar==C[i].codigo)
    		    {
      			 C[i].codigo=-1;
       			 C[i].importe=-1;
      			 C[i].cantidad=-1;              
      			 C[i].producto[0]='\0';  	
                }
            } 
    printf("\n\n\nCodigo que dio de BAJA: %d ",codigoModificar); 
    printf("\n_______________________\n\n\n\n");    
    system("PAUSE");
    system("cls");        
    opcionMenu=menu(opcionMenu);     
    break; 
	
	//case 4:
    //system("cls");
    //printf("\nINFORMAR\n");	
    //printf("_______________________\n");
	
	//for(i=0;i<CAN;i++)
    //{
      //    if(C[i].importe!=-1)
        //  {
          //    if(inicial==0)
            //  {
            //  max=C[i].importe;
              //inicial=1;
              //}
              //if(C[i].importe>max)
             // {
              //max=C[i].importe;
              //} 
         // }
   // }
	//printf("\nMAXIMO\n"); 
    //printf("__________________________\n\n"); 
    
	//for(i=0;i<CAN;i++)
    //{ 
     // if(C[i].importe==max) 
    //  {                  
     // printf("El MAXIMO es: %f\n\nProducto: %s\n\n",C[i].importe,C[i].producto);
    //  }
   // }
   // printf("__________________________\n\n\n"); 
   //system("PAUSE");
  // system("cls");
  // opcionMenu=menu(opcionMenu);  
 //  break; 
	
   case 5:
    system("cls");
    printf("HACER LISTA\n");
    listar(CAN,posicion,C);
    opcionMenu=menu(opcionMenu);
    break; 

    case 6:
    system("PAUSE");	
    return 0;
    break;
  
    default:
    system("cls");
    printf("\t\tOPCIONES\n\n(Indique numero de la opcion que desea realizar)\n\n\n1-ALTA\n\n2-MODIFICAR\n\n3-BAJA\n\n4-INFORMAR\n\n5-LISTAR\n\n6-Salir\n\n");
    printf("\nIngreso invalido, no existe opcion con ese numero\n");
    printf("\nSu opcion es: ");
    scanf("%d",&opcionMenu);
    break;  
     }
  }
	
	return 0;

}
