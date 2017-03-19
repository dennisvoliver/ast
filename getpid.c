#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	printf("my pid is:%d\n", getpid());
	if (fork() == 0) {
		execl("/bin/ps", "au", NULL);
		exit(-1);	/* should not get here */
	}
	wait(NULL);
	exit(0);
}
