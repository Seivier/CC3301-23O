#include <string.h>
#include <stdio.h>

// P1
char* prox_pal(char** pfrase);

// P2
typedef struct nodo {
	char x;
	struct nodo *izq, *der;
} Nodo;

Nodo* abb(Nodo* u, int i, int j);

// P4
int maxArreglo(int a[], int n, int p);

int main(int argc, char** argv) {

}