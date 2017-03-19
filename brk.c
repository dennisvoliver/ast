#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	intptr_t n;
	n = sbrk(0);
	printf("%lx\n", n);
	exit(0);
}
