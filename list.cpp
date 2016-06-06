// list.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
#include   <stdlib.h>

typedef struct Node
{
	int data;//数据域
	struct Node *pNext;//指针域
}NODE, *PNODE;

PNODE creat_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int lenth_list(PNODE);
bool insert_list(PNODE, int, int);
bool delete_list(PNODE, int, int *);
void sort_list(PNODE);


int main()
{
	PNODE pHead = NULL;  //等价于struct Node *pHead=NULL;
	pHead = creat_list();  //创建一个非循环单链表；
	traverse_list(pHead);
	sort_list(pHead);
	traverse_list(pHead);

    return 0;
}

PNODE creat_list(void)
{
	int len;
	int val;   //用于临时存储用户输入的节点的值；
	printf("请输入需要生成的链表节点的个数：len= ");
	scanf("%d", &len);

	PNODE pHead = (PNODE)malloc(sizeof(NODE));  //分配了一个不放有效数据的头结点；
	if (pHead == NULL)
	{
		printf("分配失败,程序终止\n");
		exit(-1);
	}

	PNODE pTail = pHead;
	pTail->pNext = NULL;

	for (int i = 0; i < len; i++)
	{
		
		printf("请输入第%d个节点的值：", i + 1);
		scanf("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (pNew == NULL)
		{
			printf("分配失败,程序终止\n");
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;


	}
	return pHead;
}


void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	while(p != NULL)
	{
		printf("%d  ", p->data);
		p = p->pNext;
	}
	printf("\n");

	return;
}

bool is_empty(PNODE pHead)
{
	if (pHead->pNext == NULL)
		return true;
	else
		return false;
}


int lenth_list(PNODE pHead)
{
	int i = 0;
	PNODE p = pHead->pNext;
	while (p != NULL)
	{
		i++;
		p = p->pNext;
	}

	return i;
}

void sort_list(PNODE pHead)
{
	PNODE p= pHead->pNext;
	PNODE pNe;
	int i,j;
	int t;
	int len=lenth_list(pHead);
	printf("len=%d\n", len);
	for (i = 0;i < len - 1; i++)
	{
		
		for (j = i + 1, pNe = p->pNext;j < len;j++)
		{
			
			if (p->data > pNe->data)
			{
				t = pNe->data;	
				pNe->data = p->data;
				p->data = t;
			}
			pNe = pNe->pNext;
		}
		p = p->pNext;
	}
}

bool insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;

	while (NULL != p&&i < pos - 1)
	{
		p=p->pNext;
		i++;
	}
	if (i > pos - 1 || NULL == p)
		return false;
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (pNew == NULL)
		{
			printf("动态分配内存失败！\n");
			exit(-1);
		}
		pNew->data = val;
		PNODE q = p->pNext;
		p->pNext = pNew;
		pNew->pNext = q; 
}

bool delete_list(PNODE pHead, int pos, int *pVal)
{
	int i = 0;
	PNODE p = pHead;

	while (NULL != p->pNext&&i < pos - 1)
	{
		p = p->pNext;
		i++;
	}
	if (i > pos - 1 || NULL == p->pNext)
		return false;
	
	PNODE	q = p->pNext;
	*pVal = q->data;    //
	p->pNext = p->pNext->pNext;   //删除p节点后面的节点；
	free(q);
	q = NULL;
	return true;
}