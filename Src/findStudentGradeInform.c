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
	int page = 1;
	float temp1 = 0;
	float temp2 = 0;
	float sumCredit = 0;
	int count1;
	int count2 = 0;
	int target[100][2];
	int k;
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
nextPage:
	k = 0;
	count1 = 0;
	for (i = 0; i < studentGradeNum; i++)
	{
		if (strcmp(studentGradeInformation[i].studentName, findInform) == 0)
		{
			count1++;
			if (count1 == 1)
			{
				system("cls");
				printf("姓名: %s\n", studentGradeInformation[i].studentName);
				printf("学号: %s\n", studentBaseInformation[j].number);
				printf("性别: %s\n", studentBaseInformation[j].sex);
				printf("年龄: %s\n\n", studentBaseInformation[j].age);
			}
			target[k++][0] = i;
			target[k][0] = -1;
		}
	}
	if (count1 == 0)
		printf("\n未找到该学生成绩信息!\n");
	else
	{
		printf("*****************************************************************\n\n");
		sortCourse(target);
		for (i = count2; target[i][0] != -1; i++)
		{
			for (j = 0; j < courseNum; j++)
			{
				if (strcmp(studentGradeInformation[target[i][0]].courseName, courseBaseInformation[j].name) == 0)
					break;
			}
			temp1 = temp1 + transformStringToFloatNumber(courseBaseInformation[j].credit) *
							studentGradeInformation[target[i][0]].GPA;
			temp2 = temp2 + transformStringToFloatNumber(studentGradeInformation[target[i][0]].grade) *
							transformStringToFloatNumber(courseBaseInformation[j].credit);
			sumCredit = sumCredit + transformStringToFloatNumber(courseBaseInformation[j].credit);
			printf("课名: %-15s", studentGradeInformation[target[i][0]].courseName);
			printf("课号: %-12s", courseBaseInformation[j].number);
			printf("成绩: %-8s", studentGradeInformation[target[i][0]].grade);
			printf("绩点: %.2f\n", studentGradeInformation[target[i][0]].GPA);
			count2++;
			if (count2 % 10 == 0)
			{
				printf("\n*****************************************************************\n");
				printf("\n共 %d 条记录, 共 %d 页, 当前为第 %d 页\n", k,
						(k % 10 == 0) ? (k / 10) : (k / 10 + 1),
						page);
				page++;
				printf("按任意键跳转到下一页...");
				fflush(stdin);
				getchar();
				goto nextPage;
			}
		}
		printf("\n*****************************************************************\n");
		printf("\n共 %d 条记录, 共 %d 页, 当前为最后一页\n", count1,
				(count2 % 10 == 0) ? (count2 / 10) : (count2 / 10 + 1));
		printf("\n平均绩点: %.2f\n", temp1 / sumCredit);
		printf("加权平均分: %.2f\n", temp2 / sumCredit);
		printf("总学分: %.1f\n", sumCredit);
	}
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
	int page = 1;
	float sumGrade = 0;
	float sumGPA = 0;
	int count1;
	int count2 = 0;
	int target[100][2];
	int k;
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
nextPage:
	k = 0;
	count1 = 0;
	for (i = 0; i < studentGradeNum; i++)
	{
		if (strcmp(studentGradeInformation[i].courseName, findInform) == 0)
		{
			count1++;
			if (count1 == 1)
			{
				system("cls");
				printf("课名: %s\n", studentGradeInformation[i].courseName);
				printf("课号: %s\n", courseBaseInformation[j].number);
				printf("学分: %s\n\n", courseBaseInformation[j].credit);
			}
			target[k++][0] = i;
			target[k][0] = -1;
		}
	}
	if (count1 == 0)
		printf("\n未找到该课程成绩信息!\n");
	else
	{
		printf("*****************************************************************\n\n");
		sortGrade(target);
		for (i = count2; target[i][0] != -1; i++)
		{
			for (j = 0; j < studentNum; j++)
			{
				if (strcmp(studentGradeInformation[target[i][0]].studentName,
						studentBaseInformation[j].name) == 0)
					break;
			}
			sumGPA = sumGPA + studentGradeInformation[target[i][0]].GPA;
			sumGrade = sumGrade + transformStringToFloatNumber(studentGradeInformation[target[i][0]].grade);
			printf("学号: %-12s", studentBaseInformation[j].number);
			printf("姓名: %-10s", studentGradeInformation[target[i][0]].studentName);
			printf("成绩: %-8s", studentGradeInformation[target[i][0]].grade);
			printf("绩点: %.2f\n", studentGradeInformation[target[i][0]].GPA);
			count2++;
			if (count2 % 10 == 0)
			{
				printf("\n*****************************************************************\n");
				printf("\n共 %d 条记录, 共 %d 页, 当前为第 %d 页\n", k,
						(k % 10 == 0) ? (k / 10) : (k / 10 + 1),
						page);
				page++;
				printf("按任意键跳转到下一页...");
				fflush(stdin);
				getchar();
				goto nextPage;
			}
		}
		printf("\n*****************************************************************\n");
		printf("\n共 %d 条记录, 共 %d 页, 当前为最后一页\n", count1,
				(count2 % 10 == 0) ? (count2 / 10) : (count2 / 10 + 1));
		printf("\n平均分: %.2f\n", sumGrade / (float)count1);
		printf("平均绩点: %.2f\n", sumGPA / (float)count1);
	}
}
