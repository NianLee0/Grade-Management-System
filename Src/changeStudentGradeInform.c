//
// Created by NianLee on 2023/5/17.
//

#include "../Inc/changeStudentGradeInform.h"

/************************************************
 * @Function: changeStudentBaseInform
 * @Description: ����Աͨ�������޸�ѧ���ɼ���Ϣ,�����������������ɼ�
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void changeStudentGradeInform(void)
{
	char studentNameTarget[20];
	char courseNameTarget[50];
	int i, j;
	printf("������Ҫ�޸���Ϣ��ѧ�������Ϳγ�����\n");
inputStudentName:
	printf("ѧ������: ");
	scanf("%s", studentNameTarget);
	for (j = 0; j < studentGradeNum; j++)
	{
		if (strcmp(studentGradeInformation[j].studentName, studentNameTarget) == 0)
		{
			j = -1;
			break;
		}
	}
	if (j != -1)
	{
		system("cls");
		printf("δ�ҵ���ѧ��!\n");
		printf("���������Ƿ���ȷ����������!\n");
		goto inputStudentName;
	}
inputCourseName:
	printf("�γ�����: ");
	scanf("%s", courseNameTarget);
	for (j = 0; j < studentGradeNum; j++)
	{
		if (strcmp(studentGradeInformation[j].courseName, courseNameTarget) == 0)
		{
			j = -1;
			break;
		}
	}
	if (j != -1)
	{
		system("cls");
		printf("δ�ҵ��ÿγ�!\n");
		printf("���������Ƿ���ȷ����������!\n");
		goto inputCourseName;
	}
	for (i = 0; i < studentGradeNum; i++)
	{
		if (strcmp(studentGradeInformation[i].studentName, studentNameTarget) == 0 &&
			strcmp(studentGradeInformation[i].courseName, courseNameTarget) == 0)
		{
			system("cls");
			printf("���ҵ���ѧ��: \n");
			printf("����: %s\n", studentGradeInformation[i].studentName);
			printf("�γ�: %s\n", studentGradeInformation[i].courseName);
			printf("�ɼ�: %s\n", studentGradeInformation[i].grade);
			printf("����: %.2f\n", studentGradeInformation[i].GPA);
			break;
		}
	}
	if (i == studentGradeNum)
	{
		printf("\nδ�ҵ���ѧ���Ĵ��ſγɼ�!\n");
		printf("���������Ƿ���ȷ����������!\n");
		changeStudentGradeInform();
	}
	else
	{
		printf("\n�������޸ĺ��ѧ���ɼ���Ϣ:\n");
		printf("����: ");
		scanf("%s", studentGradeInformation[i].studentName);
		checkStudentBaseInform(i);
		printf("����: ");
		scanf("%s", studentGradeInformation[i].courseName);
		checkCourseBaseInform(i);
		printf("�ɼ�: ");
		scanf("%s", studentGradeInformation[i].grade);
		checkStudentGradeInform(i);
		studentGradeInformation[i].GPA = calculateGPA(i);
		printf("�޸ĳɹ�!\n");
		saveStudentGradeInform();
	}
}

/************************************************
 * @Function: saveStudentGradeInform
 * @Description: ѯ�ʹ���Ա�Ƿ��޸ĺ��ѧ���ɼ���Ϣ�������ļ�
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void saveStudentGradeInform(void)
{
	char choice;
	printf("\n�Ƿ���Ϣ�������ļ�? (Y/n): ");
	fflush(stdin);
	scanf("%c", &choice);
	if (choice == 'Y' || choice == 'y' || choice == '\n')
	{
		saveStudentGradeInformIntoFile_1();
		printf("����ɹ�!\n");
		printf("�����޸Ľ�������Ч!\n");
	}
	else if (choice == 'N' || choice == 'n')
	{
		printf("��ȡ������!\n");
		printf("�����޸Ľ���ǰ����ʱ��Ч!\n");
	}
	else
	{
		system("cls");
		printf("�������!\n");
		printf("����������!\n");
		saveStudentGradeInform();
	}
}

/************************************************
 * @Function: saveStudentBaseInformIntoFile_1
 * @Description: ���޸ĺ�Ŀγ���Ϣ�������ļ�
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void saveStudentGradeInformIntoFile_1(void)
{
	char inform[100];
	FILE* fp;
	fp = fopen(studentGradeInformFilePath, "r+");
	fseek(fp, 16, SEEK_SET);
	for (int i = 0; i < studentGradeNum; i++)
	{
		sprintf(inform, "%s,%s,%s\n",
				studentGradeInformation[i].studentName,
				studentGradeInformation[i].courseName,
				studentGradeInformation[i].grade);
		fputs(inform, fp);
	}
	fclose(fp);
}

/************************************************
 * @Function: checkStudentBaseInform
 * @Description: ���ѧ��������Ϣ�ļ����Ƿ��д�ѧ����Ϣ
 * @Input: num
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void checkStudentBaseInform(int num)
{
	int k;
	for (k = 0; k < studentNum; k++)
	{
		if (strcmp(studentBaseInformation[k].name,
				studentGradeInformation[num].studentName) == 0)
		{
			k = -1;
			break;
		}
	}
	if (k != -1)
	{
		int choice;
		printf("\nѧ��������Ϣ�ļ����޴�ѧ����Ϣ!\n");
		printf("���������Ƿ���ȷ����Ӵ�ѧ����Ϣ!\n");
		printf("1. ��Ӵ�ѧ����Ϣ\n");
		printf("2. ��������\n");
		printf("0. ������һ��\n");
		printf("������: ");
		scanf("%d", &choice);
		system("cls");
		switch (choice)
		{
		case 1:
			system("cls");
			printf("�밴����ʾ����ѧ��������Ϣ:\n");
			addStudentBaseInformToFile();
			printf("��ӳɹ�!\n");
			printf("�����������...");
			fflush(stdin);
			getchar();
			system("cls");
			printf("�������޸ĺ�ĳɼ���Ϣ:\n");
			printf("����: ");
			scanf("%s", studentGradeInformation[num].studentName);
			checkStudentBaseInform(num);
			break;
		case 2:
			system("cls");
			printf("����: ");
			scanf("%s", studentGradeInformation[num].studentName);
			checkStudentBaseInform(num);
			break;
		case 0:
			mode6SubMenu();
			break;
		default:
			system("cls");
			printf("�������!\n");
			printf("����������!\n");
			checkStudentBaseInform(num);
			break;
		}
	}
}

/************************************************
 * @Function: checkCourseBaseInform
 * @Description: ���γ̻�����Ϣ�ļ����Ƿ��д˿γ���Ϣ
 * @Input: num
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void checkCourseBaseInform(int num)
{
	int k;
	for (k = 0; k < studentNum; k++)
	{
		if (strcmp(courseBaseInformation[k].name,
				studentGradeInformation[num].courseName) == 0)
		{
			k = -1;
			break;
		}
	}
	if (k != -1)
	{
		int choice;
		printf("\n�γ̻�����Ϣ�ļ����޴˿γ���Ϣ!\n");
		printf("���������Ƿ���ȷ����Ӵ˿γ���Ϣ!\n");
		printf("1. ��Ӵ˿γ���Ϣ\n");
		printf("2. ��������\n");
		printf("0. ������һ��\n");
		printf("������: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			system("cls");
			printf("�밴����ʾ����γ̻�����Ϣ:\n");
			addCourseBaseInformToFile();
			printf("��ӳɹ�!\n");
			printf("�����������...");
			fflush(stdin);
			getchar();
			system("cls");
			printf("�������޸ĺ�ĳɼ���Ϣ:\n");
			printf("����: ");
			scanf("%s", studentGradeInformation[num].studentName);
			checkStudentBaseInform(num);
			printf("����: ");
			scanf("%s", studentGradeInformation[num].courseName);
			checkCourseBaseInform(num);
			break;
		case 2:
			system("cls");
			printf("����: %s\n", studentGradeInformation[num].studentName);
			printf("����: ");
			scanf("%s", studentGradeInformation[num].courseName);
			checkCourseBaseInform(num);
			break;
		case 0:
			mode6SubMenu();
			break;
		default:
			system("cls");
			printf("�������!\n");
			printf("����������!\n");
			checkCourseBaseInform(num);
			break;
		}
	}
}

/************************************************
 * @Function: checkStudentGradeInform
 * @Description: ���ѧ���ɼ���Ϣ�Ƿ�Ϸ�
 * @Input: num
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void checkStudentGradeInform(int num)
{
	if (calculateGPA(num) == -1)
	{
		printf("\n�ɼ����Ϸ�,����������!\n");
		printf("�ɼ�: ");
		scanf("%s", studentGradeInformation[num].grade);
		checkStudentGradeInform(num);
	}
}