typedef struct {
	int edad;
	char nombre[50];	
}Persona;

typedef struct {
	int reservedsize;
	int size;
	Persona** pElements;
}ArrayList;


