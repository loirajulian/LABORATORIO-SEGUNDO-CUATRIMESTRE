int menu(int opcionMenu);

ArrayList* newArrayList();
void* get(ArrayList* self,int index);
int resizeUp(ArrayList* self);
void add(ArrayList* self,void* element);
void nuevaPersona(ArrayList* self);
int al_len(ArrayList* self );
int al_isEmpty(ArrayList* b );
void borrarEspacioReservadoNoNecesario(ArrayList* self);
void remover(ArrayList* self,int aux);
void borrarArrayList(ArrayList* self);
void set(ArrayList* self, int index, void*element);
void ingresoPorIndice(ArrayList* self);
void eliminarPorIndice(ArrayList* self);
void listarDatos(ArrayList* self);
void borrarTotalArrayList(ArrayList* self);
void ingresoIndice(ArrayList* self);
int indexOfEntero(ArrayList* self,Persona* element);
int indexOfChar(ArrayList* self,Persona* element);
void mostrarIndicePrimero(ArrayList* self);
void tamanioArrayList(ArrayList* self);
void masEspacioEnArrayList(ArrayList* self,int index);
void push(ArrayList* self, int index, void*element);
void al_push(ArrayList* self);
void* al_pop(ArrayList* self,int index);
void eliminarPop(ArrayList* self);
int al_containsEnteros(ArrayList* self,Persona* element);
int al_containsChar(ArrayList* self,Persona* element);
void existeElemento(ArrayList* self);

void hacerClondeArrayList(ArrayList* self);







