// 循环队列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>





typedef struct Queue
{
	int *pBase;
	int front;
	int rear;
}QUEUE;


void init(QUEUE *);
bool en_queue(QUEUE *, int);
void  travsere_queue(QUEUE *);
bool full(QUEUE *);
bool emput_queue(QUEUE *);
bool out_queue(QUEUE *, int *);


int main()
{
	QUEUE Q;
	int val;
	init(&Q);
	en_queue(&Q, 2);
	en_queue(&Q, 4);
	en_queue(&Q, 3);
	en_queue(&Q, 5);
	en_queue(&Q, 1);
	travsere_queue(&Q);
	out_queue(&Q, &val);
	travsere_queue(&Q);
    return 0;
}

bool full(QUEUE *pQ)
{
	if ((pQ->rear + 1) % 6 == pQ->front)
		return true;
	else
		return false;

}

void init(QUEUE *pQ)
{
	pQ->pBase = (int *)malloc(sizeof(int)*6);
	pQ->front = 0;
	pQ->rear = 0;

	return;
}

bool en_queue(QUEUE *pQ, int val)
{
	if (full(pQ))
		return false;
	else
	{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear + 1) % 6;
		return true;
	}
	
}

void  travsere_queue(QUEUE *pQ)
{
	int i = pQ->front;
	while (i != pQ->rear)
	{
		printf("%d  ", pQ->pBase[i]);
		i = (i + 1) % 6;
	}
	printf("\n");
	return;
}

bool emput_queue(QUEUE *pQ)
{
	if (pQ->rear == pQ->front)
		return true;
	else
		return false;
	
}


bool out_queue(QUEUE *pQ, int *pVal)
{
	if (emput_queue(pQ))
		return false;
	else
	{
		*pVal = pQ->pBase[pQ->front];
		pQ->front = ( pQ->front + 1) % 6;

		return true;
	}

}