#include <unistd.h> // fork
#include <sys/wait.h> // waitpid
#include <stdlib.h>
#include <limits.h> // INT_MIN

int maxArreglo(int a[], int n, int p) {
	pid_t pids[p];
	int in_fds[p];
	int tam = n/p;
	for (int i = 0; i < p; ++i) { // creacion de hijos
		int fds[2];
		pipe(fds);
		pids[i] = fork();
		if (pids[i] == 0)
		{ // hijo
			close(fds[0]);
			int max = INT_MIN;
			for (int j = i * tam; j < (i + 1) * tam; j++)
			{
				if (a[j] > max)
					max = a[j];
			}
			write(fds[1], &max, sizeof(max));
			exit(0);
		} else
		{
			close(fds[1]);
			in_fds[i] = fds[0];
		}

	}
	// padre: calcular max global
	int max_g = INT_MIN;
	for(int i = 0; i<p; i++) {
		int max_l;
		read(in_fds[i], &max_l, sizeof(max_l));
		if (max_l > max_g)
			max_g = max_l;
		close(in_fds[i]);
		waitpid(pids[i], NULL, 0);
	}

	return max_g;
}