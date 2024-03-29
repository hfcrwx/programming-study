#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define ERR_EXIT(m) \
        do \
        { \
                perror(m); \
                exit(EXIT_FAILURE); \
        } while(0)

void echo_srv(int conn)
{
	char recvbuf[1024];
	int n;
	while (1)
	{
		memset(recvbuf, 0, sizeof(recvbuf));
		n = read(conn, recvbuf, sizeof(recvbuf));
		if (n == -1)
		{
			if (n == EINTR)
				continue;

			ERR_EXIT("read");
		}
		else if (n == 0)
		{
			printf("client close\n");
			break;
		}

		fputs(recvbuf, stdout);
		write(conn, recvbuf, strlen(recvbuf));
	}

	close(conn);
}

int main(void)
{
	int listenfd;
	if ((listenfd = socket(PF_UNIX, SOCK_STREAM, 0)) < 0)
		ERR_EXIT("socket");

    // 不设置地址重复利用
	unlink("/tmp/test_socket");
	struct sockaddr_un servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sun_family = AF_UNIX;
	strcpy(servaddr.sun_path, "/tmp/test_socket");
	
	if (bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
		ERR_EXIT("bind"); // 产生套接字文件

	if (listen(listenfd, SOMAXCONN) < 0)
		ERR_EXIT("listen");

	int conn;
	pid_t pid;
	while (1)
	{
		conn = accept(listenfd, NULL, NULL);
		if (conn == -1)
		{
			if (conn == EINTR)
				continue;
			ERR_EXIT("accept");
		}

		pid = fork();
		if (pid == -1)
			ERR_EXIT("fork");

		if (pid == 0)
		{
			close(listenfd);
			echo_srv(conn);
			exit(EXIT_SUCCESS);
		}

		close(conn);
		
	}
	return 0;
}
