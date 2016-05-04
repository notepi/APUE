/****************************************
*
*readme
*功能：子进程接收父进程发来的信号，
*子进程接收并处理信号
*
****************************************/
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>


void func(int sig)
{
	printf("receive signal is:%d\n", sig);
}

void *pthread1(void *arg)
{
	struct sigaction act;
    memset(&act, 0x0, sizeof(act));
    act.sa_handler = func;
    sigaction(SIGUSR1, &act, NULL);											// 注册信号处理函数
	
	pause();																// 挂起等待信号
	
	printf("receive %s\n", arg);											// 打印回到进程语句
}


int main()
{
	pthread_t	uid1;
	int ret;
	
	ret = pthread_create(&uid1, NULL,  pthread1, "im new pthread!");		// 创建线程
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		assert(0);
		return -1;
	}
	sleep(10);																// 等待子线程就绪
	pthread_kill(uid1, SIGUSR1);											// 给子线程发送信号
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		assert(0);
		return -1;
	}
	
	while(1);																// 等待	
}