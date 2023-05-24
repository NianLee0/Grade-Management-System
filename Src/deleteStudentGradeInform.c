//
// Created by NianLee on 2023/5/17.
//

#include "../Inc/deleteStudentGradeInform.h"

/************************************************
 * @Function: deleteStudentGradeInform
 * @Description: 管理员通过输入删除学生成绩基本信息,包括姓名、课号、成绩
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
	printf("请输入要删除的成绩的学生姓名或学号: ");
	scanf("%s", studentTarget);
	for (int j = 0; j < studentNum; j++)
	{
		if (strcmp(studentBaseInformation[j].number, studentTarget) == 0)
		{
			strcpy(studentTarget, studentBaseInformation[j].name);
			break;
		}
	}
	printf("请输入要删除的成绩的课程名称或课号: ");
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
			printf("\n已找到该成绩: \n");
			printf("姓名: %s\n", studentGradeInformation[i].studentName);
			printf("课名: %s\n", studentGradeInformation[i].courseName);
			printf("成绩: %s\n", studentGradeInformation[i].grade);
			break;
		}
	}
	if (i == studentGradeNum)
	{
		printf("\n未找到该成绩!\n");
		printf("请检查输入是否正确并重新输入!\n");;
		deleteStudentGradeInform();
	}
	else
		deleteStudentGradeInformConfirm(i);
}

/************************************************
 * @Function: deleteStudentGradeInformConfirm
 * @Description: 确认是否删除学生成绩信息
 * @Input: targetStudentGradeNum: 要删除的成绩在数组中的下标
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void deleteStudentGradeInformConfirm(int targetStudentGradeNum)
{
	char confirm;
	printf("\n确认删除该成绩信息? (y/N): ");
	fflush(stdin);
	scanf("%c", &confirm);
	if (confirm == 'Y' || confirm == 'y')
	{
		printf("\n已删除该成绩信息!\n");
		deleteStudentGradeInformFromStructure(targetStudentGradeNum);
	}
	else if (confirm == 'N' || confirm == 'n' || confirm == '\n')
	{
		system("cls");
		printf("\n已取消删除操作!\n");
		mode6SubMenu();
	}
	else
	{
		printf("\n输入错误!\n");
		printf("请重新输入!\n");
		deleteStudentGradeInformConfirm(targetStudentGradeNum);
	}
}

/************************************************
 * @Function: deleteStudentGradeInformFromStructure
 * @Description: 从结构体数组中删除成绩基本信息
 * @Input: targetStudentGradeNum: 要删除的成绩在数组中的下标
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
 * @Description: 将修改后的学生成绩信息保存到文件中
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
	fputs("姓名,课名,成绩\n", fp);
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
