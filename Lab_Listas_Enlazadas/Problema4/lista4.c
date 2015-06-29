#include <stdio.h>
#include <stdlib.h>
#include "ll.h"
void loadl(list * l1);
void impr(nod * act);
void pmir(nod * act);
void main()
{
    list * l1=blist(l1);
    int op;
    clrscr();
    loadl(l1);
    clrscr();
    printf("Imprimir lista enlazada con algoritmo recursivo: \n");
    clrscr();
    impr(l1->start);
    getch();
}

void loadl(list * l1)
{
    int i,elem;
    printf("Cargando Lista (10 elementos)\n");
    for(i=0;i<10;i++)
    {
	printf("Ingrese el elemento %i: ",i+1);
	scanf("%d",&elem);
	ins(l1,elem,0,1);
    }
}
void impr(nod * act)
{
     if( act == NULL)
	printf("\b \n");
     else
     {
	printf("%d,",act->x);
	impr(act->next);
     }
}
