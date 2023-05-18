//
// Created by NianLee on 2023/5/16.
//

#include "../Inc/initStudentBaseInform.h"

/************************************************
 * @Function: loadStudentBaseInformFile
 * @Description: 打开需要的学生基本信息文件并进行数据初步处理
 * @Input: None
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void loadStudentBaseInformFile(void)
{
	char** temp;
	int dataNum = 0;
	int i = 0;
	temp = (char**)malloc(sizeof(char*) * 100);
	FILE* fp = NULL;
	fp = fopen(studentBaseInformFilePath, "r");
	fseek(fp, 0, SEEK_END);
	int num = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	temp[0] = (char*)malloc(sizeof(char) * 100);
	for (int k = 0; k < num; k++)
	{
		fseek(fp, k, SEEK_SET);
		fread(&temp[dataNum][i++], sizeof(char), 1, fp);
		if (temp[dataNum][i - 1] == '\n')
		{
			temp[dataNum][i - 1] = '\0';
			i = 0;
			dataNum++;
			k++;
			temp[dataNum] = (char*)malloc(sizeof(char) * 100);
		}
		//TODO: 读取文件时，如果文件最后一行有多个换行符，会出现问题
	}
	initStudentBaseInform(temp, dataNum);
	free(temp);
	fclose(fp);
}

/************************************************
 * @Function: initStudentBaseInform
 * @Description: 初始化学生基本信息
 * @Input: token[]:数据块, num:数据块数量
 * @Return: None
 * @Others: None
 * @Author: NianLee
 ************************************************/
void initStudentBaseInform(char* temp[], int num)
{
	char* token[10];
	for (int i = 1; i < num; i++)
	{
		token[0] = strtok(temp[i], ",");
		for (int j = 0; j < 4; j++)
			token[j + 1] = strtok(NULL, ",");
		addStudentBaseInformFromFile(token);
	}
}
