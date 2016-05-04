/****************************************
*
*readme
*���ܣ��ӽ��̽��ո����̷������źţ�
*�ӽ��̽��ղ������ź�
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
    sigaction(SIGUSR1, &act, NULL);											// ע���źŴ�����
	
	pause();																// ����ȴ��ź�
	
	printf("receive %s\n", arg);											// ��ӡ�ص��������
}


int main()
{
	pthread_t	uid1;
	int ret;
	
	ret = pthread_create(&uid1, NULL,  pthread1, "im new pthread!");		// �����߳�
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		assert(0);
		return -1;
	}
	sleep(10);																// �ȴ����߳̾���
	pthread_kill(uid1, SIGUSR1);											// �����̷߳����ź�
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		assert(0);
		return -1;
	}
	
	while(1);																// �ȴ�	
}