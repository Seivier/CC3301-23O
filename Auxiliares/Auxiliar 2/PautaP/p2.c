#include <stdio.h>

int posicionBits(int x, int p, int n);

int main() {
  int test = 12;
  int patron = 3;
  printf("%x esta en %x en la posicion %d\n", patron, test, posicionBits(test, patron, 2));
  return 0;
}

int posicionBits(int x, int p, int n) {
  int mask = ~(-1<<n);
  printf("mask: %x\n", mask);
  for(unsigned long i = 0; i < sizeof(x)*8 - n + 1;i++){
		if (((x >> i) & mask) == p){
			return i; 
	  }
  }
  return -1;
}