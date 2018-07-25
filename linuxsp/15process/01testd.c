#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>

#define ERR_EXIT(m) \
	do { \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while (0)

int setup_daemon(int nochdir, int noclose);

int main(int argc, char* argv[])
{
	setup_daemon(0, 0);
	// daemon(1, 1);
	printf("test ...\n");
	for (;;) ;
	return 0;
}

int setup_daemon(int nochdir, int noclose)
{
	pid_t pid;
	pid = fork();
	if (pid == -1)
		ERR_EXIT("fork error");

	if (pid > 0)
		exit(EXIT_SUCCESS);

	setsid();
	if (nochdir == 0)
		chdir("/");
	if (noclose == 0) {
		int i;
		for (i = 0; i < 3; ++i)
			close(i);
		open("/dev/null", O_RDWR); // 0
		dup(0); // 1
		dup(0); // 2
	}

	return 0;
}
