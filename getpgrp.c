#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	printf("my pgrp is:%d\n", getpgrp());
	if (fork() == 0) {
		execl("./ss", NULL, NULL);
		exit(-1);	/* should not get here */
	}
	wait(NULL);
	exit(0);
}
