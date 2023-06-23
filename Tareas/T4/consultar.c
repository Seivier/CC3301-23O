#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "pss.h"

#define MAXTAM (800+2)

int main(int argc, char *argv[]) {
  if(argc!=3){ // Uso incorrecto de parametros
    fprintf(stderr, "Uso: ./consultar.bin <diccionario> <llave>\n");
    return 1; 
  }

  char *nombreArchivo = argv[1]; // Tomo nombre de archivo
  char *llaveBusqueda = argv[2]; // Tomo llave de busqueda
  FILE *f = fopen(nombreArchivo, "r"); // Abro el archivo el archivo
  
  if(f == NULL){ // Si el archivo esta vacio
    perror(nombreArchivo);
  }
  
  char primeraLinea[MAXTAM + 1];
  fgets(primeraLinea, sizeof(primeraLinea), f); // Tomo primera linea
  
  fseek(f, 0, SEEK_END);
  int tamañoArchivo = ftell(f); // Calculo tamaño de archivo
  
  if(tamañoArchivo == 0){ // Si el archivo esta vacio
    fprintf(stderr, "%s: el dicionario esta vacio\n",nombreArchivo);
    return 1; 
  }
  if(tamañoArchivo%strlen(primeraLinea) != 0){ // No son multiplos
    fprintf(stderr, "%s: el tamaño del archivo no es multiplo del tamaño de la linea\n",nombreArchivo);
    return 1; 
  }
  
  int numLineas = tamañoArchivo/strlen(primeraLinea) + 1; // Calculo numero de lineas
  
  fseek(f, hash_string(llaveBusqueda), SEEK_SET); // Enunciado
  int lineaActual = hash_string(llaveBusqueda)/strlen(primeraLinea);
  
  char frase[strlen(primeraLinea) - strlen(llaveBusqueda) - 1]; // Defino frase
  frase[0] = '\0';
  char buf[MAXTAM + 1]; // Defino buf
  
  int i = 0;
  while(i < numLineas){
    if(fgets(buf, sizeof(buf), f) == NULL){
        fseek(f, 0, SEEK_SET);
        lineaActual = 1;
    }
    if(strlen(buf) != strlen(primeraLinea) && strlen(buf) != 0){ // Tamaño variable
        fprintf(stderr, "%s: linea %d de tamaño incorrecto\n",nombreArchivo, lineaActual-1);
        return 1;
    }
    char *c = buf;
    while(*c != ':'){
        if(strlen(buf) > strlen(primeraLinea)){ // Linea que no me da :(
            fprintf(stderr, "%s: linea %d no posee : para terminar la llave\n", nombreArchivo, lineaActual-1);
            return 1;
        }
        c++;
    }
    *c = '\0';
    if(strcmp(buf, llaveBusqueda) == 0){
        fseek(f, -strlen(primeraLinea) + strlen(llaveBusqueda) + 1, SEEK_CUR);
        fgets(frase, MAXTAM - strlen(llaveBusqueda) - 1, f);
        break;
    }
    i++;
    lineaActual++;
  } 
  
  if(strlen(frase) == 0){ // No se encontró la llave por lo que no se modifico la frase
    fprintf(stderr, "%s: el diccionario no contiene la llave %s\n",nombreArchivo, llaveBusqueda);
    return 1; 
  } else{
    printf(frase);
  }
  fclose(f);
  return 0;
}
