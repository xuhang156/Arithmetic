#include <cstdio>

/************************************************************************/
/*
	递归的实现  1
	函数接口主要是斐波那契数列的实现
	斐波那契主要是以兔子的繁殖作为开始，讲述的思想就是从第二个数列开始
	之后的值是通过前一个和前两个值叠加产出的
	对于数学公式可以用：
		
				0			 当 n = 0;
	F(n) =      1			 当 n = 1;
			F(n-1) + F(n -2) 当n > 1;

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
	递归的实现 2
	函数接口主要是用实现一个输入字符串逆序输出的用例
	在这里会有一个比较好玩的东西就是IO输入的缓存功能
	假设每次输入的不是一个值而是字符串，内部会做一个缓存，将你输入的字符串中每个
	字符都统统调用一遍当前的函数，这个字符作为scanf输入的值
	很有意思

	例如：
	输入：	ABCDE		 (连续输入)
	        XUHANG		 (连续输入)
			#			 

	展示：	EDCBA
			GNAHUX	
	而并非猜想的
			AX
	因为后序的字符加入到IO输入缓存中了，他们同样会调用当前的函数

*/
/************************************************************************/
void PrintStrReversed(char endflag)
{
	char datas;
	scanf_s("%c",&datas,1);
	if (datas != endflag)	PrintStrReversed(endflag);
	if (datas != endflag)   printf("%c", datas);
}
