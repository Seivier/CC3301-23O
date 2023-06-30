#include "string.h"
#include "aux.h"

void reverse(char* s) {
    char* f = s + strlen(s) - 1;
    char temp;
    while(s<f) {
        temp = *s;
        *s = *f;
        *f = temp;
        s++;
        f--;
    }
    return;
}
