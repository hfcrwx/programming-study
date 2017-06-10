#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>

void my_exit1(void)
{
	printf("my exit1 ...\n");
}

void my_exit2(void)
{
	printf("my exit2 ...\n");
}

int main(int argc, char *argv[])
{
	atexit(my_exit1);
	atexit(my_exit2);
	_exit(0); // 不会调用终止处理程序
	// exit(0);
	// return 0;
}
