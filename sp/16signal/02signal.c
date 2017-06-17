#include <signal.h>

#include <stdio.h>
#include <stdlib.h>

#define ERR_EXIT(m) \
	do { \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while (0)

void handler(int sig);

int main(int argc, char* argv[])
{
	__sighandler_t oldhandler;
	oldhandler = signal(SIGINT, handler);
	if (oldhandler == SIG_ERR)
		ERR_EXIT("signal error");

	while (getchar() != '\n')
		;
	/*
	if (signal(SIGINT, oldhandler) == SIG_ERR)
	*/
	if (signal(SIGINT, SIG_DFL) == SIG_ERR)
		ERR_EXIT("signal error");
	for (;;)
        ;

	return 0;
}

void handler(int sig)
{
	printf("recv a sig=%d\n", sig);
}
