#include <unistd.h>

#include <stdio.h>

int main(int argc, char* argv[])
{
	fork();
	fork();
	fork();
	printf("ok\n");
	return 0;
}
