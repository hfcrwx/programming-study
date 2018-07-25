#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
	mkfifo("p2", 0644);
	return 0;
}
