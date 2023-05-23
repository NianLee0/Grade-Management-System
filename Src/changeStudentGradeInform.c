//
// Created by NianLee on 2023/5/17.
//

#include "../Inc/changeStudentGradeInform.h"

/************************************************
 * @Function: changeStudentBaseInform
 * @Description: 管理员通过输入修改学生成绩信息,包括姓名、课名、成绩
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
	printf("请输入要修改信息的学生姓名和课程名称\n");
inputStudentName:
	printf("学生姓名: ");
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
		printf("未找到该学生!\n");
		printf("请检查输入是否正确并重新输入!\n");
		goto inputStudentName;
	}
inputCourseName:
	printf("课程名称: ");
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
		printf("未找到该课程!\n");
		printf("请检查输入是否正确并重新输入!\n");
		goto inputCourseName;
	}
	for (i = 0; i < studentGradeNum; i++)
	{
		if (strcmp(studentGradeInformation[i].studentName, studentNameTarget) == 0 &&
			strcmp(studentGradeInformation[i].courseName, courseNameTarget) == 0)
		{
			system("cls");
			printf("已找到该学生: \n");
			printf("姓名: %s\n", studentGradeInformation[i].studentName);
			printf("课程: %s\n", studentGradeInformation[i].courseName);
			printf("成绩: %s\n", studentGradeInformation[i].grade);
			printf("绩点: %.2f\n", studentGradeInformation[i].GPA);
			break;
		}
	}
	if (i == studentGradeNum)
	{
		printf("\n未找到该学生的此门课成绩!\n");
		printf("请检查输入是否正确并重新输入!\n");
		changeStudentGradeInform();
	}
	else
	{
		printf("\n请输入修改后的学生成绩信息:\n");
		printf("姓名: ");
		scanf("%s", studentGradeInformation[i].studentName);
		checkStudentBaseInform(i);
		printf("课名: ");
		scanf("%s", studentGradeInformation[i].courseName);
		checkCourseBaseInform(i);
		printf("成绩: ");
		scanf("%s", studentGradeInformation[i].grade);
		checkStudentGradeInform(i);
		studentGradeInformation[i].GPA = calculateGPA(i);
		printf("修改成功!\n");
		saveStudentGradeInform();
	}
}

/************************************************
 * @Function: saveStudentGradeInform
 * @Description: 询问管理员是否将修改后的学生成绩信息保存至文件
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void saveStudentGradeInform(void)
{
	char choice;
	printf("\n是否将信息保存至文件? (Y/n): ");
	fflush(stdin);
	scanf("%c", &choice);
	if (choice == 'Y' || choice == 'y' || choice == '\n')
	{
		saveStudentGradeInformIntoFile_1();
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
		saveStudentGradeInform();
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
 * @Description: 检查学生基本信息文件中是否有此学生信息
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
		printf("\n学生基本信息文件中无此学生信息!\n");
		printf("请检查输入是否正确或添加此学生信息!\n");
		printf("1. 添加此学生信息\n");
		printf("2. 重新输入\n");
		printf("0. 返回上一级\n");
		printf("请输入: ");
		scanf("%d", &choice);
		system("cls");
		switch (choice)
		{
		case 1:
			system("cls");
			printf("请按照提示输入学生基本信息:\n");
			addStudentBaseInformToFile();
			printf("添加成功!\n");
			printf("按任意键继续...");
			fflush(stdin);
			getchar();
			system("cls");
			printf("请输入修改后的成绩信息:\n");
			printf("姓名: ");
			scanf("%s", studentGradeInformation[num].studentName);
			checkStudentBaseInform(num);
			break;
		case 2:
			system("cls");
			printf("姓名: ");
			scanf("%s", studentGradeInformation[num].studentName);
			checkStudentBaseInform(num);
			break;
		case 0:
			mode6SubMenu();
			break;
		default:
			system("cls");
			printf("输入错误!\n");
			printf("请重新输入!\n");
			checkStudentBaseInform(num);
			break;
		}
	}
}

/************************************************
 * @Function: checkCourseBaseInform
 * @Description: 检查课程基本信息文件中是否有此课程信息
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
		printf("\n课程基本信息文件中无此课程信息!\n");
		printf("请检查输入是否正确或添加此课程信息!\n");
		printf("1. 添加此课程信息\n");
		printf("2. 重新输入\n");
		printf("0. 返回上一级\n");
		printf("请输入: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			system("cls");
			printf("请按照提示输入课程基本信息:\n");
			addCourseBaseInformToFile();
			printf("添加成功!\n");
			printf("按任意键继续...");
			fflush(stdin);
			getchar();
			system("cls");
			printf("请输入修改后的成绩信息:\n");
			printf("姓名: ");
			scanf("%s", studentGradeInformation[num].studentName);
			checkStudentBaseInform(num);
			printf("课名: ");
			scanf("%s", studentGradeInformation[num].courseName);
			checkCourseBaseInform(num);
			break;
		case 2:
			system("cls");
			printf("姓名: %s\n", studentGradeInformation[num].studentName);
			printf("课名: ");
			scanf("%s", studentGradeInformation[num].courseName);
			checkCourseBaseInform(num);
			break;
		case 0:
			mode6SubMenu();
			break;
		default:
			system("cls");
			printf("输入错误!\n");
			printf("请重新输入!\n");
			checkCourseBaseInform(num);
			break;
		}
	}
}

/************************************************
 * @Function: checkStudentGradeInform
 * @Description: 检查学生成绩信息是否合法
 * @Input: num
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void checkStudentGradeInform(int num)
{
	if (calculateGPA(num) == -1)
	{
		printf("\n成绩不合法,请重新输入!\n");
		printf("成绩: ");
		scanf("%s", studentGradeInformation[num].grade);
		checkStudentGradeInform(num);
	}
}