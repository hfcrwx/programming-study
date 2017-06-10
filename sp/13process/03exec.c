#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	char* const args[] = { "ls", "-l", NULL };
	printf("Entering main ...\n");
	// execlp("ls", "ls", "-l", NULL);
	execvp("ls", args);
	printf("Exiting main ...\n");
	return 0;
}
