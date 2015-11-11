#include "types.h"
#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu(int opcionMenu)
{
  printf("\t\tOPCIONES ARRAY LIST\n\n(Indique numero de la opcion que desea realizar)\n\n\n1-INGRESAR\n\n2-LISTAR\n\n3-ELIMINAR\n\n4-SALIR\n\n");
  printf("\nSu opcion es: ");
  scanf("%d",&opcionMenu);
  fflush(stdin);
  printf("\n_______________________\n\n\n\n"); 
  return opcionMenu;     
}

void nuevoNumero(ArrayList* self)
{
    char resp[2]; 
    int aux;
    int* element;
     
	do{
		element= (int*) malloc(sizeof(int));
		printf("\nIndique un numero: ");
		scanf("%d",&aux);
		*element = aux;

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

void resizeUp(ArrayList* self)
{
	void* tmp_ptr;
	tmp_ptr = (void*)realloc(self->pElements,(sizeof(void*))*(self->reservedsize+3));

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



