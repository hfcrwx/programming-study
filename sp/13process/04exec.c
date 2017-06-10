#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("Entering main ...\n");
	int ret = execl("/bin/ls", "ls", "-l", NULL);
	if (ret == -1)
		perror("execl error");
	// execlp("ls", "ls", "-l", NULL);
	printf("Exiting main ...\n");
	return 0;
}
