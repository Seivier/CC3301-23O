#include <stdio.h>
#include <stdlib.h>

#include "elim-rango.h"

void eliminarRango(Nodo **phead, double y, double z) {
  Nodo* act = *phead;
  Nodo** anterior = phead;
  while(act!=NULL) {
    Nodo* aux = act;
    act = act->prox;
    if(y<=aux->x && aux->x <= z) {
      (*anterior)->prox = act;
      free(aux);
    }
    else {
      anterior = &aux;  
    }
  }
  
}
