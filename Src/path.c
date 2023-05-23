//
// Created by NianLee on 2023/5/16.
//

#include "../Inc/path.h"

char studentBaseInformFilePath[100];
char courseBaseInformFilePath[100];
char studentGradeInformFilePath[100];

/************************************************
 * @Function: pathTest
 * @Description: 检测文件路径是否正确
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
 * @Description: 检测学生基本信息文件是否在默认路径
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void studentBaseInformFilePathTest(void)
{
	FILE* fp;
	fp = fopen("../学生基本信息.csv", "r");
	if (fp == NULL)
	{
		fp = fopen("./学生基本信息.csv", "r");
		if (fp == NULL)
		{
			printf("学生基本信息文件不在默认路径\n");
			fflush(stdin);
			strcpy(studentBaseInformFilePath,
					userFilePath(studentBaseInformFilePath));
			printf("文件路径正确!\n\n");
			system("pause");
			system("cls");
		}
		else
			strcpy(studentBaseInformFilePath, "./学生基本信息.csv");
	}
	else
		strcpy(studentBaseInformFilePath, "../学生基本信息.csv");
	fclose(fp);
}

/************************************************
 * @Function: courseBaseInformFilePathTest
 * @Description: 检测课程基本信息文件是否在默认路径
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void courseBaseInformFilePathTest(void)
{
	FILE* fp;
	fp = fopen("../课程基本信息.csv", "r");
	if (fp == NULL)
	{
		fp = fopen("./课程基本信息.csv", "r");
		if (fp == NULL)
		{
			printf("课程基本信息文件不在默认路径\n");
			fflush(stdin);
			strcpy(courseBaseInformFilePath,
					userFilePath(courseBaseInformFilePath));
			printf("文件路径正确!\n\n");
			system("pause");
			system("cls");
		}
		else
			strcpy(courseBaseInformFilePath, "./课程基本信息.csv");
	}
	else
		strcpy(courseBaseInformFilePath, "../课程基本信息.csv");
	fclose(fp);
}

/************************************************
 * @Function: studentBaseInformFilePathTest
 * @Description: 检测学生基本信息文件是否在默认路径
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void studentGradeInformFilePathTest(void)
{
	FILE* fp;
	fp = fopen("../学生成绩信息.csv", "r");
	if (fp == NULL)
	{
		fp = fopen("./学生成绩信息.csv", "r");
		if (fp == NULL)
		{
			printf("学生成绩信息文件不在默认路径\n");
			fflush(stdin);
			strcpy(studentGradeInformFilePath,
					userFilePath(studentGradeInformFilePath));
			printf("文件路径正确!\n\n");
			system("pause");
			system("cls");
		}
		else
			strcpy(studentGradeInformFilePath, "./学生成绩信息.csv");
	}
	else
		strcpy(studentGradeInformFilePath, "../学生成绩信息.csv");
	fclose(fp);
}

/************************************************
 * @Function: userFilePath
 * @Description: 获取用户输入的文件路径并验证是否正确
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
char* userFilePath(char* path)
{
	char* userFilePathStr = (char*)calloc(sizeof(char), 100);
	FILE* fp;
	printf("请输入文件路径: ");
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
		printf("文件打开失败!\n");
		printf("请检查文件路径是否正确!\n\n");
		getchar();
		userFilePath(path);
	}
	fclose(fp);
	return path;
}
