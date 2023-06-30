//
// Created by Vicente González on 28-04-23.
//
#include <stdio.h>
#include <string.h>
#include "modificar.h"

void modificar(char *nom_dic, char *palabra, char *def, int n_lin, int ancho) {
	ancho++; // para considerar el salto de linea
	FILE *f = fopen(nom_dic, "r+");
	int n_pal = strlen(palabra);
	int n_def = strlen(def);
	char buff[n_pal+1];
	while(fread(buff, sizeof(char), n_pal+1, f)) {
		if (buff[n_pal] != ':') {
			fseek(f, ancho-n_pal-1, SEEK_CUR);
			continue;
		}

		if(strcmp(buff, palabra) == 0) {
			fwrite(def, sizeof(char), n_def, f);
			while(fgetc(f) != ':') {
				fseek(f, -1, SEEK_CUR);
				fputc(' ', f);
			}
			break;
		}

		fseek(f, ancho-n_pal-1, SEEK_CUR);
	}

	fclose(f);

}