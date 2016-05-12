/****************************************
*理论未完全理解！
*readme
*功能：设置线程数据私有化
*1.创建的key可以在多线程中使用，每个线程
*  映射结果都不同
*2.一般来说，一个变量对应一个key
*3.key的创建函数，提供一个退出函数。当线程
*  正常退出时，执行这个函数。一般来说，当动
*  态申请内存给key时，退出函数用于释放申请的
*  动态内存
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
	printf("receive %s\n", arg);											// 打印回到进程语句
	ret = pthread_setspecific(key, (void *)a);								// 数据私有化绑定
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		assert(0);
	}
	
	ptr = pthread_getspecific(key);											// 检测是否私有
	if(	NULL == ptr){
		printf("not blind!\n");
		assert(0);
	}

	while(1)																// 检验两个线程是否共享
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
	printf("receive %s\n", arg);											// 打印回到进程语句
	ret = pthread_setspecific(key, (void *)a);								// 数据私有化绑定
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		assert(0);
	}
	
	ptr = pthread_getspecific(key);											// 检测是否私有
	if(	NULL == ptr){
		printf("not blind!\n");
		assert(0);
	}
	
	while(1)																// 检验两个线程是否共享
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
	
	ret = pthread_key_create(&key, NULL);									// 创建私有key
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		assert(0);
		return -1;
	}
	
	ret = pthread_create(&uid1, NULL,  pthread1, "im new pthread1!");		// 创建线程
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		assert(0);
		return -1;
	}
	
	ret = pthread_create(&uid2, NULL,  pthread2, "im new pthread2!");		// 创建线程
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		assert(0);
		return -1;
	}

	printf("i'm main pthread!\n");
	
	while(1);																// 等待	
}