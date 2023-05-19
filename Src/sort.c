//
// Created by NianLee on 2023/5/19.
//

#include "../Inc/sort.h"

/************************************************
 * @Function: sortCourse
 * @Description: 根据课号进行排序
 * @Input: int (* target)[2]: 存储需要进行排序的课程信息的数组
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void sortCourse(int (* target)[2])
{
	for (int i = 0; target[i][0] != -1; i++)
	{
		int j;
		for (j = 0; j < courseNum; j++)
			if (strcmp(studentGradeInformation[target[i][0]].courseName, courseBaseInformation[j].name) == 0)
				break;
		target[i][1] = transformNumberStrToNumber(courseBaseInformation[j].number);
	}
	for (int i = 0; target[i][0] != -1; i++)
	{
		for (int j = 0; target[j][0] != -1; j++)
		{
			if (target[j][1] > target[j + 1][1] && target[j + 1][0] != -1)
			{
				int temp = target[j][1];
				target[j][1] = target[j + 1][1];
				target[j + 1][1] = temp;
				temp = target[j][0];
				target[j][0] = target[j + 1][0];
				target[j + 1][0] = temp;
			}
		}
	}
}

/************************************************
 * @Function: sortStudentNumber
 * @Description: 根据成绩进行排序
 * @Input: int (* target)[2]: 存储需要进行排序的学生成绩信息的数组
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void sortGrade(int (* target)[2])
{
	for (int i = 0; target[i][0] != -1; i++)
		target[i][1] = transformNumberStrToNumber(studentGradeInformation[target[i][0]].grade);
	for (int i = 0; target[i][0] != -1; i++)
	{
		for (int j = 0; target[j][0] != -1; j++)
		{
			if (target[j][1] < target[j + 1][1] && target[j + 1][0] != -1)
			{
				int temp = target[j][1];
				target[j][1] = target[j + 1][1];
				target[j + 1][1] = temp;
				temp = target[j][0];
				target[j][0] = target[j + 1][0];
				target[j + 1][0] = temp;
			}
		}
	}
}

/************************************************
 * @Function: transformNumberStrToNumber
 * @Description: 将字符串形式的数字转换为整型数字
 * @Input: *str: 字符串形式的数字数组
 * @Return: int: 整型数字
 * @Others: None
 * @Author: NianLee
 ************************************************/
int transformNumberStrToNumber(char* str)
{
	int result = 0;
	for (int i = 0; i < strlen(str); i++)
		result = result * 10 + (int)(str[i] - '0');
	return result;
}