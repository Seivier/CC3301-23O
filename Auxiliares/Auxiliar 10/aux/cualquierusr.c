#include <stdio.h>
#include <string.h>

#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_SIZE 512
typedef unsigned int uint;

void permisos(uint perm);

int main() {
	permisos(0006);
}

void permisos(uint perm) {
	DIR* d = opendir(".");

	if (d == NULL)
		return;

	for(struct dirent* curr = readdir(d); curr != NULL; curr = readdir(d)){
		char* nombre = curr->d_name;

		struct stat st;
		stat(nombre, &st);
		if(S_ISREG(st.st_mode) && (st.st_mode & 0777) == perm) {
			char buf[MAX_SIZE];
			getcwd(buf, MAX_SIZE);
			printf("%s/%s\n", buf, nombre);
		}

		if(S_ISDIR(st.st_mode) && strcmp(".", nombre) != 0 && strcmp("..", nombre)) {
			chdir(nombre);
			permisos(perm);
			chdir("..");
		}

	}

	closedir(d);

}
