#include <stdio.h>
#include <stdlib.h>
typedef struct ncode
{
    int x;
    struct ncode * next;   
} ncod;

typedef struct lcistid
{
    ncod * start;
    ncod * end;
    int size;
} lcist;

lcist * bclist(lcist * lista) //Inicialización de lista
{
    lista = malloc(sizeof(lista));
    lista->start=malloc(sizeof(ncod));
    lista->end=malloc(sizeof(ncod));
    lista->start=NULL;
    lista->end=NULL;
    lista->size=0;
}

ncod * bcnode(ncod * nodo) //Inicialización de nodo
{
    nodo = malloc(sizeof(ncod));
    nodo->x=0;
    nodo->next=malloc(sizeof(ncod));
    nodo->next=NULL;
    return nodo;
}

void icns(lcist * lst, int num, int dat,int mod) //Insertar elementos en lista..
{
    ncod * neww=bcnode(neww);
    ncod * act=lst->start;
    ncod * obj;
    if(lst->size== 0)
    {
    	lst->start=neww;
    	neww->x=num;
    	neww->next=lst->start;
    	lst->end=neww;
    	lst->size++;
    }
    else
    {
	switch( mod )
	{
 	    case 1:
 	    //Insertar elementos después
    	    	lst->end->next=neww;
    	    	neww->x=num;
    	    	neww->next=lst->start;
    	    	lst->end=neww;
    	    	lst->size++;
	    	break;
    	    case 2:
		//Insertar elementos antes
    		neww->next=lst->start;
    		lst->start=neww;
		lst->end->next=lst->start;
    		neww->x=num;
    		lst->size++;
		break;
	    case 3:
		//Insertar despues de un nodo
		do
    		{
		    if(act->x == dat)
		    {
			if(act == lst->end)
			{	
			    lst->end=neww;
			    neww->x=num;
			    neww->next=lst->start;
			    act->next=neww;
			    lst->size++;
			}
			else
			{
		 	    obj=act;	
			    neww->x=num;
			    neww->next=obj->next;
			    obj->next=neww;
			    lst->size++;
			    break;
			}
    		    }
		    act=act->next;
    		}while( act != lst->start);
	    }
	}
}

void eclim(lcist * lst, int dat,int mod) //Eliminar elementos en lista..
{
    //nod * new=bnode(new);
    ncod * act=lst->start;
    ncod * obj;
    ncod * ant;
    if(lst->size== 1)
    {
    	lst->start=NULL;
    	lst->size--;
    }
    else if(lst->size > 1)
    {
	switch( mod )
	{
    	    case 1:
		//Eliminar elementos antes
    		lst->start=lst->start->next;
		lst->end->next=lst->start;
    		lst->size--;
		break;
	}
    }
    
}


void icmp(lcist * l1)
{
    ncod * act=l1->start;
    if(l1->size==0)
   	printf("La lista está vacía\n");
    else
    {
    	do
    	{
	    printf("%d,",act->x);
	    //printf("%p->%p   ",act,act->next);
	    act=act->next;
    	}while(act != l1->start);
        //}while(1);
        printf("\b \n");
    }
}

/*void main()
{
    lcist * l1 = bclist(l1);
    icns(l1,5,0,1);
    icns(l1,3,0,1);
    icns(l1,7,0,1);
    icmp(l1);
    eclim(l1,0,1);
    eclim(l1,0,1);
    eclim(l1,0,1);
    icns(l1,7,0,1);
    icmp(l1);
}*/
