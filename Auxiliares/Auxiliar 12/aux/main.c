#include <stdio.h>

char* prox_pal(char** pfrase);

typedef struct nodo {
	char x;
	struct nodo *izq, *der;
} Nodo;

Nodo* abb(Nodo* u, int i, int j);

void printNodo(Nodo* u) {
	if (!u) return;
	printNodo(u->izq);
	printf(" %c ", u->x);
	printNodo(u->der);
}

int main(int argc, char** argv) {
	// P1
	char frase[] = " hola   que";
	char* pfrase = frase;
	char* pal;
	pal = prox_pal(&pfrase);
	printf("'%s' '%s'\n", pal, pfrase);
	pal = prox_pal(&pfrase);
	printf("'%s' '%s'\n", pal, pfrase);
	pal = prox_pal(&pfrase);
	printf("'%s' '%s'\n", pal, pfrase);


	// P2
	// P2
	Nodo n1 = {'a', NULL, NULL};
	Nodo n2 = {'b', NULL, NULL};
	Nodo n3 = {'c', NULL, NULL};
	Nodo n4 = {'d', NULL, NULL};
	Nodo n5 = {'e', NULL, NULL};
	Nodo n6 = {'f', NULL, NULL};
	Nodo n7 = {'g', NULL, NULL};
	Nodo n8 = {'h', NULL, NULL};
	Nodo u[8] = {n1, n2, n3, n4, n5, n6, n7, n8};
	Nodo* raiz = abb(u, 0, 7);
	printNodo(raiz);
	printf("\n");
}