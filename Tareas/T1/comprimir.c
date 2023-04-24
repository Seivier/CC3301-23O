#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "comprimir.h"

uint comprimir(uint a[], int nbits ) { 
  //contador para el tamaño "divido"
  int na=0;
  //tamaño total arreglo
  int su=(sizeof(uint)<<3);
  //simulador de division
  while (su>=nbits){
    na++;
    su-=nbits;
  } 
  //mascara 1
  //uint mask = ((1<<(nbits-1))<<1)-1;
  /*mascara alternativa*/
   uint mask =((~((-1<<(nbits-1))<<1))) ;
  //donde se guardan los comprimidos
  uint r=0;
  //contador
  int j=0;
  //comprimidor
  while (j<na){
    //hace espacio para los siguientes n°
    r=r<<(nbits-1) << 1;
    //añade con un "o" los nbtis de la izq 
    r|=a[j]& mask;
    //suma uno al contador
    j++;
    } 
 return r;
  }
