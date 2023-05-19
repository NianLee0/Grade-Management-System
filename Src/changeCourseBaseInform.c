//
// Created by NianLee on 2023/5/16.
//

#include "../Inc/changeCourseBaseInform.h"

/************************************************
 * @Function: changeCourseBaseInform
 * @Description: 管理员通过输入修改课程信息,包括课号,课名,学分
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void changeCourseBaseInform(void)
{
	char target[20];
	int i;
	printf("请输入要修改的课程的课名或课号: ");
	scanf("%s", target);
	for (i = 0; i < courseNum; i++)
	{
		if (strcmp(courseBaseInformation[i].number, target) == 0 ||
			strcmp(courseBaseInformation[i].name, target) == 0)
		{
			printf("\n已找到该课程: \n");
			printf("课号: %s\n", courseBaseInformation[i].number);
			printf("课名: %s\n", courseBaseInformation[i].name);
			printf("学分: %s\n", courseBaseInformation[i].credit);
			break;
		}
	}
	if (i == courseNum)
	{
		printf("\n未找到该学生!\n");
		printf("请检查输入是否正确并重新输入!\n");
		changeCourseBaseInform();
	}
	else
	{
		printf("\n请输入修改后的课程信息:\n");
		printf("课号: ");
		scanf("%s", courseBaseInformation[i].number);
		printf("课名: ");
		scanf("%s", courseBaseInformation[i].name);
		printf("学分: ");
		scanf("%s", courseBaseInformation[i].credit);
		printf("修改成功!\n");
		saveCourseBaseInform();
	}
}

/************************************************
 * @Function: saveCourseBaseInform
 * @Description: 询问管理员是否将修改后的课程信息保存至文件
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void saveCourseBaseInform(void)
{
	char choice;
	printf("\n是否将信息保存至文件? (Y/n): ");
	fflush(stdin);
	scanf("%c", &choice);
	if (choice == 'Y' || choice == 'y' || choice == '\n')
	{
		saveCourseBaseInformIntoFile_1();
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
		saveCourseBaseInform();
	}
}

/************************************************
 * @Function: saveCourseBaseInformIntoFile_1
 * @Description: 将修改后的课程信息保存至文件
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void saveCourseBaseInformIntoFile_1(void)
{
	char inform[100];
	FILE* fp;
	fp = fopen(courseBaseInformFilePath, "r+");
	fseek(fp, 16, SEEK_SET);
	for (int i = 0; i < courseNum; i++)
	{
		sprintf(inform, "%s,%s,%s\n",
				courseBaseInformation[i].number,
				courseBaseInformation[i].name,
				courseBaseInformation[i].credit);
		fputs(inform, fp);
	}
	fclose(fp);
}
