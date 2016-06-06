// ��ŵ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>


void Hanoi(int n, char A, char B, char C)
{
	if (n == 1)         //�����1��
		printf("����%d��%c->%c\n",n,A,C);          //ֱ�ӽ�A�����ϵ����Ӵ�A�Ƶ�C��
	else
	{
		Hanoi(n - 1, A, C, B);                    //��A�����ϵ�n-1�����ӽ���C�Ƶ�B��
		printf("����%d��%c->%c\n", n, A, C);               //ֱ�ӽ�A���ӵ����Ӵ�A�Ƶ�C��
		Hanoi(n - 1, B, A, C);         //��B�����ϵ�n-1�����ӽ���A�Ƶ�C��
	}

		return;
}



int main()
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;

	printf("������Ҫ�ƶ����ӵĸ�����");
	scanf("%d",&n);

	Hanoi(n, 'A', 'B', 'C');



    return 0;
}

