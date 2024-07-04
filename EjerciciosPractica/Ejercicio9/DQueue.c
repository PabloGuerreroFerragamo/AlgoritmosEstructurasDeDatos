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

void deleteQD(QueueD *Q){
	NodeQD *n;
	while(!isEmpty(*Q)){
		printf("\nDelete %d",dequeue(Q));
	}
	Q->tail=NULL;
}