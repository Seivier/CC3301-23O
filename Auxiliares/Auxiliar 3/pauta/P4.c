#include <stdio.h>
#include <string.h>

char mas_repetido(char* s);

int main() {
  // tests
  char test1[] = "aaabbbb";
  char test2[] = "abbcccc";
  char test3[] = "aaabbcd";
  char test4[] = "anitalavalatina";

  printf("El caracter mas repetido en %s es '%c'\n", test1, mas_repetido(test1));
  printf("El caracter mas repetido en %s es '%c'\n", test2, mas_repetido(test2));
  printf("El caracter mas repetido en %s es '%c'\n", test3, mas_repetido(test3));
  printf("El caracter mas repetido en %s es '%c'\n", test4, mas_repetido(test4));
}

char mas_repetido(char* s) {
  // un char es un int de 8 bits (1 byte) por lo que podemos usar un arreglo de 256 posiciones
  int chars[256] = {0};

  // guardamos la cantidad de veces que aparece cada caracter usando el char como indice
  while(*s) {
    chars[(int)*s]++;
    s++;
  }

  // buscamos el caracter con mas apariciones
  int max = 0;
  char max_char = 0;
  for(int i = 0; i < 256; i++) {
    if(chars[i] > max) {
      max = chars[i];
      max_char = (char)i;
    }
  }

  return max_char;
}