#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	printf("hello world"); // 没有\n，printf不会自动清除缓冲区的
	// fflush(stdout); // 及时清空缓冲区
	//  _exit(0); // 不清除缓冲区
	exit(0); // 程序结束时清除缓冲区
	// return 0; // 程序结束时清除缓冲区
}
