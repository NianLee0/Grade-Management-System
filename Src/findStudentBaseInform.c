//
// Created by NianLee on 2023/5/14.
//

#include "../Inc/findStudentBaseInform.h"

/************************************************
 * @Function: findStudentBaseInform
 * @Description: 查找学生基本信息,包括姓名,性别,年龄,学号
 * @Input: None
 * @Output: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void findStudentBaseInform(void)
{
	char findInform[20];
	int i;
	printf("请输入要查找的学生的姓名或学号: ");
	scanf("%s", findInform);
	for (i = 0; i < studentNum; i++)
	{
		if (strcmp(studentBaseInformation[i].name, findInform) == 0 ||
			strcmp(studentBaseInformation[i].number, findInform) == 0)
		{
			printf("\n姓名: %s\n", studentBaseInformation[i].name);
			printf("性别: %s\n", studentBaseInformation[i].sex);
			printf("年龄: %s\n", studentBaseInformation[i].age);
			printf("学号: %s\n\n", studentBaseInformation[i].number);
			break;
		}
	}
	if (i == studentNum)
		printf("\n未找到该学生!\n\n");
}
