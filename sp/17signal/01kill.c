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
	if (signal(SIGUSR1, handler) == SIG_ERR)
		ERR_EXIT("signal error");

	pid_t pid = fork();
	if (pid == -1)
		ERR_EXIT("fork error");

	if (pid == 0) {
		kill(getppid(), SIGUSR1);
		exit(EXIT_SUCCESS);
	}

	int n = 5;
	do {
		n = sleep(n); // sleep会被信号打断而返回剩余时间
	} while (n > 0);

	return 0;
}

void handler(int sig)
{
	printf("recv a sig=%d\n", sig);
}
