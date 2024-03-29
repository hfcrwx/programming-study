#include <signal.h>
#include <unistd.h>

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
	struct sigaction act;
	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	if (sigaction(SIGINT, &act, NULL) < 0)
		ERR_EXIT("sigaction error\n");

	for (;;)
		pause();

	return 0;
}

void handler(int sig)
{
	printf("recv a sig=%d\n", sig);
}
