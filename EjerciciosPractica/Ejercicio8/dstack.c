#include "dstack.h"
#include <stdio.h>
#include <stdlib.h>

void createDS(NodeDS **ds){
	*ds=NULL;
}

int isEmptyDS(NodeDS *ds){
	if(ds==NULL)
		return 1;
	else
		return 0;
}

void push(NodeDS **ds,element ele){
	NodeDS *new;
   new=(NodeDS*)malloc(sizeof(NodeDS));
	new->e=ele;
	new->next=*ds;
	*ds=new;
}

element pop (NodeDS **ds){
	NodeDS * nodeaux;
	element eaux;
	if (isEmptyDS(*ds)){
		printf("Underflow");
		eaux=-1;//←valor error
	}
	else{
		nodeaux = *ds;
		*ds = nodeaux -> next;
		eaux = nodeaux -> e;
		free(nodeaux);
	}
      return eaux;
}

void deleteDS(NodeDS **ds){
	while(!isEmptyDS(*ds)){
		printf("\nDel %i",pop(ds));
	}
}

element ordenados(NodeDS **ds){
    NodeDS **aux;
    element e;
    int ordenado=1;
    createDS(aux);
    while(!isEmptyDS(ds)&&ordenado==1){
        e=pop(ds);
        push(aux,e);
        if(e>(*ds)->next){
            ordenado=0;
        }
    }
    if(ordenado==1){
        printf("Esta ordenado de manera ascendente");
    }
    else{
        printf("No esta ordenado de manera ascendente");
    }
    while(!isEmptyDS(*aux)){
        e=pop(aux);
        push(ds,e);
    }
}

int main(){
    NodeDS *ds;
    createDS(&ds);
    push(&ds,1);
    push(&ds,2);
    push(&ds,3);
    push(&ds,9);
    push(&ds,5);
    ordenados(&ds);
    return 0;
}