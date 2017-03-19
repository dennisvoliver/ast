#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	if (fork() == 0) {
	printf("my sid is:%d\n", setsid());
		execl("./ss", NULL, NULL);
		exit(-1);	/* should not get here */
	}
	wait(NULL);
	exit(0);
}
