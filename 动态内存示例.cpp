// 动态内存示例.cpp : 定义控制台应用程序的入口点。
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

	InputStudent(); //对结构体变量输入；
	OutputStudent();//对结构体变量输出；
	return 0;

}

void InputStudent(struct Student * pstu)
{

}