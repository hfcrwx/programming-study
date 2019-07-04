#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ERR_EXIT(m) \
	do \
	{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while(0)

int main(int argc, char *argv[])
{
	int fd;
	fd = open("test2.txt", O_WRONLY);
	if (fd == -1)
		ERR_EXIT("open error");

/*
	close(1);
    dup(fd); // 关闭了1, 返回文件描述符1；否则返回fd+1
*/
	dup2(fd, 1);
	printf("hello\n");
	return 0;
}
