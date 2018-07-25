#include <arpa/inet.h>
#include <stdio.h>

int main(void)
{
    unsigned int x = 0x12345678; // 1个16进制位=4个2进制位=0.5个字节
    printf("x = %x\n", x);
    unsigned char* p = (unsigned char*)&x;
    printf("%0x %0x %0x %0x\n", p[0], p[1], p[2], p[3]);

    unsigned int y = htonl(x);
    printf("y = %x\n", y);
    p = (unsigned char*)&y;
    printf("%0x %0x %0x %0x\n", p[0], p[1], p[2], p[3]);

    return 0;
}
