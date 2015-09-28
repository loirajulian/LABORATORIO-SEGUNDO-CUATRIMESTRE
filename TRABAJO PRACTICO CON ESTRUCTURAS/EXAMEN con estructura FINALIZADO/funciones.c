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
		printf("\nIngrese Codigo Producto: ");
        scanf("%d",&C[p].codigo);
        validarCodigo(p,C);
        fflush(stdin);
        
		printf("\nIngrese Producto: ");
        gets(C[p].producto);
        validarCaracteres(p,C);
        fflush(stdin);
        
        printf("\nIngrese Cantidad: ");
        scanf("%d",&C[p].cantidad);
        validarCantidad(p,C);
        fflush(stdin);
        
        printf("\nIngrese Importe: ");
        scanf("%f",&C[p].importe);
        validarImporte(p,C);
		fflush(stdin);
        
		system("cls");
}

void listarCantidadAscendente(int limite,int p,struct carga C[],struct carga auxC)
{
  int i; 
  int j;
     
      for(i=0;i<limite;i++)
      {
      	for(j=i+1;j<limite;j++)
         {
 			if(C[i].cantidad<C[j].cantidad){//del mayor al menor ordena
		 		
				auxC=C[i];
		 		C[i]=C[j];
		 		C[j]=auxC;
      	    }
		 }   
      }
   printf("\nCODIGO      IMPORTE     CANTIDAD    PRODUCTO\n"); 
   printf("___________________________________________________\n\n");     
   for(i=0;i<limite;i++)
      {
      	if(C[i].cantidad!=-1)
		{		  
         printf("\n%d             %.2f\t     %d\t         %s\n",C[i].codigo,C[i].importe,C[i].cantidad,C[i].producto);	
        }
      }
printf("___________________________________________________\n\n\n"); 
}

void listarDescripcionDescendente(int limite,int p,struct carga C[],struct carga auxC)
{
  int i; 
  int j;
     
      for(i=0;i<limite;i++)
      {
      	for(j=i+1;j<limite;j++)
         {		
		  if(strcmp(C[i].producto,C[j].producto)>0)
          {	
				auxC=C[i];
		 		C[i]=C[j];
		 		C[j]=auxC;
		   /*strcpy(auxC,C[i]); ordenamiento para textos
           strcpy(C[i],C[j]);           
           strcpy(C[j],auxC);*/ 
      	    }
		 }   
      }
        printf("\nCODIGO      IMPORTE     CANTIDAD    PRODUCTO\n"); 
		printf("___________________________________________________\n\n");     
   for(i=0;i<limite;i++)
      {
      	if(C[i].cantidad!=-1)
		{		  
		 printf("\n%d             %.2f\t     %d\t         %s\n",C[i].codigo,C[i].importe,C[i].cantidad,C[i].producto);	
        }
      }
printf("___________________________________________________\n\n\n"); 
}

int menuInformar(int opcionMenuInformar)
{
  printf("\t\tOPCIONES\n\n(Indique numero de la opcion que desea realizar)\n\n\n1-MAYOR IMPORTE\n\n2-SUMA TOTAL IMPORTE\n\n3-PROMEDIOS IMPORTES\n\n-OTRO NUMERO - VOLVER MENU PRINCIPAL\n\n");
  printf("\nSu opcion es: ");
  scanf("%d",&opcionMenuInformar);
  printf("\n___________________________________________________\n\n\n\n"); 
  return opcionMenuInformar;     
}

int menuListar(int opcionListar)
{
  printf("\t\tOPCIONES\n\n(Indique numero de la opcion que desea realizar)\n\n\n1-POR CANTIDAD DESCENDENTE\n\n2-POR DESCRIPCION ASCENDENTE\n\n-OTRO NUMERO - VOLVER MENU PRINCIPAL\n\n");
  printf("\nSu opcion es: ");
  scanf("%d",&opcionListar);
  printf("\n___________________________________________________\n\n\n\n"); 
  return opcionListar;     
}

void mayorImporte(struct carga C[])
{
	int i;
	int inicial=0;
	float max;
	
	for(i=0;i<CAN;i++)
    {
          if(C[i].importe!=-1)
          {
              if(inicial==0)
              {
              max=C[i].importe;
              inicial=1;
              }
              if(C[i].importe>max)
              {
              max=C[i].importe;
              } 
          }
    }
    
	for(i=0;i<CAN;i++)
    { 
      if(C[i].importe==max) 
     {                  
     printf("\nEl MAXIMO es: %.2f\n\nProducto: %s\n\n",C[i].importe,C[i].producto);
      }
    }
    printf("___________________________________________________\n\n\n"); 
}

void sumaImportes(struct carga C[])
{
	int i;
	float suma=0;

	for(i=0;i<CAN;i++)
    {
          if(C[i].importe!=-1)
          {
			suma=suma+C[i].importe;
		  }
    }	
	printf("\nLa suma total de los importes es: %.2f\n\n",suma);
	printf("___________________________________________________\n\n\n"); 	
}

void promedioImportes(struct carga C[])
{
	int i;
	float suma=0;
	float promedio=0;
	float contador=0;
	int contadorD=0;
	for(i=0;i<CAN;i++)
    {
          if(C[i].importe!=-1)
          {
			suma=suma+C[i].importe;
			contador=contador+1;
		  }
    }	
	promedio=suma/contador;
	for(i=0;i<CAN;i++)
    {
          if(promedio<C[i].importe)
          {
			contadorD=contadorD+1;
		    
		  }
    }   
	printf("\nEl promedio de los importes es: %.2f\n\n",promedio);
	printf("\nLos cantidad de importes que superan el promedio son: %d\n\n",contadorD);	
	printf("___________________________________________________\n\n\n"); 
}

int validarCodigo(int p,struct carga C[])
{
	while(C[p].codigo<1||C[p].codigo>1000){	
		printf("\nIngrese valor entre 1 a 1000: ");
		scanf("%d",&C[p].codigo);
	}
	return C[p].codigo;
}

float validarImporte(int p,struct carga C[])
{
	while(C[p].importe<1||C[p].importe>1000){	
		printf("\nIngrese valor entre 1 a 1000: ");
		scanf("%f",&C[p].importe);
	}
	return C[p].importe;
}

int validarCantidad(int p,struct carga C[])
{
	while(C[p].cantidad<1||C[p].cantidad>1000){	
		printf("\nIngrese valor entre 1 a 1000: ");
		scanf("%d",&C[p].cantidad);
	}
	return C[p].cantidad;
}

char validarCaracteres(int p,struct carga C[])
{
	int cantidadLetras;
	
	cantidadLetras=strlen(C[p].producto);
	printf("%d",cantidadLetras);
	while(cantidadLetras>50||cantidadLetras<1){	
		printf("\nIngrese producto nuevamente: \n");
		gets(C[p].producto);
		cantidadLetras=strlen(C[p].producto);
		printf("%d",cantidadLetras);
	}
	return C[p].producto;
}

void validarCodigoExistente(int *puntero,struct carga C[],int limite)
{
int i;
int a=*puntero;
int validacion=0;
do{
for(i=0;i<limite;i++)
    {
	if(a==C[i].codigo){
		validacion=1;		
	}
    }	
if(validacion==0){
printf("\nEl codigo ingresado no existe, ingresar nuevamente: ");	
scanf("%d",&a);
}	
}while(validacion==0);
*puntero=a;
}





