//
// Created by NianLee on 2023/5/17.
//

#include "../Inc/findStudentGradeInform.h"

/************************************************
 * @Function: findStudentGradeInformByStudent
 * @Description: 通过学生姓名或学号查找学生成绩信息,包括姓名、课名、成绩
 * @Input: None
 * @Output: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void findStudentGradeInformByStudent(void)
{
	char findInform[20];
	int i, j;
	int count = 0;
	printf("请输入要查找的学生的姓名或学号: ");
	scanf("%s", findInform);
	for (j = 0; j < studentNum; j++)
	{
		if (strcmp(studentBaseInformation[j].name, findInform) == 0)
			break;
		if (strcmp(studentBaseInformation[j].number, findInform) == 0)
		{
			strcpy(findInform, studentBaseInformation[j].name);
			break;
		}
	}
	for (i = 0; i < studentGradeNum; i++)
	{
		if (strcmp(studentGradeInformation[i].studentName, findInform) == 0)
		{
			count++;
			if (count == 1)
			{
				printf("\n姓名: %s\n", studentGradeInformation[i].studentName);
				printf("学号: %s\n", studentBaseInformation[j].number);
			}
			printf("课名: %-15s", studentGradeInformation[i].courseName);
			printf("成绩: %-8s", studentGradeInformation[i].grade);
			printf("绩点: %.2f\n", studentGradeInformation[i].GPA);
		}
	}
	if (count == 0)
		printf("\n未找到该学生成绩信息!\n");
}

/************************************************
 * @Function: findStudentGradeInformByCourse
 * @Description: 通过课程课名或课号查找学生成绩信息,包括课名、课号、姓名、成绩
 * @Input: None
 * @Output: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void findStudentGradeInformByCourse(void)
{
	char findInform[20];
	int i, j;
	int count = 0;
	printf("请输入要查找的课程的课名或课号: ");
	scanf("%s", findInform);
	for (j = 0; j < courseNum; j++)
	{
		if (strcmp(courseBaseInformation[j].name, findInform) == 0)
			break;
		if (strcmp(courseBaseInformation[j].number, findInform) == 0)
		{
			strcpy(findInform, courseBaseInformation[j].name);
			break;
		}
	}
	for (i = 0; i < studentGradeNum; i++)
	{
		if (strcmp(studentGradeInformation[i].courseName, findInform) == 0)
		{
			count++;
			if (count == 1)
			{
				printf("\n课名: %s\n", studentGradeInformation[i].courseName);
				printf("课号: %s\n", courseBaseInformation[j].number);
			}
			printf("姓名: %-10s", studentGradeInformation[i].studentName);
			printf("成绩: %-8s", studentGradeInformation[i].grade);
			printf("绩点: %.2f\n", studentGradeInformation[i].GPA);
		}
	}
	if (count == 0)
		printf("\n未找到该课程成绩信息!\n");
}
