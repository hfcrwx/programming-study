#include <muduo/base/Logging.h>
#include <errno.h>

using namespace muduo;

int main()
{
	LOG_TRACE<<"trace ...";
	LOG_DEBUG<<"debug ...";
	LOG_INFO<<"info ...";
	LOG_WARN<<"warn ...";
	LOG_ERROR<<"error ..."; // 应用级别的错误
	//LOG_FATAL<<"fatal ...";
	errno = 13;
	LOG_SYSERR<<"syserr ..."; // 系统级别的错误，日志级别和error一样
	LOG_SYSFATAL<<"sysfatal ...";
	return 0;
}
