#include <stdio.h>
#include <string.h>

#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_SIZE 512

char ROOT[MAX_SIZE];

void buscar(const char* file);

int main() {
	getcwd(ROOT, MAX_SIZE);
	buscar("t3.c");
}


void buscar(const char* file) {
	DIR* d = opendir(".");

	if (d == NULL)
		return;

	for(struct dirent* curr = readdir(d); curr != NULL; curr = readdir(d)) {
		char* nombre = curr->d_name;
		struct stat st;
		stat(nombre, &st);
		if(S_ISREG(st.st_mode) && strcmp(nombre, file) == 0) {
			char buf[MAX_SIZE];
			getcwd(buf, MAX_SIZE);
			printf(".%s/%s\n", buf + strlen(ROOT), nombre);
		}

		if(strcmp(".", nombre)==0 || strcmp("..", nombre)==0) {
			continue;
		}

		if (S_ISDIR(st.st_mode)) {
			chdir(nombre);
			buscar(file);
			chdir("..");
		}
	}

	closedir(d);


}