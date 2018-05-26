#include <cstdio>

/************************************************************************/
/*
	�ݹ��ʵ��  1
	�����ӿ���Ҫ��쳲��������е�ʵ��
	쳲�������Ҫ�������ӵķ�ֳ��Ϊ��ʼ��������˼����Ǵӵڶ������п�ʼ
	֮���ֵ��ͨ��ǰһ����ǰ����ֵ���Ӳ�����
	������ѧ��ʽ�����ã�
		
				0			 �� n = 0;
	F(n) =      1			 �� n = 1;
			F(n-1) + F(n -2) ��n > 1;

	0     1    2    3     4    5     6     7
 	0     1    1    2     3    5     8     13
*/
/************************************************************************/
int GetFibonacciData(int which)
{
	if (which < 0)
		return -1;
	if (which < 2)
		return (which == 0) ? 0 : 1;
	else
		return GetFibonacciData(which - 1) + GetFibonacciData(which - 2);
}


/************************************************************************/
/* 
	�ݹ��ʵ�� 2
	�����ӿ���Ҫ����ʵ��һ�������ַ����������������
	���������һ���ȽϺ���Ķ�������IO����Ļ��湦��
	����ÿ������Ĳ���һ��ֵ�����ַ������ڲ�����һ�����棬����������ַ�����ÿ��
	�ַ���ͳͳ����һ�鵱ǰ�ĺ���������ַ���Ϊscanf�����ֵ
	������˼

	���磺
	���룺	ABCDE		 (��������)
	        XUHANG		 (��������)
			#			 

	չʾ��	EDCBA
			GNAHUX	
	�����ǲ����
			AX
	��Ϊ������ַ����뵽IO���뻺�����ˣ�����ͬ������õ�ǰ�ĺ���

*/
/************************************************************************/
void PrintStrReversed(char endflag)
{
	char datas;
	scanf_s("%c",&datas,1);
	if (datas != endflag)	PrintStrReversed(endflag);
	if (datas != endflag)   printf("%c", datas);
}


/************************************************************************/
/* 
	�ݹ��ʵ�� 3
	�ӿ���ʹ�÷���˼����ʵ���۰���ң������õݹ�ķ�ʽ
	����˼����Ҫ�Ǵ����С������������и��С������

	���� a[]  ���ҵ�Զ�� b
	��ȡ�м��λ�� �� b�Ƚ� ����b ����벿�ֲ���  С��b���Ұ벿�ֲ���
*/
/************************************************************************/
int FindMemberLocation(int  all[],int begin, int end,const int findone)
{
	int middle = ((end + begin) >> 1);
	if (end < begin || (end == begin) && all[end] != findone)
		return -1;
	if (all[middle] > findone)
		FindMemberLocation(all, begin, (middle - 1),findone);
	else if (all[middle] < findone)
		FindMemberLocation(all, middle + 1,end, findone);
	else
		return middle;
}


