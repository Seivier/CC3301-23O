#include "string.h"
#include "aux.h"

int palindromo(char* s) {
    int n = strlen(s);
    char* f = s + n - 1;
    while(s<f) {
        if (*s != *f) {
            return 0;
        }
        s++;
        f--;
    }
    return 1;
}