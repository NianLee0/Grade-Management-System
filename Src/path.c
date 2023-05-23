//
// Created by NianLee on 2023/5/16.
//

#include "../Inc/path.h"

char studentBaseInformFilePath[100];
char courseBaseInformFilePath[100];
char studentGradeInformFilePath[100];

/************************************************
 * @Function: pathTest
 * @Description: ����ļ�·���Ƿ���ȷ
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void pathTest(void)
{
	studentBaseInformFilePathTest();
	courseBaseInformFilePathTest();
	studentGradeInformFilePathTest();
}

/************************************************
 * @Function: studentBaseInformFilePathTest
 * @Description: ���ѧ��������Ϣ�ļ��Ƿ���Ĭ��·��
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void studentBaseInformFilePathTest(void)
{
	FILE* fp;
	fp = fopen("../ѧ��������Ϣ.csv", "r");
	if (fp == NULL)
	{
		fp = fopen("./ѧ��������Ϣ.csv", "r");
		if (fp == NULL)
		{
			printf("ѧ��������Ϣ�ļ�����Ĭ��·��\n");
			fflush(stdin);
			strcpy(studentBaseInformFilePath,
					userFilePath(studentBaseInformFilePath));
			printf("�ļ�·����ȷ!\n\n");
			system("pause");
			system("cls");
		}
		else
			strcpy(studentBaseInformFilePath, "./ѧ��������Ϣ.csv");
	}
	else
		strcpy(studentBaseInformFilePath, "../ѧ��������Ϣ.csv");
	fclose(fp);
}

/************************************************
 * @Function: courseBaseInformFilePathTest
 * @Description: ���γ̻�����Ϣ�ļ��Ƿ���Ĭ��·��
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void courseBaseInformFilePathTest(void)
{
	FILE* fp;
	fp = fopen("../�γ̻�����Ϣ.csv", "r");
	if (fp == NULL)
	{
		fp = fopen("./�γ̻�����Ϣ.csv", "r");
		if (fp == NULL)
		{
			printf("�γ̻�����Ϣ�ļ�����Ĭ��·��\n");
			fflush(stdin);
			strcpy(courseBaseInformFilePath,
					userFilePath(courseBaseInformFilePath));
			printf("�ļ�·����ȷ!\n\n");
			system("pause");
			system("cls");
		}
		else
			strcpy(courseBaseInformFilePath, "./�γ̻�����Ϣ.csv");
	}
	else
		strcpy(courseBaseInformFilePath, "../�γ̻�����Ϣ.csv");
	fclose(fp);
}

/************************************************
 * @Function: studentBaseInformFilePathTest
 * @Description: ���ѧ��������Ϣ�ļ��Ƿ���Ĭ��·��
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void studentGradeInformFilePathTest(void)
{
	FILE* fp;
	fp = fopen("../ѧ���ɼ���Ϣ.csv", "r");
	if (fp == NULL)
	{
		fp = fopen("./ѧ���ɼ���Ϣ.csv", "r");
		if (fp == NULL)
		{
			printf("ѧ���ɼ���Ϣ�ļ�����Ĭ��·��\n");
			fflush(stdin);
			strcpy(studentGradeInformFilePath,
					userFilePath(studentGradeInformFilePath));
			printf("�ļ�·����ȷ!\n\n");
			system("pause");
			system("cls");
		}
		else
			strcpy(studentGradeInformFilePath, "./ѧ���ɼ���Ϣ.csv");
	}
	else
		strcpy(studentGradeInformFilePath, "../ѧ���ɼ���Ϣ.csv");
	fclose(fp);
}

/************************************************
 * @Function: userFilePath
 * @Description: ��ȡ�û�������ļ�·������֤�Ƿ���ȷ
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
char* userFilePath(char* path)
{
	char* userFilePathStr = (char*)calloc(sizeof(char), 100);
	FILE* fp;
	printf("�������ļ�·��: ");
	scanf("%[^\n]", userFilePathStr);
	int j = 0;
	for (int i = 0; i < strlen(userFilePathStr); i++)
	{
		if (userFilePathStr[i] != '\"')
			path[j++] = userFilePathStr[i];
	}
	path[j] = '\0';
	if ((fp = fopen(path, "r")) == NULL)
	{
		printf("�ļ���ʧ��!\n");
		printf("�����ļ�·���Ƿ���ȷ!\n\n");
		getchar();
		userFilePath(path);
	}
	fclose(fp);
	return path;
}
