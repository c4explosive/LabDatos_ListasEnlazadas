#include <stdio.h>
#include <stdlib.h>
#define clrscr() system("clear")
#define getch() system("read ")

typedef struct n2ode
{
    int x;
    struct n2ode * before;
    struct n2ode * next;
} n2od;

typedef struct l2istid
{
    n2od * start;
    n2od * end;
    int size;
}l2ist;

l2ist * b2list(l2ist * lista)
{
     lista = malloc(sizeof(l2ist));
     lista->start=malloc(sizeof(n2od));
     lista->end=malloc(sizeof(n2od));
     lista->start=NULL;
     lista->end=NULL;
     lista->size=0;
     return lista;
}

n2od * b2node(n2od * nodo)
{
    nodo=malloc(sizeof(n2od));
    nodo->x=0;
    nodo->before=malloc(sizeof(n2od));
    nodo->next=malloc(sizeof(n2od));
    nodo->before=NULL;
    nodo->next=NULL;
    return nodo;
}

void i2mp(l2ist * l1)
{
    n2od * act=l1->start;
    while( act != NULL)
    {
        printf("%d,",act->x);
        //printf("%p->%p  ",act,act->next);
        act=act->next;
    }
    printf("\n");
}

void pm2i(l2ist * l1)
{
    n2od * act=l1->end;
    while( act != NULL)
    {
        printf("%d,",act->x);
        act=act->before;
    }
    printf("\n");
}



void i2ns(l2ist * lst, int num,int dat,int mod) //Insertar elementos en lista..
{
    n2od * neww=b2node(neww);
    n2od * act=lst->start;
    n2od * obj;
    if(lst->size== 0)
    {
    	lst->start=neww;
    	neww->x=num;
    	neww->next=NULL;
    	neww->before=NULL;
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
    	    	neww->before=lst->end;
    	    	lst->end=neww;
    	    	lst->size++;
	    	break;
    	    case 2:
		//Insertar elementos antes
    		neww->next=lst->start;
		lst->start->before=neww;
		neww->before=NULL;
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
			    neww->before=act;
			    lst->size++;
			}
			else
			{
		 	    obj=act;	
			    neww->x=num;
			    neww->before=obj;
			    neww->next=obj->next;
			    obj->next->before=neww;
			    obj->next=neww;
			    lst->size++;
			}
			break;
		    }
		    act=act->next;
    		}
		break;
	    case 4:
		//Insertar antes de un nodo
		if(act == lst->start && act->x==dat)
		{
		    lst->start=neww;
		    neww->next=act;
		    act->before=neww;
		    neww->x=num;
		    
		}
		else
		{
		    while( act != NULL)
    		    {
		    	if(act->x == dat)
		    	{
		 	    obj=act;	
			    neww->x=num;
			    neww->next=obj;
			    neww->before=obj->before;
			    obj->before->next=neww;
			    obj->before=neww;
			    lst->size++;
			    break;
		        }
		    	act=act->next;
    		    }
		}
	}
    }
    
}
void e2lim(l2ist * lst, int dat,int mod) //Eliminar elementos en lista..
{
    //nod * new=bnode(new);
    n2od * act=lst->start;
    n2od * obj;
    n2od * ant;
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
		lst->start->before=NULL;
    		lst->size--;
		break;
	    case 2:
		//Eliminar elementos despues
    		lst->end=lst->end->before;
		lst->end->next=NULL;
    		lst->size--;
		break;
	    case 3:
		//Eliminar nodo especifico
		if(act == lst->start && act->x==dat)
		{
		    lst->start=lst->start->next;
		    lst->start->before=NULL; 
		    lst->size--; 
		}
		else
		{
		    while( act != NULL)
    		    {
		    	if(act->x == dat)
		    	{
		 	    obj=act;	
			    obj->before->next=obj->next; 
			    obj->next->before=obj->before;
			    lst->size--;
			    break;
		        }
		    	act=act->next;
    		    }
		}
		break;

	}
    }
    
}


/*void main()
{
    l2ist * l1=b2list(l1);
    i2ns(l1,5,0,1);
    i2ns(l1,8,0,1);
    i2ns(l1,9,0,1);
    i2ns(l1,7,0,1);
    i2ns(l1,4,0,1);
    i2mp(l1);
    pm2i(l1);
    e2lim(l1,7,3);
    i2mp(l1);
    pm2i(l1);
}*/
