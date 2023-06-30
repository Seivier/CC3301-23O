//
// Created by Vicente González on 25-04-23.
//
#include "modificar.h"


// Para compilar: gcc -o modificar auxiliar6.c modificar.c modificar.h
int main(int argc, char** argv) {
	char* dic = "dict.txt";
	char* pal = "alimento";
	char* def = "sustancia ingerida por un ser vivo";
	int lin = 10;
	int ancho = 47;
	modificar(dic, pal, def, lin, ancho);
}