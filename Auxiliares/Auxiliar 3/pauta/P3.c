#include <stdio.h>
#include <string.h>

void reverse(char* s);

int main() {
  // tests
  char t1[] = "anitalavalatina";
  char t2[] = "abcba";
  char t3[] = "Hola mundo!";
  char t4[] = "a";

  printf("%s al reves es ", t1);
  reverse(t1);
  printf("%s\n", t1);
  printf("%s al reves es ", t2);
  reverse(t2);
  printf("%s\n", t2);
  printf("%s al reves es ", t3);
  reverse(t3);
  printf("%s\n", t3);
  printf("%s al reves es ", t4);
  reverse(t4);
  printf("%s\n", t4);
}

void reverse(char* s) {
  // similar a palindromo
  char* final = s + strlen(s) - 1; // puntero al final del string
  while(s < final) { // mientras no nos pasemos del medio del string
    // hacemos swap de los caracteres del principio y del final
    char temp = *s; // guardamos el caracter del principio
    *s = *final; // ponemos el caracter del final en el principio
    *final = temp; // ponemos el caracter del principio en el final
    s++;
    final--;
  }
}