#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define CAN 15


int main(int argc, char *argv[]) {
	
int opcionMenu=0;
int opcionMenuInformar=0;
int opcionListar=0;
struct carga C[CAN];
struct carga auxC;
int i;
int posicion=0;
int codigoModificar;
int posicionUltima;
float max;

	
opcionMenu=menu(opcionMenu);
	
	for(i=0;i<CAN;i++)
    {             
       C[i].codigo=-1;
       C[i].importe=-1;
       C[i].cantidad=-1;                  
	   strcpy(C[i].producto," ");          
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
    validarCodigoExistente(&codigoModificar,C,CAN);
	printf("\n_______________________");
    		
            for(i=0;i<CAN;i++)
            {
                if(codigoModificar==C[i].codigo)
    		    {
    			printf("\n\nIngrese nuevos datos");
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
    validarCodigoExistente(&codigoModificar,C,CAN);
			
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
	
	case 4:
    system("cls");

	while(opcionMenuInformar!=1||2||3){
	switch(opcionMenuInformar)//sub menu en el swicht para opciones en la opcion 4
    {
	case 1:
    system("cls");
	printf("\nINFORMAR\n");	
    printf("___________________________________________________\n");
	printf("\n\t\tMAYOR IMPORTE\n"); 
    printf("___________________________________________________\n");
	mayorImporte(C);
	system("PAUSE");
	system("cls");
	break; 
	
	case 2:
    system("cls");
	printf("\nINFORMAR\n");	
    printf("___________________________________________________\n");
	printf("\n\t\tSUMA TOTAL IMPORTE\n"); 
    printf("___________________________________________________\n");
	sumaImportes(C);
	system("PAUSE");
	system("cls");
	break; 
	
	case 3:
    system("cls");
	printf("\nINFORMAR\n");	
    printf("___________________________________________________\n");
	printf("\n\t\tPROMEDIOS IMPORTES\n"); 
    printf("___________________________________________________\n");
	promedioImportes(C);
	system("PAUSE");
	system("cls");	
	break; 
	}  
	opcionMenuInformar=menuInformar(opcionMenuInformar);
	if(opcionMenuInformar>3){
		break;
	}
    }
   system("cls");
   opcionMenu=menu(opcionMenu);	 
   break; 
	
   case 5:
    
	system("cls");

	while(opcionListar!=1||2){
	switch(opcionListar)//sub menu en el swicht para opciones en la opcion 5
    {
	case 1:
    system("cls");
	printf("\nLISTAR\n");	
    printf("___________________________________________________\n");
	printf("\n\t\tPOR CANTIDAD DESCENDENTE\n"); 
    printf("___________________________________________________\n");
	listarCantidadAscendente(CAN,posicion,C,auxC);
	system("PAUSE");
	system("cls");
	break; 
	
	case 2:
    system("cls");
	printf("\nLISTAR\n");	
    printf("___________________________________________________\n");
	printf("\n\t\tPOR DESCRIPCION ASCENDENTE\n"); 
    printf("___________________________________________________\n");
	listarDescripcionDescendente(CAN,posicion,C,auxC);
	system("PAUSE");
	system("cls");
	break; 
	}  
		opcionListar=menuListar(opcionListar);
		if(opcionListar>2){
		break;
		}
    }
   system("cls");
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
