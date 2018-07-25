#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

#define ERR_EXIT(m) \
	do { \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while (0)

int main(int argc, char *argv[])
{
	signal(SIGCHLD, SIG_IGN); // 避免僵尸进程
	printf("before fork pid = %d\n", getpid());
	pid_t pid;
	pid = fork();
	if (pid == -1)
		ERR_EXIT("fork error");

	if (pid > 0)
	{
		printf("this is parent pid=%d childpid=%d\n", getpid(), pid);
		sleep(100); // 子进程成为僵尸进程
	}
	else if (pid == 0)
	{
		printf("this is child pid=%d parentpid=%d\n", getpid(), getppid());
//		sleep(100); // 成为孤儿进程
	}
	return 0;
}
