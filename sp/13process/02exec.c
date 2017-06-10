#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("Entering main ...\n");
	printf("pid=%d\n", getpid());
	// execlp("./hello", "hello", NULL);
	int ret = execlp("hello", "hello", NULL);
	if (ret == -1)
		perror("execlp error");
	printf("Exiting main ...\n");
	return 0;
}
