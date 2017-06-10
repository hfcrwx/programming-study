#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	char* const envp[] = { "AA=11", "BB=22", NULL };
	printf("Entering main ...\n");
	// execl("./hello", "hello", NULL);
	execle("./hello", "hello", NULL, envp);
	printf("Exiting main ...\n");
	return 0;
}
