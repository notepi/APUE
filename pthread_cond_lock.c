/****************************************************************
*
*readme
*���ܣ����̣߳�ȡ��������
*NOTE:��ϻ�����ʹ�õ���������
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
*pthread_cond_waitʹ�߳��˳�cpuʹ�ã��Զ��ͷŻ������������ܵ��źź�
*�Ȼ�ȡ�������������ȡ���������߳�����ʹ��cpuȨ��
*****************************************************************/

#include <stdio.h>
// ����ֿ�
	// ������
	// ��ȡλ��
	// �ձ�־
	// ����־
	// ��ȡ��������
	// д����������

void* pthread_write(void *arg)
{
	while(1)
	{
		// ��ȡ������
		// ���д���˾ͳ�Ĭ
		// д����
		// ֪ͨд��
		// �ͷŻ�����
	}
}

void* pthread_read(void *arg)
{
	// ��ȡ������
	// ������˾ͳ�Ĭ
	// ������
	// ֪ͨ����
	// �ͷŻ�����
}

int main()
{
	// ��ʼ��������
	// ��ʼ����������
	
	
	// ���ٻ�����
	// ������������
}