//
// Created by Vicente González on 30-06-23.
//
#include <stdio.h>
#include <unistd.h> // fork
#include <sys/wait.h> // waitpid
#include <sys/types.h> // pid_t
#include <stdlib.h> // exit
#include <limits.h> // INT_MIN

// lectura que garantiza cantidad de bytes leídos
int leer(int fd, void *buf, int n) {
	if (n==0)
		return 0;
	do {
		int rc= read(fd, buf, n);
		if (rc<=0)
			return 1; // fracaso: error o fin del archivo/pipe/socket
		n-= rc; // descontamos los bytes leídos
		buf= (char*)buf + rc; // avanzamos el buffer
	} while (n>0); // mientras no leamos todo lo que esperamos
	return 0; // exito
}

int maxArreglo(int a[], int n, int p){
	pid_t pids[p];
	int in_fds[p];
	int tam = n/p;
	for(int j=0; j<p; j++){
		int fds[2];
		pipe(fds);
		pids[j] = fork();
		if(pids[j] == 0){ // estamos en el hijo
			close(fds[0]); // en fds[0] se lee y el hijo solo escribe
			int max_hijo = INT_MIN;
			for(int i=j*tam; i<(j+1)*tam; i++){
				if(a[i] > max_hijo){
					max_hijo = a[i];
				}
			}
			write(fds[1], &max_hijo, sizeof(max_hijo));
			exit(0); // muy importante! (fork bomb)
		}
		else{ // estamos en el padre
			close(fds[1]); // solo leemos! cerramos el de escritura
			in_fds[j] = fds[0];
		}
	}
	// estamos en el padre porque los hijos hicieron exit
	int max = INT_MIN;
	for(int j=0; j<p; j++){
		int max_hijo;
		leer(in_fds[j], &max_hijo, sizeof(max_hijo));
		if(max_hijo > max)
			max = max_hijo;
		close(in_fds[j]);
		waitpid(pids[j], NULL, 0); // enterrar al hijo! para no tener zombies
	}
	return max;
}