// 汉诺塔.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>


void Hanoi(int n, char A, char B, char C)
{
	if (n == 1)         //如果是1，
		printf("盘子%d，%c->%c\n",n,A,C);          //直接将A柱子上的盘子从A移到C；
	else
	{
		Hanoi(n - 1, A, C, B);                    //将A柱子上的n-1个盘子借助C移到B；
		printf("盘子%d，%c->%c\n", n, A, C);               //直接将A柱子的盘子从A移到C；
		Hanoi(n - 1, B, A, C);         //将B柱子上的n-1个盘子借助A移到C；
	}

		return;
}



int main()
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;

	printf("请输入要移动盘子的个数：");
	scanf("%d",&n);

	Hanoi(n, 'A', 'B', 'C');



    return 0;
}

