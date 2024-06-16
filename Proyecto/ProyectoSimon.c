#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>//Libreria del sleep
#include <windows.h>

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

void rojo(){
    printf(ROJO_F "          "RESET_COLOR "\n");
    printf(ROJO_F "          "RESET_COLOR "\n");
    printf(ROJO_F "          "RESET_COLOR "\n");
    printf(ROJO_F "          "RESET_COLOR "\n");

    usleep(100000);//retraso

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

    usleep(100000);//retraso

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

    usleep(100000);//retraso

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

    usleep(100000);//retraso

    printf("\033[F\033[K");
    printf("\033[F\033[K");
    printf("\033[F\033[K");
    printf("\033[F\033[K");
    printf("\033[F\033[K");
    printf("\033[F\033[K");
    printf("\033[F\033[K");
    printf("\033[F\033[K");   
}

int main(){
    rojo();
    verde();
    azul();
    amarillo();

    printf("Ingresa 1 -> Rojo\n");
    printf("Ingresa 2 -> Verde\n");
    printf("Ingresa 3 -> Azul\n");
    printf("Ingresa 4 -> Amarillo\n");

    printf("Respuesta: ");
return 0;
}