#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	struct stat buf;
	int ret;
	
	ret = stat("./a.c", &buf);						// 读取文件信息
	if(ret == 0){
		// 文件存在
		printf("file is exit!\n");
	}
	ret = unlink("./a.c");							// 删除文件
	if (ret == -1) {
		printf("Could not remove old PID-file path\n");
	}
	return 1;
}