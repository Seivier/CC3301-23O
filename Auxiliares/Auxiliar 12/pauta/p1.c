//
// Created by Vicente González on 30-06-23.
//
#include <string.h>


char *prox_pal(char **pfrase) {
	char* pal = *pfrase;
	while(*pal == ' ') pal++;
	if (*pal == 0) return NULL;
	char* end = pal;
	while(*end != ' ' && *end != 0) end++;
	*end = 0;
	end++;
	*pfrase = end;
	return pal;
}


