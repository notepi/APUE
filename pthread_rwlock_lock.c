/*************************************************************************
*readme
*功能：获取退出码
*NOTES:
*1.只要没有线程没有持有某个给定的读写锁用于写，那么任意数目的线程可以持有
*  该读写锁用于读
*2. 仅当没有线程持有某个给定的读写锁用于读或者写时，才能分配该读写锁用于写
*问题：并不能保证那个线程先运行
*
***************************************************************************/
/*
*读写内存时，保护内存更合适
*/ 
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

pthread_rwlock_t rwlock;
char buff[100];													// 共享内存


void *pthread_write(void *arg)
{
	
	while(1)
	{
		pthread_rwlock_wrlock(&rwlock);							// 写入锁
		bzero(buff, 100*sizeof(char));							// 清空缓存区
		printf("please input!\n");
		fgets(buff, 100*sizeof(char), stdin);					// 从标准输入读取要写入的数据
		pthread_rwlock_unlock(&rwlock);							// 释放锁
		sleep(1);												// 释放资源
	}
}

void *pthread_read1(void *arg) 
{
	pthread_t	c_uid;
	c_uid = pthread_self();	
	printf("%u\n", c_uid);
	sleep(1);													// 等待写进程先运行
	while(1)
	{
		pthread_rwlock_rdlock(&rwlock);							// 读取锁
		printf("%u:%s", c_uid, buff);
		pthread_rwlock_unlock(&rwlock);							// 释放锁
		sleep(2);												// 释放资源
	}

}

void *pthread_read2(void *arg)
{
	pthread_t	c_uid;
	c_uid = pthread_self();	
	printf("%u\n", c_uid);
	sleep(1);													// 等待写进程先运行
	while(1)
	{
		pthread_rwlock_rdlock(&rwlock);							// 读取锁
		printf("%u:%s", c_uid, buff);
		pthread_rwlock_unlock(&rwlock);							// 释放锁
		sleep(2);												// 释放资源
	}

}

void *pthread_read3(void *arg)
{
	pthread_t	c_uid;
	c_uid = pthread_self();	
	printf("%u\n", c_uid);
	sleep(1);													// 等待写进程先运行
	while(1)
	{
		pthread_rwlock_rdlock(&rwlock);							// 读取锁
		printf("%u:%s", c_uid, buff);
		pthread_rwlock_unlock(&rwlock);							// 释放锁
		sleep(2);												// 释放资源
	}

}



int  main()
{
	int ret;
	pthread_t	uid1, uid2, uid3, uid4;
	ret = pthread_rwlock_init(&rwlock, NULL);									// 创建读写锁
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		assert(0);
		return -1;
	}
	
	// 创建信号量(个数与线程数相同)
	
	ret = pthread_create(&uid1, NULL,  pthread_write, "im new pthread!");		// 创建线程
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		assert(0);
		return -1;
	}
	
	ret = pthread_create(&uid2, NULL,  pthread_read1, "im new pthread!");		// 创建线程
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		assert(0);
		return -1;
	}
	
	ret = pthread_create(&uid3, NULL,  pthread_read2, "im new pthread!");		// 创建线程
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		assert(0);
		return -1;
	}
	
	ret = pthread_create(&uid4, NULL,  pthread_read3, "im new pthread!");		// 创建线程
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		assert(0);
		return -1;
	}
	
	while(1);																	// 避免进程退出
	
	ret = pthread_rwlock_destroy(&rwlock);										// 销毁读写锁
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		assert(0);
		return -1;
	}
	
}