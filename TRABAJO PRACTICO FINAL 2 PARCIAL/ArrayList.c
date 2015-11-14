#include "types.h"
#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu(int opcionMenu)
{
  printf("\t\tOPCIONES ARRAY LIST\n\n(Indique numero de la opcion que desea realizar)\n\n\n1-INGRESAR\n\n2-LISTAR\n\n3-ELIMINAR POR INDICE\n\n4-BORRAR ARRAYLIST\n\n5-INGRESAR DATO EN INDICE ESPECIFICO\n\n6-SALIR\n\n");
  printf("\nSu opcion es: ");
  scanf("%d",&opcionMenu);
  fflush(stdin);
  printf("\n_______________________\n\n\n\n"); 
  return opcionMenu;     
}

void nuevaPersona(ArrayList* self)
{
    char resp[2]; 
    Persona P;
    Persona* element;
 
	do{
		element= (Persona*) malloc(sizeof(Persona));
		printf("\nIndique edad: ");
		scanf("%d",&P.edad);
		printf("\nIndique nombre: ");
		scanf("%s",&P.nombre);
		*element = P;

		add(self,element);

		printf("\nQuieres agregar otro numero? (s/n):  ");
		scanf("%s",resp);
	}
	while(strcmp(resp,"s")==0);		
}

void add(ArrayList* self,void* element)
{
	
	if(self->size==self->reservedsize)
	{
		resizeUp(self);
	}	
	self->pElements[self->size] = element;
	self->size++;
	printf("\nEl numero ha sido agregado espacio ocupado %d espacio restante %d \n",self->size,self->reservedsize);
	
}

ArrayList* newArrayList()
{// Constructor
	ArrayList* pAux_self;
	pAux_self = (ArrayList*) malloc(sizeof(ArrayList));
	pAux_self->pElements =(void*)malloc(sizeof(void*)*3);
	pAux_self->reservedsize=3;
	pAux_self->size=0;

	return pAux_self;
}	

void* get(ArrayList* self,int index)
{
	return self->pElements[index];
}

int resizeUp(ArrayList* self)
{
	void* tmp_ptr;
	tmp_ptr = realloc(self->pElements,sizeof(void*)*(self->reservedsize+3));

	if (tmp_ptr == NULL) {
		/* Error: tomar medidas necesarias */
		return 0;
	}
	else {
		/* Reasignación exitosa. Asignar memoria a ptr */
		self->pElements = tmp_ptr;
		self->reservedsize+=3;
		return 1;
	}
}

void remover(ArrayList* self,int aux){
	self->pElements[aux]=-1;
	int i;
	for(i=aux ; i < self->size-1 ; i++){//Ir hasta size no tiene sentido porque no tiene proximo entonces me voy a 1 anterior asi
		self->pElements[i]=self->pElements[i+1];//Copio lo del siguiente en el anterior para compactar
	}
	self->size--;	
}

void borrarArrayList(ArrayList* self)
{
		free(self);
	
		self = newArrayList();		
}

int al_isEmpty(ArrayList* self ){
	
	int i;
    for(i=0;i<self->size;i++)
    {
     if(self->pElements[i]!=NULL)
    {
    return 0;                                                                                                                                                                   
    }                          
    }   
    return 1;	
}

void set(ArrayList* self, int index, void*element)
{
	
	self->pElements[index] = element;
	
}
void ingresoPorIndice(ArrayList* self){
	int aux;
	int c;
	Persona P;
    Persona* element;
	printf("\nIndices disponibles para ingresar dato: \n\n");
	
	for(c=0;c<self->size;c++){
		printf("Indice %d\n",c);
	}
	
	
	printf("\nIngrese el indice donde desea ingresar el dato:");
	scanf("%d",&aux);

		element= (Persona*) malloc(sizeof(Persona));
		printf("\nIndique edad: ");
		scanf("%d",&P.edad);
		printf("\nIndique nombre: ");
		scanf("%s",&P.nombre);
		*element = P;
	
	set(self,aux,element);
	
	printf("_______________________\n\n");
	
}


