#include <signal.h>
#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>

#define ERR_EXIT(m) \
	do { \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while (0)

void handler(int sig);

int main(int argc, char *argv[])
{
	struct sigaction act;
	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGQUIT);
	act.sa_flags = 0;

	if (sigaction(SIGINT, &act, NULL) < 0)
		ERR_EXIT("sigaction error");

	for (;;)
		pause();

	return 0;
}

void handler(int sig)
{
	printf("recv a sig=%d\n", sig);
	sleep(5);
}
