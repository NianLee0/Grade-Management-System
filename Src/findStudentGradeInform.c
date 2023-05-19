//
// Created by NianLee on 2023/5/17.
//

#include "../Inc/findStudentGradeInform.h"

/************************************************
 * @Function: findStudentGradeInformByStudent
 * @Description: ͨ��ѧ��������ѧ�Ų���ѧ���ɼ���Ϣ,�����������������ɼ�
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
	int target[100][2];
	int k = 0;
	printf("������Ҫ���ҵ�ѧ����������ѧ��: ");
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
				printf("\n����: %s\n", studentGradeInformation[i].studentName);
				printf("ѧ��: %s\n", studentBaseInformation[j].number);
			}
			target[k++][0] = i;
			target[k][0] = -1;
		}
	}
	if (count == 0)
		printf("\nδ�ҵ���ѧ���ɼ���Ϣ!\n");
	else
	{
		sortCourse(target);
		for (i = 0; target[i][0] != -1; i++)
		{
			for (j = 0; j < courseNum; j++)
			{
				if (strcmp(studentGradeInformation[target[i][0]].courseName, courseBaseInformation[j].name) == 0)
					break;
			}
			printf("����: %-15s", studentGradeInformation[target[i][0]].courseName);
			printf("�κ�: %-12s", courseBaseInformation[j].number);
			printf("�ɼ�: %-8s", studentGradeInformation[target[i][0]].grade);
			printf("����: %.2f\n", studentGradeInformation[target[i][0]].GPA);
		}
	}
}

/************************************************
 * @Function: findStudentGradeInformByCourse
 * @Description: ͨ���γ̿�����κŲ���ѧ���ɼ���Ϣ,�����������κš��������ɼ�
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
	int target[100][2];
	int k = 0;
	printf("������Ҫ���ҵĿγ̵Ŀ�����κ�: ");
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
				printf("\n����: %s\n", studentGradeInformation[i].courseName);
				printf("�κ�: %s\n", courseBaseInformation[j].number);
			}
			target[k++][0] = i;
			target[k][0] = -1;
		}
	}
	if (count == 0)
		printf("\nδ�ҵ��ÿγ̳ɼ���Ϣ!\n");
	else
	{
		sortGrade(target);
		for (i = 0; target[i][0] != -1; i++)
		{
			for (j = 0; j < studentNum; j++)
			{
				if (strcmp(studentGradeInformation[target[i][0]].studentName,
						studentBaseInformation[j].name) == 0)
					break;
			}
			printf("ѧ��: %-12s", studentBaseInformation[j].number);
			printf("����: %-10s", studentGradeInformation[target[i][0]].studentName);
			printf("�ɼ�: %-8s", studentGradeInformation[target[i][0]].grade);
			printf("����: %.2f\n", studentGradeInformation[target[i][0]].GPA);
		}
	}
}
