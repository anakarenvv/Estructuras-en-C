#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
	int dato;
	struct nodo* siguiente;
}nodo;

nodo* primero = NULL;	//Apuntador
nodo* ultimo = NULL;	//Apuntador

void insertarNodo();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void desplegarCola();

int main()
{
	int opcionSeleccionada;
	while(opcionSeleccionada !=6)
	{
		printf("\n|------------------------------|");
		printf("\n|      Estructura de cola      |");
		printf("\n|------------------------------|");
		printf("\n|1.- Insertar  |4.- Eliminar   |");
		printf("\n|2.- Buscar    |5.- Desplegar  |");
		printf("\n|3.- Modificar |6.- Salir      |");
		printf("\n|                              |");
		printf("\n| ^Escoga una opcion del menu^ |");
		printf("\n|                              |");
		printf("\n|------------------------------|\n\t");
		scanf("%d", &opcionSeleccionada);
		switch(opcionSeleccionada)
			{
			case 1:
				printf("\n\n Insertar un Nodo. \n\n");
				insertarNodo();
				break;
			case 2:
				printf("\n\n Buscar un Nodo. \n\n");
				buscarNodo();
				break;
			case 3:
				printf("\n\n Modificar un Nodo \n\n");
				modificarNodo();
				break;
			case 4:
				printf("\n\n Eliminar un Nodo \n\n");
				eliminarNodo();
				break;
			case 5:
				printf("\n\n Desplegar la Estructura \n\n");
				desplegarCola();
				break;
			case 6:
				printf("\n\n Salir \n\n");
				break;
			default:
				printf("\n\n Opcion invalida. \n\n");
			}
	}		

	return 0;
}



void insertarNodo()
{
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));
	printf("Ingrese el dato para el nodo: ");
	scanf("%d", &nuevo->dato);

	if(primero == NULL)
	{
		primero = nuevo;
		primero -> siguiente = NULL;
		ultimo = nuevo;
	}
	else
	{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}
	//printf("Nodo Ingresado correctamente.\n");
}

void buscarNodo()
{
	int nodoBuscado = 0, encontrado = 0;
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	printf("Ingrese el valor del nodo que decea buscar: ");
	scanf("%d", &nodoBuscado);
	if(primero != NULL)
	{
		while(actual != NULL && encontrado != 1)
		{
			if(actual->dato == nodoBuscado)
			{
				printf("\nEl nodo con el dato buscado (%d) si se encuentra en la estructura.\n", nodoBuscado);
				encontrado = 1;
			}
			actual = actual->siguiente;
		}
		if(encontrado==0)
		{
			printf("\n\nNodo no encontrado dentro de la estructura\n\n");
		}
	}
	else
	{
		printf("La cola esta vacia / no existe.");
	}
}

void modificarNodo()
{
	int nodoBuscado = 0, encontrado = 0;
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	printf("Ingrese el valor del nodo que decea modificar: ");
	scanf("%d", &nodoBuscado);
	if(primero != NULL)
	{
		while(actual != NULL && encontrado != 1)
		{
			if(actual->dato == nodoBuscado)
			{
				printf("\nEl nodo con el dato buscado (%d) si se encuentra en la estructura.", nodoBuscado);
				printf("\nIngrese el dato deceado para este nodo: ");
				scanf("%d", &actual->dato);
				printf("\n El nodo se modifico. \n");
				encontrado = 1;
			}
			actual = actual->siguiente;
		}
		if(encontrado==0)
		{
			printf("\n\nNodo no encontrado dentro de la estructura\n\n");
		}
	}
	else
	{
		printf("La cola esta vacia / no existe.");
	}
}

void eliminarNodo()
{
	int nodoBuscado = 0, encontrado = 0;
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	nodo* anterior = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	anterior = NULL;
	printf("Ingrese el valor del nodo que decea eliminar: ");
	scanf("%d", &nodoBuscado);
	if(primero != NULL)
	{
		while(actual != NULL && encontrado != 1)
		{
			if(actual->dato == nodoBuscado)
			{
				if(actual == primero)	//si hay que borrar el primer dato
				{
					primero = primero->siguiente;
				}
				else if (actual == ultimo)	//si hay que borrar el ultimo dato
				{
					anterior->siguiente = NULL;
					ultimo = anterior;
				}
				else	//si hay que borrar un dato del centro
				{
					anterior->siguiente = actual->siguiente;	//El apuntador hacia el dato que queremos eliminar se "salta" el dato a eliminar y apunta al que sigue.
				}
				encontrado = 1;
			}
			anterior = actual;
			actual = actual->siguiente;
		}
		if(encontrado==0)
		{
			printf("\n\nNodo no encontrado dentro de la estructura\n\n");
		}
		else
		{
			free(anterior);
		}
		printf("\nSe ha borrado el nodo.\n");
	}
	else
	{
		printf("La cola esta vacia / no existe.");
	}
}

void desplegarCola()
{
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	if(primero != NULL)
	{
		while(actual != NULL)
		{
			printf("\n%d", actual->dato);
			actual = actual->siguiente;
		}
	}
	else
	{
		printf("\nLa cola esta vacia / no existe.\n");
	}
}