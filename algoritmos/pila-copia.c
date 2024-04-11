#include <stdio.h>
#include <stdlib.h>

#define size 10

typedef int element;

typedef struct sstack{
    int top;
    element array[size];
}sstack;

int main(){
    sstack s;
    createSS(&s);
    push(&s,10);
    push(&s,20);
    a=pop(&s);

}

createSS(sstack *ss){
    ss->top=-1;
}

is_Empty(sstack ss){
    if(ss.top==size-1)
        return 1;
    else
        return 0;
}

is_Full(sstack ss){
    if(ss.top==size-1)
        return 1;
    else 
        return 0;
}

push(sstack *ss, element e){
    if(is_Full(*ss)){
        printf("Error de Overflow");
        return 0;
    }
    else{
        ss->top+=1;
        ss->array[ss->top]=e;
        return 1;
    }
}

printss(sstack ss){
    if(is_Empty(ss)){
        printf("Pila vacia");
        return 0;
    }

    else{
        for(int i=0;i>=ss.top;i++){
            printf("%d\n",ss.array[i]);
        }
    }
            

}

pop(sstack *ss){
    element aux;
    if(is_Empty(*ss)){
        printf("Error de underflow");
        aux=error;
        return aux;
    }

    else{
        aux=ss->array[ss->top];
        ss->top--;
        return aux;
    }
}