#include <stdio.h>
#include <stdlib.h>
#include "l2l.h"
void e2r(l2ist * l1, int op);
void l2oadl(l2ist * l1);
void main()
{
    l2ist * l1=b2list(l1);
    int op=0;
    l2oadl(l1);
    //printf("Eliminacion de elementos de forma recursiva\n");
    e2r(l1,op);
}
void l2oadl(l2ist * l1)
{
    int i,elem;
    printf("Cargando Lista (10 elementos)\n");
    for(i=0;i<10;i++)
    {
        printf("Ingrese el elemento %i: ",i+1);
        scanf("%d",&elem);
        //elem=i+1;
        i2ns(l1,elem,0,1);
    }
}

void e2r(l2ist * l1, int op)
{
    int elem,elem2,cont,est;
    n2od * act=l1->start;
    if(op==1)
    {
	printf("");
    }
    else if( l1->size==1 )
    {
    	printf("Lista: \n");
    	i2mp(l1);
	printf("No se puede eliminar más.\n");
	op=1;
	e2r(l1,op);
    }
    else
    {
    	printf("Lista: \n");
    	i2mp(l1);
	if(l1->size!=10)
        {
	    printf("¿Salir? 1/0: ");
            scanf("%d",&op);
	    if(op==1)
	    	cont=99;
	}
	if(cont != 99)
	{
	    do
	    {
	    	printf("Ingrese el elemento de referencia: ");
	    	scanf("%d",&elem2);
		while(act != NULL)
		{
		    if(act->x == elem2)
		    {
			est=0;
			break;
		    }
		    else
			est=1;
		    act=act->next;
		}
		if(est)
		{
		    clrscr();
		    printf("El elemento no está\n");
		    getch();
		}
    		printf("Lista: \n");
    		i2mp(l1);
		act=l1->start;
	    } while(est);
            e2lim(l1,elem2,4);
	}
        e2r(l1,op);
	
    }
}
