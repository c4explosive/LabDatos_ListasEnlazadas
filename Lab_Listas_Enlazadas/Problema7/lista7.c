#include <stdio.h>
#include <stdlib.h>
#include "l2l.h"
void i2r(l2ist * l1, int op);
void main()
{
    l2ist * l1=b2list(l1);
    int op=0;
    printf("Inserccion de elementos de forma recursiva\n");
    i2r(l1,op);
}
void i2r(l2ist * l1, int op)
{
    int elem,elem2,cont,est;
    n2od * act=l1->start;
    if(op==1)
    {
	printf("");
    }
    else if( l1->size==0 )
    {
	printf("Ingrese un elemento: ");
        scanf("%d",&elem);
        i2ns(l1,elem,0,1);
	i2r(l1,op);
    }
    else
    {
    	printf("Lista: \n");
    	i2mp(l1);
	if(l1->size!=1)
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
	    printf("Ingrese un elemento: ");
            scanf("%d",&elem);
            i2ns(l1,elem,elem2,3);
	}
        i2r(l1,op);
	
    }
}
