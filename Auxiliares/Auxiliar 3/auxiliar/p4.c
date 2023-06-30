#include "aux.h"

char mas_repetido(char* s) {
    int freq[255] = { 0 };

    while(*s != 0) {
        freq[*s]++;
        s++;
    }

    int max = 0;
    char m_char;
    for(int i = 0; i < 255; i++) {
        if (freq[i] > max) {
            max = freq[i];
            m_char = i;
        }
    }
    return m_char;
}