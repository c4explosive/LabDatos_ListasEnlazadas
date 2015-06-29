#include <stdio.h>
#include <stdlib.h>
#include "l2l.h"
void l2oadl(l2ist * l1);
void i2mpr(n2od * act);
void p2mir(n2od * act);
void main()
{
    l2ist * l1=b2list(l1);
    int op;
    clrscr();
    l2oadl(l1);
    do
    {
	clrscr();
    	printf("Recorrer lista doblemente enlazada con algoritmo recursivo: \n");
    	printf("1. De forma normal.\n");
    	printf("2. De forma invertida\n");
    	printf("3. Salir\n");
    	printf("Ingrese una opciòn: ");
    	scanf("%d",&op);
	switch(op)
	{
	    case 1:
		clrscr();
    	    	i2mpr(l1->start);
    	    	//i2mp(l1);
    	    	getch();
    	    	break;
	    case 2:
		clrscr();
		p2mir(l1->end);
		//pm2i(l1);
		getch();
		break;				
	    case 3:
		break;
	    default:
		clrscr();
		printf("Opción incorrecta\n");
		getch();
	}
    } while(op!=3);
}

void l2oadl(l2ist * l1)
{
    int i,elem;
    printf("Cargando Lista (10 elementos)\n");
    for(i=0;i<10;i++)
    {
	printf("Ingrese el elemento %i: ",i+1);
	scanf("%d",&elem);
	i2ns(l1,elem,0,1);
    }
}
void i2mpr(n2od * act)
{
     if( act == NULL)
	printf("");
     else
     {
	printf("%p - %d\n",act,act->x);
	i2mpr(act->next);
     }
}
void p2mir(n2od * act)
{
     if( act == NULL)
	printf("");
     else
     {
	printf("%p - %d\n",act,act->x);
	p2mir(act->before);
     }

}
