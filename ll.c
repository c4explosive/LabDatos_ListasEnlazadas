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

void ins(list * lst, int num,int mod) //Insertar elementos en lista..
{
    nod * new=bnode(new);
    if(lst->size== 0)
    {
    	lst->start=new;
    	new->x=num;
    	new->next=NULL;
    	lst->end=new;
    	lst->size++;
    }
    else
    {
	switch( mod )
	{
 	    case 1:
 	    //Insertar elementos después
    	    	lst->end->next=new;
    	    	new->x=num;
    	    	new->next=NULL;
    	    	lst->end=new;
    	    	lst->size++;
	    	break;
    	    case 2:
		//Insertar elementos antes
    		new->next=lst->start;
    		lst->start=new;
    		new->x=num;
    		lst->size++;
		break;
	}
    }
    
}


void imp(list * l1)
{
    nod * act=l1->start;
    while( act != NULL)
    {
	printf("%d,",act->x);
	act=act->next;
    }
    printf("\n");
}
void main()
{
    list * l1=blist(l1);
    list * l2=blist(l1);
    ins(l1,5,1);
    ins(l1,9,1);
    ins(l1,7,1);
    ins(l1,9,2);
    ins(l1,7,2);
    ins(l1,4,1);
    ins(l1,89,1);
    ins(l1,69,2);
    //inse(l2,3);
    imp(l1);
    //insn(l2,4);
    //imp(l2);
}

