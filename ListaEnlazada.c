
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo* siguiente; // * para apuntadores
} nodo;

nodo* primero=NULL; //Apuntadores
nodo* ultimo=NULL;


void insertarNodo();
void buscarNodo();
void desplegarNodo();
void modificarNodo();
void eliminarNodo();
void eliminarPosicion();
void insertarInicio();
void insertarLugar();
int main()
{

    int opcionSeleccionada;
    while(opcionSeleccionada!=9)
    {

    printf("\n    >>Menu<<   ");
    printf("\n 1- Insertar al final");
    printf("\n 2- Buscar ");
    printf("\n 3- Modificar");
    printf("\n 4- Eliminar");
    printf("\n 5- Desplegar");
    printf("\n 6- Eliminar posición ");
    printf("\n 7- Insertar al inicio");
    printf("\n 8- Insertar en un lugar");
   printf("\n 9- Salir \n");

    scanf("%d", &opcionSeleccionada);
    switch(opcionSeleccionada)
    {

        case 1:
            printf("\n\n Insertar un Nodo \n\n");
            insertarNodo();
            break;

        case 2:
            printf("\n\n Buscar un Nodo \n\n" );
            buscarNodo();
            break;

        case 3:
            printf("\n\n Modificar Nodo\n\n");
            modificarNodo();
            break;

        case 4:
            printf("\n\n Eliminar Nodo \n\n");
            eliminarNodo();
            break;

        case 5:
            printf("\n\n Desplegar Nodo \n\n");
            desplegarNodo();
            break;

        case 6:
             printf("\n\n Eliminar el valor de una posicion \n\n");
            eliminarPosicion();
            break;

        case 7:
             printf("\n\n Insertar al inicio \n\n");
            insertarInicio();
            break;

        case 8:
             printf("\n\n Insertar en un lugar\n");
           insertarLugar();
            break;


        case 9:
            printf("\n\n Salir \n\n");
            break;

        default:
            printf("\n\n  Opcion invalida\n\n");

        } //switch
    } // while
     return 0;

} //main

void insertarNodo()
{
    nodo* nuevo= (nodo*)malloc(sizeof(nodo)); //malloc-> apartar espacio en memoria y size of -> tamaño del nodo
    printf("Ingrese el dato para el nodo: ");
    scanf("%d", &nuevo->dato);

    if(primero==NULL)
    {
        primero= nuevo;
        primero -> siguiente=NULL;
        ultimo=nuevo;

    }
    else
    {
        ultimo ->siguiente=nuevo;
        nuevo -> siguiente= NULL;
        ultimo=nuevo;

    }
} //insertarNodo

void buscarNodo()
{
  int nodoBuscado=0, encontrado=0;
   nodo* actual= (nodo*)malloc(sizeof(nodo));
   actual= primero;
   printf("Ingrese el valor del nodo que desea buscar");
   scanf("%d",&nodoBuscado);

   if(primero!= NULL)
   {
       while(actual!= NULL && encontrado!=1)
       {
           if(actual->dato==nodoBuscado)
           {
               printf("\nEl dato buscado (%d) si se encuentra en la estructura/n", nodoBuscado);
               encontrado=1;
           }
           actual=actual->siguiente;
       }
       if(encontrado==0)
       {
           printf("\n\n El dato buscado no se encuentra en la estructura\n");
       }
   }
   else
   {
       printf("\n\n Esta estructura esta vacia\n");

   }


} //buscarNodo

void desplegarNodo()
{

  nodo*actual=(nodo*)malloc(sizeof(nodo));
  actual=primero;
  if(primero !=NULL)
  {

      while(actual!=NULL)
      {
          printf("\n %d", actual->dato);
          actual= actual->siguiente;
      }
  }
  else
  {
      printf("\n Esta estructura esta vacia\n");

  }
} //desplegarNodo

void modificarNodo()
{

  int nodoBuscado=0, encontrado=0, sustituto=0;
   nodo* actual= (nodo*)malloc(sizeof(nodo));
   actual= primero;
   printf("Ingrese el valor del nodo que desea modificar\n");
   scanf("%d",&nodoBuscado);

   if(primero!= NULL)
   {
       while(actual!= NULL && encontrado!=1)
       {
           if(actual->dato==nodoBuscado)
           {
               printf("\n ¿Cual es el numero con el que deseas cambiar este dato?\n");
               scanf("%d", &sustituto);
               actual ->dato=sustituto;//cambio o modificacion
               encontrado=1;

           }
           actual=actual->siguiente;
       }
       if(encontrado==0)
       {
           printf("\n\n El dato buscado no se encuentra en la estructura\n");
       }
   }
   else
   {
       printf("\n\n Esta estructura esta vacia\n");

   }


}//modificarN


void eliminarNodo()
{

  int nodoBuscado=0, encontrado=0;
   nodo* actual= (nodo*)malloc(sizeof(nodo));
   actual= primero;
    nodo* anterior= (nodo*)malloc(sizeof(nodo));
   // anterior=primero;

   printf("Ingrese el valor del nodo que desea eliminar\n");
   scanf("%d",&nodoBuscado);

   if(primero!= NULL)
   {
       while(actual!= NULL && encontrado!=1)
       {

           if(actual->dato==nodoBuscado) //actual apuna el nodo que queremos borrar
           {

               if(actual==primero)
               {
                   primero=primero->siguiente;
                   //actual->siguiente=NULL;
                  // free(actual);
               }


               else if(actual==ultimo)
               {
                  ultimo=anterior;
                  anterior->siguiente=NULL;
                  //free(actual);
               }

               else   //para cuando hay un valor antes y uno despues
               {

               anterior->siguiente=actual->siguiente;
              // actual->siguiente=NULL;
               //free(actual);
               }

               encontrado=1;
           }
            //Actualizar apuntadores
            //Anterior =0 de preferencia
           anterior=actual;
           actual=actual->siguiente;

           //No nos salio jsjsjsj borra de a dos
          /* if(cont<3)
           {
           actual=actual->siguiente;
           cont=cont+1;

           }
           else
           {
                anterior= anterior ->siguiente;
                actual=actual->siguiente;
                cont=cont+1;
           }
*/


       }
       if(encontrado==0)
       {
           printf("\n\n El dato buscado no se encuentra en la estructura\n");
       }
   }
   else
   {
       printf("\n\n Esta estructura esta vacia\n");

   }


} //eliminarNodo


void eliminarPosicion()
{
    int posicion_nodo=1, posicion_usr=0, encontrado=0; //encontrado es la banderita
    nodo* actual= (nodo*)malloc(sizeof(nodo));
    actual= primero;
    nodo* anterior= (nodo*)malloc(sizeof(nodo));

   printf("\n Ingrese la posicion que desea eliminar");
   scanf("%d", &posicion_usr);

    if(primero!= NULL)
   {
       while(actual!= NULL && encontrado!=1)
       {
           // preguntar
           if(posicion_nodo==posicion_usr)
           {
               if(actual==primero)
               {
                   primero=primero->siguiente;
               }
               else if(actual==ultimo)
               {
                   ultimo=anterior;
                   anterior->siguiente=NULL;
               }
               else   //para cuando hay un valor antes y uno despues
               {
                    anterior->siguiente=actual->siguiente;
               }
           encontrado=1;
           }
           anterior=actual;
           actual=actual->siguiente;
           posicion_nodo=posicion_nodo+1;
       }
    }
}

void insertarInicio()
{
    nodo* nuevo= (nodo*)malloc(sizeof(nodo)); //malloc-> apartar espacio en memoria y size of -> tamaño del nodo
    printf("Ingrese el dato para el nodo: ");
    scanf("%d", &nuevo->dato);

    nuevo ->siguiente= primero;
    primero=nuevo;

}

void insertarLugar()
{
    int cont=0, lugar, total;
    nodo* actual= (nodo*)malloc(sizeof(nodo));
   actual= primero;
   nodo* nuevo= (nodo*)malloc(sizeof(nodo));

    if(primero!= NULL)
    {
        while(actual!= NULL )
        {
           cont=cont+1;
           actual=actual->siguiente;
        }
   }

    total=cont;
    cont=0;
    actual=primero;

   printf("\n El total de nodos es %d",total); //ACUERDATE DE  %d
   printf("\n ¿En qué posición desea insertar el nuevo nodo?\n");
   scanf("%d",&lugar);


   if(lugar<=total)
   {
       printf("\n El lugar es valido\n");

       printf("\n Inserta el valor que desea agregar:\n");
       scanf("%d", &nuevo->dato);

        while(actual!= NULL && cont<lugar)
        {
           cont=cont+1;

           if(lugar==1)
           {
               nuevo ->siguiente= primero;
               primero=nuevo;

           }

           else if( lugar==total)
           {
              ultimo ->siguiente=nuevo;
              nuevo -> siguiente= NULL;
              ultimo=nuevo;
           }

           else if(lugar==cont)
           {

           //insertsr en el medio
           nuevo->siguiente=actual->siguiente;
           actual->siguiente=nuevo;
           }
           actual=actual->siguiente;

        }



   }

   else
   {
       printf("\n El lugar no es valido \n");
   }


}//insertarLugar
