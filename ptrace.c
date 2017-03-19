#include <unistd.h>
#include <sys/ptrace.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	if (fork() == 0) {
		ptrace(PTRACE_TRACEME, NULL, NULL, NULL);
		execl("./ss", NULL, NULL);
		exit(-1);	/* should not get here */
	}
	int status;
	wait(status);
	printf("parent: %d\n", status);
	exit(0);
}
