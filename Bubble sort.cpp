// 冒泡排序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


void sort(int *pArr,int len)
{
	int j, i, k;
	for (i = 0; i < len-1;i++)
	{
		for (j = 0; j < len-1-i; j++)
		{
			if (pArr[j] > pArr[j+1])
			{
				k = pArr[j];
				pArr[j] = pArr[j+1];
				pArr[j+1] = k;
			}

		}
	}
}



int main()
{
	int a[6] = { 10,2,8,-8,11,0 };
	int i;
	sort(a,6);
	for (i = 0; i < 6; i++)
	{
		printf("%d ", a[i]);

	}
	printf("\n");
    return 0;
}

