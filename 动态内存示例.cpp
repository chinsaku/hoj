// ��̬�ڴ�ʾ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>

struct Student
{
	int age;
	float score;
	char sex;

};


int main()
{
	struct Student st;

	InputStudent(); //�Խṹ��������룻
	OutputStudent();//�Խṹ����������
	return 0;

}

void InputStudent(struct Student * pstu)
{

}