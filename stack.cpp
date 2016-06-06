// stack.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *pNext;
}NODE, *PNODE;


typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK, *PSTACK;

void init(PSTACK);
void push(PSTACK, int);
void traverse(PSTACK);
bool pop(PSTACK, int *);
bool empt(PSTACK);
void clear(PSTACK);

int main()
{
	STACK S;   //STACK ����struct stack��
	int val;

	init(&S);
	push(&S,1);
	push(&S,2);
	push(&S, 6);
	push(&S, 3);
	push(&S, 26);
	push(&S, 45);

	traverse(&S);

	if (pop(&S, &val))
	{
		printf("��ջ��Ԫ���ǣ�%d\n", val);
	}
	else
	{
		printf("��ջʧ�ܣ�\n");

	}
	traverse(&S);
	clear(&S);
	traverse(&S);



    return 0;
}

void init(PSTACK pS)
{
	//pS = (PSTACK)malloc(sizeof(STACK));
	
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if (pS->pTop == NULL)
	{
		printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);
     }
	else
	{
		pS->pBottom = pS->pTop;
		pS->pTop->pNext = NULL;
	}
	
	return;

}

void push(PSTACK pS, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	//pS->pTop->pNext = pNew;
	//pS->pTop = pNew;
	//pNew->pNext = NULL;

	pNew->pNext = pS->pTop;
	pS->pTop = pNew;

	return;
}

void traverse(PSTACK pS)
{
	PNODE p = pS->pTop;
	while (p != pS->pBottom)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
	return;
}


bool empt(PSTACK pS)
{
	if (pS->pBottom == pS->pTop)
	{
		return true;
	}
	else
		return false;
}



bool pop(PSTACK pS, int *pVal)
{
	if (empt(pS))
		return false;
	else
	{
		PNODE r = pS->pTop;
		*pVal = r->data;
		pS->pTop = pS->pTop->pNext;
		free(r);
		r = NULL;
	}

	return true;
}

void clear(PSTACK pS)
{
	while (pS->pBottom != pS->pTop)
	{
		PNODE p = pS->pTop;
		pS->pTop = p->pNext;
		free(p);
		p = NULL; //��ֹ��ΪҰָ�룻Ȼ�����
	}
	return;
}