#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>//Libreria del sleep
#include <windows.h>
#include "colors.h"
#include <time.h>

#define RESET_COLOR    "\x1b[0m"
#define NEGRO_T        "\x1b[30m"
#define NEGRO_F        "\x1b[40m"
#define ROJO_T     "\x1b[31m"
#define ROJO_F     "\x1b[41m"
#define VERDE_T        "\x1b[32m"
#define VERDE_F        "\x1b[42m"
#define AMARILLO_T "\x1b[33m"
#define    AMARILLO_F  "\x1b[43m"
#define AZUL_T     "\x1b[34m"
#define    AZUL_F      "\x1b[44m"
#define MAGENTA_T  "\x1b[35m"
#define MAGENTA_F  "\x1b[45m"
#define CYAN_T     "\x1b[36m"
#define CYAN_F     "\x1b[46m"
#define BLANCO_T   "\x1b[37m"
#define BLANCO_F   "\x1b[47m"

typedef int element;

typedef struct nodeQ{
    element e;
    struct nodeQ *next;
}nodeq;

typedef struct DQueue{
    nodeq *tail;
    nodeq *head;
}DQueue;

void createDQ(DQueue *dq){
    dq->tail=NULL;
    dq->head=NULL;
}

int is_Empty(DQueue dq){
    if(dq.head==NULL&&dq.tail==NULL)
        return 1;
    else
        return 0;
}

void enqueueDQ(DQueue *dq,element ele){
    nodeq *new;
    new=(nodeq*)malloc(sizeof(nodeq));
    new->e=ele;
    new->next=NULL;
    if(is_Empty(*dq))
        dq->head=new;
    else
        dq->tail->next=new;
    dq->tail=new;
}

int dequeue(DQueue *dq){//tipo de acuerdo al retorno
    if(is_Empty(*dq)){
        printf("Esta vacia");
        return -1;//SOLO FUNCIONA CON NUMEROS
    }
    nodeq *aux=dq->head;
    element e=aux->e;
    if(dq->head==dq->tail)
        dq->tail=NULL;
    dq->head=dq->head->next;
    free(aux);
    return e;//RETORNO ELEMENT, EL CUAL DEBE COINCIDIR CON EL RETORNO ERROR
}

void rojo(){
    printf(ROJO_F "          "RESET_COLOR "\n");
    printf(ROJO_F "          "RESET_COLOR "\n");
    printf(ROJO_F "          "RESET_COLOR "\n");
    printf(ROJO_F "          "RESET_COLOR "\n");

    usleep(300000);//retraso

    printf("\033[F\033[K");//Sube una línea y borra la línea completa
    printf("\033[F\033[K");
    printf("\033[F\033[K");
    printf("\033[F\033[K");
}

void verde(){
    printf("          " VERDE_F "          " RESET_COLOR "\n");
    printf("          " VERDE_F "          " RESET_COLOR "\n");
    printf("          " VERDE_F "          " RESET_COLOR "\n");
    printf("          " VERDE_F "          " RESET_COLOR "\n");

    usleep(300000);//retraso

    printf("\033[F\033[K");
    printf("\033[F\033[K");
    printf("\033[F\033[K");
    printf("\033[F\033[K");
}

void azul(){
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    
    printf(AZUL_F "          " RESET_COLOR "\n");
    printf(AZUL_F "          " RESET_COLOR "\n");
    printf(AZUL_F "          " RESET_COLOR "\n");
    printf(AZUL_F "          " RESET_COLOR "\n");

    usleep(300000);//retraso

    printf("\033[F\033[K");
    printf("\033[F\033[K");
    printf("\033[F\033[K");
    printf("\033[F\033[K");
    printf("\033[F\033[K");
    printf("\033[F\033[K");
    printf("\033[F\033[K");
    printf("\033[F\033[K");   
}

void amarillo(){
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    
    printf("          " AMARILLO_F "          " RESET_COLOR "\n");
    printf("          " AMARILLO_F "          " RESET_COLOR "\n");
    printf("          " AMARILLO_F "          " RESET_COLOR "\n");
    printf("          " AMARILLO_F "          " RESET_COLOR "\n");

    usleep(300000);//retraso

    printf("\033[F\033[K");
    printf("\033[F\033[K");
    printf("\033[F\033[K");
    printf("\033[F\033[K");
    printf("\033[F\033[K");
    printf("\033[F\033[K");
    printf("\033[F\033[K");
    printf("\033[F\033[K");   
}

void imprimirValor(int condicion){
    if(condicion==1){
        rojo();
    }
    else if(condicion==2){
        verde();
    }
    else if(condicion==3){
        azul();
    }
    else if(condicion==4){
        amarillo();
    }
}

void coloresAnteriores(DQueue *dq){
    element e,e_dos;
    DQueue aux;
    createDQ(&aux);
    while(!is_Empty(*dq)){
        e=dequeue(dq);
        enqueueDQ(&aux,e);
        //colaAux.head->e
        imprimirValor(e);
    }
    while(!is_Empty(aux)){
        e_dos=dequeue(&aux);
        enqueueDQ(dq,e_dos);
    }
}

int main(){
    srand(time(NULL));

    DQueue cola,colaRespuestas,colaAux;
    createDQ(&cola);
    createDQ(&colaRespuestas);
    createDQ(&colaAux);

    int i,j,aleatorio,contadorWhile=0,respuesta=0,primerJuego=0,nivel=1,historialNiveles=0,what=0;
    while(contadorWhile<1){
        aleatorio=(rand()%4)+1;
        enqueueDQ(&cola,aleatorio);

        if(primerJuego!=0){
            colaAux=cola;
            coloresAnteriores(&colaAux);
            imprimirValor(aleatorio);
        }    

        if(primerJuego==0){
            imprimirValor(aleatorio);
        }
       
        printf("Ingresa 1 -> Rojo\n");
        printf("Ingresa 2 -> Verde\n");
        printf("Ingresa 3 -> Azul\n");
        printf("Ingresa 4 -> Amarillo\n");
        
        
        while(historialNiveles<nivel){
        printf("Respuesta(%d): While(%d)",historialNiveles+1,what);
        scanf("%d",&respuesta);
        enqueueDQ(&colaRespuestas,respuesta);
        historialNiveles++;
        what++;
        }
        
        historialNiveles=1;

        //Primer numero
        if((cola.head->e==colaRespuestas.head->e)&&primerJuego==0){
            enqueueDQ(&cola,aleatorio);
            primerJuego++;
            nivel++;
        }
        else if(respuesta==aleatorio){
            
        }
        else{
            printf("Opcion equivocada");
            contadorWhile++;
        }


        if((cola.head->e==colaRespuestas.head->e)&&primerJuego!=0){

            nivel++;
        }
        else{
            printf("Opcion equivocada, era %d",cola.tail->e);
            contadorWhile++;
        }
        
    }

return 0;
}