#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


#define DEST	stdout 


// �ض����������ԭ���������
void sys_err(char *ptr, int error)
{
	fprintf(DEST , "%s, errno value: %d, it means: %s\n", 
			ptr, error, strerror(error));
	exit(-1);
}

int main()
{
	sys_err("hello", 0);
}