// Arr.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>

struct Arr
{
	int * pBase;  // 储存的是数组第一个元素地址
	int len;  //数组所能容纳的最大元素的个数
	int cnt;  // 当前数组有效元素个数
};


void init_arr(struct Arr *pArr,int length);
bool append_arr(struct Arr *pArr,int val);  //追加

bool insert_arr(struct Arr *pArr,int pos, int val); //pos的值从1开始
bool delete_arr(struct Arr *pArr, int pos,int *pVal);
int get();
bool is_empty(struct Arr *pArr);
bool is_full(struct Arr *pArr);

void sort_arr(struct Arr *pArr);
void show_arr(struct Arr *pArr);
void inversion_arr(struct Arr *pArr);

int main()
{
	struct Arr arr;
	//int val;
	init_arr(&arr,6);
    append_arr(&arr,5);
	append_arr(&arr,4);
    append_arr(&arr,3);
	append_arr(&arr,2);
	append_arr(&arr, 1);
	show_arr(&arr);
	sort_arr(&arr);
	show_arr(&arr);
	/*if (delete_arr(&arr, 1, &val))
	{
		printf("删除成功\n");
		printf("删除元素为%d\n", val);
	}
	else
		printf("删除失败\n");
	printf("cnt=%d\n",arr.cnt);
	printf("%d %d %d %d\n", arr.pBase[0], arr.pBase[1], arr.pBase[2], arr.pBase[3]);
	show_arr(&arr);
	show_arr(&arr);
	
	
	//printf("%d\n", arr.len);
    return 0;
	*/
}

void init_arr(struct Arr *pArr,int length)
{
	pArr->pBase = (int *)malloc(sizeof(int)*length);
	if (NULL == pArr->pBase)
	{
		printf("动态内存分配失败!\n");
		exit(-1);
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;

	}
	return;
}

bool is_empty(struct Arr *pArr)
{
	if (pArr->cnt == 0)
		return true;
	else
		return false;

}

bool is_full(struct Arr *pArr)
{
	if (pArr->len == pArr->cnt)
		return true;
	else
		return false;
}

void show_arr(struct Arr *pArr)
{
	if (is_empty(pArr))
		printf("数组为空!\n");
	else
	{
		for (int i = 0; i < pArr->cnt; i++)
			printf("%d ",pArr->pBase[i]);
	}
/*	if(数组为空)
		提示数组为空
	else
		输出数组有效内容
*/	

}

bool append_arr(struct Arr *pArr, int val)
{
	if (is_full(pArr))   //满的时候返回false
		return false;
	else
	{
		pArr->pBase[pArr->cnt] = val;
		pArr->cnt++;
		return true;
	}
}	

bool insert_arr(struct Arr *pArr, int pos, int val)
{
	int i;
	if (is_full(pArr))   //满的时候返回false
		return false;
	
	if (pos<1 || pos>pArr->cnt+1)
		return false;
	
    for (i = pArr->cnt-1; i >= pos-1; i--)
			{
				pArr->pBase[i + 1] = pArr->pBase[i];
			}
			pArr->pBase[pos - 1] = val;
			pArr->cnt++;
			return true;
	
}

bool delete_arr(struct Arr *pArr, int pos, int *pVal)
{
	int i;
	if (is_empty(pArr))
		return false;
	if (pos<1 || pos>pArr->cnt)
		return false;

	*pVal = pArr->pBase[pos - 1];
	for (i = pos; i < pArr->cnt; i++)
	{
		pArr->pBase[i - 1] = pArr->pBase[i];
	}
	pArr->cnt--;
	return true;
}


void inversion_arr(struct Arr *pArr)
{
	int i = 0;
	int t;
	int q = pArr->cnt - 1;
	while(i < q)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[q];
		pArr->pBase[q] = t;
		i++;
		q--;

	}

}

void sort_arr(struct Arr *pArr)
{
	int i, j;
	int t;
	for (i = 0; i < pArr->cnt-1; i++)
	{
		for (j = 0; j < pArr->cnt -1- i; j++)
		{
			if (pArr->pBase[j] > pArr->pBase[j + 1])
			{
				t = pArr->pBase[j];
				pArr->pBase[j] = pArr->pBase[j + 1];
				pArr->pBase[j + 1] = t;
			}
		}
	}
}