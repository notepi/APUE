#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	struct stat buf;
	int ret;
	
	ret = stat("./a.c", &buf);						// ��ȡ�ļ���Ϣ
	if(ret == 0){
		// �ļ�����
		printf("file is exit!\n");
	}
	ret = unlink("./a.c");							// ɾ���ļ�
	if (ret == -1) {
		printf("Could not remove old PID-file path\n");
	}
	return 1;
}