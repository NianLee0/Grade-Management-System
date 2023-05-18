//
// Created by NianLee on 2023/5/16.
//

#include "../Inc/deleteCourseBaseInform.h"

/************************************************
 * @Function: deleteCourseBaseInform
 * @Description: 管理员通过输入删除课程基本信息,包括课号,课名,学分
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void deleteCourseBaseInform(void)
{
	char target[20];
	int i;
	printf("请输入要删除的课程的课名或课号: ");
	scanf("%s", target);
	for (i = 0; i < courseNum; i++)
	{
		if (strcmp(courseBaseInformation[i].name, target) == 0 ||
			strcmp(courseBaseInformation[i].number, target) == 0)
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
		printf("\n未找到该课程!\n");
		printf("请检查输入是否正确并重新输入!\n");;
		deleteCourseBaseInform();
	}
	else
		deleteCourseBaseInformConfirm(i);
}

/************************************************
 * @Function: deleteCourseBaseInformConfirm
 * @Description: 确认是否删除课程基本信息
 * @Input: targetCourseNum: 要删除的学生在数组中的下标
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void deleteCourseBaseInformConfirm(int targetCourseNum)
{
	char confirm;
	printf("\n确认删除该课程信息? (y/N): ");
	getchar();
	scanf("%c", &confirm);
	if (confirm == 'Y' || confirm == 'y')
		deleteCourseBaseInformFromStructure(targetCourseNum);
	else if (confirm == 'N' || confirm == 'n' || confirm == '\n')
	{
		system("cls");
		printf("\n已取消删除操作!\n");
		mode2SubMenu();
	}
	else
	{
		printf("\n输入错误!\n");
		printf("请重新输入!\n");
		deleteStudentBaseInformConfirm(targetCourseNum);
	}
}

/************************************************
 * @Function: deleteCourseBaseInformFromStructure
 * @Description: 从结构体数组中删除课程基本信息
 * @Input: targetCourseNum: 要删除的课程在数组中的下标
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void deleteCourseBaseInformFromStructure(int targetCourseNum)
{
	for (int i = targetCourseNum; i < courseNum - 1; i++)
		courseBaseInformation[i] = courseBaseInformation[i + 1];
	courseBaseInformation[courseNum].number[0] = '\0';
	courseBaseInformation[courseNum].name[0] = '\0';
	courseBaseInformation[courseNum].credit[0] = '\0';
	saveCourseBaseInformIntoFile_2();
	courseNum--;
}

/************************************************
 * @Function: saveCourseBaseInformIntoFile_2
 * @Description: 将修改后的课程基本信息保存到文件中
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void saveCourseBaseInformIntoFile_2(void)
{
	char inform[100];
	FILE* fp;
	fp = fopen(courseBaseInformFilePath, "w");
	fputs("课号,课名,学分\n", fp);
	fseek(fp, 16, SEEK_SET);
	for (int i = 0; i < courseNum - 1; i++)
	{
		sprintf(inform, "%s,%s,%s\n",
				courseBaseInformation[i].number,
				courseBaseInformation[i].name,
				courseBaseInformation[i].credit);
		fputs(inform, fp);
	}
	fclose(fp);
}