#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

void Pthread1_fun(int i)
{
	printf("Pthread1 recrive signal\n");
}

void * NEW_Pthread1()
{
	int err;
	struct sigaction act;
	bzero(&act, sizeof(act));		
	act.sa_handler = 
	err = sigaction(SIGUSR1, Pthread1_fun, NULL);
}


int main()
{
	int ret;
	pthread_t	uid, c_uid;
	ret = pthread_create(&uid, NULL,  NEW_Pthread1, NULL);
	if( 0 != ret){
		printf("errno value: %d, it means: %s\n",ret, strerror(ret));
		return 0;
	}
	
	
	
}