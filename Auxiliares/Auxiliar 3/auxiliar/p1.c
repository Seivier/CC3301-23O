#include "aux.h"

void to_lower(char* s) {
    while(*s != '\0') {
        char t = *s;
        if (t >= 'A' && t <= 'Z') {
            int offset = 'a' - 'A';
            *s += offset;
        }
        s++;
    }
}

void to_upper(char* s) {
    while(*s != 0) {
        if (*s >= 'a' && *s <= 'z') {
            int offset = 'a' - 'A';
            *s -= offset;
        }
        s++;
    }
}