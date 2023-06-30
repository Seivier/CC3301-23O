//
// Created by Vicente González on 25-04-23.
//
#include <stdio.h>
#include <string.h>
#include "modificar.h"

void modificar(char* nom_dic, char* palabra, char* def, int n_lin, int ancho) {
	ancho++; // Detalle de implementacion, no se considera el salto de linea dentro de ancho
    // Abrimos el archivo
	FILE *f = fopen(nom_dic, "r+");
	int n_pal = strlen(palabra);
	int n_def = strlen(def);
    // Guardamos un buffer para leer la primera palabra
	char buff[n_pal+1];
	while (fread(buff, sizeof(char), n_pal, f)) { // Leemos n_pal chars de f y lo dejamos en buff
		buff[n_pal] = 0; // Agregamos el caracter nulo por que fread no lo agrega
		if (strcmp(buff, palabra) == 0) { // Verificamos si es la palabra (caso borde: que sucede con palabras que empiezan igual? ej: casa y casamiento)
			fseek(f, 1, SEEK_CUR); // Nos 'saltamos' el primer ':'
			fwrite(def, sizeof(char), n_def, f); // Reemplazamos con la definicion nueva
			// Limpiamos lo definicion anterior
			while(fgetc(f) != ':') { // Mientras no lleguemos al proximo ':'
				fseek(f, -1, SEEK_CUR); // Importante! todas las funciones avanzan el puntero en f, por lo que hay que devolverse un poquito
				fputc(' ', f); // Reemplazamos el caracter por un espacio
			}
			break;
		}

		// En caso de que no sea la palabra, avanzamos lo necesario: con fread leimos n_pal bytes y una linea tiene ancho bytes
		fseek(f, ancho-n_pal, SEEK_CUR);
	}
}

