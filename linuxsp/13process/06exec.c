#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("Entering main ...\n");
	int ret = fcntl(1, F_SETFD, FD_CLOEXEC);
	if (ret == -1)
		perror("fcntl error");

	execlp("./hello", "hello", NULL);
	printf("Exiting main ...\n");
	return 0;
}
