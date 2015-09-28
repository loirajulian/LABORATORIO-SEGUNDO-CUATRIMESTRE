int menu(int opcionMenu);
int validarCodigo(int p,struct carga C[]);
float validarImporte(int p,struct carga C[]);
int validarCantidad(int p,struct carga C[]);
char validarCaracteres(int p,struct carga C[]);
void altaProducto(int p,struct carga[]);

int menuInformar(int opcionMenuInformar);
int menuListar(int opcionListar);
void mayorImporte(struct carga C[]);
void sumaImportes(struct carga C[]);
void promedioImportes(struct carga C[]);
void validarCodigoExistente(int *puntero,struct carga C[],int limite);

void listarCantidadAscendente(int limite,int p,struct carga C[],struct carga auxC);
void listarDescripcionDescendente(int limite,int p,struct carga C[],struct carga auxC);
