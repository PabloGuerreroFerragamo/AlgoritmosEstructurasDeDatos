#include "DQueue.h"
#include <stdio.h>
#include <stdlib.h>

void create(QueueD *Q){
	Q->tail=Q->head=NULL;
}

void enqueue(QueueD *Q,element ele){
	NodeQD *new;
	new=(NodeQD*)malloc(sizeof(NodeQD));
	new->e=ele;
	if(isEmpty(*Q)){
		Q->head=new;
		Q->head->next=NULL;
	}else{
		new->next=NULL;
		Q->tail->next=new;
	}
	Q->tail=new;
}

element dequeue(QueueD *Q){
	element aux;
	NodeQD *n;
	if(!isEmpty(*Q)){
		aux=Q->head->e;
		n=Q->head;
		Q->head=Q->head->next;
		free(n);
		
	}else{
		printf("Cola vacia");
		aux=-1; // <- valor error
	}
	return aux;
}

int isEmpty(QueueD Q){
	if(Q.head==NULL)
		return 1;
	else
		return 0;
}

void deleteDQ(QueueD *Q){
	NodeQD *n;
	while(!isEmpty(*Q)){
		printf("\nDelete %d",dequeue(Q));
	}
	Q->tail=NULL;
}

element buscador(QueueD *dq,int busqueda){
    QueueD aux;
	create(&aux);
	element e;
	int encontrado=0;
	while(!isEmpty(*dq)){
		e=dequeue(dq);
		enqueue(&aux,e);
		if(e==busqueda){
			encontrado++;
		}
	}
	while(!isEmpty(aux)){
		e=dequeue(&aux);
		enqueue(dq,e);
	}
	if(encontrado==1){
		printf("Encontrado");
	}
	else{
		printf("No encontrado");
	}
}

int main(){
    QueueD cola;
	int numero=2;
    create(&cola);
    enqueue(&cola,1);
    enqueue(&cola,2);
    enqueue(&cola,3);
    enqueue(&cola,4);
    enqueue(&cola,5);
    enqueue(&cola,6);
	buscador(&cola,numero);

    return 0;
}