#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

void main()
{
    int numeros[]={1,3,5,8};
    list * l1=blist(l1);
    nod * act;
    int i,num,cont=0,dep=0;
    for(i=0;i<4;i++)
	ins(l1,numeros[i],0,1);
    act=l1->start;
    imp(l1);		
    do
    {
	printf("Ingrese un número: ");
	scanf("%d",&num);
	while(act != NULL)
	{
	    if(act->next != NULL)
	    {
		if (l1->start->x > num)
		{
		    ins(l1,num,0,2);
		    dep=0;
		    break;
		}
		else if( act->x == num)
		{
		    printf("Elemento repetido.\n");
		    dep=0;
		    break;
		}
	    	else if(act->next->x > num)
		{
		    ins(l1,num,act->x,3);
		    dep=0;
		    break;
		}
		else
		    dep=1;
	    }
	    act=act->next;
	}
	if(dep)
	    ins(l1,num,0,1);		
    	imp(l1);		
	printf("¿Continuar? 1/0: ");
	scanf("%d",&cont);
	dep=0;
	act=l1->start;
    } while(cont);
}
