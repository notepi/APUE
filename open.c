/*************************************************************************
*readme
*功能：文件IO操作
*NOTES:
*1.The open file description is  new,  and  therefore  the  file
*  descriptor  shall  not  share it with any other process in the system.
*2.Before  successful  return  from write(),  the  file offset shall be 
*  incremented by the number of bytes actually written. On a regular file, 
*  if this incremented  file  offset is  greater  than the length of the 
*  file, the length of the file shall be set to this file offset.
*3.read()The file offset shall be incremented by the  number of bytes actually read.
*4.open()O_APPEND If  set,  the  file  offset shall be set to the end of the file
*  prior to each write.(也就是偏移量定位到文件末尾)
*5.read，write操作不同文件描述之间互不影响
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
	int fd1, fd2;															// 文件描述符
	ssize_t	writesize;
	mode_t omask;															// 保存原始mask权限
	omask = umask(0000);													// 设置屏蔽字
	int flags = 0; 
	char *str = "hello world!";
	char *ptr = "123456789789";
	char *buf[2];
	buf[0] = str;
	buf[1] = ptr;
	char RDbuff[20];
	
	// 设置读写权限，且追加都文件结尾。
	// 如果文件不存在，就创建权限为0777的文件
	fd1 = open("./a.c", O_RDWR | O_CREAT | O_APPEND, 0777);	
	if( fd1 < 0){
		printf("errno value: %d, it means: %s\n",fd1, strerror(fd1));
		assert(0);
		return -1;
	}
	umask(omask);															// 恢复原始屏蔽字
	fd2 = open("./a.c", O_RDONLY);											// 打开文件只可读
	while(1)
	{
		if(flags){
			flags = 0;
			writesize =  write(fd1, buf[0], strlen(buf[0]));				// 写入文件
		}
		else{
			flags = 1;
			writesize =  write(fd1, buf[1], strlen(buf[1]));				// 写入文件
		}
		bzero(RDbuff, 20*sizeof(char));										// 清除缓存区
		read(fd2, RDbuff, 12*sizeof(char));									// 读取数据
		printf("read buff is:%s\n", RDbuff);
		sleep(2);															// 休眠2s
	}
	
	printf("end!\n");
	while(1);
	close(fd1);
	close(fd2);
}