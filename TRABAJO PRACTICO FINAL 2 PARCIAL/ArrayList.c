#include "types.h"
#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu(int opcionMenu)
{
  printf("\t\t\tOPCIONES ARRAY LIST\n\n\t(Indique numero de la opcion que desea realizar)\n\n\n \20 1-INGRESAR\t\t\t\t\t \20 2-LISTAR\n\n \20 3-ELIMINAR POR INDICE\t\t\t \20 4-BORRAR ARRAYLIST\n\n \20 5-INGRESAR DATO EN INDICE ESPECIFICO\t\t \20 6-INDEX OF\n\n \20 7-TAMA\245O ARRAY LIST\t\t\t\t \20 8-PUSH\n\n \20 9-ELIMINACION POP\t\t\t\t \20 10-EXISTE ELEMENTO\n\n\n\n \20 11-SALIR\n\n");
  printf("\n Su opcion es: ");
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

int al_len(ArrayList* self ){//Retorna el tamaño del ArrayList.
	int tamanio;
	tamanio=self->size;
	return tamanio;
}

void borrarEspacioReservadoNoNecesario(ArrayList* self)
{
	if((self->reservedsize-(self->size-1)) >3)
	{
	self->reservedsize=self->reservedsize-3;
	}
}

void remover(ArrayList* self,int aux){
	self->pElements[aux]=-1;
	int i;
	borrarEspacioReservadoNoNecesario(self);
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
	int contador=0;
	char resp[2]; 
	Persona P;
    Persona* element;
	
	do{
	printf("\nIndices disponibles para ingresar dato: \n\n");
	for(c=0;c<self->size;c++){
		printf("Indice %d\n",c);
		contador=contador+1;
	}
	printf("\nCantidad de indices actuales: %d\n",contador);
	
	printf("\nIngrese el indice donde desea ingresar el dato:");
	scanf("%d",&aux);	
		for(c=0;c<self->size;c++)
		{
		if(aux==c){

		element= (Persona*) malloc(sizeof(Persona));
		printf("\nIndique edad: ");
		scanf("%d",&P.edad);
		printf("\nIndique nombre: ");
		scanf("%s",&P.nombre);
		*element = P;
	
		set(self,aux,element);
		printf("_______________________\n\n");
		
		}
	    }
		if(aux>contador-1){
		printf("\nEl indice indicado no existe!!\n");	
	    }
	    contador=0;
		printf("\nQuieres ingresar otro numero? (s/n):  ");
		scanf("%s",resp);
		system("cls");
	}
	while(strcmp(resp,"s")==0);			
}

void eliminarPorIndice(ArrayList* self){
	int c;
	char resp[2];
	int aux;
	
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
	    
	    printf("\nEl numero ha sido agregado espacio ocupado %d espacio restante %d \n",self->size,self->reservedsize);	
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
}

void listarDatos(ArrayList* self){
	int c;
		
	if(al_isEmpty(self)==1){
    	printf("\nNo existen datos para mostrar!!\n\n");
    }
    else{ 
    	for(c=0;c<self->size;c++){
		printf("\nValor %d Indice %d\n",self->pElements[c]->edad,c);
		printf("Valor %s Indice %d\n",self->pElements[c]->nombre,c);	
	    }
	}	
}

void borrarTotalArrayList(ArrayList* self){
	char resp[2];
	
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
    printf("______________________________________________________________\n\n");
    if(strcmp(resp,"s")==0){
	printf("Se borraron los datos con exito!!\n\n\n");
    }
    }
}

void ingresoIndice(ArrayList* self){

		if(al_isEmpty(self)==1){
    	printf("\nNo se ingresaron datos aun!!\n\n\nElija la opcion 1 del menu principal\n\n\n");
        }
    	else{ 
    	ingresoPorIndice(self);
	    }
}

int indexOfEntero(ArrayList* self,Persona* element){
	int c=0;
					
					for(c=0;c<self->size;c++){
					if(element->edad==self->pElements[c]->edad){	
					return c;				
					}
				    }
					if(self->size==c)
		            return -1;
					
}
int indexOfChar(ArrayList* self,Persona* element){
	int c=0;
					for(c=0;c<self->size;c++){
					if(*(element->nombre)==*(self->pElements[c]->nombre)){				
					return c;	
				    }
					}
					if(self->size==c)
		            return -1;
}

void mostrarIndicePrimero(ArrayList* self){
	
	Persona auxP;
	Persona* element;
	char respue[2];
	int opcion;
	int valor;
	
		if(al_isEmpty(self)==1){
    	printf("\nNo se ingresaron datos aun!!\n\n\nElija la opcion 1 del menu principal\n\n\n");
        }
    	else{ 
    	
		do{
        opcion=0;
	
		printf("De que elemento desea realizar busqueda?\n\n\n1-Nombre\n\n2-Edad\n\n\nIngrese la opcion deseada: ");
		scanf("%d",&opcion);
		fflush(stdin);
		
		if(opcion==1||opcion==2)
		{
			element= (Persona*) malloc(sizeof(Persona));
				if(opcion==1)
					{
					printf("\n\nIndique nombre: ");
					scanf("%s",&auxP.nombre);
					*element = auxP;
					valor=indexOfChar(self,element);
					if(valor>=0){
					printf("\n\nEl dato buscado se encuentra en el indice: %d\n\n",valor);	
					}
					if(valor==-1){
					printf("\n\nEl dato buscado no existe!!\n\n");	
					}					
     				}
				if(opcion==2)
					{
					printf("\n\nIndique edad: ");
					scanf("%d",&auxP.edad);				
					*element = auxP;
					valor=indexOfEntero(self,element);
					if(valor>=0){
					printf("\n\nEl dato buscado se encuentra en el indice: %d\n\n",valor);	
					}
					if(valor==-1){
					printf("\n\nEl dato buscado no existe!!\n\n");	
					}
					}	
		
		}else{
			printf("\n\nLas opciones a elejir son solo 1 o 2!!\n\n");
		}

		printf("\nQuieres buscar otro ? (s/n):  ");
		scanf("%s",&respue); 
		system("cls"); 
		}while(strcmp(respue,"n"));  	

	    }			
}

void tamanioArrayList(ArrayList* self)
{
	if(al_isEmpty(self)==1){
    printf("\nNo se ingresaron datos aun!!\n\n\nEl valor actual es 0\n\n\n");
    }
    else{ 
	int valor;
	valor=al_len(self);
	printf("\n\nEl tama\244o del Array List es de: %d \n\n",valor);
	}	
}

void masEspacioEnArrayList(ArrayList* self,int index){
	
	 int i;
     
     if(self->size==self->reservedsize)
     {
     resizeUp(self);                                   
     }     
     
     for(i=self->size-1;i>=index;i--)
     {
     self->pElements[i+1]=self->pElements[i];                                 
     }

     self->pElements[index]=NULL;
}

void push(ArrayList* self, int index, void*element){
	 
	 masEspacioEnArrayList(self,index);
     
     self->pElements[index]=element;
     self->size++;	
}

void al_push(ArrayList* self){
	int aux;
	int c;
	int contador=0;
	char resp[2]; 
	Persona P;
    Persona* element;
	
	do{
	printf("\nIndices disponibles para ingresar dato: \n\n");
	for(c=0;c<self->size;c++){
		printf("Indice %d\n",c);
		contador=contador+1;
	}
	printf("\nCantidad de indices actuales: %d\n",contador);
	
	printf("\nIngrese el indice donde desea ingresar el dato:");
	scanf("%d",&aux);	
		for(c=0;c<self->size;c++)
		{
		if(aux==c){

		element= (Persona*) malloc(sizeof(Persona));
		printf("\nIndique edad: ");
		scanf("%d",&P.edad);
		printf("\nIndique nombre: ");
		scanf("%s",&P.nombre);
		*element = P;
	
		push(self,aux,element);
		printf("_______________________\n\n");
		
		}
	    }
		if(aux>contador-1){
		printf("\nEl indice indicado no existe!!\n");	
	    }
	    contador=0;
		printf("\nQuieres ingresar otro numero? (s/n):  ");
		scanf("%s",resp);
		system("cls");
	}
	while(strcmp(resp,"s")==0);			
}

void* al_pop(ArrayList* self,int index)
{
	Persona* element;

	element = self->pElements[index];
	remover(self, index); 
	return element;
}

void eliminarPop(ArrayList* self){
	int c;
	char resp[2];
	int aux;
	Persona* element; 
	
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
		element=al_pop(self,aux);
        system("cls"); 
        printf("\nIndice borrado %d con dato %d\n",aux,element->edad);
        printf("\nIndice borrado %d con dato %s\n\n\n",aux,element->nombre);
		
		printf("\n\nIndices disponibles\n");
        printf("_______________________\n");
		for(c=0;c<self->size;c++){
		printf("\nValor %d Indice %d\n",self->pElements[c]->edad,c);
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
}

int al_containsEnteros(ArrayList* self,Persona* element){//Comprueba si existe del elemento que se le pasa como parámetro y devuelve 0 o 1.
	int c=0;
					
					for(c=0;c<self->size;c++){
					if(element->edad==self->pElements[c]->edad){	
					return 0;				
					}
				    }
					if(self->size==c)
		            return 1;
}

int al_containsChar(ArrayList* self,Persona* element){//Comprueba si existe del elemento que se le pasa como parámetro y devuelve 0 o 1.
	int c=0;
					
					for(c=0;c<self->size;c++){
					if(*(element->nombre)==*(self->pElements[c]->nombre)){	
					return 0;				
					}
				    }
					if(self->size==c)
		            return 1;
}

void existeElemento(ArrayList* self){	
	Persona auxP;
	Persona* element;
	char respue[2];
	int opcion;
	int valor;
	
		if(al_isEmpty(self)==1){
    	printf("\nNo se ingresaron datos aun!!\n\n\nElija la opcion 1 del menu principal\n\n\n");
        }
    	else{ 
    	
		do{
        opcion=0;
	
		printf("De que elemento desea realizar busqueda?\n\n\n1-Nombre\n\n2-Edad\n\n\nIngrese la opcion deseada: ");
		scanf("%d",&opcion);
		fflush(stdin);
		
		if(opcion==1||opcion==2)
		{
			element= (Persona*) malloc(sizeof(Persona));
				if(opcion==1)
					{
					printf("\n\nIndique nombre: ");
					scanf("%s",&auxP.nombre);
					*element = auxP;
					valor=al_containsChar(self,element);
					if(valor==0){
					printf("\n\nEl dato buscado existe en el el Array List\n\n");	
					}
					if(valor==1){
					printf("\n\nEl dato buscado no existe!!\n\n");	
					}					
     				}
				if(opcion==2)
					{
					printf("\n\nIndique edad: ");
					scanf("%d",&auxP.edad);				
					*element = auxP;
					valor=al_containsEnteros(self,element);
					if(valor==0){
					printf("\n\nEl dato buscado existe en el el Array List\n\n");	
					}
					if(valor==1){
					printf("\n\nEl dato buscado no existe!!\n\n");	
					}
					}	
		
		}else{
			printf("\n\nLas opciones a elejir son solo 1 o 2!!\n\n");
		}

		printf("\nQuieres buscar otro ? (s/n):  ");
		scanf("%s",&respue); 
		system("cls"); 
		}while(strcmp(respue,"n"));  	

	    }	
		
}	
	
	


