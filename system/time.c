/*************************************************
*
*readme
*��ȡϵͳʱ��
*
**************************************************/
#include <stdio.h>
#include <time.h>

/*struct tm {
               int tm_sec;         // seconds
               int tm_min;         // minutes
               int tm_hour;        // hours
               int tm_mday;        // day of the month 
               int tm_mon;         // month The number of months since January
               int tm_year;        // year The number of years since 1900
               int tm_wday;        // day of the week 
               int tm_yday;        // day in the year 
               int tm_isdst;       // daylight saving time 
           };
*/


int main()
{
	time_t timep;
	char *ptr;
	const struct tm *tptr;
	
	timep = time(NULL);							// ��ȡ����
	ptr = ctime(&timep);						// ����ת���ɱ�׼�ַ�����ʽ
	
	tptr = localtime(&timep);					// �����շֿ���
	ptr = asctime(tptr);						// ���ɱ�׼�ַ�����ʽ
	
	
	printf("year is:%s\n", ptr);
	
	return 1;
}