#include <signal.h>
#include <sys/types.h>
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
	if (signal(SIGINT, handler) == SIG_ERR)
		ERR_EXIT("signal error");

	for (; ;) {
		pause();
		printf("pause return\n");
	}

	return 0;
}

void handler(int sig)
{
	printf("recv a sig=%d\n", sig);
	sleep(1);
}
