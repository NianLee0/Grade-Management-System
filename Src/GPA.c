//
// Created by NianLee on 2023/5/17.
//

#include "../Inc/GPA.h"

/************************************************
 * @Function: calculateGPA
 * @Description: 计算学生的GPA
 * @Input: num: 学生的序号
 * @Return: GPA
 * @Others: None
 * @Author: NianLee
 ************************************************/
float calculateGPA(int num)
{
	float score = transformStringToNumber(studentGradeInformation[num].grade);
	float GPA;
	if (score >= 60 && score <= 100)
		GPA = (score - 50) * 0.1f;
	else if (score >= 0 && score < 60)
		GPA = 0;
	else
		GPA = -1;
	return GPA;
}

/************************************************
 * @Function: transformStringToNumber
 * @Description: 将字符串转换为数字
 * @Input: string: 字符串
 * @Return: 数字
 * @Others: None
 * @Author: NianLee
 ************************************************/
float transformStringToNumber(char* string)
{
	float result = 0;
	int decimalPlace = -1;
	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] == '.')
			decimalPlace = 0;
		else if (decimalPlace >= 0)
		{
			decimalPlace++;
			result += ((float)string[i] - '0') * powf(0.1f, (float)decimalPlace);
		}
		else
			result = result * 10 + (float)(string[i] - '0');
	}
	return result;
}
