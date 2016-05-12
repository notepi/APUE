/****************************************************************
*
*readme
*功能：多线程，取消，分离
*NOTE:配合互斥锁使用的条件变量
*1.pthread_cond_wait: pthread_cond_wait atomically unlocks the
* mutex (as perpthread_unlock_mutex) and waits for the condition
*variable cond to be signaled. The thread execution is suspended  
*and does not consume any CPU time until the condition variable 
*is signaled. The mutex must be locked by the calling thread on 
*entrance to pthread_cond_wait. Before returning to the calling 
*thread, pthread_cond_wait re-acquires mutex (as per pthread_lock_mutex).
*	Unlocking the mutex and suspending on the condition variable 
*is done atomically. Thus, if all threads always acquire the mutex 
*before signaling the condition, this guarantees that the condition 
*cannot be signaled (and thus ignored) between the time a thread 
*locks the mutex and the time it waits on the condition variable.
*pthread_cond_wait使线程退出cpu使用，自动释放互斥锁。当接受到信号后
*先获取互斥锁。如果获取互斥锁，线程重新使用cpu权限
*****************************************************************/

#include <stdio.h>
// 定义仓库
	// 缓存区
	// 读取位置
	// 空标志
	// 满标志
	// 读取条件变量
	// 写入条件变量

void* pthread_write(void *arg)
{
	while(1)
	{
		// 获取互斥锁
		// 如果写满了就沉默
		// 写数据
		// 通知写好
		// 释放互斥锁
	}
}

void* pthread_read(void *arg)
{
	// 获取互斥锁
	// 如果空了就沉默
	// 读数据
	// 通知读好
	// 释放互斥锁
}

int main()
{
	// 初始化互斥量
	// 初始化条件变量
	
	
	// 销毁互斥量
	// 销毁条件变量
}