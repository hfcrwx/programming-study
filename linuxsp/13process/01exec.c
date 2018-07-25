#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("Entering main ...\n");
	execlp("ls", "ls", "-l", NULL);
	printf("Exiting main ...\n");
	return 0;
}
