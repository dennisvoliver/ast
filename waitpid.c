#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	pid_t pid, n;
	int status;
	if ((pid=fork()) < 0) {
		fprintf(stderr, "can't fork\n");
		exit(-1);
	} else if (pid == 0) {
		printf("I am the child\n");
		exit(4);
	} else {
		n = waitpid(-1, &status, NULL);
		printf( \
	"parent: pid %d has exited " \
	" with exit status : %d\n", n, status);
		exit(status);
	}
}
