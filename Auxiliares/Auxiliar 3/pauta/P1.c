#include <stdio.h>
#include <string.h>

void to_lower(char *s);
void to_upper(char *s);

int main(void) {
  // tests
  char test[] = "HOLA que Tal!";
  to_lower(test);
  printf("to lower: %s", test);
  to_upper(test);
  printf("to upper: %s", test);
}

void to_lower(char *s) {
  while(*s) { // lo mismo que s != '\0', es decir, mientras no se termine el string
    if(*s >= 'A' && *s <= 'Z') // nos aprovechamos que en ASCII el abecedario esta todo junto
      *s += 'a' - 'A'; // 'A' - 'a' seria el offset o la distancia entre las minus y las mayus en ASCII
    s++;
  }
}

void to_upper(char *s) {
  // igual a la anterior pero cambiamos la condiciones y restamos el offset
  while(*s) {
    if(*s >= 'a' && *s <= 'z')
      *s -= 'a' - 'A';
    s++;
  }
}