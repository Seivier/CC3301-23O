#include <stdlib.h>

typedef struct nodo {
	char x;
	struct nodo *izq, *der;
} Nodo;


Nodo* abb(Nodo* u, int i, int j) {
	if (i>j) return NULL;
	int m = (i+j) / 2;
	Nodo* r = u+m;
	r->izq = abb(u, i, m-1);
	r->der = abb(u, m+1, j);
	return r;
}