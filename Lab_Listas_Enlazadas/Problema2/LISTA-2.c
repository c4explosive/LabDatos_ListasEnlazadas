#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
//Lista simplemente enlazada que ordene numeros enteros
#define getch() system("read ")
#define clrscr() system("clear") 
typedef struct elementolista
{
  int dato;
  struct elementolista *siguiente;
} elemento;

typedef struct listaidentificar
{
 elemento *inicio;
 elemento *final;
 int tam;
}lista;

 void inicializacion(lista *lista)
 {
  
  lista->inicio= NULL;
  lista->final= NULL;
  lista->tam=0;
 }

 int insercion(lista *lista, int *dato) //insercion en lista vacia
 {
  elemento *nuevo_elemento;
  nuevo_elemento=(elemento *)malloc(sizeof (elemento));
  if((nuevo_elemento=(elemento *) malloc(sizeof(elemento)))==NULL)
  return -1;
  if((nuevo_elemento->dato=(int *) malloc(50*sizeof(int)))==NULL)
  return -1;

  nuevo_elemento->dato=dato;
  nuevo_elemento->siguiente=NULL;

  if(lista->inicio==NULL)
  {
  lista->inicio=nuevo_elemento;
  lista->final=nuevo_elemento;
  lista->tam++;
  }
  else
  {
   lista->final->siguiente=nuevo_elemento;
   lista->final=nuevo_elemento;
  }

  return 0;
 }

 void ordenar(lista *lista) //ordena de menor a mayor
  {
   elemento *actual,*seguir;
   seguir=malloc(sizeof(int));
   actual=malloc(sizeof(int));
   int i;
   actual=lista->inicio;
  while(actual!=NULL)
   {
    seguir=actual->siguiente;
	while(seguir!=NULL)
	{
	    if(actual->dato > seguir->dato)
	     {
	      i=seguir->dato;
	      seguir->dato=actual->dato;
	      actual->dato=i;
	     }
	     seguir=seguir->siguiente;
	}
       actual=actual->siguiente;
       //seguir=actual->siguiente;
    }

  }


 int eliminar(lista *lista)//eliminar al inicio de la lista
 {
   elemento *elim_elemento;

  if(lista->tam==0)
  return -1;

  elim_elemento=lista->inicio;
  lista->inicio=lista->inicio->siguiente;
  if(lista->tam==1)
  lista->final=NULL;

  free(elim_elemento->dato);
  free(elim_elemento);
  lista->tam--;
  return 0;
}


void visualizar(lista *lista)//visualizar la lista
{
 elemento *actual;
 actual=lista->inicio;
 while(actual!=NULL)
 {
  printf("%p - %d",actual, actual->dato);
  actual=actual->siguiente;
  printf("\n");
  }
}



 int main(void)
 {
     int *m,i;
     lista *lista1=malloc(sizeof(lista));


     elemento *actual;

     clrscr();
     actual=NULL;
     inicializacion(lista1);

    for(i=0;i<10;i++)
    {
    printf("Introduzca un numero ");
    scanf("%d",&m);
    insercion(lista1,m);
    }
    ordenar(lista1);
    visualizar(lista1);

   getch();
   return 0;
 }
