/****************************************
*����δ��ȫ��⣡
*readme
*���ܣ������߳�����˽�л�
*1.������key�����ڶ��߳���ʹ�ã�ÿ���߳�
*  ӳ��������ͬ
*2.һ����˵��һ��������Ӧһ��key
*3.key�Ĵ����������ṩһ���˳����������߳�
*  �����˳�ʱ��ִ�����������һ����˵������
*  ̬�����ڴ��keyʱ���˳����������ͷ������
*  ��̬�ڴ�
*4.
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
pthread_key_t key;

int a;
void *pthread1(void *arg)
{	
	int ret;
	int * ptr ; 
	printf("receive %s\n", arg);											// ��ӡ�ص��������
	ret = pthread_setspecific(key, (void *)a);								// ����˽�л���
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		assert(0);
	}
	
	ptr = pthread_getspecific(key);											// ����Ƿ�˽��
	if(	NULL == ptr){
		printf("not blind!\n");
		assert(0);
	}

	while(1)																// ���������߳��Ƿ���
	{
		a += 10;
		printf("pthread1 the value of a is:%d\n", pthread_getspecific(key));
		sleep(5);
	}
	return (void *)1;
}
void *pthread2(void *arg)
{	
	int ret;
	int * ptr ; 
	printf("receive %s\n", arg);											// ��ӡ�ص��������
	ret = pthread_setspecific(key, (void *)a);								// ����˽�л���
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		assert(0);
	}
	
	ptr = pthread_getspecific(key);											// ����Ƿ�˽��
	if(	NULL == ptr){
		printf("not blind!\n");
		assert(0);
	}
	
	while(1)																// ���������߳��Ƿ���
	{
		a += 2;
		printf("pthread2 the value of a is:%d\n", pthread_getspecific(key));
		sleep(5);
	}
	
	return (void *)1;
}

int main()
{
	pthread_t	uid1, uid2;
	int ret;
	
	ret = pthread_key_create(&key, NULL);									// ����˽��key
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		assert(0);
		return -1;
	}
	
	ret = pthread_create(&uid1, NULL,  pthread1, "im new pthread1!");		// �����߳�
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		assert(0);
		return -1;
	}
	
	ret = pthread_create(&uid2, NULL,  pthread2, "im new pthread2!");		// �����߳�
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		assert(0);
		return -1;
	}

	printf("i'm main pthread!\n");
	
	while(1);																// �ȴ�	
}