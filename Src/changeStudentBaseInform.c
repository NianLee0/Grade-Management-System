//
// Created by NianLee on 2023/5/15.
//

#include "../Inc/changeStudentBaseInform.h"

/************************************************
 * @Function: changeStudentBaseInform
 * @Description: 管理员通过输入修改学生信息,包括姓名、性别、年龄、学号
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void changeStudentBaseInform(void)
{
	char target[20];
	int count;
	int targetStudentNum;
	printf("请输入要修改的学生姓名或学号: ");
whichOne:
	scanf("%s", target);
	count = 0;
	for (int i = 0; i < studentNum; i++)
	{
		if (strcmp(studentBaseInformation[i].name, target) == 0 ||
			strcmp(studentBaseInformation[i].number, target) == 0)
		{
			printf("\n已找到该学生: \n");
			printf("姓名: %s\n", studentBaseInformation[i].name);
			printf("性别: %s\n", studentBaseInformation[i].sex);
			printf("年龄: %s\n", studentBaseInformation[i].age);
			printf("学号: %s\n", studentBaseInformation[i].number);
			targetStudentNum = i;
			count++;
		}
	}
	if (count == 0)
	{
		printf("\n未找到该学生!\n");
		printf("请检查输入是否正确并重新输入!\n\n");
		changeStudentBaseInform();
	}
	else if (count == 1)
	{
		printf("\n请输入修改后的学生信息:\n");
		printf("姓名: ");
		scanf("%s", studentBaseInformation[targetStudentNum].name);
		printf("性别: ");
		scanf("%s", studentBaseInformation[targetStudentNum].sex);
		printf("年龄: ");
		scanf("%s", studentBaseInformation[targetStudentNum].age);
		printf("学号: ");
		scanf("%s", studentBaseInformation[targetStudentNum].number);
	test:
		for (int i = 0; i < studentNum; i++)
		{
			if (strcmp(studentBaseInformation[i].number, studentBaseInformation[targetStudentNum].number) == 0 &&
				i != targetStudentNum)
			{
				printf("\n学号重复，请重新输入学号: ");
				scanf("%s", studentBaseInformation[targetStudentNum].number);
				goto test;
			}
		}
		printf("修改成功!\n");
		saveStudentBaseInform();
	}
	else
	{
		printf("\n有多个同名同姓的学生!\n");
		printf("请输入该学生的学号以确定其身份: ");
		goto whichOne;
	}
}

/************************************************
 * @Function: saveStudentBaseInform
 * @Description: 询问管理员是否将修改后的学生信息保存至文件
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void saveStudentBaseInform(void)
{
	char choice;
	printf("\n是否将信息保存至文件? (Y/n): ");
	fflush(stdin);
	scanf("%c", &choice);
	if (choice == 'Y' || choice == 'y' || choice == '\n')
	{
		saveStudentBaseInformIntoFile_1();
		printf("保存成功!\n");
		printf("本次修改将永久有效!\n");
	}
	else if (choice == 'N' || choice == 'n')
	{
		printf("已取消保存!\n");
		printf("本次修改仅当前运行时有效!\n");
	}
	else
	{
		system("cls");
		printf("输入错误!\n");
		printf("请重新输入!\n");
		saveStudentBaseInform();
	}
}

/************************************************
 * @Function: saveStudentBaseInformIntoFile_1
 * @Description: 将修改后的课程信息保存至文件
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void saveStudentBaseInformIntoFile_1(void)
{
	char inform[100];
	FILE* fp;
	fp = fopen(studentBaseInformFilePath, "r+");
	fseek(fp, 21, SEEK_SET);
	for (int i = 0; i < studentNum; i++)
	{
		sprintf(inform, "%s,%s,%s,%s\n",
				studentBaseInformation[i].name,
				studentBaseInformation[i].sex,
				studentBaseInformation[i].age,
				studentBaseInformation[i].number);
		fputs(inform, fp);
	}
	fclose(fp);
}
