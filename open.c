/*************************************************************************
*readme
*���ܣ��ļ�IO����
*NOTES:
*1.The open file description is  new,  and  therefore  the  file
*  descriptor  shall  not  share it with any other process in the system.
*2.Before  successful  return  from write(),  the  file offset shall be 
*  incremented by the number of bytes actually written. On a regular file, 
*  if this incremented  file  offset is  greater  than the length of the 
*  file, the length of the file shall be set to this file offset.
*3.read()The file offset shall be incremented by the  number of bytes actually read.
*4.open()O_APPEND If  set,  the  file  offset shall be set to the end of the file
*  prior to each write.(Ҳ����ƫ������λ���ļ�ĩβ)
*5.read��write������ͬ�ļ�����֮�以��Ӱ��
*
*
*
***************************************************************************/
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int fd1, fd2;															// �ļ�������
	ssize_t	writesize;
	mode_t omask;															// ����ԭʼmaskȨ��
	omask = umask(0000);													// ����������
	int flags = 0; 
	char *str = "hello world!";
	char *ptr = "123456789789";
	char *buf[2];
	buf[0] = str;
	buf[1] = ptr;
	char RDbuff[20];
	
	// ���ö�дȨ�ޣ���׷�Ӷ��ļ���β��
	// ����ļ������ڣ��ʹ���Ȩ��Ϊ0777���ļ�
	fd1 = open("./a.c", O_RDWR | O_CREAT | O_APPEND, 0777);	
	if( fd1 < 0){
		printf("errno value: %d, it means: %s\n",fd1, strerror(fd1));
		assert(0);
		return -1;
	}
	umask(omask);															// �ָ�ԭʼ������
	fd2 = open("./a.c", O_RDONLY);											// ���ļ�ֻ�ɶ�
	while(1)
	{
		if(flags){
			flags = 0;
			writesize =  write(fd1, buf[0], strlen(buf[0]));				// д���ļ�
		}
		else{
			flags = 1;
			writesize =  write(fd1, buf[1], strlen(buf[1]));				// д���ļ�
		}
		bzero(RDbuff, 20*sizeof(char));										// ���������
		read(fd2, RDbuff, 12*sizeof(char));									// ��ȡ����
		printf("read buff is:%s\n", RDbuff);
		sleep(2);															// ����2s
	}
	
	printf("end!\n");
	while(1);
	close(fd1);
	close(fd2);
}