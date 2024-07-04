#include "dstack.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    NodeDS *ds,*dsDos,*auxUno,*auxDos,*respuesta;
    element eUno,eDos;
    int suma=0,acarreo=0;
    createDS(&ds);
    createDS(&dsDos);
    createDS(&auxUno);
    createDS(&auxDos);
    push(&ds,2);
    push(&ds,1);
    push(&ds,4);
    push(&ds,5);
    push(&ds,2);
    push(&ds,3);
    push(&ds,9);

    push(&dsDos,9);
    push(&dsDos,2);
    push(&dsDos,3);
    push(&dsDos,4);
    push(&dsDos,1);
    push(&dsDos,8);
    push(&dsDos,7);

    while(!isEmptyDS(ds)&&!isEmptyDS(dsDos)){
        eUno=pop(&ds);
        push(&auxUno,eUno);
        eDos=pop(&dsDos);
        push(&auxDos,eDos);
        suma=eUno+eDos+acarreo;
        if(suma>=10){
            acarreo=1;
            push(&respuesta,suma%10);
            //printf("%d",suma%10);
        }
        else{
            acarreo=0;
            push(&respuesta,suma);
            //printf("%d",suma);
        }
    }
    if(acarreo>0){
        push(&respuesta,acarreo);
        //printf("%d",acarreo);
    }
    while(!isEmptyDS(auxUno)){
        eUno=pop(&auxUno);
        push(&ds,eUno);
    }
    while(!isEmptyDS(auxDos)){
        eUno=pop(&auxDos);
        push(&dsDos,eUno);
    }

    imprimir(&respuesta);

    return 0;
}