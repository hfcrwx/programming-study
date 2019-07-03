// #include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

/*
#define ERR_EXIT(m) (perror(m), exit(EXIT_FAILURE)) // 因为宏不能用两条语句，所以用逗号表达式
*/

#define ERR_EXIT(m) \
	do \
	{ \
		perror(m); \
		exit(EXIT_FAILURE); \
    } while(0) // do-while是一条语句

int main(void)
{
	int fd;
	fd = open("test.txt", O_RDONLY);
/*
	if (fd == -1)
	{
		fprintf(stderr, "open error with errno=%d %s\n", errno, strerror(errno));
		exit(EXIT_FAILURE);
	}
*/
/*
	if (fd == -1)
	{
		perror("open error");
		exit(EXIT_FAILURE);
	}
*/
	if (fd == -1)
		ERR_EXIT("open error");

	printf("open succ\n");
	return 0;
}
