#include "dstack.h"
#include "DQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    QueueD cola,aux;
    NodeDS *pila;
    element e;
    char frase[100];
    int i,palindromo=1;
    create(&cola);
    create(&aux);
    createDS(&pila);
    printf("Introduce una frase: ");
    scanf("%s",&frase);
    for(i=0;i<strlen(frase);i++){
        if(frase[i]==" "){
            frase[i]=="";
        }
        tolower(frase[i]);
        enqueue(&cola,tolower(frase[i]));
        push(&pila,tolower(frase[i]));
    }
    
    while(!isEmpty(cola)&&palindromo==1){
        e=dequeue(&cola);
        enqueue(&aux,e);
        

        if(e!=pop(&pila)){
            palindromo=0;
        }        
    }
    if(palindromo==1){
        printf("Es un palindromo");
    }
    else{
        printf("NO es un palindromo");
    }
    while(!isEmpty(aux)){
        e=dequeue(&aux);
        enqueue(&cola,e);
    }
    return 0;
}