#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "reemplazar.h"


char *reemplazo(char *s, char c, char *pal) {
    int length = 0;
    char *ptr = s;
    int len_palabra = strlen(pal);
    while (*ptr){
        if (*ptr == c){
            length += len_palabra;
        }
        else {
            length++;
        }
        ptr++;
       
    }
    ptr = s;
    char *resultado = malloc(length + 1);
    char *ptrr = resultado;
    for (int i = 0; i < length; i++){
       
        if (*ptr == c){
           
            char *palabra = pal; /* creamos una palabra temporaria para copiar los caracteres de la palabra a sustituir, se deletea al terminar el if*/
           
            if (len_palabra == 0){
                i--;
            }
           
            while (*palabra){
                *ptrr = *palabra;
                palabra++;
                ptrr++;
            }
           
        }
        else if (*ptr){
            *ptrr = *ptr;
            ptrr++;
        }
       else {
            break;
       }
       
       ptr++;
       
       
       
    }

    *ptrr = '\0';

    return resultado;  
}

void reemplazar(char *s, char c, char *pal){
    int length = 0;
    char *ptr = s;
    int len_palabra = strlen(pal);
    while (*ptr){
        if (*ptr == c){
            length += len_palabra;
        }
        else{
            length++;
        }
        ptr++;
       
    }
   
   
    if (len_palabra < 2){ /* caso que la palabra tengo a lo mas uno de largo */
        char *sust_ptr = s;
        if (len_palabra == 1){
            while (*s){
                if (*s == c ){

                    *sust_ptr = *pal;
               
               
                }
                else {
                    *sust_ptr = *s;
                }
                sust_ptr++;
                s++;
            }
           
        }
        else {
            while (*s){
                if (*s != c){
                    *sust_ptr =*s;
                    sust_ptr++;
                }
                s++;
            }
        }
        *sust_ptr = '\0';
    }


   
    else {
   
        char *sust_ptr = s + length; /* puntero necesario para sustituir los caracteres sin "comerse" otros, empieza desde donde termina el string resultante */
        *sust_ptr = '\0';
        sust_ptr--;
        ptr--; /* utilizaremos el puntero inicial para navegar por el string original (y el otro para escribir el string resultante) */
       
        while (ptr >= s) { /* mientras que el puntero sea mayor o igual que s, no terminara el loop, o sea, vamos disminuyendo el puntero haciendo el camino de vuelta */
            if (*ptr == c){

               
               
               
                char *palabra = pal;
                printf("palabra: %s\nlen_palabra: %d\n", palabra, len_palabra);
                for (int k = 1; k < len_palabra; k++){ /*va hasta la ultima letra de la palabra a sustituir */
                    palabra++;
                }
                while (*palabra){
                    *sust_ptr = *palabra;
                    sust_ptr--;
                    palabra--;
                }
               
               
            }
            else {
                *sust_ptr = *ptr;
                sust_ptr--;
            }
            ptr--;
        }
    }
   
   
    printf("%s", s);
}
