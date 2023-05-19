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
	int page = 1;
	float temp1 = 0;
	float temp2 = 0;
	float sumCredit = 0;
	int count1;
	int count2 = 0;
	int target[100][2];
	int k;
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
				printf("����: %s\n", studentGradeInformation[i].studentName);
				printf("ѧ��: %s\n", studentBaseInformation[j].number);
				printf("�Ա�: %s\n", studentBaseInformation[j].sex);
				printf("����: %s\n\n", studentBaseInformation[j].age);
			}
			target[k++][0] = i;
			target[k][0] = -1;
		}
	}
	if (count1 == 0)
		printf("\nδ�ҵ���ѧ���ɼ���Ϣ!\n");
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
			printf("����: %-15s", studentGradeInformation[target[i][0]].courseName);
			printf("�κ�: %-12s", courseBaseInformation[j].number);
			printf("�ɼ�: %-8s", studentGradeInformation[target[i][0]].grade);
			printf("����: %.2f\n", studentGradeInformation[target[i][0]].GPA);
			count2++;
			if (count2 % 10 == 0)
			{
				printf("\n*****************************************************************\n");
				printf("\n�� %d ����¼, �� %d ҳ, ��ǰΪ�� %d ҳ\n", k,
						(k % 10 == 0) ? (k / 10) : (k / 10 + 1),
						page);
				page++;
				printf("���������ת����һҳ...");
				fflush(stdin);
				getchar();
				goto nextPage;
			}
		}
		printf("\n*****************************************************************\n");
		printf("\n�� %d ����¼, �� %d ҳ, ��ǰΪ���һҳ\n", count1,
				(count2 % 10 == 0) ? (count2 / 10) : (count2 / 10 + 1));
		printf("\nƽ������: %.2f\n", temp1 / sumCredit);
		printf("��Ȩƽ����: %.2f\n", temp2 / sumCredit);
		printf("��ѧ��: %.1f\n", sumCredit);
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
	int page = 1;
	float sumGrade = 0;
	float sumGPA = 0;
	int count1;
	int count2 = 0;
	int target[100][2];
	int k;
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
				printf("����: %s\n", studentGradeInformation[i].courseName);
				printf("�κ�: %s\n", courseBaseInformation[j].number);
				printf("ѧ��: %s\n\n", courseBaseInformation[j].credit);
			}
			target[k++][0] = i;
			target[k][0] = -1;
		}
	}
	if (count1 == 0)
		printf("\nδ�ҵ��ÿγ̳ɼ���Ϣ!\n");
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
			printf("ѧ��: %-12s", studentBaseInformation[j].number);
			printf("����: %-10s", studentGradeInformation[target[i][0]].studentName);
			printf("�ɼ�: %-8s", studentGradeInformation[target[i][0]].grade);
			printf("����: %.2f\n", studentGradeInformation[target[i][0]].GPA);
			count2++;
			if (count2 % 10 == 0)
			{
				printf("\n*****************************************************************\n");
				printf("\n�� %d ����¼, �� %d ҳ, ��ǰΪ�� %d ҳ\n", k,
						(k % 10 == 0) ? (k / 10) : (k / 10 + 1),
						page);
				page++;
				printf("���������ת����һҳ...");
				fflush(stdin);
				getchar();
				goto nextPage;
			}
		}
		printf("\n*****************************************************************\n");
		printf("\n�� %d ����¼, �� %d ҳ, ��ǰΪ���һҳ\n", count1,
				(count2 % 10 == 0) ? (count2 / 10) : (count2 / 10 + 1));
		printf("\nƽ����: %.2f\n", sumGrade / (float)count1);
		printf("ƽ������: %.2f\n", sumGPA / (float)count1);
	}
}
