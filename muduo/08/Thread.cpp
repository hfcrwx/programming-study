#include "Thread.h"
#include <iostream>
using namespace std;


Thread::Thread() : autoDelete_(false)
{
	cout<<"Thread ..."<<endl;
}

Thread::~Thread()
{
	cout<<"~Thread ..."<<endl;
}

void Thread::Start()
{
//     Run是普通的成员函数，隐含的第一个参数是Thread*（this），调用的时候是thiscall约定，某个寄存器会保存this指针。不能做为入口函数。
//     __start_routine是普通的函数
	pthread_create(&threadId_, NULL, ThreadRoutine, this);
}

void Thread::Join()
{
	pthread_join(threadId_, NULL);
}

void* Thread::ThreadRoutine(void* arg)
{
	Thread* thread = static_cast<Thread*>(arg); // 基类指针指向派生类对象
	thread->Run(); //静态成员函数不能直接调用非静态成员函数，这里传入了this指针
	if (thread->autoDelete_)
		delete thread;
	return NULL;
}

void Thread::SetAutoDelete(bool autoDelete)
{
	autoDelete_ = autoDelete;
}
