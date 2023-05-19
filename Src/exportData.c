//
// Created by NianLee on 2023/5/18.
//

#include "../Inc/exportData.h"

/************************************************
 * @Function: exportStudentData
 * @Description: 导出学生数据
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void exportStudentData(void)
{
	char target[20];
	int targetGrade[100][2];
	float temp1 = 0;
	float temp2 = 0;
	float sumCredit = 0;
	char exportPath[100] = { 0 };
	int i, j;
	int count = 0;
	printf("请输入要导出的学生姓名或学号: ");
	scanf("%s", target);
	for (i = 0; i < studentNum; i++)
	{
		if (strcmp(studentBaseInformation[i].name, target) == 0)
			break;
		else if (strcmp(studentBaseInformation[i].number, target) == 0)
		{
			strcpy(target, studentBaseInformation[i].name);
			break;
		}
		else if (i == studentNum - 1)
		{
			printf("未找到该学生!\n");
			return;
		}
	}
	time_t now = time(NULL);
	struct tm* t = localtime(&now);
	char time[9];
	strftime(time, sizeof(time), "%Y%m%d", t);
	strcat(exportPath, target);
	strcat(exportPath, time);
	strcat(exportPath, ".txt");
	FILE* fp;
	fp = fopen(exportPath, "w+");
	fprintf(fp, "姓名: %s\n", studentBaseInformation[i].name);
	fprintf(fp, "学号: %s\n", studentBaseInformation[i].number);
	fprintf(fp, "性别: %s\n", studentBaseInformation[i].sex);
	fprintf(fp, "年龄: %s\n\n", studentBaseInformation[i].age);
	fprintf(fp, "课号         课程            学分        成绩         绩点\n");
	for (j = 0; j < studentGradeNum; j++)
	{
		if (strcmp(studentGradeInformation[j].studentName, target) == 0)
		{
			targetGrade[count++][0] = j;
			targetGrade[count][0] = -1;
		}
	}
	if (count == 0)
		fprintf(fp, "\n该学生无成绩信息!\n");
	else
	{
		sortCourse(targetGrade);
		for (i = 0; targetGrade[i][0] != -1; i++)
		{
			for (j = 0; j < courseNum; j++)
			{
				if (strcmp(studentGradeInformation[targetGrade[i][0]].courseName,
						courseBaseInformation[j].name) == 0)
					break;
			}
			temp1 = temp1 + transformStringToFloatNumber(courseBaseInformation[j].credit) *
							studentGradeInformation[targetGrade[i][0]].GPA;
			temp2 = temp2 + transformStringToFloatNumber(studentGradeInformation[targetGrade[i][0]].grade) *
							transformStringToFloatNumber(courseBaseInformation[j].credit);
			sumCredit = sumCredit + transformStringToFloatNumber(courseBaseInformation[j].credit);
			fprintf(fp, "%-13s%-16s%-12s%-12s%.2f\n",
					courseBaseInformation[j].number,
					studentGradeInformation[targetGrade[i][0]].courseName,
					courseBaseInformation[j].credit,
					studentGradeInformation[targetGrade[i][0]].grade,
					studentGradeInformation[targetGrade[i][0]].GPA);
		}
		fprintf(fp, "\n平均绩点: %.2f\n", temp1 / sumCredit);
		fprintf(fp, "加权平均分: %.2f\n", temp2 / sumCredit);
	}
	fclose(fp);
	printf("\n导出成功!\n");
}

/************************************************
 * @Function: exportCourseData
 * @Description: 导出课程数据
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void exportCourseData(void)
{
	char target[20];
	int targetStudent[100][2];
	float sumGrade = 0;
	float sumGPA = 0;
	char exportPath[100] = { 0 };
	int i, j;
	int count = 0;
	printf("请输入要导出的课程的课名或课号: ");
	scanf("%s", target);
	for (i = 0; i < courseNum; i++)
	{
		if (strcmp(courseBaseInformation[i].name, target) == 0)
			break;
		else if (strcmp(courseBaseInformation[i].number, target) == 0)
		{
			strcpy(target, courseBaseInformation[i].name);
			break;
		}
		else if (i == courseNum - 1)
		{
			printf("未找到该课程!\n");
			return;
		}
	}
	time_t now = time(NULL);
	struct tm* t = localtime(&now);
	char time[9];
	strftime(time, sizeof(time), "%Y%m%d", t);
	strcat(exportPath, target);
	strcat(exportPath, time);
	strcat(exportPath, ".txt");
	FILE* fp;
	fp = fopen(exportPath, "w+");
	fprintf(fp, "课名: %s\n", courseBaseInformation[i].name);
	fprintf(fp, "课号: %s\n", courseBaseInformation[i].number);
	fprintf(fp, "学分: %s\n", courseBaseInformation[i].credit);
	fprintf(fp, "\n学号         姓名        成绩     绩点\n");
	for (j = 0; j < studentGradeNum; j++)
	{
		if (strcmp(studentGradeInformation[j].courseName, target) == 0)
		{
			targetStudent[count++][0] = j;
			targetStudent[count][0] = -1;
		}
	}
	if (count == 0)
		fprintf(fp, "\n该课程无学生信息!\n");
	else
	{
		sortGrade(targetStudent);
		for (i = 0; targetStudent[i][0] != -1; i++)
		{
			for (j = 0; j < studentNum; j++)
			{
				if (strcmp(studentGradeInformation[targetStudent[i][0]].studentName,
						studentBaseInformation[j].name) == 0)
					break;
			}
			sumGPA = sumGPA + studentGradeInformation[targetStudent[i][0]].GPA;
			sumGrade = sumGrade + transformStringToFloatNumber(studentGradeInformation[targetStudent[i][0]].grade);
			fprintf(fp, "%-13s%-12s%-8s%.2f\n",
					studentBaseInformation[j].number,
					studentGradeInformation[targetStudent[i][0]].studentName,
					studentGradeInformation[targetStudent[i][0]].grade,
					studentGradeInformation[targetStudent[i][0]].GPA);
		}
		fprintf(fp, "\n平均分: %.2f\n", sumGrade / (float)count);
		fprintf(fp, "平均绩点: %.2f\n", sumGPA / (float)count);
	}
	fclose(fp);
	printf("\n导出成功!\n");
}