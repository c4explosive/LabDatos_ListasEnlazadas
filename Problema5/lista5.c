#include <stdio.h>
#include <stdlib.h>
#include "lcl.h"
void lcoadl(lcist * l1);
void main()
{
     lcist * l1 = bclist(l1);
     lcoadl(l1);  
     printf("Lista: \n"); 
     icmp(l1);
}

void lcoadl(lcist * l1)
{
    int i,elem;
    printf("Cargando Lista Circular (10 elementos)\n");
    for(i=0;i<10;i++)
    {
        printf("Ingrese el elemento %i: ",i+1);
        scanf("%d",&elem);
        icns(l1,elem,0,1);
    }
}

