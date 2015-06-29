#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int x;
    struct node * next;   
} nod;

typedef struct listid
{
    nod * start;
    nod * end;
    int size;
} list;

list * blist(list * lista) //Inicialización de lista
{
    lista = malloc(sizeof(lista));
    lista->start=malloc(sizeof(nod));
    lista->end=malloc(sizeof(nod));
    lista->start=NULL;
    lista->end=NULL;
    lista->size=0;
}

nod * bnode(nod * nodo) //Inicialización de nodo
{
    nodo = malloc(sizeof(nod));
    nodo->x=0;
    nodo->next=malloc(sizeof(nod));
    nodo->next=NULL;
    return nodo;
}

void ins(list * lst, int num, int dat,int mod) //Insertar elementos en lista..
{
    nod * neww=bnode(neww);
    nod * act=lst->start;
    nod * obj;
    if(lst->size== 0)
    {
    	lst->start=neww;
    	neww->x=num;
    	neww->next=NULL;
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
    	    	neww->next=NULL;
    	    	lst->end=neww;
    	    	lst->size++;
	    	break;
    	    case 2:
		//Insertar elementos antes
    		neww->next=lst->start;
    		lst->start=neww;
    		neww->x=num;
    		lst->size++;
		break;
	    case 3:
		//Insertar despues de un nodo
		while( act != NULL)
    		{
		    if(act->x == dat)
		    {
			if(act == lst->end)
			{
			    lst->end=neww;
			    neww->x=num;
			    neww->next=NULL;
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
    		}
	}
    }
    
}

void elim(list * lst, int dat,int mod) //Eliminar elementos en lista..
{
    //nod * new=bnode(new);
    nod * act=lst->start;
    nod * obj;
    nod * ant;
    if(lst->size== 1)
    {
    	lst->start=NULL;
    	lst->end=NULL;
    	lst->size--;
    }
    else if(lst->size > 1)
    {
	switch( mod )
	{
    	    case 1:
		//Eliminar elementos antes
    		lst->start=lst->start->next;
    		lst->size--;
		break;
	}
    }
    
}


void imp(list * l1)
{
    nod * act=l1->start;
     if(l1->size==0)
        printf("La lista está vacía\n");
    else
    {
    	while( act != NULL)
    	{
	    printf("%d,",act->x);
	    act=act->next;
    	}
        printf("\b \n");
    }
}
