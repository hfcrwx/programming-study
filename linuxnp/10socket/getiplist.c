#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define ERR_EXIT(m) \
        do { \
            perror(m); \
            exit(EXIT_FAILURE); \
        } while (0)

int getlocalip(char* ip)
{
    char host[100] = { 0 };
    if (gethostname(host, sizeof(host)) < 0)
        return -1;
    struct hostent *hp;
    if ((hp = gethostbyname(host)) == NULL)
        return -1;

//    strcpy(ip, inet_ntoa(*(struct in_addr*)hp->h_addr_list[0]));
    strcpy(ip, inet_ntoa(*(struct in_addr*)hp->h_addr));
    return 0;
}

int main(void)
{
    char host[100] = { 0 };
    if (gethostname(host, sizeof(host)) < 0)
        ERR_EXIT("gethostname");

    printf("%s\n", host);

    struct hostent* hp;
    if ((hp = gethostbyname(host)) == NULL)
        ERR_EXIT("gethostbyname");

    int i = 0;
    while (hp->h_addr_list[i] != NULL) {
        printf("%s\n", inet_ntoa(*(struct in_addr*)hp->h_addr_list[i]));
        i++;
    }

    char ip[16] = { 0 };
    getlocalip(ip);
    printf("localip = %s\n", ip);

    return 0;
}
