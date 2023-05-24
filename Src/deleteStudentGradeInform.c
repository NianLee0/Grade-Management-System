//
// Created by NianLee on 2023/5/17.
//

#include "../Inc/deleteStudentGradeInform.h"

/************************************************
 * @Function: deleteStudentGradeInform
 * @Description: ����Աͨ������ɾ��ѧ���ɼ�������Ϣ,�����������κš��ɼ�
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void deleteStudentGradeInform(void)
{
	char studentTarget[20];
	char courseTarget[50];
	int i;
	printf("������Ҫɾ���ĳɼ���ѧ��������ѧ��: ");
	scanf("%s", studentTarget);
	for (int j = 0; j < studentNum; j++)
	{
		if (strcmp(studentBaseInformation[j].number, studentTarget) == 0)
		{
			strcpy(studentTarget, studentBaseInformation[j].name);
			break;
		}
	}
	printf("������Ҫɾ���ĳɼ��Ŀγ����ƻ�κ�: ");
	scanf("%s", courseTarget);
	for (int j = 0; j < courseNum; j++)
	{
		if (strcmp(courseBaseInformation[j].number, courseTarget) == 0)
		{
			strcpy(courseTarget, courseBaseInformation[j].name);
			break;
		}
	}
	for (i = 0; i < studentGradeNum; i++)
	{
		if (strcmp(studentGradeInformation[i].studentName, studentTarget) == 0 &&
			strcmp(studentGradeInformation[i].courseName, courseTarget) == 0)
		{
			printf("\n���ҵ��óɼ�: \n");
			printf("����: %s\n", studentGradeInformation[i].studentName);
			printf("����: %s\n", studentGradeInformation[i].courseName);
			printf("�ɼ�: %s\n", studentGradeInformation[i].grade);
			break;
		}
	}
	if (i == studentGradeNum)
	{
		printf("\nδ�ҵ��óɼ�!\n");
		printf("���������Ƿ���ȷ����������!\n");;
		deleteStudentGradeInform();
	}
	else
		deleteStudentGradeInformConfirm(i);
}

/************************************************
 * @Function: deleteStudentGradeInformConfirm
 * @Description: ȷ���Ƿ�ɾ��ѧ���ɼ���Ϣ
 * @Input: targetStudentGradeNum: Ҫɾ���ĳɼ��������е��±�
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void deleteStudentGradeInformConfirm(int targetStudentGradeNum)
{
	char confirm;
	printf("\nȷ��ɾ���óɼ���Ϣ? (y/N): ");
	fflush(stdin);
	scanf("%c", &confirm);
	if (confirm == 'Y' || confirm == 'y')
	{
		printf("\n��ɾ���óɼ���Ϣ!\n");
		deleteStudentGradeInformFromStructure(targetStudentGradeNum);
	}
	else if (confirm == 'N' || confirm == 'n' || confirm == '\n')
	{
		system("cls");
		printf("\n��ȡ��ɾ������!\n");
		mode6SubMenu();
	}
	else
	{
		printf("\n�������!\n");
		printf("����������!\n");
		deleteStudentGradeInformConfirm(targetStudentGradeNum);
	}
}

/************************************************
 * @Function: deleteStudentGradeInformFromStructure
 * @Description: �ӽṹ��������ɾ���ɼ�������Ϣ
 * @Input: targetStudentGradeNum: Ҫɾ���ĳɼ��������е��±�
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void deleteStudentGradeInformFromStructure(int targetStudentGradeNum)
{
	for (int i = targetStudentGradeNum; i < studentGradeNum - 1; i++)
		studentGradeInformation[i] = studentGradeInformation[i + 1];
	studentGradeInformation[studentGradeNum].studentName[0] = '\0';
	studentGradeInformation[studentGradeNum].courseName[0] = '\0';
	studentGradeInformation[studentGradeNum].grade[0] = '\0';
	studentGradeInformation[studentGradeNum].GPA = 0;
	saveStudentGradeInformIntoFile_2();
	studentGradeNum--;
}

/************************************************
 * @Function: saveStudentGradeInformIntoFile_2
 * @Description: ���޸ĺ��ѧ���ɼ���Ϣ���浽�ļ���
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void saveStudentGradeInformIntoFile_2(void)
{
	char inform[100];
	FILE* fp;
	fp = fopen(studentGradeInformFilePath, "w");
	fputs("����,����,�ɼ�\n", fp);
	fseek(fp, 16, SEEK_SET);
	for (int i = 0; i < studentGradeNum - 1; i++)
	{
		sprintf(inform, "%s,%s,%s\n",
				studentGradeInformation[i].studentName,
				studentGradeInformation[i].courseName,
				studentGradeInformation[i].grade);
		fputs(inform, fp);
	}
	fclose(fp);
}
