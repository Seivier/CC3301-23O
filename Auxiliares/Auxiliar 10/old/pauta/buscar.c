#include <stdio.h>
#include <string.h>

#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 512

char ROOT[MAX_PATH];

void buscar(char* file);

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Uso: %s <file>", argv[0]);
    return 1;
  }
  getcwd(ROOT, MAX_PATH);
  buscar(argv[1]);
}

void buscar(char* file) {
  DIR* d = opendir(".");
  if (d == NULL) {
    return;
  }

  for (struct dirent* entry = readdir(d); entry != NULL; entry = readdir(d)) {
    char* nombre = entry->d_name;
    struct stat statbuf;
    stat(nombre, &statbuf);
    if (S_ISREG(statbuf.st_mode) && strcmp(nombre, file) == 0) {
      char buf[MAX_PATH];
      getcwd(buf, MAX_PATH);
      printf("%s/%s\n", buf + strlen(ROOT) + 1, nombre);
    }
    if (strcmp("..", nombre) == 0 || strcmp(".", nombre) == 0) {
      continue;
    }
    if (S_ISDIR(statbuf.st_mode)) {
      chdir(nombre);
      buscar(file);
      chdir("..");
    }
  }
  closedir(d);
}
