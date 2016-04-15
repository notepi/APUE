#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

void * NEW_Pthread(void *arg)
{
	int cuid;
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);		// ����ر��߳�
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);		// ����ȡ����ر��߳�
	printf("receive:%s\n", arg);
	cuid = pthread_self();										// ��ȡ�߳�ID
	printf("uid is:%u\n", cuid);
	sleep(2);
	printf("message 1!\n");
	printf("message 2!\n");
	pthread_exit((void *)1);
}

int main()
{
	
	pthread_t	uid, c_uid;
	pid_t		pid;	
	int ret;
	void *retval;
	
	pid = getpid();												// ��ȡ����ID
	c_uid = pthread_self();										// ��ȡ�߳�ID
	printf("pid is:%u\n", pid);
	printf("c_uid is:%u\n", c_uid);
	
	ret = pthread_create(&uid, NULL,  NEW_Pthread, "im new pthread!");
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		return 0;
	}
	
	ret = pthread_cancel(uid);
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		return 0;
	}
	
	ret = pthread_join(uid, &retval);
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		return 0;
	}
	printf("New pthread return:%d!\n", (int *)retval);
	
	sleep(3);
	printf("im main pthread!\n");
	return 0;
}