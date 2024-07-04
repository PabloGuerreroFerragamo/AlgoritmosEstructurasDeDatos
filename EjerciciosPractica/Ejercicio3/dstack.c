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

element imprimir(NodeDS **ds){
	NodeDS *aux;
	element e;
	while(!isEmptyDS(*ds)){
		e=pop(ds);
		push(&aux,e);
		printf("%d",e);
	}
	while(!isEmptyDS(aux)){
		e=pop(&aux);
		push(ds,e);
	}
}