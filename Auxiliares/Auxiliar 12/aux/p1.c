#include <string.h>

char* prox_pal(char** pfrase) {
	char* pal = *pfrase;
	while(*pal == ' ')
		pal++;
	char* end = pal;
	while(*end != ' ' && *end != 0)
		end++;
	if (*end == 0) {
		*pfrase = end;
		return pal;
	}
	*end = 0; // 0 == '\0'
	end++;
	*pfrase = end;
	return pal;
}